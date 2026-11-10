cmake_minimum_required(VERSION 3.21)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)

project(Primer-mod)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

add_library(${PROJECT_NAME} SHARED ${SOURCES})

set(GEODE_SDK_PATH "$ENV{GEODE_SDK}")

if (NOT GEODE_SDK_PATH)
    set(GEODE_SDK_PATH "${CMAKE_CURRENT_SOURCE_DIR}/..")
endif()

if (NOT EXISTS "${GEODE_SDK_PATH}/CMakeLists.txt")
    message(FATAL_ERROR
        "Unable to find Geode SDK! Please define GEODE_SDK environment variable to point to Geode"
    )
else()
    message(STATUS "Found Geode: ${GEODE_SDK_PATH}")
endif()

add_subdirectory(
    "${GEODE_SDK_PATH}"
    "${CMAKE_CURRENT_BINARY_DIR}/geode"
)

setup_geode_mod(${PROJECT_NAME})
