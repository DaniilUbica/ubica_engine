cmake_minimum_required(VERSION 3.10)
set(UNIT_NAME UbicaEngine)

add_subdirectory(Primitives)

set(ENGINE_SOURCES
    Engine/Animation/Animation.cpp 
    Engine/Base/Character.cpp
    Engine/Base/GameObject.cpp
    Engine/Base/DrawableObject.cpp
    Engine/Base/TransformableObject.cpp
    Engine/DataBase/DataBaseManager.cpp
    Engine/UI/UIComponents/HealthBar.cpp
    Engine/UI/UIComponents/DamageIndicator.cpp
    Engine/UI/GameScreen/GameScreenManager.cpp
    Engine/Physics/ObjectsAttractionManager.cpp
    Engine/UI/GameScreen/GameScreenBase.cpp
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
    Engine/DataBase/DataBaseManager.h
    Engine/DataBase/DataBaseRequestData.h
    Engine/DataBase/sqlite3_pointer.h
    Engine/DataBase/sqlite3_helpers.h
    Engine/UI/UIComponents/HealthBar.h
    Engine/UI/UIComponents/DamageIndicator.h
    Engine/UI/GameScreen/GameScreenManager.h
    Engine/UI/GameScreen/GameScreenBase.h
    Engine/Physics/ObjectsAttractionManager.h
    Engine/Particles/ParticleSystem.h
    Engine/Base/Pickable.h 
    Engine/Core/Timer.h 
    Engine/World.h
    Engine/Helpers.hpp
    Engine/Constants.h
    Engine/GameStateMachine.h
    Engine/TimersHolder.hpp
    Engine/IGameManager.h
)

add_library(${UNIT_NAME} STATIC ${ENGINE_SOURCES})

find_package(SQLite3 REQUIRED)

target_link_libraries(${UNIT_NAME} PUBLIC Primitives SQLite::SQLite3)
target_include_directories(${UNIT_NAME} PUBLIC Engine)
target_include_directories(${UNIT_NAME} PUBLIC nod/include)

macro(GroupSources curdir)
    file(GLOB children RELATIVE ${PROJECT_SOURCE_DIR}/${curdir} ${PROJECT_SOURCE_DIR}/${curdir}/*)
    foreach(child ${children})
        if(IS_DIRECTORY ${PROJECT_SOURCE_DIR}/${curdir}/${child})
            GroupSources(${curdir}/${child})
        else()
            string(REPLACE "/" "\\" groupname ${curdir})
            source_group(${groupname} FILES ${PROJECT_SOURCE_DIR}/${curdir}/${child})
        endif()
    endforeach()
endmacro()

GroupSources(ubica_engine)

install(TARGETS ${UNIT_NAME}
    EXPORT ${UNIT_NAME}Targets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)
