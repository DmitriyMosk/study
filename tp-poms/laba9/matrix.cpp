#pragma once
#include"pch.h"
#include"stdlib.h"
void form(int matr[5][5])
{
	int i, j;
	for (i = 0; i < 5; i++)
		for (j = 0; j < 5; j++)
			matr[i][j] = rand() % 100 - 40;
}

int Maximum(int matr[5][5])
{
	int m = 0; 
	for (int i = 0; i < 5; i++)
		if (matr[i][i] > m)
			m = matr[i][i]; 
	return m;
}

int Minimum(int matr[5][5])
{
	int m = 99999;
	for (int i = 0; i < 5; i++)
		if (matr[5 - 1 - i][i] < m)
			m = matr[i][i];
	return m;
}