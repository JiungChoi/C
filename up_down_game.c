#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Up Down 게임 구현
// 45뽑았을 경우, 게임의 범위는 1~100
// A라는 사람이 15라고 했을 경우 Up을 출력
// B라는 사람이 75라고 했을 경우 Down을 출력
// A라는 사람이 45라고 했을 경우 정답이라고 출력

// 정답 값을 랜덤 난수로 생성 후, A와 B에 입력을 받아서 게임을 진행
// 15분인데 30분까지 시간드리도록 하겠습니다.
// 개인톡으로 코드를 보내주세요 
void main() {
   //시드값 초기화
   srand(time(NULL));

   // 정답값을 생성(난수)   
   int answer = rand() % 100 + 1;
   int userA = 0, userB = 0;

   while (1) {
      printf("User A 입력>>");
      scanf_s("%d", &userA);
      // shift + 역슬래쉬
      if (answer == userA) {
         printf("정답!");
         break;
      }
      else if (answer < userA) printf("Down\n");
      else if (answer > userA) printf("Up\n");

      printf("User B 입력>>");
      scanf_s("%d", &userB);
      if (answer == userB) {
         printf("정답!");
         break;
      }
      else if (answer < userB) printf("Down\n");
      else if (answer > userB) printf("Up\n");
   }
}



