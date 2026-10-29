#include "scenes.hpp"
#include "Player.hpp"
#include <iostream>
#include "game_parameters.hpp"
#include "level_system.hpp"
#include "renderer.hpp"

using param = Parameters;
using ls = LevelSystem;
using gs = GameSystem;

std::shared_ptr<Scene> Scenes::menu;
std::shared_ptr<Scene> Scenes::game;

// ---------------------------Menu Scene-------------------------------------

void MenuScene::update(const float& dt) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        gs::set_active_scene(Scenes::game);
    }

    Scene::update(dt);
    _text.setString("Almost Pacman");
}

void MenuScene::render(sf::RenderWindow& window) {
    Renderer::queue(&_text);
    Scene::render(window);
}

void MenuScene::load() {
    _font.loadFromFile("resources/fonts/RobotoSlab-Regular.ttf");
    _text.setFont(_font);
    _text.setCharacterSize(48);
    _text.setFillColor(sf::Color::White);
}

// -----------------------------Game Scene------------------------------------

void GameScene::render(sf::RenderWindow& window) {
    Renderer::queue(&text);
    Scene::render(window);
}

void GameScene::update(const float& dt) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)) {
        gs::set_active_scene(Scenes::menu);
    }
}

void GameScene::load() {
    return;
}