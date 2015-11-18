#ifndef playerVehicleh
#define playerVehicleh
#include <string>
#include "SFML\Graphics.hpp"
#include "vehicle.h"

class PlayerVehicle : public Vehicle {
private:
	int points;
public:
	~PlayerVehicle();
	void shoot(int target_x, int target_y);
	void die();
	PlayerVehicle(std::string, int, sf::Texture *, sf::Color, int, int, int);  // Luo hahmo
};
#endif