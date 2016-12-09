/*
 * Game.hpp
 *
 *  Created on: Oct 26, 2016
 *      Author: Dalton
 */

#ifndef GAME_HPP_
#define GAME_HPP_

class Game {
	BTSB *dict; //the AVL tree
	int numLetters; //the number of letters the user wants
	char *currLetters; //the random set of letters
	int numRight; //the count of the number of words in the AVL tree
	int totalWords; //the count of the total number of words generated
	BTSB *wordList; //The binary search tree for the word list - used 
	friend class NodeTB;
	friend class BTSB;
	//because you want to make sure there are no duplicates in the word list typed in
public:
	Game();
	Game(string infile);
	void startGame();
	void readTreeFromFile(string dictfile);
	char *getLetters(int x);
	void getWords();
	bool checkWLetters(string s);
	void checkWordsForScore(NodeTB *n);
	void test();
};



#endif /* GAME_HPP_ */
