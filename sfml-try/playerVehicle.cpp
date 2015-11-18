#include "gamestatus.h"
#include "globals.h"
#include "playerVehicle.h"
#include "opposingVehicle.h"
#include "SFML\Graphics.hpp"

class PlayerVehicle : public Vehicle {
private:
	int points;
	Gamestatus gs;
	sf::RectangleShape sade;
public:
	~PlayerVehicle() {};

	void shoot(sf::RectangleShape & sade, OpposingVehicle & target) {
		sf::Vector2f hostPos = this->getPosition();
		sf::Vector2f targetPos = target.getPosition();
		sade.setSize(sf::Vector2f((float)10, sqrt(pow(hostPos.y - targetPos.y, 2.0) + pow(hostPos.x - targetPos.x, 2.0))));
		if ((hostPos.x - targetPos.x) < 0)sade.setRotation((atan((hostPos.y - targetPos.y) / (hostPos.x - targetPos.x)) * 180 / 3.14159265) - 90);
		else sade.setRotation((atan((hostPos.y - targetPos.y) / (hostPos.x - targetPos.x)) * 180 / 3.14159265) + 90);
		sade.setPosition(hostPos);
	}

	void die() {
		gs.setgamestatus(0);
	};
	PlayerVehicle(std::string imgname, int xpos, sf::Texture * tex, sf::Color color, int x, int y, int speed)
		: Vehicle(imgname, xpos, tex, x, y, speed) {
		this->sade.setFillColor(color);
	}
};