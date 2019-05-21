#include <iostream>

using namespace std;

class Stack
{
public:
    int *item;
    int capacity;
    int top;

    Stack(int stack_size)
    {
        item = new int[stack_size];
        capacity = stack_size;
        top = -1;

        for (int i = 0; i < stack_size; ++i)
        {
            this->push(i);
        }
    }

    ~Stack()
    {
        delete []item;
    }

    bool isEmpty();
    bool isFull();
    bool push(int item);
    int pop();
    int peek();
};

int main(void)
{
    int stack_size = -1;

    cout<<"stack_size:";
    cin>>stack_size;

    Stack *stack = new Stack(stack_size); 

    cout<<"isFull: "<<((stack->isFull() == 1) ? "true" : "false")<<endl;
    cout<<"isEmpty: "<<((stack->isEmpty() == 1) ? "true" : "false")<<endl;
    cout<<"peek: "<<stack->peek()<<endl;
    for (int i = 0 ; i < stack_size; ++i)
    {
        cout<<"pop: "<<stack->pop()<<endl;
    }
    cout<<"isFull: "<<((stack->isFull() == 1) ? "true" : "false")<<endl;
    cout<<"isEmpty: "<<((stack->isEmpty() == 1) ? "true" : "false")<<endl;

    return 0;
}

bool Stack::isEmpty()
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

bool Stack::isFull()
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

bool Stack::push(int item)
{
    if (isFull() == true)
    {
        return false;
    }

    this->item[++top] = item;
    return true;
}

int Stack::pop()
{
    if (isEmpty() == true)
    {
        throw -1;
    }

    return item[top--];
}

int Stack::peek()
{
    if (isEmpty() == true)
    {
        throw -1;
    }

    return item[top];
}