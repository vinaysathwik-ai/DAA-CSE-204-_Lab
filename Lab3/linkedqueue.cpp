#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* front = nullptr;
Node* rear = nullptr;

void enqueue(int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (rear == nullptr)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue()
{
    if (front == nullptr)
    {
        cout << "Queue Underflow" << endl;
        return;
    }

    Node* temp = front;
    cout << "Deleted: " << front->data << endl;
    front = front->next;

    if (front == nullptr)
        rear = nullptr;

    delete temp;
}

void peek()
{
    if (front == nullptr)
    {
        cout << "Queue is empty" << endl;
        return;
    }

    cout << "Front element: " << front->data << endl;
}

int main()
{
    int choice, value;

    do
    {
        cout << "\n1. Enqueue";
        cout << "\n2. Dequeue";
        cout << "\n3. Peek";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 5:
                break;

            default:
                cout << "Invalid choice" << endl;
        }

    } while (choice != 5);

    return 0;
}