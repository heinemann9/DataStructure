#include <iostream>

using namespace std;

class Queue
{
public:
    int capacity;
    int *item;
    int front;
    int rear;

    Queue(int queue_size)
    {
        item = new int[queue_size];
        capacity = queue_size;
        front = 0;
        rear = 0;
    }

    bool isFull();
    bool isEmpty();
    void enQueue(int item);
    int deQueue();
    int peek();
};

int main(void)
{
    int queue_size;
    cout<<"queue size:";
    cin>>queue_size;

    Queue *queue = new Queue(queue_size);

    int i;
    cout<<"before enQueue, isEmpty(): "<<(queue->isEmpty() == 1 ? "true" : "false")<<endl;
    for (i = 0; i < queue_size; ++i)
    {
        queue->enQueue(i);
    }

    cout<<"after enQueue, isEmpty(): "<<(queue->isEmpty() == 1 ? "true" : "false")<<endl;
    cout<<"after enQueue, isFull(): "<<(queue->isFull() == 1 ? "true" : "false")<<endl;
    for (i = 0; i < queue_size; ++i)
    {
        cout<<"deQueue: "<<queue->deQueue()<<endl;
    }
    cout<<"after deQueue, isEmpty(): "<<(queue->isEmpty() == 1 ? "true" : "false")<<endl;

    return 0;
}

bool Queue::isFull()
{
    if ((rear + 1) % capacity == front)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Queue::isEmpty()
{
    if (front == rear)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Queue::enQueue(int item)
{
    if (isFull() == true)
    {
        cout<<"Queue is full."<<endl;
        return;
    }

    this->item[rear] = item;
    cout<<"enQueue: "<<this->item[rear]<<endl;
    rear = ++rear % capacity;
}

int Queue::deQueue()
{
    if (isEmpty() == true)
    {
        cout<<"Queue is empty."<<endl;
        return -1;
    }

    int item = this->item[front];
    front = ++front % capacity;
    return item;
}

int Queue::peek()
{
    if (isEmpty() == true)
    {
        cout<<"Queue is empty."<<endl;
        return -1;
    }

    return this->item[front];
}