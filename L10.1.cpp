#include <iostream>
using namespace std;

class StackArray {
private:
    int arr[100];
    int top;

public:
    StackArray() {
        top = -1;
    }

    void push(int x) {
        if (top >= 99) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = x;
    }

    void pop() {
        if (top < 0) {
            cout << "Stack Underflow" << endl;
            return;
        }
        cout << "Popped: " << arr[top--] << endl;
    }

    void display() {
        if (top < 0) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    StackArray stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.display();

    stack.pop();
    stack.display();

    return 0;
}
