#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

#include "Object.h"

namespace engine
{
	class SceneObject : public Object {
		public:
			SceneObject(){};
			~SceneObject(){};

			void read(boost::property_tree::ptree);
			void update(){};
			void draw(){};

	};
}

#endif
