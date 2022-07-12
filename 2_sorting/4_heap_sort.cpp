#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> v;

typedef pair<int, int> child;
typedef pair<int, child> parent;
vector<parent> heap;

void print_vector(vector<int> v) // printing the vector
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}

void build_child_parent_realtion() // building the child parent relation
{
    for (int i = 0; i < v.size(); i++)
    {
        heap.push_back(make_pair(v[i], make_pair(((i + 1) * 2), (i + 1) * 2 + 1))); // making pair of child and parent
    }
}

void print_child_parent_realtion() // printing the child parent relation
{
    for (int i = 0; i < heap.size(); i++)
    {
        cout << i + 1 << " \t" << heap[i].first << " \t" << heap[i].second.first << " \t" << heap[i].second.second << endl;
    }
}

void min_heapify(int i)
{
    int left_child, right_child, minimum;
    left_child = heap[i].second.first - 1;   // finding the position of left child
    right_child = heap[i].second.second - 1; // finding the position of right child

    int parent_node = heap[i].first; // finding the parent node

    // cout << "Parent " << parent_node <<"left_child: " << left_child << " right_child: " << right_child << endl;

    if (left_child <= heap.size() && heap[left_child].first < parent_node) // if left child exists and is less than parent
    {
        minimum = left_child;
    }
    else
    {
        minimum = i;
    }

    if (right_child <= heap.size() && heap[right_child].first < heap[minimum].first) // if right child exists and is less than the left child
    {
        minimum = right_child;
    }
    if (minimum != i) // if parent is not minimum
    {
        swap(heap[minimum].first, heap[i].first); // swapping the parent and the minimum
        min_heapify(minimum);
    }
}
void build_min_heap()
{
    for (int i = heap.size() / 2; i >= 0; i--) // starting from the last parent node
    {
        min_heapify(i);
    }
}

vector<int> result;
void heap_sort()
{

    int size = heap.size() - 1;
    for (int i = size; i >= 0; i--)
    {

        swap(heap[0].first, heap[i].first);
        result.push_back(heap[0].first);

        // cout << heap[i].first << " ";
        heap.pop_back();
        min_heapify(0);
    }
}

int main()
{
    // taking the user input
    v.push_back(1);
    v.push_back(6);
    v.push_back(7);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    cout << "The user input " << endl;
    print_vector(v);

    cout << "\n\nAfter building the child parent relation \n\nNode \tParent \tC 1 \tC 2" << endl;

    build_child_parent_realtion();
    print_child_parent_realtion();

    cout << "\n\nAfter building  the min heap \n\nNode \tParent \tC 1 \tC 2" << endl;
    build_min_heap();
    print_child_parent_realtion();


    cout << "\n\nThe sorted vector is \n\n";
    heap_sort();
    print_vector(result);

    cout << endl;
    return 0;
}

// 1 2 4 6 3 7