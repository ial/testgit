call vcvars32.bat 

md ..\..\build_output\expressor_test
cd ..\..\build_output\expressor_test
cmake %~dp0 -G "NMake Makefiles"
nmake