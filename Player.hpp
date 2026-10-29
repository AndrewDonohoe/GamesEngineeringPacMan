#pragma once
#include "entity.hpp"

class Player : public Entity {
public:
	void update(const float& dt) override;
	Player();
	void render(sf::RenderWindow& window) const override;
	void move(const sf::Vector2f& pos) override;

	bool valid_move(sf::Vector2f& pos);
private:
	static constexpr float _radius = 25.f;
	static constexpr float _speed = 200.f;
};