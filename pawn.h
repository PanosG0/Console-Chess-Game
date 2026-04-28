#ifndef PAWN_H
#define PAWN_H
#pragma once
#include "pioni.h"
class pawn:public pioni
{
	public:
		void makemove(board &);
		void getp(board&,int &,int &);
		bool checkpioni(board&,int,int); // αυτή η μεθοδος λειτουργεί ως περιορισμός για να μην μπορέσει ο χρήστης να "φάει" δικό του πιόνι
		pawn operator=(const pioni&);
};
#endif
