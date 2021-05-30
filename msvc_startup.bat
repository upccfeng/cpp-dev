set BUILD_DIR=%cd%

set SOURCE_DIR=%~dp0
python3 -m virtualenv python-dev
call %BUILD_DIR%\python-dev\Scripts\activate.bat
python3 -m pip install -r %SOURCE_DIR%\requirements.txt

cd %SOURCE_DIR%
python3 tasks.py download_googletest
cd %BUILD_DIR%

cmake %SOURCE_DIR%
cmake --build %BUILD_DIR%