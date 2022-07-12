
#include <bits/stdc++.h>
using namespace std;

queue<int> min_costs_queue[2];
vector<int> graph[6];

vector<vector<int>> set_row_column_to_infinity(vector<vector<int>> myVector, int row, int column)
{

    for (int i = 0; i < myVector.size(); i++)
    {
        for (int j = 0; j < myVector[i].size(); j++)
        {
            if (i == row)
            {
                myVector[i][j] = 101;
            }
            else if (j == column)
            {
                myVector[i][j] = 101;
            }
        }
    }

    return myVector;
}

void sample_graph()
{

    graph[1].push_back(101);
    graph[1].push_back(20);
    graph[1].push_back(30);
    graph[1].push_back(10);
    graph[1].push_back(11);

    graph[2].push_back(15);
    graph[2].push_back(101);
    graph[2].push_back(16);
    graph[2].push_back(4);
    graph[2].push_back(2);

    graph[3].push_back(3);
    graph[3].push_back(5);
    graph[3].push_back(101);
    graph[3].push_back(2);
    graph[3].push_back(4);

    graph[4].push_back(19);
    graph[4].push_back(6);
    graph[4].push_back(18);
    graph[4].push_back(101);
    graph[4].push_back(3);

    graph[5].push_back(16);
    graph[5].push_back(4);
    graph[5].push_back(7);
    graph[5].push_back(16);
    graph[5].push_back(101);
}
int main()
{
    sample_graph();
    vector<vector<int>> myVector;
    myVector.push_back(graph[1]);
    myVector.push_back(graph[2]);
    myVector.push_back(graph[3]);
    myVector.push_back(graph[4]);
    myVector.push_back(graph[5]);

    myVector = set_row_column_to_infinity(myVector, 2, 3);

    for (int i = 0; i < myVector.size(); i++)
    {

        for (int j = 0; j < myVector[i].size(); j++)
        {

            cout << setw(6) << myVector[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "hello world";
}
