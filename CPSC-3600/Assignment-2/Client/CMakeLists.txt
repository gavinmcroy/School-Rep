cmake_minimum_required(VERSION 3.17)
project(Client C)

set(CMAKE_C_STANDARD 99)

add_executable(Client DieWithMessage.c Practical.h TCPClientUtility.c TCPEchoClient.c)