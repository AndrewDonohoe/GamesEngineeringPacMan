#include "player.hpp"
#include "scenes.hpp"
#include "level_system.hpp"
using ls = LevelSystem;

using namespace sf;
using namespace std;

using p = Parameters;

void Player::update(const float& dt) {
    //Move in four directions based on keys
    float v_direction = 0.0f; // Vertical
    float h_direction = 0.0f; // Horizontal

    //Vertical
    if (sf::Keyboard::isKeyPressed(p::controls[0])) { // Up
        v_direction--;
    }
    if (sf::Keyboard::isKeyPressed(p::controls[2])) { // Down
        v_direction++;
    }

    //Horizontal
    if (sf::Keyboard::isKeyPressed(p::controls[1])) { // Left
        h_direction--;
    }
    if (sf::Keyboard::isKeyPressed(p::controls[3])) { // Right
        h_direction++;
    }

    Player::move(sf::Vector2f(h_direction * _speed * dt, v_direction * _speed * dt));
    Entity::update(dt);
}

Player::Player() : Entity(std::make_unique<CircleShape>(_radius)) {
    _shape->setFillColor(Color::Magenta);
    _shape->setOrigin(sf::Vector2f(_radius, _radius));
}

void Player::render(sf::RenderWindow& window) const {
    window.draw(*_shape);
}

void Player::move(const sf::Vector2f& pos) {
    if (Player::valid_move(_position + pos)) {
        _position += pos;
        _shape->setPosition(sf::Vector2f(_position));
    }
}

bool Player::valid_move(sf::Vector2f& pos) {
    return (ls::get_tile_at(pos += {(_radius-1.f), (_radius-1.f)}) != ls::WALL &&
        ls::get_tile_at(pos -= {(2*_radius-2.f), (2*_radius)}) != ls::WALL
        );
}
