cmake_minimum_required(VERSION 3.20)
project(femto_re)

set(CMAKE_CXX_STANDARD 20)

add_executable(femto_re femto-re.cpp femto-re.h characters.h token.cpp token.h parse.cpp parse.h node.cpp node.h bmp.h character.cpp util.h util.cpp)
