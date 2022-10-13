add_library(zuo STATIC
  zuo.c zuo.h)

target_include_directories(zuo
  PUBLIC
    .)

target_compile_definitions(zuo
  PRIVATE
    ZUO_EMBEDDED)
