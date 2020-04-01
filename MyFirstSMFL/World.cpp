#include "World.h"
#include "Character.h"
#include <SFML/Graphics.hpp>

using namespace sf;

void World::init()
{
	character = new Character({ 100, 100 }, { 255,0,0,255}, 1);
}

void World::update(float deltaTime)
{
}

void World::onKeyDown(sf::Event::KeyEvent keyEvent)
{
	if (keyEvent.control && keyEvent.code == Keyboard::Key::Escape) {
		//TODO: Close the game
	}
	else {
		character->onInput(keyEvent);
	}
}

void World::draw(RenderWindow& window)
{
	Drawable& pd = *character->getSprite();
	window.draw(pd);
}

