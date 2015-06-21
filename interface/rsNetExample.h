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

// interface class for p3NetExample service
//

#pragma once

#include <stdint.h>
#include <string>
#include <list>
#include <vector>
#include <retroshare/rstypes.h>

class RsNetExample ;
extern RsNetExample *rsNetExample;
 
static const uint32_t CONFIG_TYPE_NetExample_PLUGIN 		= 0xe001 ;

class RsNetExamplePongResult
{
	public:
	RsNetExamplePongResult()
	:mTS(0), mRTT(0), mOffset(0) { return; }

	RsNetExamplePongResult(double ts, double rtt, double offset)
	:mTS(ts), mRTT(rtt), mOffset(offset) { return; }

	double mTS;
	double mRTT;
	double mOffset;
};

struct RsNetExampleDataChunk
{
	typedef enum { RS_NetExample_DATA_TYPE_AUDIO, RS_NetExample_DATA_TYPE_VIDEO } RsNetExampleDataType ;

	void *data ; // create/delete using malloc/free.
	uint32_t size ;
	RsNetExampleDataType type ;	// video or audio
};

class RsNetExample
{
	public:
		virtual int sendNetExampleHangUpCall(const RsPeerId& peer_id) = 0;
		virtual int sendNetExampleRinging(const RsPeerId& peer_id) = 0;
		virtual int sendNetExampleAcceptCall(const RsPeerId& peer_id) = 0;

	virtual void ping_all() = 0;
	virtual void msg_all(std::string msg) = 0;
		// Sending data. The client keeps the memory ownership and must delete it after calling this.
		virtual int sendNetExampleData(const RsPeerId& peer_id,const RsNetExampleDataChunk& chunk) = 0;

		// The server fill in the data and gives up memory ownership. The client must delete the memory
		// in each chunk once it has been used.
		//
		virtual bool getIncomingData(const RsPeerId& peer_id,std::vector<RsNetExampleDataChunk>& chunks) = 0;

		typedef enum { AudioTransmitContinous = 0, AudioTransmitVAD = 1, AudioTransmitPushToTalk = 2 } enumAudioTransmit ;

		// Config stuff

		virtual uint32_t getPongResults(const RsPeerId& id, int n, std::list<RsNetExamplePongResult> &results) = 0;
};


