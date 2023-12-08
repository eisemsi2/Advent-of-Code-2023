#include<bits/stdc++.h>
#include <fstream>

using namespace std; 

int main() {
    vector<string> input;
    ifstream infile;

    infile.open("day1_1.txt");

    string line;
    long long sum = 0;
    while (getline(infile,line)) {
        int x = 0;
        for (int i=0; i<line.size(); i++) {
            if (line[i] <='9' && line[i]>='0') {
                x += (line[i] - '0')*10;
                break;
            }
        }
        for (int i=line.size()-1; i>=0; i--) {
            if (line[i] <='9' && line[i]>='0') {
                x += (line[i] - '0');
                break;
            }
        }

        sum += x;
    }
    cout<<sum<<endl;

    return 0;
}