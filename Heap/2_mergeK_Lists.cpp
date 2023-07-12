#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <stdlib.h>
#include <unordered_map>
#include <string.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    struct Compare
    {
        bool operator()(ListNode *a, ListNode *b)
        {
            return a->val > b->val;
        }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, Compare> pq;
        int k = lists.size();
        ListNode *head = nullptr;
        ListNode *tail = nullptr;

        // Push the initial elements into the priority queue
        for (int i = 0; i < k; i++)
        {
            if (lists[i] != nullptr)
            {
                pq.push(lists[i]);
            }
        }

        while (!pq.empty())
        {
            ListNode *temp = pq.top();
            pq.pop();

            if (head == nullptr)
            {
                head = temp;
                tail = temp;
            }
            else
            {
                tail->next = temp;
                tail = temp;
            }

            if (temp->next != nullptr)
            {
                pq.push(temp->next);
            }
        }

        return head;
    }
};


//or u can alwaypush them in a array sort it then make a linked list our of it