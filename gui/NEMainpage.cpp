#include "NEMainpage.h"
#include "ui_NEMainpage.h"
//#include "services/p3NetExample.h"
#include "interface/rsNetExample.h"


NEMainpage::NEMainpage(QWidget *parent, NetExampleNotify *notify) :
	MainPage(parent),
	mNotify(notify),
	ui(new Ui::NEMainpage)
{
	ui->setupUi(this);

	connect(mNotify, SIGNAL(NeMsgArrived(RsPeerId,QString)), this , SLOT(NeMsgArrived(RsPeerId,QString)));
	connect(mNotify, SIGNAL(NePaintArrived(RsPeerId,int,int)), this , SLOT(NePaintArrived(RsPeerId,int,int)));
	//ui->listWidget->addItem("str");
	connect(ui->paintWidget, SIGNAL(mmEvent(int,int)), this, SLOT(mmEvent(int,int)));

}

NEMainpage::~NEMainpage()
{
	delete ui;
}

void NEMainpage::mmEvent(int x, int y)
{
	rsNetExample->broadcast_paint(x,y);
}

void NEMainpage::on_pingAllButton_clicked()
{
	rsNetExample->ping_all();
	NeMsgArrived(rsPeers->getOwnId(),"ping");
}


void NEMainpage::NeMsgArrived(const RsPeerId &peer_id, QString str)
{

	std::cout << "GUI got Packet from: " << peer_id;
	std::cout << " saying " << str.toStdString();
	std::cout << std::endl;

	QString output = QString::fromStdString(rsPeers->getPeerName(peer_id));
	output+=": ";
	output+=str;
	ui->listWidget->addItem(output);
}
void NEMainpage::NePaintArrived(const RsPeerId &peer_id, int x, int y)
{

	std::cout << "GUI got Paint from: " << peer_id;
	std::cout << std::endl;

	ui->paintWidget->paintAt(x,y);
}

void NEMainpage::on_broadcastButton_clicked()
{
	rsNetExample->msg_all(ui->msgInput->text().toStdString());
	NeMsgArrived(rsPeers->getOwnId(),ui->msgInput->text());
	ui->msgInput->clear();
}
