#include<bits/stdc++.h>
#include<fstream>

using namespace std;

vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

int bfs(vector<string> grid, vector<vector<int>> &dist, int n, int m, vector<vector<bool>> &vis, pair<int,int> s) {
    int mls = 0;

    queue<pair<int,int>> bfs;
    bfs.push(s);
    vis[s.first][s.second] = true;
    dist[s.first][s.second] = 0;

    while (bfs.empty() == false) {
        pair<int,int> node = bfs.front();
        int x = node.first;
        int y = node.second;
        bfs.pop();

        for (auto dir: dirs) {
            int dx = dir.first;
            int dy = dir.second;

            if (x+dx >=n || x+dx < 0 || y+dy>=m || y+dy< 0) continue;

            if (vis[x+dx][y+dy] == true) {
                if (dist[x+dx][y+dy] == dist[x][y]+1) {
                    //some loop found
                    if (dist[x+dx][y+dy] > mls) {
                        mls = dist[x+dx][y+dy];
                        continue;
                    }
                }
                else continue;
            }

            if (grid[x+dx][y+dy] == '.') continue;
            if (grid[x+dx][y+dy] == '|' && (dx == 0)) continue;
            if (grid[x+dx][y+dy] == '-' && (dy == 0)) continue;
            if (grid[x+dx][y+dy] == 'L' && (dx != 1 && dy != -1 )) continue;
            if (grid[x+dx][y+dy] == 'J' && (dx != 1 && dy != 1 )) continue;
            if (grid[x+dx][y+dy] == '7' && (dx != -1 && dy != 1)) continue;
            if (grid[x+dx][y+dy] == 'F' && (dx != -1 && dy != -1)) continue;

            bfs.push({x+dx,y+dy});
            dist[x+dx][y+dy] = dist[x][y]+1;
            vis[x+dx][y+dy] = true;  
        }


    }
    return mls;

}

int main() {
    ifstream infile;
    infile.open("day10.txt");
    ofstream ofile;
    ofile.open("out.txt");

    vector<string> grid;

    string line;
    while(getline(infile, line)) {
        grid.push_back(line);
    }
    
    int n = grid.size();
    int m = grid[0].size();
    
    int ans = 0;
    vector<vector<int>> dist (n, vector<int> (m,-1));
    for (int i=0; i<grid.size(); i++) {
        for (int j=0; j<grid[i].size(); j++) {
            if (grid[i][j] == 'S') {
                vector<vector<bool>> vis(n, vector<bool> (m,false));
                ans = bfs(grid,dist,n,m,vis,{i,j});
            }
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            ofile<<dist[i][j]<<" ";
        }
        ofile<<endl;
    }

    cout<<ans<<endl;
}