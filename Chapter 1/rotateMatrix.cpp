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

void rotateMatrix(int (&matrix)[N][N]){
    int final = N - 1;
    for(int start = 0; start < N / 2; start++){
        for(int i = start; i < final - start; i++){
            int top = matrix[final - i][start];
            matrix[final - i][start] = matrix[final - start][final - i];
            matrix[final - start][final - i] = matrix[i][final - start];
            matrix[i][final - start] = matrix[start][i];
            matrix[start][i] = top;
        }
    } 
    print(matrix);
}


int main(){
    /*int matrix[N][N] = {1,2,3,4,5,6,7,8,9};
    print(matrix);
    rotateMatrix(matrix);*/
    int matrix[N][N] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    print(matrix);
    rotateMatrix(matrix);
    return 0;
}