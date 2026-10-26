#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<pair<int,int>> directions = {{0,1}, {1,0}, {-1,0}, {0,-1}};

    int dfs(vector<vector<int>>& grid, int i, int j, long long& sum, int n, int m) {
        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0) {
            return 0;
        }

        sum += grid[i][j];
        grid[i][j] = 0;

        for(auto &it : directions) {
            int new_i = i + it.first;
            int new_j = j + it.second;

            dfs(grid, new_i, new_j, sum, n, m);
        }

        return 0;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] > 0) {
                    long long sum = 0;
                    dfs(grid, i, j, sum, n, m);

                    if(sum % k == 0) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};

int main(){
    vector<vector<int>>grid= {{0,2,1,0,0},{0,5,0,0,5},{0,0,1,0,0},{0,1,4,7,0},{0,2,0,0,8}};
    int k=5;
    Solution s;
    cout<<s.countIslands(grid,k)<<endl;
    return 0;
}