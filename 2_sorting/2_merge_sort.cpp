#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[10] = {87, 2, 8, 3, 11, 5, 23, 7, 9, 12};

void merge(int low, int mid, int high)
{
    int h = low;
    int i = low;
    int j = mid + 1;
    int b[100];
    while ((h <= mid) && (j <= high))
    {
        if (a[h] <= a[j])
        {
            b[i] = a[h];
            h = h + 1;
        }
        else
        {
            b[i] = a[j];
            j = j + 1;
        }
        i = i + 1;
    }

    if (h > mid)
    {
        for (int k = j; k <= high; k++)
        {
            b[i] = a[k];
            i = i + 1;
        }
    }
    else
    {
        for (int k = h; k <= mid; k++)
        {
            b[i] = a[k];
            i = i + 1;
        }
    }

    for (int k = low; k <= high; k++)
    {
        a[k] = b[k];
    }
}

void mergeSort(int low, int high)
{
    if (low < high)
    {
        int mid = ((low + high) / 2);

        mergeSort(low, mid);
        mergeSort(mid + 1, high);
        merge(low, mid, high);
    }
}

int main()
{

    int size = sizeof(a) / sizeof(a[0]);
    int lowest_index = 0;
    int highest_index = size - 1;

    cout << "The unsorted array is: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    mergeSort(lowest_index, highest_index);

    cout << "Sorted array: \n";
    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}
