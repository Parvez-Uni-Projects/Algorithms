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
    string x;
    string y;

    cin >> x >> y;

    cout << x << " " << y << endl;

    vector<vector<int>> vv(x.size() + 1, vector<int>(y.size() + 1, 0));
    vector<vector<int>> bb = vv;

    cout << "The matrix are initialized as " << endl;
    cout << "The size matrix  " << endl;
    print_matrix(vv);
    cout << "The movement matrix " << endl;
    print_matrix(bb);

    for (int i = 1; i < vv.size(); i++)
    {
        for (int j = 1; j < vv[i].size(); j++)
        {
            if (y[j - 1] == x[i - 1])
            {
                vv[i][j] += vv[i - 1][j - 1] + 1;
                bb[i][j] = 1; // going to diagonal
            }
            else if (vv[i - 1][j] >= vv[i][j - 1])
            {
                vv[i][j] = vv[i - 1][j];
                bb[i][j] = 2; // goint to up
            }
            else
            {
                vv[i][j] = vv[i][j - 1];
                bb[i][j] = 3; // going to side
            }
        }
    }
    cout << "The matrix are transformed to  " << endl;
    cout << "The size matrix " << endl;
    print_matrix(vv);
    cout << "The movement matrix  " << endl;
    print_matrix(bb);

    string result = "";

    int row = x.size(), col = y.size();

    while (bb[row][col] != 0)
    {
        if (bb[row][col] == 1)
        {
            result += y[col - 1];
            row -= 1;
            col -= 1;
        }
        else if (bb[row][col] == 2)
            row -= 1;
        else if (bb[row][col] == 3)
            col -= 1;
        else
            break;
    }
    reverse(result.begin(), result.end());
    cout << "\n\nLongest common subsequence is \n"
         << result << "\nLength is\n"
         << result.size() << endl;

    cout << "Number of Longest common subsequences " << endl;

    vector<pair<int, int>> positions;

    for (int i = 0; i < vv.size(); i++)
    {
        for (int j = 0; j < vv[i].size(); j++)
        {

            if (vv[i][j] == result.size() && bb[i][j] == 1)
            {
                cout << vv[i][j] << " " << i << " " << j << endl;
                positions.push_back(make_pair(i, j));
            }
        }
    }
}