#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node
{
    /* data */
    int data;
    struct Node *left;
    struct Node *right;
};
typedef struct Node nodes;

nodes *create(nodes *node,int elem){
    nodes *newnode;
    if(node == NULL){
        newnode = (nodes *)malloc(sizeof(nodes));
        newnode->data = elem;
        newnode->left = newnode->right = NULL;
        return newnode;
    }
    else if(elem<node->data){
        node->left = create(node->left,elem);
    }
    else if(elem>node->data)
        node->right = create(node->right,elem);
    return node;    
}
nodes *findmin(nodes *node){
    if(node == NULL)
        return NULL;
    else if (node->left)
    {
        /* code */
        node = findmin(node->left);
    }
    else if(node->right)
        node = findmin(node->right);
    return node;    
        
}
nodes *search(nodes *node,int key){
    if(node== NULL)
    {    
        printf("element not found");
        return node;
    }
    else if(key>node->data)
    search(node->right,key);
    else if(key <node->data)    
     search(node->left,key);
    else{
        printf("element found %d\n",node->data);
    } 
    return node;
}
void inorder(nodes *node){
    if(node!=NULL){
        inorder(node->left);
        printf("%d",node->data);
        inorder(node->right);
    }
}
void preorder(nodes *node){
    if(node!=NULL){
        printf("%d",node->data);
        preorder(node->left);
        preorder(node->right);
    }
}
void postorder(nodes *node){
    if(node!=NULL){
        postorder(node->left);
        postorder(node->right);
        printf("%d",node->data);
    }
}
nodes *del(nodes *node,int elem){
    nodes *temp;
    if(node == NULL)
        printf("element not found\n");
    else if(elem<node->data)
        node->left = del(node->left,elem);
    else if(elem>node->data)
        node->right = del(node->right,elem);
    else {
        if(node->right&&node->left){
            temp = findmin(node->right);
            node->data = temp->data;
            node->right= del(node,elem);
            free(temp);
        }    
        else{
            temp = node;
            if(node->left == NULL)
                node = node->right;
            else if(node->right == NULL)
                node = node->left;    
        }
    }    
    return node;
}
void main(){
    int ch,i,n,elem;
    nodes *node;
    node = NULL;
    while(ch!=7){
        printf("1.create\t2.search\t3.inorder\t4.postorder\t5.preorder\t6.del\t7.exit\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("enter the number of elements to be created\n");
            scanf("%d",&n);
            for(i=0;i<n;i++)
            {
                printf("enter the element %d",i+1);
                scanf("%d",&elem);
                node = create(node,elem);
            }
            break;
        case 2:
           printf("enter the search key\n");
           scanf("%d",&elem);
           search(node,elem);
            break;
        case 3:
           inorder(node);
            break;     
        case 4:
           postorder(node);
            break; 
        case 5:
           preorder(node);
            break;    
        case 6:
         printf("enter the element to be deleted\n");
         scanf("%d",&elem);
           node = del(node,elem);
            break;    
            case 7:
            exit(0);
            break;      
        default:
        printf("invalid choice\n");
            break;
        }
    }
}