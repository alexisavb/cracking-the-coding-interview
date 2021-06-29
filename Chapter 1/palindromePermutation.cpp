#include <bits/stdc++.h>

using namespace std;

bool isPalindromePermutation(string str){
    map<char,int> mapping;
    map<char,int> :: iterator it;
    for(int i = 0; i < str.length(); i++){
        if(str[i] != ' '){
            if(str[i] >= 'A' && str[i] <= 'Z') mapping[str[i] + 32] ++;
            else mapping[str[i]]++;
        }
    }
    bool odd = false;
    for(it = mapping.begin(); it != mapping.end(); it++){
        if(it->second % 2 != 0){
            if(odd) return false;
            odd = true;
        }
    }
    return true;
}

int main(){
    cout << isPalindromePermutation("Tact coa") << endl;
    cout << isPalindromePermutation("Tact cob") << endl;
    cout << isPalindromePermutation("Tact ca") << endl;
    cout << isPalindromePermutation("Tact cb") << endl;
    return 0;
}