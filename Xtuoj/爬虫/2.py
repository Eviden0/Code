with open('3.txt','r') as f:
    for i in f:

        s1='/练习3/'+i.replace('\n','')
        s2=s1.split('/')[-1][:-5]
        tar=f'''
            <tr>
                <td><a href="{s1}">{s2}</a></td>
            </tr>
            '''
        print(tar)
# a='/练习2/1584_极大极小堆.html'

# b=a.split('/')[-1][:-5]
# # st=f'''
# # <tr>
# # <td><a href="{a}">{b}/a></td>
# # </tr>
# # '''
# print(b)