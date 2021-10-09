#ifndef LIFE_H_INCLUDED
#define LIFE_H_INCLUDED
void flife()
{
    if(life>90 || life==100 )
    {
        al_draw_bitmap(life0, 5, 5, NULL);
    }
    else if(life>80 && life<=90)
    {
        al_draw_bitmap(life1, 5, 5, NULL);
    }
    else if(life>70 && life<=80)
    {
        al_draw_bitmap(life2, 5, 5, NULL);
    }
    else if(life>60 && life<=70)
    {
        al_draw_bitmap(life3, 5, 5, NULL);
    }
    else if(life>50 && life<=60)
    {
        al_draw_bitmap(life4, 5 , 5, NULL);
    }
    else if(life>40 && life <=50)
    {
        al_draw_bitmap(life5, 5, 5, NULL);
    }
    else if(life>30 && life<=40)
    {
        al_draw_bitmap(life6, 5, 5, NULL);
    }
    else if(life>20 && life<=30)
    {
        al_draw_bitmap(life7, 5, 5, NULL);
    }
    else if(life>10 && life<=20)
    {
        al_draw_bitmap(life8, 5, 5, NULL);
    }
    else if(life>0 && life<=10)
    {
        al_draw_bitmap(life9, 5, 5, NULL);
    }
    else
    {
        al_draw_bitmap(life10, 5, 5, NULL);
    }
}


#endif // LIFE_H_INCLUDED
