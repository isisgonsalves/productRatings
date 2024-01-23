#ifndef _RATING_H
#define _RATING_H

#include <cstdlib>
using namespace std;

struct Rating {
   string personName;
   int numStars;
};

struct Node {
   Rating data;
   Node * next;
};


Node * createNode (Rating rating);

	// Creates a node in the linked list where the data is a rating struct.
	
Node * insertAtHead (Node * top, Rating rating);

	// Inserts a new rating struct at the top of the linked list and returns the new top.
	
Node * contains (Node * top, string personName);

	// Returns the node in the linked list where 'personName' rated the product.
	// If 'personName' did not rate the product, return NULL.
	
int size (Node * top);

	// Returns the amount of nodes in the linked list of ratings.
	
int getAvgRating (Node * top);

	// Finds and returns the average rating in the linked list of ratings.
	
void printRatings (Node * top);

	// Prints the all ratings for a product (person and number of stars given)
	 
void printStars (int amount);

	// Utility function to print a certain amount of stars on the monitor 

#endif
