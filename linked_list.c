#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


struct node{


    int data;
    struct node *next;
    struct node *prev;

};

struct node* start=NULL;

struct node *yeni_dugum_olustur(int veri){

       struct node *yenidugum=(struct node*)malloc(sizeof(struct node));
       yenidugum->data=veri;
       yenidugum->next=NULL;
       yenidugum->prev=NULL;

       return yenidugum; 
}


void sonaekle(int veri){

    struct node *sonaeklenecek=yeni_dugum_olustur(veri);

    if(start==NULL){
        start=sonaeklenecek;
    }

    else{

        //traverse 
        struct node*temp=start;
        while(temp->next !=NULL){

            temp=temp->next;
        }
        sonaeklenecek->prev= temp;
        temp->next=sonaeklenecek;
    }
}


void basaekle(int veri){

    struct node *basaeklenecek=yeni_dugum_olustur(veri);
    if(start==NULL){
            start=basaeklenecek;
    }
    else{

        start->prev=basaeklenecek;
        basaeklenecek->next=start;
        start=basaeklenecek;
    }
}



void arayaekle(int kiminonune,int eklenecek){

    struct node *temp=start;
    struct node* onceki=NULL;
    struct node* arayaeklenecek=yeni_dugum_olustur(eklenecek);

    if(start==NULL){
        start=arayaeklenecek;
    }
    else if(start->data==kiminonune){
        basaekle(eklenecek);

    }
    else{
    while(temp->next!=NULL){
        
        if(temp->data==kiminonune){

            onceki=temp->prev;
            break;        
        }
        temp=temp->next;
    }
    temp->prev=arayaeklenecek;
    arayaeklenecek->next=temp;
    arayaeklenecek->prev=onceki;
    onceki->next=arayaeklenecek;
    }
}
void yazdir(){
        struct node *temp=start;
        while(temp !=NULL){
             printf("%d -> ",temp->data);
            temp=temp->next;
        }
}





int main(){

    int i,secim,sayi,sayi1;

    while(1){

            printf("\n 1-sona eleman ekleme");
            printf("\n 2-basa eleman ekleme");
            printf("\n 3-araya eleman ekleme");
            printf("\n 4-cikmak icin 4 giriniz.");
            printf("\n secim gir.");
            scanf("%d",&secim);


        switch(secim){


            case 1:
                printf("sona eklemek istedigin elemani gir.");
                scanf("%d",&sayi);
                sonaekle(sayi);
                yazdir();
                break;
            case 2:
                printf("basa eklemek istediginiz sayiyi giriniz.");
                scanf("%d",&sayi);
                basaekle(sayi);
                yazdir();
                break;
            case 3:
                printf("hangi sayinin onune eklemek istediginizi girin.");
                scanf("%d",&sayi1);
                printf("hangi sayiyi eklemek istediginizi giriniz.");
                scanf("%d",&sayi);
                arayaekle(sayi1,sayi);
                yazdir();
                break;
            case 4:
                return 0;
            default: 
                    printf("yanlis tusa bastiniz.");
                    break;
        }
    }
    return 0;
}