
#include<stdio.h>
#include<malloc.h>

struct student {
	char name[10];
	int age;
};

void get_input(int num_stu, struct student* data);

int main()
{
	struct student* s;

	int cnt, i;

	printf("입력할 학생 수: ");
	scanf("%d", &cnt);

	s = (struct student*)malloc((sizeof(struct student)) * cnt);
	get_input(cnt, s);

	printf("\n\n-- 학생 명단 --\n\n");
	for (i = 0; i < cnt; i++)
	{
		printf("이름: %s, 나이: %d \n", s[i].name, s[i].age);
	}

	free(s);
	return 0;
}

void get_input(int num_stu, struct student* data)
{
	for (int i = 0; i < num_stu; i++)
	{
		printf("이름과 나이 입력: ");
		scanf("%s %d", &data[i].name, &data[i].age);
	}
}
