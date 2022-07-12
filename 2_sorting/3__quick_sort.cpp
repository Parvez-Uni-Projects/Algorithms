#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int Partition(int *arr, int lowest_index, int highest_index)
{

    int pivot_element = arr[highest_index];

    while (lowest_index <= highest_index)
    {
         lowest_index = lowest_index + 1;
        while (arr[lowest_index] < pivot_element)
        {
            lowest_index = lowest_index + 1;
        }
        highest_index = highest_index - 1;
        while (arr[highest_index] > pivot_element)
        {
            highest_index = highest_index - 1;
        }
        if (lowest_index < highest_index)
        {
            swap(arr[lowest_index], arr[highest_index]);
        }
    }

    arr[lowest_index] = arr[highest_index];
    arr[highest_index] = pivot_element;
    return highest_index;
}

void quickSort(int *arr, int lowes_index, int highest_index)
{
    if (lowes_index < highest_index)
    {
        int j = Partition(arr, lowes_index, highest_index+1 );
        quickSort(arr, lowes_index, j - 1);
        quickSort(arr, j + 1, highest_index);
    }
}
int main()
{
    // int size = sizeof(a) / sizeof(a[0]);

    // cout << "Input the array size : " << endl;

    int size;
    cin >> size;

    int arr[size];

    int lowest_index = 0;
    int highest_index = size - 1;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    // cout << "The unsorted array is: " << endl;
    // for (int i = 0; i < size; i++)
    // {
    //     cout << a[i] << " ";
    // }
    // cout << endl;

    quickSort(arr, lowest_index, highest_index);

    // cout << "Sorted array: \n";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
