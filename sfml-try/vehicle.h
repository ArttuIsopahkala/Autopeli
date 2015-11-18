#ifndef vehicleh
#define vehicleh
#include <string>
#include "SFML\Graphics.hpp"

class Vehicle : public sf::RectangleShape {
protected:
	int speed;
	sf::Texture skin;
	int x;
	int y;

public:
	Vehicle();
	~Vehicle();
	void setDimensions(int x, int y) {
		this->x = x;
		this->y = y;
	};
	void setSpeed(int speed) {
		this->speed = speed;
	};

	virtual void die() = 0;

	void draw(sf::RenderWindow &);

};
#endif