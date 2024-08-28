@echo off
cls
echo  Setup required Environment
echo -------------------------------------
REM MinGW
SET "COMPILER_PATH=C:\minGW\bin"
SET "CC=%COMPILER_PATH%\gcc"
SET "LDFLAGS=-lSDL2"
REM Cygwin
REM SET "CC=gcc"
REM SET "LDFLAGS=-lsdl2"
REM SET "CFLAGS=`sdl2-config --cflags --libs`"
echo off
echo  Clean latest build
echo ------------------------
SET "NAME_EXE=%1"
IF [%2] NEQ [] SET "NAME_EXE=%2"
REM Binary Executable
REM IF EXIST bin\%NAME_EXE%.exe del /F bin\%NAME_EXE%.exe
REM ROM Executable
IF EXIST bin\%NAME_EXE%.gb del /F bin\%NAME_EXE%.gb
echo off
echo  Copy File Dependency
echo -----------------------
copy .\etc\SDL2.dll .\bin\SDL2.dll
copy .\etc\blockdude-sprite.bmp .\bin\etc\blockdude-sprite.bmp
copy .\etc\charmap.bmp  .\bin\etc\charmap.bmp
copy .\etc\maptile.txt  .\bin\etc\maptile.txt
echo off
echo  Compile program
echo -----------------------
rem %CC% --version
%CC% -o bin\%NAME_EXE%.exe %1.c %LDFLAGS%  %3
echo off
echo  Execute program
echo -----------------------
IF EXIST bin\%NAME_EXE%.exe bin\%NAME_EXE%.exe