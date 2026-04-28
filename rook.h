#ifndef ROOK_H
#define ROOK_H
#pragma once
#include "pioni.h"
class rook:public pioni
{	
	public:
		void makemove(board &);
		bool getr(board&,int,int );
		rook operator=(const pioni&);
		
};
#endif
