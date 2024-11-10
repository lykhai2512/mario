#include "Block.h"

Block* Block::createBlock(BlockType type)
{
	switch (type)
	{
	case BlockType::none:
		break;
	case BlockType::ground:
		//return new Ground;
		break;
	case BlockType::brick:
		break;
	case BlockType::specialBrick:
		break;
	case BlockType::horizontalPipe:
		break;
	case BlockType::verticalPipe:
		break;
	case BlockType::baseBrick:
		break;
	case BlockType::cloud:
		break;
	case BlockType::castle:
		break;
	case BlockType::flag:
		break;
	case BlockType::tree:
		break;
	default:
		break;
	}
}

void Block::move(){}

void Block::jump(){}

void Block::die(){}
