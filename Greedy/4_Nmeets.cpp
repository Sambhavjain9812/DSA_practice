#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <stdlib.h>
#include <string.h>
using namespace std;
class Solution
{
public:
    struct Meeting
    {
        int start;
        int end;
    };

    static bool sortByEndTime(const Meeting &a, const Meeting &b)
    {
        return a.end < b.end;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        vector<Meeting> meet;
        for (int i = 0; i < n; i++)
        {
            Meeting m{start[i], end[i]};
            meet.push_back(m);
        }
        sort(meet.begin(), meet.end(), sortByEndTime);
        int count = 1;
        int last = meet[0].end;
        for (int i = 0; i < n; i++)
        {
            if (meet[i].start > last)
            {
                count++;
                last = meet[i].end;
            }
        }
        return count;
    }
};