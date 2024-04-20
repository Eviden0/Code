#include<iostream>
using namespace std;
int num[10010];
int n,m,k;
int main(){
    int t;
    // cin>>t;
    scanf("%d",&t);
    while (t--)
    {   
       
        /* code */
        // cin>>n>>m>>k;
        scanf("%d %d %d",&n,&m,&k);
        // int num[10010]={0},vis[10010]={0};
        int vis[10010]={0};
        for(int i=1;i<=n;i++)scanf("%d",&num[i]);
        //滑动窗口!
        //右指针先走
        int l=1,r=1;
        int cnt=0;
        bool flag=false;
        while (r<=n)
        {
            /* code */
            if(!vis[num[r]]){
                cnt++;
            }
            vis[num[r]]++;
            if(r-l==m-1){
                if(cnt!=k){
                    // cout<<"No"<<endl;
                    printf("No\n");
                    flag=true;
                    break;
                }
                else {
                    vis[num[l]]--;
                    if(!vis[num[l]])cnt--;
                    l++;
                }
            }
            r++;
        }
        if(!flag)
        printf("Yes\n");
    }
}