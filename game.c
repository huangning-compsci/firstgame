#include <stdio.h>
#include "fun.h"
#include<Windows.h>



void main()
{SetConsoleOutputCP(65001);
    int input;
 int win=-1;
 player p1;
 enemy  e1;   
 while(input!=-1)
   { printf("输入1开始游戏,输入-1结束游戏\n");
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
                    p1.sp--;
                    }
                
                    else{Rest(&p1.sp,1);}
                
                
                    if(e1.sp>0)
                    {GetHurt(p1.def,&p1.hp,e1.hurt);
                    e1.sp--;}

                    else{Rest(&e1.sp,0);}
                    
                    
                
                }
                
                 
                
            
            
            if(input==2)
            {
                if(p1.sp>=1)
                    {p1.def++;
                     printf("防御值+1，目前为\033[32m%d\033[0m\n",p1.def);
                     p1.sp--;
                    }
                else
                    Rest(&p1.sp,1);
                    
                if(e1.sp>0)
                    {GetHurt(p1.def,&p1.hp,e1.hurt*0.5);
                    e1.sp--;}
                        
                else
                    Rest(&e1.sp,0);
            }

                if (input==3)
                    {   if(p1.sp>0)
                            {if(dodge()){
                                p1.def+=3;
                                
                                printf("闪避成功，防御+3，目前防御值为：\033[33m%d\033[0m\n",p1.def);
                                        } 
                             p1.sp-=1;                               
                            }
                        else{Rest(&p1.sp,1);}
                            
                        if(e1.sp>0)    
                        {GetHurt(p1.def,&p1.hp,e1.hurt);
                            e1.sp-=1;}
                        else
                        {Rest(&e1.sp,0);}    
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
                    printf("\033[31m真遗憾！你输了\033[0m\n");
                    printf("\n--------------------\n");
                    win=0;
                    break;
                    }
                
            printf("敌人目前血量：\033[31m%.1f\033[0m\n",e1.hp);
            printf("敌人体力:%d\n你的体力:%d\n",e1.sp,p1.sp);

            if(p1.hp<100){
                        printf("***请注意：目前你的血量仅剩\033[31m%.1f\033[0m\n",p1.hp);
                        printf("--------------------\n");}
        }
    }
    if(win&&p1.hp>0)
    printf("金币+%.1f\n",p1.hp*114);


}
}