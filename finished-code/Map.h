#include "WorldObject.h"
#include "Collision.h"
#include "Animation.h"
#include "AssetManager.h"
enum class MapType {
	Nature = 1,
	Cave = 2,
	Fire = 3
};

class Map {
private:
	std::vector<WorldObject*>allObjects;
public:
	Map();
	//deallocate
	~Map();

	void draw(sf::RenderWindow* window, MapType type);
};