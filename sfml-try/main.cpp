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

	// dClock FPS:stä riippumaton peliaika
	sf::Clock dClock; 

	int y = 0;
	//Taustakuva
	sf::Image background_image;
	background_image.loadFromFile("background.jpg");
	sf::Texture background_tex;
	background_tex.loadFromImage(background_image);
	sf::RectangleShape background;
	background.setSize(sf::Vector2f((float)ag::ZONE_WIDTH, (float)ag::ZONE_HEIGHT));
	background.setPosition(0, y);
	background.setTexture(&background_tex);

	// Pelin tilan ja tapahtumien kasittely
	Event      tapahtumat;
	Gamestatus pelitila;

	// Hahmot
	sf::Texture vmantex,smantex;
	Character vman("viikatemies.png", -ag::CHARACTER_DISTANCE, &vmantex);
	Character sman("superman.png", ag::CHARACTER_DISTANCE, &smantex);	

	//Tekstit
	Teksti text("Superman voitti eran!\nR=Uusi peli | Esc=Lopeta","Viikatemies=","Supermies=","-");

	//Meter
	Meter meter(10,10);

	sf::RenderWindow window(sf::VideoMode (ag::ZONE_WIDTH,ag::ZONE_HEIGHT),"Superman vs. Viikatemies");

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	// - - - - - - - - - - - Varsinanen peli kayntiin  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	pelitila.setgamestatus(1);
	text.paivitaPisteet(0,0);
	text.paivitaErat(0,0);
	

	while(window.isOpen()) {   
	   tapahtumat.kasittele(window);

		// Pelinopeus FPS:stä riippumaton vakio
		float d = dClock.restart().asSeconds();
		float siirtyma = d * ag::GAME_SPEED;
		
		// Peli kaynnissa
		if (pelitila.getgamestatus() == 1)
		{
		
			// Viikatemiehen siirtyma
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				vman.setPosition(vman.getPosition() + sf::Vector2f(0, -siirtyma));
				vman.setRotation(0);
			}
			else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				vman.setPosition(vman.getPosition() + sf::Vector2f(0, siirtyma));
				vman.setRotation(180);
			}
			else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				vman.setPosition(vman.getPosition() + sf::Vector2f(-siirtyma, 0));
				vman.setRotation(270);
			}
			else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				vman.setPosition(vman.getPosition() + sf::Vector2f(siirtyma, 0));
				vman.setRotation(90);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
			{
				float xsijainti = (float)(std::rand() % ag::ZONE_WIDTH + 1);
				float ysijainti = (float)(std::rand() % ag::ZONE_HEIGHT + 1);
				vman.setPosition(xsijainti, ysijainti);
			}

			// Hahmo ilmestyy alueen toiselta puolelta ylittaessaan rajat
			if (vman.getPosition().x > ag::ZONE_WIDTH+ag::BORDER_LIMIT) vman.setPosition(-ag::BORDER_LIMIT,vman.getPosition().y);
			if (vman.getPosition().x < -ag::BORDER_LIMIT) vman.setPosition(ag::ZONE_WIDTH+ag::BORDER_LIMIT,vman.getPosition().y);
			if (vman.getPosition().y > ag::ZONE_HEIGHT+ag::BORDER_LIMIT) vman.setPosition(vman.getPosition().x,-ag::BORDER_LIMIT);
			if (vman.getPosition().y < -ag::BORDER_LIMIT) vman.setPosition(vman.getPosition().x,ag::ZONE_HEIGHT+ag::BORDER_LIMIT);

			// Supermanin siirtyma
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				sman.setPosition(sman.getPosition() + sf::Vector2f(0, -siirtyma));
				sman.setRotation(0);
			}
			else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				sman.setPosition(sman.getPosition() + sf::Vector2f(0, siirtyma));
				sman.setRotation(180);
			}
			else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				sman.setPosition(sman.getPosition() + sf::Vector2f(-siirtyma, 0));
				sman.setRotation(270);
			}
			else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				sman.setPosition(sman.getPosition() + sf::Vector2f(siirtyma, 0));
				sman.setRotation(90);
			}
			
			// Hahmo ilmestyy alueen toiselta puolelta ylittaessaan rajat
			if (sman.getPosition().x > ag::ZONE_WIDTH+ag::BORDER_LIMIT) sman.setPosition(-ag::BORDER_LIMIT,sman.getPosition().y);
			if (sman.getPosition().x < -ag::BORDER_LIMIT) sman.setPosition(ag::ZONE_WIDTH+ag::BORDER_LIMIT,sman.getPosition().y);
			if (sman.getPosition().y > ag::ZONE_HEIGHT+ag::BORDER_LIMIT) sman.setPosition(sman.getPosition().x,-ag::BORDER_LIMIT);
			if (sman.getPosition().y < -ag::BORDER_LIMIT) sman.setPosition(sman.getPosition().x,ag::ZONE_HEIGHT+ag::BORDER_LIMIT);

			// Jos hahmot tormaavat
			if (vman.getPosition().x < sman.getPosition().x + ag::COLLISION_LIMIT && 
				vman.getPosition().x > sman.getPosition().x - ag::COLLISION_LIMIT && 
				vman.getPosition().y < sman.getPosition().y + ag::COLLISION_LIMIT && 
				vman.getPosition().y > sman.getPosition().y - ag::COLLISION_LIMIT)
			{
				// Viikatemiehelle arvotaan uusi sijainti
				float xsijainti = (float)(std::rand() % ag::ZONE_WIDTH + 1); 
				float ysijainti = (float)(std::rand() % ag::ZONE_HEIGHT + 1); 
				vman.setPosition(xsijainti, ysijainti);

				// Kummankin pisteitä lisätään demotarkoituksessa
				sman.setpoints(sman.getpoints() + 50 );
				vman.setpoints(vman.getpoints() + 20 );
				
				//Pisteet ja voitot
				int vmp = vman.getpoints();
				int smp = sman.getpoints();
				text.paivitaPisteet(vmp, smp);
				meter.paivitaMeter(vmp, smp);
			}
			// Taustakuvan liikutus
			y = y + 1;
			background.setPosition(0, y - ag::ZONE_HEIGHT);
			if (background.getPosition().y > ag::ZONE_HEIGHT + ag::BORDER_LIMIT) {
				y = 0;
				background.setPosition(0, 0 - ag::ZONE_HEIGHT);
			}

		} // Peli kaynnissa

		// Tyhjataan naytto
		window.clear();
		
		// Piirrellaan oliot naytolle
		window.draw(background, sf::RenderStates::Default); // Tää pitää luoda ensin.
		vman.draw(window);
	    sman.draw(window);	
		text.drawloop(window);
		meter.draw(window);

		// Jos jommallakummalla pelaajalla pisteet yli 200, kerrotaan voittaja
		if (vman.getpoints() >= 200)
		{
			if (pelitila.getgamestatus()) vman.setwins(vman.getwins() +1);
			pelitila.setgamestatus(0);
			text.drawresult(window);
		}
		else if (sman.getpoints() >= 200)
		{
		    if (pelitila.getgamestatus()) sman.setwins(sman.getwins() +1);
			pelitila.setgamestatus(0);
			text.drawresult(window);
			int vmw = vman.getwins();
			int smw = sman.getwins();
			text.paivitaErat(vmw, smw);
		}

		// Pelin uudelleenkaynnistys R:lla
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			vman.setPosition(-ag::CHARACTER_DISTANCE+ag::ZONE_WIDTH/2,ag::ZONE_HEIGHT/2);
			sman.setPosition(ag::CHARACTER_DISTANCE+ag::ZONE_WIDTH/2,ag::ZONE_HEIGHT/2);
			vman.setpoints(0);
			sman.setpoints(0);
			text.paivitaPisteet(0, 0);
			meter.paivitaMeter(10, 10);
			pelitila.setgamestatus(1);
		}

		window.display();
	}
	return 0;
}