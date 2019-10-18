#ifndef TILE_H
#define TILE_H
#include <QLabel>
#include <QDebug>

class Tile: public QLabel
{
public:
    //Constructors
	Tile(QWidget* pParent=0, Qt::WindowFlags f=0);
	Tile(const QString& text, QWidget* pParent = 0, Qt::WindowFlags f = 0);

    //Methods
protected:
    void mousePressEvent(QMouseEvent *event);
public:
    void display(char elem);
    void tileDisplay();
    void validate(int c);

    //Fields
    int tileColor,piece,pieceColor,row,col,tileNum;
    char pieceName;
};

void validate_tile(int row, int col, int c);

#endif // TILE_H
