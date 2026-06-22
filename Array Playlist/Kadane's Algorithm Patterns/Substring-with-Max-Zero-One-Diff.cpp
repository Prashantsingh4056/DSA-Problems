#include <bits/stdc++.h>
using namespace std;

int maxSubstring(string &s)
{

    int Difference = 0;
    int maxDifference = INT_MIN;

    for (int i = 0; i < s.size(); i++)
    {

        // Kadane's Algorithm

        if (s[i] == '1')
        {
            Difference--;
        }
        else
        {
            Difference++;
        }

        maxDifference = max(Difference, maxDifference);

        if (Difference < 0)
        {
            Difference = 0;
        }
    }

    return maxDifference;
}

int main()
{
    
    string s = "110100110";
    int result = maxSubstring(s);   // output : 2
    cout << "Maximum difference between 0's and 1's in a substring: " << result << endl;

    // Example 2
    string s2 = "0000";
    int result2 = maxSubstring(s2);  // output : 4
    cout << "Maximum difference between 0's and 1's in a substring: " << result2 << endl;

    // Example 3
    string s3 = "1111";
    int result3 = maxSubstring(s3);  // output : 0
    cout << "Maximum difference between 0's and 1's in a substring: " << result3 << endl;

    return 0;
}