#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &nums)
{

    int slow = nums[0];
    int fast = nums[0];

    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    // find the starting point
    slow = nums[0];

    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}

int main()
{

    // Idea :
    // 1. We can treat the array as a linked list where the value at each index 
    //    points to the next index. Since there is a duplicate number, there will
    //    be a cycle in the linked list.
    // 2. We can use Floyd's Tortoise and Hare algorithm to find the duplicate number. 
    //    We will have two pointers, one slow and one fast. The slow pointer will move 
    //    one step at a time while the fast pointer will move two steps at a time.
    // 3. If there is a duplicate number, the fast pointer will eventually meet the
    //    slow pointer inside the cycle. Once they meet, we can reset one pointer to
    //    the start of the array and keep the other pointer at the meeting point. 
    //    Then we will move both pointers one step at a time until they meet again. 
    //    The point at which they meet will be the duplicate number.
    // 4. This algorithm runs in O(n) time and uses O(1) extra space.
    
    vector<int> nums = {1, 3, 4, 2, 2};
    int result = findDuplicate(nums); // output : 2
    cout << "The duplicate number is: " << result << endl;


    return 0;
}