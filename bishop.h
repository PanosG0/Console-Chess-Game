#ifndef BISHOP_H
#define BISHOP_H
#pragma once
#include "pioni.h"
class bishop:public pioni
{
	public:
		void makemove(board &);
		void getb(board&,int &,int &);
		bool checkbishop(board&,int,int);
		bool checkb2(board&,int,int);
		bishop operator=(const pioni&);
};
#endif
