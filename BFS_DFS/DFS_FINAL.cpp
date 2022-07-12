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

void print_dfs()

{
    if (count(order.begin(), order.end(), s.back()) == 0)
    {
        cout << s.back() << ">>";

        cout << "\nPrinting in function " << s.back();
        order.push_back(s.back());
        cout << "\nPushed in in order " << s.back();
        s.erase(s.end());
        cout << "Printing in function after erasing" << s.back();
    }
    else
    {
        s.erase(s.end());
    }
}

void DFS(int source)
{
    cout << source << ">>";
    order.push_back(source);
    s.push_back(source);
    // cout << s.back() << endl;
    while (!s.empty())
    {
        // cout << "\nEntered in while ";
        // cout << graph[s.back()].size() << endl;
        if (graph[s.back()].size() == 0)
        {
            print_dfs();
        }
        else if (graph[s.back()].size() > 0)
        {
            int size = graph[s.back()].size();
            // cout << "Size " << size << endl;
            int back_number = s.back();
            // cout << back_number << endl;
            for (int i = 0; i < size; i++)
            {
                s.push_back(graph[back_number][i]);
                // cout << " pushing " << graph[back_number][i] << endl;
            }

            print_dfs();
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

    // cout << graph[s.end()][0] << endl;
    // cout << graph[s.end()][1] << endl;
    // cout << graph[s.end()][2] << endl;

    DFS(root);

    graph_print(8);
}