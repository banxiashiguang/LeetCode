#!/bin/bash
awk '{
	for(i=1;i<=NF;i++)
		a[NR,i]=$i
}
END{
	for(j=1;j<=NF;j++)
	{
		for(k=1;k<=NR;k++)
		{
			if(k==NR)
				printf a[k,j] RS
			else
				printf a[k,j] FS
		}
	}
}' $1
