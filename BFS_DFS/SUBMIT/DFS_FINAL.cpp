#include <bits/stdc++.h>
using namespace std;
#define MAX 50
vector<int> graph[MAX];
vector<int> status;
stack<int> s;
#define for0(size) for (int i = 0; i < size; i++)
#define for1(size) for (int i = 1; i <= size; i++)

void graph_input(int edges)
{
    int source, destination;
    for1(edges)
    {
        cin >> source >> destination;
        graph[source].push_back(destination);
    }
}

void example_graph_input()
{

    graph[1].push_back(5);
    graph[1].push_back(6);
    graph[1].push_back(7);
    graph[6].push_back(8);
    graph[8].push_back(2);
    graph[5].push_back(6);
    graph[5].push_back(9);
    graph[7].push_back(10);
}
void graph_print(int nodes)
{
    for1(nodes)
    {
        cout << "Node " << i << " is connected to : ";
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}
void add_neighbors(int nodes)
{
    for0(graph[nodes].size())
    {

        if (status[graph[nodes][i]] == 1)
        {
            s.push(graph[nodes][i]);

            status[graph[nodes][i]] = 2;
        }
    }
}

void DFS(int source)
{

    s.push(source);
    status[source] = 2;
    while (s.empty() != true)
    {

        int nodes;
        nodes = s.top();
        s.pop();
        cout << nodes << ">";
        status[nodes] = 3;
        add_neighbors(nodes);
    }
}

int main()
{
    int nodes, edges, root = 1;
    // cout << "Enter the number of nodes" << endl;
    // cin >> nodes;
    // cout << "\nEnter the number of edges" << endl;
    // cin >> edges;
    // cout << "\nEnter the root node" << endl;
    // cin >> root;

    

    status.assign(nodes + 1, 1);

    //graph_input(edges);

    example_graph_input();
    //graph_print(nodes);

    DFS(root);
    return 0;
}