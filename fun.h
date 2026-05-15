#pragma once

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

int Initgame(player *p1,enemy *e1);
int GetHurt(int def,float *hp,float hurt);
int Fight(int *sp,float *hurt);
int Rest(int *sp,int which);
int dodge();