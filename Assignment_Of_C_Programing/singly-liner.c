#include<stdio.h>
#include<stdlib.h>

void printNode();
void addFirst(int data);
void addLast(int data);
void addPos(int pos,int data);
void delFirst();
void delLast();
void delPos(int pos);
int searchData(int search);
int searchLastOcur(int search);
int search2ndLastOcur(int search);
int searchDataCount(int search);
void link_list_at_end();

int count();


struct Node{

	int data;
	struct Node*next;
};
struct Node*head=NULL;

void main(){

	struct Node*node=malloc(sizeof(struct Node));
	node->data=30;
	node->next=NULL;
	head=node;
	addFirst(30);
	addLast(20);
	addPos(3,30);
	searchDataCount(30);
	printNode();
	printf("%d\n",count());
}

void printNode(){

	struct Node*temp=head;
	while(temp!=NULL){
		if(temp->next!=NULL){
			printf("| %d |->",temp->data);
		}else{
			printf("| %d |",temp->data);
		}	

		temp=temp->next;
	}
	printf("\n");
}
void addFirst(int data){

	struct Node*node=malloc(sizeof(struct Node));
	node->data=data;
	node->next=head;
	head=node;
}
void addLast(int data){
	struct Node*temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	struct Node*node=malloc(sizeof(struct Node));
	node->data=data;
	temp->next=node;
	node->next=NULL;


}
void addPos(int pos,int data){

	pos=pos-2;
	struct Node*temp=head;
	while(pos){
		temp=temp->next;
		pos--;
	}
	struct Node*node=malloc(sizeof(struct Node));
	node->data=data;
	node->next=temp->next;
	temp->next=node;
}
void delFirst(){
	struct Node*temp=head;
	head=head->next;
	free(temp);

}
void delLast(){
	struct Node*temp=head;
	while(temp->next->next!=NULL){
		temp=temp->next;
	}
	free(temp->next);
	temp->next=NULL;
}
void delPos(int pos){
	pos=pos-2;
	struct Node*temp=head;
	while(pos){
		temp=temp->next;
		pos--;
	}
	struct Node*temp1=temp->next;
	temp->next=temp->next->next;
	free(temp1);
}
int count(){
	int cnt=0;
	struct Node*temp=head;
	while(temp!=NULL){
		temp=temp->next;
		cnt++;
	}
	return cnt;
}
int searchData(int search){
	struct Node*temp=head;
	int index=0;
	int flag=1;
	while(temp!=NULL){
		index++;
		if(temp->data==search){
			printf("data is present at inexd: %d\n",index);
			flag--;
			break;
		}
		temp=temp->next;
	}
	if(flag){
		printf("Data is not present in linkedlist\n");
	}
}
int searchLastOcur(int search){
	struct Node*temp=head;
	int index=0;
	int flag=0;
	int lo;
	while(temp!=NULL){
		index++;
		if(temp->data==search){
			lo=index;
			flag++;
		}
		temp=temp->next;
	}
	if(flag!=0){
		printf("data last occurrence  at inexd: %d\n",lo);
	}else{
		printf("Data is not present in linkedlist");
	}
}
int search2ndLastOcur(int search){
	struct Node*temp=head;
	int index=0;
	int flag=0;
	int oldOcur=0,newOcur=0;
	while(temp!=NULL){
		index++;
		if(temp->data==search){
			oldOcur=newOcur;
			newOcur=index;
			flag++;
		}
		temp=temp->next;
	}
	if(flag!=0){
		printf("data 2nd last ocurrence at inexd: %d\n",oldOcur);
	}else{
		printf("Data is not present in linkedlist");

	}
}

int searchDataCount(int search){
	struct Node*temp=head;
	int cnt=0;
	while(temp!=NULL){
		if(temp->data==search){
			cnt++;
		}
		temp=temp->next;
	}
	if(cnt!=0){
		printf("%d is present in linked list %d times\n",search,cnt);
	}else{	
		printf("Data is not present in linkedlist\n");
	}
}
