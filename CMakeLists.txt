cmake_minimum_required(VERSION 3.23)
project(psuedo C)

set(CMAKE_C_STANDARD 99)

add_executable(psuedo main.c ASTNode.c equationParser.c)
