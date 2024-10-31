#include <stdio.h>
#include <stdlib.h>


struct node{

    int data;
    struct node* next;
};


int main(){

    struct node* ilkdugum=NULL;
    struct node* q=NULL;
    struct node* yenidugum=NULL;
    
    int n,data,i;
    printf("kac dugum gireceginizi soyleyin.\n");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        yenidugum=(struct node*)malloc(sizeof(struct node));
        if (yenidugum==NULL){

            printf("bellek tahsis edilmedi.\n");
            return 1;
        }
        printf("dugum %d in verisini giriniz.\n",i+1);
        scanf("%d",&data);
        yenidugum->data=data;
        yenidugum->next=NULL;

        if(ilkdugum == NULL){
            ilkdugum = yenidugum;
        }
        else{
            q->next = yenidugum;
        }
        q = yenidugum;
    }
    printf("bagli listedeki elemanlar.\n");
    q=ilkdugum;
    while(q !=NULL){
        printf("%d ",q->data);
        q=q->next;
    }
    printf("\n");

    return 0;

}