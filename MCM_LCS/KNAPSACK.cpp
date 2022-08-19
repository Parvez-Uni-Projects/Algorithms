#include <bits/stdc++.h>

using namespace std;

void print_matrix(vector<vector<int>> vv)
{

    for (int i = 0; i < vv.size(); i++)
    {
        for (int j = 0; j < vv[i].size(); j++)
            cout << vv[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int n;
    int w;
    cin >> n >> w;

    vector<pair<int, int>> vp;
    int temp1, temp2;
    vp.push_back(make_pair(0, 0));
    for (int i = 0; i < n; i++)
    {
        cin >> temp1 >> temp2;
        vp.push_back(make_pair(temp1, temp2));
    }

    vector<vector<int>> vv(n + 1, vector<int>(w + 1, 0));

    cout << "The matrix are initialized as " << endl;
    cout << "The initialized matrix  " << endl;
    print_matrix(vv);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (j < vp[i].first)
            {
                vv[i][j] = vv[i - 1][j];
            }
            else if (j == vp[i].first)
            {
                vv[i][j] = max(vp[i].second, vv[i - 1][j]);
            }
            else
            {
                vv[i][j] = max(vp[i].second + vv[i - 1][j - vp[i].first], vv[i - 1][j]);
            }
        }
    }

    vector<int> knapsack(n + 1, 0);
    int bag_capacity = w;

    int row = n;
    int col = w;

    cout << "The profit matrix is " << endl;
    print_matrix(vv);

    while (bag_capacity != 0 && row != 0 && col != 0)
    {
        if (vv[row][col] != vv[row - 1][col])
        {
            knapsack[row] = 1;
            col -= vp[row].first;
            row -= 1;
        }
        else
            row -= 1;
    }

    cout << "The knapsack bag is " << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << knapsack[i] << " ";
    }
    cout << "The items are  " << endl;
    for (int i = 1; i <= n; i++)
    {
        if (knapsack[i] == 1)
        {
            cout << "Item no ="<< i << " Weight = " << vp[i].first << " profit = " << vp[i].second << endl;
        }
    }
}