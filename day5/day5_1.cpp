#include<bits/stdc++.h>
#include<fstream>
#define vi vector<long long ll>
#define ll long long

using namespace std; 

int main() {
    ifstream infile;
    infile.open("day5.txt");

    vector<ll> seeds;

    string s;
    getline(infile,s);

    for (ll i=0; i<s.size(); i++) {
        string num = "";
        while (s[i] <= '9' && s[i] >='0') {
            num+=s[i];
            i++;
        }
        if (num != "") seeds.push_back(stoll(num));
    }

    ofstream ofile;

    ofile.open("out.txt");

    getline(infile,s);
    getline(infile,s);

    map<pair<ll,ll>,pair<ll,ll>> sts;
    while (getline(infile,s)) {
        if (s == "") break;

        ll source;
        ll dest;
        ll range;

        ll i=0;
        string num = "";
        while (i<s.size() && (s[i]<='9' && s[i] >= '0')) {
            num+=s[i];
            i++;
        }
        dest = stoll(num);
        i++;
        num = "";
        while (i<s.size() && (s[i]<='9' && s[i] >= '0')) {
            num+=s[i];
            i++;
        }
        source = stoll(num);
        i++;
        num = "";
        while (i<s.size() && (s[i]<='9' && s[i] >= '0')) {
            num+=s[i];
            i++;
        }
        range = stoll(num);

        sts[{source,source+range-1}] = {dest,dest+range-1};
    }

    getline(infile,s);
    

    map<pair<ll,ll>,pair<ll,ll>> stf;
    while (getline(infile,s)) {
        if (s == "") break;

        ll source;
        ll dest;
        ll range;

        ll i=0;
        string num = "";
        while (i<s.size() && (s[i]<='9' && s[i] >= '0')) {
            num+=s[i];
            i++;
        }
        dest = stoll(num);
        i++;
        num = "";
        while (i<s.size() && (s[i]<='9' && s[i] >= '0')) {
            num+=s[i];
            i++;
        }
        source = stoll(num);
        i++;
        num = "";
        while (i<s.size() && (s[i]<='9' && s[i] >= '0')) {
            num+=s[i];
            i++;
        }
        range = stoll(num);

        stf[{source,source+range-1}] = {dest,dest+range-1};
    }

    getline(infile,s);
    // getline(infile,s);

    map<pair<ll,ll>,pair<ll,ll>> ftw;
    while (getline(infile,s)) {
        if (s == "") break;

        ll source;
        ll dest;
        ll range;

        ll i=0;
        string num = "";
        while (i<s.size() && (s[i]<='9' && s[i] >= '0')) {
            num+=s[i];
            i++;
        }
        dest = stoll(num);
        i++;
        num = "";
        while (i<s.size() && (s[i]<='9' && s[i] >= '0')) {
            num+=s[i];
            i++;
        }
        source = stoll(num);
        i++;
        num = "";
        while (i<s.size() && (s[i]<='9' && s[i] >= '0')) {
            num+=s[i];
            i++;
        }
        range = stoll(num);

        ftw[{source,source+range-1}] = {dest,dest+range-1};
    }

    getline(infile,s);
    // getline(infile,s);

    map<pair<ll,ll>,pair<ll,ll>> wtl;
    while (getline(infile,s)) {
        if (s == "") break;

        ll source;
        ll dest;
        ll range;

        ll i=0;
        string num = "";
        while (i<s.size() && (s[i]<='9' && s[i] >= '0')) {
            num+=s[i];
            i++;
        }
        dest = stoll(num);
        i++;
        num = "";
        while (i<s.size() && (s[i]<='9' && s[i] >= '0')) {
            num+=s[i];
            i++;
        }
        source = stoll(num);
        i++;
        num = "";
        while (i<s.size() && (s[i]<='9' && s[i] >= '0')) {
            num+=s[i];
            i++;
        }
        range = stoll(num);

        wtl[{source,source+range-1}] = {dest,dest+range-1};
    }

    getline(infile,s);
    // getline(infile,s);

    map<pair<ll,ll>,pair<ll,ll>> ltt;
    while (getline(infile,s)) {
        if (s == "") break;

        ll source;
        ll dest;
        ll range;

        ll i=0;
        string num = "";
        while (i<s.size() && (s[i]<='9' && s[i] >= '0')) {
            num+=s[i];
            i++;
        }
        dest = stoll(num);
        i++;
        num = "";
        while (i<s.size() && (s[i]<='9' && s[i] >= '0')) {
            num+=s[i];
            i++;
        }
        source = stoll(num);
        i++;
        num = "";
        while (i<s.size() && (s[i]<='9' && s[i] >= '0')) {
            num+=s[i];
            i++;
        }
        range = stoll(num);

        ltt[{source,source+range-1}] = {dest,dest+range-1};
    }

    getline(infile,s);
    // getline(infile,s);

    map<pair<ll,ll>,pair<ll,ll>> tth;
    while (getline(infile,s)) {
        if (s == "") break;

        ll source;
        ll dest;
        ll range;

        ll i=0;
        string num = "";
        while (i<s.size() && (s[i]<='9' && s[i] >= '0')) {
            num+=s[i];
            i++;
        }
        dest = stoll(num);
        i++;
        num = "";
        while (i<s.size() && (s[i]<='9' && s[i] >= '0')) {
            num+=s[i];
            i++;
        }
        source = stoll(num);
        i++;
        num = "";
        while (i<s.size() && (s[i]<='9' && s[i] >= '0')) {
            num+=s[i];
            i++;
        }
        range = stoll(num);

        tth[{source,source+range-1}] = {dest,dest+range-1};
    }

    getline(infile,s);
    // getline(infile,s);

    map<pair<ll,ll>,pair<ll,ll>> htl;
    while (getline(infile,s)) {
        if (s == "") break;

        ll source;
        ll dest;
        ll range;

        ll i=0;
        string num = "";
        while (i<s.size() && (s[i]<='9' && s[i] >= '0')) {
            num+=s[i];
            i++;
        }
        dest = stoll(num);
        i++;
        num = "";
        while (i<s.size() && (s[i]<='9' && s[i] >= '0')) {
            num+=s[i];
            i++;
        }
        source = stoll(num);
        i++;
        num = "";
        while (i<s.size() && (s[i]<='9' && s[i] >= '0')) {
            num+=s[i];
            i++;
        }
        range = stoll(num);

        htl[{source,source+range-1}] = {dest,dest+range-1};
    }

    // map<pair<ll,ll>,pair<ll,ll>> seedtoloc;

    // for (auto p : sts) {

    // }


   


    // ll minloc = INT_MAX;
    // vector<pair<ll,ll>> locations;
    
    // vector<ll> rangesoil;

    for (int i=0; i<seeds.size(); i++) {
        if (i%2 == 1) seeds[i] += seeds[i-1];
    }

    // for (int i=0; i<seeds.size(); i++) {
    //     ofile<<seeds[i]<<" ";
    // }
    // ofile<<endl<<endl;

    //  for (auto p : sts) {
    //     ofile<<p.first.first<<" "<<p.first.second<<"              "<<p.second.first<<" "<<p.second.second<<endl;
    // }
    // ofile<<endl<<endl;
    // for (auto p : stf) {
    //     ofile<<p.first.first<<" "<<p.first.second<<"              "<<p.second.first<<" "<<p.second.second<<endl;
    // }
    // ofile<<endl<<endl;
    // for (auto p : ftw) {
    //     ofile<<p.first.first<<" "<<p.first.second<<"              "<<p.second.first<<" "<<p.second.second<<endl;
    // }
    // ofile<<endl<<endl;
    // for (auto p : wtl) {
    //     ofile<<p.first.first<<" "<<p.first.second<<"              "<<p.second.first<<" "<<p.second.second<<endl;
    // }
    // ofile<<endl<<endl;
    // for (auto p : ltt) {
    //     ofile<<p.first.first<<" "<<p.first.second<<"              "<<p.second.first<<" "<<p.second.second<<endl;
    // }
    // ofile<<endl<<endl;
    // for (auto p : tth) {
    //     ofile<<p.first.first<<" "<<p.first.second<<"              "<<p.second.first<<" "<<p.second.second<<endl;
    // }
    // ofile<<endl<<endl;
    // for (auto p : htl) {
    //     ofile<<p.first.first<<" "<<p.first.second<<"              "<<p.second.first<<" "<<p.second.second<<endl;
    // }
    
    vector<ll> soils;

    for (int i=0; i<seeds.size()-1; i+=2) {
        for (auto pp : sts) {
            if (pp.first.first <= seeds[i] && pp.first.second >= seeds[i]) {
                if (pp.first.first <= seeds[i+1] && pp.first.second >= seeds[i+1]) {
                    soils.push_back(seeds[i]-pp.first.first + pp.second.first);
                    soils.push_back(seeds[i+1]-pp.first.first + pp.first.second);
                }
                else {
                    soils.push_back(seeds[i]-pp.first.first + pp.second.first);
                    soils.push_back(pp.second.second);
                    seeds.insert(seeds.begin()+i+1,{pp.first.second,pp.first.second+1});
                }
            }
        }
    }

    vector<ll> ferts;

    for (int i=0; i<soils.size()-1; i+=2) {
        for (auto pp : stf ) {
            if (pp.first.first <= soils[i] && pp.first.second >= soils[i]) {
                if (pp.first.first <= soils[i+1] && pp.first.second >= soils[i+1]) {
                    ferts.push_back(soils[i]-pp.first.first + pp.second.first);
                    ferts.push_back(soils[i+1]-pp.first.first + pp.first.second);
                }
                else {
                    ferts.push_back(soils[i]-pp.first.first + pp.second.first);
                    ferts.push_back(pp.second.second);
                    soils.insert(soils.begin()+i+1,{pp.first.second,pp.first.second+1});
                }
            }
        }
    }

    // for (int i=0; i<soils.size(); i++) {
    //     ofile<<soils[i]<<" ";
    // }

    vector<ll> waters;

    for (int i=0; i<ferts.size()-1; i+=2) {
        for (auto pp : ftw ) {
            if (pp.first.first <= ferts[i] && pp.first.second >= ferts[i]) {
                if (pp.first.first <= ferts[i+1] && pp.first.second >= ferts[i+1]) {
                    waters.push_back(ferts[i]-pp.first.first + pp.second.first);
                    waters.push_back(ferts[i+1]-pp.first.first + pp.first.second);
                }
                else {
                    waters.push_back(ferts[i]-pp.first.first + pp.second.first);
                    waters.push_back(pp.second.second);
                    ferts.insert(ferts.begin()+i+1,{pp.first.second,pp.first.second+1});
                }
            }
        }
    }

    vector<ll> lights;

    for (int i=0; i<waters.size()-1; i+=2) {
        for (auto pp : wtl ) {
            if (pp.first.first <= waters[i] && pp.first.second >= waters[i]) {
                if (pp.first.first <= waters[i+1] && pp.first.second >= waters[i+1]) {
                    lights.push_back(waters[i]-pp.first.first + pp.second.first);
                    lights.push_back(waters[i+1]-pp.first.first + pp.first.second);
                }
                else {
                    lights.push_back(waters[i]-pp.first.first + pp.second.first);
                    lights.push_back(pp.second.second);
                    waters.insert(waters.begin()+i+1,{pp.first.second,pp.first.second+1});
                }
            }
        }
    }
    
    vector<ll> temps;

    for (int i=0; i<lights.size()-1; i+=2) {
        for (auto pp : ltt ) {
            if (pp.first.first <= lights[i] && pp.first.second >= lights[i]) {
                if (pp.first.first <= lights[i+1] && pp.first.second >= lights[i+1]) {
                    temps.push_back(lights[i]-pp.first.first + pp.second.first);
                    temps.push_back(lights[i+1]-pp.first.first + pp.first.second);
                }
                else {
                    temps.push_back(lights[i]-pp.first.first + pp.second.first);
                    temps.push_back(pp.second.second);
                    lights.insert(lights.begin()+i+1,{pp.first.second,pp.first.second+1});
                }
            }
        }
    }

    vector<ll> hums;

    for (int i=0; i<temps.size()-1; i+=2) {
        for (auto pp : tth ) {
            if (pp.first.first <= temps[i] && pp.first.second >= temps[i]) {
                if (pp.first.first <= temps[i+1] && pp.first.second >= temps[i+1]) {
                    hums.push_back(temps[i]-pp.first.first + pp.second.first);
                    hums.push_back(temps[i+1]-pp.first.first + pp.first.second);
                }
                else {
                    hums.push_back(temps[i]-pp.first.first + pp.second.first);
                    hums.push_back(pp.second.second);
                    temps.insert(temps.begin()+i+1,{pp.first.second,pp.first.second+1});
                }
            }
        }
    }

    vector<ll> locs;

    for (int i=0; i<hums.size()-1; i+=2) {
        for (auto pp : htl ) {
            if (pp.first.first <= hums[i] && pp.first.second >= hums[i]) {
                if (pp.first.first <= hums[i+1] && pp.first.second >= hums[i+1]) {
                    locs.push_back(hums[i]-pp.first.first + pp.second.first);
                    locs.push_back(hums[i+1]-pp.first.first + pp.first.second);
                }
                else {
                    locs.push_back(hums[i]-pp.first.first + pp.second.first);
                    locs.push_back(pp.second.second);
                    hums.insert(hums.begin()+i+1,{pp.first.second,pp.first.second+1});
                }
            }
        }
    }

    ll minloc1 = 1E18;
    for (int i=0; i<locs.size(); i++) {
        if (locs[i] < minloc1) minloc1 = locs[i];
    }

    cout<<minloc1<<endl;


    

    return 0;
}