//***********************************ASHUTOSH KUMAR***********************************//
/*
कर्मण्येवाधिकारस्ते मा फलेषु कदाचन।
मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि॥

Karmanye vadhikaraste Ma Phaleshu Kadachana,
Ma Karmaphalaheturbhurma Te Sangostvakarmani,

The meaning of the verse is :—
You have the right to work only but never to its fruits.
Let not the fruits of action be your motive, nor let your attachment be to
inaction
*/
#include <bits/stdc++.h>
using namespace ::std;
#include <bits/stdc++.h>

// Node class to store the elements along with their positions in a 2D array
class Node
{
public:
    int data; // The value of the element
    int row;  // Row index of the element
    int col;  // Column index of the element

    // Constructor to initialize the node with data, row, and column
    Node(int data, int row, int col)
    {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

// Comparator class to define custom sorting logic for priority_queue
class Comparator
{
public:
    // Overloaded operator() to define a min-heap
    // Returns true if the first node's data is greater than the second's
    // This ensures the smallest element comes at the top of the heap
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

// Function to merge k sorted arrays
vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
    int n = kArrays.size(); // Number of arrays (k)

    // Step 1: Initialize a priority queue (min-heap) with custom comparator
    priority_queue<Node *, vector<Node *>, Comparator> pq;

    // Step 2: Push the first element of each array into the priority queue
    for (int i = 0; i < n; i++)
    {
        // Create a node with the first element of the i-th array
        Node *temp = new Node(kArrays[i][0], i, 0);
        pq.push(temp); // Push it into the priority queue
    }

    // Vector to store the final sorted result
    vector<int> ans;

    // Step 3: Process the priority queue until it's empty
    while (!pq.empty())
    {
        // Get the smallest element (root of the min-heap)
        Node *val = pq.top();
        pq.pop(); // Remove it from the heap

        // Add the data of the smallest element to the result array
        ans.push_back(val->data);

        int row = val->row; // The row from which this element came
        int col = val->col; // The column from which this element came

        // Step 4: If there are more elements in the same row, push the next element from this row
        if (col + 1 < kArrays[row].size())
        {
            // Create a node for the next element in the current row and push it into the heap
            Node *temp = new Node(kArrays[row][col + 1], row, col + 1);
            pq.push(temp);
        }
    }

    // Step 5: Return the sorted result
    return ans;
}

int main()
{
    return 0;
}