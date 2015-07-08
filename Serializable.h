#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

#include "Common.h"

#include <iostream>
#include <string>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/foreach.hpp>

namespace engine {

	class Serializable {
		protected:
			char* id;
			std::string path;
			std::string xmlName;
		public:
			Serializable(){ xmlName = "content"; }
			virtual void serialize(std::ostream &){}
			virtual void load(boost::property_tree::ptree::value_type const& l);
			virtual void read(boost::property_tree::ptree pt){}
	};
}

#endif
