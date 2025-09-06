cmake_minimum_required(VERSION 3.10)
set(UNIT_NAME SFMLBased)

add_subdirectory(SFML)

set(SOURCES
    SFMLSprite.hpp
    SFMLRect.hpp
    SFMLTexture.hpp
)

add_library(${UNIT_NAME} STATIC ${SOURCES})

target_link_libraries(${UNIT_NAME} PUBLIC
    sfml-system
    sfml-window
    sfml-graphics
    sfml-audio
)

target_include_directories(${UNIT_NAME} PUBLIC SFML PRIVATE ${CMAKE_SOURCE_DIR}/ubica_engine/Primitives)

install(TARGETS ${UNIT_NAME}
    EXPORT ${UNIT_NAME}Targets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include/Primitives
)