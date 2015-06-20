#include "NetExampleNotify.h"

NetExampleNotify::NetExampleNotify(QObject *parent) : QObject(parent)
{

}


void NetExampleNotify::notifyReceivedMsg(const RsPeerId& peer_id, QString str)
{
	std::cout << "pNotify Recvd Packet from: " << peer_id;
	std::cout << " saying " << str.toStdString();
	std::cout << std::endl;
	emit NeMsgArrived(peer_id, str) ;
}
