cmake_minimum_required(VERSION 3.10)
set(UNIT_NAME UbicaEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(SFML)

set(ENGINE_SOURCES
    Engine/Animation/Animation.cpp 
    Engine/Base/Character.cpp
    Engine/Base/GameObject.cpp 
    Engine/UI/HealthBar.cpp 
    Engine/Particles/ParticleSystem.cpp
    Engine/Base/Pickable.cpp 
    Engine/Core/Timer.cpp 
    Engine/World.cpp
    
    Engine/Animation/Animation.h
    Engine/Base/Character.h 
    Engine/Base/GameObject.h 
    Engine/UI/HealthBar.h 
    Engine/Particles/ParticleSystem.h
    Engine/Base/Pickable.h 
    Engine/Core/Timer.h 
    Engine/World.h
    Engine/Helpers.hpp
    Engine/Constants.h
)

add_library(${UNIT_NAME} STATIC ${ENGINE_SOURCES})

target_link_libraries(${UNIT_NAME} PUBLIC
    sfml-system
    sfml-window
    sfml-graphics
    sfml-audio
)

target_link_libraries(${UNIT_NAME} PUBLIC sfml-graphics)
target_link_libraries(${UNIT_NAME} PUBLIC sfml-audio)
target_link_libraries(${UNIT_NAME} PUBLIC sfml-window)
target_link_libraries(${UNIT_NAME} PUBLIC sfml-system)
target_compile_features(${UNIT_NAME} PUBLIC cxx_std_17)
target_include_directories(${UNIT_NAME} PUBLIC Engine PUBLIC SFML/include)

install(TARGETS ${UNIT_NAME}
    EXPORT ${UNIT_NAME}Targets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)

if(WIN32)
    add_custom_command(TARGET ${UNIT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:sfml-system>
            $<TARGET_FILE_DIR:${UNIT_NAME}>
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:sfml-window>
            $<TARGET_FILE_DIR:${UNIT_NAME}>
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:sfml-graphics>
            $<TARGET_FILE_DIR:${UNIT_NAME}>
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:sfml-audio>
            $<TARGET_FILE_DIR:${UNIT_NAME}>
    )
endif()