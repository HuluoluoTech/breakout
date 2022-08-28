cmake_minimum_required (VERSION 3.23)

if (POLICY CMP0074)
  cmake_policy(SET CMP0074 NEW)
endif ()

set(PROJECTNAME breakout)
project(${PROJECTNAME})

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/configuration/root_directory.h.in ${CMAKE_CURRENT_SOURCE_DIR}/configuration/root_directory.h)

message(STATUS ${PROJECT_SOURCE_DIR})
message(STATUS ${CMAKE_CURRENT_SOURCE_DIR}/libs/)

set(CMAKE_CXX_STANDARD 17) # this does nothing for MSVC, use target_compile_options below
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_CXX_FLAGSD "${CMAKE_CXX_FLAGS} -O0 -Wall -g -ggdb -fno-rtti")

link_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/libs/
)

aux_source_directory(src DIR_MAIN_SRCS)
add_executable(${PROJECTNAME} ${DIR_MAIN_SRCS})

# include header path
target_include_directories(${PROJECTNAME} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/includes/>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/includes/breakout/>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/configuration/>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/includes/irrKlang/>)

# Link libs
target_link_libraries(${PROJECTNAME} -lglfw)
target_link_libraries(${PROJECTNAME} -lpthread)
target_link_libraries(${PROJECTNAME} -ldl)
target_link_libraries(${PROJECTNAME} -lGL)
target_link_libraries(${PROJECTNAME} -lIrrKlang)

# freetype needed
target_link_libraries(${PROJECTNAME} -lfreetype)
target_link_libraries(${PROJECTNAME} -lpng)
target_link_libraries(${PROJECTNAME} -lbz2)     # bzip2
target_link_libraries(${PROJECTNAME} -lz)       # gzip