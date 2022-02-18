/*
Queston : Return Keypad Code

Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
The numbers and their corresponding codes are given below:
0: ""
1: ""
2: "abc"
3: "def"
4: "ghi"
5: "jkl"
6: "mno"
7: "pqrs"
8: "tuv"
9: "wxyz"
Return empty string for numbers 0 and 1.

Note:
1. The order of strings are not important.
2. The input number will have digits between: [2, 9].

Input Format :
First line of input will contain T number of test cases.
Each input consists of a single line containing an integer n.

Output Format :
For each test case, print all possible strings in different lines.
Constraints :
1 <= T <= 100
1 <= n <= 10^6
Sample Input:
1
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf
*/

#include<bits/stdc++.h>
using namespace std;
const vector<string>dialer ={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
vector<string> keypad(int n){
    if(n<=1){
        return {""};
    }
    vector<string>ans = keypad(n/10);
    vector<string>output;
    int index=n%10;
    for(char c:dialer[index]){
        for(string s : ans){
            output.push_back(s+c);
        }
    }
    return output;
}
int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string>ans = keypad(n);
        for(string s : ans){
            cout<<s<<endl;
        }
    }
    return 0;
}