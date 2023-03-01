cmake_minimum_required(VERSION 3.17)
project(Server C)

set(CMAKE_C_STANDARD 99)

add_executable(Server AddressUtility.c DieWithMessage.c Practical.h TCPEchoServer.c TCPServerUtility.c)