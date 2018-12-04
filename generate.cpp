//*****************************************
//����ָ�����������վֵ�ָ��·���ļ�
//���룺num:���ɵ��վ����� �� path:�����ָ���ļ�·��
//�����void
//*****************************************

#include "pch.h"
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <algorithm>
using namespace std;

int sudoku[9][9] = { 0 };
int used[9] = { 0 };
int putnum = 0;

void generate(int num, char* path)
{
	sudoku[0][0] = (0 + 8) % 9 + 1;
	used[(0 + 8) % 9 + 1] = 1;

	FILE* file = fopen(path, "w");

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == j && j == 0) continue;
			sudoku[i][j] = i * 3 + j;
		}
	}

	srand((unsigned)time(NULL));
	while (num--)
	{
		for (int i = 0; i < 50; i++)
		{
			int a = rand() % 8 + 1;
			int b = rand() % 8 + 1;
			int tmp = sudoku[a / 3][a % 3];
			sudoku[a / 3][a % 3] = sudoku[b / 3][b % 3];
			sudoku[b / 3][b % 3] = tmp;
		}
		for (int a = 0; a < 3; a++) {
			for (int b = 0; b < 3; b++) {
				//ö��ÿ������
				if (a == 0 && b == 0) continue;
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						int row = i + a * 3;
						int line = j + b * 3;
						sudoku[row][line] = sudoku[(row % 3 + b) % 3][(line % 3 + a) % 3]; //??????????????????
					}
				}
			}
		}

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				fprintf(file, "%d%c", sudoku[i][j], j == 8 ? '\n' : ' ');
			}
		}
		fprintf(file, "\n");
	}
}

