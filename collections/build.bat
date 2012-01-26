call vcvars32.bat 

md ..\build_output\hash_map
cd ..\build_output\hash_map
cmake %~dp0 -G "NMake Makefiles"
nmake