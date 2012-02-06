
#ifndef __ROOM_H
#define __ROOM_H

/**
 * Room
 * @brief Describes a room. A room consists of Objects.
 */

#include <vector>

// forward declaration
class Object;
typedef std::vector<Object*>;

class Room
{
public:
	Room();
	~Room();

private:
};

#endif
