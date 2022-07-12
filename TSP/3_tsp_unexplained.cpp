
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
queue<int> min_costs_queue[2];
int user_infinity = 101;
int base_cost = 0;
int temp_cost = 0;
int total_nodes = 5;

typedef vector<vector<int>> myVector1;
typedef pair<int, myVector1> visited_vector;
typedef pair<int, visited_vector> predecessor;
typedef pair<int, predecessor> base_costs;
priority_queue<base_costs> pq;

void selling_route(int);

void sample_graph()
{
    vector<int> g;
    vector<int> empty;
    g.push_back(101);
    g.push_back(20);
    g.push_back(30);
    g.push_back(10);
    g.push_back(11);

    graph.push_back(g);
    g = empty;

    g.push_back(15);
    g.push_back(101);
    g.push_back(16);
    g.push_back(4);
    g.push_back(2);

    graph.push_back(g);
    g = empty;

    g.push_back(3);
    g.push_back(5);
    g.push_back(101);
    g.push_back(2);
    g.push_back(4);

    graph.push_back(g);
    g = empty;

    g.push_back(19);
    g.push_back(6);
    g.push_back(18);
    g.push_back(101);
    g.push_back(3);

    graph.push_back(g);
    g = empty;

    g.push_back(16);
    g.push_back(4);
    g.push_back(7);
    g.push_back(16);
    g.push_back(101);

    graph.push_back(g);
    g = empty;
}

void showq(queue<int> gq)
{
    queue<int> g = gq;
    while (!g.empty())
    {
        cout << '\t' << g.front();
        g.pop();
    }
    cout << '\n';
}

void show_vector(vector<vector<int>> myVector)
{
    for (int i = 0; i < myVector.size(); i++)
    {
        for (int j = 0; j < myVector[i].size(); j++)
        {
            cout << setw(6) << myVector[i][j] << " ";
        }
        cout << endl;
    }
}

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

void almighty_push(int, int, vector<vector<int>>);

vector<vector<int>> reduce_matrix(vector<vector<int>> myVector)
{

    for (int i = 0; i < myVector.size(); i++)

    {
        int minimum_cost = *min_element(myVector[i].begin(), myVector[i].end());

        if (minimum_cost == 101)
            min_costs_queue[0].push(0);
        else
            min_costs_queue[0].push(minimum_cost);
    }

    for (int i = 0; i < total_nodes; i++)
    {
        for (int j = 0; j < total_nodes; j++)
        {
            if (myVector[i][j] != user_infinity)
                myVector[i][j] -= min_costs_queue[0].front();
        }
        temp_cost += min_costs_queue[0].front();
        min_costs_queue[0].pop();
    }

    int minimum_cost = user_infinity;

    for (int j = 0; j < total_nodes; j++)
    {
        for (int i = 0; i < total_nodes; i++)
        {

            if (myVector[i][j] < minimum_cost)
            {
                minimum_cost = myVector[i][j];
            }
        }
        if (minimum_cost == 101)
            min_costs_queue[1].push(0);
        else
            min_costs_queue[1].push(minimum_cost);
        minimum_cost = user_infinity;
    }

    for (int j = 0; j < total_nodes; j++)
    {
        for (int i = 0; i < total_nodes; i++)
        {
            if (myVector[i][j] != user_infinity)
                myVector[i][j] -= min_costs_queue[1].front();
        }

        temp_cost += min_costs_queue[1].front();
        min_costs_queue[1].pop();
    }
    queue<int> empty;
    min_costs_queue[0] = empty;
    min_costs_queue[1] = empty;

    if (base_cost == 0)
    {
        base_cost = temp_cost;
        temp_cost = 0;
    }

    return myVector;
}

int debug_flag = 0;

int root = 0;
int main()
{
    int source_node = 1;
    root = source_node;
    sample_graph();
    graph = reduce_matrix(graph);
    show_vector(graph);
    cout << "The base cost is   " << base_cost << endl;
    cout << "The source node is " << source_node << endl;

    selling_route(source_node);

    cout << "\n\nThis Path's cost is " << base_cost;

    /*for (int i = 1; i <= total_nodes; i++)
    {
        root= i;
        selling_route(i);
    }*/
}

void almighty_push(int current_node, int source_node, vector<vector<int>> myVector1)
{
    vector<vector<int>> myVector;
    for (int i = 0; i < total_nodes; i++)
        myVector.push_back(myVector1[i]);

    int source_to_curr_cost = myVector[source_node - 1][current_node - 1]; 
    myVector[current_node - 1][root - 1] = user_infinity;                  
    myVector = set_row_column_to_infinity(myVector, source_node - 1, current_node - 1);
    myVector = reduce_matrix(myVector);
    int total_coming_cost = base_cost + source_to_curr_cost + temp_cost;
    temp_cost = 0;
    pq.push(make_pair(total_coming_cost * -1, make_pair(source_node, make_pair(current_node, myVector))));
}

void selling_route(int source_node)
{

    cout << "\n\n***** THE PATH IS DOWN BELOW *****" << endl;

    for (int i = 0; i < total_nodes; i++)
    {
        if (i + 1 != source_node)
        {
            almighty_push(i + 1, source_node, graph);
        }
    }

    int end_node;
    while (!pq.empty())
    {

        int current_source_node = pq.top().second.second.first;
        int current_source_nodes_predecessor = pq.top().second.first;
        int current_base_cost = pq.top().first * -1;
        base_cost = current_base_cost;

        end_node = current_source_node;

        cout << "Source is " << current_source_nodes_predecessor << endl;

        vector<vector<int>> myVector;

        for (int i = 0; i < total_nodes; i++)
        {
            myVector.push_back(pq.top().second.second.second[i]);
        }
        pq = priority_queue<base_costs>();

        for (int i = 0; i < total_nodes; i++)
        {
            if (myVector[i][root - 1] != user_infinity)
            {
                almighty_push(i + 1, current_source_node, myVector);
            }
        }
    }

    cout << "End node is " << end_node << endl;

}