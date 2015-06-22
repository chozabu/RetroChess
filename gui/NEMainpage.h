/* This is the main page displayed by the plugin */
#ifndef NEMAINPAGE_H
#define NEMAINPAGE_H

#include <retroshare-gui/mainpage.h>
#include <retroshare/rsfiles.h>
#include <retroshare/rspeers.h>
#include "gui/NetExampleNotify.h"



#include <QWidget>

namespace Ui {
class NEMainpage;
}

class NEMainpage : public MainPage
{
	Q_OBJECT

public:
	explicit NEMainpage(QWidget *parent, NetExampleNotify *notify);
	~NEMainpage();

private slots:
	void mmEvent(int x, int y);
	void on_pingAllButton_clicked();
	void NeMsgArrived(const RsPeerId &peer_id, QString str);

	void on_broadcastButton_clicked();

	void NePaintArrived(const RsPeerId &peer_id, int x, int y);
private:
	Ui::NEMainpage *ui;
	NetExampleNotify *mNotify;
};

#endif // NEMAINPAGE_H
