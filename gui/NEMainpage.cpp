#include "NEMainpage.h"
#include "ui_NEMainpage.h"

NEMainpage::NEMainpage(QWidget *parent) :
	MainPage(parent),
	ui(new Ui::NEMainpage)
{
	ui->setupUi(this);
}

NEMainpage::~NEMainpage()
{
	delete ui;
}
