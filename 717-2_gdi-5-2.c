#include "stdio.h"
#include "stdlib.h"

typedef struct node{
        int value;
        struct node* prev;
        struct node* left;
        struct node* right;
        int visit;
    }node;
typedef struct tree{
      struct node* root;
      int count;
    }tree;
typedef struct l_node{
        struct node *value;
        struct l_node *next;
    }l_node;
typedef struct list{
        l_node *tail;
        l_node *head;
    }list;

void listInit(list* l){
        l->head = NULL;
        l->tail = NULL;
    }
int listEmpty(list *l){
      int visit = (l->tail==NULL);
      return visit;
    }
int push_front(list *l,node* value){
    l_node *temp = malloc(sizeof(node));
    temp->value = value;
    if(l->head==NULL && l->tail==NULL)
    {
        l->tail=temp;
        l->head=temp;
        temp->next = NULL;
        return 0;
    }
    else
    {
       l_node *ptr = l->head;
       temp->next = ptr;
       l->head = temp;
       return 0;
    }
    return 1;
 }
node* removeFirst(list *l){
      l_node *headptr = l->head;
      node *tmp = l->head->value;

      l->head = l->head->next;

      if(l->head==NULL)
          l->tail=NULL;

      free(headptr);

      return tmp;
  }
void init(tree *t){ 
        t->count = 0;
        t->root = NULL;
    }

int find(tree *t,int value,node *n){
       node *nodeptr = t->root;
       if(!nodeptr){return 1;}
       else
       {
           while(nodeptr!=NULL)
           {

               if(value > nodeptr->value)
               {
                 nodeptr = nodeptr->right;continue;
               }
               if(value < nodeptr->value)
               {
                 nodeptr = nodeptr->left; continue;
               }
               if (value == nodeptr->value)
               {
                   if(n == NULL){return 0;}
                   else {
                     n = nodeptr;
                       return 0;}
               }               
           }
       }
       return 1;
   }
int insert(tree *t,int value){
            if(!t->root)
            {
                node *tmp = malloc(sizeof(node));if(!tmp){return 2;}
                tmp->value = value;
                tmp->right = NULL;
                tmp->left = NULL;
                tmp->prev = NULL; 
                t->root = tmp;
                (t->count)++;
                return 0;   
            }
            if(!find(t,value,NULL)){return 1;}
            else
            {
              node *prevptr;
              node *ptr = t->root;
            while(ptr)
              {
                 prevptr = ptr;
                  if( value < ptr->value)
                  {
                    if(!ptr->left)
                    {
                      node *tmp = malloc(sizeof(node));
                      if(!tmp){return 2;}
                    tmp->value = value;
                    tmp->left = NULL;
                    tmp->right = NULL;
                    tmp->prev = prevptr;
                    prevptr->left = tmp;

                    t->count ++;
                    return 0; 
                    }
                    else {ptr = ptr->left; continue;}
                  }
                  else
                  {
                    if(!ptr->right) 
                    {
                    node *tmp = malloc(sizeof(node));
                    tmp->value = value;
                    tmp->left =NULL;
                    tmp->right = NULL;
                    tmp->prev = prevptr;
                    prevptr->right = tmp;
                    t->count ++;
                    return 0; 
                    }
                    else {ptr = ptr->right; continue;}
                  }      
              }
      
            }
                        return 1;
    }

void printTree(tree *t, list *l){
      node *rootptr = t->root;
      int count = 0;
      push_front(l,t->root);
      while(!listEmpty(l))
      {
        node *tmp = removeFirst(l);
        count ++;
        if(count!= t->count)
        printf("%d ",tmp->value);
        else printf("%d\n",tmp->value);
        if(tmp->right){push_front(l,tmp->right);}
        if(tmp->left){push_front(l,tmp->left);}
        
      }
    }
int main(){
      tree *t = malloc(sizeof(tree));
      list *l = malloc(sizeof(list));
      init(t);
      listInit(l);
      for(int i = 0; i < 7; i++)
      {
        int a; scanf("%d",&a);
        insert(t,a);
      }
     printTree(t,l);
    }
