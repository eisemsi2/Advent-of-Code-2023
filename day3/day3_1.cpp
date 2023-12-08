#include<bits/stdc++.h>
#include<fstream>
#define vi vector<long long int>
#define ll long long


using namespace std; 

set<char> symbols = {'~','!','@','#','$','%','^','&','*','-','=','+','/','<','>',',','_','{','}','[',']','`',':',';','\\'};

bool check(vector<string> grid, int s, int e, int i,int num) {
    // bool valid = false;
    
    int a;
    int b;

    if (i > 0) a = i-1;
    else a = i;
    if (s > 0) b = s-1;
    else b = s;

    int q,w;
    if (a == i-1) q = a+3;
    else q = a+2;

    if (b == s-1) w = b+(e-s+1)+2;
    else w = b+(e-s+1)+1; 
    
    for (int k = a; k < q && k<grid.size(); k++) {
        for (int l=b; l<w && l<grid[k].size(); l++) {
            if (symbols.find(grid[k][l]) != symbols.end()) return true;
        }
    }

    return false;
}

int main() {
    ifstream infile;
    infile.open("day3.txt");
    vector<string> grid;

    string line;
    while (getline(infile,line)) {
        grid.push_back(line);
    }

    ll sum = 0;

    vector<vector<int>> kha;

    for (int i=0; i<grid.size(); i++) {
        int s=-1,e=-1, num = 0;
        for (int j=0; j<grid[i].size(); j++) {
            if (s == -1 && grid[i][j] <= '9' && grid[i][j] >= '0') {
                s = j;
                num = grid[i][j] - '0';
            }

            else if (s != -1 && grid[i][j] <= '9' && grid[i][j] >= '0') {
                num = num*10 + (grid[i][j]-'0');

                if (j == grid[i].size()-1) {
                    e = j;
                }
            }

            else if (s != -1 && (grid[i][j] > '9' || grid[i][j]<'0' )) {
                e = j-1;
            }

            // we found a number in grid
            if (e != -1) {
                if (check(grid,s,e,i,num) == true) {
                    sum += num;
                    kha.push_back({i,s,e});
                }
                s = -1;
                e = -1;
                num = 0;
            }
        }
    }

    for (int m=0; m<kha.size(); m++) {
        int i = kha[m][0];
        int s = kha[m][1];
        int e = kha[m][2];

        for (int j=s; j<=e; j++) {
            grid[i][j] = ' ';
        }
    }
    ofstream outfile;
    outfile.open("out.txt");
    for (int i=0; i<grid.size(); i++) {
        outfile<<grid[i]<<endl;
    }
    cout<<sum<<endl;

    return 0;
}