#include <stdio.h>
typedef struct player
{
    int hp;
    int kill;
    int def;
    int sta;
    
}player;

typedef struct enemy
{
    int hp;
    int hurt;
    int sta;
    
}enemy;

void main()
{int input;
   player p1={100,0,0,5};
    enemy e1={500,10,2};
    printf("输入1开始游戏\n");
    scanf("%d",&input);
if(input==1)
    {printf("游戏开始\n");
    
    
        while(p1.hp>0&&e1.hp>0)
    {printf("请输入1攻击，输入2防御\n");
        scanf("%d",&input);
        if(input==1)
        {e1.hp-=66;
        p1.hp-=10;
        e1.sta--;
        p1.sta--;
        if(e1.hp<0)
            {printf("--------------------\n\n");
                printf("恭喜你！你赢了\n");}
        else{printf("敌人目前血量：%d\n",e1.hp);}
        
        }
        if(input==2)
        {e1.sta--;
        p1.sta--;
        p1.def++;
        }
        if(p1.hp<50)
        {printf("目前你的血量仅剩%d\n",p1.hp);}

    }
    }printf("金币+%d",p1.hp*114);
}