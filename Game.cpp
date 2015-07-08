#include "Game.h"

namespace engine
{

	Game::Game(std::string path){
		Common::getInstance().GAMEPATH = path;
	}

	bool Game::init(){
		gFInstance = this;

		std::ifstream is ((Common::getInstance().GAMEPATH + "/game.xml").c_str(), 
				std::ifstream::binary);
		if(is)
			read(is);

		// TMP
		states[1]->init();
	}
	
	void Game::update(){
		int time = glutGet(GLUT_ELAPSED_TIME);
		if(time - Common::LAST_TIME > 1000/Common::FIXED_FPS){
			Common::LAST_TIME = time;
			
			states[1]->update();
			
			render();
		}
	}

	void Game::render(){
		glClearColor( 0.0, 0.0, 0.0, 0.0 );

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		glMatrixMode(GL_MODELVIEW);

		glLoadIdentity();
		
		states[1]->draw();

		glFlush();
		glutSwapBuffers();
	}

	bool Game::read(std::istream & is){
		// populate tree structure pt
		using boost::property_tree::ptree;
		ptree pt;
		read_xml(is, pt);
		
		name = pt.get<std::string>("game.<xmlattr>.name");
		
		version = pt.get<std::string>("game.<xmlattr>.version");
		
		if(Common::XML_DEBUG){
			std::cout << "game name version\n";
			std::cout << name << std::endl;
			std::cout << version << std::endl;
		}

		BOOST_FOREACH( ptree::value_type const& v, pt.get_child("game.gamestates") ) {
			if(utils::upperString(v.second.get<std::string>("<xmlattr>.type")) == "LEVEL"){
				Level *l = new Level();
				l->load(v);
				states.push_back(l);
			}
		}
		return true;
	}
}
