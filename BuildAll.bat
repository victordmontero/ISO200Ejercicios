cd src
for %%i in (dir *.c) do (
    gcc -I../include -L../lib -lxl %%i -o ../bin/%%i.exe
    copy /Y ..\lib\libxl.dll ..\bin
)
cd ..