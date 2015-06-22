#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QImage>
#include <stdint.h>

class TopJCDialog;

class PaintWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PaintWidget(QWidget *parent = 0);
    void setImage(const QImage&);
    QImage getImage();

    void fillImage(QColor color);
    virtual void paintAt(int x, int y);

    QColor color;
    uint8_t penWidth;
    TopJCDialog* tjd;
    
signals:
	void haveUpdate();
	void mmEvent(int x, int y);

    
public slots:

protected:
    virtual void mouseReleaseEvent(QMouseEvent * event);
    virtual void paintEvent(QPaintEvent *);
    virtual void mouseMoveEvent(QMouseEvent *);

private:
    QImage image;
    
};

#endif // PAINTWIDGET_H
