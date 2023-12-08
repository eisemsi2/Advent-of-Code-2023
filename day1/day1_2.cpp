#include<bits/stdc++.h>
#include<fstream>
#define vi vector<long long int>
#define ll long long

using namespace std; 

int main() {
    ifstream infile;
    infile.open("day1_1.txt");

    map<string,char> numbers = {{"one",'1'},{"two",'2'},{"three",'3'},{"four",'4'},{"five",'5'},{"six",'6'},{"seven",'7'},{"eight",'8'},{"nine",'9'}};   

    ll sum = 0;

    string line;

    while (getline(infile,line)) {
        int x = 0;

        bool got = false;
        for (int i=0; i<line.size() && got==false; i++) {
            if (line[i] <='9' && line[i]>='0') {
                x += (line[i] - '0')*10;
                break;
            }

            string num = "";
            for (int j=0; j<5 && i+j<line.size(); j++) {
                num += line[i+j];

                if (numbers.find(num) != numbers.end()) {
                    x += (numbers[num] - '0')*10;
                    got = true;
                    break;
                }
            }

        }

        got = false;
        for (int i=line.size()-1; i>=0 && got == false; i--) {
            if (line[i] <='9' && line[i]>='0') {
                x += (line[i] - '0');
                break;
            }

            string num = "";
            for (int j=0; j<5 && i-j>=0; j++) {
                num.insert(num.begin(),line[i-j]);

                if (numbers.find(num) != numbers.end()) {
                    x += (numbers[num] - '0');
                    got = true;
                    break;
                }
            }
        }

        sum += x;
    }

    cout<<sum<<endl;

    return 0;
}