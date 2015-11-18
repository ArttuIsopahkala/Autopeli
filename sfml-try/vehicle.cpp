#include <string>
#include "globals.h"
#include "SFML\Graphics.hpp"

class Vehicle : public sf::RectangleShape {
protected:
	int speed;

public:
	Vehicle(std::string imgname, int xpos, sf::Texture * tex, int x, int y, int speed) {
		sf::Image img;
		img.loadFromFile(imgname);
		img.createMaskFromColor(sf::Color::White);
		tex->loadFromImage(img);
		this->speed = speed;
		this->setSize(sf::Vector2f(x, y));
		this->setPosition(xpos + ag::ZONE_WIDTH / 2, ag::ZONE_HEIGHT / 2);
		this->setOrigin(x/2, y/2);
		this->setTexture(tex);
	}

	~Vehicle() {};
	int getSpeed() {
		return this->speed;
	};

	void draw(sf::RenderWindow & window) {
		window.draw(*this);
	}

};