project(test)

add_library(
  file_lib
  SHARED
  util.h
  util.c
)

add_executable(average_test average_test.c)
add_executable(compare_test compare_test.c)

target_link_libraries(average_test file_lib)
target_link_libraries(compare_test file_lib)
