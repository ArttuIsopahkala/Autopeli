#ifndef tekstih
#define tekstih
#include <string>
#include "SFML\Graphics.hpp"

class Teksti {
protected:
	std::string mntext;
	std::string vmtext;
	std::string smtext;
	std::string eratext;
	std::string vmp;
	std::string smp;
	std::string vmw;
	std::string smw;

public:
	Teksti();
	~Teksti();
	Teksti(std::string maintext, std::string viikatemies, std::string supermies, std::string erat);
	std::string getMaintext() { return mntext; };
	std::string getVMtext() { return vmtext+vmp; };
	std::string getSMtext() { return smtext+smp; };
	std::string geterattext() { return vmw+eratext+smw; };
	void paivitaPisteet(int vmp, int smp);
	void paivitaErat(int vmw, int smw);
	void drawloop(sf::RenderWindow &);
	void drawresult(sf::RenderWindow &);
};
#endif