cmake_minimum_required(VERSION 3.10)
project(UbicaEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 3.0 COMPONENTS graphics window system audio REQUIRED)

file(GLOB_RECURSE ENGINE_SOURCES 
    "src/*.cpp"
    "src/*.hpp"
)

add_library(${CMAKE_PROJECT_NAME} STATIC ${ENGINE_SOURCES})

target_link_libraries(${CMAKE_PROJECT_NAME} 
    PUBLIC SFML::Graphics SFML::Window SFML::System SFML::Audio
)

target_include_directories(${CMAKE_PROJECT_NAME}
    PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

install(TARGETS ${CMAKE_PROJECT_NAME}
    EXPORT ${CMAKE_PROJECT_NAME}Targets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)