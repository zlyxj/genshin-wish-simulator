#include<bits/stdc++.h>
using namespace std;
string up_5="芙宁娜";
string up_4[3]={"柯莱","北斗","夏洛蒂"};
string s5[7]={"迪卢克","迪希雅","琴","刻晴","七七","莫娜","提纳里"};
string s4[31]={"芭芭拉","班尼特","坎蒂斯","重云","多莉","迪奥娜","珐露珊","菲谢尔","菲米尼",
"五郎","卡维","绮良良","九条裟罗","久歧忍","莱依拉","琳妮特","米卡","凝光",
"诺艾尔","雷泽","罗莎莉亚","早柚","鹿野院平藏","砂糖","托马","香菱","行秋",
"辛焱","烟绯","瑶瑶","云堇"};
string rands4(){
    return s4[rand()%31];
}
string randup4(){
    return up_4[rand()%3];
}
string rands5(){
    return s5[rand()%7];
}
int main(){
    srand(time(0));
    cout<<"欢迎使用原神抽卡模拟器";
    cout<<"本期五星："<<up_5<<endl;
    cout<<"本期陪跑："<<up_4[0]<<' '<<up_4[1]<<' '<<up_4[2]<<endl;
    cout<<"常驻五星：\n";
    for(int i=0;i<7;i++)cout<<i+1<<'.'<<s5[i]<<endl;
    cout<<"常驻四星：\n";
    for(int i=0;i<31;i++)cout<<i+1<<'.'<<s4[i]<<((i%4==3)?'\n':' ');
    int cnt=0;
    int bd4=1;
    int bd5=1;
    int bdup=0;
    while(1){
        cnt++;
        cin.get();
        cout<<"第"<<cnt<<"抽：";
        int x=rand()%1000;
        if(bd4<10 && bd5<90){
            if(x<943){
                cout<<"抽到了[一把武器] 3*";
                bd4++;bd5++;
            }else if(x<994){
                int y=rand()%2;
                if(y)cout<<"抽到了["<<randup4()<<"] 4*";
                else{
                    if(rand()%49 <18)
                        cout<<"抽到了[一把武器] 4*";
                    else cout<<"抽到了["<<rands4()<<"] 4*";
                }
                bd4=1;bd5++;
            }else{
                if(bdup || (rand()%2)){cout<<"抽到了["<<up_5<<"] 5*";bdup=0;}
                else{cout<<"抽到了["<<rands5()<<"] 5*";bdup=1;}
                bd5=1;bd4=1;
            }
        }
        else if(bd4>=10 && bd5<90){
            bd4=1;
            if(x<994){
                int y=rand()%2;
                if(y)cout<<"抽到了["<<randup4()<<"] 4*";
                else{
                    if(rand()%49<18)
                        cout<<"抽到了[一把武器] 4*";
                    else cout<<"抽到了["<<rands4()<<"] 4*";
                }
                bd5++;
            }else{
                if(bdup || (rand()%2)){cout<<"抽到了["<<up_5<<"] 5*";bdup=0;}
                else{cout<<"抽到了["<<rands5()<<"] 5*";bdup=1;}
                bd5=1;
            }
        }else{
            if(bdup || (rand()%2)){cout<<"抽到了["<<up_5<<"] 5*";bdup=0;}
            else{cout<<"抽到了["<<rands5()<<"] 5*";bdup=1;}
            bd5=1;
            bd4++;
        }
        cout<<"  |  x="<<x<<" 四星保底"<<bd4-1<<" 五星保底"<<bd5-1<<" 大保底"<<bdup<<endl;
    }
}
