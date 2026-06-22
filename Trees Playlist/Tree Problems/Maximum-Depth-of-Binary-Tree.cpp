#include <bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//+ Way 1 : Optimal ✅, Not Interview ready ❌

void dfs(TreeNode *root, int currDepth, int &maxDepth)
{

    if (!root)
        return;

    currDepth++;

    maxDepth = max(maxDepth, currDepth);

    dfs(root->left, currDepth, maxDepth);
    dfs(root->right, currDepth, maxDepth);
}

int maxDepth(TreeNode *root)
{

    int maxDepth = 0;
    int currDepth = 0;

    dfs(root, currDepth, maxDepth);

    return maxDepth;
}

//+ Way 2 : Optimal ✅ , Interview Ready ✅

int maxDepth2(TreeNode *root)
{

    if (!root) return 0;

    int leftHeight = maxDepth(root->left);
    int rightHeight = maxDepth(root->right);

    return 1 + max(leftHeight, rightHeight);
}


//+ Way 3 : One Liner

int maxDepth3(TreeNode* root) {
        if(!root) return 0;

        return 1 + max(maxDepth(root->left) , maxDepth(root->right));
    }

int main()
{
    int arr[5] = {2, 3, 4, 5, 6};
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    return 0;
}