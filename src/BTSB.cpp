//Made by Paul
//Nov 2 2016

#include "BTSB.hpp"
#include "Game.hpp"
#include "NodeTB.hpp"
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <direct.h>
#include <windows.h>
using namespace std;

	BTSB::BTSB(){
		//constructor - sets root to NULL
		root = NULL;
		score = 0;
	}
	BTSB::~BTSB(){
		//destructor - deletes tree
		
	}
	bool BTSB::insert(string x){
		//Parameters: string to insert
		//inserts node to correct location then balances
		//returns true if inserted, false if already in tree
		if(root == NULL){
			root = new NodeTB(x);//makes root
			return true;
		}//if
		NodeTB *temp = root;
		while(temp!= NULL){//finds location
			if(temp->data == x){//if equal
				cout<<x<<" is already in the tree"<<endl;
				return false;
			}//if
			else if(x> temp->data){//goes right
				if(temp->right != NULL){
					temp = temp->right;
				}//if
				else{
					temp->right = new NodeTB(x);//inserts
					temp->right->parent = temp;
					adjustBalances(root);//balances
					return true;
				}//else
			}//else if
			else{//goes left
				if(temp->left != NULL){
					temp = temp->left;
				}//if
				else{
					temp->left = new NodeTB(x);//inserts
					temp->left->parent = temp;
					adjustBalances(root);//balances
					return true;
				}//else
			}//else
		}//while
		return false;
	}
	
	bool BTSB::insert(string x, NodeTB *n){
		//Parameters: string to insert, root node
		//inserts node to correct location then balances
		//uses recursion
		//returns true if value is inserted, false if already in tree
		if(root == NULL){
			root = new NodeTB(x);//creates root
			return true;
		}//if
		if(x<n->data){
			if(n->left == NULL){
				n->left = new NodeTB(x);//inserts node
				n->left->parent = n;
				updateHeights(root);
				adjustBalances(root);//balances;
				return true;
			}//if
			else{
				return insert(x, n->left);//continues left
			}//else
		}//if
		else if(x>n->data){
			if(n->right == NULL){
				n->right = new NodeTB(x);//inserts node
				n->right->parent = n;
				updateHeights(root);
				adjustBalances(root);//balances
				return true;
			}//if
			else{
				return insert(x, n->right);//continues right
			}//else
		}//else if
		else{
			cout<<x<<" is already in the tree"<<endl;
			return false;
		}//else
	return false;
	}
									 
	void BTSB::printTreeio(){
		//prints out the data in the tree in order (this should print out the dictionary alphabetically)
		if (root == NULL){
			return;
		}//if
		//NodeTB *temp = root;
	}
	void BTSB::printTreeio(NodeTB *n){
		//again, nice if you chose recursion
		if(n==NULL){
			return;
		}//if
		printTreeio(n->left);
		cout<<n->data<<" ";
		printTreeio(n->right);
		
	}
	void BTSB::printTreePre(){
		//for testing purposes, prints out tree in preorder
	}
	void BTSB::printTreePre(NodeTB *n){
		//for printing recursively
		if(n==NULL){
			return;
		}//if
		cout<<n->data<<" ";
		printTreePre(n->left);
		printTreePre(n->right);
	}
	void BTSB::printTreePost(){
		//for testing purposes, prints out tree in postorder
	}
	void BTSB::printTreePost(NodeTB *n){
		//for printing recursively
		if(n==NULL){
			return;
		}//if
		printTreePost(n->left);
		printTreePost(n->right);
		cout<<n->data<<" ";
	}

	bool BTSB::search(string x){
		//searches tree for x - returns true if found, false otherwise
		NodeTB *temp = root;
		while(temp != NULL){
			if(temp->data == x){
				return true;
			}//if
			if(x>temp->data){
				temp = temp->right;
			}//if
			else{
				temp = temp->left;
			}//else
			
		}
		return false;
	}
	bool BTSB::search(NodeTB *n, string x){
		//Parameters: root node, string to search for
		//recursively searches tree for node
		//returns true if in tree, false if not
		if(n->data == x){
			return true;
		}//if
		else if(n->data > x){
			if(n->left != NULL){
				return search(n->left, x);
			}//if
		}//else if
		else if(n->right != NULL){
			return search(n->right, x);
		}//else if
		return false;
	}
	int BTSB::adjustBalances(NodeTB *n){
		//parameters: node to be balanced under (root generally)
		//adjusts the heights of the tree below given node, uses recursion
		//returns balance value of tree (-1 to 1)
		if(n==NULL){
			return 0;//if null, balance value of "node" is 0
		}
		int lBal = adjustBalances(n->left);//balances left child of given node, returns balance value
		int rBal = adjustBalances(n->right);//"" of right child
		int nBal;
		
		if(n->left !=NULL){
			if(n->right != NULL){
				nBal = n->left->height - n->right->height;//gets balance of n
			}//if
			else{
				nBal = n->left->height;
			}//else
		}//if
		else{
			if(n->right != NULL){
				nBal = 0 - n->right->height;
			}//if
			else{
				nBal = 0;
			}//else
		}//else
		
		if(nBal >= 2){
			if(lBal == -1){//Left Right rotation
				n->left = rotateLeft(n->left);
				n = rotateRight(n);
			}//if
			else{//right rotation
				n = rotateRight(n);
			}//else
			nBal = 0;
		}//if
		else if(nBal <= -2){
			if(rBal == 1){//Right Left rotation
				n->right = rotateRight(n->right);
				n =rotateLeft(n);
			}//if
			else{//left rotation
				n = rotateLeft(n);
			}
			nBal = 0;//when any of these rotations are done, balance of node is always 0
		}//else
		//updateHeights(root);
		return nBal; //returns nBal (will range from -1 to 1)
	}
	NodeTB* BTSB::rotateLeft(NodeTB *n){
		/*for left rotation
		 * 1(n)         2
		 *  2     ->  1   3
		 *   3
		*/
		NodeTB *tempR = n->right;
		NodeTB *tempRL = n->right->left;
		tempR->left = n;
		tempR->parent = n->parent;
		if(n->parent != NULL){
			if(n->parent->right==n){
				n->parent->right=tempR;
			}//if
			else{
				n->parent->left = tempR;
			}//else
		}//if
		else{
			root = tempR;
		}//else
		n->right = tempRL;
		n->parent = tempR;
		if(tempRL!=NULL){
			tempRL->parent = n;
		}//if
		updateHeights(root);
		return tempR;
	}
	NodeTB* BTSB::rotateRight(NodeTB *n){
		//Parameters: node to rotate
		//returns pointer to new highest node
		/*for right rotation
		 *   3(n)       2
		 *  2     ->  1   3
		 * 1 LR         LR
		*/ 
		NodeTB *tempL = n->left;
		NodeTB *tempLR = n->left->right;
		tempL->right = n;
		tempL->parent = n->parent;
		if(n->parent != NULL){
			if(n->parent->right==n){
				n->parent->right=tempL;
			}//if
			else{
				n->parent->left = tempL;
			}//else
		}//if
		else{
			root = tempL;
		}//else
		n->left = tempLR;
		n->parent = tempL;
		if(tempLR !=NULL){
			tempLR->parent = n;
		}//if
		updateHeights(root);
		return tempL;
	}
	
	int BTSB::updateHeights(NodeTB *n){
		int leftPath = 0;
		int rightPath = 0;
		if((n->left == NULL) && (n->right == NULL)){
			n->height = 0;
			return 1;
		}//if
		else{
			if(n->left != NULL){
				leftPath = updateHeights(n->left);
			}//if
			if(n->right!=NULL){
				rightPath = updateHeights(n->right);
			}//if
			n->height = leftPath>=rightPath ? leftPath : rightPath;
			return n->height +1;
		}//else
	}
