/* (1) ���������ڽý�������, (2) 2310131, (3) �����, (4) main.c (5) 2025.05.28 */
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//�迭 ť ���� 
#define SIZE 5
typedef struct{
	int data[SIZE];
	int front, rear; //����ť 
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
	//ī�� ������ ����
	Queue card; //card�� ���� 
	card.front = card.rear=-1; //����ť, �ʱ�ȭ
	//1.5���� ī�� ��ȣ �Է�, �÷��̾�� ī�� �ް� ���ʴ�� ����
	int i, cnum;
	for(i=0;i<SIZE;i++){
		printf("%d��° ī���ȣ �Է�: ",i+1); //����ڰ� ���ڸ� �Է� 
		scanf("%d", &cnum);
		enqueue(card.data,&card.rear, cnum); //ť�� �ֱ� 
	}
	
	//2.�տ������� ����(FIFO)
	printf("ī�� ���� ����:");
	for(i=0;i<SIZE;i++){
		cnum=dequeue(card.data,&card.front, card.rear); //ť���� �ϳ��� �պ��� ���� 
		printf("%d ",cnum);
	}
	//3. �迭 ť ���, 
	//��� ī��������� ���ٿ� ��� 
	return 0;
}
