#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include <string.h>

#define NODE_OFF 10
#define BUFFER_SIZE 4096

typedef struct node{
    unsigned int isvalid : 1;
    unsigned int size : 15;
    struct node * next;
}node_t;

int main()
{
    node_t n = {.isvalid = 1, .size = 367,.next = NULL};
    node_t *n2;

    char buffer[BUFFER_SIZE];
    memset(buffer,0,BUFFER_SIZE);
    // memcpy(buffer+NODE_OFF,&n,sizeof(node_t));
    // n2 = (node_t *)(buffer+NODE_OFF);

    printf("n2 = %d,%d,%p\n",n2->isvalid,n2->size,n2->next);
}