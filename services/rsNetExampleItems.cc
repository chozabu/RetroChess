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

#include <stdexcept>
#include "serialiser/rsbaseserial.h"
#include "serialiser/rstlvbase.h"

#include "services/rsNetExampleItems.h"

/***
#define RSSERIAL_DEBUG 1
***/

#include <iostream>

#define HOLLERITH_LEN_SPEC 4
/*************************************************************************/

std::ostream& RsNetExamplePingItem::print(std::ostream &out, uint16_t indent)
{
	printRsItemBase(out, "RsNetExamplePingItem", indent);
	uint16_t int_Indent = indent + 2;
	printIndent(out, int_Indent);
	out << "SeqNo: " << mSeqNo << std::endl;

	printIndent(out, int_Indent);
	out << "PingTS: " << std::hex << mPingTS << std::dec << std::endl;

	printRsItemEnd(out, "RsNetExamplePingItem", indent);
	return out;
}

std::ostream& RsNetExamplePongItem::print(std::ostream &out, uint16_t indent)
{
	printRsItemBase(out, "RsNetExamplePongItem", indent);
	uint16_t int_Indent = indent + 2;
	printIndent(out, int_Indent);
	out << "SeqNo: " << mSeqNo << std::endl;

	printIndent(out, int_Indent);
	out << "PingTS: " << std::hex << mPingTS << std::dec << std::endl;

	printIndent(out, int_Indent);
	out << "PongTS: " << std::hex << mPongTS << std::dec << std::endl;

	printRsItemEnd(out, "RsNetExamplePongItem", indent);
	return out;
}
std::ostream& RsNetExampleProtocolItem::print(std::ostream &out, uint16_t indent)
{
	printRsItemBase(out, "RsNetExampleProtocolItem", indent);
	uint16_t int_Indent = indent + 2;
	printIndent(out, int_Indent);
	out << "flags: " << flags << std::endl;

	printIndent(out, int_Indent);
	out << "protocol: " << std::hex << protocol << std::dec << std::endl;

	printRsItemEnd(out, "RsNetExampleProtocolItem", indent);
	return out;
}
std::ostream& RsNetExampleDataItem::print(std::ostream &out, uint16_t indent)
{
	printRsItemBase(out, "RsNetExampleDataItem", indent);
	uint16_t int_Indent = indent + 2;
	printIndent(out, int_Indent);
	out << "flags: " << flags << std::endl;

	printIndent(out, int_Indent);
	out << "data size: " << std::hex << data_size << std::dec << std::endl;

	printRsItemEnd(out, "RsNetExampleDataItem", indent);
	return out;
}

/*************************************************************************/
uint32_t RsNetExampleDataItem::serial_size() const
{
	uint32_t s = 8; /* header */
	s += 4; /* flags */
	s += 4; /* data_size  */
	//s += m_msg.length()+HOLLERITH_LEN_SPEC; /* data */
	s += getRawStringSize(m_msg);

	return s;
}
uint32_t RsNetExampleProtocolItem::serial_size() const
{
	uint32_t s = 8; /* header */
	s += 4; /* flags */
	s += 4; /* protocol */

	return s;
}
uint32_t RsNetExamplePingItem::serial_size() const
{
	uint32_t s = 8; /* header */
	s += 4; /* seqno */
	s += 8; /* pingTS  */

	return s;
}
bool RsNetExampleProtocolItem::serialise(void *data, uint32_t& pktsize)
{
	uint32_t tlvsize = serial_size() ;
	uint32_t offset = 0;

	if (pktsize < tlvsize)
		return false; /* not enough space */

	pktsize = tlvsize;

	bool ok = true;

	ok &= setRsItemHeader(data, tlvsize, PacketId(), tlvsize);

#ifdef RSSERIAL_DEBUG
	std::cerr << "RsNetExampleSerialiser::serialiseNetExampleDataItem() Header: " << ok << std::endl;
	std::cerr << "RsNetExampleSerialiser::serialiseNetExampleDataItem() Size: " << tlvsize << std::endl;
#endif

	/* skip the header */
	offset += 8;

	/* add mandatory parts first */
	ok &= setRawUInt32(data, tlvsize, &offset, protocol);
	ok &= setRawUInt32(data, tlvsize, &offset, flags);

	if (offset != tlvsize)
	{
		ok = false;
		std::cerr << "RsNetExampleSerialiser::serialiseNetExamplePingItem() Size Error! " << std::endl;
	}

	return ok;
}
/* serialise the data to the buffer */
bool RsNetExampleDataItem::serialise(void *data, uint32_t& pktsize)
{
	uint32_t tlvsize = serial_size() ;
	uint32_t offset = 0;

	if (pktsize < tlvsize)
		return false; /* not enough space */

	pktsize = tlvsize;

	bool ok = true;

	ok &= setRsItemHeader(data, tlvsize, PacketId(), tlvsize);

#ifdef RSSERIAL_DEBUG
	std::cerr << "RsNetExampleSerialiser::serialiseNetExampleDataItem() Header: " << ok << std::endl;
	std::cerr << "RsNetExampleSerialiser::serialiseNetExampleDataItem() Size: " << tlvsize << std::endl;
#endif

	/* skip the header */
	offset += 8;

	/* add mandatory parts first */
	ok &= setRawUInt32(data, tlvsize, &offset, flags);
	ok &= setRawUInt32(data, tlvsize, &offset, data_size);


	ok &= setRawString(data, tlvsize, &offset, m_msg );
	std::cout << "string sizes: " << getRawStringSize(m_msg) << " OR " << m_msg.size() << "\n";
	//offset += m_msg.size() ;
	//offset += getRawStringSize(m_msg);
	//memcpy( &((uint8_t*)data)[offset],net_example_data,data_size) ;
	//offset += data_size ;

	if (offset != tlvsize)
	{
		ok = false;
		std::cerr << "RsNetExampleSerialiser::serialiseNetExamplePingItem() Size Error! " << std::endl;
		std::cerr << "expected " << tlvsize << " got " << offset << std::endl;
		std::cerr << "m_msg looks like " << m_msg << std::endl;
	}

	return ok;
}
/* serialise the data to the buffer */
bool RsNetExamplePingItem::serialise(void *data, uint32_t& pktsize)
{
	uint32_t tlvsize = serial_size() ;
	uint32_t offset = 0;

	if (pktsize < tlvsize)
		return false; /* not enough space */

	pktsize = tlvsize;

	bool ok = true;

	ok &= setRsItemHeader(data, tlvsize, PacketId(), tlvsize);

#ifdef RSSERIAL_DEBUG
	std::cerr << "RsNetExampleSerialiser::serialiseNetExamplePingItem() Header: " << ok << std::endl;
	std::cerr << "RsNetExampleSerialiser::serialiseNetExamplePingItem() Size: " << tlvsize << std::endl;
#endif

	/* skip the header */
	offset += 8;

	/* add mandatory parts first */
	ok &= setRawUInt32(data, tlvsize, &offset, mSeqNo);
	ok &= setRawUInt64(data, tlvsize, &offset, mPingTS);

	if (offset != tlvsize)
	{
		ok = false;
		std::cerr << "RsNetExampleSerialiser::serialiseNetExamplePingItem() Size Error! " << std::endl;
	}

	return ok;
}

RsNetExampleProtocolItem::RsNetExampleProtocolItem(void *data, uint32_t pktsize)
	: RsNetExampleItem(RS_PKT_SUBTYPE_NetExample_PROTOCOL)
{
	/* get the type and size */
	uint32_t rstype = getRsItemId(data);
	uint32_t rssize = getRsItemSize(data);

	uint32_t offset = 0;

	if ((RS_PKT_VERSION_SERVICE != getRsItemVersion(rstype)) || (RS_SERVICE_TYPE_NetExample_PLUGIN != getRsItemService(rstype)) || (RS_PKT_SUBTYPE_NetExample_PROTOCOL != getRsItemSubType(rstype)))
		throw std::runtime_error("Wrong packet type!") ;

	if (pktsize < rssize)    /* check size */
		throw std::runtime_error("Not enough size!") ;

	bool ok = true;

	/* skip the header */
	offset += 8;

	/* get mandatory parts first */
	ok &= getRawUInt32(data, rssize, &offset, &protocol);
	ok &= getRawUInt32(data, rssize, &offset, &flags);

	if (offset != rssize)
		throw std::runtime_error("Deserialisation error!") ;

	if (!ok)
		throw std::runtime_error("Deserialisation error!") ;
}
RsNetExamplePingItem::RsNetExamplePingItem(void *data, uint32_t pktsize)
	: RsNetExampleItem(RS_PKT_SUBTYPE_NetExample_PING)
{
	/* get the type and size */
	uint32_t rstype = getRsItemId(data);
	uint32_t rssize = getRsItemSize(data);

	uint32_t offset = 0;


	if ((RS_PKT_VERSION_SERVICE != getRsItemVersion(rstype)) || (RS_SERVICE_TYPE_NetExample_PLUGIN != getRsItemService(rstype)) || (RS_PKT_SUBTYPE_NetExample_PING != getRsItemSubType(rstype)))
		throw std::runtime_error("Wrong packet type!") ;

	if (pktsize < rssize)    /* check size */
		throw std::runtime_error("Not enough size!") ;

	bool ok = true;

	/* skip the header */
	offset += 8;

	/* get mandatory parts first */
	ok &= getRawUInt32(data, rssize, &offset, &mSeqNo);
	ok &= getRawUInt64(data, rssize, &offset, &mPingTS);

	if (offset != rssize)
		throw std::runtime_error("Deserialisation error!") ;

	if (!ok)
		throw std::runtime_error("Deserialisation error!") ;
}

/*************************************************************************/
/*************************************************************************/


uint32_t RsNetExamplePongItem::serial_size() const
{
	uint32_t s = 8; /* header */
	s += 4; /* seqno */
	s += 8; /* pingTS  */
	s += 8; /* pongTS */

	return s;
}

/* serialise the data to the buffer */
bool RsNetExamplePongItem::serialise(void *data, uint32_t& pktsize)
{
	uint32_t tlvsize = serial_size() ;
	uint32_t offset = 0;

	if (pktsize < tlvsize)
		return false; /* not enough space */

	pktsize = tlvsize;

	bool ok = true;

	ok &= setRsItemHeader(data, tlvsize, PacketId(), tlvsize);

#ifdef RSSERIAL_DEBUG
	std::cerr << "RsNetExampleSerialiser::serialiseNetExamplePongItem() Header: " << ok << std::endl;
	std::cerr << "RsNetExampleSerialiser::serialiseNetExamplePongItem() Size: " << tlvsize << std::endl;
#endif

	/* skip the header */
	offset += 8;

	/* add mandatory parts first */
	ok &= setRawUInt32(data, tlvsize, &offset, mSeqNo);
	ok &= setRawUInt64(data, tlvsize, &offset, mPingTS);
	ok &= setRawUInt64(data, tlvsize, &offset, mPongTS);

	if (offset != tlvsize)
	{
		ok = false;
		std::cerr << "RsNetExampleSerialiser::serialiseNetExamplePongItem() Size Error! " << std::endl;
	}

	return ok;
}
RsNetExampleDataItem::RsNetExampleDataItem(void *data, uint32_t pktsize)
	: RsNetExampleItem(RS_PKT_SUBTYPE_NetExample_DATA)
{
	/* get the type and size */
	uint32_t rstype = getRsItemId(data);
	uint32_t rssize = getRsItemSize(data);

	uint32_t offset = 0;

	if ((RS_PKT_VERSION_SERVICE != getRsItemVersion(rstype)) || (RS_SERVICE_TYPE_NetExample_PLUGIN != getRsItemService(rstype)) || (RS_PKT_SUBTYPE_NetExample_DATA != getRsItemSubType(rstype)))
		throw std::runtime_error("Wrong packet subtype") ;

	if (pktsize < rssize)    /* check size */
		throw std::runtime_error("Not enough space") ;

	bool ok = true;

	/* skip the header */
	offset += 8;

	/* get mandatory parts first */
	ok &= getRawUInt32(data, rssize, &offset, &flags);
	ok &= getRawUInt32(data, rssize, &offset, &data_size);


	ok &= getRawString(data, rssize, &offset, m_msg );

	/*net_example_data = malloc(data_size) ;
	memcpy(net_example_data,&((uint8_t*)data)[offset],data_size) ;
	offset += data_size ;*/

	if (offset != rssize)
		throw std::runtime_error("Serialization error.") ;

	if (!ok)
		throw std::runtime_error("Serialization error.") ;
}
RsNetExamplePongItem::RsNetExamplePongItem(void *data, uint32_t pktsize)
	: RsNetExampleItem(RS_PKT_SUBTYPE_NetExample_PONG)
{
	/* get the type and size */
	uint32_t rstype = getRsItemId(data);
	uint32_t rssize = getRsItemSize(data);

	uint32_t offset = 0;

	if ((RS_PKT_VERSION_SERVICE != getRsItemVersion(rstype)) || (RS_SERVICE_TYPE_NetExample_PLUGIN != getRsItemService(rstype)) || (RS_PKT_SUBTYPE_NetExample_PONG != getRsItemSubType(rstype)))
		throw std::runtime_error("Wrong packet subtype") ;

	if (pktsize < rssize)    /* check size */
		throw std::runtime_error("Not enough space") ;

	bool ok = true;

	/* skip the header */
	offset += 8;

	/* get mandatory parts first */
	ok &= getRawUInt32(data, rssize, &offset, &mSeqNo);
	ok &= getRawUInt64(data, rssize, &offset, &mPingTS);
	ok &= getRawUInt64(data, rssize, &offset, &mPongTS);

	if (offset != rssize)
		throw std::runtime_error("Serialization error.") ;

	if (!ok)
		throw std::runtime_error("Serialization error.") ;
}

/*************************************************************************/

RsItem* RsNetExampleSerialiser::deserialise(void *data, uint32_t *pktsize)
{
#ifdef RSSERIAL_DEBUG
	std::cerr << "RsNetExampleSerialiser::deserialise()" << std::endl;
#endif

	/* get the type and size */
	uint32_t rstype = getRsItemId(data);

	if ((RS_PKT_VERSION_SERVICE != getRsItemVersion(rstype)) || (RS_SERVICE_TYPE_NetExample_PLUGIN != getRsItemService(rstype)))
		return NULL ;
	
	try
	{
		switch(getRsItemSubType(rstype))
		{
			case RS_PKT_SUBTYPE_NetExample_PING: 		return new RsNetExamplePingItem(data, *pktsize);
			case RS_PKT_SUBTYPE_NetExample_PONG: 		return new RsNetExamplePongItem(data, *pktsize);
			case RS_PKT_SUBTYPE_NetExample_PROTOCOL: 	return new RsNetExampleProtocolItem(data, *pktsize);
			case RS_PKT_SUBTYPE_NetExample_DATA: 		return new RsNetExampleDataItem(data, *pktsize);

			default:
				return NULL;
		}
	}
	catch(std::exception& e)
	{
		std::cerr << "RsNetExampleSerialiser: deserialization error: " << e.what() << std::endl;
		return NULL;
	}
}


/*************************************************************************/

