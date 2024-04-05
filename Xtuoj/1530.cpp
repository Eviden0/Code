#include<stdio.h>
int main(){

    
    char c[4][5]={'0'};
    int As=0,Bs=0;
    //三局两胜
    int index=1;
    int flag=0;//flag=0,默认alice开
    //各自的得分
    //初始
    int tarscore;
    int stop=0;
    // printf("Alice start game %d\n",index);
    while (scanf("%d %s %s %s %s",&tarscore,c[0],c[1],c[2],c[3])!=EOF)//以文件输出结尾作为结尾!
    {   
        // getchar();
        // if(){
        //     stop=1;
        // }
        if(stop==0){
            if(flag==0){
                printf("Alice start game %d\n",index);
            }
            else{
                printf("Bob start game %d\n",index);
            }
        }
        stop=1;
        int score=0;
        for(int i=0;i<4;i++){
            if(c[i][0]=='P')score+=5;
            
        }
        // printf("%d---%d\n",tarscore,score); 
        //没有出现正确的分数时一直互相喊,知道出现为止!
        if(score==tarscore){
            if(flag==0){
                As+=1;
                printf("Alice win game %d\n",index);
                index++;
                stop=0;
                // if(stop!=1)
                // printf("Alice start game %d\n",index);
            }
            else {
                Bs+=1;
                printf("Bob win game %d\n",index);
                index++;
                stop=0;
                // if(stop!=1)
                // printf("Bob start game %d\n",index);
            }
            

        }
        else {
            flag=flag^1;
            if(flag==1)printf("Change to Bob\n");
            else printf("Change to Alice\n");
        }
        // 先赢两局的情况要特判断
        //貌似这题没有结局,只是判断当局情况!
        // if(stop==1){
        //     printf("Game over %d:%d",As,Bs);
        //     break;
        // }
    }
    printf("Game over %d:%d\n",As,Bs);
}
