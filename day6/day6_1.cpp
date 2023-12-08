#include<bits/stdc++.h>
#include <fstream>
#define ll long long
using namespace std; 

int main() {
    vector<string> input;
    ifstream infile;

    infile.open("day6.txt");

    string line;
    getline(infile,line);

    vector<ll> times;
    string num = "";
    for (int i=0; i<line.size(); i++) {
        while (line[i] <= '9' && line[i]>='0') {
            num+=line[i];
            i++;
        }
        // if (num != "") {
        //     times.push_back(stoi(num));
        // }
    }
    times.push_back(stoll(num));
    

    getline(infile,line);

    vector<ll> dist;
    num = "";
    for (int i=0; i<line.size(); i++) {
        // string num = "";
        while (line[i] <= '9' && line[i]>='0') {
            num+=line[i];
            i++;
        }
        // if (num != "") {
        //     dist.push_back(stoi(num));
        // }
    }
    dist.push_back(stoll(num));
    ll prod = 1;
    for (int i=0; i<times.size(); i++) {
        ll ways = 0;
        ll min = 0;

        for (int j=0; j<times[i]; j++) {
            ll time = times[i] - j;
            ll dis = j*time;

            if (dis > dist[i]) {
                min = j;
                break;
            } 
        }

        ll max = 0;
        for (int j=times[i]; j>=0; j--) {
            ll time = times[i] - j;
            ll dis = j*time;

            if (dis > dist[i]) {
                max = j;
                break;
            } 
        }
        // cout<<min<<endl;
        // cout<<max<<endl;

        prod = prod*(max-min+1);
    }
    
    cout<<prod<<endl;

    return 0;
}