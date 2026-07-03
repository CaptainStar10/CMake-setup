cmake_minimum_required(VERSION 3.8)
project(ProjectName)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Release>:Release>")

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/dependencies/Application/")

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/dependencies/OpenGL/glfw-3.4/")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/dependencies/OpenGL/glad/")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/dependencies/OpenGL/stb/")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/dependencies/OpenGL/glm/")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/dependencies/OpenGL/noise/")

file(GLOB_RECURSE SourceFilesCPP CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE SourceFilesHPP CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp")
file(GLOB_RECURSE ApplicationFilesCPP CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/dependencies/Application/Application/*.cpp")
file(GLOB_RECURSE ApplicationFilesHPP CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/dependencies/Application/Application/*.hpp")
add_executable(ProjectName "./dependencies/OpenGL/glad.c" "./dependencies/OpenGL/stb/stb.cpp" "${SourceFilesCPP}" "${SourceFilesHPP}" "${ApplicationFilesCPP}" "${ApplicationFilesHPP}")
target_include_directories(ProjectName PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/dependencies/OpenGL/glfw-3.4/include/")
target_include_directories(ProjectName PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/dependencies/OpenGL/glad/include/")
target_include_directories(ProjectName PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/dependencies/OpenGL/stb/include/")
target_include_directories(ProjectName PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/dependencies/OpenGL/glm/")
target_include_directories(ProjectName PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/dependencies/OpenGL/noise/")
target_link_libraries(ProjectName PRIVATE opengl32 glfw stb glad glm noise Application)

if(MSVC)
	target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC _CRT_SECURE_NO_WARNINGS)
	#Removes the console ->
	#set_target_properties("${CMAKE_PROJECT_NAME}" PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
endif()