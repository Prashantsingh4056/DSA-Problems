#include <bits/stdc++.h>
using namespace std;

//* --------------------------- Brute force Code , not Memoized --------------------------

bool solve1(int idx, unordered_set<string> &st, string s, vector<string> &wordDict)
{

    // base case if index reaches out of boundary
    if (idx == s.size())
        return true;

    // return true if whole string is found in wordDict
    if (st.find(s) != st.end())
        return true;

    // Take all possible lengths of substring 
    for (int l = 1; l < s.size(); l++)
    {

        // take a substring from index idx to length l
        string temp = s.substr(idx, l);

        // if the substring exists in wordDict , check for remaining String
        if (st.find(temp) != st.end() && solve1(idx + l, st, s, wordDict))
            return true;
    }

    // otherwise , return false
    return false;
}

bool wordBreak1(string s, vector<string> &wordDict)
{

    // take unordered set to store all words
    unordered_set<string> st;


    // Store all words in the unordered set
    for (int i = 0; i < wordDict.size(); i++)
    {

        st.insert(wordDict[i]);
    }

    // call the recursive function
    return solve1(0, st, s, wordDict);
}

//* ------------------------------------------------------------------------------------

//* ---------------------------------- Optimized code / Memoization -----------------------

// Recursive solver with memoization
bool solve(int idx, unordered_set<string>& st, string s, int t[]) {
    // Base: successfully reached the end of the string
    if (idx == s.size()) return true;

    // Return cached result if already calculated
    if (t[idx] != -1) return t[idx];

    // Try all possible substring lengths starting from idx
    for (int l = 1; idx + l <= s.size(); l++) {
        string temp = s.substr(idx, l);

        // If prefix is valid, solve for the remaining suffix
        if (st.find(temp) != st.end() && solve(idx + l, st, s, t)) {
            return t[idx] = 1; // Cache true
        }
    }

    return t[idx] = 0; // Cache false
}

// Wrapper function to initialize lookup set and DP array
bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> st;
    int t[301];

    // Initialize DP array with -1 (unvisited)
    for (int i = 0; i < 301; i++) t[i] = -1;

    // Convert vector to set for O(1) lookups
    for (int i = 0; i < wordDict.size(); i++) {
        st.insert(wordDict[i]);
    }

    // Start recursion from index 0
    return solve(0, st, s, t);
}

int main()
{

    string s1 = "leetcode";
    vector<string> wordDict1 = {"leet", "code"};

    cout << "Test Case 1: " << s1 << endl;
    cout << wordBreak(s1, wordDict1) << endl;

    // Test Case 2
    string s2 = "applepenapple";
    vector<string> wordDict2 = {"apple", "pen"};

    cout << "Test Case 2: " << s2 << endl;
    cout << wordBreak(s2, wordDict2) << endl;
}