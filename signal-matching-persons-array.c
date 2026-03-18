#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct persoana{
    char nume[10];
    int indentificator;
    int semnal[20];
};

void afisare(struct persoana * pers, int n){
    for(int i=0;i<n;i++){
        printf("%s\n", (pers+i)->nume);
        printf("%d\n", (pers+i)->indentificator);
        for(int j=0;j<20;j++)
            printf("%d ", (pers+i)->semnal[j]);
        printf("\n");
    }
}

void test_2(struct persoana * pers, int n){
    int p=0,max=0;
    char nume_2[10];
    for(int i=0;i<n;i++){
        for(int j=0;j<20;j++)
            p=p+(pers+i)->semnal[j]*(pers+i)->semnal[j];
        p=p/20;
        if(p>max){
            max=p;
            strcpy(nume_2,(pers+i)->nume);
        }
    }
    printf("%s\n", nume_2);
}

void test_3(struct persoana * pers, int n, int q){
    for(int i=0;i<n;i++){
        if(q==(pers+i)->indentificator)
            printf("%s\n", (pers+i)->nume);
    }
}

int main(){
    int nr_pers,c;
    struct persoana * pers;
    
    scanf("%d", &nr_pers);
    pers=(struct persoana *)malloc(nr_pers*sizeof(struct persoana));
    
    for(int i=0;i<nr_pers;i++){
        scanf("%s", (pers+i)->nume);
        scanf("%d", &(pers+i)->indentificator);
        for(int j=0;j<20;j++){
            scanf("%d", &(pers+i)->semnal[j]);
        }
    }
    scanf("%d", &c);
    
    if(c==1){
        afisare(pers, nr_pers);
    }
    else if(c==2){
        test_2(pers, nr_pers);
    }
    else if(c==3){
        int query;
        scanf("%d", &query);
        test_3(pers, nr_pers, query);
    }
    else if(c==4){
        int semnal_nou[20],d=0;
        char nume_2[10];
        for(int i=0;i<20;i++)
            scanf("%d", &semnal_nou[i]);
        for(int j=0;j<20;j++)
            d=d+(semnal_nou[j]-(pers+0)->semnal[j])*(semnal_nou[j]-(pers+0)->semnal[j]);
        int min=d;
        for(int i=1;i<nr_pers;i++){
            d=0;
            for(int j=0;j<20;j++){
                d=d+(semnal_nou[j]-(pers+i)->semnal[j])*(semnal_nou[j]-(pers+i)->semnal[j]);
            }
            if(d<min){
                min=d;
                strcpy(nume_2,(pers+i)->nume);
            }
        }
        printf("%s\n", nume_2);
    }
    
    return 0;
}
