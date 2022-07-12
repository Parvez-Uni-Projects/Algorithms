#include <bits/stdc++.h>
using namespace std;

int partition(int *arr, int low, int high)
{
    int pivot = arr[high];
    int smallest = (low - 1);

    for (int i = low; i <= high - 1; i++)
    {
        if (arr[i] < pivot)
        {
            smallest++;
            swap(arr[smallest], arr[i]);
        }
    }

    swap(arr[smallest + 1], arr[high]);

    return (smallest + 1);
}

void Quicky(int *arr, int low, int high)
{

    if (low < high)
    {
        int div = partition(arr, low, high);
        Quicky(arr, low, div - 1);
        Quicky(arr, div+1, high);
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