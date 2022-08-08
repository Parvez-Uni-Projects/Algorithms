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


}

int main()
{
    sample_graph();
    int total_node = 6;
    int visited = 1;
    int src = 1;

    vector<pair<int, int>> v;
    v.push_back(make_pair(0, 0));
    v.push_back(make_pair(101, 0));
    v.push_back(make_pair(101, 0));
    v.push_back(make_pair(101, 0));
    v.push_back(make_pair(101, 0));
    v.push_back(make_pair(101, 0));
    int total_nodes = 6;
    vector<pair<int, pair<int, int>>> edge;
    edge.push_back(make_pair(2, make_pair(1, 2)));
    edge.push_back(make_pair(3, make_pair(1, 2)));
    edge.push_back(make_pair(5, make_pair(2, 3)));
    edge.push_back(make_pair(1, make_pair(2, 4)));
    edge.push_back(make_pair(2, make_pair(3, 6)));
    edge.push_back(make_pair(1, make_pair(5, 3)));
    edge.push_back(make_pair(9, make_pair(5, 6)));

    int total_edge = edge.size();
    for (int i = 0; i < total_nodes; i++)
    {

        for (int i = 0; i < total_edge; i++)
        {
            int curr_src = edge[i].second.first;
            int curr_des = edge[i].second.second;
            int curr_weight = edge[i].first + v[curr_src-1].first;

            if (v[curr_des-1].first > curr_weight )
            {
                v[curr_des-1].first = curr_weight;
                v[curr_des-1].second = curr_src;

            }
        }
    }

    for ( int i = 0 ; i < v.size();i++)
    {
        cout << v[i].second << " ";
    }

    return 0;
}
