#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct elev{
    char nume[20],cod[20];
    int note[9];
};

void afisare(struct elev * elevi, int nr_elevi){
    for(int i=0;i<nr_elevi;i++){
        printf("%s\n", (elevi+i)->nume);
        printf("%s\n", (elevi+i)->cod);
        for(int j=0;j<9;j++){
            printf("%d ", (elevi+i)->note[j]);
        }
        printf("\n");
    }
}

void medie_max(struct elev * elevi, int nr_elevi){
    int max=0;
    char nume_2[20];
    for(int i=0;i<nr_elevi;i++){
        int s=0;
        for(int j=0;j<9;j++){
            s=s+(elevi+i)->note[j];
        }
        s=s/9;
        if(s>max){
            max=s;
            strcpy(nume_2,(elevi+i)->nume);
        }
    }
    printf("%s\n", nume_2);
}

void medie_min(struct elev * elevi, int nr_elevi){
    for(int i=0;i<nr_elevi;i++){
        int s=0;
        for(int j=0;j<9;j++){
            s=s+(elevi+i)->note[j];
        }
        if(s/9<6)
            printf("%s\n", (elevi+i)->nume);
    }
}

void val_mediana(struct elev * elevi, int nr_elevi, char * c){
    int aux;
    for(int i=0;i<nr_elevi;i++){
        if(!strcmp((elevi+i)->cod,c)){
            int b=0;
            while(!b){
                b=1;
                for(int j=0;j<8;j++){
                    if((elevi+i)->note[j]>(elevi+i)->note[j+1]){
                        aux=(elevi+i)->note[j];
                        (elevi+i)->note[j]=(elevi+i)->note[j+1];
                        (elevi+i)->note[j+1]=aux;
                        b=0;
                    }
                }
            }
            printf("%d\n", (elevi+i)->note[4]);
        }
    }
}

int main(){
    int nr_elevi,t;
    struct elev * elevi;
    
    scanf("%d", &nr_elevi);
    
    elevi=(struct elev *)malloc(nr_elevi*sizeof(struct elev));
    
    for(int i=0;i<nr_elevi;i++){
        scanf("%s", (elevi+i)->nume);
        scanf("%s", (elevi+i)->cod);
        for(int j=0;j<9;j++)
            scanf("%d", &(elevi+i)->note[j]);
    }
    scanf("%d", &t);
    
    if(t==1){
        afisare(elevi, nr_elevi);
    }
    else if(t==2){
        medie_max(elevi, nr_elevi);
    }
    else if(t==3){
        medie_min(elevi, nr_elevi);
    }
    else if(t==4){
        char cod_2[20];
        scanf("%s", cod_2);
        val_mediana(elevi, nr_elevi, cod_2);
    }
    
    return 0;
}
