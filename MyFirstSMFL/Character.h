#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
//forward declaration
namespace sf {
	class RectangleShape;
	class Color;
}

class Character
{
public:
	//Si pasamos referencia se puede utilizar para cambiar los valores de lo que pasamos
	//al poner const nos aseguramos que no se pueda modificar.
	//Se suele utilizar referencia para devolver varios parametros
	Character(const sf::Vector2f& size, const sf::Color& color, float velocity);
	~Character();

	void update(float deltaTime);
	void onInput(sf::Event::KeyEvent event);

	sf::RectangleShape* getSprite() const;

private:
	//Character's sprite
	sf::RectangleShape* m_sprite;
	sf::Vector2f m_position;
	sf::Vector2f m_direction;
	float m_velocity;
};

