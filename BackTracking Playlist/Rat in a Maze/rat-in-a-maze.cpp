#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>> &arr, int n, vector<string> &paths, string &path)
{

    if (row == -1 || row == arr.size() || col == -1 || col == arr[0].size() || arr[row][col] == 0)
        return;

    if (row == n - 1 && col == n - 1)
    {
        paths.push_back(path);
    }

    arr[row][col] = 0;

    path.push_back('D');
    dfs(row + 1, col, arr, n, paths, path);
    path.pop_back();

    path.push_back('L');
    dfs(row, col - 1, arr, n, paths, path);
    path.pop_back();

    path.push_back('R');
    dfs(row, col + 1, arr, n, paths, path);
    path.pop_back();

    path.push_back('U');
    dfs(row - 1, col, arr, n, paths, path);
    path.pop_back();

    arr[row][col] = 1;
}

vector<string> searchMaze(vector<vector<int>> &arr, int n)
{

    vector<string> paths;

    string path = "";

    dfs(0, 0, arr, n, paths, path);

    return paths;
}  

int main()
{
    int arr[5] = {2, 3, 4, 5, 6};
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    return 0;
}