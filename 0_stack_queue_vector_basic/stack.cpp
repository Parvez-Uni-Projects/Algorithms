#include <bits/stdc++.h>
using namespace std;

stack<int> sokina;

int main ()
{

    sokina.push(10);
    sokina.push(20);
    sokina.push(30);

    cout << sokina.top()<<endl;
    sokina.pop();
    cout << sokina.top()<<endl;
    sokina.pop();
    cout << sokina.top()<<endl;
    sokina.pop();
    //cout << "hello world"<<endl;
}
