#ifndef RETROCHESSCHATWIDGETHOLDER_H
#define RETROCHESSCHATWIDGETHOLDER_H

#include "RetroChessChatWidgetHolder.h"
#include <gui/chat/ChatWidget.h>
#include <gui/common/RsButtonOnText.h>
#include <gui/RetroChessNotify.h>

class RetroChessChatWidgetHolder : public QObject, public ChatWidgetHolder
{
	Q_OBJECT

public:
	RetroChessChatWidgetHolder(ChatWidget *chatWidget, RetroChessNotify *notify);

public slots:
	void chessPressed();
protected:
	QToolButton *playChessButton ;
	RetroChessNotify *mRetroChessNotify;
};

#endif // RETROCHESSCHATWIDGETHOLDER_H
