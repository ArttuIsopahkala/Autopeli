#ifndef opposingVehicleh
#define opposingVehicleh
#include <string>
#include "SFML\Graphics.hpp"
#include "vehicle.h"

class OpposingVehicle : public Vehicle {
private:
	int prize;
public:
	OpposingVehicle();
	~OpposingVehicle();
	void die();
	int givePrize();
	OpposingVehicle(std::string, int, sf::Texture *, sf::Color, int, int, int, int);  // Luo hahmo
	void draw(sf::RenderWindow &);
};
#endif