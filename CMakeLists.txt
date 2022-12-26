cmake_minimum_required(VERSION 3.24)
project(CoinkGL_engine_2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
include_directories(${INCLUDE_DIR})

set(COINK_GL_DIR ${CMAKE_SOURCE_DIR}/include/coink_gl)
include_directories(${COINK_GL_DIR})

set(GLFW_LIB_DIR ${CMAKE_SOURCE_DIR}/lib/GLFW)
set(FREETYPE_LIB_DIR ${CMAKE_SOURCE_DIR}/lib/freetype)
set(GLFW_LIB_DIR ${CMAKE_SOURCE_DIR}/lib/GLFW)
link_directories(${GLFW_LIB_DIR})
link_directories(${FREETYPE_LIB_DIR})
link_directories(${GLFW_LIB_DIR})

set(GLAD_SRC ${PROJECT_SOURCE_DIR}/src/glad.c)
set(STB_SRC ${PROJECT_SOURCE_DIR}/src/stb.c)

file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)
add_executable(${PROJECT_NAME} ${GLAD_SRC} ${STB_SRC} ${SOURCES})
target_link_libraries(${PROJECT_NAME} glfw3 glfw3dll freetype)
