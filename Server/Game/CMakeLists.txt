cmake_minimum_required(VERSION 3.13)
project(r-type_server)

set(CMAKE_CXX_STANDARD 14)

set(SFML_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/Server/Game/Encapsulation/SFML-2.5.1-Compiled/include")
set(SFML_LIBRARY_DIR "${CMAKE_SOURCE_DIR}/Server/Game/Encapsulation/SFML-2.5.1-Compiled/lib")
set(SFML_DIR "${CMAKE_SOURCE_DIR}/Server/Game/Encapsulation/SFML-2.5.1-Compiled/lib/cmake/SFML")

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)
include_directories (${CMAKE_SOURCE_DIR}/Server/Game/GameEngine/include)
include_directories (${CMAKE_SOURCE_DIR}/Server/Game/GameObject/include)
include_directories (${CMAKE_SOURCE_DIR}/Server/Game/Encapsulation/include)
include_directories (${CMAKE_SOURCE_DIR}/Server/Game/Menu/include)
include_directories (${CMAKE_SOURCE_DIR}/Server/Game/Miscellaneous/include)
include_directories (${CMAKE_SOURCE_DIR}/Server/Game/R-type/include)
include_directories (${CMAKE_SOURCE_DIR}/Server/Game/Enemies)
include_directories (${CMAKE_SOURCE_DIR}/Server/Game/)
include_directories (${CMAKE_SOURCE_DIR}/Com)
include_directories (${CMAKE_SOURCE_DIR})

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

if(SFML_FOUND)
    message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
    message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
    message(STATUS "SFML_VERSION: ${SFML_VERSION}")
endif()

add_executable (r-type_server main.cpp UDPServer.cpp ../../Com/BinaryConverter.cpp server_udp.cpp R-type/src/Bullet.cpp R-type/src/Obstacle.cpp R-type/src/Enemy2.cpp R-type/src/Player.cpp R-type/src/ShootPowerUp.cpp R-type/src/SpeedPowerUp.cpp R-type/src/PlayerControler.cpp Menu/src/Animated.cpp Menu/src/MenuImage.cpp Menu/src/Button.cpp Encapsulation/src/SFMLGraphics.cpp Encapsulation/src/SFMLEvent.cpp Encapsulation/src/SFMLWindow.cpp Encapsulation/src/Time.cpp GameEngine/src/GameEngine.cpp GameEngine/src/SceneManager.cpp GameObject/src/GameObject.cpp GameObject/src/StateManager.cpp GameObject/src/PositionManager.cpp GameEngine/src/Scene.cpp GameEngine/src/SceneFactory.cpp)
target_compile_options(r-type_server PUBLIC -g3)
target_link_libraries (r-type_server pthread boost_system sfml-graphics sfml-window sfml-system dl)