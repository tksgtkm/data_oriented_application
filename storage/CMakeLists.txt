project(test)

add_library(
  file_lib
  SHARED
  file_structure.h
  file_structure.c
)

add_executable(test test.c)

target_link_libraries(test file_lib)
