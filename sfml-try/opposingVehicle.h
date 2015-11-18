#ifndef opposingVehicleh
#define opposingVehicleh
#include <string>
#include "SFML\Graphics.hpp"
#include "vehicle.h"

class OpposingVehicle : public Vehicle {
private:

public:
	OpposingVehicle();
	~OpposingVehicle();
	void die() {
		givePoints();
		erase();
	};

	OpposingVehicle(std::string, int, sf::Texture *);  // Luo hahmo
	void draw(sf::RenderWindow &);
};
#endif