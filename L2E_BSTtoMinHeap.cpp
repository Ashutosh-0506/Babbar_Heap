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
class BinaryTreeNode
{

public:
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(int data)
    {
        this->left = NULL;
        this->right = NULL;
        this->data = data;
    }
};
void inorder(BinaryTreeNode *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}
void preorder(BinaryTreeNode *root, vector<int> &ans, int &index)
{
    if (root == NULL)
    {
        return;
    }
    root->data = ans[index++];
    preorder(root->left, ans, index);
    preorder(root->right, ans, index);
}
BinaryTreeNode *convertBST(BinaryTreeNode *root)
{
    // Write your code here.
    vector<int> ans;
    inorder(root, ans);

    int n = ans.size();
    int index = 0;
    preorder(root, ans, index);
    return root;
}
int main()
{
    return 0;
}