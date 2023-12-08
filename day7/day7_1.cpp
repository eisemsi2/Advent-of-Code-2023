#include<bits/stdc++.h>
#include <fstream>

using namespace std; 

bool cmp( vector<string> a, vector<string> b) {
    if (a[0] != b[0]) {
        return a[0]>b[0];
    }
    else {
        return a[1]>b[1];
    }
}

int main() {
    vector<string> input;
    ifstream infile;

    infile.open("day7.txt");
    int ans = 0;
    vector<vector<string>> ranks;
    vector<string> hands;
    vector<int> finalorder;
    int m = 0;
    vector<int> bids;
    string line;
    // map<char,int> stren = {{'A',14},{'K',13},{'Q',12},{'J',11},{'T',10},{'9',9},{'8',8},{'7',7},{'6',6},{'5',5},{'4',4},{'3',3},{'2',2}};

    while (getline(infile,line)) {
        string hand = "";
        string bid = "";

        int i=0;
        int wildcards = 0;
        while (line[i] != ' ') {
            if (line[i] == 'T') hand += 'A';
            else if (line[i] == 'J') {
                hand += '1';
                wildcards++;
            }
            else if (line[i] == 'Q') hand +='C';
            else if (line[i] == 'K') hand += 'D';
            else if (line[i] == 'A') hand += 'E';
            else hand += line[i];
            i++;
        }
        i++;
        while (i < line.size()) {
            bid += line[i];
            i++; 
        }
        bids.push_back(stoi(bid));
        hands.push_back(hand);
        // int rank;

        map<char,int> cards;
        for (int i=0; i<hand.size(); i++) {
            if (hand[i] == '1') continue;
            cards[hand[i]]++;
        }

        char maxoccr = '.';
        int maxo = -1;
        for (auto p:cards) {
            if (p.second > maxo) {
                maxo = p.second;
                maxoccr = p.first;
            }
        }

        cards[maxoccr]+=wildcards;


        // int rank;
        if (cards.size() == 1) {
            ranks.push_back({to_string(7),hand,to_string(m)});
        }
        else if (cards.size() == 2) {
            for (auto p : cards) {
                if (p.second == 1) {
                    ranks.push_back({to_string(6),hand,to_string(m)});
                    break;
                }
                if (p.second == 2) {
                    ranks.push_back({to_string(5),hand,to_string(m)});
                    break;
                }
            }
        }
        else if (cards.size() == 3) {
            for (auto p : cards) {
                if (p.second == 3) {
                    ranks.push_back({to_string(4),hand,to_string(m)});
                    break;
                }
                if (p.second == 2) {
                    ranks.push_back({to_string(3),hand,to_string(m)});
                    break;
                }
            }
        }
        else if (cards.size() == 4) ranks.push_back({to_string(2),hand,to_string(m)});
        else ranks.push_back({to_string(1),hand,to_string(m)});

        // ans += rank*stoi(bid);
        m++;
        
    }

    sort(ranks.begin(), ranks.end(),cmp);

    

    for (int i=0; i<ranks.size(); i++) {
        ans += (ranks.size() - i)*bids[stoi(ranks[i][2])];
    }


    cout<<ans<<endl;

    return 0;
}