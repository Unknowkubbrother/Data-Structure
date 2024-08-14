// Stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Stack
	public:
		int size;
		int top;
		int *arr;
        Stack(int size) {
			this->size = size;
			this->top = -1;
			this->arr = new int[size];
		}
		void push(int value) {
			if (top == size - 1) {
				cout << "Stack is full" << endl;
				return;
			}
			arr[++top] = value;
		}
		int pop() {
			if (top == -1) {
				cout << "Stack is empty" << endl;
				return -1;
			}
			return arr[top--];
		}
		int peek() {
			if (top == -1) {
				cout << "Stack is empty" << endl;
				return -1;
			}
			return arr[top];
		}
		bool isEmpty() {
			return top == -1;
		}
		bool isFull() {
			return top == size - 1;
		}
		void display() {
			if (top == -1) {
				cout << "Stack is empty" << endl;
				return;
			}
			for (int i = 0; i <= top; i++) {
				cout << arr[i] << " ";
			}
			cout << endl;
		}
};

int main()
{
    std::cout << "Hello World!\n";
}
