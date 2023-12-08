#include<bits/stdc++.h>
#include <fstream>
#include<sstream>

#define ll long long
using namespace std; 

int main() {
    // vector<string> input;
    ifstream infile;

    infile.open("day4.txt");

    vector<ll> power2;
    power2.push_back(1);

    for (int i=1; i<=32; i++) {
        power2.push_back(2*power2[i-1]);
    }

    vector<int> hashcards (300,0);
    vector<int> points (300,0);
    int card = 1;
    string line;
    ll sum = 0;
    while (getline(infile,line)) {
        stringstream ss(line);
        hashcards[card]++;
        map<int,int> hash;
        string x;
        getline(ss,x,':');

        getline(ss,x,'|');
        string y;
        getline(ss,y);
        y+=' ';

        string num = "";
        for (int i=0; i<x.size(); i++) {
            if (x[i] == ' ' && num!="") {
                hash[stoi(num)]++;
                num="";
            }
            else if (x[i] == ' ') continue;
            else {
                num+=x[i];
            }
        }

        num = "";
        ll thiscard = 0;
        int counter = 0;
        for (int i=0; i<y.size(); i++) {
           if (y[i] == ' ' && num!="") {
                if (hash.find(stoi(num)) != hash.end()) {
                    if (counter == 0) {
                        thiscard = 1;
                    }
                    else thiscard += thiscard;

                    counter++;
                }
                num="";
            }
            else if (y[i] == ' ') continue;
            else {
                num+=y[i];
            } 
        }

        for (int i=1; i<=counter; i++) {
            hashcards[card+i] += hashcards[card];  

            if (card+i >202) break;

        }
        
        points[card] = thiscard;
        card++;
    }

    for (int i=1; i<=202; i++) {
        sum += hashcards[i];
    }

    cout<<sum<<endl;

    return 0;
}