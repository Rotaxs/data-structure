cmake_minimum_required(VERSION 3.20)

project(
    HashTable
    VERSION 1.0
    LANGUAGES C
)

add_library(hashTable)

target_compile_features(hashTable PUBLIC
    c_std_17
)

target_sources(hashTable PRIVATE
    src/hash_table.c
)

target_include_directories(hashTable PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)