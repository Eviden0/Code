str="""1539 区间
题意
小写英文串去掉最短的一个区间，使得剩下的字母最多出现次数不超过
k
。
思路
问题的核心是怎么快速知道字母最多出现次数。显然，我们可以使用递推预处理得到数组 pre[i][j]表示前
i
个字母中含有多少个字母
j
。这样，对于去掉的区间
[l,r]
,那么剩下字符串中字母j有pre[n][j] - pre[r][j] + pre[l-1][j]。
1
预处理pre数组
2
ans=n

3
枚举左端点
l
, 再枚举右端点
r
,保证
r−l+1<ans

4
对于区间
[l,r]
, 枚举字母，检查去掉区间内的字母后的最高频次是否超过
k
, 合法的话，那么更新答案。
时间复杂度 
O(n 
2
 )
"""

str=str.replace('\n','')
str=str.replace('。','。\n')
print(str)
# for i in str:
#     # print(i)
#     if(i==' 'or i=='\n'):
#         str.replace(i,'')
		# continue
    # print(i,end='')
    