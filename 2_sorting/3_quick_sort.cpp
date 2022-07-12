#include <bits/stdc++.h>
using namespace std;

int partition(int *arr, int low, int high)
{
    int pivot = arr[high];
    while (low <= high)
    {
        while (arr[low] < pivot)
            low++;
        while (arr[high] > pivot)
            high--;
        if (low <= high)
        {
            swap(arr[low], arr[high]);
            low++;
            high--;
        }
    }
    return low;
}

void Quicky(int *arr, int low, int high)
{
    int div = partition(arr, low, high);

    if (low < div - 1)
    {
        Quicky(arr, low, div - 1);
    }
    if (high > div)
    {
        Quicky(arr, div, high);
    }
}

int main()

{

    int size;
    cin >> size;
    int arr[size];

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    int low = 0;
    int high = size - 1;
    Quicky(arr, low, high);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}