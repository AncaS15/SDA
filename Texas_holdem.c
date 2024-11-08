#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct jucator{
    char nume[20];
    int carte_1, carte_2;
    int carti_t[7];
    int mana[5];
    //int pct=0;
};

void afisare(struct jucator * joc, int n){
    for(int i=0;i<n;i++){
        printf("%s\n", (joc+i)->nume);
        printf("%d ", (joc+i)->carte_1);
        printf("%d \n", (joc+i)->carte_2);
    }
}

void sort(int nr_elemente, int* ptr) 
{ 
    int i, j, temp;
    for (i = 0; i < nr_elemente - 1; i++) {
        for (j = i + 1; j < nr_elemente; j++){
            if (*(ptr + j) < *(ptr + i)){
                temp = *(ptr + i); 
                *(ptr + i) = *(ptr + j); 
                *(ptr + j) = temp; 
            } 
        } 
    } 
}

void sort_i(int nr_elemente, int* ptr) 
{ 
    int i, j, temp;
    for (i = 0; i < nr_elemente - 1; i++) {
        for (j = i + 1; j < nr_elemente; j++){
            if (*(ptr + j) > *(ptr + i)){
                temp = *(ptr + i); 
                *(ptr + i) = *(ptr + j); 
                *(ptr + j) = temp; 
            } 
        } 
    } 
}

int main(){
    int nr_jucatori,c;
    int etalate[5];
    struct jucator * joc;
    
    scanf("%d", &nr_jucatori);
    joc=malloc(nr_jucatori*sizeof(struct jucator));
    
    for(int i=0;i<nr_jucatori;i++){
        scanf("%s", (joc+i)->nume);
        scanf("%d%d", &(joc+i)->carte_1, &(joc+i)->carte_2);
    }
    for(int i=0;i<5;i++)
        scanf("%d", &etalate[i]);
    scanf("%d", &c);
    
    if(c==1){
        afisare(joc, nr_jucatori);
        for(int i=0;i<5;i++)
            printf("%d ", etalate[i]);
        printf("\n");
    }
    else if(c==2){
        int x=0;
        for(int i=0;i<nr_jucatori;i++){
            for(int j=0;j<5;j++){
                (joc+i)->carti_t[j]=etalate[j];
            }
            (joc+i)->carti_t[5]=(joc+i)->carte_1;
            (joc+i)->carti_t[6]=(joc+i)->carte_2;
            sort(7,(joc+i)->carti_t);
            for(int j=0;j<7;j++){
                for(int k=j+1;k<7;k++){
                    if((joc+i)->carti_t[j]==(joc+i)->carti_t[k]){
                        (joc+i)->carti_t[k]=0;
                    }
                }
            }
            sort(7,(joc+i)->carti_t);
            for(int j=0;j<3;j++){
                x=0;
                for(int k=j+1;k<j+5;k++){
                    if((joc+i)->carti_t[j]==(joc+i)->carti_t[k]-(k-j) && (joc+i)->carti_t[j]!=0)
                        x++;    
                }
                if(x==4){
                    printf("%s\n", (joc+i)->nume);
                    for(int k=j;k<j+5;k++){
                        printf("%d ", (joc+i)->carti_t[k]);
                    }
                    printf("\n");
                }
            }
        }
    }
    else if(c==3){
        for(int i=0;i<nr_jucatori;i++){
            int x=0;
            for(int j=0;j<5;j++)
                (joc+i)->carti_t[j]=etalate[j];
            (joc+i)->carti_t[5]=(joc+i)->carte_1;
            (joc+i)->carti_t[6]=(joc+i)->carte_2;
            sort_i(7,(joc+i)->carti_t);
            for(int j=0;j<6 && x<5;j++){
                if(j<5 && (joc+i)->carti_t[j]!=0 && (joc+i)->carti_t[j]==(joc+i)->carti_t[j+1] && (joc+i)->carti_t[j]==(joc+i)->carti_t[j+2]){
                    (joc+i)->mana[x]=(joc+i)->carti_t[j];
                    (joc+i)->mana[x+1]=(joc+i)->carti_t[j+1];
                    (joc+i)->mana[x+2]=(joc+i)->carti_t[j+2];
                    j+=2;
                    x+=3;
                    //(joc+i)->carti_t[j]=0; (joc+i)->carti_t[j+1]=0; (joc+i)->carti_t[j+2]=0;
                }
                else if((joc+i)->carti_t[j]!=0 && (joc+i)->carti_t[j]==(joc+i)->carti_t[j+1]){
                    (joc+i)->mana[x]=(joc+i)->carti_t[j];
                    (joc+i)->mana[x+1]=(joc+i)->carti_t[j+1];
                    j+=1;
                    x+=2;
                    //(joc+i)->carti_t[j]=0; (joc+i)->carti_t[j+1]=0;
                }
            }
            // for(int j=0;j<7 && x<5;j++)
            //     if((joc+i)->carti_t[j]!=0)
            //         (joc+i)->mana[x++]=(joc+i)->carti_t[j];
            for(int j=0;j<7 && x<5;j++){
                int a=0;
                for(int k=0;k<5;k++){
                    if((joc+i)->carti_t[j]==(joc+i)->mana[k]){
                        a=1; break;
                    }
                }
                if(!a){
                    (joc+i)->mana[x]=(joc+i)->carti_t[j];
                    x++;
                }
            }
            sort(5,(joc+i)->mana);
            printf("%s\n", (joc+i)->nume);
            for(int j=0;j<5;j++)
                printf("%d ", (joc+i)->mana[j]);
            printf("\n");
        }
    }
    else if(c==4){
        
    }
        
    
    
    return 0;
}
