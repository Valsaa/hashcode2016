#ifndef DRONE_H
#define DRONE_H

#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstdio>
#include "node.h"
#include "warehouse.h"

using namespace std;

typedef enum {L, U, D, W} _Action;

class Drone {

    public:
        Drone(void);
	Drone(Drone *drone);
	Drone(int x, int y, int drone_ID);
        ~Drone(void);

	void debug(void);
	void writeResult(FILE *output);
	void load(FILE *output, int warehouse_ID, int product_type_ID, int nb_items);
	void unload(FILE *output, int order_ID, int product_type_ID, int nb_items);
	void deliver(FILE *output, int order_ID, int product_type_ID, int nb_items);
	void wait(FILE *output, int nb_turns);

	int drone_ID;
	int x;
	int y;

};

#endif // DRONE_H
