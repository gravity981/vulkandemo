@echo off
call compile_shaders.bat
mkdir build 2>nul
pushd build
cmake -G "Visual Studio 15 2017" ..
popd
pause