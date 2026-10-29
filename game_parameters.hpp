#pragma once //insure that this header file is included only once and there will no multiple definition of the same thing
#include <SFML/Graphics.hpp>
#include <string>

struct Parameters {
	static constexpr int game_width = 800;
	static constexpr int game_height = 600;
	static constexpr float time_step = 0.017f; //60 fps

	static constexpr sf::Keyboard::Key controls[4] = {
		sf::Keyboard::W, //Up
		sf::Keyboard::A, //Left
		sf::Keyboard::S, //Down
		sf::Keyboard::D, //Right
	};

	static const std::string maze_1;
	static const std::string maze_2;
	static const std::string maze_3;
};