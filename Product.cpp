#include <iostream>
#include <fstream>
#include "Rating.h"
#include "Product.h"
 
using namespace std;


int readProducts (Product products[], char filename [100]){ //amazing
	
	ifstream in;
	in.open(filename);
	
	int numProducts=0;
	
	string name;
	int stars;
	
	string code; 
	in>>code;

	while(code != "END"){
		
		Node * top = NULL; //reset the list after each product
		
		products[numProducts].code = code;
		in>>products[numProducts].name;

		in>>name;
		
		while (name != "###"){
			
			Rating temp;

			in>>stars;

			temp.personName=name; 	
			temp.numStars=stars; 
		
			top= insertAtHead(top, temp);
			
			in>>name;
		}
		
		products[numProducts].top = top;
		
		//printRatings(products[numProducts].top);

		numProducts++;
		
		in>>code;
		
	}

	sortProducts(products,numProducts);

	in.close();
	
	return numProducts;
}


void sortProducts (Product products[], int numProducts) {
	
	//bubble sort for products
	
	Product temp;
	
	for (int i=0;i<numProducts-1;i++){
		for (int j= 0; j<numProducts-1-i;j++){
			if (products[j+1].code < products[j].code){
				temp= products[j];
				products[j] = products[j+1];
				products[j+1] = temp;
			}
		}
	}

}


int searchProducts (Product products[], int numProducts, string key) {

	//binary search
	
	int hi=numProducts;
	int lo = 0;
	int mid;
	
	while( lo <= hi){
		
		mid= (lo+hi)/2;
		
		if (products[mid].code == key){
			return mid;
		}
		else{
			if(products[mid].code > key){
				hi=mid -1;
			}
			else {
				lo=mid + 1;
			}
		}
	}
	
	return -1;
}


void printProductRatings (Product products[], int numProducts, string code) { //looks good
	
	int location = searchProducts(products, numProducts, code);
	
	if(location != -1){
		
		cout<<"Product Name: "<<products[location].name<<"\t";
		cout<<"\n\nRatings:\n";
		printRatings(products[location].top);
		
		double avg= getAvgRating(products[location].top);
		
		cout<<"Average Rating: "<<avg<<endl;
		cout<<"Average Stars : ";
		printStars(avg);
		
		cout<<endl<<endl;
	}
	else
		cout<<"Sorry, The Product Code "<<code<<" was not found."<<endl;
	
}
	

void printRatingsByPerson (Product products[], int numProducts, string personName) { //very nice

	Node * curr;
	curr= NULL;
	
	for(int i=0; i<numProducts;i++){
	
		curr = contains(products[i].top, personName);
		
		if (curr != NULL) {
	
			cout<<"Product Name: "<<products[i].name<<"\n";
			cout<<"Product Code: "<<products[i].code<<"\n";
			cout<<"Rating given by "<<personName<<" : "<<curr->data.numStars;
					
			cout<<endl<<endl;
		}
	}
		if(curr == NULL)
			cout<<"Sorry, The Person name "<<personName<<" was not found."<<endl;
	
}	


void printProductRatingsGTE (Product products[], int numProducts, int n) { //PERFECTION
	
	int i;
	bool higher = false;
	
	for (i=0; i<numProducts;i++){
		
		int avgRating= getAvgRating(products[i].top);
		
		if(avgRating >= n){
			higher=true;
			
			cout<<"\nProduct Name  : "<<products[i].name<<"\n";
			cout<<"Product Code  : "<<products[i].code<<"\n";
			cout<<"Average Rating: "<<avgRating<<"\n";
			cout<<"Average Stars : ";
			printStars(avgRating);
			cout<<endl;
		}
	} 
	
	if(higher == false)
		cout<<"There are no products with an Average rating higher than "<<n<<endl;
	
}
	

void addRating (Product products[], int numProducts, string code, Rating rating) { //yesyesyes
	
	string name;
	
	Node * curr;
	
	int count=1;
	
	int location = searchProducts(products, numProducts, code);
	
	if(location != -1){
		
		cout<<"Enter New Name: ";
		cin>>name;
		
		curr = products[location].top;
			
			 while (curr != NULL) {
				if(curr->data.personName == name)
					count++;
				curr=curr->next;
			}
			
				if(count > 1){
					cout<<"Sorry, The same person cannot rate a product 2 or more times."<<endl;
				}
				else{
					
					rating.personName= name;
					cout<<"Enter the Rating: ";
					cin>>rating.numStars;
					
					products[location].top= insertAtHead(products[location].top, rating);
					
					cout<<"New Ratings:\n";
					printRatings(products[location].top);
				}
		
	}
	else
		cout<<"Sorry, The Product Code "<<code<<" was not found."<<endl;
}


void updateRating (Product products[], int numProducts, string code, Rating rating) {

	bool found = false;
	
	Node * curr;
	
	int location = searchProducts(products, numProducts, code);
	
	if(location != -1){
		cout<<"Enter Person Name: ";
		cin>>rating.personName;
		
		curr = products[location].top;
			
			 while (curr != NULL) {
				if(curr->data.personName == rating.personName){
					found= true;
					cout<<"Enter NEW Rating: ";
					cin>>rating.numStars;
					
					curr->data.numStars=rating.numStars;
				}	
				
				curr=curr->next;
			}
			
			if (found == false)
				cout<<"Sorry, Person name "<<rating.personName<<" not found"<<endl;	
			else{
				cout<<"Updated Ratings:\n";
				printRatings(products[location].top);
			}	
	}
	else
		cout<<"Sorry, The Product Code "<<code<<" was not found."<<endl;
	
}
