#ifndef NEMAINPAGE_H
#define NEMAINPAGE_H

#include <retroshare-gui/mainpage.h>
#include <retroshare/rsfiles.h>
#include <retroshare/rspeers.h>



#include <QWidget>

namespace Ui {
class NEMainpage;
}

class NEMainpage : public MainPage
{
	Q_OBJECT

public:
	explicit NEMainpage(QWidget *parent = 0);
	~NEMainpage();

private slots:
	void on_pingAllButton_clicked();

private:
	Ui::NEMainpage *ui;
};

#endif // NEMAINPAGE_H
