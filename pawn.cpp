#include "pawn.h"
#include <cmath>
void pawn::makemove(board &c)
{
	int i,j;
	cout<<"Δώσε τις συντεταγμένες που θες να κινήσεις τον στρατιώτη: ";
	cin>>i>>j;
	this->getp(c,i,j);
	c.N[this->x][this->y]=' ';
	if( c.turn=='w')
	{
	    c.N[i-1][j-1]='P';
	}
	else
	{
		c.N[i-1][j-1]='p';
	}
	this->x=i-1;
	this->y=j-1;
	system("cls");
	c.ektupwsh();
}

void pawn::getp(board& c,int& i,int& j)
{
	int log=1;
	if (this->x==1 || this->x==6)
	{
		if(c.N[i-1][j-1]!=' ')
		{
			while(i<3 || i>6  || (abs((i-1)-this->x))>log || abs(j-1-this->y)>1 || this->checkpioni(c,i,j) )   //(abs(a.y-j>2)
	          {
		        cout<<"Ξαναπροσπάθησε: ";
		        cin>>i>>j;
	          
	            if(c.N[i-1][j-1]!=' ' && i>=3 && i<=6 && (abs((i-1)-this->x))<=1 && (abs(this->y-j)<=2) && !this->checkpioni(c,i,j) ) // logw tou prwtou me to c.
	              {
	          	    break;
			      }
			    else
			      {
			      	log=2;
				  }
		      }
	    }
	    else
	    {
	    	while(i<3 || i>6  || (abs((i-1)-this->x))>2|| ((this->y!=(j-1))) || this->checkpioni(c,i,j) )
	         {
		       cout<<"Ξαναπροσπάθησε: ";
		       cin>>i>>j;
		       if(c.N[i-1][j-1]!=' ' && i>=3 && i<=6 && (abs((i-1)-this->x))<=1 && (abs(this->y-j)<=2) && !this->checkpioni(c,i,j) ) // logw tou prwtou me to c.
	              {
	          	    break;
			      }
	         }
		}
	}
	else // exei kounithei
	{
		if(c.N[i-1][j-1]!=' ')
		{
			while(i<3 || i>6  || (abs((i-1)-this->x))>1 || (abs(this->y-j)>2) || this->checkpioni(c,i,j))
	        {
		       cout<<"Ξαναπροσπάθησε: ";
		       cin>>i>>j;
	         
	         if(c.N[i-1][j-1]!=' ' && i>=3 && i<=6 && (abs((i-1)-this->x))<=1 && (abs(this->y-j)<=2) && !this->checkpioni(c,i,j)) // logw tou prwtou me to c.
	         {
	          	break;
			 }
			}
		}
	}
}

bool pawn::checkpioni(board& c,int i,int j)
{
	if(c.N[i-1][j-1]==' ')
	{
		return false;
	}
	if(c.turn=='w')
	{
		if (c.N[i-1][j-1]<90)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (c.N[i-1][j-1]>90)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

pawn pawn::operator=(const pioni& a)
{
	pawn p;
	p.x=a.x;
	p.y=a.y;
	p.type=a.type;
	return p;
}
