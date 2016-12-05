####TileList
Tile types: 1 is somethings a tower can be placed on, 2 is unplaceable not monster path, 3 is monster path,
4 is a monster entry point, 5 is the base location

####MonsterPathLength
The length of the monster path, excluding the spawn tile and including the base

####MonsterDirections
In lieu of pathfinding, we explicitly tell the monsters where to go
Array length must be equal to monsterPathLength
1 to move up, 2 to move left, 3 to move down, and 4 to move right