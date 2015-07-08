#include "SceneryObject.h"

namespace engine
{
	void SceneryObject::read(boost::property_tree::ptree pt){
		using boost::property_tree::ptree;
		
		if(pt.find("body") != pt.not_found())
			body.read(pt.get_child("body"));
		
		if(Common::XML_DEBUG)
			std::cout << body;
	}

	void SceneryObject::update(){
		b2Vec2 p = body.getPosition();
		//std::cout << p.x << " , " << p.y << std::endl;
	}

}
