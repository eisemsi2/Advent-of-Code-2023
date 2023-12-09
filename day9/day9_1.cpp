#include <bits/stdc++.h>
#include <fstream>
#define ll long long
using namespace std;

int main() {
    ifstream infile;
    infile.open("day9.txt");
    // ofstream ofile;
    // ofile.open("out.txt");
    ll sum = 0;
    string line;
    
    while(getline(infile,line)) {
        // ofile<<line<<endl;
        vector<ll> nums;
        for (int i=0; i<line.size(); i++) {
            string num = "";
            while (line[i] != ' ' && i != line.size() ) {
                num += line[i];
                i++;
            }
            nums.push_back(stoi(num));
        }

        reverse(nums.begin(), nums.end());

        int val = nums[nums.size()-1];
        vector<ll> lasts;
        // firsts.push_back(val);
        // int sp = 1;
        while(true) {
            vector<ll> diff;
            bool allzeros = true;
            for (int i=0; i<nums.size()-1; i++) {
                diff.push_back(nums[i+1]-nums[i]);
                if (diff[i] != 0) allzeros = false;
            }

            // ofile<<"    ";
            // for (int i=0; i<diff.size(); i++) {
            //     ofile<<diff[i]<<" ";
            // }
            // ofile<<endl;
            lasts.push_back(diff[diff.size()-1]);
            for (int i=0; i<nums.size()-1; i++) {
                nums[i] = diff[i];
            }
            nums.pop_back();
            // sp++;
            
            if (allzeros == true || nums.size() == 1) break;
        }

        // ofile<<endl<<endl;

        // int par = 0;
        // ll x = 0;
        
        for (int j=0; j<lasts.size(); j++) {
            val += lasts[j];
        }

        sum += val;

    }

    cout<<sum<<endl;
}