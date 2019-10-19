#include "tile.h"
#include "validation.h"
#include "chess.h"
#include "../interface/rsRetroChess.h"

validation *valid = new validation();

/*extern int count,turn;
extern QWidget *myWidget;
extern Tile *click1;
extern Tile *tile[8][8];
*/
void validate(Tile *temp,int c);
void disOrange();

Tile::Tile(QWidget* pParent, Qt::WindowFlags f) : QLabel(pParent, f)
{}

Tile::Tile(const QString& text, QWidget* pParent, Qt::WindowFlags f) : QLabel(text, pParent, f)
{}

void Tile::mousePressEvent(QMouseEvent *event)
{
    validate(++((RetroChessWindow*)m_chess_window)->count);
    std::string peer_id = ((RetroChessWindow*)m_chess_window)->mPeerId;
    rsRetroChess->chess_click(peer_id, this->row,this->col,((RetroChessWindow*)m_chess_window)->count);
}

void Tile::display(char elem)
{
	this->pieceName=elem;

	if(this->pieceColor && this->piece)
	{
		switch(elem)
		{
		case 'P':
			this->setPixmap(QPixmap(":/images/pawn_white.svg"));
			break;
		case 'R':
			this->setPixmap(QPixmap(":/images/rook_white.svg"));
			break;
		case 'H':
			this->setPixmap(QPixmap(":/images/knight_white.svg"));
			break;
		case 'K':
			this->setPixmap(QPixmap(":/images/king_white.svg"));
			break;
		case 'Q':
			this->setPixmap(QPixmap(":/images/queen_white.svg"));
			break;
		case 'B':
			this->setPixmap(QPixmap(":/images/bishop_white.svg"));
			break;
		}
	}

	else if(this->piece)
	{
		switch(elem)
		{
		case 'P':
			this->setPixmap(QPixmap(":/images/pawn_black.svg"));
			break;
		case 'R':
			this->setPixmap(QPixmap(":/images/rook_black.svg"));
			break;
		case 'H':
			this->setPixmap(QPixmap(":/images/knight_black.svg"));
			break;
		case 'K':
			this->setPixmap(QPixmap(":/images/king_black.svg"));
			break;
		case 'Q':
			this->setPixmap(QPixmap(":/images/queen_black.svg"));
			break;
		case 'B':
			this->setPixmap(QPixmap(":/images/bishop_black.svg"));
			break;
		}
	}
	else
		this->clear();
}

void Tile::validate(int c)
{
	Tile *temp = this;
	int retValue,i;

	if(c==1)
	{
        if(temp->piece && (temp->pieceColor==((RetroChessWindow*)m_chess_window)->turn))
		{
			//texp[max++]=temp->tileNum;
            retValue=((RetroChessWindow*)m_chess_window)->chooser(temp);

			if(retValue)
			{
                ((RetroChessWindow*)m_chess_window)->click1= new Tile();
				temp->setStyleSheet("QLabel {background-color: green;}");
                ((RetroChessWindow*)m_chess_window)->click1=temp;
			}
			else
			{
				//temp->setStyleSheet("QLabel {background-color: red;}");
                ((RetroChessWindow*)m_chess_window)->count=0;
			}
		}
		else
		{
			//qDebug()<<"Rascel, clicking anywhere";
            ((RetroChessWindow*)m_chess_window)->count=0;
		}
	}

	else
	{

        if(temp->tileNum==((RetroChessWindow*)m_chess_window)->click1->tileNum)
		{
            ((RetroChessWindow*)m_chess_window)->click1->tileDisplay();
            ((RetroChessWindow*)m_chess_window)->disOrange();
            ((RetroChessWindow*)m_chess_window)->max=0;
            ((RetroChessWindow*)m_chess_window)->count=0;
		}

        for(i=0; i<((RetroChessWindow*)m_chess_window)->max; i++)
		{
            if(temp->tileNum==((RetroChessWindow*)m_chess_window)->texp[i])
			{
                ((RetroChessWindow*)m_chess_window)->click1->piece=0;
				temp->piece=1;

                temp->pieceColor=((RetroChessWindow*)m_chess_window)->click1->pieceColor;
                temp->pieceName=((RetroChessWindow*)m_chess_window)->click1->pieceName;

                ((RetroChessWindow*)m_chess_window)->click1->display(((RetroChessWindow*)m_chess_window)->click1->pieceName);
                temp->display(((RetroChessWindow*)m_chess_window)->click1->pieceName);

                ((RetroChessWindow*)m_chess_window)->click1->tileDisplay();
				temp->tileDisplay();

                retValue=((RetroChessWindow*)m_chess_window)->check(((RetroChessWindow*)m_chess_window)->click1);
				/*
				if(retValue)
				{
					tile[wR][wC]->setStyleSheet("QLabel {background-color: red;}");
				}
				*/

                ((RetroChessWindow*)m_chess_window)->disOrange();

                ((RetroChessWindow*)m_chess_window)->max=0;

                ((RetroChessWindow*)m_chess_window)->turn=(((RetroChessWindow*)m_chess_window)->turn+1)%2;
                ((RetroChessWindow*)m_chess_window)->count=0;
			}

			else
                ((RetroChessWindow*)m_chess_window)->count=1;
		}
	}
}

void Tile::tileDisplay()
{

	if(this->tileColor)
		this->setStyleSheet("QLabel {background-color: rgb(120, 120, 90);}:hover{background-color: rgb(170,85,127);}");
	else
		this->setStyleSheet("QLabel {background-color: rgb(211, 211, 158);}:hover{background-color: rgb(170,95,127);}");
}


void Tile::setChessWindow(const QWidget *board)
{	m_chess_window = board;	}

const QWidget* Tile::getChessWindow() const
{	return m_chess_window;	}
