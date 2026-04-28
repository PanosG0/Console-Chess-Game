#ifndef KING_H
#define KING_H
#pragma once
#include "pioni.h"
class king:public pioni
{
	public:
		void makemove(board &);
		bool getkk(board&,int,int);
		bool roke(board&,int,int);
		king operator=(const pioni&);
};
#endif
