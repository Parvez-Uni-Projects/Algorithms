// Write a program to sort implement priority queue using vector.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> priority;
vector<int> user_input;

void sample_user_input()
{
    user_input.push_back(10);
    user_input.push_back(30);
    user_input.push_back(5);
    user_input.push_back(1000);
    user_input.push_back(9);
    user_input.push_back(20);
}

void print_vector(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
int main()
{
    /**========================================================================
     * !                     Priority Queue Implemented by the user           *
     *========================================================================**/
    sample_user_input(); // taking input from user just an exapmple
    cout << "Before adding user input into the priority queue" << endl;
    print_vector(user_input); // printing the user input
    cout <<endl;

    for (int i = 0; i < user_input.size(); i++) // iterating through user input
    {
        for (int j = 0; j < i + 1; j++) // iterating through priority queue
        {
            if ( priority.size() == 0) // if the priority queue is empty then push the element
            {

                 priority.push_back(user_input[i]);
                break;
            }
            else if (user_input[i] >  priority[j]) // if the element is less than the element in the priority queue then psuh the element , by turning > into < we get a priority queue of increasing order
            {
                 priority.insert( priority.begin() + j, user_input[i]);
                break;
            }
            else if (j ==  priority.size()) // if the element is greater than all the elements in the priority queue then push it at the end
            {

                 priority.push_back(user_input[i]);
                break;
            }
        }
    }
    cout << "After adding user input into the priority queue" << endl;
    print_vector( priority); // printing the priority queue

    /**========================================================================
     * !                     Priority Queue using STL           *
     *========================================================================**/
    /*
        priority_queue<int> user_input;
        user_input.push(10);
        user_input.push(30);
        user_input.push(5);
        user_input.push(1000);
        user_input.push(9);
        user_input.push(20);
        cout << "Printing  priority queue" << endl;
        while (!user_input.empty())
        {
            cout << user_input.top() << " ";
            user_input.pop();
        }
    */
    return 0;
}