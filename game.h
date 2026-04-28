#ifndef GAME_H
#define GAME_H
#pragma once
#include <fstream>
class board
{	
	public:	
	  char N[8][8];
	  char katagrafh[8][8]; //ypotithemenos pinakas
	  char turn;
	  void ektupwsh();
	  void set();
};

#endif
