/*Question : Construct the Array
Your goal is to find the number of ways to construct an array such that consecutive positions contain different values.

Specifically, we want to construct an array with  elements such that each element between  and , inclusive. We also want the first and last elements of the array to be  and .

Given ,  and , find the number of ways to construct such an array. Since the answer may be large, only find it modulo .




link to the question : https://www.hackerrank.com/challenges/construct-the-array/problem 


*/
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);
#define MOD 1000000007
/*
 * Complete the 'countArray' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 *  3. INTEGER x
 */


long countArray(int n, int k, int x) {
    // Return the number of ways to fill in the array.
    long onecount =1;
    long nonOne=0;
    for(int i=1;i<n;i++){
        long prevOne  = onecount;
        onecount=(nonOne*(k-1))%MOD;
        nonOne = (prevOne +(nonOne*(k-2))%MOD)%MOD;
        if(x==1){
            return onecount;
        } else{
            return nonOne;
        }
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    int x = stoi(first_multiple_input[2]);

    long answer = countArray(n, k, x);

    fout << answer << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
