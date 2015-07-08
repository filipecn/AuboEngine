#ifndef FIXTURE_H
#define FIXTURE_H

#include "Serializable.h"
#include "Constants.h"
#include <vector>
#include <Box2D/Box2D.h>

namespace engine
{
	class Fixture : public Serializable {
		public:
			unsigned char type;
			std::vector<b2Vec2> vertices;
			b2Vec2 center;
			float radius, w, h, angle;
			float restitution;
			float friction;
			float density;
			bool sensor;
			unsigned char categoryBits;
			unsigned char groupIndex;
			unsigned char maskBits;
			
			Fixture();
			void read(boost::property_tree::ptree);
			
			friend std::ostream &operator<<( std::ostream &out, const Fixture& );
	};
}

#endif
