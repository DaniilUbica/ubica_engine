cmake_minimum_required(VERSION 3.10)
set(UNIT_NAME Primitives)

option(USE_SFML "Use SFML as engine's graphic lib" ON)

if(USE_SFML)
    add_subdirectory(Impls/SFMLBased)
endif()

set(PRIMITIVES_SOURCES
    Sprite/Sprite.cpp
    
    Sprite/Sprite.h
    Sprite/Interface/ISprite.h
    Sprite/Interface/SpriteFactory.h
)

if(USE_SFML)
    list(APPEND PRIMITIVES_SOURCES
        Impls/SFMLBased/Sprite/SFMLSprite.cpp
        Impls/SFMLBased/Sprite/SFMLSprite.h
    )
endif()

add_library(${UNIT_NAME} STATIC ${PRIMITIVES_SOURCES})

set(INCLUDE_DIRS 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/Sprite
)

if(USE_SFML) 
    target_link_libraries(${UNIT_NAME} PUBLIC Impls/SFMLBased)
endif()

target_include_directories(${UNIT_NAME} PUBLIC ${INCLUDE_DIRS})

install(TARGETS ${UNIT_NAME}
    EXPORT ${UNIT_NAME}Targets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include/Primitives
)