#include "meter.h"
#include "character.h"
#include "SFML\Graphics.hpp"

// Oletuskonstruktori ja -destruktori
Meter::Meter() {}
Meter::~Meter() {}

// Meteren luonti

Meter::Meter(int vmp, int smp) {
	this->vmp = vmp;
	this->smp = smp;
}
void Meter::draw(sf::RenderWindow & window) {
	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(20, getVMP()));
	rectangle.setFillColor(sf::Color::Red);
	rectangle.setOutlineColor(sf::Color::Black);
	rectangle.setOutlineThickness(2);
	rectangle.setPosition(0, 20);

	sf::RectangleShape rectangle1;
	rectangle1.setSize(sf::Vector2f(20, getSMP()));
	rectangle1.setFillColor(sf::Color::Blue);
	rectangle1.setOutlineColor(sf::Color::Black);
	rectangle1.setOutlineThickness(2);
	rectangle1.setPosition(490, 20);

	window.draw(rectangle);
	window.draw(rectangle1);
}
void Meter::paivitaMeter(int vmp, int smp) {
	this->vmp = vmp;
	this->smp = smp;
}