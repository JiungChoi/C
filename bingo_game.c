#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 5x5 빙고 판 만들기
// 숫자는 1~25까지 만들고 중복없이 2차원배열에 넣어주세요 !
// 30분까지 시간 드리겠습니다.
// 다하신분은 코드를 개인톡으로 보내주세요 !

void main() {
   int generatedArray[26] = { 0, };
   int bingo[5][5];
   int generatedNumber = 0;
   int inputRow = 0, inputCol = 0;

   srand(time(NULL));

   for (int row = 0; row < 5; row++) {
      for (int col = 0; col < 5; col++) {
         generatedNumber = rand() % 25 + 1;
         if (generatedArray[generatedNumber] == 0) {
            generatedArray[generatedNumber] = 1;
            bingo[row][col] = generatedNumber;
         }
         else {
            col--;
            continue;
         }
      }
   }
   while (1) {
      system("cls");
      for (int row = 0; row < 5; row++) {
         for (int col = 0; col < 5; col++) {
            printf("%3d", bingo[row][col]);
         }
         printf("\n\n");
      }

      printf("행 열 입력(종료하려면 -1 -1 입력)>>");
      scanf_s("%d %d", &inputRow, &inputCol);

      if (inputRow == -1 || inputCol == -1) break;

      bingo[inputRow][inputCol] = -1;

   }

}
