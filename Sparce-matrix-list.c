#include<stdio.h> 
#include<stdlib.h> 

struct node 
{ 
	int value; 
	int row; 
	int column; 
	struct Node *next; 
};

void create_new_node_sorted_triplet(struct node** start, int z,int ro, int c,int tr,int tc ) 
{ 
	struct node *temp, *r; 
	temp =*start; 
	if (temp == NULL) 
	{ 
		temp = (struct node *) malloc (sizeof(struct node)); 
		temp->value = z; 
		temp->row_position = ro; 
		temp->column_postion = c; 
		temp->next = NULL; 
		*start = temp;
		create_new_node_sorted_triplet(start,z,ro,c,tr,tc); 

	} 
	else
	{   temp=(*start)->next; 
		while (temp->next != NULL) 
			temp = temp->next; 

		r = (struct node *) malloc (sizeof(struct node)); 
		r->value = z; 
		r->row_position = ro; 
		r->column_postion = c; 
        r->next = NULL;
		temp->next = r;
        (*start->value)++; 
	} 
}

void add_sparce_matrix(struct node** st1,struct node** st2){
	struct node *t1,*t,*t2,*prev;
	if((*st1)->row==(*st2)->row && (*st1)->column==(*st2)->column){
		struct node *st3 = merge(st1,st2);
		struct node *head3= (struct node *) malloc (sizeof(struct node));
		head3->row=(*st1)->row;
		head3->column=(*st1)->column;
		head3->value=0;
		head3->next=st3;
		t1=*head3->next;
		t2=*head3->next;
		prev=*head3->next;
		for(;t1!=NULL;t1=t1->next){
			for(t2=t1->next;t2!=NULL;t2=t2->next){
				if(t1->row==t2->row && t1->column==t2->column){
					t1->value=t1->value+t2->value;
					t=t2;
					prev->next=t2->next;
					free(t);
				}
				else{
					prev=t2;
				}
			}
		}
	}
	else{
		printf("\n Not Possible");
	}
}

void merge(struct node** st1,struct node** st2){

}