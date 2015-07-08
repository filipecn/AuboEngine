#include "Fixture.h"

namespace engine
{
	Fixture::Fixture(){
		xmlName = "fixture";
	}

	void Fixture::read(boost::property_tree::ptree pt){
		using boost::property_tree::ptree;
		// TYPE
		center.Set(pt.get<float>("shapeProperties.x"),pt.get<float>("shapeProperties.y"));
		switch(pt.get<char>("<xmlattr>.type")){
			case 'b': type = RECTANGLE; 
				  w = pt.get<float>("shapeProperties.w");
				  h = pt.get<float>("shapeProperties.h");
				  break;
			case 'c': type = CIRCLE; 
				  radius = pt.get<float>("shapeProperties.r");
				  break;
			case 'p': type = POLYGON; 
				  break;
		}
		// RESTITUTION
		restitution = pt.get<float>("restitution");
		// FRICTION
		friction = pt.get<float>("friction");
		// DENSITY
		density = pt.get<float>("density");
		// SENSOR
		sensor = pt.get<bool>("sensor");
		// CATEGORY BITS
		categoryBits = pt.get<unsigned char>("categoryBits");
		// GROUP INDEX
		groupIndex = pt.get<unsigned char>("groupIndex");
		// MASK BITS
		maskBits = pt.get<unsigned char>("maskBits");

	}

	std::ostream &operator<<( std::ostream &output, const Fixture &f )
	{ 
		output << "Fixture: " << "\n" 
			<< "restitution: " << f.restitution << "\n"
			<< "friction: " << f.friction << "\n"
			<< "\n";
		return output;            
	}


}
