/* Question : Find all the subsequences of a string */

#include<bits/stdc++.h>
using namespace std;

int subsequence(string input,string output[]){
    if(input.size()==0){
        output[0]="";
        return 1;
    }
    string smallString = input.substr(1);
    int smallOutputSize = subsequence(smallString,output);
    for(int i=0;i<smallOutputSize;i++){
        output[i+smallOutputSize]=input[0]+output[i];
    }
    return smallOutputSize*2;
}

int main(){
    string input;
    cin>>input;
    string* output =new string[1000];
    int count = subsequence(input,output);
    for(int i=0;i<count;i++){
        cout<<output[i]<<endl;
    }
    return 0;
}
