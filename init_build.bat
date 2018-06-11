@echo off
mkdir build 2>nul
cd build
cmake -G "Visual Studio 15 2017" ..
pause