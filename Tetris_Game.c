#include<stdio.h>
#include<Windows.h> //sleep()
#include<stdlib.h> //system(cls), rand(), srand()
#include<conio.h> //kbhit()
#include<time.h> // time()

#define Board_Width 12  //보드판의 가로 길이 = 12 좌표는 24
#define Board_Height 22 //보드판의 세로 길이 = 22 
#define basic_speed_of_game 300

//현재 블럭의 모양, 회전 방향을 저장할 구조체 선언
typedef struct now_block
{
	int x_of_block;
	int y_of_block;
	int now_type;
	int now_rotation;

}now_block;

// 콘솔 창에서 이미지를 출력하기 위해서 좌표를 이동시켜줄 함수
void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void gotoxy(int x, int y);

//보드 판 오프닝 함수
void OPENING()
{
	int x = 0, y = 0;


	for (int big = 0; big < 10; big++)
	{
		gotoxy(20, 18);
		printf("Left  :  ←");
		gotoxy(20, 19);
		printf("Right :  →");
		gotoxy(20, 20);
		printf("Change:  ↑");
		gotoxy(20, 21);
		printf("Down  :  space");
		gotoxy(60, 24);
		printf("if you want to exit ,please press key 'Enter' ");
		gotoxy(80, 26);
		printf("this game is made by 최지웅 ");

		if (big % 2 == 0)
		{
			for (int i = 0; i < 500; i++)
			{

				x = rand() % 120;
				y = rand() % 14;
				gotoxy(x, y);
				printf("*");

			}
			Sleep(300);

			gotoxy(20, 3);
			printf("★★★★★    ★★★★★   ★★★★★   ★★★★★   ★★★★★   ★★★★★");
			gotoxy(20, 4);
			printf("    ★        ★               ★       ★      ★       ★       ★        ");
			gotoxy(20, 5);
			printf("    ★        ★               ★       ★       ★      ★       ★        ");
			gotoxy(20, 6);
			printf("    ★        ★★★★★       ★       ★★★★★       ★       ★★★★★");
			gotoxy(20, 7);
			printf("    ★        ★               ★       ★ ★            ★               ★");
			gotoxy(20, 8);
			printf("    ★        ★               ★       ★   ★          ★               ★");
			gotoxy(20, 9);
			printf("    ★        ★               ★       ★    ★         ★               ★");
			gotoxy(20, 10);
			printf("    ★        ★★★★★       ★       ★      ★   ★★★★★   ★★★★★\n\n\n\n\n\n");

			Sleep(300);
			system("cls");
		}
		else
		{
			for (int i = 0; i < 500; i++)
			{

				x = rand() % 120;
				y = rand() % 14;
				gotoxy(x, y);
				printf("*");
			}
			Sleep(300);

			gotoxy(20, 3);
			printf("☆☆☆☆☆    ☆☆☆☆☆   ☆☆☆☆☆   ☆☆☆☆☆   ☆☆☆☆☆   ☆☆☆☆☆");
			gotoxy(20, 4);
			printf("    ☆        ☆               ☆       ☆      ☆       ☆       ☆        ");
			gotoxy(20, 5);
			printf("    ☆        ☆               ☆       ☆       ☆      ☆       ☆        ");
			gotoxy(20, 6);
			printf("    ☆        ☆☆☆☆☆       ☆       ☆☆☆☆☆       ☆       ☆☆☆☆☆");
			gotoxy(20, 7);
			printf("    ☆        ☆               ☆       ☆ ☆            ☆               ☆");
			gotoxy(20, 8);
			printf("    ☆        ☆               ☆       ☆   ☆          ☆               ☆");
			gotoxy(20, 9);
			printf("    ☆        ☆               ☆       ☆    ☆         ☆               ☆");
			gotoxy(20, 10);
			printf("    ☆        ☆☆☆☆☆       ☆       ☆      ☆   ☆☆☆☆☆   ☆☆☆☆☆\n\n\n\n\n\n");

			Sleep(300);
			system("cls");
		}
	}

	Sleep(100);

}

//게임이 시작된다면 실행 될 함수
void Game_start()
{
	//블럭 만들기
	int block[7][4][4][4] = {
		//ㅡ
		{{{0,0,0,0},
		  {0,0,0,0},
		  {0,0,0,0},
		  {1,1,1,1}},

		{ {1,0,0,0},
		  {1,0,0,0},
		  {1,0,0,0},
		  {1,0,0,0}},

		{ {0,0,0,0},
		  {0,0,0,0},
		  {0,0,0,0},
		  {1,1,1,1}},

		{ {1,0,0,0},
		  {1,0,0,0},
		  {1,0,0,0},
		  {1,0,0,0}}},

		  //ㅁ
		  {{{0,0,0,0},
			{0,0,0,0},
			{1,1,0,0},
			{1,1,0,0}},

		  {{0,0,0,0},
			{0,0,0,0},
			{1,1,0,0},
			{1,1,0,0}},

		  {{0,0,0,0},
			{0,0,0,0},
			{1,1,0,0},
			{1,1,0,0}},

		  {{0,0,0,0},
			{0,0,0,0},
			{1,1,0,0},
			{1,1,0,0}}},

			//ㅗ
		  {{{0,0,0,0},
			{0,0,0,0},
			{0,1,0,0},
			{1,1,1,0}},

		  {{0,0,0,0},
			{1,0,0,0},
			{1,1,0,0},
			{1,0,0,0}},

		{{0,0,0,0},
		{0,0,0,0},
		{1,1,1,0},
		{0,1,0,0}},

		{{0,0,0,0},
		{0,1,0,0},
		{1,1,0,0},
		{0,1,0,0}}},

		//ㄴ
  {{{0,0,0,0},
	{0,0,0,0},
	{1,0,0,0},
	{1,1,1,0}},

	{{0,0,0,0},
	{1,1,0,0},
	{1,0,0,0},
	{1,0,0,0}},

	{{0,0,0,0},
	{0,0,0,0},
	{1,1,1,0},
	{0,0,1,0}},

	{{0,0,0,0},
	{0,1,0,0},
	{0,1,0,0},
	{1,1,0,0}} },

	//ㄴ<->
	{{{0,0,0,0},
	  {0,0,0,0},
	  {0,0,1,0},
	  {1,1,1,0}},

	{{0,0,0,0},
	  {1,0,0,0},
	  {1,0,0,0},
	  {1,1,0,0}},

	  {{0,0,0,0},
	  {0,0,0,0},
	  {1,1,1,0},
	  {1,0,0,0}},

	  {{0,0,0,0},
	  {1,1,0,0},
	  {0,1,0,0},
	  {0,1,0,0}}},

	  //ㄱㄴ
		{ {{0,0,0,0},
		  {0,0,0,0},
		  {1,1,0,0},
		  {0,1,1,0}},

		{{0,0,0,0},
		  {0,1,0,0},
		  {1,1,0,0},
		  {1,0,0,0}},

		  {{0,0,0,0},
		  {0,0,0,0},
		  {1,1,0,0},
		  {0,1,1,0}},

		   {{0,0,0,0},
		  {0,1,0,0},
		  {1,1,0,0},
		  {1,0,0,0}} },

		  //ㄱㄴ<->
		  { {{0,0,0,0},
			{0,0,0,0},
			{0,1,1,0},
			{1,1,0,0}},

		  {{0,0,0,0},
			{1,0,0,0},
			{1,1,0,0},
			{0,1,0,0}},

		   {{0,0,0,0},
			{0,0,0,0},
			{0,1,1,0},
			{1,1,0,0}},

			{{0,0,0,0},
			{1,0,0,0},
			{1,1,0,0},
			{0,1,0,0}} },
	};

	int abs_Board[Board_Height][Board_Width * 2];
	int key = 0;
	now_block B1;
	int the_number_of_block = 1;
	int game_speed;
	int full_of_line[22] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

	srand((unsigned int)time(NULL));

	//첫 째, 마지막 줄에 있는 벽면 값은 11로 저장 , 사이에 있는 벽면의 값은 10 저장 
	for (int j = 0; j < Board_Height; j++)
	{
		for (int i = 0; i < (Board_Width * 2); i++)
		{
			if (j == 0 || j == Board_Height - 1)
			{
				abs_Board[j][i] = 1;
			}
			else if (i == 0 || i == (Board_Width * 2) - 2)
			{
				abs_Board[j][i] = 1;
			}
			else abs_Board[j][i] = 0;
		}
	}

	OPENING(); 

		//다음 블록 보여주는 칸
		gotoxy(26, 0);
	printf("N E X T B L O C K");
	for (int i = 0; i < 8; i++)
	{
		gotoxy(26, i + 1);
		if (i == 0 || i == 7)
		{
			printf("▩▩▩▩▩▩▩▩");
		}
		else
		{
			printf("▩            ▩");
		}
	}


	//if 절대 보드의 값이 1이면 벽면에 벽돌 설치
	for (int i = 0; i < Board_Height; i++)
	{
		for (int j = 0; j < (Board_Width); j++)
		{
			if (abs_Board[i][j * 2] == 1)
			{
				gotoxy(j * 2, i);
				printf("▩");
			}
			else if (abs_Board[i][j * 2] == 0)
			{
				gotoxy(j * 2, i);
				printf("  ");
			}
		}
	}

	//게임 시작
	while (1)
	{
		the_number_of_block++;
		B1.x_of_block = 8;
		B1.y_of_block = 1;
		int crush_block = 0;
		B1.now_type = (rand() % 7);
		B1.now_rotation = 0;

		//'enter'를 눌렀을 경우 종료 모드 실행
		if (key == 13)
		{
			gotoxy(20, 10);
			char real_exit = '\0';
			printf("정말 종료하시겠습니까? : (Y or N)");
			scanf_s("%c", &real_exit, sizeof(real_exit));
			if ((real_exit == 'Y') || (real_exit == 'y'))
			{
				break;
			}
		}

		//한 블럭의 일생
		while (1)
		{

			key = 0;
			//바닥이거나 crush_block 가 1이라면 현재 블럭을 멈춤
			if (B1.y_of_block == 17)
			{
				break;
			}
			else if (crush_block == 1)
			{
				break;
			}

			//key 입력받기
			if (_kbhit())
			{
				key = _getch();
				//↑
				if (key == 72)
				{

					for (int i = 0; i < 4; i++)
					{

						for (int j = 0; j < 4; j++)
						{
							if (abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] == the_number_of_block)
							{
								abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] = 0;
							}
						}
					}

					B1.now_rotation++;
					if (B1.now_rotation == 4)
					{
						B1.now_rotation = (B1.now_rotation % 4);
					}
					key = 0;
				}
				//↓
				else if (key == 80)
				{
					//원래 있던 블럭 지우기
					for (int i = 0; i < 4; i++)
					{
						gotoxy(B1.x_of_block, B1.y_of_block + i);
						for (int j = 0; j < 4; j++)
						{
							if (block[B1.now_type][B1.now_rotation][i][j] == 1)
							{
								gotoxy(B1.x_of_block + (j * 2), B1.y_of_block + i);
								printf("  ");
								abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] = 0;
							}

						}
					}
					//Block 내리기

					if (B1.y_of_block >= 16)
					{
						for (int i = 0; i < 4; i++)
						{
							gotoxy(B1.x_of_block, B1.y_of_block + i);
							for (int j = 0; j < 4; j++)
							{
								if (block[B1.now_type][B1.now_rotation][i][j] == 1)
								{
									printf("▩");
									abs_Board[B1.y_of_block + i][B1.x_of_block + (2 * j)] = the_number_of_block;
								}
								else if ((abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] == 0) && (block[B1.now_type][B1.now_rotation][i][j] == 0))
								{
									printf("  ");
								}
								else if ((abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] != 0) && (block[B1.now_type][B1.now_rotation][i][j] == 0))
								{
									if ((i != 3) && (j != 3))
										gotoxy(B1.x_of_block + ((j + 1) * 2), B1.y_of_block + i);
									else if ((i != 3) && (j == 3))
										gotoxy(B1.x_of_block + (j * 2), B1.y_of_block + i);
									else if ((i == 3) && (j != 3))
										gotoxy(B1.x_of_block + ((j + 1) * 2), B1.y_of_block + i);
									else if ((i == 3) && (j == 3))
										gotoxy(50, 2);

								}
							}
						}
					}
					else
					{
						B1.y_of_block = B1.y_of_block + 3;
						for (int i = 0; i < 4; i++)
						{
							gotoxy(B1.x_of_block, B1.y_of_block + i);
							for (int j = 0; j < 4; j++)
							{
								if (block[B1.now_type][B1.now_rotation][i][j] == 1)
								{
									printf("▩");
									abs_Board[B1.y_of_block + i][B1.x_of_block + (2 * j)] = the_number_of_block;
								}
								else if ((abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] == 0) && (block[B1.now_type][B1.now_rotation][i][j] == 0))
								{
									printf("  ");
								}
								else if ((abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] != 0) && (block[B1.now_type][B1.now_rotation][i][j] == 0))
								{
									if ((i != 3) && (j != 3))
										gotoxy(B1.x_of_block + ((j + 1) * 2), B1.y_of_block + i);
									else if ((i != 3) && (j == 3))
										gotoxy(B1.x_of_block + (j * 2), B1.y_of_block + i);
									else if ((i == 3) && (j != 3))
										gotoxy(B1.x_of_block + ((j + 1) * 2), B1.y_of_block + i);
									else if ((i == 3) && (j == 3))
										gotoxy(50, 2);

								}
							}
						}
					}
				}
				//←
				else if (key == 75)
				{
					int crush = 0;

					for (int i = 0; i < 4; i++)
					{
						for (int j = 0; j < 4; j++)
						{
							if ((abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] == the_number_of_block) && (abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2) - 2]) < the_number_of_block)
							{
								if ((abs_Board[B1.y_of_block][B1.x_of_block + (j * 2) - 2] != 0))
								{
									crush = 1;
								}
							}
						}
					}
					if (crush == 0)
					{
						for (int i = 0; i < 4; i++)
						{
							gotoxy(B1.x_of_block, B1.y_of_block + i);
							for (int j = 0; j < 4; j++)
							{
								if (block[B1.now_type][B1.now_rotation][i][j] == 1)
								{
									gotoxy(B1.x_of_block + (j * 2), B1.y_of_block + i);
									printf("  ");
									abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] = 0;
								}

							}
						}
						for (int i = 0; i < 4; i++)
						{
							for (int j = 0; j < 4; j++)
							{
								if (abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] == the_number_of_block)
								{
									abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] = 0;
								}
							}
						}
						for (int i = 0; i < 4; i++)
						{
							for (int j = 0; j < 4; j++)
							{
								if (block[B1.now_type][B1.now_rotation][i][j] == 1)
								{

									abs_Board[B1.y_of_block + i][B1.x_of_block + ((j - 1) * 2)] = the_number_of_block;
								}
							}
						}
						B1.x_of_block = B1.x_of_block - 2;
					}
					else if (crush == 1) {}
					key = 0;
				}
				//→
				else if (key == 77)
				{
					int crush = 0;

					for (int i = 0; i < 4; i++)
					{
						for (int j = 0; j < 4; j++)
						{
							if ((abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] == the_number_of_block) && (abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2) + 2]) < the_number_of_block)
							{
								if ((abs_Board[B1.y_of_block][B1.x_of_block + (j * 2) + 2] != 0))
								{
									crush = 1;
								}
							}
						}
					}
					if (crush == 0)
					{
						for (int i = 0; i < 4; i++)
						{
							gotoxy(B1.x_of_block, B1.y_of_block + i);
							for (int j = 0; j < 4; j++)
							{
								if (block[B1.now_type][B1.now_rotation][i][j] == 1)
								{
									gotoxy(B1.x_of_block + (j * 2), B1.y_of_block + i);
									printf("  ");
									abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] = 0;
								}

							}
						}
						for (int i = 0; i < 4; i++)
						{
							for (int j = 0; j < 4; j++)
							{
								if (abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] == the_number_of_block)
								{
									abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] = 0;
								}
							}
						}
						for (int i = 0; i < 4; i++)
						{
							for (int j = 0; j < 4; j++)
							{
								if (block[B1.now_type][B1.now_rotation][i][j] == 1)
								{

									abs_Board[B1.y_of_block + i][B1.x_of_block + ((j + 1) * 2)] = the_number_of_block;
								}
							}
						}
						B1.x_of_block = B1.x_of_block + 2;
					}
					else if (crush == 1) {}
					key = 0;
				}
				//enter
				else if (key == 13)
				{
					break;
				}

			}

			//화면에 블럭 만들기
			for (int i = 0; i < 4; i++)
			{
				gotoxy(B1.x_of_block, B1.y_of_block + i);
				for (int j = 0; j < 4; j++)
				{
					if (block[B1.now_type][B1.now_rotation][i][j] == 1)
					{
						printf("▩");
						abs_Board[B1.y_of_block + i][B1.x_of_block + (2 * j)] = the_number_of_block;
					}
					else if ((abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] == 0) && (block[B1.now_type][B1.now_rotation][i][j] == 0))
					{
						printf("  ");
					}
					else if (abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] != 0 && (block[B1.now_type][B1.now_rotation][i][j] == 0))
					{
						if ((i != 3) && (j != 3))
							gotoxy(B1.x_of_block + ((j + 1) * 2), B1.y_of_block + i);
						else if ((i != 3) && (j == 3))
							gotoxy(B1.x_of_block + (j * 2), B1.y_of_block + i);
						else if ((i == 3) && (j != 3))
							gotoxy(B1.x_of_block + ((j + 1) * 2), B1.y_of_block + i);
						else if ((i == 3) && (j == 3))
							gotoxy(50, 2);
					}
				}
			}

			//key 입력받기
			if (_kbhit())
			{
				key = _getch();
				//↑
				if (key == 72)
				{

					for (int i = 0; i < 4; i++)
					{

						for (int j = 0; j < 4; j++)
						{
							if (abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] == the_number_of_block)
							{
								abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] = 0;
							}
						}
					}

					B1.now_rotation++;
					if (B1.now_rotation == 4)
					{
						B1.now_rotation = (B1.now_rotation % 4);
					}
					key = 0;
				}
				//↓
				else if (key == 80)
				{
					//원래 있던 블럭 지우기
					for (int i = 0; i < 4; i++)
					{
						gotoxy(B1.x_of_block, B1.y_of_block + i);
						for (int j = 0; j < 4; j++)
						{
							if (block[B1.now_type][B1.now_rotation][i][j] == 1)
							{
								gotoxy(B1.x_of_block + (j * 2), B1.y_of_block + i);
								printf("  ");
								abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] = 0;
							}

						}
					}
					//Block 내리기

					if (B1.y_of_block >= 16)
					{
						for (int i = 0; i < 4; i++)
						{
							gotoxy(B1.x_of_block, B1.y_of_block + i);
							for (int j = 0; j < 4; j++)
							{
								if (block[B1.now_type][B1.now_rotation][i][j] == 1)
								{
									printf("▩");
									abs_Board[B1.y_of_block + i][B1.x_of_block + (2 * j)] = the_number_of_block;
								}
								else if ((abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] == 0) && (block[B1.now_type][B1.now_rotation][i][j] == 0))
								{
									printf("  ");
								}
								else if ((abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] != 0) && (block[B1.now_type][B1.now_rotation][i][j] == 0))
								{
									if ((i != 3) && (j != 3))
										gotoxy(B1.x_of_block + ((j + 1) * 2), B1.y_of_block + i);
									else if ((i != 3) && (j == 3))
										gotoxy(B1.x_of_block + (j * 2), B1.y_of_block + i);
									else if ((i == 3) && (j != 3))
										gotoxy(B1.x_of_block + ((j + 1) * 2), B1.y_of_block + i);
									else if ((i == 3) && (j == 3))
										gotoxy(50, 2);

								}
							}
						}
					}
					else
					{
						B1.y_of_block = B1.y_of_block + 3;
						for (int i = 0; i < 4; i++)
						{
							gotoxy(B1.x_of_block, B1.y_of_block + i);
							for (int j = 0; j < 4; j++)
							{
								if (block[B1.now_type][B1.now_rotation][i][j] == 1)
								{
									printf("▩");
									abs_Board[B1.y_of_block + i][B1.x_of_block + (2 * j)] = the_number_of_block;
								}
								else if ((abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] == 0) && (block[B1.now_type][B1.now_rotation][i][j] == 0))
								{
									printf("  ");
								}
								else if ((abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] != 0) && (block[B1.now_type][B1.now_rotation][i][j] == 0))
								{
									if ((i != 3) && (j != 3))
										gotoxy(B1.x_of_block + ((j + 1) * 2), B1.y_of_block + i);
									else if ((i != 3) && (j == 3))
										gotoxy(B1.x_of_block + (j * 2), B1.y_of_block + i);
									else if ((i == 3) && (j != 3))
										gotoxy(B1.x_of_block + ((j + 1) * 2), B1.y_of_block + i);
									else if ((i == 3) && (j == 3))
										gotoxy(50, 2);

								}
							}
						}
					}
				}
				//←
				else if (key == 75)
				{
					int crush = 0;

					for (int i = 0; i < 4; i++)
					{
						for (int j = 0; j < 4; j++)
						{
							if ((abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] == the_number_of_block) && (abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2) - 2]) < the_number_of_block)
							{
								if ((abs_Board[B1.y_of_block][B1.x_of_block + (j * 2) - 2] != 0))
								{
									crush = 1;
								}
							}
						}
					}
					if (crush == 0)
					{
						for (int i = 0; i < 4; i++)
						{
							gotoxy(B1.x_of_block, B1.y_of_block + i);
							for (int j = 0; j < 4; j++)
							{
								if (block[B1.now_type][B1.now_rotation][i][j] == 1)
								{
									gotoxy(B1.x_of_block + (j * 2), B1.y_of_block + i);
									printf("  ");
									abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] = 0;
								}

							}
						}
						for (int i = 0; i < 4; i++)
						{
							for (int j = 0; j < 4; j++)
							{
								if (abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] == the_number_of_block)
								{
									abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] = 0;
								}
							}
						}
						for (int i = 0; i < 4; i++)
						{
							for (int j = 0; j < 4; j++)
							{
								if (block[B1.now_type][B1.now_rotation][i][j] == 1)
								{

									abs_Board[B1.y_of_block + i][B1.x_of_block + ((j - 1) * 2)] = the_number_of_block;
								}
							}
						}
						B1.x_of_block = B1.x_of_block - 2;
					}
					else if (crush == 1) {}
					key = 0;
				}
				//→
				else if (key == 77)
				{
					int crush = 0;

					for (int i = 0; i < 4; i++)
					{
						for (int j = 0; j < 4; j++)
						{
							if ((abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] == the_number_of_block) && (abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2) + 2]) < the_number_of_block)
							{
								if ((abs_Board[B1.y_of_block][B1.x_of_block + (j * 2) + 2] != 0))
								{
									crush = 1;
								}
							}
						}
					}
					if (crush == 0)
					{
						for (int i = 0; i < 4; i++)
						{
							gotoxy(B1.x_of_block, B1.y_of_block + i);
							for (int j = 0; j < 4; j++)
							{
								if (block[B1.now_type][B1.now_rotation][i][j] == 1)
								{
									gotoxy(B1.x_of_block + (j * 2), B1.y_of_block + i);
									printf("  ");
									abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] = 0;
								}

							}
						}
						for (int i = 0; i < 4; i++)
						{
							for (int j = 0; j < 4; j++)
							{
								if (abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] == the_number_of_block)
								{
									abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] = 0;
								}
							}
						}
						for (int i = 0; i < 4; i++)
						{
							for (int j = 0; j < 4; j++)
							{
								if (block[B1.now_type][B1.now_rotation][i][j] == 1)
								{

									abs_Board[B1.y_of_block + i][B1.x_of_block + ((j + 1) * 2)] = the_number_of_block;
								}
							}
						}
						B1.x_of_block = B1.x_of_block + 2;
					}
					else if (crush == 1) {}
					key = 0;
				}
				//enter
				else if (key == 13)
				{
					break;
				}

			}

			//화면에 블럭 만들기
			for (int i = 0; i < 4; i++)
			{
				gotoxy(B1.x_of_block, B1.y_of_block + i);
				for (int j = 0; j < 4; j++)
				{
					if (block[B1.now_type][B1.now_rotation][i][j] == 1)
					{
						printf("▩");
						abs_Board[B1.y_of_block + i][B1.x_of_block + (2 * j)] = the_number_of_block;
					}
					else if ((abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] == 0) && (block[B1.now_type][B1.now_rotation][i][j] == 0))
					{
						printf("  ");
					}
					else if (abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] != 0 && (block[B1.now_type][B1.now_rotation][i][j] == 0))
					{
						if ((i != 3) && (j != 3))
							gotoxy(B1.x_of_block + ((j + 1) * 2), B1.y_of_block + i);
						else if ((i != 3) && (j == 3))
							gotoxy(B1.x_of_block + (j * 2), B1.y_of_block + i);
						else if ((i == 3) && (j != 3))
							gotoxy(B1.x_of_block + ((j + 1) * 2), B1.y_of_block + i);
						else if ((i == 3) && (j == 3))
							gotoxy(50, 2);
					}
				}
			}

			//key 입력받기
			if (_kbhit())
			{
				key = _getch();
				//↑
				if (key == 72)
				{

					for (int i = 0; i < 4; i++)
					{

						for (int j = 0; j < 4; j++)
						{
							if (abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] == the_number_of_block)
							{
								abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] = 0;
							}
						}
					}

					B1.now_rotation++;
					if (B1.now_rotation == 4)
					{
						B1.now_rotation = (B1.now_rotation % 4);
					}
					key = 0;
				}
				//↓
				else if (key == 80)
				{
					//원래 있던 블럭 지우기
					for (int i = 0; i < 4; i++)
					{
						gotoxy(B1.x_of_block, B1.y_of_block + i);
						for (int j = 0; j < 4; j++)
						{
							if (block[B1.now_type][B1.now_rotation][i][j] == 1)
							{
								gotoxy(B1.x_of_block + (j * 2), B1.y_of_block + i);
								printf("  ");
								abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] = 0;
							}

						}
					}
					//Block 내리기

					if (B1.y_of_block >= 16)
					{
						for (int i = 0; i < 4; i++)
						{
							gotoxy(B1.x_of_block, B1.y_of_block + i);
							for (int j = 0; j < 4; j++)
							{
								if (block[B1.now_type][B1.now_rotation][i][j] == 1)
								{
									printf("▩");
									abs_Board[B1.y_of_block + i][B1.x_of_block + (2 * j)] = the_number_of_block;
								}
								else if ((abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] == 0) && (block[B1.now_type][B1.now_rotation][i][j] == 0))
								{
									printf("  ");
								}
								else if ((abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] != 0) && (block[B1.now_type][B1.now_rotation][i][j] == 0))
								{
									if ((i != 3) && (j != 3))
										gotoxy(B1.x_of_block + ((j + 1) * 2), B1.y_of_block + i);
									else if ((i != 3) && (j == 3))
										gotoxy(B1.x_of_block + (j * 2), B1.y_of_block + i);
									else if ((i == 3) && (j != 3))
										gotoxy(B1.x_of_block + ((j + 1) * 2), B1.y_of_block + i);
									else if ((i == 3) && (j == 3))
										gotoxy(50, 2);

								}
							}
						}
					}
					else
					{
						B1.y_of_block = B1.y_of_block + 3;
						for (int i = 0; i < 4; i++)
						{
							gotoxy(B1.x_of_block, B1.y_of_block + i);
							for (int j = 0; j < 4; j++)
							{
								if (block[B1.now_type][B1.now_rotation][i][j] == 1)
								{
									printf("▩");
									abs_Board[B1.y_of_block + i][B1.x_of_block + (2 * j)] = the_number_of_block;
								}
								else if ((abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] == 0) && (block[B1.now_type][B1.now_rotation][i][j] == 0))
								{
									printf("  ");
								}
								else if ((abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] != 0) && (block[B1.now_type][B1.now_rotation][i][j] == 0))
								{
									if ((i != 3) && (j != 3))
										gotoxy(B1.x_of_block + ((j + 1) * 2), B1.y_of_block + i);
									else if ((i != 3) && (j == 3))
										gotoxy(B1.x_of_block + (j * 2), B1.y_of_block + i);
									else if ((i == 3) && (j != 3))
										gotoxy(B1.x_of_block + ((j + 1) * 2), B1.y_of_block + i);
									else if ((i == 3) && (j == 3))
										gotoxy(50, 2);

								}
							}
						}
					}
				}
				//←
				else if (key == 75)
				{
					int crush = 0;

					for (int i = 0; i < 4; i++)
					{
						for (int j = 0; j < 4; j++)
						{
							if ((abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] == the_number_of_block) && (abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2) - 2]) < the_number_of_block)
							{
								if ((abs_Board[B1.y_of_block][B1.x_of_block + (j * 2) - 2] != 0))
								{
									crush = 1;
								}
							}
						}
					}
					if (crush == 0)
					{
						for (int i = 0; i < 4; i++)
						{
							gotoxy(B1.x_of_block, B1.y_of_block + i);
							for (int j = 0; j < 4; j++)
							{
								if (block[B1.now_type][B1.now_rotation][i][j] == 1)
								{
									gotoxy(B1.x_of_block + (j * 2), B1.y_of_block + i);
									printf("  ");
									abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] = 0;
								}

							}
						}
						for (int i = 0; i < 4; i++)
						{
							for (int j = 0; j < 4; j++)
							{
								if (abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] == the_number_of_block)
								{
									abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] = 0;
								}
							}
						}
						for (int i = 0; i < 4; i++)
						{
							for (int j = 0; j < 4; j++)
							{
								if (block[B1.now_type][B1.now_rotation][i][j] == 1)
								{

									abs_Board[B1.y_of_block + i][B1.x_of_block + ((j - 1) * 2)] = the_number_of_block;
								}
							}
						}
						B1.x_of_block = B1.x_of_block - 2;
					}
					else if (crush == 1) {}
					key = 0;
				}
				//→
				else if (key == 77)
				{
					int crush = 0;

					for (int i = 0; i < 4; i++)
					{
						for (int j = 0; j < 4; j++)
						{
							if ((abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] == the_number_of_block) && (abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2) + 2]) < the_number_of_block)
							{
								if ((abs_Board[B1.y_of_block][B1.x_of_block + (j * 2) + 2] != 0))
								{
									crush = 1;
								}
							}
						}
					}
					if (crush == 0)
					{
						for (int i = 0; i < 4; i++)
						{
							gotoxy(B1.x_of_block, B1.y_of_block + i);
							for (int j = 0; j < 4; j++)
							{
								if (block[B1.now_type][B1.now_rotation][i][j] == 1)
								{
									gotoxy(B1.x_of_block + (j * 2), B1.y_of_block + i);
									printf("  ");
									abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] = 0;
								}

							}
						}
						for (int i = 0; i < 4; i++)
						{
							for (int j = 0; j < 4; j++)
							{
								if (abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] == the_number_of_block)
								{
									abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] = 0;
								}
							}
						}
						for (int i = 0; i < 4; i++)
						{
							for (int j = 0; j < 4; j++)
							{
								if (block[B1.now_type][B1.now_rotation][i][j] == 1)
								{

									abs_Board[B1.y_of_block + i][B1.x_of_block + ((j + 1) * 2)] = the_number_of_block;
								}
							}
						}
						B1.x_of_block = B1.x_of_block + 2;
					}
					else if (crush == 1) {}
					key = 0;
				}
				//enter
				else if (key == 13)
				{
					break;
				}

			}

			//화면에 블럭 만들기
			for (int i = 0; i < 4; i++)
			{
				gotoxy(B1.x_of_block, B1.y_of_block + i);
				for (int j = 0; j < 4; j++)
				{
					if (block[B1.now_type][B1.now_rotation][i][j] == 1)
					{
						printf("▩");
						abs_Board[B1.y_of_block + i][B1.x_of_block + (2 * j)] = the_number_of_block;
					}
					else if ((abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] == 0) && (block[B1.now_type][B1.now_rotation][i][j] == 0))
					{
						printf("  ");
					}
					else if (abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] != 0 && (block[B1.now_type][B1.now_rotation][i][j] == 0))
					{
						if ((i != 3) && (j != 3))
							gotoxy(B1.x_of_block + ((j + 1) * 2), B1.y_of_block + i);
						else if ((i != 3) && (j == 3))
							gotoxy(B1.x_of_block + (j * 2), B1.y_of_block + i);
						else if ((i == 3) && (j != 3))
							gotoxy(B1.x_of_block + ((j + 1) * 2), B1.y_of_block + i);
						else if ((i == 3) && (j == 3))
							gotoxy(50, 2);
					}
				}
			}

			//key 입력받기
			if (_kbhit())
			{
				key = _getch();
				//↑
				if (key == 72)
				{

					for (int i = 0; i < 4; i++)
					{

						for (int j = 0; j < 4; j++)
						{
							if (abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] == the_number_of_block)
							{
								abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] = 0;
							}
						}
					}

					B1.now_rotation++;
					if (B1.now_rotation == 4)
					{
						B1.now_rotation = (B1.now_rotation % 4);
					}
					key = 0;
				}
				//↓
				else if (key == 80)
				{
					//원래 있던 블럭 지우기
					for (int i = 0; i < 4; i++)
					{
						gotoxy(B1.x_of_block, B1.y_of_block + i);
						for (int j = 0; j < 4; j++)
						{
							if (block[B1.now_type][B1.now_rotation][i][j] == 1)
							{
								gotoxy(B1.x_of_block + (j * 2), B1.y_of_block + i);
								printf("  ");
								abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] = 0;
							}

						}
					}
					//Block 내리기

					if (B1.y_of_block >= 16)
					{
						for (int i = 0; i < 4; i++)
						{
							gotoxy(B1.x_of_block, B1.y_of_block + i);
							for (int j = 0; j < 4; j++)
							{
								if (block[B1.now_type][B1.now_rotation][i][j] == 1)
								{
									printf("▩");
									abs_Board[B1.y_of_block + i][B1.x_of_block + (2 * j)] = the_number_of_block;
								}
								else if ((abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] == 0) && (block[B1.now_type][B1.now_rotation][i][j] == 0))
								{
									printf("  ");
								}
								else if ((abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] != 0) && (block[B1.now_type][B1.now_rotation][i][j] == 0))
								{
									if ((i != 3) && (j != 3))
										gotoxy(B1.x_of_block + ((j + 1) * 2), B1.y_of_block + i);
									else if ((i != 3) && (j == 3))
										gotoxy(B1.x_of_block + (j * 2), B1.y_of_block + i);
									else if ((i == 3) && (j != 3))
										gotoxy(B1.x_of_block + ((j + 1) * 2), B1.y_of_block + i);
									else if ((i == 3) && (j == 3))
										gotoxy(50, 2);

								}
							}
						}
					}
					else
					{
						B1.y_of_block = B1.y_of_block + 3;
						for (int i = 0; i < 4; i++)
						{
							gotoxy(B1.x_of_block, B1.y_of_block + i);
							for (int j = 0; j < 4; j++)
							{
								if (block[B1.now_type][B1.now_rotation][i][j] == 1)
								{
									printf("▩");
									abs_Board[B1.y_of_block + i][B1.x_of_block + (2 * j)] = the_number_of_block;
								}
								else if ((abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] == 0) && (block[B1.now_type][B1.now_rotation][i][j] == 0))
								{
									printf("  ");
								}
								else if ((abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] != 0) && (block[B1.now_type][B1.now_rotation][i][j] == 0))
								{
									if ((i != 3) && (j != 3))
										gotoxy(B1.x_of_block + ((j + 1) * 2), B1.y_of_block + i);
									else if ((i != 3) && (j == 3))
										gotoxy(B1.x_of_block + (j * 2), B1.y_of_block + i);
									else if ((i == 3) && (j != 3))
										gotoxy(B1.x_of_block + ((j + 1) * 2), B1.y_of_block + i);
									else if ((i == 3) && (j == 3))
										gotoxy(50, 2);

								}
							}
						}
					}
				}
				//←
				else if (key == 75)
				{
					int crush = 0;

					for (int i = 0; i < 4; i++)
					{
						for (int j = 0; j < 4; j++)
						{
							if ((abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] == the_number_of_block) && (abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2) - 2]) < the_number_of_block)
							{
								if ((abs_Board[B1.y_of_block][B1.x_of_block + (j * 2) - 2] != 0))
								{
									crush = 1;
								}
							}
						}
					}
					if (crush == 0)
					{
						for (int i = 0; i < 4; i++)
						{
							gotoxy(B1.x_of_block, B1.y_of_block + i);
							for (int j = 0; j < 4; j++)
							{
								if (block[B1.now_type][B1.now_rotation][i][j] == 1)
								{
									gotoxy(B1.x_of_block + (j * 2), B1.y_of_block + i);
									printf("  ");
									abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] = 0;
								}

							}
						}
						for (int i = 0; i < 4; i++)
						{
							for (int j = 0; j < 4; j++)
							{
								if (abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] == the_number_of_block)
								{
									abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] = 0;
								}
							}
						}
						for (int i = 0; i < 4; i++)
						{
							for (int j = 0; j < 4; j++)
							{
								if (block[B1.now_type][B1.now_rotation][i][j] == 1)
								{

									abs_Board[B1.y_of_block + i][B1.x_of_block + ((j - 1) * 2)] = the_number_of_block;
								}
							}
						}
						B1.x_of_block = B1.x_of_block - 2;
					}
					else if (crush == 1) {}
					key = 0;
				}
				//→
				else if (key == 77)
				{
					int crush = 0;

					for (int i = 0; i < 4; i++)
					{
						for (int j = 0; j < 4; j++)
						{
							if ((abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] == the_number_of_block) && (abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2) + 2]) < the_number_of_block)
							{
								if ((abs_Board[B1.y_of_block][B1.x_of_block + (j * 2) + 2] != 0))
								{
									crush = 1;
								}
							}
						}
					}
					if (crush == 0)
					{
						for (int i = 0; i < 4; i++)
						{
							gotoxy(B1.x_of_block, B1.y_of_block + i);
							for (int j = 0; j < 4; j++)
							{
								if (block[B1.now_type][B1.now_rotation][i][j] == 1)
								{
									gotoxy(B1.x_of_block + (j * 2), B1.y_of_block + i);
									printf("  ");
									abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] = 0;
								}

							}
						}
						for (int i = 0; i < 4; i++)
						{
							for (int j = 0; j < 4; j++)
							{
								if (abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] == the_number_of_block)
								{
									abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] = 0;
								}
							}
						}
						for (int i = 0; i < 4; i++)
						{
							for (int j = 0; j < 4; j++)
							{
								if (block[B1.now_type][B1.now_rotation][i][j] == 1)
								{

									abs_Board[B1.y_of_block + i][B1.x_of_block + ((j + 1) * 2)] = the_number_of_block;
								}
							}
						}
						B1.x_of_block = B1.x_of_block + 2;
					}
					else if (crush == 1) {}
					key = 0;
				}
				//enter
				else if (key == 13)
				{
					break;
				}

			}

			//화면에 블럭 만들기
			for (int i = 0; i < 4; i++)
			{
				gotoxy(B1.x_of_block, B1.y_of_block + i);
				for (int j = 0; j < 4; j++)
				{
					if (block[B1.now_type][B1.now_rotation][i][j] == 1)
					{
						printf("▩");
						abs_Board[B1.y_of_block + i][B1.x_of_block + (2 * j)] = the_number_of_block;
					}
					else if ((abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] == 0) && (block[B1.now_type][B1.now_rotation][i][j] == 0))
					{
						printf("  ");
					}
					else if (abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] != 0 && (block[B1.now_type][B1.now_rotation][i][j] == 0))
					{
						if ((i != 3) && (j != 3))
							gotoxy(B1.x_of_block + ((j + 1) * 2), B1.y_of_block + i);
						else if ((i != 3) && (j == 3))
							gotoxy(B1.x_of_block + (j * 2), B1.y_of_block + i);
						else if ((i == 3) && (j != 3))
							gotoxy(B1.x_of_block + ((j + 1) * 2), B1.y_of_block + i);
						else if ((i == 3) && (j == 3))
							gotoxy(50, 2);
					}
				}
			}

			//내려오는 속도
			Sleep(basic_speed_of_game);

			for (int i = 0; i < 4; i++)
			{
				gotoxy(B1.x_of_block, B1.y_of_block + i);
				for (int j = 0; j < 4; j++)
				{
					if (block[B1.now_type][B1.now_rotation][i][j] == 1)
					{
						gotoxy(B1.x_of_block + (j * 2), B1.y_of_block + i);
						printf("  ");
						abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] = 0;
					}

				}
			}

			//Block 한 칸 내리기
			B1.y_of_block++;
			for (int i = 0; i < 4; i++)
			{
				gotoxy(B1.x_of_block, B1.y_of_block + i);
				for (int j = 0; j < 4; j++)
				{
					if (block[B1.now_type][B1.now_rotation][i][j] == 1)
					{
						printf("▩");
						abs_Board[B1.y_of_block + i][B1.x_of_block + (2 * j)] = the_number_of_block;
					}
					else if ((abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] == 0) && (block[B1.now_type][B1.now_rotation][i][j] == 0))
					{
						printf("  ");
					}
					else if ((abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] != 0) && (block[B1.now_type][B1.now_rotation][i][j] == 0))
					{
						if ((i != 3) && (j != 3))
							gotoxy(B1.x_of_block + ((j + 1) * 2), B1.y_of_block + i);
						else if ((i != 3) && (j == 3))
							gotoxy(B1.x_of_block + (j * 2), B1.y_of_block + i);
						else if ((i == 3) && (j != 3))
							gotoxy(B1.x_of_block + ((j + 1) * 2), B1.y_of_block + i);
						else if ((i == 3) && (j == 3))
							gotoxy(50, 2);

					}
				}
			}

			//key 입력받기
			if (_kbhit())
			{
				key = _getch();
				//↑
				if (key == 72)
				{

					for (int i = 0; i < 4; i++)
					{

						for (int j = 0; j < 4; j++)
						{
							if (abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] == the_number_of_block)
							{
								abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] = 0;
							}
						}
					}

					B1.now_rotation++;
					if (B1.now_rotation == 4)
					{
						B1.now_rotation = (B1.now_rotation % 4);
					}
					key = 0;
				}
				//↓
				else if (key == 80)
				{
					//원래 있던 블럭 지우기
					for (int i = 0; i < 4; i++)
					{
						gotoxy(B1.x_of_block, B1.y_of_block + i);
						for (int j = 0; j < 4; j++)
						{
							if (block[B1.now_type][B1.now_rotation][i][j] == 1)
							{
								gotoxy(B1.x_of_block + (j * 2), B1.y_of_block + i);
								printf("  ");
								abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] = 0;
							}

						}
					}
					//Block 내리기

					if (B1.y_of_block >= 16)
					{
						for (int i = 0; i < 4; i++)
						{
							gotoxy(B1.x_of_block, B1.y_of_block + i);
							for (int j = 0; j < 4; j++)
							{
								if (block[B1.now_type][B1.now_rotation][i][j] == 1)
								{
									printf("▩");
									abs_Board[B1.y_of_block + i][B1.x_of_block + (2 * j)] = the_number_of_block;
								}
								else if ((abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] == 0) && (block[B1.now_type][B1.now_rotation][i][j] == 0))
								{
									printf("  ");
								}
								else if ((abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] != 0) && (block[B1.now_type][B1.now_rotation][i][j] == 0))
								{
									if ((i != 3) && (j != 3))
										gotoxy(B1.x_of_block + ((j + 1) * 2), B1.y_of_block + i);
									else if ((i != 3) && (j == 3))
										gotoxy(B1.x_of_block + (j * 2), B1.y_of_block + i);
									else if ((i == 3) && (j != 3))
										gotoxy(B1.x_of_block + ((j + 1) * 2), B1.y_of_block + i);
									else if ((i == 3) && (j == 3))
										gotoxy(50, 2);

								}
							}
						}
					}
					else
					{
						B1.y_of_block = B1.y_of_block + 3;
						for (int i = 0; i < 4; i++)
						{
							gotoxy(B1.x_of_block, B1.y_of_block + i);
							for (int j = 0; j < 4; j++)
							{
								if (block[B1.now_type][B1.now_rotation][i][j] == 1)
								{
									printf("▩");
									abs_Board[B1.y_of_block + i][B1.x_of_block + (2 * j)] = the_number_of_block;
								}
								else if ((abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] == 0) && (block[B1.now_type][B1.now_rotation][i][j] == 0))
								{
									printf("  ");
								}
								else if ((abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] != 0) && (block[B1.now_type][B1.now_rotation][i][j] == 0))
								{
									if ((i != 3) && (j != 3))
										gotoxy(B1.x_of_block + ((j + 1) * 2), B1.y_of_block + i);
									else if ((i != 3) && (j == 3))
										gotoxy(B1.x_of_block + (j * 2), B1.y_of_block + i);
									else if ((i == 3) && (j != 3))
										gotoxy(B1.x_of_block + ((j + 1) * 2), B1.y_of_block + i);
									else if ((i == 3) && (j == 3))
										gotoxy(50, 2);

								}
							}
						}
					}
				}
				//←
				else if (key == 75)
				{
					int crush = 0;

					for (int i = 0; i < 4; i++)
					{
						for (int j = 0; j < 4; j++)
						{
							if ((abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] == the_number_of_block) && (abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2) - 2]) < the_number_of_block)
							{
								if ((abs_Board[B1.y_of_block][B1.x_of_block + (j * 2) - 2] != 0))
								{
									crush = 1;
								}
							}
						}
					}
					if (crush == 0)
					{
						for (int i = 0; i < 4; i++)
						{
							gotoxy(B1.x_of_block, B1.y_of_block + i);
							for (int j = 0; j < 4; j++)
							{
								if (block[B1.now_type][B1.now_rotation][i][j] == 1)
								{
									gotoxy(B1.x_of_block + (j * 2), B1.y_of_block + i);
									printf("  ");
									abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] = 0;
								}

							}
						}
						for (int i = 0; i < 4; i++)
						{
							for (int j = 0; j < 4; j++)
							{
								if (abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] == the_number_of_block)
								{
									abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] = 0;
								}
							}
						}
						for (int i = 0; i < 4; i++)
						{
							for (int j = 0; j < 4; j++)
							{
								if (block[B1.now_type][B1.now_rotation][i][j] == 1)
								{

									abs_Board[B1.y_of_block + i][B1.x_of_block + ((j - 1) * 2)] = the_number_of_block;
								}
							}
						}
						B1.x_of_block = B1.x_of_block - 2;
					}
					else if (crush == 1) {}
					key = 0;
				}
				//→
				else if (key == 77)
				{
					int crush = 0;

					for (int i = 0; i < 4; i++)
					{
						for (int j = 0; j < 4; j++)
						{
							if ((abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] == the_number_of_block) && (abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2) + 2]) < the_number_of_block)
							{
								if ((abs_Board[B1.y_of_block][B1.x_of_block + (j * 2) + 2] != 0))
								{
									crush = 1;
								}
							}
						}
					}
					if (crush == 0)
					{
						for (int i = 0; i < 4; i++)
						{
							gotoxy(B1.x_of_block, B1.y_of_block + i);
							for (int j = 0; j < 4; j++)
							{
								if (block[B1.now_type][B1.now_rotation][i][j] == 1)
								{
									gotoxy(B1.x_of_block + (j * 2), B1.y_of_block + i);
									printf("  ");
									abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] = 0;
								}

							}
						}
						for (int i = 0; i < 4; i++)
						{
							for (int j = 0; j < 4; j++)
							{
								if (abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] == the_number_of_block)
								{
									abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] = 0;
								}
							}
						}
						for (int i = 0; i < 4; i++)
						{
							for (int j = 0; j < 4; j++)
							{
								if (block[B1.now_type][B1.now_rotation][i][j] == 1)
								{

									abs_Board[B1.y_of_block + i][B1.x_of_block + ((j + 1) * 2)] = the_number_of_block;
								}
							}
						}
						B1.x_of_block = B1.x_of_block + 2;
					}
					else if (crush == 1) {}
					key = 0;
				}
				//enter
				else if (key == 13)
				{
					break;
				}

			}

			//화면에 블럭 만들기
			for (int i = 0; i < 4; i++)
			{
				gotoxy(B1.x_of_block, B1.y_of_block + i);
				for (int j = 0; j < 4; j++)
				{
					if (block[B1.now_type][B1.now_rotation][i][j] == 1)
					{
						printf("▩");
						abs_Board[B1.y_of_block + i][B1.x_of_block + (2 * j)] = the_number_of_block;
					}
					else if ((abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] == 0) && (block[B1.now_type][B1.now_rotation][i][j] == 0))
					{
						printf("  ");
					}
					else if (abs_Board[B1.y_of_block + i][B1.x_of_block + (j * 2)] != 0 && (block[B1.now_type][B1.now_rotation][i][j] == 0))
					{
						if ((i != 3) && (j != 3))
							gotoxy(B1.x_of_block + ((j + 1) * 2), B1.y_of_block + i);
						else if ((i != 3) && (j == 3))
							gotoxy(B1.x_of_block + (j * 2), B1.y_of_block + i);
						else if ((i == 3) && (j != 3))
							gotoxy(B1.x_of_block + ((j + 1) * 2), B1.y_of_block + i);
						else if ((i == 3) && (j == 3))
							gotoxy(50, 2);
					}
				}
			}



			//abs_board 출력 프로그램
			gotoxy(50, 1);
			for (int j = 0; j < Board_Height; j++)
			{
				for (int i = 0; i < (Board_Width * 2); i++)
				{
					printf("%d", abs_Board[j][i]);
				}
				gotoxy(50, 1 + j);
			}

			//crush or not
			for (int j = 0; j < 4; j++)
			{
				for (int i = 0; i < 4; i++)
				{
					if ((abs_Board[B1.y_of_block + j][B1.x_of_block + (i * 2)] == the_number_of_block) && (abs_Board[B1.y_of_block + j + 1][B1.x_of_block + (i * 2)] < the_number_of_block))
					{
						if (abs_Board[B1.y_of_block + j + 1][B1.x_of_block + (i * 2)] != 0)
						{
							if (the_number_of_block != 1)
							{
								crush_block = 1;
								break;
							}
						}
					}
				}
				if (crush_block == 1)
				{
					break;
				}
			}
		}

		// 1줄이 채워진다면 줄 비워주기
		for (int i = 20; i > 0; i--)
		{
			for (int j = 1; j < 11; j++)
			{
				if (abs_Board[i][2 * j] != 0)
				{
					full_of_line[i]++;
				}
			}
			if (full_of_line[i] == 10)
			{
				//지우기
				for (int y2 = i; (y2) > 1; (y2)--)
				{
					for (int x2 = 1; (x2) < 11; (x2)++)
					{
						gotoxy(2 * (x2), y2);
						printf("  ");
					}
				}
				for (int y1 = i; (y1) > 1; (y1)--)
				{
					for (int x1 = 1; (x1) < 11; (x1)++)
					{
						if (y1 == i)
						{
							gotoxy(2 * (x1), y1);
							printf("뿅");
						}
					}
				}
				Sleep(200);
				for (int y2 = i; (y2) > 1; (y2)--)
				{
					for (int x2 = 1; x2 < 11; x2++)
					{
						gotoxy(2 * (x2), y2);
						printf("  ");
					}
				}

				for (int y3 = i; y3 > 1; y3--)
				{
					for (int x3 = 1; x3 < 11; x3++)
					{
						abs_Board[y3][2 * (x3)] = 0;
						abs_Board[y3][2 * (x3)] = abs_Board[(y3)-1][2 * (x3)];


						if (abs_Board[y3][2 * (x3)] != 0)
						{
							gotoxy(2 * (x3), y3);
							printf("▩");
						}

						else if (abs_Board[y3][2 * (x3)] == 0)
						{
							gotoxy(2 * (x3), y3);
							printf("  ");
						}
					}
				}
			}

			full_of_line[i] = 0;
		}

	}

	//게임이 종료 되고 난 후
	for (int i = 0; i < 4; i++)
	{
		system("cls");
		gotoxy(30, 9 - i);
		printf("===================================================");
		gotoxy(30, 10 - i);
		printf("게 임 을   이 용 해   주 셔 서   감 사 합 니 다 .");
		gotoxy(30, 11 - i);
		printf("===================================================");

		Sleep(50);
	}
	for (int i = 0; i < 21; i++)
	{
		if (i % 3 == 0)
		{
			system("cls");
			gotoxy(30, 6 + i);
			printf("===================================================");
			gotoxy(30, 7 + i);
			printf("게 임 을   이 용 해   주 셔 서   감 사 합 니 다 .");
			gotoxy(30, 8 + i);
			printf("===================================================");
			Sleep(50);
		}
		else if (i % 3 == 1)
		{
			system("cls");
			gotoxy(30, 6 + i);
			printf("===임=============해=====셔==========사========다===");
			gotoxy(30, 7 + i);
			printf("게         이         주    서          합         .");
			gotoxy(30, 8 + i);
			printf("======을======용=================감========니======");
			Sleep(50);
		}
		else
		{
			system("cls");
			gotoxy(30, 6 + i);
			printf("===임=========용==해============감=======합=====다===");
			gotoxy(30, 7 + i);
			printf("          이         주    서        사           .");
			gotoxy(30, 8 + i);
			printf("게====을================셔=================니======");
			Sleep(50);
		}

	}
	system("cls");
	gotoxy(30, 27);
	printf("===================================================");
	gotoxy(30, 28);
	printf("게 임 을   이 용 해   주 셔 서   감 사 합 니 다 .");
	Sleep(50);
	system("cls");
	gotoxy(30, 28);
	printf("===================================================");
	Sleep(50);
	system("cls");



	printf("\n\n\n\n\n\n\n\n\n\n");

}




int main(void)
{
	Game_start();


	return 0;
}
