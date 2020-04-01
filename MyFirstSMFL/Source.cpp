#include <SFML/Graphics.hpp>
#include "Character.h"
#include "World.h"

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(200, 200), "SFML works!");
	window.setFramerateLimit(60);

	//Character character({ 100,50 }, { 50,200,0,0 }, 2);
	Clock deltaClock;
	World world;

	world.init();
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed)
			{
				auto data = event.key;
				world.onKeyDown(data);
			}
		}
		window.clear(Color(10, 10, 100, 255));
		float deltaTime = deltaClock.restart().asSeconds();
		world.update(deltaTime);
		world.draw(window);

		window.display();
	}

	return 0;
}