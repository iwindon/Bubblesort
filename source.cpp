//
//  source.cpp
//  SemesterProject - Fall 2013
//  Professor: Dr. Steven C. Shaffer
//  Created by Ivan Windon on 11/12/13.
//  Copyright (c) 2013 Ivan Windon. All rights reserved.
//  CMPSC101 - Semester Project
/*  Ask the user for a list of names. Allow the user to enter up to 25 names. After all entries are received,
 sort the list and display the list in alphabetical order. You must use arrays and create a function to sort
 and a separate function to display the  array. Implement your own bubble sort (do not use one that is built in);
 refer to http://en.wikipedia.org/wiki/Bubble_sort for details on a bubble sort.
 */


#include <iostream>
#include <string>
#include <stdio.h>
#include <iomanip>
using namespace std;


// Bubble Sort to sort through the array of 25 or less and then put the array into alphabetical order
void bubbleSort(string array[], int size) {
	bool swapped=true;
	int count=0;  // Initialized the count to begin stepping through the array.
	int number = 1;
	while(swapped) {
		swapped=false;
		count++;  // Increments the count by one to move to the next pass of the array.
		for (int i=0; i<size-number; i++) {
			if(array[i]>array[i+1]) {  // Starts by comparing the first two array elements
				string temp=array[i]; // Creates a temp location to hold the array element during the swap
				array[i]=array[i+1]; // Moves on to the next array element.
				array[i+1]=temp; // Assigns the temp value back into the proper location of the original array.
				swapped=true; // Bool to let that a swap has taken place.
			}
            
		}
	}
}

// Function that prints the names in the array onto the screen after they have been processed by the Bubble Sort
void printNames(string arg[], int length) {
	for (int n=0; n < length; n++) // Steps through the array elements one at a time.
		cout << arg[n] << endl; // Prints the array element onto the screen.
}
int main() {
	string names[25]; // Sets up the array to have up to 25 elements.
	int counter = 0;  // Sets the main counter at 0 to start accepting input into the array.
	int counter2 = 1; // The secondary counter is for displaying which name number you are currently entering
	cout << "Enter up to 25 names (type Exit to stop)" << endl;
	while (counter < 25) { // Starts the while loop, and will stop once the max of 25 has been reached.
		cout << "Enter name #" << counter2 << ": ";
		getline(cin, names[counter]);
		if (names[counter] == "Exit") { // Looks to see if Exit has been typed.
			break; // If exit is entered the data input of the array will stop and move on to the Bubble Sort.
		}
		counter ++;  // Increments the main counter by one to input the next name into the array element.
		counter2 ++; // Increments the display counter so you know you are entering the next number and where you are.
	}
	bubbleSort(names, counter); // Call of the Bubble Sort Function, passing the names entered as well as the number array elements.
	cout << endl << endl << "Your names in alphabetical order: " << endl;  // Sets up display formating
    cout << setfill('-')<<setw(35)<<"-"<<endl;
	printNames(names, counter); // Function to print out the names, which are now in alphabetical order.
	cout << endl;
    
}                                              