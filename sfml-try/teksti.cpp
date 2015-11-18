#include "teksti.h"
#include "character.h"
#include <string>
#include "SFML\Graphics.hpp"

// Oletuskonstruktori ja -destruktori
Teksti::Teksti() {}
Teksti::~Teksti() {}

// Tekstien luonti

Teksti::Teksti(std::string maintext, std::string viikatemies, std::string supermies, std::string erat) {
	this->mntext = maintext;
	this->vmtext = viikatemies;
	this->smtext = supermies;
	this->eratext = erat;
}

void Teksti::paivitaPisteet(int vmp, int smp) {
	std::string s = std::to_string(vmp);
	std::string t = std::to_string(smp);
	this->vmp = s;
	this->smp = t;
}
void Teksti::paivitaErat(int vmw, int smw) {
	std::string s = std::to_string(vmw);
	std::string t = std::to_string(smw);
	this->vmw = s;
	this->smw = t;
}
void Teksti::drawloop(sf::RenderWindow & window) {
sf::Font font;
font.loadFromFile("arial.ttf");

sf::Text vmtext(getVMtext(), font);
vmtext.setCharacterSize(20);
vmtext.setStyle(sf::Text::Bold);
vmtext.setColor(sf::Color::Red);
vmtext.setPosition((float)30, (float)410);

sf::Text smtext(getSMtext(), font);
smtext.setCharacterSize(20);
smtext.setStyle(sf::Text::Bold);
smtext.setColor(sf::Color::Blue);
smtext.setPosition((float)320, (float)410);

sf::Text eratext(geterattext(), font);
eratext.setCharacterSize(20); 
eratext.setStyle(sf::Text::Bold);
eratext.setColor(sf::Color::White);
eratext.setPosition((float)220, (float)410);
	window.draw(vmtext);
	window.draw(smtext);
	window.draw(eratext);
}
void Teksti::drawresult(sf::RenderWindow & window) {
	sf::Font font;
	font.loadFromFile("arial.ttf");

	sf::Text mntext(getMaintext(), font);
	mntext.setCharacterSize(20);
	mntext.setStyle(sf::Text::Bold);
	mntext.setColor(sf::Color::White);
	mntext.setPosition((float)180, (float)200);
	window.draw(mntext);
}