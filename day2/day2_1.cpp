#include<bits/stdc++.h>
#include<fstream>
#include<sstream>
#define vi vector<long long int>
#define ll long long


using namespace std; 

int main() {
    ifstream infile;

    infile.open("day2_1.txt");

    ll ans = 0;

    string line;
    int i = 1;
    while (getline(infile,line)) {
        stringstream ss(line);

        string x;
        getline(ss,x,':');
        map<string, int> mx = {{"red",0},{"green",0},{"blue",0}};
        // bool isposs = true;

        while (getline(ss,x,';')) {
            stringstream s1(x);
            string y;
            while (getline(s1,y,',')) {
                int j=0;
                if (y[j] == ' ') j++;

                string z="";
                while (y[j] <='9' && y[j]>='0') {
                    z+=y[j];
                    j++;
                }
                int a = stoi(z);

                z  ="";
                j++;
                while (j<y.size()) {
                    z+=y[j];
                    j++;
                }

                if (a > mx[z]) {
                    mx[z] = a;
                }
            }
        }

        ll prod = mx["red"]*mx["blue"]*mx["green"];
        ans += prod;

        i++;

    }

    cout<<ans<<endl;

    return 0;
}