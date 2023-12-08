#include<bits/stdc++.h>
#include<fstream>
#define vi vector<long long int>
#define ll long long


using namespace std; 

// set<char> symbols = {'~','!','@','#','$','%','^','&','*','-','=','+','/','<','>',',','_','{','}','[',']','`',':',';','\\'};

// bool check(vector<string> grid, int s, int e, int i,int num) {
//     // bool valid = false;
    
//     int a;
//     int b;

//     if (i > 0) a = i-1;
//     else a = i;
//     if (s > 0) b = s-1;
//     else b = s;

//     int q,w;
//     if (a == i-1) q = a+3;
//     else q = a+2;

//     if (b == s-1) w = b+(e-s+1)+2;
//     else w = b+(e-s+1)+1; 
    
//     for (int k = a; k < q && k<grid.size(); k++) {
//         for (int l=b; l<w && l<grid[k].size(); l++) {
//             if (symbols.find(grid[k][l]) != symbols.end()) return true;
//         }
//     }

//     return false;
// }
bool numadj(vector<string> grid, int i, int j) {
    if ((grid[i][j-1] <= '9' && grid[i][j-1] >='0') || (grid[i][j] <= '9' && grid[i][j] >='0') || (grid[i][j+1] <= '9' && grid[i][j+1] >='0')) return true;
    else return false;
}

vector<int> findadj( int i, int j, vector<string> grid) {
    //searching in i-1

    vector<int> r ;
    if (i != 0) {
        if (grid[i-1][j] != '.') {
            if (numadj(grid,i-1,j) == true) {
                string num = "";
                int j1 = j;
                while (j1>=0 && (grid[i-1][j1]>='0' && grid[i-1][j1] <='9' )) {
                    num.insert(num.begin(), grid[i-1][j1]);
                    j1--;
                }
                j1 = j+1;
                while (j1<grid[0].size() && (grid[i-1][j1]>='0' && grid[i-1][j1] <='9' )) {
                    num += grid[i-1][j1];
                    j1++;
                }
                r.push_back(stoi(num));
            }
        }

        else {
            if (grid[i-1][j-1] >='0' && grid[i-1][j-1] <='9') {
                string num = "";
                int j1 = j-1;
                while (j1>=0 && (grid[i-1][j1]>='0' && grid[i-1][j1] <='9' )) {
                    num.insert(num.begin(), grid[i-1][j1]);
                    j1--;
                }
                r.push_back(stoi(num));
            }
            if (grid[i-1][j+1] >='0' && grid[i-1][j+1] <='9') {
                string num = "";
                int j1 = j+1;
                while (j1<grid[0].size() && (grid[i-1][j1]>='0' && grid[i-1][j1] <='9' )) {
                    num += grid[i-1][j1];
                    j1++;
                }
                r.push_back(stoi(num));
            }
        }
    }
    if (i != grid.size()-1) {
        if (grid[i+1][j] != '.') {
            if (numadj(grid,i+1,j) == true) {
                string num = "";
                int j1 = j;
                while (j1>=0 && (grid[i+1][j1]>='0' && grid[i+1][j1] <='9' )) {
                    num.insert(num.begin(), grid[i+1][j1]);
                    j1--;
                }
                j1 = j+1;
                while (j1<grid[0].size() && (grid[i+1][j1]>='0' && grid[i+1][j1] <='9' )) {
                    num += grid[i+1][j1];
                    j1++;
                }
                r.push_back(stoi(num));
            }
        }

        else {
            if (grid[i+1][j-1] >='0' && grid[i+1][j-1] <='9') {
                string num = "";
                int j1 = j-1;
                while (j1>=0 && (grid[i+1][j1]>='0' && grid[i+1][j1] <='9' )) {
                    num.insert(num.begin(), grid[i+1][j1]);
                    j1--;
                }
                r.push_back(stoi(num));
            }
            if (grid[i+1][j+1] >='0' && grid[i+1][j+1] <='9') {
                string num = "";
                int j1 = j+1;
                while (j1<grid[0].size() && (grid[i+1][j1]>='0' && grid[i+1][j1] <='9' )) {
                    num += grid[i+1][j1];
                    j1++;
                }
                r.push_back(stoi(num));
            }
        }
    }

    if (grid[i][j+1] >='0' && grid[i][j+1] <='9') {
        string num = "";
        int j1 = j+1;
        while (j1<grid[0].size() && (grid[i][j1]>='0' && grid[i][j1] <='9' )) {
            num += grid[i][j1];
            j1++;
        }
        r.push_back(stoi(num));
    }
    if (grid[i][j-1] >='0' && grid[i][j-1] <='9') {
        string num = "";
        int j1 = j-1;
        while (j1>=0 && (grid[i][j1]>='0' && grid[i][j1] <='9' )) {
            num.insert(num.begin(), grid[i][j1]);
            j1--;
        }
        r.push_back(stoi(num));
    }

    return r;
    
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

    // vector<vector<int>> kha;

    for (int i=0; i<grid.size(); i++) {
        // int s=-1,e=-1, num = 0;
        // for (int j=0; j<grid[i].size(); j++) {
        //     if (s == -1 && grid[i][j] <= '9' && grid[i][j] >= '0') {
        //         s = j;
        //         num = grid[i][j] - '0';
        //     }

        //     else if (s != -1 && grid[i][j] <= '9' && grid[i][j] >= '0') {
        //         num = num*10 + (grid[i][j]-'0');

        //         if (j == grid[i].size()-1) {
        //             e = j;
        //         }
        //     }

        //     else if (s != -1 && (grid[i][j] > '9' || grid[i][j]<'0' )) {
        //         e = j-1;
        //     }

        //     // we found a number in grid
        //     if (e != -1) {
        //         // if (check(grid,s,e,i,num) == true) {
        //         //     sum += num;
        //         //     kha.push_back({i,s,e});
        //         // }
        //         s = -1;
        //         e = -1;
        //         num = 0;
        //     }
        // }

        for (int j=0; j<grid[0].size();j++) {

            if (grid[i][j] == '*') {
                vector<int> nums = findadj(i,j,grid);
                if (nums.size() == 1|| nums.size()== 0) continue; 
                ll prod = 1;
                for (int k=0; k<nums.size(); k++) {
                    prod = prod*nums[k];
                }

                sum += prod;
            }

        }
    }

    // for (int m=0; m<kha.size(); m++) {
    //     int i = kha[m][0];
    //     int s = kha[m][1];
    //     int e = kha[m][2];

    //     for (int j=s; j<=e; j++) {
    //         grid[i][j] = ' ';
    //     }
    // }
    // ofstream outfile;
    // outfile.open("out.txt");
    // for (int i=0; i<grid.size(); i++) {
    //     outfile<<grid[i]<<endl;
    // }
    cout<<sum<<endl;

    return 0;
}