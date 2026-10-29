#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "../Entity.hpp"
#include "entity_manager.hpp"

class Scene {
public:
    Scene() = default;

    virtual ~Scene() = default;
    virtual void update(const float& dt);
    virtual void render(sf::RenderWindow& window);
    virtual void load();
    virtual void unload();

protected:
    static std::shared_ptr<EntityManager> em;
};

class GameSystem {
public:
    static void start(unsigned int width, unsigned int height,
        const std::string& name, const float& time_step);
    static void clean();
    static void reset();
    static void set_active_scene(const std::shared_ptr<Scene>& act_sc);

private:
    static void _init();
    static void _update(const float& dt);
    static void _render(sf::RenderWindow& window);
    static std::shared_ptr<Scene> _active_scene;
};
