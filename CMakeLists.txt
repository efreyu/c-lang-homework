cmake_minimum_required(VERSION 3.12)
project(c_lang_homework C)

set(CMAKE_C_STANDARD 99)

add_executable(c_lang_homework algorithm/lesson4/hw.c)

target_link_libraries(c_lang_homework m)