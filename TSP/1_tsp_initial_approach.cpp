
#include<bits/stdc++.h>
using namespace std;

vector <int> graph [7];
int min_col = 5;
int min_row = 6;
int user_infinity = 101;


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

void find_minimum_going_cost(int i)
{
    int minimum_cost = *min_element(graph[i].begin(), graph[i].end());

    graph[i].push_back(minimum_cost);


}

void find_minimum_backing_cost(int j)
{
    int minimum_cost = user_infinity;
    for(int i = 1 ; i <= 5 ; i++ )
    {

        if (graph[i][j] < minimum_cost)
        {

            minimum_cost = graph[i][j];

        }
    }

    graph[6].push_back(minimum_cost);


}
void print_graph(int size)
{
    for (int i = 1 ; i <= size; i++)
    {

        for (int j = 0; j < graph[i].size(); j++)
        {

            cout <<setw(6) <<graph[i][j] << " " ;
        }
        cout<<"\n";
    }

}

void initial_reduced_matrix(int i)
{

    for (int j= 0 ; j < graph[i].size()-1 ; j++ )
    {

        if (i-1 != j)
        {

            graph[i][j] -= graph[i][min_col];
        }
    }
}
void final_reduced_matrix(int j)
{
    for (int i= 1 ; i <= 5 ; i++ )
    {

        if (i-1 != j)
        {

            graph[i][j] -= graph[min_row][j];
        }
    }
}
void last_index_sum()
{
    int sum=0;
    for(int i=1;i<=5;i++)
    {
         sum+=graph[6][i-1];
         sum+=graph[i][5];
    }
     graph[6].push_back(sum);


}
int main()
{
    sample_graph();

    cout << "\nUser given sample graph" <<endl;
    print_graph(5);

    for(int i = 1; i <=5; i++)
    {
        find_minimum_going_cost(i);
    }
    cout << "\nMinimum going cost of person " <<endl;
    print_graph(5);

    for(int i = 1; i <=5; i++)
    {
        initial_reduced_matrix(i);
    }

    cout << "\nInitial reduced matrix " <<endl;
    print_graph(5);


    cout << "\nMinimum backing cost of person " <<endl;

   for(int i = 0; i <5; i++)
    {
       find_minimum_backing_cost(i);
    }


    print_graph(6);


    for(int i = 0; i <5; i++)
    {
        final_reduced_matrix(i);
    }

    last_index_sum();


    cout << "\nFinal reduced matrix " <<endl;
    print_graph(6);

}
