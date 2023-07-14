#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <stdlib.h>
#include <unordered_map>
#include <string.h>
#include <string>
using namespace std;
template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

bool isLeaf(BinaryTreeNode<int> *root)
{
    if (!root->left && !root->right)
    {
        return true;
    }
    return false;
}
void help(BinaryTreeNode<int> *root, vector<string> &ans, string temp)
{
    temp += to_string(root->data) + " ";
    if (isLeaf(root))
    {
        ans.push_back(temp);
        return;
    }
    if (root->left)
        help(root->left, ans, temp);
    if (root->right)
        help(root->right, ans, temp);
}

vector<string> allRootToLeaf(BinaryTreeNode<int> *root)
{
    vector<string> ans;
    string temp = "";
    if (!root)
        return ans;
    help(root, ans, temp);
    return ans;
}