from typing import overload
from _pytest.fixtures import yield_fixture
import pytest
from build import *

class TestBuild():
    @pytest.fixture(autouse=True)
    def mock_os_path(self):
        class MockPath:
            def __init__(self):
                self.pathes = []

            def add(self, path):
                self.pathes.append(path)

            def exists(self, path):
                for p in self.pathes:
                    if p == path:
                        return True

                return False

            def mkdir(self, dir):
                self.pathes.append(dir)

        mock_path = MockPath()

        old_os_path = os.path
        old_mkdir = os.mkdir
        os.path.exists = mock_path.exists
        os.mkdir = mock_path.mkdir

        yield mock_path

        os.path = old_os_path
        os.mkdir = old_mkdir

    @pytest.fixture(autouse=True)
    def mock_git(self, mock_os_path):
        class Mockgit:
            def __init__(self, _):
                pass

            def clone(self, url, dir):
                mock_os_path.add(dir)

        old_git = git.Git

        git.Git = Mockgit

        yield

        git.Git = old_git

    @pytest.fixture(scope="function")
    def setup(self):
        def mock_run_cmd(cmds):
            pass

        old_run_cmd = Build._run_cmd
        Build._run_cmd = mock_run_cmd

        yield

        Build._run_cmd = old_run_cmd

    def test_build_parse_arguments(self):

        arg_opts = parse_arguments(["vscode"])
        assert arg_opts.platform == "vscode"

        arg_opts = parse_arguments(["xcode"])
        assert arg_opts.platform == "xcode"

        arg_opts = parse_arguments(["msvc"])
        assert arg_opts.platform == "msvc"

        arg_opts = parse_arguments(["vscode",
            "--build-dir", "PATHTOBUILD"])
        assert arg_opts.build_dir == "PATHTOBUILD"

        arg_opts = parse_arguments(["vscode"])
        assert arg_opts.build_dir == os.path.realpath(os.path.join(os.path.dirname(__file__), "..", "build"))

    def test_build(self, setup, mock_os_path):
        args = [
            "vscode",
            "--build-dir", "../cpp-dev.build"
        ]
        arg_opts = parse_arguments(args)

        build = Build(arg_opts)
        assert build.platform == "vscode"
        assert build.dst_dir == os.path.realpath(os.path.join(os.path.dirname(__file__), "..", "..", "cpp-dev.build"))
        assert build.src_dir == os.path.realpath(os.path.join(os.path.dirname(__file__), ".."))

        build.build()
        path = os.path.realpath(os.path.join(os.path.dirname(__file__), "..", "..", "cpp-dev.build", "third_party_source", "googletest"))
        assert path in mock_os_path.pathes
