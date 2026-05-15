#include "fun.h"
#include <stdlib.h>

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
    *hurt*=1.05;
}

int Rest(int *sp,int which)
{if(which ==0)
    *sp+=1;
if(which ==1)
    *sp+=2;
}


int dodge()
{
    int num=rand()%5+1;
 if(num>3){
    
                           
        
        
    
    return 1;
    }
return 0;
 }
