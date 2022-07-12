#include <bits/stdc++.h>
using namespace std;

vector<int> parvez[10];

int  main ()
{
    /*
        parvez[1].push_back(2);
        parvez[1].push_back(3);
        parvez[1].push_back(4);
        parvez[3].push_back(4);
        parvez[2].push_back(3);

        */
    int source , destination;


    for (int i = 1 ; i <= 5; i++)
    {
        cout << "Edge : " << i << "\n"<< "Source: ";
        cin >> source ;
        cout <<"Destination: ";
        cin>> destination;

        parvez[source].push_back(destination);
        parvez[destination].push_back(source);

    }


    for (int i = 1; i <= 4 ; i++)
    {
        cout << "Node " << i << " Is connected to edge "<<endl;
        for (int j = 0 ; j <parvez[i].size();j++)
        {
            cout << parvez[i][j]<<" ";
        }
        cout <<endl;
    }

    cout <<endl;
    cout << parvez[1].size()<<endl;

    cout << parvez[1][0]<<endl;
    cout << parvez[1].front()<<endl;
   // cout << parvez[i].erase(0);

    //parvez[1].erase();

}
