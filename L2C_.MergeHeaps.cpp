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
class Solution
{
private:
    // Function to heapify a subtree rooted at index 'index' in a vector 'v' of size 'size'
    // 'heapify' ensures the subtree follows the Max-Heap property
    void heapify(vector<int> &v, int size, int index)
    {
        int largest = index;       // Initialize largest as the root
        int left = 2 * index + 1;  // Left child index
        int right = 2 * index + 2; // Right child index

        // If the left child is larger than the current largest (root), update largest
        if (left < size && v[largest] < v[left])
        {
            largest = left;
        }

        // If the right child is larger than the current largest, update largest
        if (right < size && v[largest] < v[right])
        {
            largest = right;
        }

        // If the largest is not the root, swap the root with the largest child
        if (largest != index)
        {
            swap(v[largest], v[index]);
            // Recursively heapify the affected subtree
            heapify(v, size, largest);
        }
    }

public:
    // Function to merge two heaps 'a' and 'b' into a single Max-Heap
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
    {
        // Append all elements of vector 'b' to vector 'a'
        for (auto &it : b)
        {
            a.push_back(it);
        }

        int size = m + n; // Total size of the merged heap

        // Start heapifying from the last non-leaf node to build the Max-Heap
        for (int i = size / 2; i >= 0; i--)
        {
            heapify(a, size, i); // Ensure the subtree rooted at 'i' is a Max-Heap
        }
        return a; // Return the merged Max-Heap
    }
};

int main()
{
    return 0;
}