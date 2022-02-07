/*
Question : Permutation and Palindrome
You are given a string s with length n. You should find a permutation P of numbers 1 through n such that if you apply this permutation on the string s, you will get a palindromic string.

The result of applying a permutation P on the string s is a string t with length n such that for each i (1 ≤ i ≤ n), the i-th character of t is given as as t[i] = s[Pi].

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains the string s.
Output
For each test case, print a single line. If it is impossible to find a valid permutation P, this line should contain a single integer -1. Otherwise, it should contain n space-separated integers P1, P2, ..., Pn.

If there are multiple valid permutations, you may print any one.

Constraints
1 ≤ n ≤ 105
s will consist only of lowercase English letters (i.e. characters 'a' through 'z')
Subtasks
Subtask #1 (20 points): 1 ≤ T, n ≤ 10

Subtask #2 (20 points): 1 ≤ T, n ≤ 100

Subtask #3 (60 points): 1 ≤ T ≤ 10

Example
Input

4
aa
baa
abc
abab

Output

1 2
2 1 3
-1
1 2 4 3
Explanation
Example case 1: The string t obtained using the identity permutation will have t[1] = s[1] and t[2] = s[2]. That means t = "aa", which is a palindrome.

Example case 2: The characters of the string t obtained by applying the permutation 2, 1, 3 are t[1] = s[2], t[2] = s[1] and t[3] = s[3]. Therefore, t = "aba", which is a palindrome.

Example case 3: There is no way to find a permutation P such that we can obtain a palindrome from s using it.

Example case 4: Applying the permutation 1, 2, 4, 3 on s results in t = "abba", which is a palindrome. Another permutation that you may apply is 2, 1, 3, 4; this results in t = "baab", which is also a palindrome.
*/

/*<------------Link for the Question------------->*/

https://www.codechef.com/problems/PERMPAL

#include<bits/stdc++.h>
using namespace std;
char getChar(int i){
    return (char)(i+97);
}
void printPalindromicString(string s){
    map<char,vector<int>>indexesMap;
    for(int i=0;i<s.length();i++){
        indexesMap[s[i]].push_back(i);
    }
    int odd_freq_count = 0;
    for(int i=0;i<26;i++){
        if((indexesMap[getChar(i)].size() % 2)!=0){
            odd_freq_count++;
        }
    }
    if(odd_freq_count>=2){
        cout<<"-1";
         return;
    }
    int ans[s.length()];
    int start =0 ;
    int end =s.length()-1;
    for(int i=0;i<26;i++){
        char currentChar=getChar(i);
        for(int j=0;j<indexesMap[currentChar].size();j+=2){
            if((indexesMap[getChar(i)].size()-j)==1){
                ans[s.length()/2]=indexesMap[currentChar][j];
                continue;
            }
            ans[start]=indexesMap[currentChar][j];
            ans[end]=indexesMap[currentChar][j+1];
            start++;
            end--;
        }
        for(int i=0;i<s.length();i++){
            cout<<ans[i]+1<<" ";
        }
        return;
    }
    
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        printPalindromicString(s);
        cout<<endl;
    }
    return 0;
}