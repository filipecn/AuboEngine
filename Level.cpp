#include "Level.h"

namespace engine
{
	Level::Level(){
		xmlName = "level";
	}

	void Level::init(){
		if(Common::INIT_DEBUG) 
			std::cout << "init " << name << std::endl;
		world.init();
		for(unsigned int i = 0; i < actors.size(); i++)
			world.addObject(actors[i]);
		for(unsigned int i = 0; i < sceneObjects.size(); i++)
			world.addObject(sceneObjects[i]);
		for(unsigned int i = 0; i < scenery.size(); i++)
			world.addObject(scenery[i]);
		camera.init();
	}

	void Level::update(){
		world.step();
		for(unsigned int i = 0; i < actors.size(); i++)
			actors[i]->update();
		for(unsigned int i = 0; i < sceneObjects.size(); i++)
			sceneObjects[i]->update();
		for(unsigned int i = 0; i < scenery.size(); i++)
			scenery[i]->update();
	}

	void Level::draw(){
		camera.look();
		
		world.draw();
		//for(unsigned int i = 0; i < actors.size(); i++)
		//	actors[i]->draw();
		for(unsigned int i = 0; i < sceneObjects.size(); i++)
			sceneObjects[i]->draw();
		for(unsigned int i = 0; i < scenery.size(); i++)
			scenery[i]->draw();
	}

	void Level::serialize(std::ostream &o){}

	void Level::read(boost::property_tree::ptree pt){
		using boost::property_tree::ptree;
		
		// LEVEL ATTRIBUTES
		name = pt.get<std::string>("<xmlattr>.name");	
		if(Common::XML_DEBUG) std::cout << name << std::endl;
		
		camera.read(pt.get_child("camera"));
		// WORLD ATTRIBUTES
		world.read(pt.get_child("world"));
		// ACTORS
		BOOST_FOREACH( ptree::value_type const& v, pt.get_child("actors") ) {
			if(Common::XML_DEBUG){
				std::cout << v.second.get<std::string>("<xmlattr>.name") << "\n";
				std::cout << v.second.get<std::string>("<xmlattr>.type") << "\n";
			}
		}
		// SCENE OBJECTS
		BOOST_FOREACH( ptree::value_type const& v, pt.get_child("sceneObjects") ) {
			SceneObject* so = new SceneObject();
			so->load(v);
			sceneObjects.push_back(so);
		}
		// SCENERY OBJECTS
		BOOST_FOREACH( ptree::value_type const& v, pt.get_child("scenery") ) {
			SceneryObject* so = new SceneryObject();
			so->load(v);
			scenery.push_back(so);
		}
	}
}
