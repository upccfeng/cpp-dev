# Cpp development environment

## MSVC in Windows

### Requirments

* python3
* python3-venv (optional)
* cmake & make

### Build

```bat
REM "git clone https://github.com/upccfeng/cpp-dev.git" as <SOURCE_DIR>

mkdir <BUILD_DIR>

REM Setting virtualenv (optional)
cd <BUILD_DIR>
python3 -m virtualenv python-dev
call .\python-dev\Scripts\activate.bat

REM Build
cd <SOURCE_DIR>
python3 -m pip install -r requirements.txt
python3 build.py msvc --build-dir <BUILD_DIR>

REM Open with MSVC
cd <BUILD_DIR>
start .\test_cppdev.sln
```

## Xcode in MacOS

### Requirments

* python3
* python3-venv (optional)
* cmake & make

### Build

```bash
# "git clone https://gtihub.com/upccfeng/cpp-dev.git" as <SOURCE_DIR>

mkdir <BUILD_DIR>

# Setting virtualenv (optional)
cd <BUILD_DIR>
python3 -m venv python-dev
source ./python-dev/bin/activate

# Build
cd <SOURCE_DIR>
python3 -m pip install -r requirements.txt
python3 build.py xcode --build-dir <BUILD_DIR>

# Open with Xcode
cd <BUILD_DIR>
open ./test_cppdev.xcodeproj
```

## VSCode in Linux

### Requirments

* python3
* python3-venv (optional)
* cmake & make

### Build

```bash
# "git clone https://gtihub.com/upccfeng/cpp-dev.git" as <SOURCE_DIR>

mkdir <BUILD_DIR>

# Setting virtualenv (optional)
cd <BUILD_DIR>
python3 -m venv python-dev
source ./python-dev/bin/activate

# Build
cd <SOURCE_DIR>
python3 -m pip install -r requirements.txt
python3 build.py vscode --build-dir <BUILD_DIR>

# Open with VSCode
cd <SOURCE_DIR>
code .
```

### Run Test

```bash
cd <BUILD_DIR>

./processing/test_processing
./leetcode/test_all
./tools/test_tools
```

### Get Ubuntu env by Docker

```bash
cd docker
docker build -t cppdev .
docker-compose up -d
docker exec -it cppdev bash
```