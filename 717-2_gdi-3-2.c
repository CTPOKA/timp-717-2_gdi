#include "stdio.h"
#include "stdlib.h"

typedef struct node
{
    int value;
    struct node *next;
    struct node *prev;  
} node;

typedef struct list
{
 struct node *head;
 struct node *tail;
} list;

void init(list* l)
{
    l->head = NULL;
    l->tail = NULL;
}

void clear (list *l)
{
    node *Node = l->head;
    while(Node!=NULL)
    {
        free(Node);
        Node = Node->next;
    }
    l->tail = NULL;
    l->head = NULL;
}

int isEmpty(list *l)
{
    if(l->head==NULL && l->tail==NULL) return 0;
    else return 1;
}

node* find(list *l,int value)
{
    node *Node = l->head;
    while(Node!=NULL)
    {
        if(Node->value == value) {return Node;}
        else Node = Node->next;
    }
    return NULL;
}

int push_back(list *l,int value)
{
    
    node *Node = malloc(sizeof(node));
    Node->value = value;
    Node->next = NULL;
    if(l->head==NULL&&l->tail==NULL)
    {
      l->head = Node;
      l->tail = Node;
      Node->prev = NULL;
    }
    else{
    node *ptr = l->tail;
    Node->prev = ptr;
    ptr->next = Node;
    l->tail = Node;   
    }
}

int push_front(list *l,int value)
{
    node *Node = malloc(sizeof(node));
    Node->value = value;
    Node->prev = NULL;
    if(l->head==NULL && l->tail==NULL)
    {
        l->tail=Node;
        l->head=Node;
        Node->next = NULL;
        return 0;
    }
    else
    {
       node *ptr = l->head;
       ptr->prev = Node;
       Node->next = ptr;
       l->head = Node;
       return 0;
    }
    return 1;
}

int insertAfter(node *n,int value)
{
    node *Node = malloc(sizeof(node));
    Node->value = value;
    Node->next = n->next;
    Node->prev = n;
    n->next = Node;
    return 0;
}

int insertBefore(node *n,int value)
{
    node *prevp = n->prev; 
    node *Node = malloc(sizeof(node));
    Node->value = value;
    if(prevp==NULL)
    {
        prevp = Node;
        Node->next = n;
        Node->prev = NULL;
        
    }
    else{
        Node->value = value;
        prevp->next = Node;
        prevp = Node;
        Node->next = n;
    }
    
}

int removeFirst(list *l, int value)
{
   node* headptr = l->head;
   node* Node;
   while(headptr!=NULL)
   {
       Node = headptr;
       headptr = headptr->next;
       if(Node->value==value)
       {
           if(Node->prev==NULL)
           {
               (Node->next)->prev = NULL;
               l->head =Node->next;
               free(Node);break;
           }
           if(Node->next==NULL)
           {
               (Node->prev)->next = NULL;
               l->tail = Node->prev;
               free(Node);break;
           }
           else{(Node->prev)->next = headptr;
           headptr->prev = Node->prev;
           free(Node);}break;
       }
   }
}

int removeLast(list *l,int value)
{
    node* tailptr = l->tail;
    node* Node;
    while(tailptr!=NULL)
    {
        Node = tailptr;
        tailptr = tailptr->prev;
        if(Node->value==value)
        {
            if(tailptr==NULL)
            {
                (Node->next)->prev = NULL;
                l->head = Node->next;
                free(Node);
                break;
            }
            if(Node->next==NULL)
            {
                tailptr->next = NULL;
                l->tail = tailptr;
                free(Node);
                break;
            }
            else
            {
                tailptr->next = Node->next;
                (Node->next)->prev = tailptr;
                free(Node);
                break;
            }
        }
    }
}

void print(list *l)
{
node* ptr = l->head;
   for(;ptr!=NULL;ptr = ptr->next)
   {
    if(ptr->next==NULL)printf("%d",ptr->value);
    else  printf("%d ",ptr->value);
   }
    printf("\n");
}

void print_invers(list *l)
{
    node *tailptr = l->tail;
    for(;tailptr!=NULL;tailptr = tailptr->prev)
    {
        if(tailptr->prev == NULL) printf("%d",tailptr->value);
        else printf("%d ",tailptr->value);
    }
    printf("\n");
}

int check(list *l,int value)
{
    node* ptr = l->head;
    for(;ptr!=NULL;ptr = ptr->next)
    {
        if(ptr->value == value)
        {
            return 1;
        }     
    }
    return 0;
}

int addAfter(list *l,int value,unsigned n)
{ 
   node* headptr = l->head;
   node *Node1 = malloc(sizeof(node));
   node *Node2;
   unsigned u = 0;
    while(u!=n)
    {
        Node2 = headptr;
        headptr = headptr->next;
        u++;
    }
    headptr->prev = Node1;
    Node1->next = headptr;
    Node1->prev = Node2;
    Node2->next = Node1;
}

int addBefore(list *l,int value,unsigned n)
{
    node* headptr = l->head;
    node* Node1 = malloc(sizeof(node));
    Node1->value = value;
    node *Node2;
    unsigned u = 0;
    while(u!=n)
    {
        Node2 = headptr;
        headptr = headptr->next;
        u++;
    }
    (Node2->prev)->next = Node1;
    Node1->next = Node2;
    Node1->prev = Node2->prev;
    Node2->prev = Node1;

}

int main()
{
 list l;
 int n,a,k,m,t,j,x,u,y,z,r;
 
 scanf("%u",&n);
 init(&l);
 for(int i=1;i<=n;i++)
 {
     scanf("%d",&a);
     push_back(&l,a);
 }
 
 print(&l);
 
 for(int i=1; i <= 3;i++)
 {
    scanf("%d",&k);
    printf("%d",check(&l,k));
 }
 
 printf("\n");
 
 scanf("%d",&m);
 push_back(&l,m);
 print_invers(&l);
 
 scanf("%d",&t);
 push_front(&l,t);
 print(&l);
 
 scanf("%u %d",&j,&x);
 addAfter(&l,x,j);
 print_invers(&l);
 
 scanf("%u %d",&u,&y);
 addBefore(&l,y,u);
 print(&l);
 
 scanf("%d",&z);
 removeFirst(&l,z);
 print_invers(&l);
 
 scanf("%d",&r);
 removeLast(&l,r);
 print(&l);
 clear(&l);
}
