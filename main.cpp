#include <iostream>
#include "game.cpp"

int main(void)
{
	system("chcp 1253");
	system("cls");
	board c;
	c.set();
	c.ektupwsh();
	pioni l;
	l.play(c);
	return 0;
}
