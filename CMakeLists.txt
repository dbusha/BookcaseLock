# Define CMake's minimum version (must-do) and the project's name and supported languages
cmake_minimum_required(VERSION 3.8)
project(BookcaseLock LANGUAGES C CXX ASM)

# Call a framework utility function, passing it information about the hardware board that will
# be used - This function returns a structure known only to the framework
get_board_id(board_id trinket3)

file(GLOB SOURCES src/*.cpp)

# Create an executable suitable for the Arduino firmware using CMake-style target-creation
add_arduino_executable(BookcaseLock ${board_id} ${SOURCES})

# Upload the created target through a connected Serial Port (Where your board is connected to)
#upload_arduino_target(BookcaseLock "${board_id}" "")

# Generate .ino file for Arduino IDE
# Todo: Make architecture agnostic
set(INO_FILE ${PROJECT_SOURCE_DIR}/BookcaseLock.ino)
set(INO_FILE_HEADER "// This file is autogenerated from src/Bookcase_lock_ino.cpp for the Arduino IDE")
message(STATUS Generating ${INO_FILE})

add_custom_command(TARGET ${PROJECT_NAME}
        PRE_BUILD
        COMMAND echo ${INO_FILE_HEADER} > ${INO_FILE})

add_custom_command(TARGET ${PROJECT_NAME}
        PRE_BUILD
        COMMAND cat ${PROJECT_SOURCE_DIR}/src/bookcase_lock_ino.cpp >> ${INO_FILE})
