#include <bits/stdc++.h>

using namespace std;

bool oneWay(string str, string str2){
    int less = str.length() - str2.length();
    if(abs(less) > 1) return false;
    map<char,int> mapping;
    map<char,int> :: iterator it;
    int count = 0;

    for(int i = 0; i < str.length(); i++)
        mapping[str[i]]++;
    
    for(int i = 0; i < str2.length(); i++)
        mapping[str2[i]]--;

    for(it = mapping.begin(); it != mapping.end(); it++)
        if(it->second != 0) count++;
    
    return (count == 1 || count == 2) ? true : false;
}

int main(){
    cout << oneWay("pale","ple") << endl;
    cout << oneWay("pale","pleewr") << endl;
    cout << oneWay("pales","pale") << endl;
    cout << oneWay("pale","bale") << endl;
    cout << oneWay("pale","bake") << endl;
    return 0;
}