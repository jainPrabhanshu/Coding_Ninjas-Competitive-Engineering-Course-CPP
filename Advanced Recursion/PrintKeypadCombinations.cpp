/*
Question : Return Keypad Code

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

#include <iostream>
#include <string>
#include<vector>
using namespace std;
const vector<string> dialer = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void keypad(int num,string output){
    if(num==0){
        cout<<output<<endl;
        return ;
    }
    int index = num%10;
    if(index<=1){
        keypad(num/10,output);
    }
    string current = dialer[index];
    for(char c : current){
        keypad(num/10,c+output);
    }
}
void printKeypad(int num){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
    keypad(num,"");
}
