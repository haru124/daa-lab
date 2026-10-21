#include<iostream>
using namespace std;

struct item {
    int weight;
    int value;
};

int knapsack(item items[], int numitems, int capacity) {
    int table[numitems + 1][capacity + 1];

    for (int i = 0; i <= numitems; i++) {
        for (int j = 0; j <= capacity; j++) {
            if (i == 0 || j == 0)
                table[i][j] = 0;
            else if (items[i - 1].weight <= j)
                table[i][j] = max(table[i - 1][j], items[i - 1].value + table[i - 1][j - items[i - 1].weight]);
            else
                table[i][j] = table[i - 1][j];
        }
    }

    return table[numitems][capacity];
}

int main() {
    item items[] = { {3, 7}, {4, 8},  {5, 9}, {6, 10} };

    int numitem = 4;
    int capacity = 15;

    int max = knapsack(items, numitem, capacity);

    cout << "max: " << max << endl;

    return 0;
}
