#include<cstdio>

#include "Game.h"
#include "Common.h"

using namespace engine;

int main(int argc, char** argv){
	//std::cout << engine::Common::getInstance().DRAW_MODE << "\n";
	engine::Common::getInstance().DRAW_MODE = 10;
	engine::Common::getInstance().XML_DEBUG = false;
	engine::Common::getInstance().INIT_DEBUG = true;
	engine::Common::getInstance().RUN_DEBUG = true;
	//std::cout << engine::Common::getInstance().DRAW_MODE << "\n";

	engine::Game game(std::string("TestGame"));
	game.init();
	game.start(argc,argv);

	return 0;
}
