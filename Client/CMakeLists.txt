cmake_minimum_required(VERSION 3.13)
project(r-type_client)

set(CMAKE_CXX_STANDARD 14)

set(SFML_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/Server/Game/Encapsulation/SFML-2.5.1-Compiled/include")
set(SFML_LIBRARY_DIR "${CMAKE_SOURCE_DIR}/Server/Game/Encapsulation/SFML-2.5.1-Compiled/lib")
set(SFML_DIR "${CMAKE_SOURCE_DIR}/Server/Game/Encapsulation/SFML-2.5.1-Compiled/lib/cmake/SFML")

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)
include_directories (${CMAKE_SOURCE_DIR}/Client/include)
include_directories (${CMAKE_SOURCE_DIR}/Server/Game/Encapsulation/include)
include_directories (${CMAKE_SOURCE_DIR}/Server/Game/Miscellaneous/include)
include_directories (${CMAKE_SOURCE_DIR}/Com)
include_directories (${CMAKE_SOURCE_DIR})

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

if(SFML_FOUND)
    message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
    message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
    message(STATUS "SFML_VERSION: ${SFML_VERSION}")
endif()

add_executable (r-type_client src/main.cpp src/Client.cpp src/UDPClient.cpp src/DisplayInfo.cpp src/EventManager.cpp ../Com/BinaryConverter.cpp ../Server/Game/Encapsulation/src/SFMLGraphics.cpp ../Server/Game/Encapsulation/src/SFMLEvent.cpp ../Server/Game/Encapsulation/src/SFMLWindow.cpp ../Server/Game/Encapsulation/src/Time.cpp)
target_compile_options(r-type_client PUBLIC -g3)
target_link_libraries (r-type_client pthread boost_system sfml-graphics sfml-window sfml-system sfml-audio)