/*
Question : Merge Sort Code

Sort an array A using Merge Sort.
Change in the input array itself. So no need to return or print anything.

Input format :
First line of input will contain T number of test cases
First line of every input will contain a single integer N size of the input array.
second line of each input will contain N space-separated integers.

Output format :
For every test case print, array elements in increasing order (separated by space) in a separate line.

Constraints :
1 <= T <= 10
1 <= n <= 10^5

Sample Input 1 :
1
6 
2 6 8 5 4 3
Sample Output 1 :
2 3 4 5 6 8

Sample Input 2 :
1
5
2 1 5 2 3
Sample Output 2 :
1 2 2 3 5
*/
#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>& arr,int start,int mid,int end){
    vector<int>temp;
    int i=start,j=mid+1;
    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i++]);
        }else{
            temp.push_back(arr[j++]);
        }
    }
    while(i<=mid){
        temp.push_back(arr[i++]);
    }
    while(j<=end){
        temp.push_back(arr[j++]);
    }
    for(int i=start;i<=end;i++){
        arr[i]=temp[i-start];
    }
}
void mergeSort(vector<int>& arr,int start,int end){
    if(start<end){
    int mid = (start+end)/2;
    mergeSort(arr,start,mid);
    mergeSort(arr,mid+1,end);
    merge(arr,start,mid,end);
    }
}
int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        mergeSort(arr,0,n-1);
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
