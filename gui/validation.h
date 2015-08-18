#ifndef VALIDATION_H
#define VALIDATION_H
#include "tile.h"


class validation
{
    int flag,retVal;

public:
    validation();
    int chooser(Tile *temp);
    int validateBishop(Tile *temp);
    int validateQueen(Tile *temp);
    int validateKing(Tile *temp);
    int validateHorse(Tile *temp);
    int validateRook(Tile *temp);
    int validatePawn(Tile *temp);
    void orange();
    int check(Tile *temp);
};

#endif // VALIDATION_H
