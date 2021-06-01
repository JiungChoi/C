#include <stdio.h>
#include <string.h>

// 연락처 구조체 정의
struct address {
	char name[30];
	char age[5];
	char phone[15];
};

void print_menu();
void view_juso();
void add_juso();
void delete_juso();

// 연락처 파일명을 전역변수로 고정
const char *fname = "c:\\temp\\juso.txt";

int main()
{
	char select = 0;
	puts(" \n### 친구 핸펀 Ver 2.0 ### \n");

	while (select != 4)
	{
		print_menu();
		select = getche();
		getchar();

		switch (select)
		{
		case '1': view_juso();
			break;
		case '2': add_juso();
			break;
		case '3': delete_juso();
			break;
		case '4': return 0;
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
	printf("4. 끝내기 \n");
}

// 연락처 파일에서 기존 입력된 내용을 읽어서 출력
void view_juso()
{
	char str[200] = "";
	FILE *rfp, *wfp;
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
void add_juso()
{
	struct address adr = { "", "", "" };
	char wstr[200] = "";
	FILE *wfp;

	wfp = fopen(fname, "a"); // 파일 추가 모드로 열기

	printf("이름을 입력 ==> ");
	gets(adr.name);
	printf("나이를 입력 ==> ");
	gets(adr.age);
	printf("전화번호를 입력 ==> ");
	gets(adr.phone);

	// 입력된 3개의 값을 하나의 문자열로 만듦
	strcat(wstr, adr.name);
	strcat(wstr, "\t");
	strcat(wstr, adr.age);
	strcat(wstr, "\t");
	strcat(wstr, adr.phone);
	strcat(wstr, "\n");

	fputs(wstr, wfp);  // 파일에 문자열 쓰기

	fclose(wfp);
}

// 연락처 파일에서 선택한 연락처를 제거
void delete_juso()
{
	// 연락처 파일의 내용 전체를 저장하기 위한 2차원 배열
	char read_str[50][200] = { "", }; // 최대 연락처 개수를 50개로 가정

	char str[200] = "";
	FILE *rfp, *wfp;
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

