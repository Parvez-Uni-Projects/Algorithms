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
    // cout << "Total number of nodes " << endl;
    cin >> total_nodes;
    adj = initialize_adj(adj);

    int total_edges;
    // cout << "Total number of edges" << endl;
    cin >> total_edges;
    int temp_source;
    int temp_destination;
    int temp_weight;

    for (int i = 0; i < total_edges; i++)
    {
        // cout << "Edge number " << i + 1 << endl;
        // cout << "Source :" << endl;
        cin >> temp_source;
        // cout << "Destination :" << endl;
        cin >> temp_destination;

        // cout << "Destination :" << endl;
        cin >> temp_weight;

        if (temp_source != temp_destination)
        {
            adj[temp_source - 1][temp_destination - 1].first = temp_weight;
            adj[temp_source - 1][temp_destination - 1].second = temp_source;
        }

        // cout << endl;
    }
}

void show_shortest_path(vector<ROW> ADJ_M, int source, int destination)
{
    // cout << "its all mikeyes fault " << endl;
    cout << "Cost = " << ADJ_M[source][destination].first << endl;

    stack<int> s;
    s.push(destination + 1);

    for (int i = 0; i < ADJ_M.size() - 1; i++)
    {
        if (ADJ_M[source][destination].second == source + 1)
        {
            s.push(ADJ_M[source][destination].second);
            break;
        }
        else
        {
            s.push(ADJ_M[source][destination].second);
            destination = ADJ_M[source][destination].second - 1;
        }
    }
    cout << "Path is  ";
    while (!s.empty())
    {
        cout << s.top() << "->";
        s.pop();
    }
    cout << endl;
    
}

void show_lowest_cost_destination(vector<ROW> ADJ_M, int source)
{
    cout << "Lowest costly path destination is " << endl;

    int temp_min = USER_INFINITY;
    int min_node = 0;

    for (int i = 0; i < ADJ_M[source].size(); i++)
    {
        if (i != source)
        {
            if (temp_min > ADJ_M[source][i].first)
            {
                temp_min = ADJ_M[source][i].first;
                min_node = i;
            }
        }
    }
    cout << min_node + 1 << endl;
    cout << endl;
}



void findPath(vector<ROW> ADJ_M, int rank)
{
    int temp_cost;
    int total_hit = 0;
    for (int i = 0; i < rank; i++)
    {
        for (int j = 0; j < ADJ_M.size(); j++)
        {
            if (i != j)
            {
                for (int k = 0; k < ADJ_M.size(); k++)
                {
                    if (j != k && k != i)
                    {
                        total_hit++;
                        temp_cost = min(ADJ_M[j][k].first, ADJ_M[j][i].first + ADJ_M[i][k].first);
                        if (temp_cost < ADJ_M[j][k].first)
                        {
                            ADJ_M[j][k].first = temp_cost;
                            ADJ_M[j][k].second = ADJ_M[i][k].second;
                        }
                    }
                    
                }
            }
        }
    }
    cout << "The final reduced matrix using " << rank << " nodes is " << endl;
     show_graph(ADJ_M);
    // for (int i = 0; i < ADJ_M.size(); i++)
    // {

    //     for (int j = 0; j < ADJ_M.size(); j++)
    //     {
    //         if (i != j)
    //         {
    //             cout << "Path from " << i + 1 << " to " << j + 1 << " is " << endl;
    //             show_shortest_path(ADJ_M, i, j);
    //         }
    //     }
    // }
    // cout << "Lowest cost destination " << ADJ_M.size() << endl;

    // for (int i = 0; i < ADJ_M.size(); i++)
    // {
    //     cout << "From " << i + 1 << endl;
    //     show_lowest_cost_destination(ADJ_M, i);
    // }  
}

int main()
{
    int rank;
    cin >> rank;
    take_input();
    //show_graph(adj);
    findPath(adj, rank);
}
