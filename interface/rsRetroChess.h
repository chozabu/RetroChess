/* this is a simple class to make it easy for any part of the plugin to call its services */
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

// interface class for p3RetroChess service
//

#pragma once

#include <stdint.h>
#include <string>
#include <list>
#include <vector>
#include <retroshare/rstypes.h>

class RsRetroChess ;
extern RsRetroChess *rsRetroChess;
 
static const uint32_t CONFIG_TYPE_RetroChess_PLUGIN 		= 0xe001 ;

class RsRetroChess
{
	public:

	virtual void ping_all() = 0;
	virtual void broadcast_paint(int x, int y) = 0;
	virtual void msg_all(std::string msg) = 0;
	virtual void chess_click(int col, int row, int count) = 0;
	virtual void set_peer(RsPeerId peer) = 0;
};


