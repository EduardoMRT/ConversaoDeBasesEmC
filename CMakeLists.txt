cmake_minimum_required(VERSION 3.28)
project(ConversaoDeBasesEmC C)

set(CMAKE_C_STANDARD 23)

add_executable(ConversaoDeBasesEmC main.c
        structs/pessoa.h)
