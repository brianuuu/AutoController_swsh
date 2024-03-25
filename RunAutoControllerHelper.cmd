cd %~dp0

if not exist AutoControllerHelper\ (
    echo.
    echo Please unzip the folder before you can use it.
    echo.
    pause
    exit
)

if not exist AutoControllerHelper\AutoControllerHelper.exe (
    echo.
    echo AutoControllerHelper\AutoControllerHelper.exe not found. Did your anti-virus delete it?
    echo.
    pause
    exit
)

cd AutoControllerHelper
start "" AutoControllerHelper.exe
