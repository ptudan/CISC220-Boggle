/*
 * BSTB.hpp
 *
 *  Created on: Oct 26, 2016
 *      Author: Dalton
 */

#ifndef BSTB_HPP_
#define BSTB_HPP_

#include "NodeTB.hpp"
#include <iostream>
#include <fstream>
using namespace std;

class BTSB {
	NodeTB *root;
	int score; //for wordlist when calculating score, initialized to 0
	friend class NodeTB;
	friend class Game;

public:
	BTSB();//constructor - sets root to NULL
	~BTSB();//destructor - deletes tree
	bool insert(string x); //recursively inserts x into the tree with the current root (possibly of a subtree) being n
	bool insert(string x, NodeTB *n); //Note the overloading of methods - this is nice if you choose to write this
									  //method recursively. If a string is already in the tree, you may want to
									  //print out a warning, but otherwise it can just be ignored.
	void printTreeio(); //prints out the data in the tree in order (this should print out the dictionary alphabetically)
	void printTreeio(NodeTB *n); //again, nice if you chose recursion
	void printTreePre(); //for testing purposes, prints out tree in preorder
	void printTreePre(NodeTB *n); //for printing recursively
	void printTreePost(); //for testing purposes, prints out tree in postorder
	void printTreePost(NodeTB *n); //for printing recursively
	bool search(string x); //searches tree for x - returns true if found, false otherwise
	bool search(NodeTB *n, string x); //if recursive
	int adjustBalances(NodeTB *n); //adjusts the heights of the trees
	NodeTB *rotateRight(NodeTB *n); //for right rotation
	NodeTB *rotateLeft(NodeTB *n); //for left rotation
	int updateHeights(NodeTB *n);
};

#endif /* BSTB_HPP_ */
