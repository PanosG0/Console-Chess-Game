#include "bishop.h"
#include <cmath>
void bishop::makemove(board& c)
{
	int i=-1,j=-1;
	this->getb(c,i,j);
	c.N[this->x][this->y]=' ';
	if( c.turn=='w')
	{
		c.N[i-1][j-1]='B';
	}
	else
	{
		c.N[i-1][j-1]='b';                                     
	}
	this->x=i-1;
	this->y=j-1;
	system("cls");
	c.ektupwsh();
}

void bishop::getb(board& c,int& i,int& j)
{
	cout<<"Δώσε τις συντεταγμένες που θες να κινήσεις τον αξιωματικό: "<<endl;
	bool flag;
	bool k=0;
	do
	{
		if(k)
		{
		  cout<<"Ξαναπροσπάθησε: ";
		}
		k=1;
		cin>>i>>j;
	    i--;
	    j--;
	    if(abs(this->x-this->y)==abs(i-j))
	    {
	    	flag=false;
		}
		else
		{
			flag=true;
		}
		i++;
		j++;
	}
	while( flag || this->checkbishop(c,i,j) );
}

bool bishop::checkbishop(board& c,int i,int j)
{
	if (c.N[i-1][j-1]==' ' && c.N[this->x+1][this->y+1]==' ' && (j>this->y+1) )
	{
		return false;
	}
	if  (c.N[i-1][j-1]==' ' &&  c.N[this->x+1][this->y-1]==' ' && (j<this->y+1))
	{
		return false;
	}
	if (c.N[i-1][j-1]==' ' &&   c.N[this->x-1][this->y-1]==' '  && (j<this->y+1))
	{
		return false;
	}
	if(c.N[i-1][j-1]==' ' &&   c.N[this->x-1][this->y+1]==' '  && (j>this->y+1))
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
			
			if (c.N[this->x+1][this->y+1]==' ' && (j>this->y+1))
	            {
		           return false;
	            }
	        if  (c.N[this->x+1][this->y-1]==' ' && (j<this->y+1))
	            {
		           return false;
	            }
	        if (c.N[this->x-1][this->y-1]==' '  && (j<this->y+1))
	           {
	           	 return false;
			   }
			if (c.N[this->x-1][this->y+1]==' '  && (j>this->y+1))
			  {
			  	return false;
			  }
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
			if (c.N[this->x+1][this->y+1]==' ' && (j>this->y+1))
	            {
		           return false;
	            }
	        if  (c.N[this->x+1][this->y-1]==' ' && (j<this->y+1))
	            {
		           return false;
	            }
			if (c.N[this->x-1][this->y-1]==' '  && (j<this->y+1))
	           {
	           	 return false;
			   }
			if (c.N[this->x-1][this->y+1]==' '  && (j>this->y+1))
			  {
			  	return false;
			  } 
		}
	}
	return true;
}

//bool bishop::checkb2(board& c,int i,int j) // elegxei tis prohgoumenes theseis endiamesa sthn diadromh pou tha kanei o aksiwmatikos
//{
//	int k,l=1;
//	i--;
//	j--;
//	for (k=1; k<4; k++) // mexri kai 4 koutia mporei na metakinhthei
//	{
//		while((this->x+k)<=i && (this->y+l)<=j)
//		{
//		   if (c.N[this->x+k][this->y+l]!=' ')
//		    {
//			return true;
//		    }
//	    }
//	}
//	return false;
//}

bishop bishop::operator=(const pioni& a)
{
	bishop p;
	p.x=a.x;
	p.y=a.y;
	p.type=a.type;
	return p;
}
