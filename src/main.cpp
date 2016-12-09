#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include "BTSB.hpp"
#include "Game.hpp"
#include "NodeTB.hpp"
using namespace std;

int main() {
	srand(time(NULL));
	Game g = Game();
	//g.test();
	g.startGame();
}
