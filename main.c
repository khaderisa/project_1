#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef char String[100];

struct TEAM {
    String name;
    String code;
    int noWins;
    int noDraws;
    int noLoses;
    int goalsDifference;
    struct TEAM *Next;
};

typedef struct TEAM *nTeam;

int IsLast(nTeam P){
    return P->Next==NULL;
}
nTeam creatList() {
    nTeam L;
    L = (nTeam) malloc(sizeof(nTeam));
    L->Next = NULL;
    return L;
}

void insert(nTeam L, String name,String code,
            int noWins,int noDraws,int noLoses,int goalsDifference) {
    nTeam p;
    p = (nTeam) malloc(sizeof(struct TEAM));
    p->Next = L->Next;
    L->Next = p;
    strcpy(p->name, name);
    strcpy(p->code, code);
    p->noWins=noWins;
    p->noDraws=noDraws;
    p->noLoses=noLoses;
    p->goalsDifference=goalsDifference;
    printf("insert\n");

}
int IsEmpty(nTeam L){
    return L->Next == NULL;
}
void PrintList(nTeam L){
    nTeam P = L;
    if(IsEmpty(L))
        printf("Empty list\n");
    else
        do{
            P=P->Next;
            printf("%s\t", P->name);
            printf("%s\t", P->code);
            printf("%d\t", P->noWins);
            printf("%d\t", P->noDraws);
            printf("%d\t", P->noLoses);
            printf("%d\n", P->goalsDifference);
        }while( !IsLast(P) );
    printf("\n");
}
void print (nTeam L){
    nTeam p=L->Next;
    while (1){
        printf("%s\t", p->name);
        printf("%s\t", p->code);
        printf("%d\t", p->noWins);
        printf("%d\t", p->noDraws);
        printf("%d\t", p->noLoses);
        printf("%d\n", p->goalsDifference);
        p=p->Next;
        if(p==NULL)
            break;
    }
}
void InsertLast(nTeam P, String name,String code,
                int noWins,int noDraws,int noLoses,int goalsDifference){
    nTeam p=P;
    if (IsEmpty(P)){
        insert(P,name,code,noWins,noDraws,noLoses,goalsDifference);
    } else {
        nTeam t;
        while (p->Next->Next!=NULL){
            p=p->Next;
        }
        t = (nTeam)malloc(sizeof(nTeam));
        strcpy(p->name, name);
        strcpy(p->code, code);
        p->noWins=noWins;
        p->noDraws=noDraws;
        p->noLoses=noLoses;
        p->goalsDifference=goalsDifference;
        p->Next->Next = t;
        t->Next = NULL;
        printf("insert last\n");
    }
}

int main() {

    nTeam A=creatList();

    FILE *fileTeam;
    fileTeam = fopen("C:\\Users\\2019\\Desktop\\teams.txt", "r");


    String a;
    char *t;
    String name, code, wins, draw, lose, df;
    for (int i=0;i<4;i++) {
//        if (a==NULL)
//            break;
        fscanf(fileTeam, "%s", &a);
        printf("%s\n", a);
//        int i = 1;
        t = strtok(a, ",");
//        printf("%s\n", t);
        strcpy(name, t);
//        printf("%s\n", name);
        printf("%s\n", t);
        t = strtok(NULL, ",");
        strcpy(code, t);
//        printf("%s\n", code);
        printf("%s\n", t);
        t = strtok(NULL, ",");
        strcpy(wins, t);
//        printf("%s\n", wins);
        printf("%s\n", t);
        t = strtok(NULL, ",");
        strcpy(draw, t);
//        printf("%s\n", draw);
        printf("%s\n", t);
        t = strtok(NULL, ",");
        strcpy(lose, t);
//        printf("%s\n", lose);
        printf("%s\n", t);
        t = strtok(NULL, ",");
        strcpy(df, t);
//        printf("%s\n", df);
        printf("%s\n", t);
        insert(A, name, code, atoi(wins) , atoi(draw),
               atoi(lose) , atoi(df) );
//        fscanf(fileTeam, "%s", &a);
    }


//    printf("%s\n",A->Next->name);
//    PrintList(A);
    print(A);
























//    String a;
//    fscanf(fileTeam,"%s", &a);
//    printf("%s\n",a);
//
//    char *t;
//    String name ,code,wins ,draw,lose,df;
//    int i=1;
//    t=strtok(a,",");
//    printf("%s\n", t);
//    strcpy(name, t);
//    printf("%s\n", name);
//    printf("%s\n", t);
//    t=strtok(NULL,",");
//    strcpy(code, t);
//    printf("%s\n", code);
//    printf("%s\n", t);
//    t=strtok(NULL,",");
//    strcpy(wins, t);
//    printf("%s\n", wins);
//    printf("%s\n", t);
//    t=strtok(NULL,",");
//    strcpy(draw, t);
//    printf("%s\n", draw);
//    printf("%s\n", t);
//    t=strtok(NULL,",");
//    strcpy(lose, t);
//    printf("%s\n", lose);
//    printf("%s\n", t);
//    t=strtok(NULL,",");
//    strcpy(df, t);
//    printf("%s\n", df);
//    printf("%s\n", t);




//    while (t != NULL) {
//        t=strtok(NULL,",");
//        printf("%s\n", t);
//        //strcpy(strArray[0], t);
//        i++;
//    }
//    printf("arr: %s\n", strArray[0]);
/////////////////////

//    char *t;
//    String strArray[7];
//    int i=1;
//    t=strtok(a,",");
//    printf("%s\n", t);
//    strcpy(strArray[0], t);
//    while (t != NULL) {
//        t=strtok(NULL,",");
//        printf("%s\n", t);
//        strcpy(strArray[i], t);
//        i++;
//    }

    return 0;
}
