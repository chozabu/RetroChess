#include "NEMainpage.h"
#include "ui_NEMainpage.h"
//#include "services/p3NetExample.h"
#include "interface/rsNetExample.h"


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

void NEMainpage::on_pingAllButton_clicked()
{
	//p3service->ping_all();
	rsNetExample->ping_all();

}
