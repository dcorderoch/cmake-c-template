cmake_minimum_required(VERSION 3.20)

project(template
  DESCRIPTION "CMake template for C project"
  LANGUAGES C
)

add_executable(${PROJECT_NAME})

set_target_properties(${PROJECT_NAME}
  PROPERTIES
    LINKER_LANGUAGE C
    C_EXTENSIONS OFF
    C_STANDARD 99
    C_STANDARD_REQUIRED ON
)

target_sources(${PROJECT_NAME}
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/src/main.c
)

target_compile_options(${PROJECT_NAME}
  PRIVATE
    $<$<OR:$<C_COMPILER_ID:Clang>,$<C_COMPILER_ID:GNU>>:
      -Wall
      -Werror
      -Wextra
      -pedantic
    >
)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)