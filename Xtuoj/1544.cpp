#include<bits/stdc++.h>
using namespace std;
int main()
{
    //其实这里可以用 vector+二分查找 实现
    vector<int> pq;
    pq={3,10,1,2,4,5};
    sort(pq.begin(),pq.end());
    int tar=6;
    int index=lower_bound(pq.begin(),pq.end(),tar)-pq.begin();
    pq.insert(pq.begin()+index,tar);
    for(int i=0;i<pq.size();i++)cout<<pq[i]<<" ";
}