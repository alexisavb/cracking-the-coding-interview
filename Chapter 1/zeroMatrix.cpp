#include <bits/stdc++.h>

using namespace std;

const int N = 4;

void print(int (&matrix)[N][N]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void zeroMatrix(int (&matrix)[N][N]){
    vector<pair<int,int> > coord;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
           if(matrix[i][j] == 0)
               coord.push_back(make_pair(i,j));
    
    for(int i = 0; i < coord.size(); i++){
        for(int j = 0; j < N; j++)
            matrix[j][coord[i].second] = 0;
        
        for(int j = 0; j < N; j++)
            matrix[coord[i].first][j] = 0;
    }
}

int main(){
    int matrix[N][N] = {1,2,3,0,7,8,9,10,4,0,5,6,7,10,9,10};
    print(matrix);
    zeroMatrix(matrix);
    print(matrix);
    return 0;
}