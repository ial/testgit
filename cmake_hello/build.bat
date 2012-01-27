call vcvars32.bat 

md ..\build_output\cmake_hello
cd ..\build_output\cmake_hello
cmake %~dp0 -G "NMake Makefiles"
nmake