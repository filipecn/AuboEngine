#ifndef SCENERYOBJECT_H
#define SCENERYOBJECT_H

#include "Object.h"

namespace engine
{
	class SceneryObject : public Object {
		public:	
			SceneryObject(){};
			~SceneryObject(){};

			void read(boost::property_tree::ptree);
			void update();
			void draw(){}
	};
}

#endif
