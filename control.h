#ifndef CONTROL_H_INCLUDED
#define CONTROL_H_INCLUDED

#include <stdbool.h>
#include "datastrc.h"

void placement(int max_pl,int max_pg,int ***pngns_pos,char **map,int rows,int cols);
int count_points(int x,int y,char **map,int scores[6]);
void move_penguin(int x,int y,int max_pl, int max_pg,int ***pngns_pos,char **map,int scores[6],int rows,int cols);
void a_turn(int max_pl,int max_pg,int ***pngns_pos,char **map,int scores[6],int rows,int cols);

void upleft(int pl,int pg,int dist,int ***pngns_pos,int max_pl,int max_pg,char **map);
void left(int pl,int pg,int dist,int ***pngns_pos,int max_pl,int max_pg,char **map);
void downleft(int pl,int pg,int dist,int ***pngns_pos,int max_pl,int max_pg,char **map);
void upright(int pl,int pg,int dist,int ***pngns_pos,int max_pl,int max_pg,char **map);
void right(int pl,int pg,int dist,int ***pngns_pos,int max_pl,int max_pg,char **map);
void downright(int pl,int pg,int dist,int ***pngns_pos,int max_pl,int max_pg,char **map);

#endif // CONTROL_H_INCLUDED
