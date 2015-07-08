#ifndef LEVEL_H
#define LEVEL_H

#include "Utils.h"
#include "Common.h"
#include "Camera.h"
#include "GameState.h"
#include "SceneObject.h"
#include "SceneryObject.h"
#include "Actor.h"
#include "World.h"

#include <Box2D/Box2D.h>

#include <iostream>
#include <vector>

namespace engine 
{

	/**
	 * @brief Defines a complete game level.
	 * @author FCN
	 * 
	 * A level has graphics, objectives and objects.
	 */

	class Level : public GameState {
		private:
			Camera camera;
			World world;
			/*Level Objects*/
			std::vector<Actor*> actors;
			std::vector<SceneObject*> sceneObjects;
			std::vector<SceneryObject*> scenery;
		public:
			/*Level Attributes*/
			std::string name;
			std::string version;
			
			Level();
			void init();
			void update();
			void draw();
			void serialize(std::ostream &);

			void read(boost::property_tree::ptree);
	};

}

#endif
