#pragma once
#include <SFML/Graphics.hpp>
#include "../Entity.hpp"

struct EntityManager {
	static std::vector<std::shared_ptr<Entity>> list;
	void update(float dt);
	void render(sf::RenderWindow& window);
};