#ifndef GOMOKU_H
#define GOMOKU_H

#define USERPORT 59630
#define DATAPORT 59631
#define RULEPORT 59632
#define BOARDSIZE 15
#define SOCKETSIZE 16

enum GAMEWORD {
    WIN,
    LOSE,
    LEGAL,
    ILLEGAL
};

enum PLAYER{
    BLACK,
    WHITE,
    NONE
};

void boardTypeCast1to2(char board1[BOARDSIZE*BOARDSIZE],int board2[BOARDSIZE][BOARDSIZE]);
void boardTypeCast2to1(char board1[BOARDSIZE*BOARDSIZE],int board2[BOARDSIZE][BOARDSIZE]);


#endif
