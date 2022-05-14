cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard
set(CMAKE_CXX_STANDARD_REQUIRED ON)   # Enable c++14 standard
project(clientTests VERSION 1)

include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
FetchContent_MakeAvailable(googletest)

# Now link against gtest or gtest_main.
add_executable(serverTests serverTests.cpp)
target_link_libraries(serverTests gtest_main pthread)
enable_testing()

include(GoogleTest)
gtest_discover_tests(serverTests)