#include <bits/stdc++.h>
using namespace std;

typedef pair<int, bool> dv;
typedef pair<int, dv> wdv;
vector<wdv> graph[7];

vector<int> path;
vector<wdv> path_details;

queue<wdv> pq;

int total_node = 6;

void sample_graph()
{
    graph[1].push_back(make_pair(2, make_pair(2, false)));
    graph[1].push_back(make_pair(3, make_pair(4, false)));

    graph[2].push_back(make_pair(5, make_pair(3, false)));
    graph[2].push_back(make_pair(1, make_pair(4, false)));

    graph[3].push_back(make_pair(2, make_pair(6, false)));

    graph[4].push_back(make_pair(1, make_pair(5, false)));

    graph[5].push_back(make_pair(1, make_pair(3, false)));
    graph[5].push_back(make_pair(10, make_pair(6, false)));
}

void print_graph()
{

    for (int i = 1; i <= 5; i++)
    {
        cout << "Node " << i << " Is connected to " << endl;

        for (int j = 0; j < graph[i].size(); j++)
        {

            cout << graph[i][j].second.first << "\tHaving weight " << graph[i][j].first << " Visit status " << graph[i][j].second.second << endl;
        }
        cout << endl;
    }
}

int find_min_weight_node(int node)
{
    int min = 1000;
    int min_index = 1000;
    for (int j = 0; j < graph[node].size(); j++)
    {
        if (min > graph[node][j].first)
        {
            min = graph[node][j].first;
            min_index = j;
        }
    }

    return min_index;
}
int weight_total = 0;
void dijkstra(int root)
{

    int source = root;

    cout << "Source is " << source << endl;

    int min_index = find_min_weight_node(source);

    // cout << min_index;

    pq.push(make_pair(graph[source][min_index].first, make_pair(graph[source][min_index].second.first, graph[source][min_index].second.second)));
    weight_total += graph[source][min_index].first;
    path_details.push_back(make_pair(graph[source][min_index].first, make_pair(graph[source][min_index].second.first, graph[source][min_index].second.second)));
    int visited = 1;
    // path_details.push_back(make_pair(2, make_pair(1, 0)));

    // cout << pq.top().second.first << endl;
    int i = 1;

    while (!pq.empty())

    {
        int node = pq.front().second.first;
        visited++;
        path.push_back(node);
        cout << node << endl;

        if (graph[node].size() == 0)
            break;

        int min_index = find_min_weight_node(node);

        int destination = graph[node][min_index].second.first;
        int weight = graph[node][min_index].first;
        int visited = graph[node][min_index].second.second;

        // cout << weight << destination << visited << endl;
        weight_total += weight;

        pq.pop();

        pq.push(make_pair(weight, make_pair(destination, visited)));
        path_details.push_back(make_pair(weight, make_pair(destination, visited)));
    }
}

int main()
{
    sample_graph();

    // print_graph();
    int root = 2;

    dijkstra(root);

    cout << "\nThe shortest path to any node from source " << root <<" is " << endl;

    // cout << 1 << "->";

    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i] << "->";
    }

    cout << "\n\nThe path details are down below" << endl;

    for (int i = 0; i < path_details.size(); i++)
    {
        // cout << "From node " << path_details[i].second.first << " to " << path_details[i + 1].second.first << " Weight is " << path_details[i].first << endl;
        cout << path_details[i].first << path_details[i].second.first << path_details[i].second.second << endl;
    }

    cout << weight_total;
}