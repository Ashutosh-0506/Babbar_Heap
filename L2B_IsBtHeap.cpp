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

// Structure of node
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
private:
    // Function to check if the binary tree is a Complete Binary Tree (CBT)
    bool isCBT(struct Node *root, int index, int maxCount)
    {
        // If root is NULL, it's considered a complete tree (base case)
        if (root == NULL)
        {
            return true;
        }

        // If the index of the current node exceeds the total node count, it's not CBT
        if (index >= maxCount)
        {
            return false;
        }

        // Recursively check the left and right subtrees
        int left = isCBT(root->left, index * 2 + 1, maxCount);  // Left child index
        int right = isCBT(root->right, index * 2 + 2, maxCount); // Right child index
        
        // The tree is a CBT if both left and right subtrees are CBT
        return left && right;
    }

    // Function to count the total number of nodes in the tree
    int count(struct Node *root)
    {
        // Base case: if the node is NULL, there are no nodes to count
        if (root == NULL)
        {
            return 0;
        }

        // Return 1 (for the current node) + count of nodes in the left and right subtrees
        return 1 + count(root->left) + count(root->right);
    }

    // Function to check if the binary tree satisfies the Max-Heap property
    bool isMax(struct Node *root)
    {
        // Base case: if the node is NULL, it's considered a valid max-heap
        if (root == NULL)
        {
            return true;
        }

        // If it's a leaf node (no children), it's a valid max-heap
        if (root->left == NULL && root->right == NULL)
        {
            return true;
        }

        // If there's only a left child, check if the parent is greater than the left child
        if (root->right == NULL)
        {
            return root->data > root->left->data;
        }

        // If there are both left and right children, check if:
        // - the parent is greater than both children
        // - and both the left and right subtrees are also max-heaps
        return (root->data > root->left->data) && 
               (root->data > root->right->data) && 
               isMax(root->left) && 
               isMax(root->right);
    }

public:
    // Main function to check if a binary tree is a heap
    bool isHeap(struct Node *tree)
    {
        int index = 0;
        // Get the total number of nodes in the tree
        int maxCount = count(tree);
        
        // Check if the tree is both a Complete Binary Tree (CBT) and satisfies Max-Heap property
        return isCBT(tree, index, maxCount) && isMax(tree);
    }
};
 
int main()
{
    return 0;
}