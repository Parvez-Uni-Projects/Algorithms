#include <bits/stdc++.h>
using namespace std;
#define MAX 50
vector<int> graph[MAX];
vector<int> s;
vector<int> order;
#define for0(size) for (int i = 0; i < size; i++)
#define for1(size) for (int i = 1; i <= size; i++)

void graph_input(int node, int edges)
{
    int source, destination;
    cout << "Enter source and destination in pair : " << endl;
    for1(edges)
    {
        cin >> source >> destination;
        graph[source].push_back(destination);
    }
}

void graph_print(int nodes)
{
    for1(nodes)
    {
        cout << "Node " << i << " is connected to " << endl;
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
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

void print_bfs()

{
    if (count(order.begin(), order.end(), s.front()) == 0)
    {
        cout << s.front() << ">>";
        order.push_back(s.front());
        s.erase(s.begin());
    }
    else
    {
        s.erase(s.begin());
    }
}

void BFS(int source)
{
    cout << source << ">>";
    order.push_back(source);
    s.push_back(source);
    // s.insert(s.begin(), source);
    while (!s.empty())
    {
        if (graph[s.front()].size() == 0)
        {
            print_bfs();
        }
        else if (graph[s.front()].size() > 0)
        {
            for (int i = 0; i < graph[s.front()].size(); i++)
            {
                // s.push_back(graph[s.front()][i]);

                int target = graph[s.front()][i];
                //cout << "Pushing" << target << endl;
               // s.insert(s.begin(), target);
                s.push_back(graph[s.front()][i]);
            }

            print_bfs();
        }
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

    // graph_input(nodes, edges);
    example_graph_input();

    BFS(root);
}