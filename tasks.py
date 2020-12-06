import os
import subprocess
import sys
import argparse
import logging
import git
import shutil

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

class RemoveFolderErrorExcetpion(Exception):
    pass

GOOGLETEST_BUIILD_FOLDER = 'googletest_build'
CPP_TEST_BUILD_FOLDER = 'cpp_build'
SOURCE_DIR = os.getcwd()

#
# TODO: maybe can bring the build path from parameters
#
BUILD_DIR = os.path.join(SOURCE_DIR, 'build')
if not os.path.exists(BUILD_DIR):
    os.mkdir(BUILD_DIR)

GOOGLETEST_DIR = os.path.join(BUILD_DIR, 'third_party_source', 'googletest')

INSTALL_DIR = os.path.join(BUILD_DIR, 'install')
if not os.path.exists(INSTALL_DIR):
    os.mkdir(INSTALL_DIR)

if not os.path.exists(INSTALL_DIR):
    raise PathErrorExcetpion('Path: "{}" not found'.format(INSTALL_DIR))
else:
    logger.info('Install path is: {}'.format(INSTALL_DIR))

@taskrunner.task
def download_googletest():
    logger.info('Donwload google test from GitHub')

    if not os.path.exists(GOOGLETEST_DIR):
        git.Git(BUILD_DIR).clone('https://github.com/google/googletest.git', GOOGLETEST_DIR)

    if not os.path.exists(GOOGLETEST_DIR):
        raise PathErrorExcetpion('Path: "{}" not found'.format(GOOGLETEST_DIR))
    else:
        logger.info('GoogleTest source path is: {}'.format(GOOGLETEST_DIR))


@taskrunner.task
def build_googletest():
    logger.info('Start to build google test and install')

    GOOGLETEST_BUILD_DIR = os.path.join(BUILD_DIR, GOOGLETEST_BUIILD_FOLDER)
    if not os.path.exists(GOOGLETEST_BUILD_DIR):
        os.mkdir(GOOGLETEST_BUILD_DIR)

    if not os.path.exists(GOOGLETEST_BUILD_DIR):
        raise PathErrorExcetpion('Path: "{}" not found'.format(GOOGLETEST_BUILD_DIR))
    else:
        logger.info('GoogleTest build path is: {}'.format(GOOGLETEST_BUILD_DIR))

    GOOGLETEST_INSTALL_DIR = os.path.join(INSTALL_DIR, 'googletest')
    if not os.path.exists(GOOGLETEST_INSTALL_DIR):
        os.mkdir(GOOGLETEST_INSTALL_DIR)

    if not os.path.exists(GOOGLETEST_INSTALL_DIR):
        raise PathErrorExcetpion('Path: "{}" not found'.format(GOOGLETEST_INSTALL_DIR))
    else:
        logger.info('GoogleTest install path is: {}'.format(GOOGLETEST_INSTALL_DIR))

    #
    # TODO: support multiplatform (windows, linux, macos), now support linux
    #       * use differen shell on different platform
    #       * cmake will bring additional params, ex: -DCMAKE_CXX_COMPILER, -DCMAKE_CXX_COMPILER
    #
    # TODO: generate xcode project on macos and build it.
    #       generate visual studio project on windows and build it.
    cmd = '\n'.join(['cd {}'.format(GOOGLETEST_BUILD_DIR),
                        'cmake -DCMAKE_INSTALL_PREFIX={install_path} {src_dir}'.format(install_path=GOOGLETEST_INSTALL_DIR, src_dir=GOOGLETEST_DIR),
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
        raise BuildCodeException('Build googletest failed')

@taskrunner.task
def clean_googletest():
    logger.info('Clean googletest build and install folder')

    GOOGLETEST_BUILD_DIR = os.path.join(BUILD_DIR, GOOGLETEST_BUIILD_FOLDER)
    try:
        shutil.rmtree(GOOGLETEST_BUILD_DIR)
    except OSError as e:
        logger.info(e)

    if os.path.exists(GOOGLETEST_BUILD_DIR):
        raise RemoveFolderErrorExcetpion('Remove "{}" folder failed'.format(GOOGLETEST_BUILD_DIR))

    GOOGLETEST_INSTALL_DIR = os.path.join(BUILD_DIR, 'install', 'googletest')
    try:
        shutil.rmtree(GOOGLETEST_INSTALL_DIR)
    except OSError as e:
        logger.info(e)

    if os.path.exists(GOOGLETEST_INSTALL_DIR):
        raise RemoveFolderErrorExcetpion('Remove "{}" folder failed'.format(GOOGLETEST_INSTALL_DIR))

@taskrunner.task
def build_tests():
    logger.info('Build Cpp test code')

    CPP_BUILD_DIR = os.path.join(BUILD_DIR, CPP_TEST_BUILD_FOLDER)
    if not os.path.exists(CPP_BUILD_DIR):
        os.mkdir(CPP_BUILD_DIR)

    if not os.path.exists(CPP_BUILD_DIR):
        raise PathErrorExcetpion('Path: "{}" not found'.format(CPP_BUILD_DIR))
    else:
        logger.info('Cpp test code build path is: {}'.format(CPP_BUILD_DIR))

    #
    # TODO: support multiplatform (windows, linux, macos), now support linux
    #       * use differen shell on different platform
    #       * cmake will bring additional params, ex: -DCMAKE_CXX_COMPILER, -DCMAKE_CXX_COMPILER
    #
    # TODO: generate xcode project on macos and build it.
    #       generate visual studio project on windows and build it.
    cmd = '\n'.join(['cd {}'.format(CPP_BUILD_DIR),
                        'cmake {src_dir}'.format(src_dir=SOURCE_DIR),
                        'make'])
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
        raise BuildCodeException('Build Cpp test code failed')

@taskrunner.task
def clean_tests():
    logger.info('Clean cpp build folder')

    CPP_BUILD_DIR = os.path.join(BUILD_DIR, CPP_TEST_BUILD_FOLDER)
    try:
        shutil.rmtree(CPP_BUILD_DIR)
    except OSError as e:
        logger.info(e)

    if os.path.exists(CPP_BUILD_DIR):
        raise RemoveFolderErrorExcetpion('Remove "{}" folder failed'.format(CPP_BUILD_DIR))

@taskrunner.task
def clean_all():
    logger.info('Clean root build folder')

    try:
        shutil.rmtree(BUILD_DIR)
    except OSError as e:
        logger.info(e)

    if os.path.exists(BUILD_DIR):
        raise RemoveFolderErrorExcetpion('Remove "{}" folder failed'.format(BUILD_DIR))

    if not os.path.exists(BUILD_DIR):
        os.mkdir(BUILD_DIR)

    if not os.path.exists(INSTALL_DIR):
        os.mkdir(INSTALL_DIR)

if __name__ == '__main__':
    #
    # TODO: pwd should be the build folder, maybe current
    #
    CPP_ROOT_DIR = __dir__

    logger.info('Start to run task')

    taskrunner.main({
        'default': ['download_googletest', 'build_googletest', 'build_tests'],
        'googletest_clean_and_build': ['clean_googletest', 'build_googletest'],
        'tests_clean_and_build': ['clean_tests', 'build_tests'],
        'all_clean_and_build': ['clean_all', 'default']
    }, cpp_root_dir=CPP_ROOT_DIR)

    logger.info('End of running')
