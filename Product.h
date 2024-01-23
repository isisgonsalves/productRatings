#ifndef _PRODUCT_H
#define _PRODUCT_H

struct Product {
   string code;
   string name;
   Node * top;
};

int readProducts (Product products[], char filename []);

	// Reads the product data from 'filename' and stores in the 'products' array.
	// Return the amount of products read.
	
void sortProducts (Product products[], int numProducts);

	// Sort the products in the 'products' array in ascending order by code
	 
int searchProducts (Product products[], int numProducts, string key);

	// Searches the products in the 'products' array for 'key'.
	// Binary search must be used.
	
void printProductRatings (Product products[], int numProducts, string code);

	// Prints all the ratings for the product with the given 'code'.
	
void printRatingsByPerson (Product products[], int numProducts, string personName);

	// Prints all the ratings made by 'personName'.
	
void printProductRatingsGTE (Product products[], int numProducts, int n);

	// Prints product data for all products where the average rating is >= 'n'.
	
void addRating (Product products[], int numProducts, string code, Rating rating);

	// Adds a new rating for the product with the given 'code'.
	
void updateRating (Product products[], int numProducts, string code, Rating rating);

	// Updates a rating of the product with the given 'code'.
	
#endif
