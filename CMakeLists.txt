cmake_minimum_required(VERSION 3.10)
set(UNIT_NAME UbicaEngine)

add_subdirectory(Primitives)

set(ENGINE_SOURCES
    Engine/Animation/Animation.cpp 
    Engine/Base/Character.cpp
    Engine/Base/GameObject.cpp
    Engine/Base/DrawableObject.cpp
    Engine/Base/TransformableObject.cpp
    Engine/UI/HealthBar.cpp
    Engine/UI/DamageIndicator.cpp
    Engine/Physics/ObjectsAttractionManager.cpp
    Engine/Particles/ParticleSystem.cpp
    Engine/Base/Pickable.cpp 
    Engine/Core/Timer.cpp 
    Engine/World.cpp
    Engine/GameStateMachine.cpp

    Engine/Animation/Animation.h
    Engine/Base/Character.h 
    Engine/Base/GameObject.h
    Engine/Base/DrawableObject.h
    Engine/Base/TransformableObject.h
    Engine/UI/HealthBar.h
    Engine/UI/DamageIndicator.h
    Engine/Physics/ObjectsAttractionManager.h
    Engine/Particles/ParticleSystem.h
    Engine/Base/Pickable.h 
    Engine/Core/Timer.h 
    Engine/World.h
    Engine/Helpers.hpp
    Engine/Constants.h
    Engine/GameStateMachine.h
    Engine/TimersHolder.hpp
)

add_library(${UNIT_NAME} STATIC ${ENGINE_SOURCES})

target_link_libraries(${UNIT_NAME} PUBLIC Primitives)
target_include_directories(${UNIT_NAME} PUBLIC Engine)
target_include_directories(${UNIT_NAME} PUBLIC nod/include)

install(TARGETS ${UNIT_NAME}
    EXPORT ${UNIT_NAME}Targets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)
