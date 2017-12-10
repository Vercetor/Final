#pragma once
#ifndef TRILINKTREE.H
#define TRILINKTREE.H
#include <iostream>
// Trilink Node Struct.
struct TriNode {

	// Variables.
	int V1, V2;									// Value 1 and Value 2.
	bool F1, F2;								// Flag 1 and Flag 2 for deleting.
	TriNode *Parent, *Low, *Medium, *High;		// Parent and Leaf Nodes.
	int nodeCount;								// Node count increment.

};// End of Trilink Node Struct


// Trilink Tree Class
class TriTree
{

private:
	TriNode *root;		// Root for new Trilink Tree.

public:
	TriTree()
	{
		TriNode tree;		// Constructor
		tree.V1 = NULL;		// set the new V1, and V2 values to null.
		tree.V2 = NULL;

		root = new TriNode;		// Set root to new TriNode struct.
		root = NULL;			// Set root to null.

		tree.Parent = NULL;		// Set all variables in TriNode to Null.
		tree.Low = NULL;
		tree.Medium = NULL;
		tree.High = NULL;
	} // End of TriTree public variables.

	  // Member Functions for Trilink Tree.
	int insert(TriNode *&tree, int value, int nodeCount);					// Inserts value into tree.
	int search(TriNode *&tree, int value, int nodeCount);					// Search for value into tree.
	int dltValue(TriNode *&tree, int value, int nodeCount);				// Deletes a value in tree.
	void display(TriNode *&tree, int value, int nodeCount);				// Displays all values in tree.

};// End of TriTree Class
#endif // End of TrilinkTree.h