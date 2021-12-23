#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct node
{
	char data;
	struct node *next;

}Qnode,*Qlink;

typedef struct
{
	Qlink front,rear;
}linkqueue;

void Createqueue(linkqueue *q);		//�����ն���
int Emptyqueue(linkqueue *q);
void Enqueue(linkqueue *q,char e);
char Dequeue(linkqueue *q); 

void main(){
	char x,data,judge;
	linkqueue q;
	Createqueue(&q);
	printf("�������ַ���\n������ַ�Ϊ��0��ʱ��ִ�г��Ӳ�����������Ԫ�ش�ӡ����Ļ�ϣ�\n��������ַ�Ϊ��@��ʱ��������ʣ������Ԫ�����γ��Ӳ���ӡ����Ļ�ϣ�\n�����������ַ�ʱ���ַ����\n");
	
	while(1){
	
		fflush(stdin);
		x=getche();				
		if(x=='0'){
			if(Emptyqueue(&q))
				printf("\n�����ѿ�\n");
			else{
				data=Dequeue(&q);
				printf("\n����һ��Ԫ��%c\n",data);
			}
		}
		else if(x=='@'){
			if(Emptyqueue(&q))
				printf("\n�����ѿ�\n");
			else{
				printf("\n��������Ԫ��:");
				while(!Emptyqueue(&q)){
					data=Dequeue(&q);
					printf("%c",data);
				}
			}
			printf("\nֹͣ��N,���������������\n");
			fflush(stdin);
			judge=getch();
			if(judge=='N'||judge=='n')
				break;
			else 
			{
				printf("��������룺");
				continue;
			}

		}else
				Enqueue(&q,x);
	}


}

void Createqueue(linkqueue *q){
	q->front=(Qlink)malloc(sizeof(Qnode));
	q->front->next=NULL;
	q->rear=q->front;
}

int Emptyqueue(linkqueue *q){
	if(q->front==q->rear)	return(1);
	else	return(0);
}

void Enqueue(linkqueue *q,char e){
	Qlink p;
	p=(Qlink)malloc(sizeof(Qnode));
	p->data=e;
	p->next=NULL;
	q->rear->next=p;
	q->rear=p;
}

char Dequeue(linkqueue *q){

	Qlink p;
	if(Emptyqueue(q))	return(0);
	else
	{
		p=q->front;
		q->front=p->next;
		free(p);
		return(q->front->data);

	}
}