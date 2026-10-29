#include "entity_manager.hpp"
#include <iostream>

std::vector<std::shared_ptr<Entity>> EntityManager::list;

// Entity Manager
void EntityManager::update(float dt) {
	for (std::shared_ptr<Entity>& ent : EntityManager::list) {
		ent->update(dt);
	}
}

void EntityManager::render(sf::RenderWindow& window) {
	for (std::shared_ptr<Entity>& ent : EntityManager::list) {
		ent->render(window);
	}
}