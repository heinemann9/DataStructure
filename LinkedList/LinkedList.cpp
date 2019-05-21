#include <iostream>
#include <string>

using namespace std;

typedef struct LinkedList
{
public:
    string item;
    LinkedList *next;

    LinkedList(string item)
    {
        this->item = item;
        this->next = nullptr;
    }
}LinkedList;

int main(void)
{
    LinkedList *header = nullptr;
    string item[] = {"12345", "2345", "345", "45"};

    cout<<"sizeof(item):"<<sizeof(item)<<endl;
    cout<<"sizeof(item[0]):"<<sizeof(item[0])<<endl;

    int i;
    for (i = 0; i < sizeof(item)/sizeof(item[0]); ++i)
    {
        LinkedList *linkedList = new LinkedList(item[i]);

        linkedList->next = header;
        header = linkedList;
    }

    LinkedList *temp = header;
    for (i = 0; i < sizeof(item)/sizeof(item[0]); ++i)
    {
        cout<<"item: "<<temp->item<<endl;
        temp = temp->next;
    }

    return 0;
}