#pragma once
//#include <SFML/Window/Event.hpp>
class Character;

namespace sf {
	class RenderWindow;
	struct sf::Event::KeyEvent;
}

typedef sf::Event::KeyEvent KeyEvent;

class World
{
public:
	void init();
	void update(float deltaTime);
	void draw(sf::RenderWindow& window);

	void onKeyDown(KeyEvent keycode);

private:
	Character* character;
};

