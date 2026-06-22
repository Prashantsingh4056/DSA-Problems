#include <bits/stdc++.h>
using namespace std;

    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> st(nums.begin() , nums.end());
        int maxLen = 0;

        for(int num : st){

            if(st.find(num - 1) == st.end()){
                int curr = num;
                int len = 1;

                while(st.count(curr + 1)){
                    curr++;
                    len++;
                }

                maxLen = max(maxLen , len);
            }
        }

        return maxLen;
    }


int main() {
    
    vector<int> vec = {1,2,3,11,33,4,5};
    cout << longestConsecutive(vec) << endl;
    
    return 0;
}