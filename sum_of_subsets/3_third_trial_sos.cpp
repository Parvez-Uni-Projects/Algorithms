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
            maximum_possible_sum += x;
        }
        sum_of_all += x;

        user_input.push_back(make_pair(x, i));
    }
    // cout << "Enter the sum you want " << endl;
    cin >> sum_wanted;
}

int check_case_number()
{

    int case_number = 1;

    for (int i = 0; i < user_input.size(); i++)
    {
        if (case_number == 1 && user_input[i].first < 0)
        {
            case_number = 3;
            break;
        }
    }
    if (sum_wanted < 0)
    {
        case_number += 1;
    }
    return case_number;
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
     
         if ((s.top().first < sum_wanted && s.top().second.second.first != 0 ) || i== 1)
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
        //cout << "hello world" << endl;
    }
}

int main()
{
    int n;
    // cout << "Total elements of set " << endl;
    cin >> n;

    take_user_input(n);
    // sort(user_input.begin(), user_input.end());

    int case_number = check_case_number();

    // case_number = 1  when elements of set is positive and wanted_sum is positive
    // case_number = 2  when elements of set is positive and wanted_sum is negative
    // case_number = 1  when elements of set has negative and wanted_sum is positive
    // case_number = 1  when elements of set has negative and wanted_sum is negative

    set_min_max(user_input);

    if (maximum_possible_sum < sum_wanted || sum_wanted < minimum_possible_sum)
    {
        cout << "Wanted sum is out of range\nNot possible to find the sum " << sum_wanted << endl;
    }
    
    else
    {
        switch (case_number)
        {
        case 1:
            cout << "All elements of set are positive and wanted sum is positive , case = 1" << endl;
            push_into_stack();
            break;
        case 2:
            cout << "Wanted sum is out of range no solution is possible" << endl;
            break;
        case 3:
            cout << "Has negative elements in set and wanted sum is positive" << endl;
            sort(user_input.begin(), user_input.end());
            push_into_stack();

            break;
        case 4:
            cout << "Case number 4 has been hit" << endl;
            sum_wanted *= -1;

            cout << "Sum wanted is " << sum_wanted << endl;
            sum_of_all *= -1;
            cout << "Sum of all is " << sum_of_all << endl;

            for (int i = 0; i < user_input.size(); i++)
            {
                user_input[i].first *= -1;
            }

            sort(user_input.begin(), user_input.end());

            push_into_stack();
            break;

        default:
            break;
        }
    }
}