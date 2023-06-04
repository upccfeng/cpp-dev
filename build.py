import sys
import os
import argparse
import logging
import git
import subprocess

logging.basicConfig(level=logging.INFO,
                    format="%(asctime)s - %(levelname)s: %(message)s",
                    filename="./build.log")
logger = logging.getLogger()

class BuildCodeException(Exception):
    pass

class PathErrorExcetpion(Exception):
    pass

def parse_arguments(args):

    parser = argparse.ArgumentParser()

    parser.add_argument("platform", help="Specify the build platform", choices=["xcode", "msvc", "vscode"])
    parser.add_argument("--build-dir",
        help="Build directory",
        default=os.path.join(os.path.dirname(os.path.realpath(__file__)), "build"))


    return parser.parse_args(args)

class Build:
    def __init__(self, opts):
        #
        # TODO: opts is dependent on parse_arguments
        #
        self.platform = opts.platform
        self.dst_dir = os.path.realpath(opts.build_dir)

        self.src_dir = os.path.realpath(os.path.dirname(__file__))

        #
        # TODO: Any better way? Lookup environment?
        #
        if self.platform == "msvc":
            self.shell = "cmd"
        else:
            self.shell = "bash"

    def _download_googletest(self, url="https://github.com/google/googletest.git"):
        logger.info('Donwload google test from GitHub: {}'.format(url))

        build_dir = self.dst_dir

        GOOGLETEST_DIR = os.path.join(build_dir, 'third_party_source', 'googletest')

        if not os.path.exists(GOOGLETEST_DIR):
            git.Git(build_dir).clone(url, GOOGLETEST_DIR)

        logger.info('GoogleTest source path is: {}'.format(GOOGLETEST_DIR))

    @staticmethod
    def _get_generator(platform):
        if platform == "xcode":
            return "Xcode"
        elif platform == "msvc":
            #
            # TODO: Get Visual Studio version, shouldn't hardcode
            #
            return "Visual Studio 17 2022"
        else:
            return "Unix Makefiles"

    @staticmethod
    def _run_cmd(cmds, shell="bash"):
        b_cmd = str.encode(cmds)

        p = subprocess.Popen(shell, stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        p.stdin.write(b_cmd)
        p.stdin.close()

        stdout = []
        while True:
            ln = p.stdout.readline()
            if not ln:
                break

            try:
                sys.stdout.write(ln.decode('utf-8'))
                stdout.append(ln)
            except:
                sys.stdout.write("unknow binary\n")

        p.wait()

        return p.returncode

    def _build_googletest(self):
        logger.info('Start to build google test and install')

        build_dir = self.dst_dir
        install_dir = os.path.join(build_dir, "install")

        if not os.path.exists(install_dir):
            os.mkdir(install_dir)

        GOOGLETEST_BUILD_DIR = os.path.join(build_dir, "googletest_build")
        if not os.path.exists(GOOGLETEST_BUILD_DIR):
            os.mkdir(GOOGLETEST_BUILD_DIR)

        if not os.path.exists(GOOGLETEST_BUILD_DIR):
            raise PathErrorExcetpion('Path: "{}" not found'.format(GOOGLETEST_BUILD_DIR))
        else:
            logger.info('GoogleTest build path is: {}'.format(GOOGLETEST_BUILD_DIR))

        GOOGLETEST_INSTALL_DIR = os.path.join(install_dir, 'googletest')
        if not os.path.exists(GOOGLETEST_INSTALL_DIR):
            os.mkdir(GOOGLETEST_INSTALL_DIR)

        if not os.path.exists(GOOGLETEST_INSTALL_DIR):
            raise PathErrorExcetpion('Path: "{}" not found'.format(GOOGLETEST_INSTALL_DIR))
        else:
            logger.info('GoogleTest install path is: {}'.format(GOOGLETEST_INSTALL_DIR))

        GOOGLETEST_DIR = os.path.join(build_dir, 'third_party_source', 'googletest')
        cmds = '\n'.join(['cd {}'.format(GOOGLETEST_BUILD_DIR),
                            'cmake -DCMAKE_INSTALL_PREFIX={install_path} {src_dir}'.format(install_path=GOOGLETEST_INSTALL_DIR, src_dir=GOOGLETEST_DIR),
                            'make',
                            'make install'])

        if Build._run_cmd(cmds, shell=self.shell):
            raise BuildCodeException('Build googletest failed')

    def _build_third_party(self):
        self._download_googletest()

        if self.platform == "vscode":
            self._build_googletest()

    def _build_all(self):
        logger.info('Build Cpp test code')

        build_dir = self.dst_dir
        src_dir = self.src_dir

        cmds = '\n'.join(['cd {}'.format(build_dir),
                            'cmake {src_dir} -G "{generators}"'.format(src_dir=src_dir, generators=Build._get_generator(self.platform)),
                            'cmake --build {build_dir}'.format(build_dir=build_dir)])

        if Build._run_cmd(cmds, shell=self.shell):
            raise BuildCodeException('Build Cpp test code failed')

    def build(self):
        self._build_third_party()
        self._build_all()


if __name__ == "__main__":

    logger.info("Start to build")

    arg_opts = parse_arguments(sys.argv[1:])

    build = Build(arg_opts)
    build.build()

    logger.info("End of building")