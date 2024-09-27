#include "IntStack.h"
#include <iostream>

using namespace std;

// Push an integer onto the stack
void IntStack::push(int value) {
    stack.push_back(value);
}

// Pop an integer from the stack
void IntStack::pop() {
    if (empty()) {
        throw out_of_range("Stack is empty, cannot pop.");
    }
    stack.pop_back();
}

// Check if the stack is empty
bool IntStack::empty() const {
    return stack.empty();
}

// Get the top element of the stack
int IntStack::top() const {
    if (empty()) {
        throw out_of_range("Stack is empty, no top element.");
    }
    return stack.back();
}

// Calculate the average value of the stack elements
double IntStack::average() const {
    if (empty()) {
        throw out_of_range("Stack is empty, cannot calculate average.");
    }
    double sum = 0;
    for (int value : stack) {
        sum += value;
    }
    return sum / stack.size();
}

// Print the stack elements
void IntStack::show() const {
    if (empty()) {
        cout << "Stack is empty." << endl;
        return;
    }
    cout << "Current Stack: ";
    for (int value : stack) {
        cout << value << " ";
    }
    cout << endl;
}