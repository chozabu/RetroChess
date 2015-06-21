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
	ui->listWidget->addItem("str");

}

NEMainpage::~NEMainpage()
{
	delete ui;
}

void NEMainpage::on_pingAllButton_clicked()
{
	rsNetExample->ping_all();

}


void NEMainpage::NeMsgArrived(const RsPeerId &peer_id, QString str)
{

	std::cout << "GUI got Packet from: " << peer_id;
	std::cout << " saying " << str.toStdString();
	std::cout << std::endl;
	QString output = QString::fromStdString(peer_id.toStdString());
	output+=": ";
	output+=str;
	ui->listWidget->addItem(output);
}

void NEMainpage::on_broadcastButton_clicked()
{
	rsNetExample->msg_all(ui->msgInput->text().toStdString());

}
