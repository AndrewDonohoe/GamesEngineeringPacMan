#pragma once
#include <string>
#include "game_system.hpp"

struct Scenes {
	static std::shared_ptr<Scene> menu;
	static std::shared_ptr<Scene> game;
};

class MenuScene : public Scene {
private:
	sf::Font _font;
	sf::Text _text;

public:
	MenuScene() = default;
	void update(const float& dt) override;
	void render(sf::RenderWindow& window) override;
	void load() override;
};

class GameScene : public Scene {
private:
	sf::Text text;
	sf::Clock scoreClock;
	void respawn();

public:
	GameScene() = default;
	void update(const float& dt) override;
	void render(sf::RenderWindow& window) override;
	void load() override;
};