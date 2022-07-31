#include <bits/stdc++.h>
using namespace std;

typedef vector<pair<int, int>> ROW;
vector<ROW> adj;
int total_nodes;
int USER_INFINITY = 99;

vector<ROW> initialize_adj(vector<ROW> ADJ_M)
{
    for (int i = 0; i < total_nodes; i++)
    {
        ROW temp(total_nodes, make_pair(USER_INFINITY, USER_INFINITY));
        ADJ_M.push_back(temp);
    }
    for (int i = 0; i < ADJ_M.size(); i++)
    {
        for (int j = 0; j < ADJ_M[i].size(); j++)
        {
            if (i == j)
                ADJ_M[i][j].first = 0;
        }
        cout << endl;
    }
    return ADJ_M;
}

void show_graph(vector<ROW> ADJ_M)
{

    for (int i = 0; i < ADJ_M.size(); i++)
    {
        for (int j = 0; j < ADJ_M[i].size(); j++)
        {
            cout << setw(7) << ADJ_M[i][j].first << "/" << ADJ_M[i][j].second << setw(7);
        }
        cout << endl;
    }
}
void take_input()
{
    //cout << "Total number of nodes " << endl;
    cin >> total_nodes;
    adj = initialize_adj(adj);

    
    int total_edges;
    //cout << "Total number of edges" << endl;
    cin >> total_edges;
    int temp_source;
    int temp_destination;
    int temp_weight;

    for (int i = 0; i < total_edges; i++)
    {
        //cout << "Edge number " << i + 1 << endl;
       // cout << "Source :" << endl;
        cin >> temp_source;
       // cout << "Destination :" << endl;
        cin >> temp_destination;

        //cout << "Destination :" << endl;
        cin >> temp_weight;

        if (temp_source != temp_destination)
        {
            adj[temp_source - 1][temp_destination - 1].first = temp_weight;
            adj[temp_source - 1][temp_destination - 1].second = temp_source;
        }

       // cout << endl;
    }

    
}

int main()
{

    take_input();
    show_graph(adj);
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