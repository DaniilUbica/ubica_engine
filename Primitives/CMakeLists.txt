cmake_minimum_required(VERSION 3.10)
set(UNIT_NAME Primitives)

option(USE_SFML "Use SFML as engine's graphic lib" ON)

if(USE_SFML)
    add_subdirectory(Impls/SFMLBased)
endif()

set(PRIMITIVES_SOURCES
    primitives.cpp

    Primitives/Config.h
    Primitives/Vector2.hpp
    Primitives/Rect.hpp
    Primitives/Drawable.h
    Primitives/IDrawable.h
    Primitives/Event.hpp
    Primitives/Color.h
    Primitives/Clock.hpp
    
    Primitives/Sprite/Sprite.hpp
    Primitives/Sprite/SpriteFactory.hpp
    Primitives/Sprite/ISprite.h

    Primitives/Texture/Texture.hpp
    Primitives/Texture/TextureFactory.hpp
    Primitives/Texture/ITexture.h

    Primitives/Image/Image.hpp
    Primitives/Image/IImage.h
    Primitives/Image/ImageFactory.hpp

    Primitives/RectangleShape/RectangleShape.hpp
    Primitives/RectangleShape/IRectangleShape.h
    Primitives/RectangleShape/RectangleShapeFactory.hpp

    Primitives/CircleShape/CircleShape.hpp
    Primitives/CircleShape/ICircleShape.h
    Primitives/CircleShape/CircleShapeFactory.hpp

    Primitives/RenderWindow/RenderWindow.hpp 
    Primitives/RenderWindow/RenderWindowFactory.hpp
    Primitives/RenderWindow/IRenderWindow.h 

    Primitives/View/View.hpp 
    Primitives/View/ViewFactory.hpp
    Primitives/View/IView.h 

    Primitives/Text/IText.h 
    Primitives/Text/Text.hpp 
    Primitives/Text/TextFactory.hpp

    Primitives/Font/IFont.h 
    Primitives/Font/Font.hpp 
    Primitives/Font/FontFactory.hpp
)

add_library(${UNIT_NAME} STATIC ${PRIMITIVES_SOURCES})

set(INCLUDE_DIRS 
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Primitives
)

if(USE_SFML) 
    target_link_libraries(${UNIT_NAME} PUBLIC SFMLBased)
endif()

target_include_directories(${UNIT_NAME} ${INCLUDE_DIRS})

file(WRITE ${CMAKE_CURRENT_SOURCE_DIR}/Config.h "#pragma once\n")
if(USE_SFML)
    file(APPEND ${CMAKE_CURRENT_SOURCE_DIR}/Config.h "#define USE_SFML\n")
endif()

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

GroupSources(ubica_engine/Primitives)

install(TARGETS ${UNIT_NAME}
    EXPORT ${UNIT_NAME}Targets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include/Primitives
)