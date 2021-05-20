#include<stdio.h>
#include<malloc.h>

typedef struct
{
	int num;
	char name[20];
	int kor, eng, mat;
	int tot;
	double avg;
	char grade;

}Student;

int cnt = 0;

void input_data(Student* pary);

void calc_data(Student* pary);

void sort_data(Student* pary);

void print_data(Student* pary);

int main()
{
	printf("학생 수 입력: ");
	scanf("%d", &cnt);

	Student* ary;
	ary = (struct student*)malloc(sizeof(Student) * cnt);

	input_data(ary);

	calc_data(ary);

	printf("# 정렬 전 데이터... \n");
	print_data(ary);
	sort_data(ary);
	printf("# 정렬 후 데이터... \n");
	print_data(ary);

	return 0;
}



void input_data(Student* pary)
{

	for (int i = 0; i < cnt; i++)
	{
		printf("학번: ");
		scanf("%d", &pary[i].num);
		printf("이름: ");
		scanf("%s", &pary[i].name);
		printf("국어, 영어, 수학 점수: ");
		scanf("%d %d %d", &pary[i].kor, &pary[i].eng, &pary[i].mat);
	}
}

void calc_data(Student* pary)
{
	for (int i = 0; i < cnt; i++)
	{
		pary[i].tot = pary[i].kor + pary[i].eng + pary[i].mat;
		pary[i].avg = pary[i].tot / 3;

		if (pary[i].avg >= 90)
			pary[i].grade = 'A';
		else if (pary[i].avg >= 80)
			pary[i].grade = 'B';
		else if (pary[i].avg >= 70)
			pary[i].grade = 'C';
		else
			pary[i].grade = 'F';
	}
}

void sort_data(Student* pary)
{
	Student* q, * p;

	Student temp;
	for (int i = 0; i < cnt - 1; i++)
	{
		p = pary + i;
		q = p + 1;
		for (int k = 0; k < cnt - 1 - i; k++)
		{
			q = q + k;
			if (p[i].avg < q[i].avg)
			{
				temp = *p;
				*p = *q;
				*q = temp;
			}
		}
	}
}

void print_data(Student* pary)
{
	for (int i = 0; i < cnt; i++)
	{
		printf("%10d %20s %10d %10d %10d %10d %10f %10c\n", pary[i].num, pary[i].name, pary[i].kor, pary[i].eng, pary[i].mat, pary[i].tot, pary[i].avg, pary[i].grade);
	}
}


