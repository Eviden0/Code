#include <bits/stdc++.h>
using namespace std;
// char a[4];
string a;
vector<int> pq;
int main()
{
    // int n1=3;
    pq[0] = 0;
    while (cin >> a)
    {
        // scanf("%s",a)!=EOF
        // scanf("%s",a);
        // cin>>a;
        // for(char i:a)cout<<i<<' ';
        // pq[0]=1;
        if (a[1] == 'u')
        {
            int n;
            scanf("%d", &n);
            // int index=lower_bound(pq.begin(),pq.end(),n)-pq.begin();

            // cout<<index<<endl;
            int index = 0;

            pq.insert(pq.begin() + index, n);
            index++;
        }
        else
        {
            // cout<<pq[(pq.size()+1)/2]<<endl;
            for (int i : pq)
                cout << i << ' ';
        }
    }
    // int t=3;
    // while(t--){
    //     string s;
    //     cin>>s;
    //     if(s[1]=='u'){
    //         int n;cin>>n;
    //         cout<<s<<' '<<n<<endl;
    //     }
    //     else cout<<s<<endl;
    // }
}