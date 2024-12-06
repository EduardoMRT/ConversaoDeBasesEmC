cmake_minimum_required(VERSION 3.28)
project(ConversaoDeBasesEmC C)

set(CMAKE_C_STANDARD 23)

set(CURL_INCLUDE_DIRS "${CMAKE_SOURCE_DIR}/curl-8.11.0_4-win64-mingw/include")
set(CURL_LIBRARIES "${CMAKE_SOURCE_DIR}/curl-8.11.0_4-win64-mingw/lib/libcurl.a")

include_directories(${CURL_INCLUDE_DIRS})

add_executable(ConversaoDeBasesEmC main.c structs/pessoa.h)

target_link_libraries(ConversaoDeBasesEmC ${CURL_LIBRARIES})

