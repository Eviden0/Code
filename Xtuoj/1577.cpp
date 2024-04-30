// #include<iostream>
// #include<algorithm>

// using namespace std;

// int main(){
//     int t;cin>>t;
//     while (t--)
//     {
//         int a[10005]={0};
//         int n;
//         cin>>n;
//         for(int i=0;i<n;i++)scanf("%d",&a[i]);
//         int res=0;
//         sort(a,a+n);
//         for(int i=0;i<n;i++){
//             //最小的肯定要先于大的去
//             //因此小的都没去那么后面的肯定去不成了直接退出

//             if(a[i]>i+1)break;
//             // cout<<a[i]<<' ';
//             res++;
//         }
//         cout<<res<<endl;
//         /* code */
//     }
    
// }

#include<iostream>

using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;
        scanf("%d",&n);
        int cp=1;
        // int a[10005]={0};
        int ans=0;
        for(int i=0;i<n;i++){
            int x;
            
            scanf("%d",&x);
            //这种其实不行,因为即使出现在前面,那么也可以等到后面有人去的时候改变答案
            //即 具有记忆性
            //先排序为最好
            if(cp>=x){cp++;ans++;}
        }
        cout<<ans<<endl;
    }


}