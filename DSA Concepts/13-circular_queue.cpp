#include <iostream>
using namespace std;

// front => f ; rear => r
class circularQueue
{
    int *arr;
    int currSize, cap;
    int f, r;

public:
    circularQueue(int size)
    {
        cap = size;
        arr = new int[cap];
        currSize = 0;
        f = 0;
        r = -1;
    }

    void push(int data)
    { // O(1)
        if (currSize == cap)
        {
            cout << "Cirular Queue is Full.\n";
            return;
        }
        r = (r + 1) % cap;
        arr[r] = data;
        currSize++;
    }

    void pop()
    { // O(1)
        if (empty())
        {
            cout << "Circular Queue is Empty.\n";
            return;
        }
        f = (f + 1) % cap;
        currSize--;
    }

    int front()
    { // O(1)
        if (empty())
        {
            cout << "Circular Queue is Empty.\n";
            return -1;
        }
        return arr[f];
    }

    bool empty()
    { // O(1)
        return currSize == 0;
    }
};

int main()
{
    circularQueue cq(5);

    cq.push(1);
    cq.push(2);
    cq.push(3);
    cq.push(4);
    cq.pop();
    cq.push(5);
    cout << "Elements of Circular Queue : \n";
    while (!cq.empty())
    {
        printf("%d ", cq.front());
        cq.pop();
    }
    cout << endl;

    return 0;
}