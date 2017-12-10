// FinalColinPowersTriLinkTree.cpp

#include "stdafx.h"
#include "TrilinkTree.h"
#include <iostream>

using namespace std;

//******************************************************
//***  Method Name: Main
//***  Method Author: Colin P.
//******************************************************
//*** Purpose of the Method: Main Function.
//*** Method parameters: user prompt, call other functions and output.
//*** Return value: none.
//******************************************************
//*** Date: 12/7/17
//******************************************************
int main()
{
	// Variables
	int value;			// holds input for number to be entered into Trilink tree.
	int choice;			// User input for menu navigation with switch statement.
	int nodeCount = 0;		// Counts node increments.

	// Constructor
	TriTree tree;

	// cout display to welcome the user.
	cout << "Welcome! This program uses a Trilink Tree to store integers!" << endl;
	while (1) {																						// looping menu till user exits.
		cout << "+++++MENU+++++" << endl;
		cout << "1) Insert Int. into Trilink Tree." << endl;
		cout << "2) Search for Int. in Trilink Tree." << endl;
		cout << "3) Delete number in Trilink Tree." << endl;
		cout << "4) Display the Trilink Tree." << endl;
		cout << "5) Exit the program." << endl;
		cout << "Please make a selection by entering a number: ";
		cin >> choice;																				// Get the users input for the Trilink Tree.
		cout << endl;

		// Switch statement to implement users choice.
		switch (choice) {
		case 1: cout << "Enter an Int. to be inserted into the Trilink Tree: " << endl;
			cin >> value;																			// Get the Int. the user wants to put into the Trilink Tree.
			tree.insert(tree.root, value, nodeCount);																		// Call the insert function and pass the user value.
			break;
		case 2: cout << "Enter and Int. to be search for." << endl;
			cin >> value;
			tree.search(tree.root, value, nodeCount);
			break;
		case 3: cout << "Enter an Int. to be removed from the Trilink Tree: " << endl;
			cin >> value;																			// Get User input for Int. to be deleted.
			tree.dltValue(tree.root, value, nodeCount);																	// Call the dltValue function.
			break;
		case 4: cout << "Your Trilink Tree is: " << endl;
			tree.display(tree.root, value, nodeCount);																	// Call the display function.
			break;
		case 5: exit(0);																			// Exit the program.
			break;
		default: cout << "You have made an invalid selection. Please try again" << endl << endl;   // Catch error message for invalid selections.
		} // End of switch statement
	}// End of while statement

    return 0;
}// End of Main.

 //******************************************************
 //***  Method Name: Insert
 //***  Method Author: Colin P.
 //******************************************************
 //*** Purpose of the Method: Inserts value into trilink tree.
 //*** Method parameters: int value. the value passed from main that is the users selection.
 //*** Return value: none.
 //******************************************************
 //*** Date: 12/7/17
 //******************************************************
int TriTree::insert(TriNode *&tree, int value, int nodeCount)
{
	// If tree is empty make a new node and make it the root of the tree,
	if (!tree)
	{
		root = new TriNode(*tree);	// tree becomes a new TriNode root.
		nodeCount++;				// Increments Node Count.
		return nodeCount;			// Returns Node Count to Main.
	}

	// New value >= V1, and V2 is empty, stores value in V2.
	if (value >= tree->V1 && tree->V2 = NULL)
	{
		tree->V2 = value;
		nodeCount++;
		return nodeCount;
	}
	// New value is <= V1, create new node and link to Low.
	if (value <= tree->V1)
	{
		insert(tree->Low, value, nodeCount);	// Creates new node and links to Low.
		nodeCount++;							// Increments Node Counter.
		return nodeCount;						// Returns Node Counter to Main.
		
	}

	// New value is >= V1, and <= V2, create new node and link to Medium.
	else if (value >= tree->V1 && value <= tree->V2)
	{
		insert(tree->Medium, value, nodeCount);	// Creates new node and links to Medium.
		nodeCount++;							// Increments Node Counter.
		return nodeCount;						// Returns Node Counter to Main.
	}

	// New value is >= V2, create new node and link to H.
	else if (value >= tree->V1 && value <= tree->V2)
	{
		insert(tree->High, value, nodeCount);	// Creates new node and links to High.
		nodeCount++;							// Increments Node Counter.
		return nodeCount;						// Returns Node Counter to Main.
	}

	// If number is already in tree, ignore duplicate number
	else if (tree->V1 == value || tree->V2 == value)					// Checks if user input is equal too anything in V1 or V2of the entire tree.
	{
		return;				// returns no value to main, does not increment node counter.
	}
}// End of Insert.

 //******************************************************
 //***  Method Name: Search
 //***  Method Author: Colin P.
 //******************************************************
 //*** Purpose of the Method: Searches for value in trilink tree.
 //*** Method parameters: int value.
 //*** Return value: none.
 //******************************************************
 //*** Date: 12/7/17
 //******************************************************
int TriTree::search(TriNode *&tree, int value, int nodeCount)
{
	// Search value for user entered search int.
	TriNode* SValue;
	SValue = root;

	// Message to find int. user wants.
	cout << "Which integer are you searching for?" << endl;
	cin >> SValue;

	// Check to see if tree is not empty.
	if (tree != NULL)
	{
		// This finds the root node of either V1 or V2.
		while (SValue)
		{
			parent = SValue;
			if (tree->root > SValue->V1]) SValue = SValue->V1;
			else SValue = SValue->V2;
		}

		// This searches for the value entered by the user.
		// Once user entered value is found,  ix will equal the value, and the while loop 
		// will cout it has been found, and the loop will end.
		while (int ix = 0; ix != SValue; ix++)
		{
			if (SValue->V1) // if V1 was identified as the root.
			{
				if (SValue = tree->Low)
				{
					SValue->V1 = tree->Low;
					ix = SValue->V1;
					cout << "Your integer has been found!" << endl;
				}
				else if (SValue = tree->Medium)
				{
					SValue->V1 = tree->Medium;
					ix = SValue->V1;
					cout << "Your integer has been found!" << endl;
				}
				else if (SValue = tree->High)
				{
					SValue->V1 = tree->High;
					ix = SValue->V1;
					cout << "Your integer has been found!" << endl;
				}
			}
			else // if V2 was identified as the root.
			{
				if (SValue->V2) // if V1 was identified as the root.
				{
					if (SValue = tree->Low)
					{
						SValue->V2 = tree->Low;
						ix = SValue->V2;
						cout << "Your integer has been found!" << endl;
					}
					else if (SValue = tree->Medium)
					{
						SValue->V2 = tree->Medium;
						ix = SValue->V2;
						cout << "Your integer has been found!" << endl;
					}
					else if (SValue = tree->High)
					{
						SValue->V2 = tree->High;
						ix = SValue->V2;
						cout << "Your integer has been found!" << endl;
					}
				}
			}
			if (ix != SValue)
			{
				cout << "Integer not found.";
				break;
			}
		}
	}
	else
	{	// if the tree is empty, cout message
		cout << "Tree is empty." << endl;
	}
	return;
}// End of Search.

//******************************************************
//***  Method Name: dltValue
//***  Method Author: Colin P.
//******************************************************
//*** Purpose of the Method: Deletes value in trilink tree.
//*** Method parameters: int value.
//*** Return value: none.
//******************************************************
//*** Date: 12/7/17
//******************************************************
int TriTree::dltValue(TriNode *&tree, int value, int nodeCount)
{
	// boolean flags for nodes to delete integer. True == deleted, False == not found.
	TriNode* F1;
	TriNode* F2;

	// Value to be deleted.
	TriNode* SValue;

	// Message to find int. user wants.
	cout << "Which integer do you want to delete" << endl;
	cin >> SValue;

	// Check to see if tree is not empty.
	if (tree != NULL)
	{
		// This finds the root node of either V1 or V2.
		while (SValue)
		{
			parent = SValue;
			if (tree->root > SValue->V1]) SValue = SValue->V1;
			else SValue = SValue->V2;
		}

		// This searches for the value entered by the user.
		// Once user entered value is found,  ix will equal the value, and the while loop 
		// will cout it has been found, and the loop will end.
		while (int ix = 0; ix != SValue; ix++)
		{
			if (SValue->V1) // if V1 was identified as the root.
			{
				if (SValue = tree->Low)
				{
					SValue->V1 = tree->Low;
					delete tree->Low;		// deletes value
					F1 == 1;				// Sets bool F1 to true.
					return F1;
					ix = SValue->V1;
					cout << "Your integer has been deleted!" << endl;
				}
				else if (SValue = tree->Medium)
				{
					SValue->V1 = tree->Medium;
					delete tree->Medium;		// deletes value
					F1 == 1;				// Sets bool F1 to true.
					return F1;
					ix = SValue->V1;
					cout << "Your integer has been deleted!" << endl;
				}
				else if (SValue = tree->High)
				{
					SValue->V1 = tree->High;
					delete tree->High;		// deletes value
					F1 == 1;				// Sets bool F1 to true.
					return F1;
					ix = SValue->V1;
					cout << "Your integer has been deleted!" << endl;
				}
			}
			else // if V2 was identified as the root.
			{
				if (SValue->V2)
				{
					if (SValue = tree->Low)
					{
						SValue->V2 = tree->Low;
						delete tree->Low;		// deletes value
						F2 == 1;				// Sets bool f2 to true.
						return F2;
						ix = SValue->V2;
						cout << "Your integer has been deleted!" << endl;
					}
					else if (SValue = tree->Medium)
					{
						SValue->V2 = tree->Medium;
						delete tree->Medium;		// deletes value
						F2 == 1;				// Sets bool f2 to true.
						return F2;
						ix = SValue->V2;
						cout << "Your integer has been deleted!" << endl;
					}
					else if (SValue = tree->High)
					{
						SValue->V2 = tree->High;
						delete tree->High;		// deletes value
						F2 == 1;				// Sets bool f2 to true.
						return F2;
						ix = SValue->V2;
						cout << "Your integer has been deleted!" << endl;
					}
				}
			}
			if (ix != SValue)
			{
				cout << "Integer not found.";
				break;
			}
		}
	}
	else
	{	// if the tree is empty, cout message
		cout << "Tree is empty." << endl;
	}
	return F1 && F2;
}// End of dltValue.

//******************************************************
//***  Method Name: Display
//***  Method Author: Colin P.
//******************************************************
//*** Purpose of the Method: Displays all values in trilink tree.
//*** Method parameters: int value.
//*** Return value: none.
//******************************************************
//*** Date: 12/7/17
//******************************************************
void TriTree::display(TriNode *&tree, int value, int nodeCount)
{	
	int value;

	// Check to see if tree is not empty.
	if (tree != NULL)
	{
		// Displays root.
		if (tree == root)
			cout << "Root->: " << root << endl;
		else   // increments through to give space between data.
		{
			// for loop to display all data within tree using recursion and counter.
			for (int ix = 0; ix < nodeCount; ix++)
			{
				cout << "   " << endl;
				cout << tree->V1 << endl;
				cout << tree->V2 << endl;
				display(tree->Low, value, nodeCount);
				display(tree->Medium, value, nodeCount);
				display(tree->High, value, nodeCount);
			}// End of For Loop.
		}// end of If/Else.
	}// End of If.
	return;
}// End of Display.

