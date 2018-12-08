//*****************************************
//�������̨����
//���룺 ����̨����
//����� true: ������ȷ   false�����ִ���
//˵������������� -c �����֣������generate��������ָ��������������
//��������� -s ��·���������·�����ļ��е��������⣬����������
//sudoku.txt�ļ��С�
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
#include "sourse.h"

char path_of_sudoku[17] = { "Sudoku_final.txt" };// Ҫ����������·��

int process_input(int argc, char* argv[])
{
	if (argv[1][0] == '-')
	{
		if (argv[1][1] == 'c') {
			for (int i = 0; argv[2][i] != '\0'; i++) {
				if (argv[2][i] <= '9' && argv[2][i] >= '0') continue;
				else {
					printf("������ʮ����������\n");
					return false;
				}
			}
			int weight = 1;
			int sum = 0; // ��������ִ�С
			for (int i = (int)strlen(argv[2]) - 1; i >= 0; i--)
			{
				sum += weight * (argv[2][i] - '0');
				weight *= 10;
			}
			generate(sum, path_of_sudoku);
			return true;
		}
		else if (argv[1][1] == 's') {
			game puzzle(argv[2]);
			puzzle.solution();
			return true;
		}
		else {
			printf("��������ȷ����\n");
			return false;
		}
	}
	else { 
		printf("��������ȷ����\n"); 
		return false;
	}
}