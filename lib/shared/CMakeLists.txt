cmake_minimum_required(VERSION 3.20)

project(shared C)

add_library(${PROJECT_NAME} SHARED)

set_target_properties(${PROJECT_NAME}
  PROPERTIES
    WINDOWS_EXPORT_ALL_SYMBOLS ON
    LINKER_LANGUAGE C
    C_EXTENSIONS OFF
    C_STANDARD 90
    C_STANDARD_REQUIRED ON
)

target_sources(${PROJECT_NAME}
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/src/shared.c
)

target_include_directories(${PROJECT_NAME}
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include
)

target_compile_options(${PROJECT_NAME}
  PRIVATE
    $<$<OR:$<C_COMPILER_ID:Clang>,$<C_COMPILER_ID:GNU>>:
      -Wconversion
    >
)

target_link_libraries(${PROJECT_NAME}
  PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
      m
    >
)
