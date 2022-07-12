// Sample code to try 
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int>mpr;
//vector<pair<int,int>>testv;
vector<mpr>testv;


bool bfun(mpr a, mpr b)
{
    return a.second<b.second;
}

bool bsfun(int a, int b)
{
    return a>b;
}

bool bCount(int node)
{
    if (node == 5)
        return true;
    return false;
}

int main()
{
    // step 1
    testv.push_back(make_pair(10,500));
    testv.push_back(make_pair(20,900));
    testv.push_back(make_pair(50,100));
   
    /*
    // step 1
    cout<<testv[0].first  <<endl;
    cout<<testv[0].second  <<endl;
    cout<<testv[1].first  <<endl;
    cout<<testv[1].second  <<endl;
    cout<<testv[2].first  <<endl;
    cout<<testv[2].second  <<endl;*/
   
    // then try using loop
   
    // step 2
    cout<<"Before sort fun call "<<endl;
   
    int indeex;
    for(indeex=0; indeex<3; indeex++)
    {
        cout<<testv[indeex].first<<" ";
        cout<<testv[indeex].second<<endl;
    }
   
    cout<<"After sort fun call "<<endl;
    sort(testv.begin(), testv.end(), bfun);
   
    int k;
    for(k=0; k<3; k++)
    {
        cout<<testv[k].first<<" ";
        cout<<testv[k].second<<endl;
    }
   
    // step 3
   
    vector<int>simpleV;
    for(k=0;k<10;k++)
    {
        simpleV.push_back(k);
    }
   
   
    cout<<"Before sort fun call "<<endl;
    for(k=0; k<10;k++)
    {
        cout<<simpleV[k]<<" ";
    }
    cout<<endl;
    sort(simpleV.begin(), simpleV.end(), bsfun);
   
   
   
    cout<<"after sort fun call "<<endl;
    for(k=0; k<10;k++)
    {
        cout<<simpleV[k]<<" ";
    }
   
    cout<<endl;
   
    int countNODE, cN;
    countNODE=count(simpleV.begin(), simpleV.end(), 1);
    cN= count_if(simpleV.begin(), simpleV.end(), bCount);
   
    cout<<countNODE<<" "<<cN;
   

    return 0;
}