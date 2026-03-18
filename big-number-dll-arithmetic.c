#include <stdio.h>
#include <stdlib.h>

typedef struct calculator{
    int cifra;
    struct calculator *next;
    struct calculator *prev;
} calc;

calc *creare_nod(int cifra){
    calc *nod_nou=malloc(sizeof(calc));
    nod_nou->cifra=cifra;
    nod_nou->next=NULL;
    nod_nou->prev=NULL;
    return nod_nou;
}

calc *adaugare(calc *head, int cifra){
    calc *nod_curent=head;
    if(head==NULL)
        return creare_nod(cifra);
    while(nod_curent->next!=NULL)
        nod_curent=nod_curent->next;
    nod_curent->next=creare_nod(cifra);
    nod_curent->next->prev=nod_curent;
    return head;
}

void afisare(calc *head){
    calc *nod_curent=head;
    while(nod_curent->next!=NULL)
        nod_curent=nod_curent->next;
    while(nod_curent->prev!=NULL){
        printf("%d", nod_curent->cifra);
        nod_curent=nod_curent->prev;
    }
    printf("%d\n", nod_curent->cifra);
}

calc *suma(calc *nr1, calc *nr2, calc *s){
    while(nr1 && nr2){
        s=adaugare(s, nr1->cifra+nr2->cifra);
        nr1=nr1->next;
        nr2=nr2->next;
    }
    while(nr1){
        s=adaugare(s,nr1->cifra);
        nr1=nr1->next;
    }
    while(nr2){
        s=adaugare(s,nr2->cifra);
        nr2=nr2->next;
    }
    return s;
}

calc *suma_final(calc *head){
    calc *s=head;
    while(s){
        if(s->cifra>9){
            s->cifra-=10;
            s->next->cifra+=1;
        }
        s=s->next;
    }
    return head;
}

calc *dif(calc *nr1, calc *nr2, calc *d){
    while(nr1 && nr2){
        if(nr1->cifra<nr2->cifra){
            d=adaugare(d, (nr1->cifra+10)-nr2->cifra);
            nr1->next->cifra-=1;
        }
        else
            d=adaugare(d, nr1->cifra-nr2->cifra);
        nr1=nr1->next;
        nr2=nr2->next;
    }
    return d;
}

void palindrom(calc *head){
    calc *nod1=head;
    calc *nod2=head;
    while(nod2->next)
        nod2=nod2->next;
    while(nod1->cifra!=nod2->cifra){
        if(nod1->cifra!=nod2->cifra){
            printf("nu");
            return;
        }
        nod1=nod1->next;
        nod2=nod2->prev;
    }
    printf("da");
}

int main(){
    int n1, n2, t, a;
    calc *nr1=NULL;
    calc *nr2=NULL;
    
    scanf("%d%d%d", &n1,&n2,&t);
    
    if(n1>n2) a=1;
    else a=0;
    
    while(n1!=0){
        nr1=adaugare(nr1,n1%10);
        n1=n1/10;
    }
    while(n2!=0){
        nr2=adaugare(nr2,n2%10);
        n2=n2/10;
    }
    
    if(t==1){
        afisare(nr1);
        afisare(nr2);
    }
    else if(t==2){
        calc *s=NULL;
        s=suma(nr1,nr2,s);
        s=suma_final(s);
        afisare(s);
    }
    else if(t==3){
        calc *d=NULL;
        if(a)
            d=dif(nr1,nr2,d);
        else{
            printf("-");
            d=dif(nr2,nr1,d);
        }
        afisare(d);
    }
    else if(t==4){
        calc *s=NULL;
        s=suma(nr1,nr2,s);
        s=suma_final(s);
        palindrom(s);
    }
    
    return 0;
}
