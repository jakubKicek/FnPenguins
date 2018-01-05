////////////////
// control.c  //
// by Jakub   //
////////////////

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "control.h"
#include "mapio.h"
#include "datastrc.h"

int count_points(int x,int y,char **map,int scores[6]);
void a_turn(int max_pl,int max_pg,int ***pngns_pos,char **map,int scores[6],int rows,int cols);  //single turn for all players, 1st player moves all of his pngns, then second one etc.

void upleft(int pl,int pg,int dist,int ***pngns_pos,int max_pl,int max_pg,char **map);
void left(int pl,int pg,int dist,int ***pngns_pos,int max_pl,int max_pg,char **map);
void downleft(int pl,int pg,int dist,int ***pngns_pos,int max_pl,int max_pg,char **map);
void upright(int pl,int pg,int dist,int ***pngns_pos,int max_pl,int max_pg,char **map);
void right(int pl,int pg,int dist,int ***pngns_pos,int max_pl,int max_pg,char **map);
void downright(int pl,int pg,int dist,int ***pngns_pos,int max_pl,int max_pg,char **map);

void move_penguin(int pl,int pg,int max_pl, int max_pg,int ***pngns_pos,char **map,int scores[6])//changing coordinates function
{
    int way,dist;//way is direction of movement and dist is distance (number of floes)
    bool cant_i=1;//useful variable in determining movement availability, if equals "1" the availability must be checked
    //max_pl is for max_players
    //max_pg is for max_penguins
    //pl is for crnt_player index
    //pg is for crnt_player's penguin index, shortcuts make it transparent
    int a=pngns_pos[pl][pg][0];
    int b=pngns_pos[pl][pg][1];
    printf("Your coordinates are (%d,%d). ",a,b);
    while(cant_i)
    {
        printf("In which direction and how far would you like to go?\n 1: up-left    2: up-right\n 3: left       4: right\n 5: down-left  6: down-right\n");
        printf("Direction: ");
        scanf("%d",&way);
        printf("Distance: ");
        scanf("%d",&dist);
        switch(way){
            case 1:  upleft(pl,pg,dist,pngns_pos,max_pl,max_pg,map);  cant_i=0; break;
            case 2:  upright(pl,pg,dist,pngns_pos,max_pl,max_pg,map);  cant_i=0; break;
            case 3:  left(pl,pg,dist,pngns_pos,max_pl,max_pg,map);  cant_i=0; break;
            case 4:  right(pl,pg,dist,pngns_pos,max_pl,max_pg,map);  cant_i=0; break;
            case 5:  downleft(pl,pg,dist,pngns_pos,max_pl,max_pg,map);  cant_i=0; break;
            case 6:  downright(pl,pg,dist,pngns_pos,max_pl,max_pg,map);  cant_i=0; break;
            default: printf("Sorry, %d is not valid direction.",way); cant_i=1;   break;
        }

    }
    int pts=count_points(a,b,map,scores);
    scores[pl]+=pts;
    map[a][b] = ' ';
    printf("Your penguin is successfully moving to (%d,%d).\n",x,y);
    pngns_pos[pl][pg][0]=x;
    pngns_pos[pl][pg][1]=y;
    if (map[x][y]=='1')
    {
        map[x][y]='a'+pl;
    }
    else if (map[x][y]=='2')
    {
        map[x][y]='A'+pl;
    }
    else if (map[x][y]=='3')
    {
        map[x][y]='U'+pl;
    }
}
void a_turn(int max_pl,int max_pg,int ***pngns_pos,char **map,int scores[6])
{
    int i=0,j=0,k=0;
    for(j;j<max_pg;j++)
    {
        for(i=0;i<max_pl;i++)
        {
            system("cls");
            printf("%Player %d's turn!\n",i);
            for(k=0;k<max_pl;k++)
            {
                printf("P%d: %d\t", k, scores[k]);
            }
            printf("\n");
            print_map(map,rows,cols);
            move_penguin(i,j,max_pl,max_pg,pngns_pos,map,scores);
        }
    }
}
int count_points(int x,int y,char **map,int scores[6])
{
    if (is_pos_correct(map[x][y])>0)
    {
        return 1 + (is_pos_correct(map[x][y])-1)/6;
    }
    return 0;
}

void placement(int max_pl,int max_pg,int ***pngns_pos,char **map,int rows,int cols)
{
    int x,y;
    int i=0,j=0;
    for(i=0;i<max_pl;i++)
    {
        for(j=0;j<max_pg;j++)
        {
            system("cls");
            print_map(map,rows,cols);
            printf("\nPlease, enter initial coordinates for player %d, penguin %d: ",i,j);
            scanf("%d",&x);
            scanf("%d",&y);
            pngns_pos[i][j][0]=x;
            pngns_pos[i][j][1]=y;
            map[x][y]='a'+i;
        }
    }
}



//PENGUINS' MOVEMENT:
void upleft(int pl,int pg,int dist,int ***pngns_pos,int max_pl,int max_pg,char **map)
{
    int x=pngns_pos[pl][pg][0];
    int y=pngns_pos[pl][pg][1];
    int i=1,j=0,k=0;
    bool b
    {
        for(i;i<dist;i++)
        {
            for(k;k<max_pl;k++)
            {
                for(j;j<max_pg;j++)
                {
                    if(((pngns_pos[k][j][0]==(x-i)&&pngns_pos[k][j][1]==(y-i)))||map[x-i][y-i]==' ') {pngns_pos[pl][pg][0]=(x-i+1); pngns_pos[pl][pg][1]=(y-i+1); printf("\nYour penguin encountered an obstacle.\n") return false; break;;}
                }
            }

        }
    }
    if(b)
    {
        pngns_pos[pl][pg][0]=(x-i);
        pngns_pos[pl][pg][1]=(y-i);
    }
}
void left(int pl,int pg,int dist,int ***pngns_pos,int max_pl,int max_pg,char **map)
{
    int x=pngns_pos[pl][pg][0];
    int y=pngns_pos[pl][pg][1];
    int i=1,j=0,k=0;
    bool b
    {
        for(i;i<dist;i++)
        {
            for(k;k<max_pl;k++)
            {
                for(j;j<max_pg;j++)
                {
                    if((pngns_pos[k][j][0]==(x-i)&&pngns[k][j][1]==y)||map[x-i][y]==' ') {pngns_pos[pl][pg][0]=(x-i+1); printf("\nYour penguin encountered an obstacle.\n") return false; break;;}
                }
            }

        }
    }
    if(b)
    {
        pngns_pos[pl][pg][0]=(x-i);
    }
}
void downleft(int pl,int pg,int dist,int ***pngns_pos,int max_pl,int max_pg,char **map)
{
    int x=pngns_pos[pl][pg][0];
    int y=pngns_pos[pl][pg][1];
    int i=1,j=0,k=0;
    bool b
    {
        for(i;i<dist;i++)
        {
            for(k;k<max_pl;k++)
            {
                for(j;j<max_pg;j++)
                {
                    if(((pngns_pos[k][j][0]==(x-i)&&pngns_pos[k][j][1]==(y+i)))||map[x-i][y+i]==' ') {pngns_pos[pl][pg][0]=(x-i+1); pngns_pos[pl][pg][1]=(y+i-1); b=0; printf("\nYour penguin encountered an obstacle.\n") return false; break;;}
                }
            }

        }
    }
    if(b)
    {
        pngns_pos[pl][pg][0]=(x-i);
        pngns_pos[pl][pg][1]=(y+i);
    }
}
void upright(int pl,int pg,int dist,int ***pngns_pos,int max_pl,int max_pg,char **map)
{
    int x=pngns_pos[pl][pg][0];
    int y=pngns_pos[pl][pg][1];
    int i=1,j=0,k=0;
    bool b
    {
        for(i;i<dist;i++)
        {
            for(k;k<max_pl;k++)
            {
                for(j;j<max_pg;j++)
                {
                    if(((pngns_pos[k][j][0]==(x+i)&&pngns_pos[k][j][1]==(y-i)))||map[x+i][y-i]==' ') {pngns_pos[pl][pg][0]=(x+i-1); pngns_pos[pl][pg][1]=(y-i+1); printf("\nYour penguin encountered an obstacle.\n") return false; break;;}
                }
            }

        }
    }
    if(b)
    {
        pngns_pos[pl][pg][0]=(x+i);
        pngns_pos[pl][pg][1]=(y-i);
    }
}
void right(int pl,int pg,int dist,int ***pngns_pos,int max_pl,int max_pg,char **map)
{
    int x=pngns_pos[pl][pg][0];
    int y=pngns_pos[pl][pg][1];
    int i=1,j=0,k=0;
    bool b
    {
        for(i;i<dist;i++)
        {
            for(k;k<max_pl;k++)
            {
                for(j;j<max_pg;j++)
                {
                    if(((pngns_pos[k][j][0]==(x+i)&&pngns_pos[k][j][1]==(y)))||map[x+i][y]==' ') {pngns_pos[pl][pg][0]=(x+i-1); pngns_pos[pl][pg][1]=(y); printf("\nYour penguin encountered an obstacle.\n") return false; break;;}
                }
            }

        }
    }
    if(b)
    {
        pngns_pos[pl][pg][0]=(x+i);
    }
}
void downright(int pl,int pg,int dist,int ***pngns_pos,int max_pl,int max_pg,char **map)
{
    int x=pngns_pos[pl][pg][0];
    int y=pngns_pos[pl][pg][1];
    int i=1,j=0,k=0;
    bool b
    {
        for(i;i<dist;i++)
        {
            for(k;k<max_pl;k++)
            {
                for(j;j<max_pg;j++)
                {
                    if(((pngns_pos[k][j][0]==(x+i)&&pngns_pos[k][j][1]==(y+i)))||map[x+i][y+i]==' ') {pngns_pos[pl][pg][0]=(x+i-1); pngns_pos[pl][pg][1]=(y+i-1); b=0; printf("\nYour penguin encountered an obstacle.\n") return false; break;;}
                }
            }

        }
    }
    if(b)
    {
        pngns_pos[pl][pg][0]=(x+i);
        pngns_pos[pl][pg][1]=(y+i);
    }
}
