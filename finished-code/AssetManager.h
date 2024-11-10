#pragma once
#include<iostream>
#include<vector>
#include "Block.h"


class AssetManager {
private:
	std::vector<std::string>dirt_fileNames;
	std::vector<std::string>brick_fileNames;
	std::vector<std::string>specialBrick_fileNames;
	std::vector<std::string>castle_fileNames;
	//...
public:
	void load();
	void get(BlockType type,Map map_type);
	//...
};


