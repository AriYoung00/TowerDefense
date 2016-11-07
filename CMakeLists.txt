cmake_minimum_required(VERSION 3.2)
project(TowerDefense)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp src/Tower/TowerMan.cpp include/Tower/TowerMan.h src/Tower/Tower.cpp include/Tower/Tower.h src/Events/ButtonClickEvent.cpp include/Events/ButtonClickEvent.h)
add_executable(TowerDefense ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(TowerDefense ${SFML_LIBRARIES})
endif()

include_directories(${CMAKE_SOURCE_DIR}/include)
