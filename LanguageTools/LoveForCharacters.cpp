/*
Question : Love for characters

Ayush loves the characters ‘a’, ‘s’, and ‘p’. He got a string of lowercase letters and he wants to find out how many times characters ‘a’, ‘s’, and ‘p’ occurs in the string respectively. Help him find it out.

Input:
First line contains an integer denoting length of the string.
Next line contains the string.

Constraints:
1<=n<=10^5
‘a’<= each character of string <= ‘z’

Output:
Three space separated integers denoting the occurrence of letters ‘a’, ‘s’ and ‘p’ respectively.

Sample Input:
6
aabsas
Sample output:
3 2 0
*/

#include <bits/stdc++.h>
using namespace std;
vector<int> characterLove(string s, int n, vector<int> &ans)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'a')
        {
            ans[0]++;
        }
        if (s[i] == 's')
        {
            ans[1]++;
        }
        if (s[i] == 'p')
        {
            ans[2]++;
        }
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> temp(3, 0);
    characterLove(s, n, temp);
    for (int i = 0; i < temp.size(); i++)
    {
        cout << temp[i] << " ";
    }
    return 0;
}
