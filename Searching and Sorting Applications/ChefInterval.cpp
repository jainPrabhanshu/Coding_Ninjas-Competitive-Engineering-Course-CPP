#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main (){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<pair<int,int>>intervals;
        for(int i=0;i<n;i++){
            int start ,end;
            cin >> start >>end;
            intervals.push_back(make_pair(start,end));
            sort(intervals.begin(),intervals.end());
            while(m--){
                int currTime;
                cin>>currTime;
                int position = lower_bound(intervals.begin(),intervals.end(),make_pair(currTime,0))-intervals.begin();
                //When currTime matches with zeroth position
                if(position==0){
                    int ans = intervals[0].first-currTime;
                    cout<<ans<<endl;
                }else{
                    int ans = -1;
                    //comparinmg with just before the position
                    if(intervals[position-1].second>currTime){
                        int ans = 0;
                    }else if(intervals.size()>currTime){
                        //position lies between intervals
                        ans = intervals[position].first-currTime;
                    }
                    cout<<ans<<endl;
                }
            }

        }
    }
}