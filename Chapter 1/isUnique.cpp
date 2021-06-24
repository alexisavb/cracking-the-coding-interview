#include<bits/stdc++.h>

using namespace std;

bool isUnique(string str){
    if(str.size() > 128) return false;
    bool ascii[128] = {false};
    for(int i = 0; i < str.size(); i++){
        if(ascii[str[i]]) return false;
        ascii[str[i]] = true;
    }
    return true;
}

int main(){
    cout << isUnique("abcdefg158r") << endl;
    cout << isUnique("abcdefg158ra") << endl;
    cout << isUnique("aaaaaaa") << endl;
    cout << isUnique("osnay") << endl;
    return 0;
}