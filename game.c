#include <stdio.h>
#include <stdlib.h>
typedef struct player
{
    float hp;
    float hurt;
    int sp;
    int def;
    
}player;

typedef struct enemy
{
    float hp;
    float hurt;
    int sp;
    int def;
    
}enemy;

int Initgame(player *p1,enemy *e1){
     *p1=(player){100,66,5,0};
     *e1=(enemy){500,27,2,2};
    return 1;
}

int GetHurt(int def,float *hp,float hurt)
{if(def*5>hurt)
    return 0;
else     
    {
        *hp=*hp-hurt+def*5;
        return 1;
    }    
}

int Fight(int *sp,float *hurt)
{
    (*sp)--;
    *hurt*=1.1;
}

int Rest(int *sp,int which)
{if(which ==0)
    *sp+=1;
if(which ==1)
    *sp+=2;
}


int dodge(player *p1,enemy *e1)
{
    int num=rand()%5+1;
 if(num>3){
    p1->def+=3;
    p1->sp-=1;
    printf("闪避成功，防御+3，目前防御值为：\033[33m%d\033[0m\n",p1->def);
    
    if(e1->sp>0)            //应该做一个体力判断函数，将体力更改的内容集合起来
        e1->sp-=1;
    else
        Rest(&e1->sp,0);    //这边存在一点问题，不够简洁
    
    return 1;
    }
else{if (e1->sp>0)
        {Fight(&e1->sp,&e1->hurt);
        GetHurt(p1->def,&p1->hp,e1->hurt);}
    else
        Rest(&e1->sp,0);
       
       p1->sp-=1;
        return 0;
} }







void main()
{int input;
 int win;
 player p1;
 enemy  e1;   
    printf("输入1开始游戏\n");
    scanf("%d",&input);
if(input==1)
    {printf("\n--------------------\n");
        printf("游戏开始\n");
     Initgame(&p1,&e1);
    
        while(p1.hp>0&&e1.hp>0)
        {
            printf("请输入1攻击，输入2防御,输入3闪避\n");
            scanf("%d",&input);
            printf("\n--------------------\n");
            if(input==1)
                {
                    if(p1.sp>=1)
                    {
                    GetHurt(e1.def,&e1.hp,p1.hurt);
                    Fight(&p1.sp,&p1.hurt);
                    }
                
                else{Rest(&p1.sp,1);}
                
                if(e1.sp>=1)
                    {
                    GetHurt(p1.def,&p1.hp,e1.hurt);
                    Fight(&e1.sp,&e1.hurt);
                    
                    }
                else{Rest(&e1.sp,0);}
                }
                
                 
                
            
            
            if(input==2){
                if(p1.sp>=1)
                    {p1.def++;
                     printf("防御值+1，目前为\033[32m%d\033[0m\n",p1.def);
                     p1.sp--;
                    }
                else
                    Rest(&p1.sp,1);
                    
                if(e1.sp>=1){
                    GetHurt(p1.def,&p1.hp,e1.hurt*0.5);
                    Fight(&e1.sp,&e1.hurt);
                    }    
                else
                    Rest(&e1.sp,0);
                        }

                if (input==3)
                    {if(p1.sp>0)
                        {dodge(&p1,&e1);}
                    else{Rest(&p1.sp,1);e1.sp-=1;}
                    }

                if(e1.hp<0)
                    {printf("\n--------------------\n");
                     printf("恭喜你！你赢了\n");
                     printf("\n--------------------\n");
                     win=1;
                    break;}
                  else if(p1.hp<0)
                    {
                    printf("\n--------------------\n");
                    printf("真遗憾！你输了\n");
                    printf("\n--------------------\n");
                    win=0;
                    break;
                    }
                else
                    {
                     printf("敌人目前血量：\033[31m%.1f\033[0m\n",e1.hp);}
                  
                        
            printf("敌人体力:%d\n你的体力:%d\n",e1.sp,p1.sp);

            if(p1.hp<100){
                        printf("***请注意：目前你的血量仅剩\033[31m%.1f\033[0m\n",p1.hp);
                        printf("--------------------\n");}
        }
    }
    if(win&&p1.hp>0)
    printf("金币+%.1f",p1.hp*114);


}