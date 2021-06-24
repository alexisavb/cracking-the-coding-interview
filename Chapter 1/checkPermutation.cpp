#include<bits/stdc++.h>

using namespace std;

bool isPermutation(string str1, string str2){
    if(str1.size() != str2.size()) return false;
    map<char,int> mapping;
    map<char,int> :: iterator it;
    for(int i = 0; i < str1.size(); i++)
        mapping[str1[i]]++;
    for(int i = 0; i < str2.size(); i++){
        if(mapping.find(str2[i]) == mapping.end()) return false;
        mapping[str2[i]]--;
    }
    for(it = mapping.begin(); it != mapping.end(); it++)
        if(it->second != 0) return false;
    return true;
}

int main(){
    cout << isPermutation("abcde","abcd") << endl;
    cout << isPermutation("abcde","ecdba") << endl;
    cout << isPermutation("abcde","ecdb3") << endl;
    return false;
}