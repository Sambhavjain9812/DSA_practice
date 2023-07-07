#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

class Solution
{
public:
//we are comparing value/weight and  sorting them;
    bool static comp(Item a, Item b)
    {
        double r1 = (double)a.value / (double)a.weight;
        double r2 = (double)b.value / (double)b.weight;
        return r1 > r2;
    }
    // function to return fractionalweights
    double fractionalKnapsack(int W, Item arr[], int n)
    {

        sort(arr, arr + n, comp);

        int curWeight = 0;
        double finalvalue = 0.0;

        for (int i = 0; i < n; i++)
        {

            if (curWeight + arr[i].weight <= W)
            {
                curWeight += arr[i].weight;
                finalvalue += arr[i].value;
            }
            else
            {
                int remain = W - curWeight;
                finalvalue += (arr[i].value / (double)arr[i].weight) * (double)remain; // weight of 1 val * remaining wt of the problem
                break;
            }
        }

        return finalvalue;
    }
};