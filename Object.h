#ifndef OBJECT_H
#define OBJECT_H

#include "Serializable.h"

#include "Body.h"

#include <string>

namespace engine {
	
	/**
	 * @brief The base element of the engine.
	 * @author FCN
	 * 
	 * An Object describes any interactable element on the game.
	 */

	class Object : public Serializable {
		public:
			std::string name;
			
			/*Physic Attributes*/
			Body body;
			
			Object(){};
			virtual void update() = 0;
			virtual void draw() = 0;
	};

}

#endif
	
