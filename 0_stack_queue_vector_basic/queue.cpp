#include <bits/stdc++.h>
using namespace std;

queue<int> sokina;

int main ()
{

    sokina.push(10);
    sokina.push(20);
    sokina.push(30);

    cout << sokina.front()<<endl;
    sokina.pop();
    cout << sokina.front()<<endl;
    sokina.pop();
    cout << sokina.front()<<endl;
    sokina.pop();

}
