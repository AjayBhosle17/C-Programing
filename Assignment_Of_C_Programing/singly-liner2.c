#include<stdio.h>
#include<stdlib.h>
int count();
int count2();
void printNode();
void printNode2();
void addLast();
void addLast2();
void listConcat();
void ConcatFirstN();
void ConcatLastN();
void ConcatListRange();
void LLCopy();
void LLNCopy();
void LLLNCopy();
void LLCopyRange();
void LLCopyAlt();
void LLCopyEven();
void LLCopyPrime();
int SubList();
int LSubList();
void CopyAsc();
struct Node{
	int data;
	struct Node*next;
};
struct Node*head=NULL;
struct Node*head2=NULL;

void main(){
	int n1,n2;
	head=malloc(sizeof(struct Node));
	head->data=10;
	head->next=NULL;
	printf("number of nodes in list 1 : ");
	scanf("%d",&n1);
	for(int i=1;i<n1;i++){
		if(i==1){
			printf("data in 1 list : ");
			scanf("%d",&head->data);
		}
		addLast();
	}
	head2=malloc(sizeof(struct Node));
	head2->data=0;
	head2->next=NULL;
	char ch;
	printf("Fill 2nd list : \n----for yes enter ' y 'and for 'n'----\n");
	scanf(" %c",&ch);
	if(ch=='y'||ch=='Y'){
		printf("number of nodes in list 2 : ");
		scanf("%d",&n2);
		for(int i=1;i<n2;i++){
			if(i==1){
				printf("data in 1 list : ");
				scanf("%d",&head2->data);
			}
			addLast2();
		}

	}
	
	CopyAsc();
	printNode2();
}

int count(){
	struct Node*temp=head;
	int cnt=0;
	while(temp!=NULL){
		temp=temp->next;
		cnt++;
	}
	return cnt;
}
int count2(){
	struct Node*temp=head2;
	int cnt=0;
	while(temp!=NULL){
		temp=temp->next;
		cnt++;
	}
	return cnt;
}
void printNode(){
	
	struct Node*temp=head;
	while(temp!=NULL){
		if(temp->next==NULL){
			printf("| %d |",temp->data);
		}else{	
			printf("| %d |->",temp->data);
		}	
		temp=temp->next;
	}
	printf("\n");
}
void printNode2(){
	
	struct Node*temp=head2;
	while(temp!=NULL){
		if(temp->next==NULL){
			printf("| %d |",temp->data);
		}else{	
			printf("| %d |->",temp->data);
		}	
		temp=temp->next;
	}
	printf("\n");

}	
void addLast(){
	struct Node*temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	struct Node*node=malloc(sizeof(struct Node));
	printf("data in 1 list : ");
	scanf("%d",&node->data);
	node->next=NULL;
	temp->next=node;
}
void addLast2(){
	struct Node*temp=head2;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	struct Node*node=malloc(sizeof(struct Node));
	printf("data in 2 list : ");
	scanf("%d",&node->data);
	node->next=NULL;
	temp->next=node;
}
void listConcat(){
	struct Node*temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=head2;
	printNode();
}
void ConcatFirstN(){
	int n;
	printf("input number of elements : ");
	scanf("%d",&n);
	struct Node*temp2=head2;
	for(int i=1;i<=n;i++){
		struct Node*temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		struct Node*node=malloc(sizeof(struct Node));
		node->data=temp2->data;
		node->next=NULL;
		temp->next=node;
		temp2=temp2->next;	
	}
	printNode();

}

void ConcatLastN(){
	int n;
	printf("Enter last n element to copy : ");
	scanf("%d",&n);
	int pos=count2()-n;
	struct Node*temp2=head2;
	while(pos){
		temp2=temp2->next;
		pos--;
	}
	struct Node*temp=head;
	for(int i=1;i<=n;i++){
		struct Node*temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		struct Node*node=malloc(sizeof(struct Node));
		node->data=temp2->data;
		node->next=NULL;
		temp->next=node;
		temp2=temp2->next;	

	}
	printNode();


}
void ConcatListRange(){
	struct Node*temp1=head;
	printf("Enter starting range:");
	int sr,er;
	scanf("%d",&sr);
	printf("Enter ending range :");
	scanf("%d",&er);
	int pos=sr-1;
	while(pos){
		temp1=temp1->next;
		pos--;
	}
	int lim=er-sr;
	
	for(int i=1;i<=lim+1;i++){
		struct Node*temp2=head2;
		while(temp2->next!=NULL){
			temp2=temp2->next;
		}
		struct Node*node=malloc(sizeof(struct Node));
		node->data=temp1->data;
		temp2->next=node;
		temp1=temp1->next;
	}
	printNode2();
}
void LLCopy(){
	
	struct Node*temp1=head;
	struct Node*temp2=head2;
	head2->data=head->data;
	temp1=temp1->next;

	for(int i=1;i<count();i++){
		struct Node*node=malloc(sizeof(struct Node));
		node->data=temp1->data;
		temp2->next=node;
		temp2=temp2->next;
		temp1=temp1->next;
	}
	
	printNode2();

}
void LLNCopy(){
	
	struct Node*temp1=head;
	struct Node*temp2=head2;
	head2->data=head->data;
	temp1=temp1->next;
	int n;
	printf("Number of elements copy :");
	scanf("%d",&n);

	for(int i=1;i<n;i++){
		struct Node*node=malloc(sizeof(struct Node));
		node->data=temp1->data;
		temp2->next=node;
		temp2=temp2->next;
		temp1=temp1->next;
	}
	
	printNode2();

}
void LLLNCopy(){
	printf("Last N number copy list : ");
	int n;
	scanf("%d",&n);
	int pos=count()-n;
	struct Node*temp1=head;
	while(pos){
		temp1=temp1->next;
		pos--;
	}	
	struct Node*temp2=head2;
	head2->data=temp1->data;
	temp1=temp1->next;
	while(temp1!=NULL){
		struct Node*node=malloc(sizeof(struct Node));
		node->data=temp1->data;
		temp2->next=node;
		temp2=temp2->next;
		temp1=temp1->next;
	}
	
	printNode2();

}
void LLCopyRange(){
	int ul,ll;
	printf("input starting range : ");
	scanf("%d",&ul);
	getchar();
	printf("input ending range : ");
	scanf("%d",&ll);
	int pos=ul-1;
	struct Node*temp1=head;
	struct Node*temp2=head2;
	while(pos){
		temp1=temp1->next;
		pos--;
	}
	temp2->data=temp1->data;
	temp1=temp1->next;
	for(int i=ul;i<ll;i++){
		struct Node*node=malloc(sizeof(struct Node));
		node->data=temp1->data;
		temp2->next=node;
		temp2=temp2->next;
		temp1=temp1->next;
	}

}
void LLCopyAlt(){
	int cnt=1;
	struct Node*temp1=head;
	struct Node*temp2=head2;
	temp2->data=temp1->data;
	temp1=temp1->next;
	while(temp1!=NULL){
		if(cnt%2==0){
			struct Node*node=malloc(sizeof(struct Node));	
			node->data=temp1->data;
			temp2->next=node;
			temp2=temp2->next;
		}
		cnt++;
		temp1=temp1->next;
	}	
}
void LLCopyEven(){
	struct Node*temp1=head;
	struct Node*temp2=head2;
	int flag=1;
	while(temp1!=NULL){
		int n=temp1->data;
		int sum=0;
		while(n!=0){
			int rem=n%10;
			n=n/10;
			sum=sum+rem;	
		}
		if(sum%2==0){
			if(flag==1){
				temp2->data=temp1->data;
				flag++;
			}else{
				struct Node*node=malloc(sizeof(struct Node));	
				node->data=temp1->data;
				temp2->next=node;
				temp2=temp2->next;
			}
		}

		temp1=temp1->next;
	}
}
void LLCopyPrime(){
        struct Node*temp1=head;
        struct Node*temp2=head2;
        int flag=1;
        while(temp1!=NULL){
                int n=temp1->data;
                int sum=0;
                while(n!=0){
                        int rem=n%10;
                        n=n/10;
                        sum=sum+rem;
                }
		int cnt=0;
		for(int i=1;i<=sum;i++){
			if(sum%i==0){
				cnt++;
			}
			if(cnt>2)
				break;

		}
                if(cnt==2){
                        if(flag==1){
                                temp2->data=temp1->data;
                                flag++;
                        }else{
                                struct Node*node=malloc(sizeof(struct Node));
                                node->data=temp1->data;
                                temp2->next=node;
                                temp2=temp2->next;
                        }
                }

                temp1=temp1->next;
        }
}

int SubList(){
	struct Node*temp1=head;
	struct Node*temp2=head2;
	int pos=1,cnt=1,temp,result=0;
	int cnt2=count2();


	while(temp1!=NULL){

		if(temp1->data==temp2->data){
			temp=pos;

			while( result!=cnt2 && temp2!=NULL && temp1!=NULL ){

				if(temp1->data==temp2->data){
					result++;	
				}

				temp1=temp1->next;
				temp2=temp2->next;
				pos++;

			}

			 if(result==cnt2){
          	               return temp;
			 }  
			result=0; 

		}
		if(temp1==NULL&&temp2==NULL){
                        break;
                }
		temp1=temp1->next;
                temp2=head2;;
		pos++;
		
	}
}
int LSubList(){
	struct Node*temp1=head;
        struct Node*temp2=head2;
        int pos=1,temp,result=0;
	int lpos,flag=0;
        int cnt2=count2();

          while(temp1!=NULL){

                if(temp1->data==temp2->data){
                        temp=pos;
                        while( result!=cnt2 && temp2!=NULL && temp1!=NULL ){
				printf("%d   %d",temp1->data,temp2->data);
                                if(temp1->data==temp2->data){
                                        result++;
                                }
                                temp1=temp1->next;
                                temp2=temp2->next;
                                pos++;
                        }
                        if(result==cnt2){
				lpos=temp;
				flag++;
				result=0;

                        }
                }
		if(temp1==NULL&&temp2==NULL){
			break;
		}	
                temp1=temp1->next;
                temp2=head2;;
                pos++;

        }
	if(flag>0){
		return lpos;
	}  
	  

}
void CopyAsc(){

	struct Node*temp1=head;
	struct Node*temp2=head2;
	int cnt=1;
	int count1=count();

	while(cnt<count1){

		struct Node*temp=head;
		int cnt2=1;
		while(cnt2<count1){

			if(temp->data > temp->next->data){
				int val=temp->data;
				temp->data=temp->next->data;
				temp->next->data=val;
			}
			temp=temp->next;
			cnt2++;

		}

		cnt++;
	
	}

	LLCopy();

}

