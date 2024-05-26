cmake_minimum_required(VERSION 3.0.0)
project(opengl VERSION 0.1.0 LANGUAGES C)

include(CTest)
enable_testing()

add_executable(opengl hellogl.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})


target_link_libraries(opengl glew)
target_link_libraries(opengl SDL2)

include(CPack)
