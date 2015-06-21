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
	void on_pingAllButton_clicked();
	void NeMsgArrived(const RsPeerId &peer_id, QString str);

	void on_broadcastButton_clicked();

private:
	Ui::NEMainpage *ui;
	NetExampleNotify *mNotify;
};

#endif // NEMAINPAGE_H
