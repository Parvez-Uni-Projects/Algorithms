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

    // graph[1].push_back(2);
    // graph[1].push_back(3);
    // graph[1].push_back(4);
    // graph[1].push_back(5);
    // graph[3].push_back(2);
    // graph[4].push_back(3);

    graph[1].push_back(5);
    graph[1].push_back(6);
    graph[1].push_back(7);
    graph[6].push_back(8);
    graph[8].push_back(2);
    graph[5].push_back(6);
    graph[5].push_back(9);
    graph[7].push_back(10);
    
}

// void dfs(int source)
// {
//     cout << source << " ";

//     if (graph[source].size() != 0)
//     {
//         int front = graph[source][0];
//         graph[source].erase(graph[source].begin());
//         dfs(front);
//     }
//     else if (graph[source].size() == 0)
//     {
//     }
// }

void print_dfs()

{
    if (count(order.begin(), order.end(), s.front()) == 0)
    {
        cout << s.front() << " ";
        order.push_back(s.front());
        s.erase(s.begin());
    }
    else
    {
        s.erase(s.begin());
    }
}

void dfs(int nodes, int source)
{
    cout << source << " ";
    order.push_back(source);
    for (int j = 0; j < graph[source].size(); j++)
    {
        s.push_back(graph[source][j]);
    }

    while (!s.empty())
    {
        if (graph[s.front()].size() == 0)
        {
            print_dfs();
        }
        else if (graph[s.front()].size() > 0)
        {

            for (int j = 0; j < graph[s.front()].size(); j++)
            {
                s.push_back(graph[s.front()][j]);
            }
            print_dfs();
        }
    }
}

// void dfs(int nodes, int source)
// {
//     cout << source << " ";
//     order.push_back(source);
//     for (int j = 0; j < graph[source].size(); j++)
//     {
//         s.push_back(graph[source][j]);
//     }

//     while (!s.empty())
//     {
//         if (graph[s.front()].size() == 0)
//         {
//             print_dfs();
//         }
//         else if (graph[s.front()].size() > 0)
//         {

//             for (int j = 0; j < graph[s.front()].size(); j++)
//             {
//                 s.push_back(graph[s.front()][j]);
//             }
//             print_dfs();
//         }
//     }
// }

void find_root_with_max_edge(int nodes)
{
    int number_of_node = 0;
    int number_of_edges = 0;

    for1(nodes)
    {
        if (graph[i].size() >= number_of_edges)
        {

            number_of_node = i;
            number_of_edges = graph[i].size();
        }
    }
    cout << "Node number " << number_of_node << " has maximum edge " << number_of_edges << endl;
}
leaf_nodes(int nodes)
{
    cout << "Leaf Nodes are " << endl;
    for1(nodes)
    {
        if (graph[i].size() == 0)
        {
            cout << i << " ";
        }
    }
}
int main()
{
    int nodes, edges, root;

    // cout << "Enter the number of nodes" << endl;
    // cin >> nodes;
    // cout << "\nEnter the number of edges" << endl;
    // cin >> edges;
    // cout << "\nEnter the root node" << endl;
    // cin >> root;

    // cout << nodes << edges << root;

    // graph_input(nodes, edges);
    example_graph_input();
    nodes = 5;
    // graph_print(nodes);
    // leaf_nodes(nodes);
    dfs(nodes, 5);

    // dfs(1);
    //  find_root_with_max_edge(nodes);
    //  cout << graph[1][0];
    //  graph[1].erase(graph[1].begin());
    //  // cout << graph[1].at(0);
    //  find_root_with_max_edge(nodes);

    // cout << graph[1][0];
    //  cout << "Hello world";
}