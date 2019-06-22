cmake_minimum_required(VERSION 2.8)
project(screeps-api)

include(${CMAKE_CURRENT_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

file(GLOB SOURCES "src/*.cpp")
add_library(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC include PRIVATE ${CONAN_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${CONAN_LIBS})

install(TARGETS ${PROJECT_NAME}
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib)
  
install(FILES
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME}.wasm
  DESTINATION bin)
