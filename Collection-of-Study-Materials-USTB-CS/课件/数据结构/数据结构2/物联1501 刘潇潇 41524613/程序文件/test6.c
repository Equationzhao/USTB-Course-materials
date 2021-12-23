#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>		
# include <windows.h>
# include <time.h>
//����ƽ�����������
typedef struct Bnode{

	int tag;
	int BF;
	char word[30];
	struct Bnode *Lchild,*Rchild;

}Btnode,*BTptr;

typedef struct Bnode1{

	int tag;
	char word[30];
	
}Btnode1,*BTptr1;

typedef struct snode{

	BTptr node;
	struct snode *next;

}slinknode,*slink;

typedef struct node{
	int tag;
	char word[30];
	struct node *next;
}linknode,*link;

//��Ҫ����
void read(BTptr *bt);
void Input(BTptr *bt);
void Output(BTptr Bt);
void extra(BTptr *bt);
void write(BTptr bt);

//����������
void BSTinsert(BTptr *T,BTptr *s);		//����������������(ƽ�����������)
BTptr LL(BTptr a);
BTptr RR(BTptr a);
BTptr LR(BTptr a);
BTptr RL(BTptr a);
void Inorder(BTptr T);					//����������������ǰʮ��
void oneorder(BTptr T);					//�����������������ض����ʴ���

//ջ�Ĳ���

int Emptystack(slink s);         //���zhan��
BTptr Pop(slink *top);			//��ջ 
void Push(slink *top,BTptr e);		//��ջ
BTptr Gettop(slink s);			//ȡջ��Ԫ��

//ȫ�ֱ���
FILE *fps=NULL;					//�ļ����д�롢����
int a=0;
char judge='Y';
long op,ed,s;
void main(){

	BTptr Bt;
	
	while(judge!='N'&&judge!='n'){
		Bt=NULL;
		if(judge=='Y')	
			
		read(&Bt);
		
		else	{
			
		Input(&Bt);
		//ed=clock();s=ed-op;
		//printf("%ldms\n",s);
			
		}
	
		Output(Bt);

		
	}
}

void read(BTptr *bt){

	char c[300]={0},a;
	int j=0;	
	BTptr1 q;
	q=(BTptr1)malloc(sizeof(Btnode1));
	fps=fopen("F:\\���ݽṹ���㷨\\��������.txt","r");
	printf("��ѯ�ϴ�ͳ�ƽ��:\n");
	fread(q, sizeof(Btnode1),1,fps);
	while(!feof(fps)){

		BTptr Bt;
		Bt=(BTptr)malloc(sizeof(Btnode));
		Bt->BF=0;
		Bt->tag=q->tag;
		strcpy(Bt->word,q->word);
		Bt->Lchild=Bt->Rchild=NULL;
		BSTinsert(bt,&Bt);				//����ƽ�����������

		fread(q, sizeof(Btnode1),1,fps);
	}

	fclose(fps);	
	
}

void Input(BTptr *bt){
	char test[30]; 
	int num=0;
	int i,j=0;
	int a=1;
	FILE *fp=NULL;
	char fname[1000];
	printf("������ͳ�Ƶ��ļ�������");
	fflush(stdin);
	scanf("%d",&num);
	while(num<1){
		printf("��������ʵ��ļ���:");
		fflush(stdin);
		scanf("%d",&num);
	}

	for(i=0;i<num;i++){
		printf("������Ҫ�򿪵��ļ�����");
		scanf("%s",fname);
		//op=clock();
		if((fp=fopen(fname,"r"))!=NULL){

			while(a!=EOF)
			{
				
				//�����ַ�����Ϊ��Сд��ĸ�����ֺ��»��ߣ������ַ����������ʷָ�����
				j=0;
				a=(test[j]=fgetc(fp));
				while(test[j]=='_'||(test[j]>='A'&&test[j]<='Z')||(test[j]>='a'&&test[j]<='z')||(test[j]>='0'&&test[j]<='9'))
				{
					j++;
					a=(test[j]=fgetc(fp));
				}
				test[j]='\0';

				if(test[0]!='\0')
				{
					BTptr p;
					p=(BTptr)malloc(sizeof(Btnode));
					p->tag=1;strcpy(p->word,test);
					p->BF=0;p->Lchild=p->Rchild=NULL;
					BSTinsert(bt,&p);				//����ƽ�����������
				}

			}
			fclose(fp);
		}else
		{
			printf("�Ҳ�������ļ�����������һ���ļ���\n");

		}
	}

}

void extra(BTptr *bt){

	printf("׷��ͳ��\n");
	Input(bt);
	Output(*bt);

}

void write(BTptr bt){

	BTptr p;
	BTptr1 q;
	slink s;
	
	s=NULL;
	p=bt;
	q=(BTptr1)malloc(sizeof(Btnode1));

	fps=fopen("F:\\���ݽṹ���㷨\\��������.txt","w");//1.��wģʽ���ļ�a.txt����дģʽ�򿪣�������ļ�����������

		while(1){
		while(p){
			Push(&s,p);
			p=p->Lchild;
		}
		if(Emptystack(s))
		{
			//printf("�Ҳ����������\n");
			break;
		}
		p=Pop(&s);
		q->tag=p->tag;
		strcpy(q->word,p->word);
		fwrite(q, sizeof(Btnode1),1,fps);
		p=p->Rchild;	
	}
	fclose(fps);//2.�ر��ļ�������
}

void Output(BTptr Bt){
	BTptr p;
	p=Bt;
	printf("1 ������ִ�������ǰ10�����ʼ�����ִ���\n2 ����ĳ���ʳ��ִ���\n3 ׷��ͳ��\n4 ���³�ʼ��\n5 ��������\n");
	while(1){
		fflush(stdin);
		scanf("%d",&a);
		while(a!=1&&a!=2&&a!=3&&a!=4&&a!=5){
			printf("û�����ѡ����¼���1~4��\n");
			fflush(stdin);
			scanf("%d",&a);
		}
		switch (a)
		{
		case 1 :Inorder(p);break;
		case 2 :oneorder(p);break;
		case 3 :extra(&p);break;
		}
		if(a==4){
			fps=fopen("F:\\���ݽṹ���㷨\\��������.txt","w");//1.��wģʽ���ļ�a.txt����дģʽ�򿪣�������ļ�����������
			fclose(fps);//2.�ر��ļ�������
			judge='c';
			break;
		}
		if(a==5){

			write(Bt);
			judge='N';
			break;
		}

	}

}

//����������



//���ǰʮ��
void Inorder(BTptr T){
	BTptr p;
	slink s;
	link ten,head,r;
	int i;
	s=NULL;
	//fps=fopen("F:\\���ݽṹ���㷨\\��������.txt","r+");
	head=(link)malloc(sizeof(linknode));
	ten=(link)malloc(sizeof(linknode));
	ten->tag=0;
	ten->word[0]='\0';
	ten->next=NULL;
	head->next=ten;
	p=T;

	while(1){
		while(p){
			Push(&s,p);
			p=p->Lchild;
		}
		if(Emptystack(s))
			break;
		p=Pop(&s);
		//�����ǰ�棬���β����¼��ȡǰʮ����
		r=head;
		for(i=0;i<9;i++){

			if(p->tag>=(r->next)->tag)
			{
				link q;
				q=(link)malloc(sizeof(linknode));
				q->tag=p->tag;
				strcpy(q->word,p->word);
				q->next=r->next;
				r->next=q;
				break;
			}else
				r=r->next;

		}

		p=p->Rchild;	
	}
	//������֡�д���ļ�
	r=head->next;
	if(r->tag==0)
		printf("����һ�����ĵ�\n");
	else{
			printf("�����ļ��е��ʳ���ǰʮ������Ϊ��\n");	
	for(i=1;i<11;i++){
		printf("%d\t���ִ�����%d\t����%s\n",i,r->tag,r->word);
		r=r->next;
		if(r->tag==0)	break;
		if(r==NULL) break;
	}
	}
		

}

//�����ض����ʴ���
void oneorder(BTptr T){

	BTptr p;
	slink s;
	char a[30];
	int i;
	s=NULL;
	p=T;
	//fps=fopen("F:\\���ݽṹ���㷨\\��������.txt","r+");
	printf("��������Ҫ���ҵĵ��ʣ�\n");
	fflush(stdin);
	gets(a);
	while(1){
		while(p){
			Push(&s,p);
			p=p->Lchild;
		}
		if(Emptystack(s))
		{
			printf("�Ҳ����������\n");
			break;
		}
		p=Pop(&s);
		if((strcmp(p->word,a))==0)
		{
			printf("���� %s ���ִ���Ϊ %d\n",a,p->tag);
			break;
		}
		p=p->Rchild;	
	}	
		
}

//ջ����

int Emptystack(slink s){

	if(s==NULL) return(1);
	else return(0);

}


BTptr Pop(slink *top){
	slink q=NULL;
	if(Emptystack(*top)) return(0);
	else{
		q=*top;
		*top=(*top)->next;
		return(q->node);       //����ջ�е����ڵ�
	}
}




void Push(slink *top,BTptr e){
	slink p;
	p=(slink)malloc(sizeof(slinknode));
	p->node=e;
	p->next=*top;
	*top=p;
}


BTptr Gettop(slink s){
	if(s!=NULL) return(s->node);
	return(0);
}


//ƽ��������ڵ����
//T��s�ֱ��Ǹ��ڵ�ʹ�����Ľڵ�ָ�룻pΪ��Ҫ�ָ�룬saָ����ܲ�ƽ���������q��f�ֱ�ָ��p��sa�ĸ��ڵ�
void BSTinsert(BTptr *T,BTptr *s)
{
	BTptr p=NULL,q=NULL,sa=NULL,f=NULL;
	int d;
	if(*T==NULL){ *T=*s;return;}			//����ʱ��s��Ϊ���ڵ�
	
	sa=p=*T;
	while(p!=NULL){
	
		d=strcmp((*s)->word,p->word);
		if(d==0)	{(p->tag)++;	return;}	//��¼����
		//������s�����BF��=0�Ľڵ�sa���丸f
		if(p->BF!=0)	{sa=p;f=q; }
		q=p;						//���µ�ǰpΪq
		if(d<0) p=p->Lchild;		//������ʵ�����
		else p=p->Rchild;

	}

	if(d<0) q->Lchild=*s;
	else	q->Rchild=*s;
	if(strcmp((*s)->word,sa->word)<0)
	{
		p=sa->Lchild;
		q=p;
		sa->BF+=1;
	}
	else
	{
		p=sa->Rchild;
		q=p;
		sa->BF-=1;
	}
	while(p!=*s)
		if(strcmp((*s)->word,p->word)<0)			//�����д�
		{
			p->BF=1;
			p=p->Lchild;
		}else
		{
			p->BF=-1;
			p=p->Rchild;
		}
		switch(sa->BF)
		{
		case 2:
			switch(q->BF)
			{
			case 1:p=LL(sa);break;
			case -1:p=LR(sa);break;

			}
			//�÷��ص��½ڵ�ȡ��ԭsa
			if(f==NULL)	*T=p;
			else if(f->Lchild==sa)	f->Lchild=p;
			else f->Rchild=p;
			break;
		case -2:
			switch(q->BF)
			{
			case -1:p=RR(sa);break;
			case 1:p=RL(sa);break;

			}
			if(f==NULL) *T=p;
			else if(f->Lchild==sa)	f->Lchild=p;
			else f->Rchild=p;
			break;
		}
	
		
}

BTptr LL(BTptr a)
{
	BTptr b=a->Lchild;
	a->Lchild=b->Rchild;
	b->Rchild=a;
	b->BF=a->BF=0;
	return(b);
}
BTptr RR(BTptr a)
{
	BTptr b=a->Rchild;
	a->Rchild=b->Lchild;
	b->Lchild=a;
	b->BF=a->BF=0;
	return(b);
}
BTptr LR(BTptr a)
{
	BTptr b=a->Lchild,c=b->Rchild;
	a->Lchild=c->Rchild;
	b->Rchild=c->Lchild;
	c->Lchild=b;
	c->Rchild=a;
	switch(c->BF)
	{
	case 1:a->BF=-1;b->BF=0;break;
	case -1:a->BF=0;b->BF=-1;break;
	case 0:a->BF=b->BF=0;break;
	}
	c->BF=0;
	return(c);
}
BTptr RL(BTptr a)
{
	BTptr b=a->Rchild,c=b->Lchild;
	a->Rchild=c->Lchild;
	b->Lchild=c->Rchild;
	c->Lchild=a;
	c->Rchild=b;
	switch(c->BF)
	{
	case 1:a->BF=0;b->BF=-1;break;
	case -1:a->BF=-1;b->BF=0;break;
	case 0:a->BF=b->BF=0;break;
	
	}
	c->BF=0;return(c);
}