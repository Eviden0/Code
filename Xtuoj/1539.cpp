#include<iostream>

using namespace std;

/*



*/
int main(){
    /*
    1539 区间题意小写英文串去掉最短的一个区间，使得剩下的字母最多出现次数不超过k。
思路问题的核心是怎么快速知道字母最多出现次数。
显然，我们可以使用递推预处理得到数组 pre[i][j]表示前i个字母中含有多少个字母j。
这样，对于去掉的区间[l,r],那么剩下字符串中字母j有pre[n][j] - pre[r][j] + pre[l-1][j]。
1预处理pre数组2ans=n3枚举左端点l, 再枚举右端点r,保证r−l+1<ans4对于区间[l,r], 枚举字母，检查去掉区间内的字母后的最高频次是否超过k, 合法的话，那么更新答案。
时间复杂度 O(n 2 )
    */
    int T;cin>>T;
    while (T--)
    {   
        int zom[26]={0};
        /* code */
        int k;cin>>k;
        while (1)
        {
            char a=getchar();
            if(a=='\n')break;
            zom[a-'a']++;
            /* code */
        }
        

    }
    
}