#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "game_parameters.hpp"

class Entity {
public:
	Entity(std::unique_ptr<sf::Shape> shp);
	Entity() = delete;
	virtual ~Entity() = default;

	virtual void update(const float& dt);
	virtual void render(sf::RenderWindow& window) const = 0;

	const sf::Vector2f get_position();
	void set_position(const sf::Vector2f& pos);
	virtual void move(const sf::Vector2f& pos);

protected:
	std::unique_ptr<sf::Shape> _shape;
	sf::Vector2f _position;
};