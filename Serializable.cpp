#include "Serializable.h"

namespace engine
{
	void Serializable::load(boost::property_tree::ptree::value_type const& l){
		using boost::property_tree::ptree;
		ptree pt = l.second;
		
		path = pt.get<std::string>("<xmlattr>.path", std::string(""));
		if(path.size()){
			path = Common::GAMEPATH + "/" + path;
			std::ifstream is ((path + "/" + xmlName + ".xml").c_str(), std::ifstream::binary);
			if(is){
				ptree _pt;
				read_xml(is,_pt);
				read(_pt.get_child(xmlName));
			}
			return;
		}

		read(pt);
	}
}
