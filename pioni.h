#include <iostream>
#ifndef PIONI_H
#define PIONI_H
#pragma once
#include "game.h"
#include "pawn.h"
using namespace std;
class pioni
{
	public:
		int x,y;
		char type;
		string colour;
	public:
		void setc();
		void changeturn(board&);
	    bool move(board&);
	    void check1(board&,int&,int&,char &);// type & xy
		bool search(int,int,char&,board&);
		void play(board&);
		bool checkking(board&);
};
#endif
