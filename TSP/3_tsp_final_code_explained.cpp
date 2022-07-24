#include <bits/stdc++.h>
using namespace std;

#define vv vector<vector<int>>
#define pb push_back
vv graph;                   // The vector for storing user inputs
queue<int> min_costs_queue; // for keeping track of coming and goind cost
int user_infinity = 101;    // Incase of user input (max_weight + 2)
int base_cost = 0;          // total path cost will finally be stored in here
int temp_cost = 0;          // temporary cost for queue
int total_nodes = 5;        // total number of nodes
int root = 0;               // root given by user

// Creating a data structure to store by sequence of
// path_cost ,source node ,current node , reduced matrix
typedef vv myVector1;
typedef pair<int, myVector1> visited_vector;
typedef pair<int, visited_vector> predecessor;
typedef pair<int, predecessor> base_costs;
priority_queue<base_costs> pq;
vector<priority_queue<base_costs>> route_details; // for storing the path details

// for better understanding taking pre defined complete graph
void sample_graph()
{
    vector<int> g;
    vector<int> empty;
    g.pb(101); // edges where source is 1
    g.pb(20);
    g.pb(30);
    g.pb(10);
    g.pb(11);

    graph.pb(g);
    g = empty; // clearing the vector g after pushing it into the graph

    g.pb(15); // edges where source is 2
    g.pb(101);
    g.pb(16);
    g.pb(4);
    g.pb(2);

    graph.pb(g);
    g = empty;

    g.pb(3); // edges where source is 3
    g.pb(5);
    g.pb(101);
    g.pb(2);
    g.pb(4);

    graph.pb(g);
    g = empty;

    g.pb(19); // edges where source is 4
    g.pb(6);
    g.pb(18);
    g.pb(101);
    g.pb(3);

    graph.pb(g);
    g = empty;

    g.pb(16); // edges where source is 5
    g.pb(4);
    g.pb(7);
    g.pb(16);
    g.pb(101);

    graph.pb(g);
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

void show_vector(vv myVector) // showing a queue
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
void show_route_details()
{
    cout << "\n\n****** Details of each path is down below ******\n"
         << endl;

    int start = 0;
    int stop = total_nodes - 1;
    for (int i = 1; i <= 5; i++)
    {

        cout << "From root " << i << endl;

        for (int j = start; j < stop; j++)
        {
            cout << "Going to " << route_details[j].top().second.second.first << " With cost ";
            cout << route_details[j].top().first * -1 << " " << endl;
        }
        cout << endl;
        start += total_nodes - 1;
        stop += total_nodes - 1;
    }
}
// setting row to infinity for source and setting column to infinity for destination
vv set_row_column_to_infinity(vv myVector, int row, int column)
{
    for (int i = 0; i < myVector.size(); i++)
    {
        for (int j = 0; j < myVector[i].size(); j++)
        {
            if (i == row || j == column)
            {
                myVector[i][j] = user_infinity;
            }
        }
    }

    return myVector;
}

// function that is returning a reduced cost matrix
vv reduce_matrix(vv myVector)
{
    // finding minimum value of each row and pushing them into the min_cost_queue
    for (int i = 0; i < myVector.size(); i++)

    {
        int minimum_cost = *min_element(myVector[i].begin(), myVector[i].end());

        if (minimum_cost == 101)
            min_costs_queue.push(0);
        else
            min_costs_queue.push(minimum_cost);
    }
    // deducting the minimum value of each row from every index of the row to get at least one zero in the row
    for (int i = 0; i < total_nodes; i++)
    {
        for (int j = 0; j < total_nodes; j++)
        {
            if (myVector[i][j] != user_infinity)
                myVector[i][j] -= min_costs_queue.front();
        }
        temp_cost += min_costs_queue.front();
        min_costs_queue.pop();
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
            min_costs_queue.push(0);
        else
            min_costs_queue.push(minimum_cost);
        minimum_cost = user_infinity;
    }
    // deducting the minimum value of each column from every index of the column to get at least one zero in the column

    for (int j = 0; j < total_nodes; j++)
    {
        for (int i = 0; i < total_nodes; i++)
        {
            if (myVector[i][j] != user_infinity)
                myVector[i][j] -= min_costs_queue.front();
        }

        temp_cost += min_costs_queue.front();
        min_costs_queue.pop();
    }

    if (base_cost == 0) // only works for source node
    {
        base_cost = temp_cost;
        temp_cost = 0;
    }

    return myVector;
}

void pq_push(int current_node, int source_node, vv q_vector)
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

    cout << "\n\n***** THE PATH IS DOWN BELOW FOR ROOT " << root << "  *****" << endl;

    // initially pushing all the nodes except the source to the queue
    for (int i = 1; i <= total_nodes; i++)
    {
        if (i != source_node)
        {
            pq_push(i, source_node, graph);
        }
    }
    int current_source_node;
    while (!pq.empty())
    {
        current_source_node = pq.top().second.second.first;
        base_cost = pq.top().first * -1;
        // cout << "Source is " << pq.top().second.first << endl;
        cout << pq.top().second.first << "->";

        vv myVector = pq.top().second.second.second;
        route_details.pb(pq);

        pq = priority_queue<base_costs>(); // clearing the queue

        for (int i = 1; i <= total_nodes; i++) // pushing all the unvisited nodes to the queue
        {
            if (myVector[i - 1][root - 1] != user_infinity) // checking the root column if every node is visited or not
            {
                pq_push(i, current_source_node, myVector);
            }
        }
    }

    cout << current_source_node << endl;
    cout << "\n"
         << base_cost << " is the total path cost  ";
}

int main()
{
    int source_node = 1;
    root = source_node;           // setting the root as source node for using in other functions
    sample_graph();               // creating the graph
    graph = reduce_matrix(graph); // finding the reduced matrix
    show_vector(graph);
    int first_reduced_base_cost = base_cost;
    cout << "The base cost is   " << base_cost << endl;
    // cout << "The source node is " << source_node << endl;
    // selling_route(source_node); // solving the graph for one source only
    for (int i = 1; i <= total_nodes; i++) // here source is dynamic to find way from any source
    {
        root = i;
        base_cost = first_reduced_base_cost;
        selling_route(i);
        cout << endl;
    }
    // path details are stored in in route_details as in queue .can access all of them via modifying
    show_route_details();
}

    101     10     17      0      1 
    12    101     11      2      0
     0      3    101      0      2
    15      3     12    101      0
    11      0      0     12    101
The base cost is   25


***** THE PATH IS DOWN BELOW FOR ROOT 1  *****
1->4->2->5->3

28 is the total path cost


***** THE PATH IS DOWN BELOW FOR ROOT 2  *****
2->5->3->1->4

28 is the total path cost


***** THE PATH IS DOWN BELOW FOR ROOT 3  *****
3->1->4->2->5

28 is the total path cost


***** THE PATH IS DOWN BELOW FOR ROOT 4  *****
4->5->3->1->2

37 is the total path cost


***** THE PATH IS DOWN BELOW FOR ROOT 5  *****
5->3->1->4->2

28 is the total path cost


****** Details of each path is down below ******

From root 1
Going to 4 With cost 25
Going to 2 With cost 28
Going to 5 With cost 28 
Going to 3 With cost 28

From root 2
Going to 5 With cost 28
Going to 3 With cost 28
Going to 1 With cost 28
Going to 4 With cost 25
Going to 2 With cost 28
Going to 5 With cost 28

From root 4
Going to 5 With cost 27
Going to 3 With cost 30
Going to 1 With cost 37
Going to 2 With cost 37

From root 5
Going to 3 With cost 28
Going to 1 With cost 28
Going to 4 With cost 28
Going to 2 With cost 28