#include <bits/stdc++.h>

using namespace std;

void print_matrix(vector<vector<int>> vv)
{

    for (int i = 0; i < vv.size(); i++)
    {
        for (int j = 0; j < vv[i].size(); j++)
            cout << fixed << setw(6) << vv[i][j] << " ";
        cout << endl;
    }
}

vector<vector<int>> multiply_matrix(vector<vector<int>> A, vector<vector<int>> B)
{

    int p = A.size();
    int q = A[0].size();
    int r = B[0].size();

    vector<vector<int>> C(p, vector<int>(r, 0));

    for (int i = 0; i < p; i++)
        for (int j = 0; j < r; j++)
            for (int k = 0; k < q; k++)
                C[i][j] += A[i][k] * B[k][j];

    return C;
}

int main()
{

    // vector<vector<int>> A{{1, 2}, {4, 5}, {7, 8}};
    // vector<vector<int>> B{{11, 12, 13}, {14, 15, 16}};

    vector<vector<int>> A{{3, 4, 2}};
    vector<vector<int>> B{{13, 9, 7, 15}, {8, 7, 4, 6}, {6, 4, 0, 3}};

    vector<vector<int>> C = multiply_matrix(A, B);

    print_matrix(C);

    return 0;
}