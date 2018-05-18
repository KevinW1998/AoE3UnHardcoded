@echo off
mkdir build-vs2017
cd build-vs2017
cmake ../. -G "Visual Studio 15 2017" -T "v141" -DCMAKE_INSTALL_PREFIX=%cd%/../build-vs2017-install
pause
