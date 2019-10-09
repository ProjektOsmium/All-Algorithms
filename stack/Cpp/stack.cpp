#include <iostream>
using namespace std;

class Stack {
private:
    int* stack;
    int top;
    int size;
public:
    Stack (int stack_size){
        size = stack_size;
        stack = new int[stack_size];
        top = -1;
    };

    void push(int value){
        if(top+1 == size){
            cout << "Stack is full!" << endl;
        }else{
            cout << value << " pushed!" << endl;
            stack[++top] = value;
        }
    }

    void pop(void){
        if(top == -1){
            cout << "Stack is empty!" << endl;
        }else{
            cout << stack[top--] << " popped!" << endl;
        }
    }

};
int main(int argc, char const *argv[]) {
    Stack stack(2); //size of 2
    stack.push(2);
    stack.push(3);
    stack.push(3);
    stack.pop();
    stack.pop();
    stack.pop();
    return 0;
}
