#include "Body.h"

namespace engine
{
	Body::Body(){
		xmlName = "body";
	}
	
	void Body::read(boost::property_tree::ptree pt){
		using boost::property_tree::ptree;

		// TYPE
		switch(pt.get<char>("type")){
			case 's': type = b2_staticBody; break;
			case 'd': type = b2_dynamicBody; break;
			case 'k': type = b2_kinematicBody; break;
		}
		// ANGLE
		angle = pt.get<float>("angle");
		// FIXED ROTATION
		fixedRotation = pt.get<bool>("fixedRotation");
		// POSITION
		position.Set(pt.get<float>("position.x"),pt.get<float>("position.y"));
		// FIXTURES
		BOOST_FOREACH( ptree::value_type const& v, pt.get_child("fixtures")){
			Fixture f;
			f.load(v);
			if(Common::XML_DEBUG)
				std::cout << f;
			fixtures.push_back(f);
		}

	}

	std::ostream &operator<<( std::ostream &output, const Body &b )
	{ 
		output << "Body: " << "\n" 
			<< "type: " << b.type << "\n"
			<< "fixedRotation: " << b.fixedRotation << "\n"
			<< "position: " << b.position.x << "," << b.position.y << "\n"
			<< "angle: " << b.angle << "\n"
			<< "\n";
		return output;            
	}

	b2Vec2 Body::getPosition() {
		return pBody->GetPosition();
	}
}
