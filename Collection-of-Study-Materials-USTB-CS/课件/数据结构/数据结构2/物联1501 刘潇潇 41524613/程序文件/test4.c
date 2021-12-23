#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct Bnode
{
	char res[30];
	struct Bnode *Lchild,*Rchild;

}Btnode,*BTptr;

typedef struct node
{
	BTptr zhan;

	struct node *next;

}linknode,*link;

int j;

BTptr CreateLBtree();			//����������
void Tinsert(BTptr* BT,char* P);		//���÷ǵݹ����ģʽ
int Emptystack(link s);         //���zhan��
BTptr Pop(link *top);			//��ջ 
void Push(link *top,BTptr e);		//jinzhan
BTptr Gettop(link s);			//ȡջ��Ԫ��
void Inorder(BTptr T);								//�������

main(){
	BTptr BT;	
	char k='Y';
	while(k=='y'||k=='Y'){
		BT=CreateLBtree();
		printf("���ֵ�˳�����������\n");
		Inorder(BT);
		printf("\n��Y�������������˳�\n");
		fflush(stdin);
		k=_getch();
	}
}

BTptr CreateLBtree(){
	char k,c[50][30],a,d[30];
	int i=0;
	BTptr bt;
	j=0;
	k=0;
	bt=(BTptr)malloc(sizeof(Btnode));	
	bt->Lchild=bt->Rchild=NULL;
	printf("��W�Ӽ������룬F���ļ�����\n");
	while(k==0){
	fflush(stdin);
	k=getch();
	if(k=='W'||k=='w')
	{
		printf("�����룺���ո���������س�����,��Ч���ַ��Զ����ԣ�\n");

		i=0;
		a=0;
		fflush(stdin);

		while(1){			
			i=0;
			a=0;
			while(a!=' '&&a!='\n')
			{
				c[j][i]=getchar();
				a=c[j][i];
				if((a>='A'&&a<='Z')||(a>='a'&&a<='z'))
					i++;
			}
			c[j][i]='\0';		
			if(j==0){
				strcpy(bt->res,c[0]);
				j++;
			}else{
				Tinsert(&bt,c[j]);
			}
			if(a=='\n')
				break;
		}
	}
	else if(k=='F'||k=='f')
	{

		FILE *fp=NULL;
		char fname[1000];
		printf("������Ҫ�򿪵��ļ�����");
		scanf_s("%s",fname);
		//F:\\���ݽṹ���㷨\\������.txt
		if((fp=fopen(fname,"r"))!=NULL){
		while(!feof(fp))
		{
			fscanf(fp,"%s",c[j]);
			printf("%s ",c[j]);

			if(j==0){
				strcpy(bt->res,c[0]);
				j++;
			}else{
				Tinsert(&bt,c[j]);
			}

		}
		fclose(fp);
		}else
		{printf("�Ҳ�������ļ�������ѡ�� W or  F\n");
		k=0;
		}
	}else
	{
		printf("û�����ѡ�����ѡ�� W or  F\n");
		k=0;
	}
	}
	return(bt);
}



void Tinsert(BTptr *BT,char* P){			//����ڵ�
	BTptr p,q,R,w;
	link s;
	s=NULL;
	w=NULL;
	p=*BT;
	while(1){
		while(*BT){
			Push(&s,*BT);
			*BT=(*BT)->Lchild;
		}	
		if(Emptystack(s))
			break;
		(*BT)=Pop(&s);
		if(strcmp((P),((*BT)->res))<0)
		{
			R=(BTptr)malloc(sizeof(Btnode));
			strcpy(R->res,P);
			R->Lchild=R->Rchild=NULL;
			q=(*BT)->Lchild;
			(*BT)->Lchild=R;
			R->Lchild=q;
			j++;
			(*BT)=p;
			Push(&s,R);
			break;
		}					//�嵽p������
		else if(strcmp((P),((*BT)->res))==0)
		{
			R=(BTptr)malloc(sizeof(Btnode));
			strcpy(R->res,P);
			R->Lchild=R->Rchild=NULL;
			(*BT)=p;
			Push(&s,R);
			break;
		}
		w=(*BT);
		(*BT)=(*BT)->Rchild;

	}			
	if(Emptystack(s))
	{	
		R=(BTptr)malloc(sizeof(Btnode));
		strcpy(R->res,P);
		R->Lchild=R->Rchild=NULL;
		w->Rchild=R;	
		j++;
		(*BT)=p;
	}

}

void Inorder(BTptr T){
	BTptr p;
	link s;
	s=NULL;
	p=T;
	while(1){
		while(p){
			Push(&s,p);
			p=p->Lchild;
		}

		if(Emptystack(s))
			break;
		p=Pop(&s);
		printf("%s ",p->res);
		p=p->Rchild;	
	}
}


int Emptystack(link s){

	if(s==NULL) return(1);
	else return(0);

}


BTptr Pop(link *top){
	link q=NULL;
	if(Emptystack(*top)) return(0);
	else{
		q=*top;
		*top=(*top)->next;
		return(q->zhan);       //����ջ�е����ڵ�
	}
}




void Push(link *top,BTptr e){
	link p;
	p=(link)malloc(sizeof(linknode));
	p->zhan=e;
	p->next=*top;
	*top=p;
}


BTptr Gettop(link s){
	if(s!=NULL) return(s->zhan);
	return(0);

}
