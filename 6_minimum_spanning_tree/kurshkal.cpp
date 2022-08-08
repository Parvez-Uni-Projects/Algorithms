#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> des_src;
typedef pair<int, des_src> weight_pack;
vector<weight_pack> edge_set;
vector<weight_pack> tree_set;
priority_queue<weight_pack> edge_queue;
set<weight_pack> edge_s;

int main()
{
    int nodes = 0;
    int edges = 0;

    // cout << "Enter the number of nodes " << endl;
    cin >> nodes;

    // cout << "Enter the number of edges " << endl;
    cin >> edges;

    int src, des, weight;
    for (int i = 0; i < edges; i++)
    {
        cin >> weight >> des >> src;
        edge_set.push_back(make_pair(weight, make_pair(des, src)));
        edge_s.insert(edge_set[i]);
    }
    // cout << "The weights are " << endl;
    for (int i = 0; i < edge_set.size(); i++)
    {

        cout << edge_set[i].first << " " << edge_set[i].second.first << " " << edge_set[i].second.second << endl;
    }

    vector<bool> visited(nodes, false);

    for (int i = 0; i < visited.size(); i++)
    {
        cout << visited[i] << " ";
    }

    cout << endl;

    sort(edge_set.begin(), edge_set.end());

    cout << "The sorted orders are " << endl;
    for (int i = 0; i < edge_set.size(); i++)
    {
        // weight destination source
        cout << edge_set[i].first << " " << edge_set[i].second.first << " " << edge_set[i].second.second << endl;

        if (visited[edge_set[i].second.first - 1] != 1)
        {
            visited[edge_set[i].second.first - 1] = 1;
            tree_set.push_back(edge_set[i]);
        }
    }

    cout << "The tree edges  are " << endl;
    for (int i = 0; i < tree_set.size(); i++)
    {
        // weight destination source
        cout << tree_set[i].first << " " << tree_set[i].second.first << " " << tree_set[i].second.second << endl;
    }
    cout << endl;
    for (int i = 0; i < visited.size(); i++)
    {
        cout << visited[i] << " ";
    }
}

/*

7
11
2 2 1
8 7 1
14 6 1
21 7 6
25 2 6
19 2 3
13 5 6
17 3 6
5 3 5
1 4 5
9 4 3

*/