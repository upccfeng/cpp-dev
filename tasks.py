import os
import subprocess
import sys
import argparse
import git

__dir__ = os.path.dirname(os.path.realpath(__file__))
sys.path.insert(0, os.path.join(__dir__, 'pylib'))
import taskrunner

@taskrunner.task
def build_google_test():
    BUILD_DIR = os.getcwd()
    #
    # TODO: check is donwload yet
    #
    git.Git(BUILD_DIR).clone("https://github.com/google/googletest.git")

    GOOGLE_TEST_DIR = os.path.join(BUILD_DIR, 'googletest')

    #
    # TODO: mkdir build folder in google test, and build in it
    #
    cmd = '\n'.join(['cd {}'.format(GOOGLE_TEST_DIR),
                        'cmake .',
                        'make'])
    b_cmd = str.encode(cmd)

    p = subprocess.Popen('bash', stdin=subprocess.PIPE,
                         stdout=subprocess.PIPE, stderr=subprocess.PIPE)
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

    # stderr = [ln.replace('\r\n', '') for ln in p.stderr.readlines()]

    # return ExecResult(
    #     return_code=p.returncode,
    #     stdout=stdout,
    #     stderr=stderr)



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

    taskrunner.main({
        'default': ['foo', 'bar', 'car']
    }, dir=CPP_BUILD_DIR)
