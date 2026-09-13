#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int value;
    int weight;
    double ratio;
};

bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

double fractionalKnapsack(Item items[], int n, int capacity) {
    for (int i = 0; i < n; i++)
        items[i].ratio = (double)items[i].value / items[i].weight;

    sort(items, items + n, compare);

    double totalValue = 0.0;
    int remaining = capacity;

    for (int i = 0; i < n; i++) {
        if (remaining == 0)
            break;

        if (items[i].weight <= remaining) {
            totalValue += items[i].value;
            remaining -= items[i].weight;
        } else {
            double fraction = (double)remaining / items[i].weight;
            totalValue += items[i].value * fraction;
            remaining = 0;
        }
    }

    return totalValue;
}

int main() {
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    Item items[n];

    cout << "Enter value and weight of each item:\n";

    for (int i = 0; i < n; i++)
        cin >> items[i].value >> items[i].weight;

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    double result = fractionalKnapsack(items, n, capacity);

    cout << "Maximum value = " << result << endl;

    return 0;
}