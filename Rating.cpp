#include <iostream>
#include <cstdlib>
#include "Rating.h"

using namespace std;

    
Node * createNode (Rating rating) {
	
	Node * newNode; 
   
   newNode = new Node;
   newNode->data = rating;
   newNode->next = NULL;
   return newNode;

   return NULL;
}


Node * insertAtHead (Node * top, Rating rating) {
   
   Node * newNode;
   
   newNode = createNode (rating);
   newNode->next = top; 			
   top = newNode;
   
   return top;    
  
}   



Node * contains (Node * top, string personName) {

   Node * curr;
   
   curr = top;
   while (curr != NULL) {
   	
	    if (curr->data.personName == personName)
	         return curr; 
	  	curr = curr->next;
   }
   return NULL;      
   
}



int size (Node * top) {
	
	Node * curr;
    int numNodes = 0;
   
   curr = top;
   while (curr != NULL) {
      numNodes = numNodes + 1;
      curr = curr->next;
   }
   return numNodes;
}



int getAvgRating (Node * top) {
	
   Node * curr;
   
   curr = top;
   int sum = 0;
   double avg = 0.0;
   
   int count= 0;
   
   if(curr == NULL){
//  	cout<<"\tNo ratings to determine Average.\n"<<endl;
   	return 0;
   }
   	
   
   while (curr != NULL) {
   	  count++;
   	  sum = sum + curr->data.numStars;
      curr = curr->next;
    }
  	
  	avg = sum/count;
	
   return avg;

}


void printRatings (Node * top) {

	Node * curr;
   
   curr = top;
   
   if(curr == NULL){
   	cout<<"No ratings as yet!"<<endl;
   }

   
   while (curr != NULL) {
   	  
      cout <<"\t\t" <<curr -> data.personName << ": ";
      cout << curr -> data.numStars;
      curr = curr->next;
      
      cout <<endl;
   }
  	 cout << "\n";
}



void printStars (int amount) {
	
	if(amount == 0){
		cout<<"-";
	}
	
	for(int i=0; i <amount ; i++){
		cout<<"*";
	}
	cout<<endl;

}
