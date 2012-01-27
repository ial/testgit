include_directories (${HASHMAP_SOURCE_DIR}/hash_map) 

link_directories (${HASHMAP_BINARY_DIR}/hash_map) 

add_executable (hashmapProgram main.cpp) 

target_link_libraries (hashmapProgram hashmap_lib) 
