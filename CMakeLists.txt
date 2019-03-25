cmake_minimum_required(VERSION 3.13)
project(tcp)

set(CMAKE_CXX_STANDARD 14)

add_executable(tcp main.cpp )
add_executable(select  select.cpp )
add_executable(week  week.c)
add_executable(reverse  reverse.c )
add_executable(bad bad_ret.c m.h)
add_executable(kill_man kill_man.c)