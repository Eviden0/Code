#include<stdio.h>
char ch[2][8];
char ch1[2][8];
int main(){
    int a,n=1,flag1=0,flag2=0,flag3=0;
    
    n=1;
    int count=1;
    while(scanf("%d %s %s %s %s",&a,&ch[0],&ch[1],&ch1[0],&ch1[1])!=EOF){
        getchar();
        if(flag3==0){
        if(n==1){
            printf("Alice start game %d\n",count);
        }
        else{
            printf("Bob start game %d\n",count);
        }
    }
        flag3=1;
        int sum=0;
        for(int i=0;i<2;i++){
            if(ch[i][0]=='P')
            sum+=5;
            if(ch1[i][0]=='P'){
                sum+=5;
            }
           
        }
        if(sum==a){
            flag3=0;
            if(n==1){
                    printf("Alice win game %d\n",count);
                    flag1++;
                    
            }
            else{
                printf("Bob win game %d\n",count);
                flag2++;
            }
                count++;
        }
        else{
            if(n==1){
                printf("Change to Bob\n");
                n=2;
            }
            else{
                printf("Change to Alice\n");
                n=1;
            }
        }
        
    }
    printf("Game over %d:%d\n",flag1,flag2);
    
    return 0;
} 


//202205566502