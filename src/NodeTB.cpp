//Made by Paul
//Nov 2 2016

#include "BTSB.hpp"
#include "Game.hpp"
#include "NodeTB.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

NodeTB::NodeTB(string s){
	data = s;
	parent = NULL;
	left = NULL;
	right = NULL;
	height = 0;
}

NodeTB::~NodeTB(){
	
}

void NodeTB::setLeft(NodeTB *n){
	left = n;
}

void NodeTB::setRight(NodeTB *n){
	right = n;
}
