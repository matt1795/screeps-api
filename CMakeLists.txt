cmake_minimum_required(VERSION 3.0)
project(screeps-api)

include(${CMAKE_CURRENT_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

file(GLOB SOURCES "src/*.cpp")
add_library(${PROJECT_NAME} ${SOURCES})

message(STATUS ${CMAKE_SYSTEM_NAME})
message(STATUS ${EMSCRIPTEN_ROOT_PATH})

target_include_directories(${PROJECT_NAME}
    PUBLIC include 
    PRIVATE ${CONAN_INCLUDE_DIRS}
)
target_link_libraries(${PROJECT_NAME} PRIVATE ${CONAN_LIBS})
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17 cxx_auto_type)

install(TARGETS ${PROJECT_NAME}
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib)
  
install(FILES
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME}.wasm
  DESTINATION bin)
