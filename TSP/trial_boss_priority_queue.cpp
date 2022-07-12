
#include <bits/stdc++.h>
using namespace std;

// priority_queue<int, vector<int>> pq;

// queue<int> min_costs_queue[2];

// typedef vector<int> ma_vector[5];
// priority_queue<pair<int,ma_vector> > testPQwPV;
// typedef vector<int> myVector1;
typedef vector<vector<int>> myVector1;
typedef pair<int, myVector1> visited_vector;
typedef pair<int, visited_vector> predecessor;
typedef pair<int, predecessor> base_costs;
priority_queue<base_costs> pq;

vector<int> graph[7];
void sample_graph()
{

    graph[1].push_back(101);
    graph[1].push_back(20);
    graph[1].push_back(30);
    graph[1].push_back(10);
    graph[1].push_back(11);

    graph[2].push_back(15);
    graph[2].push_back(101);
    graph[2].push_back(16);
    graph[2].push_back(4);
    graph[2].push_back(2);

    graph[3].push_back(3);
    graph[3].push_back(5);
    graph[3].push_back(101);
    graph[3].push_back(2);
    graph[3].push_back(4);

    graph[4].push_back(19);
    graph[4].push_back(6);
    graph[4].push_back(18);
    graph[4].push_back(101);
    graph[4].push_back(3);

    graph[5].push_back(16);
    graph[5].push_back(4);
    graph[5].push_back(7);
    graph[5].push_back(16);
    graph[5].push_back(101);
}
int main()
{
    sample_graph();

    vector<vector<int>> myVector;

    myVector.push_back(graph[1]);
    myVector.push_back(graph[2]);
    myVector.push_back(graph[3]);
    myVector.push_back(graph[4]);
    myVector.push_back(graph[5]);

    // pq.push(make_pair(2, make_pair(3, make_pair(4, graph[1]))));
    pq.push(make_pair(2, make_pair(3, make_pair(4, myVector))));

    cout << pq.top().first << pq.top().second.first << pq.top().second.second.first <<endl ;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << setw(6)<<pq.top().second.second.second[i][j] << " ";
        }
        cout <<endl;
    }

    // // min_costs_queue[0].push(2);
    // // min_costs_queue[1].push(3);

    // // cout << min_costs_queue[0].front();
    // // cout << min_costs_queue[1].front();

    // cout << "Hello world" << endl;
    // // pq.second.push_back(2);
    // // cout << pq.second[0];

    // vector<int> main_vector[5];
    // main_vector[0].push_back(1);
    // main_vector[1].push_back(1);
    // main_vector[2].push_back(1);
    // main_vector[3].push_back(1);
    // main_vector[4].push_back(1);
    // //testPQwPV.top().first = 2;

    // testPQwPV.push(make_pair(2, main_vector));

    // vector<int> copy[5];
    // //copy[0] = main_vector[0];

    // //cout << copy[0][0];
}
