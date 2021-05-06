

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int* answer;
int* player;
int strike = 0, ball = 0, level_selection = 0, trial = 0;

void level_set()
{
	printf("\n<<< 난이도를 설정해주세요 ! >>>  ");
	scanf("%d", &level_selection);
	player = (int*)calloc(level_selection, sizeof(int));
	if (player == NULL) printf("메모리가 부족합니다.");
	answer = (int*)calloc(level_selection, sizeof(int));
	if (answer == NULL) printf("메모리가 부족합니다.");
}

void initiliaze()
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < level_selection;)
	{
		int num = rand() % 10;
		char ovl = 'N';

		for (int k = 0; k < level_selection; k++)
			if (answer[k] == num)
				ovl = 'Y';

		if (ovl == 'N')
		{
			answer[i] = num;
			printf(" computer[%d]: %d \n", i + 1, answer[i]);
			i++;
		}
		else
			ovl = 'N';
	}
}

int get_input(int* player)
{

	for (int i = 0; i < level_selection; i++)
	{
		printf("%d 번 째 숫자: ", i + 1);
		scanf("%d", &player[i]);
	}

	for (int i = 0; i < level_selection; i++)
		if ((player[i] <= 0) || (player[i] > 9))
			return 1;
	return 0;
}

void compare_answer_player(int* answer, int* player)
{
	strike = 0;
	ball = 0;

	for (int i = 0; i < level_selection; i++)
	{

		if (*(answer + i) == *(player + i))
			strike++;
		else
			for (int j = 0; j < level_selection; j++)
			{
				if (*(answer + j) == *(player + i))
					ball++;
			}
	}
}

int print_and_check_result()
{
	printf("\nstrike : %d  ball: %d\n", strike, ball);

	if (strike == level_selection)
		return 1;
	else
		return 0;
}

int main()
{
	char out = '\0';
	printf("\n<<< 숫자야구 게임 >>>\n");

	while ((out != 'Y')||(out != 'y'))
	{
		level_set();
		initiliaze();

		for (trial = 0; ; trial++)
		{
		re:
			printf("\n[현재 회차: %d]\n숫자를 입력해 주세요(띄어쓰기 구분) \n", trial + 1);
			int err = get_input(player);

			// 10이상의 수나 음수를 입력 받았을 때 (err == 1)
			if (err)
			{
				printf("\n10 이하의 양수를 입력해 주세요! \n");
				goto re;
			}
			compare_answer_player(answer, player);

			int victory = print_and_check_result();
			if (victory)
			{
				printf("\n\n축하합니다 승리했습니다 ! 짝짝짝 \n\n");
				break;
			}
		}

		printf("종료 하시겠습니까 ? y or n ");
		scanf(" %c",&out);
		if (out == 'y') break;
	}

	printf("<<< 이용해 주셔서 감사합니다 >>>\n");

	return 0;
}
