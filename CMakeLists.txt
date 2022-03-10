cmake_minimum_required(VERSION 3.20)
project(femto_re)

set(CMAKE_CXX_STANDARD 20)

# external modules
find_package(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GTKMM3 REQUIRED gtkmm-3.0)
PKG_CHECK_MODULES(PANGOMM REQUIRED pangomm-1.4)

INCLUDE_DIRECTORIES(${GTKMM3_INCLUDE_DIRS})
LINK_DIRECTORIES(${GTKMM3_LIBRARY_DIRS})
ADD_DEFINITIONS(${GTKMM3_CFLAGS_OTHER})

INCLUDE_DIRECTORIES(${PANGOMM_INCLUDE_DIRS})
LINK_DIRECTORIES(${PANGOMM_LIBRARY_DIRS})
ADD_DEFINITIONS(${PANGOMM_CFLAGS_OTHER})

add_executable(femto_re femto-re.cpp femto-re.h characters.h token.cpp token.h parse.cpp parse.h node.cpp node.h bmp.h character.cpp util.h util.cpp window.h window.cpp Command.cpp Command.h render.cpp render.h)
TARGET_LINK_LIBRARIES(femto_re ${GTKMM3_LIBRARIES} "-pthread")
