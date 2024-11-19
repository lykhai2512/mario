#include "Map.h"
#include <fstream>
#include <string>
#include <cassert>
Map::Map(std::string filename) // for now this will be a .txt file. ' ' represents emptiness, 1 represents tile bricks
{
	std::ifstream in(filename);
	assert(in.is_open());
	while (!in.eof())
	{
		std::vector<Block *> lineElements;
		std::string line;
		std::getline(in, line);
		for (auto &l : line)
		{
			if (l == ' ')
				lineElements.push_back(0);
			else
				lineElements.push_back(new Block(AssetManager::getTexture("resources/block.png"), 32, 32));
		}
		this->elementPTRs.push_back(lineElements);
	}
}

Map::~Map()
{
	for (auto& i : this->elementPTRs)
		for (auto& j : i)
			delete j;
}

void Map::debugPrint()
{

}

void Map::draw(sf::RenderWindow &tgt) // for now the map will use just 1 texture file so ill just leave it as a solid path
{
	for(int i = 0; i < this->elementPTRs.size(); i++)
		for (int j = 0; j < this->elementPTRs[i].size(); j++)
		{
			if (elementPTRs[i][j])
			{
				elementPTRs[i][j]->setPosition(sf::Vector2f(j * 32, i * 32));
				elementPTRs[i][j]->draw(tgt);
			}
		}
			
}

sf::Vector2i Map::getArea()
{
	return sf::Vector2i(this->elementPTRs[0].size(), this->elementPTRs.size());
}