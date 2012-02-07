# ROOMRUNNER

- Web: http://www.andrewsimeon.com/
- Email: andrew@andrewsimeon.com
- GitHub: http://github.com/megadrive


## Table of Contents

    1.0 Overview
        1.1 Technologies
        1.2 Structure
        1.3 Program constants
    2.0 Assets
        2.1 Loading
        2.2 Database
    3.0 Player
    4.0 Rooms/Houses
        4.1 Population
        4.2 Obstacles
        4.3 Enemies

1.0     Overview
----------------
RoomRunner is a modular platformer where each level is designed separately and then placed 
together to form a level.
TODO: Decide whether it will be randomly generated levels or self-written. Or both.

1.1     Technologies
--------------------
Language: C/C++
Graphics: SDL 1.2 http://libsdl.org/
Database: SQLite http://www.sqlite.org/

1.2     Structure
-----------------
Source:

    ${GAME_ROOT}/           Solution/Project directory.
    ${GAME_ROOT}/assets     Graphics/Sounds/Miscellanious files.
    ${GAME_ROOT}/src        Source files (*.h and *.cpp).

Deploy:

    ${GAME_ROOT}/           Executable.
    ${GAME_ROOT}/assets     Graphics/Sounds/Miscellanious required files.

1.3     Program constants
-------------------------
    WINDOW_WIDTH    The window's width
    WINDOW_HEIGHT   The window's height

2.0     Assets
--------------
Textures should be loaded into a global TextureLibrary. At the end of the unload of each Room, 
run a check for unused Textures and unload them to conserve memory.

2.1     Loading
---------------
SDL will handle all graphic loading. They load into a TextureLibrary singleton. Levels are stored 
in an SQLite database that is read in the loading/init phase of a scene.

2.2		Database
----------------
The database is only used for Room loading and Object placing. To keep everything in a nice line, 
a Cell class is used. These are 16 pixels by 16 pixels and can contain one Object, referenced 
from the other table.

Tables required:

- Objects(ObjectId, Name, Width, Height, ImagePath = NULL);
- Rooms(RoomId, Name, WidthModifier = 1, TilesetImagePath);
- Cells(CellId, RoomId, ObjectId, GridX, GridY);

Cells.RoomId must refer to a VALID Room. 
Cells.ObjectId must refer to a VALID Object. 

3.0     Player
--------------
The player can move left and right, duck and jump. His jump height formula is:
    height + (height * 0.75)

4.0     Rooms/Houses
-------------
Rooms are, by default, 320 pixels by 240 pixels. They can contain any number of objects.
Houses contain rooms, these are the overarching world.

4.1		Population
------------------
Rooms are populated via SQLite, which are created via a custom Tiled Map Editor plugin by me (TODO). 
A connection should be made and then read into the Room's vector, loading Textures as required.

4.2     Obstacles
-----------------
    Name		Type	Function

4.3     Enemies
---------------
    Name		Type	Description
