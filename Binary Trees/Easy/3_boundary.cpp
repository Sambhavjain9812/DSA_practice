#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <stdlib.h>
#include <unordered_map>
#include <string.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};
bool isLeaf(TreeNode<int> *root)
{
    if (!root->right && !root->left)
    {
        return true;
    }
    return false;
}
void addleft(TreeNode<int> *root, vector<int> &res)
{
    TreeNode<int> *curr = root->left;
    while (curr)
    {
        if (!isLeaf(curr))
        {
            res.push_back(curr->data);
        }
        if (curr->left)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
}
void addright(TreeNode<int> *root, vector<int> &res)
{
    TreeNode<int> *curr = root->right;
    vector<int> temp;
    while (curr)
    {
        if (!isLeaf(curr))
        {
            temp.push_back(curr->data);
        }
        if (curr->right)
        {
            curr = curr->right;
        }
        else
        {
            curr = curr->left;
        }
    }
    for (int i = temp.size() - 1; i >= 0; i--)
    {
        res.push_back(temp[i]);
    }
}

void addleaf(TreeNode<int> *root, vector<int> &res)
{
    if (isLeaf(root))
    {
        res.push_back(root->data);
    }
    if (root->left)
        addleaf(root->left, res);
    if (root->right)
        addleaf(root->right, res);
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
    // Write your code here.
    vector<int> res;
    if (!root)
        return res;

    if (!isLeaf(root))
        res.push_back(root->data);

    addleft(root, res);

    // add leaf nodes
    addleaf(root, res);

    addright(root, res);
    return res;
}