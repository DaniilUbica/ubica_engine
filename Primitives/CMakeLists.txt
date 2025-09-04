cmake_minimum_required(VERSION 3.10)
set(UNIT_NAME Primitives)

option(USE_SFML "Use SFML as engine's graphic lib" ON)

set(DEFINES)

if(USE_SFML)
    set(DEFINES ${DEFINES} -DUSE_SFML)
    add_subdirectory(Impls/SFMLBased)
endif()

set(PRIMITIVES_SOURCES
    Sprite/Sprite.cpp
    Vector2/Vector2.cpp
    Rect/Rect.cpp
    
    Sprite/Sprite.h
    Sprite/Interface/ISprite.h
    Sprite/Interface/SpriteFactory.h
    
    Vector2/Vector2.h
    Vector2/Interface/IVector2.h
    Vector2/Interface/Vector2Factory.h

    Rect/Rect.h
    Rect/Interface/IRect.h
    Rect/Interface/RectFactory.h
)

add_library(${UNIT_NAME} STATIC ${PRIMITIVES_SOURCES})

set(INCLUDE_DIRS 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/Sprite
)

if(USE_SFML) 
    target_link_libraries(${UNIT_NAME} PUBLIC SFMLBased)
endif()

target_include_directories(${UNIT_NAME} PUBLIC ${INCLUDE_DIRS})

target_compile_definitions(${UNIT_NAME} PUBLIC ${DEFINES})

install(TARGETS ${UNIT_NAME}
    EXPORT ${UNIT_NAME}Targets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include/Primitives
)