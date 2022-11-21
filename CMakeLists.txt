cmake_minimum_required(VERSION 3.12.4)

set(PATCH_VERSION "2" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(cmd7 VERSION ${PROJECT_VESRION})

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(SRC_PATH "src/")
set(CMAKE_EXE_LINKER_FLAGS " -static")
include_directories("src/")
include_directories(
        ../include
)

add_library(
        bulk_obj
        ${SRC_PATH}/bulkman.cpp
        ${SRC_PATH}/bulksubs.cpp
        ${SRC_PATH}/buffhandlers.cpp
)

add_executable(bulk ${SRC_PATH}/bulk.cpp)
target_link_libraries(bulk bulk_obj -static-libgcc -static-libstdc++)

add_executable(gtest-bulkman ${SRC_PATH}/gtest-bulkman.cpp)
target_link_libraries(gtest-bulkman
        gtest_main
        bulk_obj
        ${CMAKE_THREAD_LIBS_INIT}
        )

install(TARGETS bulk RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)
enable_testing()
add_test(GOOGLE_TEST1 gtest-bulkman)
