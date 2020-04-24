#include <string.h>
#include <stdlib.h>

#include "diff.h"

int shortest_edit (const char *a, const char *b)
{
	int  n, m;
	int  max;
	int *v;
	int  v_len;
	
	n = strlen (a);
	m = strlen (b);
	max = n + m;
	v_len = 2 * max + 1;
	
	v = (int *) malloc (sizeof (int) * v_len);
	
	v[(v_len / 2) + 1] = 0;
	
	for (int d = 0; d <= max; d++)
	{
		int x, y;
		
		for (int k = -d; k <= d; k += 2)
		{
			if (k == -d || (k != d && v[(k + (v_len / 2)) - 1] < v[(k + (v_len / 2)) + 1]))
			{
				x = v[(k + (v_len / 2)) + 1];
			}
			else
			{
				x = v[(k + (v_len / 2)) - 1] + 1;
			}
			
			y = x - k;
			
			while (x < n && y < m && a[x] == b[y])
			{
				x++;
				y++;
			}
			
			v[(k + (v_len / 2))] = x;
			
			if (x >= n && y >= m)
			{
				free (v);
				return d;
			}
		}
	}
	
	free (v);
}
