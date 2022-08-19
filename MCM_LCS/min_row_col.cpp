#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<vector<int>> vv{{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}, {21, 22, 23, 24, 25}};
    vector<int> sum_v;
    for (int i = 0; i < vv.size(); i++)
    {
        int temp_min = 10e6;
        temp_min = min(temp_min, *min_element(vv[i].begin(), vv[i].end()));
        for (int j = 0; j < vv[i].size(); j++)
            temp_min = min(temp_min, vv[j][i]);
        sum_v.push_back(temp_min);
        cout << sum_v[i] << " ";
    }
    cout << endl;
    cout << accumulate(sum_v.begin(), sum_v.end(), 0) << endl;
}