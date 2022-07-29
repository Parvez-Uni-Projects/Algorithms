#include <bits/stdc++.h>
using namespace std;

#define mp make_pair

int sum_of_all = 0;           // total sum of all the elements
int sum_wanted = 0;           // the sum wanted form the subsets
int maximum_possible_sum = 0; // maximum possible sum of the set
int minimum_possible_sum = 0; // minimum possible sum of the set

bool negative_exits = false; // checking for negative element
bool positive_exits = false; // checking for positive element

typedef vector<int> v_int;
typedef pair<int, v_int> vi;
typedef pair<int, vi> vii;
typedef pair<int, vii> viii;
// storing  sum ,  level , sum in hand , route
stack<viii> s;
// storing value and initial given indices
vector<pair<int, int>> user_input;

void take_user_input(int n)
{
    int x;
    // cout << "Enter the elements " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x < 0)
        {
            minimum_possible_sum += x; // finding sum of all negative number
            negative_exits = true;
        }
        else
        {
            maximum_possible_sum += x; // finding sum of all positive number
            positive_exits = true;
        }
        sum_of_all += x; // sum of all elements

        user_input.push_back(make_pair(x, i)); // storing value and given order
    }
    // cout << "Enter the sum you want " << endl; //sum wanted from  the subset
    cin >> sum_wanted;
}

void set_min_max(vector<pair<int, int>> v)
{
    if (!negative_exits) // if there is no negative element
    {
        sort(v.begin(), v.end());
        minimum_possible_sum = v[0].first; // the lowest positive number is the minimum possible sum
    }

    if (!positive_exits) // if there is no positive element
    {
        sort(v.begin(), v.end(), greater<>());
        maximum_possible_sum = v[0].first; // the highest negative number is the maximum possible sum
    }

    cout << "Maximum possible sum is  " << maximum_possible_sum << endl;
    cout << "Minimum possible sum is  " << minimum_possible_sum << endl;
}
void show_vector(vector<int> v) // printing the vector
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void push_into_stack()
{
    v_int route(user_input.size(), 0);           // initializing the route
    s.push(mp(0, mp(0, mp(sum_of_all, route)))); // initializing the stack as level = 0
    int curr_key;
    int curr_level;
    int curr_sum;
    v_int curr_route;
    int value_indice;
    bool first_push = true;
    while (!s.empty())
    {

        if ((s.top().first < sum_wanted && s.top().second.second.first != 0) || first_push)
        {
            curr_key = s.top().first;                     //  retrieving the sum of subsets
            curr_level = s.top().second.first;            //  retrieving  level
            curr_sum = s.top().second.second.first;       //  retrieving  sum in hand
            curr_route = s.top().second.second.second;    // retrieving the route
            value_indice = user_input[curr_level].second; // index number of value to be added

            s.pop();                                  // popping from the stack
            curr_sum -= user_input[curr_level].first; // deleting the set element value

            s.push(mp(curr_key, mp(curr_level + 1, mp(curr_sum, curr_route)))); // pushing right child

            curr_key += user_input[curr_level].first; // addign the set element value
            curr_route[value_indice] = 1;             // setting route[i] = 1 as left child

            s.push(mp(curr_key, mp(curr_level + 1, mp(curr_sum, curr_route)))); // pushing left child
            first_push = false;                                                 // first time pushed
        }
        else if (s.top().first == sum_wanted) // if the sum is found
        {
            cout << "The found route for the wanted sum is" << endl;
            show_vector(s.top().second.second.second); // printing the route
            s.pop();
        }
        else if (s.top().first > sum_wanted || s.top().second.second.first == 0)
        {
            s.pop(); // if it is greater than popping it
        }
    }
}

int main()
{
    int n;
    // cout << "Enter total number of elements" <<endl;
    cin >> n;

    take_user_input(n); // take user input

    set_min_max(user_input);

    if (maximum_possible_sum < sum_wanted || sum_wanted < minimum_possible_sum) // checking the range
    {
        cout << "Wanted sum is out of range\nNot possible to find the sum " << sum_wanted << endl;
    }

    else
    {
        if (sum_wanted < 0) // if the sum wanted is negative flipping all the signs
        {
            sum_wanted *= -1;
            sum_of_all *= -1;
            for (int i = 0; i < user_input.size(); i++)
            {
                user_input[i].first *= -1;
            }
        }
        sort(user_input.begin(), user_input.end()); // sorting the values in ascending order
        push_into_stack();                          // starting the process
    }
}