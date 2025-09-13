cmake_minimum_required(VERSION 3.10)
set(UNIT_NAME Primitives)

option(USE_SFML "Use SFML as engine's graphic lib" OFF)

if(USE_SFML)
    add_subdirectory(Impls/SFMLBased)
endif()

set(PRIMITIVES_SOURCES
    primitives.cpp

    Config.h
    Vector2.hpp
    Rect.hpp
    Drawable.h
    IDrawable.h
    Event.hpp
    Color.h
    
    Sprite/Sprite.hpp
    Sprite/SpriteFactory.hpp
    Sprite/ISprite.h

    Texture/Texture.hpp
    Texture/TextureFactory.hpp
    Texture/ITexture.h

    Image/Image.hpp
    Image/IImage.h
    Image/ImageFactory.hpp

    RectangleShape/RectangleShape.hpp
    RectangleShape/IRectangleShape.h
    RectangleShape/RectangleShapeFactory.hpp

    CircleShape/CircleShape.hpp
    CircleShape/ICircleShape.h
    CircleShape/CircleShapeFactory.hpp

    RenderWindow/RenderWindow.hpp 
    RenderWindow/RenderWindowFactory.hpp
    RenderWindow/IRenderWindow.h 
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

file(WRITE ${CMAKE_CURRENT_SOURCE_DIR}/Config.h "#pragma once\n")
if(USE_SFML)
    file(APPEND ${CMAKE_CURRENT_SOURCE_DIR}/Config.h "#define USE_SFML\n")
endif()

install(TARGETS ${UNIT_NAME}
    EXPORT ${UNIT_NAME}Targets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include/Primitives
)