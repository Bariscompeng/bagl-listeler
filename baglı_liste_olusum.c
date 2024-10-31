#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node*sonraki;
};



int main() {
    struct node*q=NULL;
    struct node*ilkdugum=NULL;
    ilkdugum=(struct node*)malloc(sizeof(struct node));
    struct node*ikincidugum=(struct node*)malloc(sizeof(struct node));
    struct node*ucuncudugum=(struct node*)malloc(sizeof(struct node));
    struct node*dorduncudugum=(struct node*)malloc(sizeof(struct node));

    ilkdugum -> data=15;
    ilkdugum -> sonraki=ikincidugum;
    ikincidugum -> data=20;
    ikincidugum -> sonraki=ucuncudugum;
    ucuncudugum -> data=30;
    ucuncudugum -> sonraki=dorduncudugum;
    dorduncudugum -> data=45;
    dorduncudugum -> sonraki=NULL;

    q=ilkdugum;
    while(q !=NULL)
    { 
        printf("%d ",q->data);
        q=q->sonraki;
       
    }
    


    return 0;
}