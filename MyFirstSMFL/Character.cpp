#include "Character.h"

#include <SFML\Graphics\RectangleShape.hpp>
#include <SFML\System\Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>

using namespace sf;

Character::Character(const sf::Vector2f& size, const sf::Color& color, float velocity)
	: m_velocity(velocity)
{
	m_sprite = new sf::RectangleShape(size);
	m_sprite->setFillColor(color);
	m_sprite->setPosition({ 0,0 });
}

Character::~Character()
{
	delete m_sprite;
}

void Character::update(float deltaTime)
{
	m_sprite->setPosition(m_position);

}

void Character::onInput(sf::Event::KeyEvent event)
{
	if (event.code == Keyboard::Key::Right)
	{
		m_direction.x = m_velocity;
	}

	if (event.code == Keyboard::Key::Left)
	{
		m_direction.x = -m_velocity;
	}

	if (event.code == Keyboard::Key::Up)
	{
		m_direction.y = -m_velocity;
	}

	if (event.code == Keyboard::Key::Down)
	{
		m_direction.y = m_velocity;
	}

	m_position += m_direction;
}

sf::RectangleShape * Character::getSprite() const
{
	return m_sprite;
}
