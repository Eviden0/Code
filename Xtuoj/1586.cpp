#include<iostream>
#include<algorithm>
using namespace std;
int num[10005];
long long mod=1000000007;
int main(){
    int t;cin>>t;
    while(t--){
        int ans=1;
        int n,k;scanf("%d %d",&n,&k);
        int fcnt_num=0;
        for(int i=0;i<n;i++){scanf("%d",&num[i]);}//scanf("%d",&num[i]);
        sort(num,num+n);
        int l=0,r=n-1;
        // for(int i=0;i<n;i++){cout<<num[i]<<' ';}
        //4 3
        //-3 -1 3 4 
        int flag=1;
        //分奇偶讨论!
        if(k%2!=0){
            if(num[r]<0)flag=-1;
            ans*=num[r];//最大的是一定要取的,无论正负
            r--;
            k--;
            // if(ans<0)flag=-1;
            // if(!ans){printf("0\n");break;}
        }
        
        // cout<<num[r]<<endl;
        // cout<<k<<' '<<flag<<endl;
        while(k){  
            long long l_ans=(long long)num[l]*(long long)num[l+1],r_ans=(long long)num[r]*(long long)num[r-1];//k=偶数时,每次取2直接滑过去
            if(l_ans*flag>r_ans*flag){
                //取左
                // cout<<l_ans*flag<<endl;
                ans=(ans%mod)*(l_ans%mod)%mod;
                l=l+2;
            }
            else {
                // cout<<r_ans*flag<<' '<<endl;
                ans=(ans%mod)*(r_ans%mod)%mod;
                r=r-2;
            }
            k-=2;
        }
        // cout<<ans<<endl;
        printf("%d\n",ans);
    }
}

        //哎哟,采用高手思路

        
        //判断什么时候结果一定为负
        // if(n-fcnt_num<k)
        // {
        //     sort(num,num+n,[](int a, int b) { return abs(a) > abs(b); });//绝对值大小排序
        //     for(int i=0;i<k;i++)ans*=num[i];
        //     cout<<ans%mod<<endl;
        // }
        // else {
        //     //一定是大于等于0的数了
        //     sort(num,num+n,[](int a, int b) { return a > b; });
        //     if(k%2==0){
        //         //直接选吗?

        //     }else {

        //     }
        //     if(ans>=0)cout<<ans%mod<<endl;
        //     else cout<<"error!"<<endl;
        // }
        // for(int i=0;i<n;i++)cout<<num[i]<<' ';
        // bool fl=true;
        // int cnt=0,fuindex=0,fucnt=0,ffindex=num[n-1];
        // for(int i=0;i<n;i++){
        //     if(cnt>=k){
        //         while(1&&i<n){
        //             if(num[i]>=0){ffindex=num[i];break;}
        //             i++;
        //             // if(i>=n){ffindex=num[i];break;}
        //         }
        //         break;
        //         }
        //     else {
        //         if(num[i]<0){fuindex=num[i];fucnt++;}
        //         ans*=num[i];
        //         cnt++;
        //     }
        // }
        // cout<<fuindex<<' '<<ffindex<<' '<<ans<<endl;
        // if(fucnt%2==0)cout<<ans%mod<<endl;
        // else cout<<ans/fuindex*ffindex%mod<<endl;

        /*思路不对,叉掉!*/