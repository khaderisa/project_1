#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef char String[100];

struct TEAM {
    String name;
    char *code;
    int noWins;
    int noDraws;
    int noLoses;
    int goalsDifference;
    struct TEAM *Next;
};

typedef struct TEAM *nTeam;

nTeam creatList() {
    nTeam L;
    L = (nTeam) malloc(sizeof(nTeam));
    L->Next = NULL;
    return L;
}

void insert(nTeam L, String name) {
    nTeam p = (nTeam) malloc(sizeof(nTeam));
    p->Next = L->Next;
    L->Next = p;
    strcpy(p->name, name);

}

int main() {

    FILE *fileTeam;
    fileTeam = fopen("C:\\Users\\2019\\Desktop\\teams.txt", "r");
    String a;
//    char *ar[7];
//
//    int i=0;
//
//    fscanf(fileTeam,"%s", &a);
//    printf("%s\n",a);
    char *t;
//    t=strtok(a,",");
//    printf("%s\n", t);
//    ar[0]=t;
//    ++i;
//    while (t != NULL) {
//        t=strtok(NULL,",");
////        printf("%s\n", t);
//        ar[i+1]=t;
//        ++i;
//    }
//
////    printf("%s\n", ar[0]);
////    for (int i = 1; i< 7; i++) {
////        arr[i]=ar[i];
////    }
//    for (int i = 1; i< 7; i++) {
//        printf("%s\n", ar[i]);
//    }
////    for (int i = 1; i< 6; i++) {
////        printf("%s\n", ar[i]);
////    }



    nTeam A = creatList();

    fscanf(fileTeam, "%s", &a);
    printf("%s\n", a);
    t = strtok(a, ",");
//    printf("%s\n", t);
    String strArray[6];
    strcpy(strArray[0],t);

    //char *s = t;

    int i=1;
    while (t != NULL) {
        t = strtok(NULL, ",");
        strcpy(strArray[i],t);
        printf("arr: %s\n", strArray[i]);
        i++;

    }

    for (int y = 0; y < 6; y++) {
        printf("%s",strArray[y]);
    }
    //printf("%s\n", s);
//    insert(A, t);
//    printf("%s", A->name);
    return 0;
}
