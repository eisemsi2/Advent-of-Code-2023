#include<bits/stdc++.h>
#include<fstream>

#define pp pair<int,int>
#define mp(x,y) make_pair(x,y)
#define ll long long
using namespace std;

int main() {
    vector<vector<char>> temp;
    vector<vector<char>> grid;

    ifstream infline;
    infline.open("day11.txt");
    ofstream out;
    out.open("out.txt");

    string line;
    while (getline(infline,line)) {
        vector<char> row;
        bool isemptyrow = true;
        for (int i=0; i<line.size(); i++) {
            row.push_back(line[i]);
            if (row[i] == '#') isemptyrow = false;
        }

        temp.push_back(row);
        if (isemptyrow == true) {
            row.clear();
            for (int i=0; i<line.size(); i++) {
                row.push_back('!');
            }
            // for (int k=0; k<9; k++)
            temp.push_back(row);
        }
    }

    int m = temp[0].size();
    int n = temp.size();
    
    grid.resize(n);

    for (int i=0; i<m; i++) {
        bool isemptycol = true;
        for (int j=0; j<n; j++) {
            if (temp[j][i] == '#') isemptycol = false;
            grid[j].push_back(temp[j][i]);
        }

        if (isemptycol == true) {
        // for (int k=0; k<9; k++) {
            for (int j=0; j<n; j++) {
                grid[j].push_back('!');
            }
        // }
        }

    }


    vector<pp> galaxies;
    n = grid.size();
    m = grid[0].size();

    vector<int> prerow (n,0);
    vector<int> precol (m,0);

    for (int i=1; i<n; i++) {
        bool expandedrow = true;
        for (int j=0; j<m; j++) {
            if (grid[i][j] != '!') expandedrow = false;
        }
        if (expandedrow == true) prerow[i] = prerow[i-1]+1;
        else prerow[i] = prerow[i-1];
    }

    for (int j=1; j<m; j++) {
        bool expandedcol = true;
        for (int i=0; i<n; i++) {
            if (grid[i][j] != '!') expandedcol = false;
        }
        if (expandedcol == true) precol[j] = precol[j-1]+1;
        else precol[j] = precol[j-1];
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            out<<grid[i][j];
        }
        out<<endl;
    }
    out<<endl;

    for (int i=0; i<n; i++) {
        out<<prerow[i]<<" ";
    }
    out<<endl;
    for (int i=0; i<m; i++) {
        out<<precol[i]<<" ";
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (grid[i][j] == '#') {
                galaxies.push_back(mp(i,j));
            }
        }
    }

    ll ans = 0;
    for (int i=0; i<galaxies.size(); i++) {
        for (int j=i+1; j<galaxies.size(); j++) {
            int x1 = galaxies[i].first;
            int y1 = galaxies[i].second;
            int x2 = galaxies[j].first;
            int y2 = galaxies[j].second;

            ll rowwrap = abs(prerow[x2]-prerow[x1]);
            ll colwrap = abs(precol[y2]-precol[y1]);

            ans += abs(x2-x1) + abs(y2-y1) + rowwrap*999998 + colwrap*999998;
        }

    }

    cout<<ans<<endl;






}