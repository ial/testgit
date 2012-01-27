call vcvars32.bat 

md ..\build_output\google_test
cd ..\build_output\google_test
cmake %~dp0 -G "NMake Makefiles" -Dgtest_force_shared_crt:BOOL=ON
nmake