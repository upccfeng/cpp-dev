import os
import subprocess
import sys
import argparse
import git

__dir__ = os.path.dirname(os.path.realpath(__file__))
sys.path.insert(0, os.path.join(__dir__, 'pylib'))
import taskrunner

@taskrunner.task
def git_clone():
    print('git_clone')

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
