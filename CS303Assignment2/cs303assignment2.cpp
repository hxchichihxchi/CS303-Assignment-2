// CS303 Assignment 2 - Duy Lam
#include "LinkedList.h"
#include "IntStack.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main() {
	// Prompts a menu for user to decide.
	int choice;
	cout << "CS303 Assignment 2\n---------------------\n";
	cout << "1: Launch Linked List \n";
	cout << "2: Launch Integer Stack \n";
	cout << "Enter anything else to quit. \n";
	cin >> choice;

	// PART 1 - LINKED LIST //
	if (choice == 1) {
		
		cout << "Launching Linked List Activity... \n" << endl;
		LinkedList<int> list;

		// Generates a list with random int values from 1-100 and pushes elements
		list.push_back(rand() % 100);
		list.push_front(rand() % 100);
		list.push_back(rand() % 100);
		list.push_front(rand() % 100);
		cout << "Generated List: ";
		list.displayList();


		// Print front and back elements
		cout << "Front: " << list.front() << endl;
		cout << "Back: " << list.back() << endl;

		// Insert an integer at inputted index value on list.
		int userIndex = 0;
		int userInput = 0;
		int userVal = 0;
		cout << "Enter an index value: " << endl;
		cin >> userInput;
		if (userInput > 4) {
			cout << "Inputted value exceeds number of items in list. Inputted value is automatically set to 4. \n";
			userInput = 4;
		}
		if (userInput < 0) {
			cout << "Inputted value is less than 0. Inputted value is automatically set to 0. \n";
			userInput = 0;
		}
		else {
			userIndex = userInput;
		}

		cout << "Inputted Index Value: " << userIndex << "\n";

		cout << "Enter an integer to add at that index value: ";
		cin >> userVal;
		list.insert(userIndex, userVal);

		// Print the list after insertion
		cout << "The New List After Adding " << userVal << " at " << userIndex << ".\n";
		list.displayList();
		cout << endl;

		// Removing an element at input index value.
		cout << "Enter an index value to remove the element from the list: ";
		cin >> userInput;
		if (userInput > 4) {
			cout << "Inputted value exceeds number of items in list. Inputted value is automatically set to 4. \n";
			userIndex = 4;
		}
		if (userInput < 0) {
			cout << "Inputted value is less than 0. Inputted value is automatically set to 0. \n";
			userIndex = 1;
		}
		else {
			userIndex = userInput;
		}
		list.remove(userIndex);

		// Print the list after removal
		cout << "The New List After Removing Element at " << userIndex << "\n";
		list.displayList();

		// Print the list after popping
		cout << "After popping back and front: ";
		list.displayList();

		// Check if the list is empty
		cout << (list.empty() ? "List is Empty" : "List is NOT Empty") << endl;
	}

	// PART 2 - INTEGER STACK //
	if (choice == 2) {
		cout << "Launching Integer Stack Activity... \n" << endl;
		

		// Creates a stack object
		IntStack stack;
		cout << "Created a stack object." << std::endl;

		// Checks if the stack is empty (This SHOULD be empty/yes since stack object is created but no elements are pushed yet.)
		cout << "The stack is now currently " << (stack.empty() ? "EMPTY" : "NOT Empty") << endl;

		
		// Generated some integer values 1-100 and pushed the stack, stack is then shown.
		cout << "Generated integer values 0-100 and pushed into stack. \n" << endl;
		stack.push(rand()%100);
		stack.push(rand()%100);
		stack.push(rand()%100);
		stack.show();

		// Check if the stack is empty again (This SHOULD be NOT Empty since elements have now been pushed into the stack.)
		cout << "The stack is now currently " << (stack.empty() ? "EMPTY" : "NOT Empty") << endl;

		// User adding more int values/elements into the stack, then shows the updated stack with the new elements.
		cout << "How many more elements would you like to add?: ";
		int userInput;
		cin >> userInput;
		// Loop that adds and pushes integers, iterates until i is equal to the user input.
		for (int i = 0; i < userInput; i++) {
			stack.push(rand() % 100);
		}

		stack.show();

		// Displaying, then removing an element from the stack. Displays the stack after removal.
		cout << "The top element in the stack currently is " << stack.top() << endl;
		cout << "Removing top element." << endl;
		stack.pop();
		stack.show();

		// Finds the top of the stack
		try {
			cout << "New Top Element of Stack: " << stack.top() << endl;
		}
		catch (const out_of_range& e) {
			cout << e.what() << endl;
		}

		// Finds the average of the stack and prints it out.
		try {
			cout << "Average Value of Stack Elements: " << stack.average() << endl;
		}
		catch (const out_of_range& e) {
			cout << e.what() << endl;
		}
	}
	else {
		cout << "\nClosing..." << endl;
		return 0;
	}
	cout << "\nClosing..." << endl;
	return 0;
}