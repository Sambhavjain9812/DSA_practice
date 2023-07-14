#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <stdlib.h>
#include <map>
#include <string.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};
class Solution
{
public:
    vector<int> bottomView(Node *root)
    {
        // Your Code Here
        queue<pair<Node *, int>> q;
        q.push({root, 0});
        map<int, int> mp;
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            Node *temp = it.first;
            int line = it.second;
            mp[line] = temp->data;
            if (temp->left)
            {
                q.push({temp->left, line - 1});
            }
            if (temp->right)
            {
                q.push({temp->right, line + 1});
            }
        }
        vector<int> res;
        for (auto it : mp)
        {
            res.push_back(it.second);
        }
        return res;
    }
};