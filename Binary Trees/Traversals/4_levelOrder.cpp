#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <stdlib.h>
#include <unordered_map>
#include <string.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        queue<TreeNode *> q;
        vector<vector<int>> result;
        if (root == NULL)
        {
            return result;
        }
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();

            vector<int> currlevel;
            for (int i = 0; i < size; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                currlevel.push_back(curr->val);
                if (curr->left)
                {
                    q.push(curr->left);
                }
                if (curr->right)
                {
                    q.push(curr->right);
                }
            }
            result.push_back(currlevel);
        }
        return result;
    }
};