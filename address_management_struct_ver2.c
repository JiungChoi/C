#include <stdio.h>
#include <string.h>

#define MAX_NUM 50
const char* fname = "c:\\temp\\juso.txt"; // 연락처 파일명
struct address {
	char name[30];
	char age[5];
	char phone[15];
};

int how_many_address();
void address_set(int* cnt, struct address* set);
void print_menu();
void view_juso();
void add_juso(int* cnt, struct address* input);
void delete_juso();
void find_juso(int* cnt, struct address* find_list);

int main()
{
	puts(" \n### 친구 핸펀 Ver 2.0 ### \n");
	struct address add_list[MAX_NUM];
	int cnt = how_many_address(); //현재 저장한 연락처 수
	address_set(&cnt,add_list);
	char select = 0;

	while (select != 4)
	{
		print_menu();
		printf("\n>> ");
		select = getche();
		printf(" 번을 선택하셨습니다. \n");

		switch (select)
		{
		case '1': view_juso();
			break;
		case '2': add_juso(&cnt, add_list);
			break;
		case '3': delete_juso();
			break;
		case '4': find_juso(&cnt, add_list);
			break;
		case '5': return 0;
			break;
		default: printf("\n 잘못 입력했어요. 다시 선택하세요.\n");
		}
	}

	return 0;
}

// 처음에 사용자의 선택을 위한 메뉴 출력
void print_menu()
{
	printf("\n");
	printf("1. 연락처 출력 \n");
	printf("2. 연락처 등록 \n");
	printf("3. 연락처 삭제 \n");
	printf("4. 연락처 검색 \n");
	printf("5. 저장 후 끝내기 \n");
}

//연락처에 몇개의 주소가 저장된지 리턴
int how_many_address()
{
	int i = 0;
	char str[200] = "";
	FILE* rfp; 
	rfp = fopen(fname,"r");

	if (rfp == NULL)
		return 0;

	for (i = 0; ; i++)
	{
		fgets(str, 200, rfp);
		if(feof(rfp))
		{
			fclose(rfp);
			printf("\n<<주소록 인원 : %d명>> \n",i);
			return i;
		}
	}
}

//텍스트 파일로 불러온 주소 add_list 배열에 순서대로 저장
void address_set(int* cnt, struct address* set)
{
	FILE* rfp;

	rfp = fopen(fname, "r");

	for (int i = 0; i < *cnt; i++)
	{
		fscanf(rfp,"%s %s %s",set[i].name, set[i].age, set[i].phone);
	}
	fclose(rfp);
}

// 연락처 파일에서 기존 입력된 내용을 읽어서 출력
void view_juso()
{
	char str[200] = "";
	FILE* rfp, * wfp;
	int i;

	rfp = fopen(fname, "r");

	// 만약, 연락처 파일이 없다면 빈파일을 만듦
	if (rfp == NULL)
	{
		wfp = fopen(fname, "w");
		fclose(wfp);
		rfp = fopen(fname, "r");
	}

	// 기존의 연락처를 모두 읽어서 출력
	for (i = 1; ; i++)  // i는 계속 1씩 증가하는 무한루프
	{
		fgets(str, 200, rfp);

		if (feof(rfp))
			break;

		printf("%2d:  %s", i, str);
	}

	// i가 1이면 실제 파일에는 내용이 없음
	if (i == 1)
		puts("\n ** 연락처 파일에 전화번호가 하나도 없어요. **\n");

	fclose(rfp);
}

// 연락처를 추가
void add_juso(int* cnt, struct address* input)
{
	struct address temp;
	char in_file[MAX_NUM][200] = { "", };
	char wstr[200] = "";
	FILE* wfp;

	wfp = fopen(fname, "w");

	printf("\n이름을 입력 ==> ");
	gets(input[*cnt].name);
	printf("나이를 입력 ==> ");
	gets(input[*cnt].age);
	printf("전화번호를 입력 ==> ");
	gets(input[*cnt].phone);

	*cnt += 1;

	if (*cnt > 1)
	{
		for (int i = 0; i < *cnt; i++)
		{
			for (int j = i + 1; j < *cnt; j++)
			{
				if (strcmp(input[j].name, input[i].name) < 0)
				{
					temp = input[j];
					input[j] = input[i];
					input[i] = temp;
				}
			}
		}
	}

	for (int i = 0; i < *cnt; i++)
	{
		strcat(in_file[i], input[i].name);
		strcat(in_file[i], "\t");
		strcat(in_file[i], input[i].age);
		strcat(in_file[i], "\t");
		strcat(in_file[i], input[i].phone);
		strcat(in_file[i], "\n");
	}
	for (int i = 0; i < *cnt; i++)
	{
		fputs(in_file[i], wfp);
	}

	fclose(wfp);
}

// 연락처 파일에서 선택한 연락처를 제거
void delete_juso()
{
	// 연락처 파일의 내용 전체를 저장하기 위한 2차원 배열
	char read_str[50][200] = { "", }; // 최대 연락처 개수를 50개로 가정

	char str[200] = "";
	FILE* rfp, * wfp;
	int del_line, i, count = 0;

	rfp = fopen(fname, "r");

	// 연락처 파일이 없으면 돌아간다.
	if (rfp == NULL)
	{
		puts("\n!! 연락처 파일이 없습니다. !!\n");
		return;
	}

	printf("\n삭제할 행 번호는 ? ");
	scanf("%d", &del_line);

	for (i = 0; i < 50; i++)  // 파일에 있는 동안에 수행, 단 최대 50개
	{
		strcpy(str, "");
		fgets(str, 200, rfp);

		if (i + 1 != del_line)  // 삭제하는 행이 아니라면, 추가
		{
			strcpy(read_str[i], str);
			count++;
		}
		else
			printf("%d 행이 삭제되었습니다. \n", del_line);

		if (feof(rfp))
			break;
	}

	fclose(rfp);

	// 파일을 쓰기 모드로 열고, 새로운 내용을 쓴다.
	wfp = fopen(fname, "w");

	for (i = 0; i < count; i++)
		fputs(read_str[i], wfp);

	fclose(wfp);
}

void find_juso(int* cnt, struct address* find_list)
{
	int find_num = 0;
	printf("검색하고 싶은 번호를 입력하세요: ");
	scanf("%d", &find_num);


	if ((0 < find_num)&(find_num<= *cnt))
		printf("\n\n<<검색 완료>>\n[%d : %s %s %s]\n", find_num, find_list[find_num - 1].name, find_list[find_num - 1].age, find_list[find_num - 1].phone);
	else
		printf("\n <<검색에 실패했습니다>> \n1~%d 사이의 번호를 입력해 주세요.\n", *cnt);
}
