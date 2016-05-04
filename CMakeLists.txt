cmake_minimum_required (VERSION 2.8.7)
project (diglett)

#include_directories("include/")

find_package(Threads)
#set_property(TARGET diglett PROPERTY C_STANDARD 99)
#set(CMAKE_C_FLAGS "-std=c99")

file(
  GLOB_RECURSE
  source_files
  src/*
  include/*
  test/*
)

add_executable(
  diglett
  src/main_client.c
  ${source_files}
)

target_link_libraries(diglett ${CMAKE_THREAD_LIBS_INIT} )
