#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int ternarySrch(int *arr, int low, int up, int key)
{
    //cout << key<<endl;

    int mid_1 = 0;
    int mid_2 = 0;
    int difference = 0;
    if (up == low)
    {
        if (key == arr[low])
            return low;
        else
            return -1;
    }
    else if ((up - low) == 1 )
    {
        if (key == arr[low])
        {
            return low;
        }
        else if (key == arr[up])
        {
            return up;
        }
        else 
        return -1;
    }
    else
    {
        difference = (up- low);
        mid_1 = low + (difference/ 3);
        mid_2 = up - (difference/ 3);
        if (key == arr[mid_1])
            return mid_1;
        else if (key == arr[mid_2])
        {
            return mid_2;
        }
        else if (key < arr[mid_1])
        {
            cout << "Hitted in the first block" << endl;
            return ternarySrch(arr, low, mid_1 - 1, key);
        }
        else if (key < arr[mid_2])
        {
            cout << "Hitted in the second block" << endl;
            return ternarySrch(arr,mid_1 +1 , mid_2-1,key);
        }
        else
        {
            cout << "Hitted in the third block" << endl;
            //cout << "Hitted here" << endl;
           return ternarySrch(arr, mid_2 + 1, up, key);

        }
            
    }
    return 0;
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

        index = ternarySrch(arr, low, up, key);

        

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
