cmake_minimum_required(VERSION 3.20)

project(mylib C)

add_library(${PROJECT_NAME})

set_target_properties(${PROJECT_NAME}
  PROPERTIES
    LINKER_LANGUAGE C
    C_EXTENSIONS OFF
    C_STANDARD 90
    C_STANDARD_REQUIRED ON
)

target_sources(${PROJECT_NAME}
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/src/mylib.c
)

target_include_directories(${PROJECT_NAME}
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(${PROJECT_NAME}
  PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
      m
    >
)
