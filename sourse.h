#pragma once

void generate(int num, char* path);
int process_input(int argc, char* argv[]);
int jdg_rep(int row, int line, int putnum, int sudoku[9][9]);

class game
{
public:
	game(char* path);
	void read();
private:
	int sudoku[9][9];
	char* puzzle_path;
	int confirm[9][9];
	int possible_number[9][9][10]; // -1������ã��������ǿ��ã�0�������� �������� �����ʼ��
	//int number_of_not_possible_num[9][9];
	void solve_puzzle();
	void output();
	void fillnum(int row, int line, int putnum);
};