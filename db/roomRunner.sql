
-- Database Creation SQL for RoomRunner.
-- This is only for SQLite3.

-- Turn on foreign keys
PRAGMA foreign_keys = ON;

-- Object describes an object in the game world.
CREATE TABLE IF NOT EXISTS Objects(
	ObjectId INTEGER PRIMARY KEY,
	Name TEXT,
	Type INTEGER DEFAULT(0), -- Enumeration in Object.
	GridCellX INTEGER DEFAULT(0),
	GridCellY INTEGER DEFAULT(0)
);

-- Rooms describes a room, which contains many Cells, which contain 1 object.
CREATE TABLE IF NOT EXISTS Rooms(
	RoomId INTEGER PRIMARY KEY,
	Name TEXT,
	Width INTEGER DEFAULT(20),
	Height INTEGER DEFAULT(15)
);

-- Cell describes a cell, which contains an object.
CREATE TABLE IF NOT EXISTS Cell(
	CellId INTEGER PRIMARY KEY,
	RoomId INTEGER NOT NULL, -- must reference valid Rooms.RoomId
	ObjectId INTEGER, -- must reference valid Objects.ObjectId
	Layer INTEGER DEFAULT(0),
	FOREIGN KEY (RoomId) REFERENCES Rooms(RoomId),
	FOREIGN KEY (ObjectId) REFERENCES Objects(ObjectId)
);


