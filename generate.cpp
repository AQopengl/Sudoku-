//*****************************************
//����ָ�����������վֵ�ָ��·���ļ�
//���룺num:���ɵ��վ����� �� path:�����ָ���ļ�·��
//�����void
//*****************************************

#include "pch.h"
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <algorithm>
using namespace std;
#include "sourse.h"

int sudoku[9][9] = {0};
int putnum = 0;

void generate(int num, char* path)
{
	sudoku[0][0] = (0 + 8) % 9 + 1;

	errno_t err;
	FILE* file;
	err = fopen_s(&file, path, "w");
	if (file == 0) {
		printf("File not exist!\n");
		return;
	}
	srand((unsigned)time(NULL));
	while (num--)
	{
		for (int i = 1; i < 9; i++)
		{
			sudoku[i / 3][i % 3] = i;
		}
		for (int i = 0; i < 20; i++)
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
						sudoku[row][line] = sudoku[(row + b) % 3][(line + a) % 3];
					}
				}
			}
	    }

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (num == 0 && i == 8 && j == 8)
					fprintf(file, "%d", sudoku[i][j]);
				else
					fprintf(file, "%d%c", sudoku[i][j], j == 8 ? '\n' : ' ');
			}
		}
		if (num) fprintf(file, "\n");
	}
	fclose(file);
}