/*
 * NodeTB.hpp
 *
 *  Created on: Nov 2, 2016
 *      Author: Paul
 */

#include <stdlib.h>
#include <iostream>
#ifndef NODETB_HPP_
#define NODETB_HPP_
using namespace std;
	//asdf
class NodeTB{

public:
	string data;
	int height;
	NodeTB *parent;
	NodeTB *left;
	NodeTB *right;
	NodeTB(string s);
	~NodeTB();
	string getData();
	void setLeft(NodeTB *n);
	void setRight(NodeTB *n);
	
};



#endif /* NODETB_HPP_ */
