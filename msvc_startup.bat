set BUILD_DIR=%cd%

set SOURCE_DIR=%~dp0
python3 -m venv python-dev
call %SOURCE_DIR%\python-dev\Scripts\activate.bat
pip install -r %SOURCE_DIR%\requirements.txt

python %SOURCE_DIR%\tasks.py download_googletest
cmake %SOURCE_DIR%
cmake --build %BUILD_DIR%