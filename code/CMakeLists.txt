cmake_minimum_required(VERSION 3.0)
project(html-parser)
set(CMAKE_BUILD_TYPE Debug)
set(sources main.cpp
	CommandLineParser.cpp
	Logger.cpp
	)
add_executable(${PROJECT_NAME} ${sources})
target_link_libraries(${PROJECT_NAME} gq gumbo)
