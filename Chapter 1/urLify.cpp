#include <bits/stdc++.h>

using namespace std;

string urlify(string str, int righLength){
    int spaces = 0;
    for(int i = 0; i < righLength; i++){
        if(str[i] == ' ')
            spaces++;
    }
    int index = righLength + (2 * spaces) - 1;
    for(int i = righLength - 1; i >= 0; i--){
        if(str[i] != ' '){
            str[index--] = str[i];
        }else{
            str[index--] = '0';
            str[index--] = '2';
            str[index--] = '%';
        }
    }
    return str;
}

int main(){
    cout << urlify("Mr John Smith    ",13) << endl;
    cout << urlify("Alexis Osnaya  ",13) << endl;
    return 0;
}