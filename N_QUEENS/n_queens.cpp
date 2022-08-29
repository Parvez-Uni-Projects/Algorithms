#include <bits/stdc++.h>

using namespace std;

vector<pair<vector<int>, vector<vector<int>>>> store_result;
//int count_rep = 1;
void print_matrix(vector<vector<int>> vv)
{
    for (int i = 1; i < vv.size(); i++)
    {
        for (int j = 1; j < vv[i].size(); j++)
            cout << fixed << setw(6) << vv[i][j] << " ";
        cout << endl;
    }
}

void print_position(vector<int> v)
{

    cout << "\nThe solution board is" << endl;
    vector<vector<int>> vv(v.size(), vector<int>(v.size(), 0));

    for (int i = 1; i < v.size(); i++)
        vv[i][v[i]] = 1;

    store_result.push_back(make_pair(v, vv));

    print_matrix(vv);
}

void print_vector(vector<int> v)
{
    cout << endl;
    for (int i = 1; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    print_position(v);
}

bool Place(int k, int i, vector<int> x)
{
    for (int j = 1; j <= k - 1; j++)
    {
        if (x[j] == i || abs(x[j] - i) == abs(j - k))
            return false;
    }
    return true;
}

void NQueens(int k, int n, vector<int> x)
{
    //count_rep++;
    for (int i = 1; i <= n; i++)
    {
        if (Place(k, i, x))
        {
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
    int n = 0;
    cout << "\n\n\n\nEnter the number of queens " << endl;
    cin >> n;

    vector<int> result(n + 1, 0);

    if (n == 0)
        cout << "No solution avaible " << endl;
    else
        NQueens(1, n, result);

    cout << "Total number of solution is " << endl;
    cout << store_result.size() << endl;
    // cout << "Total number recursive call is " << endl;
    // cout << count_rep << endl;


}
