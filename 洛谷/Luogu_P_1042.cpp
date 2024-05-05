// WWWWWWWWWWW
//WWWWWWWWWWW
//LW
#include<iostream>

using namespace std;
int w,l;
int win[62503];
int main(){
    char c;
    //循环读入
    for(int i=1;cin>>c&&c!='E';i++){
        if(c=='W')win[i]=1;else win[i]=2;
    }
    //------11分制
    for(int i=1;1;i++){
        if(win[i]==1)w++;
        if(win[i]==2)l++;
        if(win[i]==0){
            cout<<w<<":"<<l<<endl<<endl;
            break;
        }
        if(abs(w-l)>=2){
            if(w>=11||l>=11){
                cout<<w<<':'<<l<<endl;
                 w=0,l=0;
            }
        }
        
    }
     w=0,l=0;

    //----21分制
    for(int i=1;1;i++){
        if(win[i]==1)w++;
        if(win[i]==2)l++;
        if(win[i]==0){
            cout<<w<<":"<<l;
            break;
        }
        if(abs(w-l)>=2){
            if(w>=21||l>=21){
                cout<<w<<':'<<l<<endl;
                w=0,l=0;
            }
        }
    }

}