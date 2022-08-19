
#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<vector<int>> vv{{13, 15, 18, 19}, {22}, {9}, {15}};
    cout << "Initial state = " << endl;
    for (int i = 0; i < vv.size(); i++)
    {
        for (int j = 0; j < vv.size(); j++)
        {
            if (i >= 1 && j >= 1)
                vv[i].push_back(min(vv[i - 1][j], min(vv[i][j - 1], vv[i - 1][j - 1])));
            cout << fixed << setw(6) << vv[i][j] << " ";
        }
        cout << endl;
    }
}