#include "game_parameters.hpp"
#include "game_system.hpp"
#include "scenes.hpp"

Parameters p;

int main() {
	Scenes::menu = std::make_shared<MenuScene>();
	Scenes::menu->load();
	Scenes::game = std::make_shared<GameScene>();
	Scenes::game->load();
	GameSystem::set_active_scene(Scenes::menu);
	GameSystem::start(p.game_width, p.game_height, "pacman", p.time_step);
	return 0;
}