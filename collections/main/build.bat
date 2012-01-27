call vcvars32.bat 

md ..\..\build_output\hash_map_main
cd ..\..\build_output\hash_map_main
cmake %~dp0 -G "NMake Makefiles"
nmake