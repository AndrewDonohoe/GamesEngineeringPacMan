#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include "game_system.hpp"
#include "../scenes.hpp"
#include "renderer.hpp"

using gs = GameSystem;
using sc = Scene;

//---------Scene----------

std::shared_ptr<EntityManager> Scene::em;

void Scene::update(const float& dt) {
    Scene::em->update(dt);
}

void Scene::render(sf::RenderWindow& window) {
    Scene::em->render(window);
}

void Scene::unload() {
    return;
}

void Scene::load() {
    return;
}

//------------GameSystem--------------

std::shared_ptr<Scene> gs::_active_scene;

void gs::start(unsigned int width, unsigned int height,
    const std::string& name, const float& time_step) {
    sf::RenderWindow window(sf::VideoMode({ width, height }), name);
    _init();
    Renderer::initialise(window);
    sf::Event event;
    while (window.isOpen()) {
        static sf::Clock clock;
        float dt = clock.restart().asSeconds();
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                clean();
                return;
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close();
        }
        window.clear();
        _update(dt);
        _render(window);
        sf::sleep(sf::seconds(time_step));
        //Wait for Vsync
        window.display();
    }
    window.close();
    clean();
}

void gs::clean() {}

void gs::reset() {}

void gs::set_active_scene(const std::shared_ptr<Scene>& act_sc) {
    gs::_active_scene = act_sc;
}

void gs::_init() {

}

void gs::_update(const float& dt) {
    gs::_active_scene->update(dt);
    Renderer::update(dt);
}

void gs::_render(sf::RenderWindow& window) {
    gs::_active_scene->render(window);
    Renderer::render();
}

