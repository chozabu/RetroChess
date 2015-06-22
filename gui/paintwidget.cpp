#include "paintwidget.h"

#include <QBuffer>
#include <QPainter>
#include <iostream>

#include <QtGui/QApplication>
#include <QClipboard>
PaintWidget::PaintWidget(QWidget *parent) :
    QWidget(parent),image(600,300,QImage::Format_RGB32),color(Qt::black),penWidth(8)
{
    image.fill(qRgb(255, 255, 255));
}

void PaintWidget::setImage(const QImage &img){
    image=img.copy();
    update();
}

QImage PaintWidget::getImage(){
    return image;
}

void PaintWidget::fillImage(QColor color){
    image.fill(qRgb(255, 255, 255));
    update();
}

void PaintWidget::mouseMoveEvent(QMouseEvent *event)
{
    QPainter p(&image);
    p.setPen(color);
    p.setBrush(color);
	QPoint pos = event->pos();
    if(penWidth==1){
		p.drawPoint(pos);
    }else{
		p.drawEllipse(pos,penWidth/2,penWidth/2);
    }
//check if u want to clear Jenster--
// if (event->button() == Qt::RightButton) image.fill(qRgb(255, 255, 255));

	// trigger repaint of widget
	update();
	emit mmEvent(pos.x(), pos.y());
	//tjd->paintMouseMove(event);
}


void PaintWidget::paintAt(int x, int y)
{
    QPainter p(&image);
    p.setPen(color);
    p.setBrush(color);
    if(penWidth==1){
        p.drawPoint(x,y);
    }else{
        p.drawEllipse(x,y,penWidth/2,penWidth/2);
    }
    // trigger repaint of widget
    update();
}

qint64 getImgSize(QImage image){
	QByteArray ba;
    QBuffer buffer(&ba);
    buffer.open(QIODevice::WriteOnly);
    image.save(&buffer, "PNG");
	return buffer.buffer().toBase64().size();
}

void PaintWidget::mouseReleaseEvent(QMouseEvent *event){
    std::cout<<"PaintWidgte::mouseReleseEvent()"<<std::endl;
//check if u want to clear Jenster--
 if (event->button() == Qt::RightButton) { image.fill(qRgb(255, 255, 255));update(); }
//check to see if we want to send to clipboard
 if (event->button() == Qt::MiddleButton) {
	 QImage img = image.scaledToWidth(image.width()*0.5);
	 while(getImgSize(img)> 5500){
		 img = img.scaledToWidth(img.width()*0.8);
	 }
   QApplication::clipboard()->setImage(img);
}

   

    emit haveUpdate();
}

void PaintWidget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.drawImage(0,0,image);
}
