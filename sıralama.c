#include <stdio.h>
#include <stdlib.h>


struct node {

    int data;
    struct node* next;
};


struct node* start=NULL;
struct node *q=NULL;
struct node *temp=NULL;

void sonaekle(int veri){

    struct node *eklenecek=(struct node*)malloc(sizeof(struct node));
    eklenecek->data =veri;
    eklenecek->next=NULL;


    if(start==NULL){

        start=eklenecek;
    }
    else
    {

        q=start;
        while(q->next != NULL){
            q=q->next;

        }
        q->next=eklenecek;
    }

}





void yazdir(){
    q=start;
    while(q->next !=NULL){
        printf("%d=>", q->data);
        q=q->next;

    }
    printf("%d",q->data);
}

void basaekle(int basa){

    struct node* basagelecek=(struct node*)malloc(sizeof(struct node));
    basagelecek->data=basa;
    basagelecek->next=start;
    start=basagelecek;
}

void arayaekle(int x,int y){

    struct node* arayaeklenecek=(struct node*)malloc(sizeof(struct node));
    arayaeklenecek->data=y;
    q=start;
    while(q->next->data!=x){
        q=q->next;
    }
    struct node* onune=(struct node*)malloc(sizeof(struct node));
    onune=q->next;
    q->next=arayaeklenecek;
    arayaeklenecek->next=onune;
}  

void bastansil(){

    struct node* ikinci=NULL;
    ikinci= start->next;
    free(start);
    start=ikinci;

}

void sondansil(){

    if(start!=NULL)
    {

        q=start;
        while(q->next->next!=NULL){
            q=q->next;
        }
        free(q->next);
        q->next=NULL;

    }

}


void aradansil(int x){
    if(start->data ==x){
        bastansil();
    }
    struct node *onceki =NULL;
    struct node *sonraki=NULL;

    q=start;
    while(q->next->data !=x){
        q=q->next;
    }
    if(q->next == NULL){
        sondansil();
    }
    onceki=q;
    sonraki= q->next->next;
    free(q->next),
    onceki->next=sonraki;

}




int main() {


    int secim,sona,basa,x,y;
    while (1==1){
        printf("\n1-sona eleman ekle.");
        printf("\n2-basa eleman ekle.");
        printf("\n3-araya eleman ekle.");
        printf("\n islem seciniz.");
        scanf("%d",&secim);


        switch(secim)
        {

                case 1:

                    printf("\n sona eklemek istediginiz elemani giriniz...");
                    scanf("%d",&sona);
                    sonaekle(sona);
                    yazdir();
                    break;
                case 2:
                    printf("\n basa eklemek istediginiz elemani ekle...");
                    scanf("%d",&basa);
                    basaekle(basa);
                    yazdir();
                    break;
                case 3:
                    printf("\n hangi sayinin onune ekleme yapacaksiniz...");
                    scanf("%d",&x);
                    printf("\n hangi sayiyi ekleyeceksiniz...");
                    scanf("%d",&y);
                    arayaekle(x,y);
                    yazdir();
                    break;
                case 4:
                    sondansil();
                    yazdir();
                    break;
                case 5:
                    bastansil();
                    yazdir();
                    break;
                case 6:
                    printf("\nSilinmesini istediginiz sayiyi girin...");
                    scanf("%d",&secim);
                    aradansil(secim);
                    yazdir();
                    break;



        }



    }













 return 0;
}