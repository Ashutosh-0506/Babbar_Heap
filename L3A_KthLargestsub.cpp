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

// Function to find the k-th largest sum of subarrays in a given array
int getKthLargest(vector<int> &arr, int k)
{
    // Get the size of the input array
    int n = arr.size();

    // Min-heap (priority queue) to store the k largest sums
    // The smallest sum among the top k will be at the top of the heap
    priority_queue<int, vector<int>, greater<int>> pq;

    // Outer loop to start from each index of the array
    for (int i = 0; i < n; i++)
    {
        int total = 0; // To store the sum of subarray starting at index 'i'

        // Inner loop to form subarrays starting from index 'i' to 'j'
        for (int j = i; j < n; j++)
        {
            total += arr[j]; // Add arr[j] to the current subarray sum

            // If the heap has less than 'k' elements, just add the current sum
            if (pq.size() < k)
            {
                pq.push(total);
            }
            else
            {
                // If the heap has 'k' elements and the current sum is larger than
                // the smallest sum in the heap (which is at the top), replace it
                if (pq.top() < total)
                {
                    pq.pop();       // Remove the smallest sum
                    pq.push(total); // Insert the current sum
                }
            }
        }
    }

    // The k-th largest sum will be at the top of the heap
    return pq.top();
}

int main()
{
    return 0;
}