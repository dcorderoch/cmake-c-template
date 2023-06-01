cmake_minimum_required(VERSION 3.20)

project(template
  DESCRIPTION "CMake template for C project"
  LANGUAGES C
)

# generator expressions are not available for multiple compiler options
# in a single expression, so here global compiler options are set
# explicitly, as most warning options would be repeated in all
# target-specific compiler options, this might also be the place to
# enable LTO
if (WIN32)
  if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(GLOBAL_CFLAGS /W3)
  endif ()
  if (CMAKE_BUILD_TYPE STREQUAL "Release")
    set(GLOBAL_CFLAGS /O2)
  endif ()
else ()
  if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(GLOBAL_CFLAGS -Wall -Wextra -Werror -pedantic -Wmissing-declarations)
  endif ()
  if (CMAKE_BUILD_TYPE STREQUAL "Release")
    set(GLOBAL_CFLAGS -O2)
  endif ()
endif (WIN32)

add_compile_options(${GLOBAL_CFLAGS})

add_subdirectory(lib)

add_executable(${PROJECT_NAME})

set_target_properties(${PROJECT_NAME}
  PROPERTIES
    LINKER_LANGUAGE C
    C_EXTENSIONS OFF
    C_STANDARD 99
    C_STANDARD_REQUIRED ON
    SKIP_BUILD_RPATH FALSE
    INSTALL_RPATH "$ORIGIN/../lib"
    BUILD_RPATH_USE_ORIGIN TRUE
    BUILD_WITH_INSTALL_RPATH FALSE
    INSTALL_RPATH_USE_LINK_PATH TRUE
)

target_sources(${PROJECT_NAME}
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/src/main.c
)

target_compile_definitions(${PROJECT_NAME}
  PRIVATE
    TEST_DEFINE=37
)

target_compile_options(${PROJECT_NAME}
  PRIVATE
    $<$<OR:$<C_COMPILER_ID:Clang>,$<C_COMPILER_ID:GNU>>:
      -Wcomment
    >
)

set(APP_LOGIC app)

add_library(${APP_LOGIC} OBJECT)

target_sources(${APP_LOGIC}
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/src/point.c
)

target_include_directories(${APP_LOGIC}
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(${PROJECT_NAME}
  PRIVATE
    shared
    static
    custom
    ${APP_LOGIC}
)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
