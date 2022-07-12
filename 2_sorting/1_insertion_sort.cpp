#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int arr[10] = {1, 2, 8, 3, 11, 5, 23, 7, 9, 12};

int main()
{

    int n = sizeof(arr) / sizeof(arr[0]); // size of arr
    int temp;                             // loop variables

    cout << "The unsorted array is: "; // printing the unsorted arr
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int key, i;

    for (int j = 1; j < n; j++)
    {
        key = arr[j];
        i = j - 1;

        while ((i > 0) && (arr[i] > key))
        {
            arr[i + 1] = arr[i];
            i = i - 1;
        }
        arr[i + 1] = key;
    }

    cout << "The sorted array is:   "; // printing the sorted arr
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
