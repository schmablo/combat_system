cmake_minimum_required(VERSION 3.20)
project(CombatSystem LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra -Wpedantic -Werror)

enable_testing()

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
FetchContent_MakeAvailable(googletest)

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS src/*.cpp)

set(HEADER_DIRS ${CMAKE_SOURCE_DIR}/include)

# Remove main.cpp from SRC_FILES to avoid adding it to the library
list(FILTER SRC_FILES EXCLUDE REGEX ".*main.cpp")

add_library(combat STATIC ${SRC_FILES})
target_include_directories(combat PUBLIC ${HEADER_DIRS})

# Add executable with main.cpp
add_executable(combat_system src/main.cpp)
target_link_libraries(combat_system PRIVATE combat)
target_include_directories(combat_system PUBLIC ${HEADER_DIRS})

file(GLOB_RECURSE TEST_FILES CONFIGURE_DEPENDS tests/*.cpp)

add_executable(tests ${TEST_FILES})
target_link_libraries(tests combat gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)
