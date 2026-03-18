#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct studenti{
    char nume[21];
    int grupa,nr_note;
    int *note;
    struct studenti *next;
} student;

student *creare(char nume[21], int grupa, int nr_note, int *note){
    student *nod_nou=malloc(sizeof(student));
    strcpy(nod_nou->nume,nume);
    nod_nou->grupa=grupa;
    nod_nou->nr_note=nr_note;
    nod_nou->note=malloc(nod_nou->nr_note*sizeof(int));
    for(int i=0;i<nod_nou->nr_note;i++)
        nod_nou->note[i]=note[i];
    nod_nou->next=NULL;
    return nod_nou;
}

student *adaugare(student *head, char nume[21], int grupa, int nr_note, int *note){
    student *nod_curent=head;
    if(head==NULL)
        return creare(nume,grupa,nr_note,note);
    while(nod_curent->next!=NULL)
        nod_curent=nod_curent->next;
    nod_curent->next=creare(nume,grupa,nr_note,note);
    return head;
}

void afisare(student *head){
    student *nod_curent=head;
    while(nod_curent!=NULL){
        printf("%s ", nod_curent->nume);
        printf("%d ", nod_curent->grupa);
        for(int i=0;i<nod_curent->nr_note;i++)
            printf("%d ", nod_curent->note[i]);
        printf("\n");
        nod_curent=nod_curent->next;
    }
}

void medie_max(student *head){
    student *nod_curent=head, *stud_max=head;
    float medie,max=0.0;
    while(nod_curent!=NULL){
        float s=0.0;
        for(int i=0;i<nod_curent->nr_note;i++){
            s+=nod_curent->note[i];
        }
        medie=(float)s/nod_curent->nr_note;
        if(medie>max){
            max=medie;
            stud_max=nod_curent;
        }
        nod_curent=nod_curent->next;
    }
    printf("%s ", stud_max->nume);
    printf("%d ", stud_max->grupa);
    for(int i=0;i<stud_max->nr_note;i++)
        printf("%d ", stud_max->note[i]);
}

float medie(student *nod_curent){
    float s=0.0;
    for(int i=0;i<nod_curent->nr_note;i++)
        s+=nod_curent->note[i];
    return s/nod_curent->nr_note;
}

student *sortare(student *head){
    student *nod_curent=head, *aux;
    int k=0,b=0;
    while(nod_curent!=NULL){
        k++;
        nod_curent=nod_curent->next;
    }
    student **v=(student **)malloc(k*sizeof(student *));
    nod_curent=head;
    for(int i=0;i<k;i++){
        v[i]=nod_curent;
        nod_curent=nod_curent->next;
    }
    while(b==0){
        b=1;
        for(int i=0;i<k-1;i++)
            if(medie(v[i])>medie(v[i+1])){
                aux=v[i];
                v[i]=v[i+1];
                v[i+1]=aux;
                b=0;
            }
    }
    for(int i=0;i<k;i++){
        printf("%s ", v[i]->nume);
        printf("%d ", v[i]->grupa);
        for(int j=0;j<v[i]->nr_note;j++)
            printf("%d ", v[i]->note[j]);
        printf("\n");
    }
}

int main(){
    int t;
    student *stud=NULL;
    scanf("%d", &t);

    while(t==1){
        char nume[21];
        int grupa, nr_note, *note;
        scanf("%s", nume);
        scanf("%d%d", &grupa,&nr_note);
        note=malloc(nr_note*sizeof(int));
        for(int i=0;i<nr_note;i++)
            scanf("%d", &note[i]);
        stud=adaugare(stud,nume,grupa,nr_note,note);
        scanf("%d", &t);
    }
    if(t==2){
        afisare(stud);
    }
    else if(t==3){
        medie_max(stud);
    }
    else if(t==4){
        int grupa;
        student *stud_2=NULL, *nod_1=stud;
        scanf("%d", &grupa);
        while(nod_1!=NULL){
            if(grupa==nod_1->grupa)
                stud_2=adaugare(stud_2,nod_1->nume,nod_1->grupa,nod_1->nr_note,nod_1->note);
            nod_1=nod_1->next;
        }
        afisare(stud_2);
    }
    else if(t==5){
        int grupa;
        student *stud_2=NULL, *nod_1=stud;
        scanf("%d", &grupa);
        while(nod_1!=NULL){
            if(grupa==nod_1->grupa)
                stud_2=adaugare(stud_2,nod_1->nume,nod_1->grupa,nod_1->nr_note,nod_1->note);
            nod_1=nod_1->next;
        }
        sortare(stud_2);
    }

    return 0;
}
