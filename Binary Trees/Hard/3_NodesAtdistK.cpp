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
    void abc(unordered_map<TreeNode *, TreeNode *> &parent, TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                if (curr->left)
                {
                    q.push(curr->left);
                    parent[curr->left] = curr;
                }
                if (curr->right)
                {
                    q.push(curr->right);
                    parent[curr->right] = curr;
                }
            }
        }
    }

    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        unordered_map<TreeNode *, TreeNode *> parent;
        abc(parent, root);
        int count = 0;
        queue<TreeNode *> q;
        q.push(target);
        unordered_map<TreeNode *, bool> vis;
        vis[target] = true;
        while (!q.empty())
        {
            if (count == k)
            {
                break;
            }
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                if (!vis[curr->left] && curr->left)
                {
                    q.push(curr->left);
                    vis[curr->left] = true;
                }
                if (!vis[curr->right] && curr->right)
                {
                    q.push(curr->right);
                    vis[curr->right] = true;
                }
                if (parent[curr] && !vis[parent[curr]])
                {
                    q.push(parent[curr]);
                    vis[parent[curr]] = true;
                }
            }
            count++;
        }

        vector<int> ans;
        while (!q.empty())
        {
            auto x = q.front();
            q.pop();

            ans.push_back(x->val);
        }
        return ans;
    }
};
