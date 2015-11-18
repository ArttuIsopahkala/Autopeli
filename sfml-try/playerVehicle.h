#ifndef playerVehicleh
#define playerVehicleh
#include <string>
#include "SFML\Graphics.hpp"
#include "vehicle.h"

class PlayerVehicle : public Vehicle {
private:
	int points;
public:
	PlayerVehicle();
	~PlayerVehicle();
	void shoot(int target_x, int target_y);
	void die() {
		//resetGame();
	};

	void setPoints(int points) {
		this->points = points;
	}
	int getPoints() { return points; }

	void setpoints(int);
	int getpoints();
	PlayerVehicle(std::string, int, sf::Texture *);  // Luo hahmo
	void draw(sf::RenderWindow &);
};
#endif