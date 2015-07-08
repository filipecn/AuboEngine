#ifndef BODY_H
#define BODY_H

#include "Serializable.h"
#include "Fixture.h"

#include <vector>
#include <Box2D/Box2D.h>

namespace engine
{
	class Body : public Serializable {
		public:
			b2Body *pBody;

			std::vector<Fixture> fixtures;
			b2BodyType type;
			bool fixedRotation;
			b2Vec2 position;
			float angle;
			
			Body();
			void read(boost::property_tree::ptree);
			b2Vec2 getPosition();

			friend std::ostream &operator<<( std::ostream &out, const Body& );
	};
}

#endif
