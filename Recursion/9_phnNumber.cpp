#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <stdlib.h>
#include <string.h>
using namespace std;
class Solution
{
    private:
        void solve(string digit, vector<string> &ans, int index, string output, string mapping[])
        {
           	//base case
            if (index >= digit.size())
            {
                ans.push_back(output);
                return;
            }

            int number = digit[index] - '0';
            string value = mapping[number];
            for (int i = 0; i < value.size(); i++)
            {
                output.push_back(value[i]);
                solve(digit, ans, index + 1, output, mapping);
                output.pop_back();
            }
        }
    public:
        vector<string> letterCombinations(string digits)
        {
           vector<string> ans;
            int index = 0;
            string output;
            string mapping[10] = { "",
                "",
                "abc",
                "def",
                "ghi",
                "jkl",
                "mno",
                "pqrs",
                "tuv",
                "wxyz" };
            if (digits.size() == 0)
                return ans;
            solve(digits, ans, index, output, mapping);
            return ans;
        }
};