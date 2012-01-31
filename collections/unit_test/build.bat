call vcvars32.bat 

md ..\..\build_output\hash_map_test
cd ..\..\build_output\hash_map_test
cmake %~dp0 -G "NMake Makefiles"
nmake