#include "Common.h"

namespace engine
{
	bool Common::XML_DEBUG = false;
	bool Common::INIT_DEBUG = false;
	bool Common::RUN_DEBUG = false;

	std::string Common::GAMEPATH = "";

	int Common::FIXED_FPS = 60;
	int Common::LAST_TIME = 0;
	int Common::FRAME = 0;
}
