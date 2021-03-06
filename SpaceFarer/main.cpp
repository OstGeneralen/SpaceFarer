#include "SFML\System\Clock.hpp"
#include <iostream>
#include "Game\Game.h"
#include "Engine\json.hpp"

int main()
{
	sf::Clock clock;
	sf::Time time;

	bool shouldRun = true;
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