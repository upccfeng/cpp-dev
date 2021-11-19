
build_dir=$(pwd)
echo "build dir: $build_dir"

source_dir=$(dirname $0)
echo "source dir: $source_dir"

python3 -m venv python-dev
source $build_dir/python-dev/bin/activate
python3 -m pip install -r $source_dir/requirements.txt
pwd
cd $source_dir
python3 tasks.py download_googletest
cd $build_dir

cmake $source_dir -G "Xcode"
cmake --build $build_dir


