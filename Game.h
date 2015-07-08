#ifndef GAME_H
#define GAME_H

#include "Constants.h"
#include "Utils.h"
#include "GameState.h"
#include "Level.h"
#include "Serializable.h"
#include "Common.h"
#include "GraphicsFramework.h"

#include <iostream>
#include <vector>
#include <string>

namespace engine
{
	/**
	 * @brief The Engine itself.
	 * @author FCN
	 * 
	 * Game runs the game state machine.\n 
	 * Get players actions, runs the game's logic and jump through states (levels,menus,etc.). 
	 */
	class Game : public GraphicsFramework {
	
		std::vector<GameState*> states;
		std::vector<GameState*> menus;

		public:
			/*Game attributes*/
			std::string name;
			std::string version;

			/*Constructors*/
			Game(){};
			Game(std::string);
			
			/*Public Methods*/
			bool init();
			void update();
			void render();
			
		private:
			bool read(std::istream &);

	};

}

#endif
