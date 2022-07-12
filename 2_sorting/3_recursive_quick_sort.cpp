#include<bits/stdc++.h>
using namespace std;
#define MAX 9999
#define rep0(i,n) for(int i = 0; i < n; i++)
#define rep1(i,n) for(int i = 0; i < n; i++)
int partition(vector<int>&s, int low, int high)
{
    int pivot=s[high];
    while(low<=high)
    {
        while(s[low]<pivot)
            low++;
        while(s[high]>pivot)
            high--;
        if(low<=high)
        {
            int tmp=s[low];
            s[low]=s[high];
            s[high]=tmp;
            low++;
            high--;
        }
    }
    return low;
}
void recursiveQuickSort(vector<int>&s, int i, int j)
{
    int pIndex = partition(s,i,j);
    if(i<pIndex-1)
    {
        recursiveQuickSort(s, i, pIndex-1);
    }
    if(j>pIndex)
    {
        recursiveQuickSort(s, pIndex, j);
    }
}
int main()
{
    vector<int>digits;
    int aSize,element;
    cout<<"how many digits to be sorted?:";
    cin>>aSize;

    rep0(i,aSize)
    {
        cin>>element;
        digits.push_back(element);
    }

    recursiveQuickSort(digits,0, aSize-1);

    cout<<"List after sorting : ";

    rep0(i,aSize)
    cout<<digits[i]<<" ";
}