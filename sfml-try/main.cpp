/*
   +---------------------------------------------------------------------+
   |  SMV -  - Superman Meets Viikatemies - Version 40                     |
   +---------------------------------------------------------------------+
   | Copyright (c) 2002-2014 The SMV Group (http://aaaseeemviii.com/)      |
   +---------------------------------------------------------------------+
   | This source file is subject to version 40.00 of the SMV license,      |
   | that is bundled with this package in the file LICENSE, and is         |
   | available through the world-wide-web at the following url:            |
   | http://aaaseeemviii.com/license/40_00.txt.                            |
   | If you did not receive a copy of the SMV license and are unable to    |
   | obtain it through the world-wide-web, please send a note to           |
   | license@aaaseeemviii.com so we can mail you a copy immediately.       |
   +---------------------------------------------------------------------+
   | Authors: Ari Rantala <ara@aaaseeemviii.com>                           |
   +---------------------------------------------------------------------+
*/


/* ************************************************************************
  Luotu:    29.9.2014 Ari Rantala

  Toiminta: SMV - Superman Meets Viikatemies. SMV on pieni SFML-kirjaston
            perusominaisuuksia demonstroiva "peli", jonka dokumentaatio
			toimitetaan toistaiseksi vain puhuttuna.
************************************************************************ */

#include <iostream>
#include <random>
#include "globals.h"
#include "event.h"
#include "gamestatus.h"
#include "character.h"
#include "teksti.h"
#include "meter.h"
#include <math.h>
#include <SFML/Graphics.hpp>

int main() {

	// Satunnaislukujen alustus
	std::random_device rd;
    std::srand(rd());

	// dClock FPS:st‰ riippumaton peliaika
	sf::Clock dClock; 

	int y = 0;
	int carspeed = 0;

	//Taustakuva
	sf::Image background_image;
	background_image.loadFromFile("background.jpg");
	sf::Texture background_tex;
	background_tex.loadFromImage(background_image);
	sf::RectangleShape background;
	sf::RectangleShape background2;
	background.setSize(sf::Vector2f((float)ag::ZONE_WIDTH, (float)ag::ZONE_HEIGHT));
	background.setPosition(0, y);
	background.setTexture(&background_tex);
	background2.setSize(sf::Vector2f((float)ag::ZONE_WIDTH, (float)ag::ZONE_HEIGHT));
	background2.setPosition(0, y - (float)ag::ZONE_HEIGHT);
	background2.setTexture(&background_tex);

	// Pelin tilan ja tapahtumien kasittely
	Event      tapahtumat;
	Gamestatus pelitila;

	// Hahmot
	sf::Texture vmantex,smantex,playertex;
	Character sman("playercar.png", ag::CHARACTER_DISTANCE, &playertex);
	Character auto1("superman.png", ag::CHARACTER_DISTANCE, &smantex);
	Character auto2("viikatemies.png", ag::CHARACTER_DISTANCE, &vmantex);
	Character auto3("playercar.png", ag::CHARACTER_DISTANCE, &playertex);

	//Tekstit
	Teksti text("Superman voitti eran!\nR=Uusi peli | Esc=Lopeta","Viikatemies=","Supermies=","-");

	//Meter
	Meter meter(10,10);

	sf::RenderWindow window(sf::VideoMode (ag::ZONE_WIDTH,ag::ZONE_HEIGHT),"Idiootti vs. Retardi");

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// - - - - - - - - - - - Varsinanen peli kayntiin  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	pelitila.setgamestatus(1);
	text.paivitaPisteet(0,0);
	text.paivitaErat(0,0);
	sman.setPosition(ag::ZONE_WIDTH / 2, 400);

	while(window.isOpen()) {   
	   tapahtumat.kasittele(window);

		// Pelinopeus FPS:st‰ riippumaton vakio
		float d = dClock.restart().asMilliseconds();
		float siirtyma = d * ag::GAME_SPEED;
		
		// Peli kaynnissa
		if (pelitila.getgamestatus() == 1)
		{

			// Supermanin siirtyma
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				sman.setPosition(sman.getPosition() + sf::Vector2f(0, -siirtyma));
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				sman.setPosition(sman.getPosition() + sf::Vector2f(0, siirtyma));
			}
			else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				sman.setPosition(sman.getPosition() + sf::Vector2f(-siirtyma, 0));
			}
			else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				sman.setPosition(sman.getPosition() + sf::Vector2f(siirtyma, 0));
			}
			
			// Hahmo ilmestyy alueen toiselta puolelta ylittaessaan rajat
			if (sman.getPosition().x > ag::ZONE_WIDTH-ag::BORDER_LIMIT) pelitila.setgamestatus(0);
			if (sman.getPosition().x < ag::BORDER_LIMIT) pelitila.setgamestatus(0);
			if (sman.getPosition().y > ag::ZONE_HEIGHT - ag::BORDER_LIMIT) sman.setPosition(sman.getPosition().x, ag::ZONE_HEIGHT - ag::BORDER_LIMIT);
			if (sman.getPosition().y < ag::BORDER_LIMIT) sman.setPosition(sman.getPosition().x, ag::BORDER_LIMIT);

			// Jos autot tormaavat
			/*if (vman.getPosition().x < sman.getPosition().x + ag::COLLISION_LIMIT && 
				vman.getPosition().x > sman.getPosition().x - ag::COLLISION_LIMIT && 
				vman.getPosition().y < sman.getPosition().y + ag::COLLISION_LIMIT && 
				vman.getPosition().y > sman.getPosition().y - ag::COLLISION_LIMIT)
			{
				// Kummankin pisteit‰ lis‰t‰‰n demotarkoituksessa
				sman.setpoints(sman.getpoints() + 50 );
				
				//Pisteet ja voitot
				int smp = sman.getpoints();
				text.paivitaPisteet(0, smp);
				meter.paivitaMeter(0, smp);
			}*/

			// Taustakuvien liikutus

			y += 4; // 1 = nopeus

			//speed = oppositevehicle.getSpeed();
			int speed = 3;
			
			carspeed += speed;
		
			background.setPosition(0, y);
			background2.setPosition(0, y - ag::ZONE_HEIGHT);
			if (background.getPosition().y > ag::ZONE_HEIGHT) {
			y = 0;
			}

			//vastustajien valuminen
			auto1.setPosition(50, carspeed);
			auto2.setPosition(100, carspeed);
			auto3.setPosition(200, carspeed);
			if (auto1.getPosition().y > ag::ZONE_HEIGHT) {
				carspeed = 0;
			}
		} // Peli kaynnissa

		// Tyhjataan naytto
		window.clear();
		
		// Piirrellaan oliot naytolle
		window.draw(background, sf::RenderStates::Default); // T‰‰ pit‰‰ luoda ensin.
		window.draw(background2, sf::RenderStates::Default); // T‰‰ pit‰‰ luoda ensin.
		auto1.draw(window);
		auto2.draw(window);
		auto3.draw(window);
	    sman.draw(window);	
		text.drawloop(window);
		meter.draw(window);

		// Pelin lopetustilastot
		if (pelitila.getgamestatus()==0)
		{
		    if (pelitila.getgamestatus()) sman.setwins(sman.getwins() +1);
			text.drawresult(window);
			int smw = sman.getwins();
			text.paivitaErat(0, smw);
		}

		// Pelin uudelleenkaynnistys R:lla
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			sman.setPosition(ag::CHARACTER_DISTANCE+ag::ZONE_WIDTH/2,ag::ZONE_HEIGHT/2);
			sman.setpoints(0);
			text.paivitaPisteet(0, 0);
			meter.paivitaMeter(10, 10);
			pelitila.setgamestatus(1);
		}

		window.display();
	}
	return 0;
}