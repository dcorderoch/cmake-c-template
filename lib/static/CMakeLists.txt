cmake_minimum_required(VERSION 3.20)

project(static C)

add_library(${PROJECT_NAME} STATIC)

set_target_properties(${PROJECT_NAME}
  PROPERTIES
    LINKER_LANGUAGE C
    C_EXTENSIONS OFF
    C_STANDARD 90
    C_STANDARD_REQUIRED ON
)

target_sources(${PROJECT_NAME}
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/src/static.c
)

target_include_directories(${PROJECT_NAME}
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include
)

target_compile_options(${PROJECT_NAME}
  PRIVATE
    $<$<OR:$<C_COMPILER_ID:Clang>,$<C_COMPILER_ID:AppleClang>,$<C_COMPILER_ID:GNU>>:
      -Wno-sign-conversion
    >
)

target_link_options(${PROJECT_NAME}
  PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
      -fuse-ld=mold
    >
)
