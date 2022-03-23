#include<bits/stdc++.h>
using namespace std;

int minCost1(int** input,int si,int sj,int ei,int ej){
    if(si==ei && sj==ej){
        return input[ei][ej];
    }
    if(si>ei || sj>ej){
        return INT_MAX;
    }
    int option1 = minCost1(input,si+1,sj,ei,ej);
    int option2 = minCost1(input,si+1,sj+1,ei,ej);
    int option3 = minCost1(input,si,sj+1,ei,ej);
    return input[si][sj] + min(option1,min(option2,option3));
}

int minCost2(int** input,int m,int n){
    int** output = new int*[m];
    for(int i=0;i<m;i++){
        output[i]=new int[n];
    }
    output[m-1][n-1]=input[m-1][n-1];
    for(int i=m-2;i>=0;i--){
        output[i][n-1]=output[i+1][n-1] + input[i][n-1];
    }
    for(int i=m-2;i>=0;i--){
        output[m-1][i]=output[m-1][i+1] + input[m-1][i];
    }
    for(int i=m-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            output[i][j]=input[i][j] + min(output[i+1][j],min(output[i+1][j+1],output[i][j+1]));
        }
    }
    return output[0][0];
}

int main(){
    int **input = new int*[3];
    input[0]=new int[3];
    input[1]=new int[3];
    input[2]=new int[3];
    input[0][0]=4;
    input[0][1]=3;
    input[0][2]=2;
    input[1][0]=1;
    input[1][1]=8;
    input[1][2]=3;
    input[2][0]=1;
    input[2][1]=1;
    input[2][2]=8;
    //cout<<minCost1(input,0,0,2,2)<<endl;
    cout<<minCost2(input,3,3)<<endl;
    delete [] input[0];
    delete [] input[1];
    delete [] input[2];
}