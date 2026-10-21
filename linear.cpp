#include <iostream>
#include <string>
using namespace std;

int linearsearch(string arr[], int N, string x)
{
    for (int i = 0; i < N; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

// Driver code
int main(void)
{
    string arr[] = { "Candle","Watch","Notebook","Pen","Mug","Stapler","Tape","Ruler","Paper clip","Eraser" };
    string x;
    cin>>x;

    int N = 10;

    // Function call
    int result = linearsearch(arr, N, x);

    if(result == -1)
        cout<<"Not Available";
    else
        cout<<"Available";
    return 0;
}
