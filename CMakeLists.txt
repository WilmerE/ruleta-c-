cmake_minimum_required(VERSION 3.10)
project(RuletaCXX)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

# Archivos fuente principales (omite manual.cpp y test.cpp)
set(SOURCES
    main.cpp
    src/participante.cpp
    src/jugador.cpp
    src/apuesta.cpp
    src/ruleta.cpp
)

add_executable(ruleta ${SOURCES})
