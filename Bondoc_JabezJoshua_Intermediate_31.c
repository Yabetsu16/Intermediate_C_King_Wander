#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GSIZE 8

struct loc {
	int row;
	int col;
};

void output(int t, struct loc k)
{
	int row,col;

	if( t==0 )
		puts("Start:");
	else
		printf("Turn %d:\n",t);

	for( row=0; row<GSIZE; row++ )
	{
		for( col=0; col<GSIZE; col++ )
		{
			if( row==k.row && col==k.col )
				printf(" K ");
			else
				printf(" . ");
		}
		putchar('\n');
	}
}

int move(void)
{
	int r;

	r = (rand() % 3) - 1;
	return(r);
}

int escaped(struct loc k)
{
	enum { FALSE, TRUE };

	if( k.row<0 )
		return(TRUE);
	if( k.row>=GSIZE )
		return(TRUE);
	if( k.col<0 )
		return(TRUE);
	if( k.col>=GSIZE )
		return(TRUE);
	return(FALSE);
}

int main()
{
	int turn = 0;
	struct loc king = { 3, 4};

	srand( (unsigned)time(NULL) );

	while(1)
	{
		output(turn,king);
		king.row += move();
		king.col += move();
		if( escaped(king) )
			break;
		turn++;
	}
	printf("The king wandered off the grid after %d turns\n",turn);

	return(0);
}
