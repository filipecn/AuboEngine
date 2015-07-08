#ifndef COMMON_H
#define COMMON_H

#include <string>

namespace engine
{

	class Common {
		private:
			Common(){}
		public:
			inline static Common& getInstance(){
				static Common c;
				return c;
			}
			~Common(){};
			
			static std::string GAMEPATH;
			unsigned DRAW_MODE;
			static bool XML_DEBUG;
			static bool INIT_DEBUG;
			static bool RUN_DEBUG;

			static int FIXED_FPS;
			static int LAST_TIME;
			static int FRAME;
	};

}

#endif
