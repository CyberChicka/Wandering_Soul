cmake_minimum_required(VERSION 3.20)
project(Wandering_Soul)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc ")

set(SFML_STATIC_LIBRARIES TRUE)

add_executable(Wandering_Soul main.cpp Map.h Map.h Map.h view.h mission.h Menu.h Player.h Enemy.h Entity.h TextAndImages.h Nps.h HP.h Boss.h "Object_Class .h" isBook.h Particle.h LifeBar.h Radius.h Smart_Pointer.h Bullet.h " EventFunction.h" MusicSound.h)

set(SFML_DIR "E:\\programm\\SFML-2.5.1\\lib\\cmake\\SFML")

target_link_libraries(Wandering_Soul sfml-graphics sfml-audio sfml-network)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_nodules")

find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)
