/* (1) 지능형전자시스템전공, (2) 2310131, (3) 김수안, (4) main.c (5) 2025.05.28 */
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//배열 큐 정의 
#define SIZE 5
typedef struct{
	int data[SIZE];
	int front, rear; //공백큐 
}Queue; 

//enqueue
void enqueue(int a[], int *rear, int item){
	if(*rear==SIZE-1){
		printf("Queue is full\n");
		return;
	}
	a[++*rear]=item;
}
//dequeue
int dequeue(int a[], int *front, int rear){
	if(*front==rear){
		printf("Queue is empty\n");
		exit(1);
	}
	else return a[++*front];
} 

int main(int argc, char *argv[]) {
	//카드 뒤집기 게임
	Queue card; //card줄 생성 
	card.front = card.rear=-1; //공백큐, 초기화
	//1.5장의 카드 번호 입력, 플레이어는 카드 받고 차례대로 저장
	int i, cnum;
	for(i=0;i<SIZE;i++){
		printf("%d번째 카드번호 입력: ",i+1); //사용자가 숫자를 입력 
		scanf("%d", &cnum);
		enqueue(card.data,&card.rear, cnum); //큐에 넣기 
	}
	
	//2.앞에서부터 공개(FIFO)
	printf("카드 공개 순서:");
	for(i=0;i<SIZE;i++){
		cnum=dequeue(card.data,&card.front, card.rear); //큐에서 하나씩 앞부터 빼기 
		printf("%d ",cnum);
	}
	//3. 배열 큐 사용, 
	//출력 카드공개순서 한줄에 출력 
	return 0;
}
