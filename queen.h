#ifndef QUEEN_H
#define QUEEN_H
#pragma once
#include "pioni.h"
class queen:public pioni
{
	public:
		void makemove(board &);
		bool getq(board&,int,int);
		bool getq2(board&,int,int);
		bool checkqueen(board&,int,int);
		queen operator=(const pioni&);
		
};
#endif
