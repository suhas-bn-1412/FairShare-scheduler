#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int total_tickets = 0;

struct node
{
	int proc_no;
	int tickets;
	struct node* next;
};

void insert(struct node** head, int proc_no, int tickets)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->proc_no = proc_no;
	temp->tickets = tickets;
	temp->next = (struct node*)malloc(sizeof(struct node));
	temp->next = NULL;
	struct node* p = *head;

	if(p == NULL)
		*head = temp;
		
	else
	{
		while(p->next!=NULL)
			p = p->next;
		p->next = temp;
	}
}

void print_processes(struct node* head)
{
	struct node* p = head;
	if(p==NULL)
	{
		printf("There are no processes.\n");
		return;
	}
	
	while(p!=NULL)
	{
		printf("Process: %d	Tickets: %d\n",p->proc_no,p->tickets);
		p = p->next;
	}
	return;
}

int pick_winner(struct node* head, int ticket_no)
{
	int c = 0;
	int i = 0;
	struct node* p = head;
	while(p)
	{
		i++;
		c = c + p->tickets;
		if(c > ticket_no)
			return p->proc_no;
		p = p->next;
	}
	return -1;
}

int main()
{	
	int n = 0;
	printf("Enter the number of processes:\n");
	scanf("%d",&n);
	
	printf("Enter the tickets to be allocated for each processses.\n");
	
	struct node* head;
	head = (struct node*)malloc(sizeof(struct node));
	head = NULL;
	
	for(int i = 0; i < n; i++)
	{
		int tickets;
		printf("Tickets allocated for process %d: ",i+1);
		scanf("%d",&tickets);
		insert(&head, i+1, tickets);
		total_tickets = total_tickets + tickets;
	}
	
	printf("\nTotal tickets: %d\n\n",total_tickets);
	
	print_processes(head);
	printf("\n");
	srand(time(0));
	
	int* share = (int*)malloc(sizeof(int)*n);
	for(int i = 0; i < n; i++)
		share[i]=0;
	
	
	for(int i = 0; i < 20; i++)
	{
		//generate winning ticket number
		int winning_ticket = rand() % total_tickets;
		
		//pick the winner
		int winner = pick_winner(head, winning_ticket);
		
		share[winner-1] = share[winner-1] + 1;
		
		//display
		printf("Winning ticket: %d	Winner: %d\n",winning_ticket,winner);
	}	
	printf("\n");
	for(int i = 0; i < n; i++)
	{
		float percentage = (share[i]*100) / 20;
		printf("Process %d ",i+1);
		printf("was scheduled %f%% of the time\n",percentage);
	}
	
}


