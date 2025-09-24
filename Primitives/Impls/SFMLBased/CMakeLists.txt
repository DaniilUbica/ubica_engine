cmake_minimum_required(VERSION 3.10)
set(UNIT_NAME SFMLBased)

add_subdirectory(SFML)

set(SOURCES
    sfmlbased.cpp

    SFMLSprite.hpp
    SFMLTexture.hpp
    SFMLImage.hpp
    SFMLRenderWindow.hpp
    SFMLRectangleShape.hpp
    SFMLCircleShape.hpp
    SFMLView.hpp
    Helpers.hpp
)

add_library(${UNIT_NAME} STATIC ${SOURCES})

set(INCLUDE_DIRS 
    PUBLIC SFML
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Primitives
)

target_link_libraries(${UNIT_NAME} PUBLIC
    sfml-system
    sfml-window
    sfml-graphics
    sfml-audio
)

target_include_directories(${UNIT_NAME} ${INCLUDE_DIRS})

install(TARGETS ${UNIT_NAME}
    EXPORT ${UNIT_NAME}Targets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include/Primitives
)