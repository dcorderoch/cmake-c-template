cmake_minimum_required(VERSION 3.20)

project(custom C)

# this can be compiled statically or dynamically setting
# the BUILD_SHARED_LIBS option off or on respectively
add_library(${PROJECT_NAME})

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
    ${CMAKE_CURRENT_LIST_DIR}/src/custom.c
)

target_include_directories(${PROJECT_NAME}
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include
)

# install .so/.dll, but no .a if built as static library
if (BUILD_SHARED_LIBS)
  install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
    LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
    # NOTE: I don't want this, but this is how the .lib file would be installed on windows
    # ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/${PROJECT_NAME}
  )
endif (BUILD_SHARED_LIBS)
