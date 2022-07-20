#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> weight_destination;

vector<priority_queue<weight_destination>> graph;

void sample_graph()
{
    priority_queue<weight_destination> temp;
    priority_queue<weight_destination> empty;

    temp.push(make_pair(-2, 2));
    temp.push(make_pair(-3, 4));

    graph.push_back(temp);
    temp = empty;

    temp.push(make_pair(-5, 3));
    temp.push(make_pair(-1, 4));

    graph.push_back(temp);
    temp = empty;

    temp.push(make_pair(-2, 6));

    graph.push_back(temp);
    temp = empty;

    temp.push(make_pair(-1, 5));

    graph.push_back(temp);
    temp = empty;

    temp.push(make_pair(-1, 3));
    temp.push(make_pair(-10, 6));

    graph.push_back(temp);
    temp = empty;
}

int main()
{
    sample_graph();
    int total_node = 6;
    int visited = 1;
    int src = 1;
    
    while (visited != total_node)
    {
        src -= 1;
        src = graph[src].top().second;
        cout << src << " ->";
        visited++;
    }

    return 0;
}

/*

Dijkstra algorithm works where there is no negative edge but there can be a cycle . 

In this algorithm there will be an source node where we will traverse to the lowest weighted node from the source so while taking input if we take weight and destination in a queue in a 2d vector then and while keeping it weight to a minus so that we will always find the lowest weighted node in the first column. 

So once we have created the graph all the lowest weighted nodes destination from the source will be in the first coulmn .

so now all we have to do is to visit a node and find the lowest weighted destination from that source and again set that destination as the new source 

*/