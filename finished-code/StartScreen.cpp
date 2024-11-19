#include "StartScreen.h"

StartScreen* StartScreen::runState(sf::RenderWindow& tgt)
{
	sf::RectangleShape startButton(sf::Vector2f(300, 100));
	startButton.setPosition(sf::Vector2f(tgt.getSize().x / 2 - 150, tgt.getSize().y / 2 - 50));
	startButton.setFillColor(sf::Color::Red);
	sf::Font a(AssetManager::getTypeFace("resources/PhantomMuff_Full_Letters_1_1_5.ttf"));
	sf::Text startText("test button lol", a);
	startText.setPosition(sf::Vector2f(tgt.getSize().x / 2 - 150, tgt.getSize().y / 2 - 50));
	while (tgt.isOpen())
	{
		sf::Event ee;
		while (tgt.pollEvent(ee))
		{
			if (ee.type == sf::Event::Closed) {
				tgt.close();
				return 0;
			}
		}
		tgt.clear(sf::Color::Blue);
		tgt.draw(startButton);
		tgt.draw(startText);
		tgt.display();
	}
}
