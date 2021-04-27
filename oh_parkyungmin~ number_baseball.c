#include<stdio.h>

void game(int* computer)
{
	int my_answer[4];
	int strike = 0;
	int ball = 0;
	printf("숫자열을 입력해 주세요 (띄워쓰기 구분): ");
	scanf("%d %d %d",&my_answer[0], &my_answer[1], &my_answer[2]);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (my_answer[i] == computer[i])
				strike++;
			else if (my_answer[i] == computer[j])
				ball++;
		}
	}
	
	if (strike/3 != 3)
	{
		printf("\n\n ㅜㅜ %d strike %d ball~! \n\n", strike/3 , ball);
		game(computer);
	}

	printf("맞아요~! 아야 아야!");
	
	return;
}


int main()
{
	int computer[4] = {1, 2, 3};

	printf("짝짝짝 환영합니다 어서오세요 야구 게임이에요 방긋!\n");

	game(computer);
 
	return 0;

}

