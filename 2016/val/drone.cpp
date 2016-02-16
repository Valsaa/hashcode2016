#include "drone.h"

Drone::Drone(void) {
	this->x = 0;
	this->y = 0;
	this->drone_ID = 0;
}

Drone::Drone(Drone *drone) {
	this->x = drone->x;
	this->y = drone->y;
	this->drone_ID = drone->drone_ID;
}

Drone::Drone(int x, int y, int drone_ID) {
	this->x = x;
	this->y = y;
	this->drone_ID = drone_ID;
}

void Drone::debug(void) {
	cout << this->drone_ID << " " << this->x << " " << this->y << endl;
}

void Drone::load(FILE *output, int warehouse_ID, int product_type_ID, int nb_items) {
	fprintf(output, "%d L %d %d %d\n", this->drone_ID,  warehouse_ID, product_type_ID, nb_items);
}

void Drone::unload(FILE *output, int order_ID, int product_type_ID, int nb_items) {
	fprintf(output, "%d U %d %d %d\n", this->drone_ID,  order_ID, product_type_ID, nb_items);
}

void Drone::deliver(FILE *output, int order_ID, int product_type_ID, int nb_items) {
	fprintf(output, "%d D %d %d %d\n", this->drone_ID,  order_ID, product_type_ID, nb_items);
}

void Drone::wait(FILE *output, int nb_turns) {
	fprintf(output, "%d W %d\n", this->drone_ID, nb_turns);
}

void Drone::writeResult(FILE *output) {
	this->load(output, 0, 1, 2);
	this->unload(output, 8, 541, 22);
	this->unload(output, 2, 13, 94);
	this->load(output, 7, 11, 25);
	this->wait(output, 25);
}

Drone::~Drone(void) {}
