// Given a set find the subsets where the sum of subsets will be equal to x

#include <bits/stdc++.h>
using namespace std;

vector<int> user_input;
int sum_of_all = 0;
int sum_wanted = 0;
#define mp make_pair
typedef vector<int> v_int;
typedef pair<int, v_int> vi;
typedef pair<int, vi> vii;
typedef pair<int, vii> viii;
vector<viii> jumbo;

stack<viii> s;

void take_user_input(int n)
{

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        sum_of_all += x;
        user_input.push_back(x);
    }

    cin >> sum_wanted;
}
void show_vector(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void debug_jumbo_stack()
{
    cout << "The first value is : " << jumbo[0].first << endl;
    cout << "The second value is : " << jumbo[0].second.first << endl;
    cout << "The third value is : " << jumbo[0].second.second.first << endl;
    cout << "The vecot is : " << endl;
    show_vector(jumbo[0].second.second.second);

    cout << "The size of the stack is : " << s.size() << endl;
    cout << "The top of the stack is : " << s.top().first << endl;
    cout << "The top of the stack is : " << s.top().second.first << endl;
    cout << "The top of the stack is : " << s.top().second.second.first << endl;
    cout << "The top of the stack is : " << endl;
    show_vector(s.top().second.second.second);
}

void push_into_stack()
{
    int curr_key;
    int curr_level;
    int curr_sum;
    v_int curr_route;

    int i = 1;
    int j = 1;
    while (!s.empty())
    {
        // cout << "\nValue of i is " << i << " "<< endl;
        if (s.top().first < sum_wanted && s.top().second.second.first != 0)
        {
            curr_key = s.top().first;
            curr_level = s.top().second.first;
            curr_sum = s.top().second.second.first;
            curr_route = s.top().second.second.second;
            s.pop();
            curr_route[curr_level - 1] = 0;
            curr_sum -= user_input[curr_level - 1];
            curr_level += 1;

            // cout << "Pushing the  " << j << " child " << endl;
            // cout << curr_key << " " << curr_level << " " << curr_sum << endl;
            // show_vector(curr_route);
            // cout << endl;
            //j++;

            s.push(mp(curr_key, mp(curr_level, mp(curr_sum, curr_route))));

            curr_key += user_input[curr_level - 2];
            curr_route[curr_level - 2] = 1;

            // cout << "Pushing the  " << j << " child " << endl;
            // cout << curr_key << " " << curr_level << " " << curr_sum << endl;
            // show_vector(curr_route);
            // cout << endl;
            j++;
            s.push(mp(curr_key, mp(curr_level, mp(curr_sum, curr_route))));
        }
        else if (s.top().first == sum_wanted)
        {

            cout << "The found route for the wanted sum is" << endl;
            show_vector(s.top().second.second.second);
            s.pop();
        }
        else if (s.top().first > sum_wanted || s.top().second.second.first == 0)
        {
            // cout << "it's too big to handle " << endl;
            // cout << "Popping bebo " << endl;

            s.pop();
            // cout << "Next top values are " << endl;
            // cout << "The top of the stack is : " << s.top().first << endl;
            // cout << "The top of the stack is : " << s.top().second.first << endl;
            // cout << "The top of the stack is : " << s.top().second.second.first << endl;
            // cout << "The top of the stack is : " << endl;
            // show_vector(s.top().second.second.second);
        }
        //i++;
    }
}

int main()
{
    int n;
    cin >> n;
    v_int route(n, 0);
    take_user_input(n);
    show_vector(user_input);
    cout << sum_of_all << endl;

    if(sum_of_all < sum_wanted)
    {

        cout << "Wanted sum is greater then sets sum\nNot possible to find the sum " << sum_wanted <<endl;
    }
    else
    {
        jumbo.push_back(mp(0, mp(1, mp(sum_of_all, route))));
    s.push(jumbo[0]);

    push_into_stack();
    }


}

/*
6
5 10 12 13 15 18
80
*/
