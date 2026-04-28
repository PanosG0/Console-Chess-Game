#ifndef KNIGHT_H
#define KNIGHT_H
#pragma once
#include "pioni.h"

class knight:public pioni
{
	public:
		void makemove(board &);
		void getk(board&,int &,int &);
		bool checknight(board&,int,int);
		knight operator=(const pioni&);
		
};
#endif
