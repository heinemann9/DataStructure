#include <iostream>

using namespace std;

int *stack;
int capacity = 5;
int top = -1;

bool isEmpty();
bool isFull();
bool push(int item);
int pop();
int peek();

int main(void)
{
    int value[] = {0, 1, 2, 3, 4};
    stack = new int[capacity];

    int i;
    for (i = 0; i < sizeof(value)/sizeof(value[0]); ++i)
    {
        push(value[i]);
    }

    cout<<"isFull: "<<((isFull() == 1) ? "true" : "false")<<endl;
    cout<<"peek: "<<peek()<<endl;
    cout<<"pop: "<<pop()<<endl;
    cout<<"isFull: "<<((isFull() == 1) ? "true" : "false")<<endl;
    cout<<"pop: "<<pop()<<endl;
    cout<<"pop: "<<pop()<<endl;
    cout<<"pop: "<<pop()<<endl;
    cout<<"pop: "<<pop()<<endl;
    cout<<"isEmpty: "<<((isEmpty() == 1) ? "true" : "false")<<endl;

    return 0;
}

bool isEmpty()
{
    if (top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isFull()
{
    if (top == capacity - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

bool push(int item)
{
    if (isFull() == true)
    {
        return false;
    }

    stack[++top] = item;
    return true;
}

int pop()
{
    if (isEmpty() == true)
    {
        throw -1;
    }

    return stack[top--];
}

int peek()
{
    if (isEmpty() == true)
    {
        throw -1;
    }

    return stack[top];
}