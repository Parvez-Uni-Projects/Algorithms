
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;     // The vector for storing user inputs
queue<int> min_costs_queue[2]; // [0] = going cost [1]= backing cost
int user_infinity = 101;       // This can also be determined while taking user input (max_weight + 2)
int base_cost = 0;             // total path cost will finally be stored in here
int temp_cost = 0;             // temporary cost for queue
int total_nodes = 5;           // total number of nodes

// Creating a data structure to store by sequence path_cost ,source node ,current node , reduced matrix
typedef vector<vector<int>> myVector1;
typedef pair<int, myVector1> visited_vector;
typedef pair<int, visited_vector> predecessor;
typedef pair<int, predecessor> base_costs;
priority_queue<base_costs> pq;

void selling_route(int);
// for better understanding taking pre defined complete graph
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
    g = empty; // clearing the vector g after pushing it into the graph

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

void show_queue(queue<int> gq) // showing a queue
{
    queue<int> g = gq;
    while (!g.empty())
    {
        cout << '\t' << g.front();
        g.pop();
    }
    cout << '\n';
}

void show_vector(vector<vector<int>> myVector) // showing a queue
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
// setting row to infinity for source and setting column to infinity for destination
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

// function that is returning a reduced cost matrix
vector<vector<int>> reduce_matrix(vector<vector<int>> myVector)
{
    // finding minimum value of each row and pushing them into the min_cost_queue
    for (int i = 0; i < myVector.size(); i++)

    {
        int minimum_cost = *min_element(myVector[i].begin(), myVector[i].end());

        if (minimum_cost == 101)
            min_costs_queue[0].push(0);
        else
            min_costs_queue[0].push(minimum_cost);
    }
    // deducting the minimum value of each row from every index of the row to get at least one zero in the row
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

    // finding minimum value of each colum and pushing them into the min_cost_queue
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
    // deducting the minimum value of each column from every index of the column to get at least one zero in the column

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

    if (base_cost == 0) // only works for source node
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
    root = source_node; // setting the root as source node for using in other functions

    sample_graph();               // creating the graph
    graph = reduce_matrix(graph); // finding the reduced matrix
    show_vector(graph);
    cout << "The base cost is   " << base_cost << endl;
    cout << "The source node is " << source_node << endl;

    selling_route(source_node); // solving the graph

    /*for (int i = 1; i <= total_nodes; i++) // here source is dynamic to find way from any source
    {
        root= i;
        selling_route(i);
    }*/
}

void almighty_push(int current_node, int source_node, vector<vector<int>> q_vector)
{
    int source_to_curr_cost = q_vector[source_node - 1][current_node - 1];
    q_vector[current_node - 1][root - 1] = user_infinity; // so that it can't get back until all nodes visited
    q_vector = set_row_column_to_infinity(q_vector, source_node - 1, current_node - 1);
    q_vector = reduce_matrix(q_vector);
    int total_cost = base_cost + source_to_curr_cost + temp_cost; // all over travelling cost
    temp_cost = 0;
    pq.push(make_pair(total_cost * -1, make_pair(source_node, make_pair(current_node, q_vector)))); // pushing the infos to queue
}

void selling_route(int source_node)
{

    cout << "\n\n***** THE PATH IS DOWN BELOW *****" << endl;

    // initially pushing all the nodes except the source to the queue
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
        // storing the datas from the queue
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
        pq = priority_queue<base_costs>(); // clearing the queue

        for (int i = 0; i < total_nodes; i++) // pushing all the unvisited nodes to the queue
        {
            if (myVector[i][root - 1] != user_infinity) // checking the root column if every node is visited or not
            {
                almighty_push(i + 1, current_source_node, myVector);
            }
        }
    }

    cout << "End node is " << end_node << endl;
    cout << "\n\nThis Path's cost is " << base_cost;
}