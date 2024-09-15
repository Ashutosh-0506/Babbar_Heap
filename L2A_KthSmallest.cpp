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
public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k)
    {
        // Step 1: Find the size of the array
        int n = arr.size();

        // Step 2: Create a min-heap (priority_queue with greater<int>).
        // A min-heap will allow us to access the smallest elements first.
        priority_queue<int, vector<int>, greater<int>> pq;

        // Step 3: Insert all elements of the array into the min-heap
        for (auto &it : arr)
        {
            pq.push(it); // Push each element into the heap
        }

        // Step 4: Remove the smallest elements (k-1 times) to reach the kth smallest
        while (!pq.empty() && k > 1)
        {
            pq.pop(); // Remove the top element (smallest in the heap)
            k--;      // Decrement k to move closer to the kth smallest
        }

        // Step 5: After popping k-1 elements, the top of the heap is the kth smallest element
        return pq.top(); // Return the kth smallest element
    }
};

int main()
{
    return 0;
}