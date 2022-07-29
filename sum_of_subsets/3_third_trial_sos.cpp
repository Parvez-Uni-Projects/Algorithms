#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
vector<pair<int, int>> user_input;

int sum_of_all = 0;
int sum_wanted = 0;
int sum_of_negative = 0;
int maximum_possible_sum = 0;
int minimum_possible_sum = 0;

int negative_count = 0;
int positive_count = 0;

typedef vector<int> v_int;
typedef pair<int, v_int> vi;
typedef pair<int, vi> vii;
typedef pair<int, vii> viii;
vector<viii> jumbo;

stack<viii> s;

void take_user_input(int n)
{
    int x;
    // cout << "Enter the elements " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x < 0)
        {
            sum_of_negative += x;
            negative_count += 1;
        }
        else
        {
            positive_count += 1;
            maximum_possible_sum += x;
        }
        sum_of_all += x;

        user_input.push_back(make_pair(x, i));
    }
    // cout << "Enter the sum you want " << endl;
    cin >> sum_wanted;
}

void set_min_max(vector<pair<int, int>> v)
{
    if (negative_count == 0)
    {
        sort(v.begin(), v.end());
        minimum_possible_sum = v[0].first;
    }

    else
        minimum_possible_sum = sum_of_negative;
    if (positive_count == 0)
    {
        sort(v.begin(), v.end(), greater<>());
        maximum_possible_sum = v[0].first;
    }

    cout << "Maximum possible sum is  " << maximum_possible_sum << endl;
    cout << "Minimum possible sum is  " << minimum_possible_sum << endl;
}
void show_vector(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void show_user_input(vector<pair<int, int>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << " " << v[i].second << endl;
    }
}

void push_into_stack()
{
    v_int route(user_input.size(), 0);
    jumbo.push_back(mp(0, mp(1, mp(sum_of_all, route))));
    s.push(jumbo[0]);
    int curr_key;
    int curr_level;
    int curr_sum;
    v_int curr_route;
    int val_pos;
    int i = 1;
    while (!s.empty())
    {

        if ((s.top().first < sum_wanted && s.top().second.second.first != 0) || i == 1)
        {
            curr_key = s.top().first;
            curr_level = s.top().second.first;
            curr_sum = s.top().second.second.first;
            curr_route = s.top().second.second.second;
            val_pos = user_input[curr_level - 1].second;

            s.pop();

            curr_route[val_pos] = 0;
            curr_sum -= user_input[curr_level - 1].first;
            curr_level += 1;

            s.push(mp(curr_key, mp(curr_level, mp(curr_sum, curr_route))));

            curr_key += user_input[curr_level - 2].first;
            curr_route[val_pos] = 1;

            s.push(mp(curr_key, mp(curr_level, mp(curr_sum, curr_route))));
            i++;
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

int main()
{
    int n;

    cin >> n;

    take_user_input(n);

    set_min_max(user_input);

    if (maximum_possible_sum < sum_wanted || sum_wanted < minimum_possible_sum)
    {
        cout << "Wanted sum is out of range\nNot possible to find the sum " << sum_wanted << endl;
    }

    else
    {
        if (sum_wanted < 0)
        {
            sum_wanted *= -1;
            sum_of_all *= -1;
            for (int i = 0; i < user_input.size(); i++)
            {
                user_input[i].first *= -1;
            }
        }
        sort(user_input.begin(), user_input.end());
        push_into_stack();
    }
}