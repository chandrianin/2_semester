cmake_minimum_required(VERSION 3.24)

project(1_lab)

set(CMAKE_CXX_STANDARD 17)


add_definitions(-DSFML_STATIC)

include_directories("ext/SFML/include/")
include_directories("inc/")
link_directories("ext/SFML/lib/")

add_executable(1_lab main.cpp inc/animation.h src/animation.cpp)

target_link_libraries("1_lab"
#        sfml-graphics-s
#        sfml-window-s
#        sfml-system-s
#        sfml-audio-s
        sfml-graphics-s-d
        sfml-window-s-d
        sfml-system-s-d
        sfml-audio-s-d
        opengl32
        freetype
        winmm
        gdi32
        openal32
        flac
        vorbisenc
        vorbisfile
        vorbis
        ogg
)

FILE(COPY ext/font/GoogleSans-Regular.ttf DESTINATION ext/font/)