#include<bits/stdc++.h>
#include <fstream>

using namespace std; 

int main() {
    ifstream infile;
    infile.open("day8.txt");

    string dir;
    getline(infile, dir);

    map<string, vector<string>> adj;
    string line;
    getline(infile,line);

    vector<string> endsA;

    while (getline(infile, line)) {
        int i=0;
        string p = ""; 
        while (line[i] != ' ') {
            p+=line[i];
            i++;
        }
        if (p[2] == 'A') endsA.push_back(p);
        i += 4;
        string l = "";
        while (line[i] != ',') {
            l += line[i];
            i++;
        }
        i+=2;
        string r = "";
        while (line[i] != ')') {
            r += line[i];
            i++;
        }

        adj[p].push_back(l);
        adj[p].push_back(r);
    }

    vector<int> steps;
    for (int k=0; k<endsA.size(); k++) {
        string node = endsA[k];

        int j = 0;
        int step = 0;
        while (node[2] != 'Z') {
            if (dir[j] == 'L')
                node = adj[node][0];
            else 
                node = adj[node][1];

            j++;
            step++;
            if (j == dir.size()) {
                j = 0;
            }
        }

        steps.push_back(step);
    }

    long long ans = 1;
    for (int k=0; k<steps.size(); k++) {
        ans = lcm(ans,steps[k]); 
    }
    cout<<ans<<endl;



    

    return 0;
}