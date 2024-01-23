#include <iostream>
#include <fstream>
#include "Rating.h"
#include "Product.h"

using namespace std;

// insert your additional function prototypes here (if needed) 
int menu();

// write the code for your additional functions here (if needed)
int menu () {
	
	int option;
	bool validOption;
	
	validOption = false;
	
	while (!validOption) {
		cout << endl;
		cout << "\n\n\t\t\t      Isis Gonsalves : 816026980" << endl;
		cout << "\t\t\t\tCOMP 2611 ASSIGNMENT 1" << endl;
		cout << "\t\t\t\t----------------------" << endl;
		cout << endl;
		cout << "\t  Enter 1:  To Read data from Product.txt." << endl;
		cout << "\t  Enter 2:  To Display all the ratings for a product and the average rating." << endl;
		cout << "\t  Enter 3:  To Find the ratings for all products by a certain person." << endl;
		cout << "\t  Enter 4:  To Find the products which have an average rating >= n stars." << endl;
		cout << "\t  Enter 5:  To Add a rating for a product." << endl;
		cout << "\t  Enter 6:  To Update the rating for a product." << endl;
		cout << "\t  Enter 7:  To Quit. "<<endl<<endl;
		cout << "\t  Enter Option:  ";
		cin  >> option;
		cout<<endl;
	
		if (option >= 1 && option <= 7)	
			validOption = true;
		else{
			cout<<"\nSorry, option 1 to 7 must be entered. Please try again."<<endl;
			//system("cls");	
		}
			
	}								
	
	return option;
}

int main() {
	
	Rating rating;
	Product products[1000];
	
	char filename [100] = "Product.txt"; 
	
	int numProducts = 0;

	// write code to display menu and process options selected by user
	
	numProducts = readProducts(products,filename); // read before to run other options without running option 1 first.
		
	int choice= menu();
	
	while (choice != 7){
		
		if (choice == 1){
			 numProducts = readProducts(products,filename);
			 cout<<"\nData read and sorted successfully..."<<endl;
		}
		else
			if (choice == 2){
	
				string key;
				cout<<"Enter key: ";
				cin>>key;
				
				printProductRatings(products,numProducts,key);
			}
			else
				if (choice == 3){
					
					string personName;
					cout<<"Enter person name: ";
					cin>>personName;
					cout<<endl;
					
					printRatingsByPerson(products,numProducts,personName);
					
				}
				else
					if (choice == 4){
						int numOfStars;
						cout<<"Enter Number of stars: ";
						cin>>numOfStars;
						
						printProductRatingsGTE(products,numProducts,numOfStars);
					}
					else
						if (choice == 5){
							
							string code;
							cout<<"Enter code: ";
							cin>>code;
							addRating(products,numProducts,code,rating);
							
						}
						else
							if (choice == 6){
								
								string code;
								cout<<"Enter code: ";
								cin>>code;
								updateRating(products,numProducts,code,rating);
	
							}
										
		choice=menu();
	}
	
	cout<<"\nExit successful... "<<endl;
	
	// you will need to call functions from Product.cpp and Rating.cpp
		
	return 0;	
		
}
