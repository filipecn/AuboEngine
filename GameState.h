#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "Serializable.h"

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
	class GameState : public Serializable {
		protected:
			std::string path;
		public:
			virtual void init() = 0;
			virtual void update() = 0;
			virtual void draw() = 0;
	};

}

#endif
