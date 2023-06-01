# CMake C template

template for C projects, using modern CMake

## using

- target-specific definition for main executable
- target-specific include directories for targets
- global warning compile options
- target-specific compile options (dummy unshared warnings)
- disabling C++ via project()'s LANGUAGES C
- turning off C extensions
- setting C standard
- target installation (executable)
- simple shared/dynamic library
- simple static library
- simple library that can be static or shared
- "app library" ("app business logic" that's object files, see cmake's Object Libraries)

## to do

- test windows feature parity
- make installer
  * NSIS is in cmake book
  * Linux?
- add tests
  * tests must compile and run quickly, see [doctest](https://github.com/doctest/doctest)
