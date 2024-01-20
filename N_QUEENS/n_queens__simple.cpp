#include <bits/stdc++.h>
using namespace std;
int total_solution = 0;

void print_vector(vector<int> v)
{

    for (int i = 1; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

bool canPlace(int k, int i, vector<int> x)
{

    // k tomo column e i tomo row e queen ta rakha jabe kina check korchi
    for (int j = 1; j <= k - 1; j++) {
        if (x[j] == i || abs(x[j] - i) == abs(j - k))
            return false;
    }
    return true;
}



void NQueens(int k, int n, vector<int> x)
{
    for (int i = 1; i <= n; i++) {
        if (canPlace(k, i, x)) {
            x[k] = i;
            if (k == n) {
                print_vector(x);
            } else {
                NQueens(k + 1, n, x);
            }
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

    return 0;
}
