cmake_minimum_required(VERSION 3.12)
project(OpenGL)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_PLATFORM_INDEPENDENT_CODE ON)

option(BUILD_WINDOWS_GUI_APP "Building executable as Windows GUI application" OFF)

include(cmake/macros.cmake)

# OpenGL
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})

add_subdirectory(Dependencies)

# Enable Win32 GUI App on Windows
set(EXECUTABLE_ARG "")
if(BUILD_WINDOWS_GUI_APP)
    if (WIN32)
        set(EXECUTABLE_ARG "${EXECUTABLE_ARG}WIN32")
    endif()
endif()

#Compiler specific libs
set(ADDITIONAL_LIBS "")
message("*********************")
if (MINGW)
    message("Using MINGW Compiler")
    set(ADDITIONAL_LIBS "${ADDITIONAL_LIBS}mingw32")
elseif(MSVC)
    message("Using Microsoft Visual Compiler")
    set(ADDITIONAL_LIBS "${ADDITIONAL_LIBS}glu32.lib")
endif()
message("*********************")

# Add all included subdirectories
foreach (_incl ${INCLUDE_PATHS})
    include_directories(${_incl})
endforeach()

add_executable(${PROJECT_NAME} ${EXECUTABLE_ARG} ${ENGINE_SOURCE} main.cpp)

# -I

# -L
# Tells the linker what to link
target_link_libraries(${PROJECT_NAME} ${OPENGL_gl_LIBRARY} ${ADDITIONAL_LIBS} glfw GLEW)