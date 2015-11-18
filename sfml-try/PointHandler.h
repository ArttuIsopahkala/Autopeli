#ifndef PointHandlerh
#define PointHandlerh
#include <string>
#include "SFML\Graphics.hpp"
#include "vehicle.h"

class PointHandler {
	private:
		int points;
	public:
		int receiveAndReturn(int prize);
		int returnAll();
		void write();
};
#endif