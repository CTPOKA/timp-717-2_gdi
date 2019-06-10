#include "stdio.h"
#include "stdlib.h"

typedef struct node
{
    int value;
    struct node *next;
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
  node *headptr = l->head;
  node* tmp;
  while(headptr)
  {
      tmp = headptr;
    free(tmp);  
    headptr = headptr->next;
  }
     free(headptr);
     l->head = NULL;
     l->tail = NULL;
}

int isEmpty(list *l)
{
        if(l->head==NULL && l->tail==NULL) return 0;
        else return 1;
}

node* find(list *l,int value)
{
    node* ptr = l->head;
    {
        if(ptr->value == value)
        {
            return ptr; 
        }  
    }
    return NULL;
}

int push_back(list *l,int value)
{
 if(l->head==NULL && l->tail==NULL)
 {
      node* tmp = malloc(sizeof(node));
      l->head = tmp;
      l->tail = tmp;
      tmp->value = value;
      tmp->next = NULL;
 }else
 {
     node* tmp = malloc(sizeof(node));
     node* ptr = l->tail;
     tmp->value = value;
     ptr->next = tmp;
     l->tail = tmp;
 }
 return 0;
}

int push_front(list *l,int value)
{
    if(l->head==NULL && l->tail==NULL)
    {
      node* tmp = malloc(sizeof(node));
      l->head = tmp;
      l->tail = tmp;
      tmp->value = value;
      tmp->next = NULL;
    }
    else
    {
      node* tmp = malloc(sizeof(node));
      tmp->value = value;
      tmp->next = l->head;
      l->head = tmp;
      node* ptr = l->head;

    do
      {
       ptr = ptr->next;
       l->tail = ptr;
      }
    while(ptr->next!=NULL);
      return 0;
    }
}

int insertAfter(node *n,int value)
{ 
    node* tmp = malloc(sizeof(node)); 
    tmp->value = value;
    tmp->next = n->next;
    n->next = tmp;
    return 0;   
}

int Remove(list *l,int value)
{   
    node *tmp;
    node *ptrhead = l->head;
    while(ptrhead)
    { 
        if(ptrhead->value == value){ 
            tmp->next = ptrhead->next;
            free(ptrhead);break;}
        else {
            tmp = ptrhead;
            ptrhead = ptrhead->next;        
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

int addAfter(list *l,int value,int n)
{ 
   int count = 0;
   node *tmp1,*tmpnode;
   node *ptrhead = l->head;
   while(count!=n)
   {
       tmp1 = ptrhead;
       ptrhead = ptrhead->next;
       count++;
   }
    tmpnode = malloc(sizeof(node));
    tmpnode->value = value;
    tmpnode->next = ptrhead;
    tmp1->next = tmpnode;
}

int main ()
{
    int n,a,k,x,m,t,z,j;
    struct list l;
    init(&l);
    
    scanf("%u",&n);
    
    for(int i = 1;i<=n;i++)
    {
        scanf("%d",&a);
        push_back(&l,a);
    }
    
    print(&l);
    
    for(int i = 1; i<=3;i++)
    {
        scanf("%d",&k);
        printf("%d",check(&l,k));
    }
    printf("\n");
    
    scanf("%d",&m);
    push_back(&l,m);
    
    print(&l);
    
    scanf("%d",&t);
    push_front(&l,t);
    
    print(&l);
    
    scanf("%u",&j);
    scanf("%d",&x);
    addAfter(&l,x,j);
    
    print(&l);
    
    scanf("%d",&z);
    Remove(&l,z);
    
    print(&l);
    clear(&l);
}  

