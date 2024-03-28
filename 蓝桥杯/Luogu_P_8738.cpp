#include<iostream>
#include<string>
using namespace std;
//输入的公元年份为不超过 
// 9999
// 9999 的正整数。
// 天干一共有十个，分别为：甲（jiǎ）、乙（yǐ）、丙（bǐng）、丁（dīng）、
// 戊 （wù）、己（jǐ）、庚（gēng）、辛（xīn）、壬（rén）、癸（guǐ）。

// 地支一共有十二个，分别为：子（zǐ）、丑（chǒu）、寅（yín）、卯（mǎo）、辰（chén）、
// 巳（sì）、午（wǔ）、未（wèi）、申（shēn）、酉（yǒu）、戌（xū）、亥（hài）。
//tiangang 2014
//dizhi 2020
string tiangan[10]={"jia","yi","bing","ding"
,"wu","ji","geng","xin","ren","gui"};
string dizhi[12]={"zi","chou","yin","mao","chen","si","wu","wei","shen","you","xu","hai"};
int main(){
    int n,in1,in2;
    cin>>n;
    if(n<2014)in1=(10-((2014-n)%10))%10;
    else in1=(n-2014)%10;
    if(n<2020)in2=(12-((2020-n)%12))%12;
    else in2=(n-2020)%12;
    // cout<<"tiangan:"<<tiangan[in1]<<"  "<<"dizhi:"<<in2<<dizhi[in2];
    cout<<tiangan[in1]<<dizhi[in2];
}