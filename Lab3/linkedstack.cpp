#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* top = nullptr;

void push(int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

void pop()
{
    if (top == nullptr)
    {
        cout << "Stack Underflow" << endl;
        return;
    }

    Node* temp = top;
    cout << "Popped: " << top->data << endl;
    top = top->next;
    delete temp;
}

void peek()
{
    if (top == nullptr)
    {
        cout << "Stack is empty" << endl;
        return;
    }

    cout << "Top element: " << top->data << endl;
}

int main()
{
    int choice, value;

    do
    {
        cout << "\n1. Push";
        cout << "\n2. Pop";
        cout << "\n3. Peek";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                push(value);
                break;

            case 2:
                pop();
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