#include<stdio.h>

#include<stdlib.h>





typedef struct Book {

	int num;

	char title[50];

	char author[50];



	struct Book* next;

}Book;



void add_book(Book* head) {

	Book* add_book = (Book*)malloc(sizeof(Book));



	printf("\n\n책의 정보를 입력해주세요\n");

	printf("책 번호 : ");

	scanf("%d", &add_book->num);

	printf("책 제목 : ");

	scanf("%s", &add_book->title);

	printf("책 저자 : ");

	scanf("%s", &add_book->author);







	add_book->next = head->next;

	head->next = add_book;



	printf("\n 등록이 완료되었습니다. \n");

}



void del_book(Book* head) {



	int del_num = 0, find = 0;

	printf("삭제하고 싶은 책 번호를 입력해 주세요");

	scanf("%d", &del_num);



	Book* target = head->next, * pre_target = head;

	for (; target != NULL; target = target->next) {

		if (target->num == del_num) {

			pre_target->next = target->next;

			free(target);

			find = 1;

			break;

		}

		pre_target = pre_target->next;

	}

	if (!find) printf("\n삭제하고자 하시는 책이 없습니다.\n");

}



void find_book(Book* head) {

	int find_num = 0, find = 0;

	printf("\n검색하고 싶은 책 번호를 입력해 주세요\n");

	scanf(" %d", &find_num);



	Book* target = head->next;

	for (; target != NULL; target = target->next) {

		if (target->num == find_num) {

			printf(" 책 번호 : %d  책 제목 : %s 책 저자 : %s", target->num, target->title, target->author);

			find = 1;

			break;

		}

	}

	if (!find) printf("\n찾으시는 책이 없습니다.\n");

}



void print_all(Book* head) {

	Book* target = head->next;



	if (target == NULL) {

		printf("책이 없습니다.");

	}

	for (; target != NULL; target = target->next) {

		printf("%d.  책 제목 : %s 책 저자 : %s\n", target->num, target->title, target->author);

	}



}



void end_prog(Book* head) {

	Book* target = head->next;

	free(head);



	for (; target != NULL; target = target->next) {

		head = target;

		target = head->next;

		free(head);

	}

	printf("\n<<<종료>>>\n");

}



int main() {

	printf("<< 도서관 프로그램 >>");

	

	Book* head = (Book*)malloc(sizeof(Book));

	head->next = NULL;



	int sel_mode = 0;

	while (1) {

		printf("\n원하는 기능을 선택해 주세요. \n 1.추가 \n 2.삭제 \n 3.전체 출력 \n 4.검색 \n 5.종료 \n >>   ");

		scanf(" %d", &sel_mode);

		

		switch (sel_mode)

		{

		case 1:

			add_book(head);

			break;

		case 2:

			del_book(head);

			break;

		case 3:

			print_all(head);

			break;

		case 4:

			find_book(head);

			break;

		case 5:

			end_prog(head);

			break;

		default:

			printf("\n다시 선택해 주세요\n");

			break;

		}



		if (sel_mode == 5) break;

	}





	return 0;

}
