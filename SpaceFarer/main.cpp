#include "SFML\System\Clock.hpp"
#include <iostream>
#include "Game.h"

int main()
{
	sf::Clock clock;
	sf::Time time;

	bool shouldRun;
	Game game(shouldRun);

	game.Init();

	while (shouldRun)
	{
		time = clock.restart();
		game.Update(time.asSeconds());
		game.Render();
	}

	return 0;
}