//Made by Paul
//Nov 2 2016

#include "BTSB.hpp"
#include "Game.hpp"
#include "NodeTB.hpp"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
using namespace std;

Game::Game(){
	readTreeFromFile("dict.txt");
	numRight = 0;
	totalWords = 0;
	currLetters = NULL;
	wordList = new BTSB();
}

Game::Game(string f){
	readTreeFromFile(f);
	numRight = 0;
	totalWords = 0;
	currLetters = NULL;
	wordList = new BTSB();
}

void Game::startGame(){
	cout<<"How many letters would you like to play with (3-8 recommended): ";
	cin>>numLetters;//asks for number of letters
	currLetters = getLetters(numLetters);
	getWords();
	checkWordsForScore(wordList->root);
	int score = ((totalWords - numRight)*(-6)) + (numRight*3);//calculates score
	cout<<"Your score is: "<<score<<", with "<<numRight<<" correct out of "<<totalWords<<" entered."<<endl;
}

void Game::test(){
	cout<<"post"<<endl;
	dict->updateHeights(dict->root);
	dict->adjustBalances(dict->root);
	dict->printTreePost(dict->root);
	cout<<endl;
	cout<<"pre"<<endl;
	dict->printTreePre(dict->root);
	cout<<endl;
	cout<<"io"<<endl;
	dict->printTreeio(dict->root);
}

void Game::readTreeFromFile(string dictfile){
	dict = new BTSB();
	ifstream file(dictfile.c_str()); // converts a string to a character array
	string word;
	while (!file.eof()) { // checks for end of file
		file >> word;
		dict->insert(word, dict->root);//this was coded wrong by her lol
	}//while
	//dict->adjustBalances(dict->root);
	return;
}

void Game::checkWordsForScore(NodeTB *n){//recursively checks wordList tree against dict tree
	if(n == NULL){
		return;
	}
	checkWordsForScore(n->left);
	checkWordsForScore(n->right);
	if(checkWLetters(n->data)){//if word is used with chars given
		if(dict->search(dict->root, n->data)){//if word is in the dictionary
			numRight++;
		}//if
	}//if
}

bool Game::checkWLetters(string s){
	for(unsigned int j = 0; j<s.size(); j++){
		bool isIn = false;
		for(int i = 0; i<numLetters; i++){
			if(s[j] == currLetters[i]){//if the char is in the given letters
				isIn = true;
			}//if
		}//for
		if(!isIn){
			return false;
		}//if
	}//for
	return true;
}

char* Game::getLetters(int numChar){
	char *letters = new char[numChar];
	int numVowels = (rand()%(numChar -3)) +1;//sets numVowels to 1-(numChar-2) ie for 6, 1-3
	string vowList = "aeiou";//list of vowels
	string conList = "bcdfghjklmnpqrstvwxyz";//list of consonants
	for(int i = 0; i<numVowels; i++){
		letters[i] = vowList[rand()%5];//generates vowels
	}//for
	for(int i = 0; i<numChar - numVowels; i++){
		letters[i+numVowels] = conList[rand()%21];//generates consonants
	}//for
	cout<<"Your letters are: ";
	for(int i = 0; i<numChar; i++){//prints letters
		cout<<letters[i]<<" ";
	}//for
	cout<<endl;
	return letters;
}
void Game::getWords(){
	string letters;
	for(int i = 0; i<numLetters; i++){
		letters += currLetters[i];
	}//for
	string entry;
	cout<<"Enter a word using "<<letters<<" (-1 to exit): ";//asks for words
	cin>>entry;
	cout<<endl;
	while(entry != "-1"){//checks for exit value
		totalWords++;
		wordList->insert(entry, wordList->root);//adds entry to wordTree
		cout<<"Enter a word using "<<letters<<" (-1 to exit): ";
		cin>>entry;
		cout<<endl;
	}//while
	
}

