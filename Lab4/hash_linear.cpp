#include <iostream>
using namespace std;

class HashTable {
    int table[10];
    const int SIZE = 10;
public:
    HashTable() {
        for (int i = 0; i < SIZE; i++)
            table[i] = -1;
    }

    void insert(int key) {
        int index = key % SIZE;

        for (int i = 0; i < SIZE; i++) {
            int pos = (index + i) % SIZE;

            if (table[pos] == -1) {
                table[pos] = key;
                return;
            }
        }

        cout << "Hash table is full\n";
    }

    void display() {
        for (int i = 0; i < SIZE; i++) {
            cout << i << " : ";
            if (table[i] == -1)
                cout << "EMPTY ";
            else
                cout << table[i]<<"\t";
        }
    }
};

int main() {
    HashTable ht;
    int choice,key;
    do {
        cout << "\nLinear Probing Hash Table\n"; 
        cout << "1. Insert\n"; 
        cout << "2. Display\n"; 
        cout << "3. Exit\n"; 
        cout << "Enter your choice: "; 
        cin >> choice; 
        switch (choice) { 
            case 1: cout << "Enter element: "; 
                    cin >> key; 
                    ht.insert(key); 
                    break; 
            case 2: ht.display(); 
                    break; 
            case 3: cout << "Exiting...\n"; 
                    break; 
            default: cout << "Invalid choice.\n"; 
        } 
    } while (choice != 3);
    return 0;
}