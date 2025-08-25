cmake_minimum_required(VERSION 3.10)
set(UNIT_NAME UbicaEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.x)
FetchContent_MakeAvailable(SFML)

set(ENGINE_SOURCES
    src/Animation.cpp 
    src/Character.cpp 
    src/GameObject.cpp 
    src/HealthBar.cpp 
    src/ParticleSystem.cpp
    src/Pickable.cpp 
    src/Timer.cpp 
    src/World.cpp
    
    include/Animation.h 
    include/Character.h 
    include/Constants.h 
    include/GameObject.h 
    include/Helpers.hpp 
    include/ParticleSystem.h 
    include/Pickable.h 
    include/Timer.h 
    include/UI/HealthBar.h
    include/World.h
)

add_library(${UNIT_NAME} STATIC ${ENGINE_SOURCES})

target_link_libraries(${UNIT_NAME} PRIVATE sfml-graphics)
target_link_libraries(${UNIT_NAME} PRIVATE sfml-audio)
target_link_libraries(${UNIT_NAME} PRIVATE sfml-window)
target_link_libraries(${UNIT_NAME} PRIVATE sfml-system)
target_compile_features(${UNIT_NAME} PRIVATE cxx_std_17)
target_include_directories(${UNIT_NAME} PRIVATE include)

install(TARGETS ${UNIT_NAME}
    EXPORT ${UNIT_NAME}Targets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)