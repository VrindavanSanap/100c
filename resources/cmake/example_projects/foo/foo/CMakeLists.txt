add_library(foo)

target_sources(foo
  PUBLIC
    FILE_SET foo_headers
    TYPE HEADERS
    BASE_DIRS ./include
    FILES include/foo/foo.h
  PRIVATE 
    foo.cpp
)

