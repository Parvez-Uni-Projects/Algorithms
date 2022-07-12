#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int linearSrch(int *arr, int low, int up, int key)
{

    for (int i = low; i < up; i++)
    {
        if (arr[i] == key)
        {

            return i;
            break;
        }
    }
    return -1;
}
int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int low = 0;
    int up = 9;
    int key;
    int index;
    bool want_to_search = true;
    int choice;
    while (want_to_search)
    {
        cout << "Enter a key to search : " << endl;
        cin >> key;

        index = linearSrch(arr, low, up, key);

        if (index >= 0)
        {
            cout << "Key is found at index " << index << endl;
        }
        else
        {
            cout << "Key not found " << endl;
        }

        cout << "\nDo you want to searach again ? \n 1. Yes \n 2. No\nEnter your choice" << endl;
        cin >> choice;
        if (choice == 2)
        {
            want_to_search = false;
        }
        else if (choice == 1)
        {
            want_to_search = true;
        }
        else
        {
            cout << "Invalid choice ending the program !" << endl;
            want_to_search = false;
        }
    }

    return 0;
}
