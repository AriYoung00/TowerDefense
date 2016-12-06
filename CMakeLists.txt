cmake_minimum_required(VERSION 3.2)
project(TowerDefense)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_BUILD_TYPE Debug)

set(SOURCE_FILES src/main.cpp
        src/Tower/Tower.cpp
        src/Tower/TowerMan.cpp
        src/Events/ButtonClickEvent.cpp
        src/Location/TilePoint.cpp
        src/Monster/Monster.cpp
        src/Monster/MonsterMan.cpp
        src/UI/UIManager.cpp
        src/Location/TileUtil.cpp
				src/State/StateManager.cpp
				include/lib/Animation.cpp
				include/lib/AnimatedSprite.cpp
)
add_executable(TowerDefense ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(TowerDefense ${SFML_LIBRARIES})
endif()

include_directories(${CMAKE_SOURCE_DIR}/include)
