#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <stdlib.h>
#include <unordered_map>
#include <string.h>
using namespace std;
/*
    Time Complexity: O( N * N )
    Space Complexity: O( 1 )

    where N is the length of string
*/

string minWindow(string S, string T)
{
    // Initially our window is empty
    string window = "";
    int j = 0, min = S.length();

    for (int i = 0; i < S.length(); i++)
    {

        // If characters are same, then increment the j pointer
        if (S[i] == T[j])
        {
            j++;

            // If we finally reach the end of string T, we can start shrinking our window
            if (j == T.length())
            {
                int end = i;
                j--;

                // We are doing j-- in order to minimise our window size
                while (j >= 0)
                {
                    if (S[i] == T[j])
                    {
                        j--;
                    }
                    i--;
                }

                // Incrementing i and j for next iteration
                j++;
                i++;

                // Updating our window, if we found an element of minimum length
                if (end - i < min)
                {

                    // Updating minimum
                    min = end - i;

                    // Updating window
                    window = "";
                    for (int j = i; j <= end; ++j)
                    {
                        window += S[j];
                    }
                }
            }
        }
    }

    // Returning our final answer, which is stored in window
    return window;
}