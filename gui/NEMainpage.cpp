#include "NEMainpage.h"
#include "ui_NEMainpage.h"
//#include "services/p3RetroChess.h"
#include "interface/rsRetroChess.h"
#include<qjsondocument.h>


NEMainpage::NEMainpage(QWidget *parent, RetroChessNotify *notify) :
	MainPage(parent),
	mNotify(notify),
	ui(new Ui::NEMainpage)
{
	ui->setupUi(this);

	connect(mNotify, SIGNAL(NeMsgArrived(RsPeerId,QString)), this , SLOT(NeMsgArrived(RsPeerId,QString)));
	connect(mNotify, SIGNAL(NePaintArrived(RsPeerId,int,int)), this , SLOT(NePaintArrived(RsPeerId,int,int)));
	//ui->listWidget->addItem("str");
	connect(ui->paintWidget, SIGNAL(mmEvent(int,int)), this, SLOT(mmEvent(int,int)));
	make_board();

}

NEMainpage::~NEMainpage()
{
	delete ui;
}

void NEMainpage::mmEvent(int x, int y)
{
	rsRetroChess->broadcast_paint(x,y);
}

void NEMainpage::on_pingAllButton_clicked()
{
	rsRetroChess->ping_all();
	NeMsgArrived(rsPeers->getOwnId(),"ping");
}


void NEMainpage::NeMsgArrived(const RsPeerId &peer_id, QString str)
{
	QJsonDocument jdoc = QJsonDocument::fromJson(str.toUtf8());
	QVariantMap vmap = jdoc.toVariant().toMap();
	std::cout << "GUI got Packet from: " << peer_id;
	std::cout << " saying " << str.toStdString();
	std::cout << std::endl;
	QString type = vmap.value("type").toString();
	if (type == "chat"){
		QString output = QString::fromStdString(rsPeers->getPeerName(peer_id));
		output+=": ";
		output+=vmap.value("message").toString();
		ui->listWidget->addItem(output);
	}else if (type == "paint"){
		int x =vmap.value("x").toInt();
		int y =vmap.value("y").toInt();
		NePaintArrived(peer_id,x,y);
	}else{
		QString output = QString::fromStdString(rsPeers->getPeerName(peer_id));
		output+=": ";
		output+=str;
		ui->listWidget->addItem(output);
	}

	{
		QString output = QString::fromStdString(rsPeers->getPeerName(peer_id));
		output+=": ";
		output+=str;
		ui->netLogWidget->addItem(output);
	}
}
void NEMainpage::NePaintArrived(const RsPeerId &peer_id, int x, int y)
{

	std::cout << "GUI got Paint from: " << peer_id;
	std::cout << std::endl;

	ui->paintWidget->paintAt(x,y);
}

void NEMainpage::on_broadcastButton_clicked()
{
	rsRetroChess->msg_all(ui->msgInput->text().toStdString());
	NeMsgArrived(rsPeers->getOwnId(),ui->msgInput->text());
	ui->msgInput->clear();
}
