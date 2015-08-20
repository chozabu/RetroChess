/* This is the main page displayed by the plugin */
#ifndef NEMAINPAGE_H
#define NEMAINPAGE_H

#include <retroshare-gui/mainpage.h>
#include <retroshare/rsfiles.h>
#include <retroshare/rspeers.h>
#include "gui/RetroChessNotify.h"

#include "gui/chess.h"

#include <QWidget>

namespace Ui {
class NEMainpage;
}

class NEMainpage : public MainPage
{
	Q_OBJECT

public:
	explicit NEMainpage(QWidget *parent, RetroChessNotify *notify);
	~NEMainpage();

private slots:
	void on_pingAllButton_clicked();
	void NeMsgArrived(const RsPeerId &peer_id, QString str);

	void on_broadcastButton_clicked();

	void on_playButton_clicked();

private:
	Ui::NEMainpage *ui;
	RetroChessNotify *mNotify;

	RetroChessWindow *tempwindow;
};

#endif // NEMAINPAGE_H
