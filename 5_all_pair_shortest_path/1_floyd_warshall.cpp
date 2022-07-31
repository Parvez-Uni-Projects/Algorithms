#include <bits/stdc++.h>
using namespace std;

typedef vector<int> ROW;
vector<ROW> adj;
int total_nodes ;
int USER_INFINITY = 101;

void initialize_adj()
{
    for (int i = 0; i < total_nodes; i++)
    {
        ROW temp(total_nodes, USER_INFINITY);
        adj.push_back(temp);
    }
}

void show_graph(vector<vector<int>> ADJ_M)
{

    for (int i = 0; i < ADJ_M.size(); i++)
    {
        for (int j = 0; j < ADJ_M[i].size(); j++)
        {
            cout << setw(5) << ADJ_M[i][j] << " ";
        }
        cout << endl;
    }
}
void take_input()
{
    cout << "Total number of nodes " << endl;
    cin >> total_nodes;
    initialize_adj();

    cout << adj.size() << endl;
    show_graph(adj);
    int total_edges;
    cout << "Total number of edges" << endl;
    cin >> total_edges;
    int temp_source;
    int temp_destination;
    int temp_weight;

    for (int i = 0; i < total_edges; i++)
    {
        cout << "Edge number " << i + 1 << endl;
        cout << "Source :" << endl;
        cin >> temp_source;
        cout << "Destination :" << endl;
        cin >> temp_destination;

        cout << "Destination :" << endl;
        cin >> temp_weight;

        if (temp_source != temp_destination)
            adj[temp_source - 1][temp_destination - 1] = temp_weight;

        cout << endl;
    }

    show_graph(adj);
}

int main()
{

    take_input();
}

/*
5
9
1 2 3
1 5 -4
1 3 8
2 5 7
2 4 1
3 2 4
4 1 2
4 3 -5
5 4 6

*/