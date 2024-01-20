#include <bits/stdc++.h>
using namespace std;


// This below vector is used to store the result of the solution board
vector<pair<vector<int>, vector<vector<int>>>> store_result;
// int count_rep = 1;
int total_solution = 0;

// This function is used to print the matrix of the solution board
void print_matrix(vector<vector<int>> vv)
{
    for (int i = 1; i < vv.size(); i++) {
        for (int j = 1; j < vv[i].size(); j++) {
            cout << (vv[i][j] ? "Q " : ". ");
            // cout << fixed << setw(6) << vv[i][j] << " ";
        }

        cout << endl;
    }
}


// This function is used to print the position of the queen in the solution board
// Also it store the result of the solution board in the vector of pair
void print_position(vector<int> v)
{

    cout << "\nThe solution board is" << endl;
    vector<vector<int>> vv(v.size(), vector<int>(v.size(), 0));

    for (int i = 1; i < v.size(); i++)
        vv[i][v[i]] = 1;

    store_result.push_back(make_pair(v, vv));

    // Printing the position of the queen in the solution board
    print_matrix(vv);
}


// Printing the vector 
void print_vector(vector<int> v)
{
    cout << endl;
    for (int i = 1; i < v.size(); i++) {

        cout << v[i] << " ";
    }

    //print_position(v);
}


// This function is used to check the position of the queen in the solution board if it is safe or not
bool Place(int k, int i, vector<int> x)
{
    for (int j = 1; j <= k - 1; j++) {
        if (x[j] == i || abs(x[j] - i) == abs(j - k))
            return false;
    }
    return true;
}


// This is the main function which is used to find the solution of the n-queen problem
// It is a recursive function and backtracking is used in this function
// It is used to find the position of the queen in the solution board
// It is used to find the solution board
// It is used to find the total number of solution

// the parameter k is used to check the position of the queen in the solution board
// the parameter n is used to check the number of queens
// the parameter x is used to store the position of the queen in the solution board
void NQueens(int k, int n, vector<int> x)
{
    // count_rep++;
    for (int i = 1; i <= n; i++) {
        if (Place(k, i, x)) {
            x[k] = i;
            if (k == n)
                print_vector(x);
            else
                NQueens(k + 1, n, x);
        }
    }
}

int main()
{

    // taking input of the number of queens
    int n = 0;
    cout << "\n\n\n\nEnter the number of queens " << endl;
    cin >> n;

    // vector to store the position of the queen in the solution board
    vector<int> result(n + 1, 0);


    // if the number of queens is 0 then there is no solution
    if (n == 0)
        cout << "No solution avaible " << endl;
    else
        NQueens(1, n, result);

    cout << "\nTotal number of solution is " << endl;
    cout << store_result.size() << endl;
    // cout << "Total number recursive call is " << endl;
    // cout << count_rep << endl;


    //cerr << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}
