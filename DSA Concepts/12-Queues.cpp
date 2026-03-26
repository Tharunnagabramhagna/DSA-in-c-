#include <iostream>
#include <queue>
#include <deque>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Queue
{
    Node *head;
    Node *tail;

public:
    Queue()
    {
        head = tail = NULL;
    }

    void enqueue(int data)
    { // O(1)
        Node *newNode = new Node(data);

        if (isEmpty())
            head = tail = newNode;
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void dequeue()
    { // O(1)
        // Edge Case
        if (isEmpty())
        {
            cout << "Queue is Empty.\n";
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    int front()
    { // O(1)
        // Edge Case
        if (isEmpty())
        {
            cout << "Queue is Empty.\n";
            return -1;
        }
        return head->data;
    }

    bool isEmpty()
    { // O(1)
        return head == NULL;
    }
};

int main()
{
    Queue q;
    q.enqueue(50);
    q.enqueue(108);
    q.enqueue(121);
    q.enqueue(169);
    q.enqueue(427);

    cout << "Elements of Queue : \n";
    while (!q.isEmpty())
    {
        cout << q.front() << " ";
        q.dequeue();
    }

    cout << endl;

    queue<int> q1; // using STL libary

    q1.push(75);
    q1.push(100);
    q1.push(125);

    cout << "Elements of Queue-1 : \n";
    while (!q1.empty())
    {
        cout << q1.front() << " ";
        q1.pop();
    }

    cout << endl;

    // Deque
    deque<int> q2;

    q2.push_back(1);
    q2.push_back(11);
    q2.push_back(22);
    q2.push_front(32);

    cout << "Elements of deque in each cycle : \n";
    while (!q2.empty())
    {
        cout << q2.front() << " " << q2.back() << " ";
        q2.pop_front();
        q2.pop_back();
        cout << endl;
    }

    return 0;
}