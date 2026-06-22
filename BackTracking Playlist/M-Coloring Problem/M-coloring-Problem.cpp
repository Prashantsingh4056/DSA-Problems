#include <bits/stdc++.h>
using namespace std;


// check that is it safe to color a node with a given color 
bool isSafeToColor(int currColor , int node , vector<vector<int>> &mat , vector<int>& color , int n , int m){


    for(int k = 0 ; k < n ; k++){
        if(mat[node][k] == 1 && node != k && color[k] == currColor) return false;
    }

    return true;
}


bool isPossibleToColor(int node , vector<vector<int>> &mat , vector<int>& color , int n , int m){

    // if we reached the end node , this means all the previous nodes are colored
    if(node == n) return true;

    // check for each color from 1 to m
    for(int i = 1 ; i <= m ; i++){

        // condition check if we can color the node with i color
        if(isSafeToColor(i , node , mat , color , n , m)){

            // make the curr node with color i
            color[node] = i;
            if(isPossibleToColor(node + 1 , mat , color , n , m)) return true;
            color[node] = 0;
        }
    }

    // return false if not able to color a node
    return false;

}

string graphColoring(vector<vector<int>> &mat, int m) {

    // n -> number of nodes 
    int n = mat.size();

    // color vector to track the nodes which already been colored
    vector<int> color(n , 0);

    // function that tells if it is possible to color the graph with m colors 
    if(isPossibleToColor(0 , mat , color , n , m)) return "YES";

    return "NO";
}

