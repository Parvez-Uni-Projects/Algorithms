// Given a set find the subsets where the sum of elements of subset will be equal to x

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair

int sum_wanted = 0;
int maximum_possible_sum = 0;
int minimum_possible_sum = 0;

typedef vector<int> v_int;
typedef pair<int, v_int> vi;
typedef pair<int, vi> vii;
typedef pair<int, vii> viii;
vector<viii> jumbo;
v_int user_input;

stack<viii> s;

void take_user_input(int n)
{
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        maximum_possible_sum += x;
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

void push_into_stack()
{
    int curr_key;
    int curr_level;
    int curr_sum;
    v_int curr_route;

    while (!s.empty())
    {

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

            s.push(mp(curr_key, mp(curr_level, mp(curr_sum, curr_route))));

            curr_key += user_input[curr_level - 2];
            curr_route[curr_level - 2] = 1;

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
            s.pop();
        }
    }
}
void set_min_max()
{

    minimum_possible_sum = *min_element(user_input.begin(), user_input.end());
    cout << "Maximum possible sum is  " << maximum_possible_sum << endl;
    cout << "Minimum possible sum is  " << minimum_possible_sum << endl;
}

int main()
{
    int n;
    cin >> n;
    v_int route(n, 0);
    take_user_input(n);
    show_vector(user_input);
    cout << endl;
    set_min_max();

    if (maximum_possible_sum < sum_wanted)
    {
        cout << "Wanted sum is greater then sets sum\nNot possible to find the sum " << sum_wanted << endl;
    }
    else if (sum_wanted < minimum_possible_sum)
    {
        cout << "Wanted sum is smaller then sets sum\nNot possible to find the sum " << sum_wanted << endl;
    }
    else
    {
        // current sum - level - current total sum - current route
        jumbo.push_back(mp(0, mp(1, mp(maximum_possible_sum, route))));
        s.push(jumbo[0]);
        push_into_stack();
    }
}

/*
6
5 10 12 13 15 18
80
*/
