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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (!root)
        {
            return res;
        }
        queue<TreeNode *> q;
        q.push(root);
        bool flag = true;
        while (!q.empty())
        {
            int size = q.size();
            vector<int> currLevel(size);
            for (int i = 0; i < size; i++)
            {
                int index = flag ? i : size - i - 1;

                TreeNode *curr = q.front();
                q.pop();
                currLevel[index] = curr->val;
                if (curr->left)
                {
                    q.push(curr->left);
                }
                if (curr->right)
                {
                    q.push(curr->right);
                }
            }
            flag = !flag;
            res.push_back(currLevel);
        }
        return res;
    }
};