#include "NEMainpage.h"
#include "ui_NEMainpage.h"

//#include "services/p3RetroChess.h"
#include "interface/rsRetroChess.h"
#include <qjsondocument.h>

#include <iostream>
#include <string>
#include <QTime>
#include <QMenu>


NEMainpage::NEMainpage(QWidget *parent, RetroChessNotify *notify) :
	MainPage(parent),
	mNotify(notify),
	ui(new Ui::NEMainpage)
{
	ui->setupUi(this);

	connect(mNotify, SIGNAL(NeMsgArrived(RsPeerId,QString)), this , SLOT(NeMsgArrived(RsPeerId,QString)));
	connect(mNotify, SIGNAL(chessStart(RsPeerId)), this , SLOT(chessStart(RsPeerId)));
	    connect(ui->friendSelectionWidget, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(contextMenuFriendsList(QPoint)));
	//ui->listWidget->addItem("str");
	ui->friendSelectionWidget->start();
	ui->friendSelectionWidget->setModus(FriendSelectionWidget::MODUS_SINGLE);

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


void NEMainpage::chessStart(const RsPeerId &peer_id){

	create_chess_window(peer_id.toStdString(), 0);
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
	  QString output = QTime::currentTime().toString() +" ";
		output+= QString::fromStdString(rsPeers->getPeerName(peer_id));
		output+=": ";
		output+=vmap.value("message").toString();
		ui->listWidget->addItem(output);
	}else if (type == "chessclick"){
		int row = vmap.value("row").toInt();
		int col = vmap.value("col").toInt();
		int count = vmap.value("count").toInt();
		RetroChessWindow* rcw = activeGames.value(peer_id.toStdString());
		rcw->validate_tile(row,col,count);
	}else if (type == "chess_init"){
		create_chess_window(peer_id.toStdString(), 1);
	}else if (type == "chess_invite"){
		rsRetroChess->gotInvite(peer_id);
		mNotify->notifyChessInvite(peer_id);
	}else if (type == "chess_accept"){
		if (rsRetroChess->hasInviteTo(peer_id)){
			create_chess_window(peer_id.toStdString(), 1);
			rsRetroChess->acceptedInvite(peer_id);
		}
	}else{
		QString output = QTime::currentTime().toString() +" ";
		output+= QString::fromStdString(rsPeers->getPeerName(peer_id));
		output+=": ";
		output+=str;
		ui->listWidget->addItem(output);
	}

	{
		QString output = QTime::currentTime().toString() +" ";
		output+= QString::fromStdString(rsPeers->getPeerName(peer_id));
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

void NEMainpage::create_chess_window(std::string peer_id, int player_id){
	RetroChessWindow *rcw = new RetroChessWindow(peer_id, player_id);
	rcw->show();

	activeGames.insert(peer_id, rcw);
	ui->active_games->addItem(QString::fromStdString(peer_id));
}

void NEMainpage::on_playButton_clicked()
{
	//get peer
	FriendSelectionWidget::IdType idType;
	std::string fid = ui->friendSelectionWidget->selectedId(idType);
	//make_board();
	create_chess_window(fid, 0);

	QVariantMap map;
	map.insert("type", "chess_init");

	rsRetroChess->qvm_msg_peer(RsPeerId(fid),map);

	std::cout << fid;
}

void NEMainpage::contextMenuFriendsList(QPoint)
{
    QMenu contextMnu(this);

    int selectedCount = ui->friendSelectionWidget->selectedItemCount();

    FriendSelectionWidget::IdType idType;
    ui->friendSelectionWidget->selectedId(idType);

    QAction *action = contextMnu.addAction(QIcon(), tr("Play Chess"), this,  SLOT(on_playButton_clicked()));
    action->setEnabled(selectedCount);



    
    contextMnu.exec(QCursor::pos());
}
