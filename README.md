# Cpp development environment

## Get Ubuntu env by Docker

```bash
cd docker
docker build -t cppdev .
docker-compose up -d
docker exec -it cppdev bash
```

## Ubuntu

### Requirments

* python3
* pip3
* python3-venv (options for python virtual env)

### Set up tasks runner env

```bash
source startup.sh
# or
source startup-venv.sh # for virtual env
```

### Build Code

```bash
python3 tasks.py [task]
```

### Run Test

```bash
./build/cpp_build/test_processing
./build/cpp_build/leetcode/test_all
./build/cpp_build/tools/test_tools
```

## Windows

TBD

## MacOS

TBD