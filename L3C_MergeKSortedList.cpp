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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Custom comparator class to be used with the priority_queue (min-heap)
class Comparator
{
public:
    // Comparator to ensure that the priority_queue behaves as a min-heap
    // It returns true if the value of node 'a' is greater than the value of node 'b'
    // This makes the smallest element have the highest priority
    bool operator()(ListNode *a, ListNode *b)
    {
        return a->val > b->val; // Min-heap: smaller values have higher priority
    }
};

class Solution
{
public:
    // Function to merge k sorted linked lists into one sorted list
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int n = lists.size(); // Get the number of linked lists

        // Step 1: Initialize a priority_queue (min-heap) to store ListNode pointers
        priority_queue<ListNode *, vector<ListNode *>, Comparator> pq;

        // Step 2: Push the head (first node) of each linked list into the priority queue
        for (int i = 0; i < n; i++)
        {
            if (lists[i] != NULL)
            {                      // Only push non-null heads
                pq.push(lists[i]); // Add the head node of the i-th list
            }
        }

        // Step 3: Create a dummy node to serve as the start of the merged list
        ListNode *dummy = new ListNode(0); // Dummy node with value 0
        ListNode *ans = dummy;             // 'ans' pointer will build the final merged list

        // Step 4: Process the priority queue until it's empty
        while (!pq.empty())
        {
            // Get the node with the smallest value (top of the min-heap)
            ListNode *val = pq.top();
            pq.pop(); // Remove the smallest node from the heap

            // Attach the smallest node to the merged list
            ans->next = val;
            ans = ans->next; // Move 'ans' to the newly added node

            // Step 5: If the smallest node has a next node, push it into the heap
            if (val->next != NULL)
            {
                pq.push(val->next); // Push the next node of the current list
            }
        }

        // Step 6: Return the merged list, starting from dummy->next (skipping the dummy node)
        return dummy->next;
    }
};

int main()
{
    return 0;
}