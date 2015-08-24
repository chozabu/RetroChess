

#include <QToolButton>
#include <QPropertyAnimation>
#include <QIcon>
#include <QLayout>


#include "interface/rsRetroChess.h"

#include "gui/chat/ChatWidget.h"

#include "RetroChessChatWidgetHolder.h"

#include <retroshare/rsstatus.h>
#include <retroshare/rspeers.h>


#define CALL_START ":/images/call-start.png"
#define IMAGE_RetroChess ":/images/chess-icon.png"

RetroChessChatWidgetHolder::RetroChessChatWidgetHolder(ChatWidget *chatWidget, RetroChessNotify *notify)
 : QObject(), ChatWidgetHolder(chatWidget), mRetroChessNotify(notify)
{
    QIcon icon ;
    icon.addPixmap(QPixmap(IMAGE_RetroChess)) ;


	playChessButton = new QToolButton ;
	playChessButton->setIcon(icon) ;

	mChatWidget->addChatBarWidget(playChessButton);
	connect(playChessButton, SIGNAL(clicked()), this , SLOT(chessPressed()));

}

void RetroChessChatWidgetHolder::chessPressed()
{
	RsPeerId peer_id =  mChatWidget->getChatId().toPeerId();//TODO support GXSID
	if (rsRetroChess->hasInviteFrom(peer_id)){
		rsRetroChess->acceptedInvite(peer_id);
		mRetroChessNotify->notifyChessStart(peer_id);
		return;
	}
	rsRetroChess->sendInvite(peer_id);
}
