cmake_minimum_required(VERSION 3.0.0)
project(opengl_atividade VERSION 0.1.0 LANGUAGES C)

include(CTest)
enable_testing()
add_executable(${PROJECT_NAME} hellogl.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})


# Open GL
find_package(OpenGL REQUIRED) # Add this line
include_directories(${OPENGL_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES})
target_link_libraries(${PROJECT_NAME} glfw)

# GLEW
find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})
link_libraries(${GLEW_LIBRARIES})

# SDL2
find_package(SDL2 REQUIRED)
include_directories(${PROJECT_NAME} ${SDL2_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})


# cglm fetch
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)

fetchcontent_declare(
  cglm
  GIT_REPOSITORY https://github.com/recp/cglm.git
  GIT_TAG v0.8.5
  GIT_PROGRESS TRUE
)

if(NOT cglm_POPULATED)
  message("populating cglm")
  fetchcontent_populate(cglm)
  add_subdirectory(${cglm_SOURCE_DIR} ${cglm_BUILD_DIR})
endif()

# Lib Math e CGLM
target_link_libraries(${PROJECT_NAME} cglm)
target_link_libraries(${PROJECT_NAME}  m)


include(CPack)
