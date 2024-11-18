#include "Block.h"

//Block* Block::createBlock(BlockType type)
//{
//	switch (type)
//	{
//	case BlockType::none:
//		break;
//	case BlockType::ground:
//		//return new Ground;
//		break;
//	case BlockType::brick:
//		break;
//	case BlockType::specialBrick:
//		break;
//	case BlockType::horizontalPipe:
//		break;
//	case BlockType::verticalPipe:
//		break;
//	case BlockType::baseBrick:
//		break;
//	case BlockType::cloud:
//		break;
//	case BlockType::castle:
//		break;
//	case BlockType::flag:
//		break;
//	case BlockType::tree:
//		break;
//	default:
//		break;
//	}
//}

Block::Block(sf::Texture& a, float sizeX, float sizeY)
	:sizeX(sizeX), sizeY(sizeY)
{
	this->blocc.setSize(sf::Vector2f(sizeX, sizeY));
	this->blocc.setTexture(&a);

}

void Block::move(float dt)
{

}

void Block::jump()
{

}

void Block::die()
{

}

void Block::collect(WorldObject* object)
{

}

void Block::standOn(WorldObject* object)
{

}

void Block::setPositionFor(WorldObject * object)
{

}

void Block::hit(WorldObject* object)
{

}

bool Block::isDead()
{
	return true;
}

void Block::draw(sf::RenderWindow& window)
{
	window.draw(this->blocc);
}

void Block::setPosition(sf::Vector2f a)
{
	this->blocc.setPosition(a);
}

sf::Vector2f Block::getPosition()
{
	return this->blocc.getPosition();
}

sf::FloatRect Block::getGlobalBounds()
{
	return this->blocc.getGlobalBounds();	
}