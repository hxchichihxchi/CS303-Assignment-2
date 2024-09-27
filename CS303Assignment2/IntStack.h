#pragma once
#include <vector>
#include <stdexcept>

using namespace std;

class IntStack {
private:
    vector<int> stack;
// Functions for IntStack
public:
    void push(int value);
    void pop();
    bool empty() const;
    int top() const;
    double average() const;
    void show() const;
};
