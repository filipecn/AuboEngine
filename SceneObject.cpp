#include "SceneObject.h"

namespace engine
{
	void SceneObject::read(boost::property_tree::ptree pt){
		using boost::property_tree::ptree;

		if(pt.find("body") != pt.not_found())
			body.read(pt.get_child("body"));
	}
}
