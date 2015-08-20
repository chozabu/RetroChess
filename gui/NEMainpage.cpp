#include "NEMainpage.h"
#include "ui_NEMainpage.h"
//#include "services/p3RetroChess.h"
#include "interface/rsRetroChess.h"
#include<qjsondocument.h>
#include <iostream>
#include <string>


NEMainpage::NEMainpage(QWidget *parent, RetroChessNotify *notify) :
	MainPage(parent),
	mNotify(notify),
	ui(new Ui::NEMainpage)
{
	ui->setupUi(this);

	connect(mNotify, SIGNAL(NeMsgArrived(RsPeerId,QString)), this , SLOT(NeMsgArrived(RsPeerId,QString)));
	//ui->listWidget->addItem("str");
	ui->widget->start();
	ui->widget->setModus(FriendSelectionWidget::MODUS_SINGLE);

}

NEMainpage::~NEMainpage()
{
	delete ui;
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
	}else if (type == "chessclick"){
		int row = vmap.value("row").toInt();
		int col = vmap.value("col").toInt();
		int count = vmap.value("count").toInt();
		tempwindow->validate_tile(row,col,count);
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

void NEMainpage::on_broadcastButton_clicked()
{
	rsRetroChess->msg_all(ui->msgInput->text().toStdString());
	NeMsgArrived(rsPeers->getOwnId(),ui->msgInput->text());
	ui->msgInput->clear();
}

void NEMainpage::on_playButton_clicked()
{

	//make_board();

	RetroChessWindow *rcw = new RetroChessWindow();
	tempwindow = rcw;
	rcw->show();
	FriendSelectionWidget::IdType idType;
	std::string fid = ui->widget->selectedId(idType);
	rsRetroChess->set_peer(RsPeerId(fid));
	std::cout << fid;
}
