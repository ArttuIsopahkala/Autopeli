#ifndef meterh
#define meterh
#include "SFML\Graphics.hpp"

class Meter {
protected:
	int vmp;
	int smp;
public:
	Meter();
	~Meter();
	Meter(int vmp, int smp);
	int getVMP() { return vmp; };
	int getSMP() { return smp; };
	void paivitaMeter(int vmp, int smp);
	void draw(sf::RenderWindow &);

};
#endif