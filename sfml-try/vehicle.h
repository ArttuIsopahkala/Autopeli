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
	Vehicle(std::string, int, sf::Texture *, int, int, int);
	~Vehicle();
	void setDimensions(int x, int y);
	void setSpeed(int speed);

	virtual void die() = 0;

	void draw(sf::RenderWindow &);

};
#endif