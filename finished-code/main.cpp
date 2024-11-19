#include "Map.h"
#include "AssetManager.h"
#include "WorldObject.h"
#include "Mario.h"
#include "Character.h"
#include "StartScreen.h"
#include "GameState.h"
int main()
{

	
	//Map map("resources/in.txt");
	//Mario m(AssetManager::getTexture("resources/mario_left.png"), 3, 15, 25, 2.5, 32, 32);
	//sf::Clock clocc;
	//sf::RenderWindow window(sf::VideoMode(1600, 1600), "test??");
	//window.setFramerateLimit(120);
	//sf::View view;
	//while (window.isOpen())
	//{
	//	sf::Event e;
	//	while (window.pollEvent(e))
	//	{
	//		if (e.type == sf::Event::Closed)
	//			window.close();
	//	}

	//	float dt = clocc.restart().asSeconds();
	//	m.mapCollisionHandler(map);
	//	m.move(dt);
	//	
	//	window.clear();

	//	view.setCenter(m.getPosition());
	//	window.setView(view);

	//	m.draw(window);
	//	map.draw(window);
	//	
	//	
	//	
	//	window.display();

	//}

	sf::RenderWindow test(sf::VideoMode(800, 600), "startScreen test");
	
	GameState* pointer = new StartScreen;
	while (pointer)
	{
		GameState* nextPointer = pointer->runState(test);
		delete pointer;
		pointer = nextPointer;
	}

	return 0;


}