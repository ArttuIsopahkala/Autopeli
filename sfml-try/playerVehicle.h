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
<<<<<<< HEAD
	void die();
	PlayerVehicle(std::string, int, sf::Texture *, sf::Color, int, int, int);  // Luo hahmo
=======
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
>>>>>>> a9ceade5cd761ae1904cdfc3eb5ea235f18f215d
};
#endif