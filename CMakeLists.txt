cmake_minimum_required(VERSION 3.10)
project(gdnative_class_factory VERSION 0.1)
set(GODOT_CUSTOM_API_FILE "${CMAKE_CURRENT_SOURCE_DIR}/api.json" CACHE STRING "")
add_subdirectory(godot-cpp)
add_library(${PROJECT_NAME} 
SHARED
src/ClassFactoryManager.cpp 
src/modules/Dummy.cpp
src/modules/NativeLabelController.cpp
src/gdlibrary.cpp 
)
target_include_directories(${PROJECT_NAME}
PUBLIC
${CMAKE_CURRENT_SOURCE_DIR}/src
${CMAKE_CURRENT_SOURCE_DIR}/godot-cpp/include/core
${CMAKE_CURRENT_SOURCE_DIR}/godot-cpp/include/gen
)
target_link_libraries(${PROJECT_NAME} godot-cpp)
install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_SYSTEM_NAME}/${CMAKE_SYSTEM_PROCESSOR})