
#include <bits/stdc++.h>
using namespace std;

queue<int> min_costs_queue[2];

int main()
{
    min_costs_queue[0].push(2);
    min_costs_queue[1].push(3);
   

    cout << min_costs_queue[0].front();
    cout << min_costs_queue[1].front();
   
}
