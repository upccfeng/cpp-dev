import os
import subprocess
import sys
import argparse
import logging
import git

__dir__ = os.path.dirname(os.path.realpath(__file__))
sys.path.insert(0, os.path.join(__dir__, 'pylib'))
import taskrunner


logging.basicConfig(level=logging.INFO,
                    format='%(asctime)s - %(levelname)s: %(message)s',
                    filename='./tasks.log')
logger = logging.getLogger()

class BuildCodeException(Exception):
    pass

class PathErrorExcetpion(Exception):
    pass

@taskrunner.task
def build_googletest():
    BUILD_DIR = os.getcwd()

    GOOGLETEST = 'googletest'
    GOOGLETEST_DIR = os.path.join(BUILD_DIR, 'sources', GOOGLETEST)
    if not os.path.isdir(GOOGLETEST_DIR):
        git.Git(BUILD_DIR).clone('https://github.com/google/googletest.git', GOOGLETEST_DIR)

    if not os.path.isdir(GOOGLETEST_DIR):
        raise PathErrorExcetpion('Path: "{}" not found'.format(GOOGLETEST_DIR))
    else:
        logger.info('GoogleTest source path is: {}'.format(GOOGLETEST_DIR))

    GOOGLETEST_BUILD_DIR = os.path.join(GOOGLETEST_DIR, 'build')
    if not os.path.isdir(GOOGLETEST_BUILD_DIR):
        os.mkdir(GOOGLETEST_BUILD_DIR)

    if not os.path.isdir(GOOGLETEST_BUILD_DIR):
        raise PathErrorExcetpion('Path: "{}" not found'.format(GOOGLETEST_BUILD_DIR))
    else:
        logger.info('GoogleTest build path is: {}'.format(GOOGLETEST_BUILD_DIR))

    INSTALL_DIR = os.path.join(BUILD_DIR, 'install')
    if not os.path.isdir(INSTALL_DIR):
        os.mkdir(INSTALL_DIR)

    if not os.path.isdir(INSTALL_DIR):
        raise PathErrorExcetpion('Path: "{}" not found'.format(INSTALL_DIR))
    else:
        logger.info('GoogleTest install path is: {}'.format(INSTALL_DIR))

    #
    # TODO: support multiplatform (windows, linux, macos), now support linux
    #       * use differen shell on different platform
    #       * cmake will bring additional params, ex: -DCMAKE_CXX_COMPILER, -DCMAKE_CXX_COMPILER
    #
    cmd = '\n'.join(['cd {}'.format(GOOGLETEST_BUILD_DIR),
                        'cmake -DCMAKE_INSTALL_PREFIX={install_path} {src_dir}'.format(install_path=INSTALL_DIR, src_dir=GOOGLETEST_DIR),
                        'make',
                        'make install'])
    b_cmd = str.encode(cmd)

    p = subprocess.Popen('bash', stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    p.stdin.write(b_cmd)
    p.stdin.close()

    stdout = []
    while True:
        ln = p.stdout.readline()
        if not ln:
            break

        sys.stdout.write(ln.decode('utf-8'))
        stdout.append(ln)

    p.wait()

    if p.returncode:
        raise BuildCodeException('Build {} failed'.format(GOOGLETEST))

@taskrunner.task
def foo():
    print('foo')

@taskrunner.task
def bar():
    print('bar')

@taskrunner.task
def car():
    print('car')

if __name__ == '__main__':
    #
    # TODO: pwd should be the build folder, maybe current
    #
    CPP_BUILD_DIR = __dir__

    logger.info('Start to run task')

    taskrunner.main({
        'default': ['foo', 'bar', 'car']
    }, dir=CPP_BUILD_DIR)

    logger.info('End of running')
