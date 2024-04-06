#include<iostream>

using namespace std;

/*
---------如何理解这两种搜索的区别呢,主要是while条件的不同
---------如果是搜具体的某个数(一般是直接搜到答案),也就是直接搜二分时mid的值,直接返回mid
---------但是如果不是搜具体的某个数,而是搜索一段区间,即返回的不是mid而是left或right这种边界
---------那么此时返回的状态其实是最后一次搜索结果的前一个(或者几个)状态 

---------如何理解这个left+1<right
-----这里的'1'可以表示left和right之间相差多少时退出循环!
-----除了搜最后一次外可以while退出时写等号,其他时候维护距离不能写=!
-----这里的传参传的是有效数组的后一位,如果刚好传有效数组那么长,搜不到当解是最后一个的情况
-----因此尽量开大一点点数组

*/
bool check1(int index,int tar){
    if(index < tar)return true;
    return false;
}
bool check2(int index,int tar){
    if(index > tar)return true;
    return false;
}
int binasearch_lower(int n[],int size,int tar){
    //0 1 | 3, 3, 3, 5, 7
    //看这个分界线
    int left=0,right=size;
    while (left+1<right)
    {
        /* code */
        int mid = (left+right)/2;
        if(check1(n[mid],tar)){
            left=mid;
        }else right=mid;
    }
    if(n[right]==tar)return right;
    else return -1; 
}

int binasearch_upper(int n[],int size,int tar){
    //1 , 3, 3, 3,| 5, 7
    //看这个分界线
    int left=0,right=size;
    while (left+1<right)
    {
        /* code */
        int mid = (left+right)/2;
        if(check2(n[mid],tar)){
            right=mid;
        }else left=mid;
    }
    if(n[left]==tar)return left;
    else return -1;
    // return 0;
}
bool testsearch(int n[],int size,int tar){
    int l=0,r=size;
    while(l+0<=r){
        int mid = (l+r)/2;
        if(n[mid]==tar)return true;
        else{
            if(n[mid]>tar)r=mid-1;
            else l=mid+1;
        }
    }
    return false;
}

int main(){
    int a[12]={0,1 ,3, 3, 3, 5, 7, 9, 11, 13, 15};
    int b[8]={1,2,3,4,5,6,7,8};
    cout<<binasearch_lower(a,12,9)<<' '<<binasearch_upper(a,12,9)<<endl;
    cout<<testsearch(b,8,4);
}