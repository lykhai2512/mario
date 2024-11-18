#include "Map.h"
#include "AssetManager.h"
#include "WorldObject.h"
#include "Mario.h"
#include "Character.h"


int main()
{

	
	Map map("in.txt");
	Mario m(AssetManager::get("mario_left.png"), 3, 20, 30, 1.5, 32, 32);
	sf::Clock clocc;
	sf::RenderWindow window(sf::VideoMode(1600, 1600), "test??");
	window.setFramerateLimit(60);
	sf::View view;
	while (window.isOpen())
	{
		sf::Event e;
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				window.close();
		}

		float dt = clocc.restart().asSeconds();
		m.mapCollisionHandler(map);
		m.move(dt);
		
		window.clear();

		view.setCenter(m.getPosition());
		window.setView(view);

		m.draw(window);
		map.draw(window);
		
		
		
		window.display();

	}
}