#include "SFML\Graphics.hpp"
#include "opposingVehicle.h"

class OpposingVehicle : public Vehicle {
	private:
		int prize;
	public:
		~OpposingVehicle() {};
		void die() {
			delete this;
		};
		int givePrize() {
			return this->prize;
		};
		OpposingVehicle(std::string imgname, int xpos, sf::Texture * tex, sf::Color color, int x, int y, int speed, int prize)
			: Vehicle(imgname, xpos, tex, x, y, speed) {
			this->prize = prize;
		};  // Luo hahmo
};