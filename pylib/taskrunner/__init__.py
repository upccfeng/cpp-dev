import sys
import argparse
import os
import json

tasks = {}

def parse_arguments(args, alias, dir):

    parser = argparse.ArgumentParser()

    parser.add_argument('task',
                    metavar='task',
                    default='default',
                    const='all',
                    nargs='?',
                    choices=list(alias.keys()) + list(tasks.keys()),
                    help='list servers, storage, or both (default: %(default)s)')

    return parser.parse_args(args)

class Task(object):
    def __init__(self, body):
        self.body = body
        self.name = getattr(body, '__name__', '')

    def __call__(self, *args, **kwargs):
        result = self.body(*args, **kwargs)
        return result

def task(*args, **kwargs):
    klass = Task
    if len(args) == 1 and callable(args[0]):
        obj = klass(args[0], **kwargs)
        tasks[obj.name] = obj
        return obj

class TaskNotFoundError(Exception):
    pass

class TaskTypeError(Exception):
    pass

def main(alias, **kwargs):
    CPP_BUILD_DIR = kwargs['dir']

    if len(sys.argv) == 1:
        sys.argv.append('default')

    arg_opts = parse_arguments(sys.argv[1:], alias, **kwargs)

    for k, v in alias.items():
        if isinstance(v, str):
            if v not in tasks.keys():
                raise TaskNotFoundError('task {} not found'.format(v))

            tasks[k] = [v]
        elif isinstance(v, list):
            for t in v:
                if t not in tasks.keys():
                    raise TaskNotFoundError('task {} not found'.format(t))

            tasks[k] = v
        else:
            raise TaskTypeError('Type shall be str or list')

    if callable(tasks[arg_opts.task]):
        tasks[arg_opts.task]()
    else:
        for k in tasks[arg_opts.task]:
            tasks[k]()
