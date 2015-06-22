/****************************************************************
 *  RetroShare is distributed under the following license:
 *
 *  Copyright (C) 2015
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  as published by the Free Software Foundation; either version 2
 *  of the License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor,
 *  Boston, MA  02110-1301, USA.
 ****************************************************************/

#pragma once

#include <list>
#include <string>

#include "services/rsNetExampleItems.h"
#include "services/p3service.h"
#include "serialiser/rstlvbase.h"
#include "serialiser/rsconfigitems.h"
#include "plugins/rspqiservice.h"
#include <interface/rsNetExample.h>

class p3LinkMgr;
class NetExampleNotify ;

class NetExamplePeerInfo
{
	public:

    bool initialisePeerInfo(const RsPeerId &id);

    RsPeerId mId;
	double mCurrentPingTS;
	double mCurrentPingCounter;
	bool   mCurrentPongRecvd;

	uint32_t mLostPongs;
	uint32_t mSentPings;
	uint32_t total_bytes_received ;
	uint32_t average_incoming_bandwidth ;

	std::list<RsNetExamplePongResult> mPongResults;
	std::list<RsNetExampleDataItem*> incoming_queue ;
};


//!The RS VoIP Test service.
 /**
  *
  * This is only used to test Latency for the moment.
  */

class p3NetExample: public RsPQIService, public RsNetExample
// Maybe we inherit from these later - but not needed for now.
//, public p3Config, public pqiMonitor
{
	public:
		p3NetExample(RsPluginHandler *cm,NetExampleNotify *);

		/***** overloaded from rsNetExample *****/

		virtual uint32_t getPongResults(const RsPeerId &id, int n, std::list<RsNetExamplePongResult> &results);

		// Call stuff.
		//

		// Sending data. The client keeps the memory ownership and must delete it after calling this.
		virtual int sendNetExampleData(const RsPeerId &peer_id,const RsNetExampleDataChunk& chunk) ;

		// The server fill in the data and gives up memory ownership. The client must delete the memory
		// in each chunk once it has been used.
		//
		virtual bool getIncomingData(const RsPeerId& peer_id,std::vector<RsNetExampleDataChunk>& chunks) ;

		virtual int sendNetExampleHangUpCall(const RsPeerId& peer_id) ;
		virtual int sendNetExampleRinging(const RsPeerId& peer_id) ;
		virtual int sendNetExampleAcceptCall(const RsPeerId &peer_id) ;

		/***** overloaded from p3Service *****/
		/*!
		 * This retrieves all chat msg items and also (important!)
		 * processes chat-status items that are in service item queue. chat msg item requests are also processed and not returned
		 * (important! also) notifications sent to notify base  on receipt avatar, immediate status and custom status
		 * : notifyCustomState, notifyChatStatus, notifyPeerHasNewAvatar
		 * @see NotifyBase
		 */
		virtual int   tick();
		virtual int   status();
		virtual bool  recvItem(RsItem *item);

		/*************** pqiMonitor callback ***********************/
		//virtual void statusChange(const std::list<pqipeer> &plist);


		/************* from p3Config *******************/
		virtual RsSerialiser *setupSerialiser() ;

		/*!
		 * chat msg items and custom status are saved
		 */
		virtual bool saveList(bool& cleanup, std::list<RsItem*>&) ;
		virtual bool loadList(std::list<RsItem*>& load) ;
		virtual std::string configurationFileName() const { return "net_example.cfg" ; }

		virtual RsServiceInfo getServiceInfo() ;

		void 	ping_all();

		void broadcast_paint(int x, int y);
		void 	msg_all(std::string msg);
	private:
		int   sendPackets();
		void 	sendPingMeasurements();
		void 	sendBandwidthInfo();

		int sendNetExampleBandwidth(const RsPeerId &peer_id,uint32_t bytes_per_sec) ;

		int 	handlePing(RsNetExamplePingItem *item);
		int 	handlePong(RsNetExamplePongItem *item);

		int 	storePingAttempt(const RsPeerId &id, double ts, uint32_t mCounter);
		int 	storePongResult(const RsPeerId& id, uint32_t counter, double ts, double rtt, double offset);

		void handleProtocol(RsNetExampleProtocolItem*) ;
		void handlePaint(RsNetExamplePaintItem *item);
		void handleData(RsNetExampleDataItem*) ;

		RsMutex mNetExampleMtx;

		NetExamplePeerInfo *locked_GetPeerInfo(const RsPeerId& id);

		static RsTlvKeyValue push_int_value(const std::string& key,int value) ;
		static int pop_int_value(const std::string& s) ;

		std::map<RsPeerId, NetExamplePeerInfo> mPeerInfo;
		time_t mSentPingTime;
		time_t mSentBandwidthInfoTime;
		uint32_t mCounter;

		RsServiceControl *mServiceControl;
		NetExampleNotify *mNotify ;

		int _atransmit ;
		int _voice_hold ;
		int _vadmin ;
		int _vadmax ;
		int _min_loudness ;
		int _noise_suppress ;
		bool _echo_cancel ;
};
