#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef char String[100];
struct Players{
    String name;
    struct Players* Next;
};
typedef struct Players* nPlayer;
struct TEAM {
    String name;
    String code;
    int noWins;
    int noDraws;
    int noLoses;
    int goalsDifference;
    struct TEAM *Next;
    int point;
    nPlayer listPlayer;
};

typedef struct TEAM *nTeam;

int IsLastq(nTeam P);
nTeam creatList() ;
void insert(nTeam L, String name,String code,int noWins,
            int noDraws,int noLoses,int goalsDifference);
int IsEmpty(nTeam L);
void PrintList(nTeam L);
void print (nTeam L);
void InsertLast(nTeam P, String name,String code,int noWins,
                int noDraws,int noLoses,int goalsDifference);
void addTeam();

////////////////////////////////////////////////////////////////
struct node {
    int Data;
    struct node* Next;
};
struct node* createList();
int IsEmptyq(struct node* L);
int getGreatestNum(struct node* L);
int PN10(int n);
int numOfIndex(int n);
int IsLast(struct node* P,struct node*L);
void insertLast(int x,struct node*L);
void DeleteList(struct node* L);
void insertListLast(struct node* a,struct node*L);
void PrintListq(struct node* L);
void Insert(int X, struct node* P);
nTeam findTeam(int key,nTeam L);
nTeam FindTeam(const String c,nTeam L);
nTeam copy(nTeam L);
void MakeEmpty(nTeam L);
nTeam deleteTeam(nTeam p,nTeam L);
///////////////////////
void radixSort(nTeam b){
    struct node* A=createList();
    nTeam u=b->Next;
    while (!IsLastq(u)) {
        Insert(u->point, A);
        u=u->Next;
    }
    Insert(u->point, A);

    struct node* arrayList[10];
    for (int i = 0; i < 10; i++) {
        arrayList[i]=createList();
    }
    int ab=getGreatestNum(A);
    int n = numOfIndex(ab);
    struct node*p;
    int a,md,dv;
    for (int count = 0; count < n; count++) {
        p=A->Next;
        md=PN10(count+1);
        dv=PN10(count);
        do{
            a=((p->Data)% md)/dv;
            insertLast(p->Data,arrayList[a]);
            p=p->Next;
        } while (p!=NULL);
        DeleteList(A);
        for (int i = 0; i < 10; i++) {
            if(!IsEmptyq(arrayList[i])){
                insertListLast(arrayList[i],A);
                arrayList[i]->Next=NULL;
            }
        }
    }
    ////////////   ////
    nTeam e=creatList();
    u=b->Next;
    while(u!=NULL){
        insert(e,u->name,u->code,u->noWins,u->noDraws,
               u->noLoses,u->goalsDifference);
//        b=deleteTeam(b);
//        PrintList(b);
        u=u->Next;
    }
    MakeEmpty(b);
//    PrintList(A);
//    PrintList(e);

    struct node*o=A->Next;
//    printf("hjhj\n");
    while (o != NULL) {
        u= findTeam(o->Data,e);
        insert(b,u->name,u->code,u->noWins,u->noDraws,
               u->noLoses,u->goalsDifference);
        e=deleteTeam(u,e);
//        PrintList(e);
        o=o->Next;

    }
//    PrintList(b);
    u=b;
    int c=1;
    while (u->Next->Next != NULL ) {
        if((u->Next->point==u->Next->Next->point) &&
                (u->Next->goalsDifference)<(u->Next->Next->goalsDifference)){
            nTeam s=u->Next;
            u->Next=s->Next;
            s->Next=u->Next->Next;
            u->Next->Next=s;

        }
        u=u->Next;
    }
//    print(b);
}
///////////////////////////////////////////////////////
//struct Players{
//    String name;
//    struct Players* Next;
//};
//typedef struct Players* nPlayer;
nPlayer creatPlayer(){
    nPlayer L;
    L=(nPlayer) malloc(sizeof (struct Players));
    L->Next=NULL;
    printf("creat\n");
    return L;
}void Inserwt(String X, nPlayer P){
    nPlayer temp;
    temp = (struct node*)malloc(sizeof(struct node));
    strcpy(temp->name, X);
    temp->Next = P->Next;
    P->Next = temp;
    printf("jin\n");
}
int compare(char a[],char b[])
{
    int flag=0,i=0;  // integer variables declaration
    while(a[i]!='\0' &&b[i]!='\0')  // while loop
    {
        if(a[i]!=b[i])
        {
            flag=1;
            break;
        }
        i++;
    }
    if(flag==0)
        return 0;
    else
        return 1;
}
//////////////////////////////////////////////////////////////////
int main() {

    nTeam A=creatList();
//    print(A);
    FILE *fileTeam;
    fileTeam = fopen("C:\\Users\\2019\\Desktop\\teams.txt", "r");



    String a;
    char *t;
    String name, code, wins, draw, lose, df;
    while(fgets(a,50,fileTeam)!=NULL){
        printf("%s\n", a);
        t = strtok(a, ",");
        strcpy(name, t);
        printf("%s\n", t);
        t = strtok(NULL, ",");
        strcpy(code, t);
        printf("%s\n", t);
        t = strtok(NULL, ",");
        strcpy(wins, t);
        printf("%s\n", t);
        t = strtok(NULL, ",");
        strcpy(draw, t);
        printf("%s\n", t);
        t = strtok(NULL, ",");
        strcpy(lose, t);
        printf("%s\n", t);
        t = strtok(NULL, ",");
        strcpy(df, t);
        printf("%s\n", t);
        insert(A, name, code, atoi(wins) , atoi(draw),
               atoi(lose) , atoi(df) );
    }

    radixSort(A);
    print(A);
//
//    int choose ;
//    FILE * fileIn;
//    fileIn = fopen("C:\\Users\\2019\\Desktop\\teaminfo.txt", "w");
//
//    do{
//        printf("1-Add Team\n"
//               "2-Delete Team\n"
//               "3-modify\n"
//               "0-out\n");
//        scanf("%d", &choose);
//
//        switch (choose) {
//            case 1:
//                printf(" Enter information like this\nname, code, No. of wins,"
//                       " No. of draws, No. of loses,"
//                       " Goals difference\n");
//                scanf("%s", a);
//                printf("%s\n", a);
//                t = strtok(a, ",");
//                strcpy(name, t);
//                printf("%s\n", t);
//                t = strtok(NULL, ",");
//                strcpy(code, t);
//                printf("%s\n", t);
//                t = strtok(NULL, ",");
//                strcpy(wins, t);
//                printf("%s\n", t);
//                t = strtok(NULL, ",");
//                strcpy(draw, t);
//                printf("%s\n", t);
//                t = strtok(NULL, ",");
//                strcpy(lose, t);
//                printf("%s\n", t);
//                t = strtok(NULL, ",");
//                strcpy(df, t);
//                printf("%s\n", t);
//                insert(A, name, code, atoi(wins) , atoi(draw),
//                       atoi(lose) , atoi(df) );
//                radixSort(A);
//                break;
//            case 2:
//                printf("Enter code of team you want to delete .\n");
//
//                String td;
//                scanf("%s", &td);
//                nTeam q = FindTeam(td, A);
//                deleteTeam(q, A);
//                printf("deleted\n");
//                radixSort(A);
//                break;
//            case 3:
//                printf("Enter the code of team \n");
//                String dt;
//                scanf("%s", &dt);
//                nTeam w = FindTeam(dt, A);
//                if(w==NULL)
//                    break;
//                printf("Enter No. of wins,No. of draws, No. of loses,Goals difference\n");
//                scanf("%s", &a);
//                t = strtok(a, ",");
//                strcpy(wins, t);
//                printf("%s\n", t);
//                t = strtok(NULL, ",");
//                strcpy(draw, t);
//                printf("%s\n", t);
//                t = strtok(NULL, ",");
//                strcpy(lose, t);
//                printf("%s\n", t);
//                t = strtok(NULL, ",");
//                strcpy(df, t);
//                printf("%s\n", t);
//                insert(A, w->name, w->code, atoi(wins) , atoi(draw),
//                       atoi(lose) , atoi(df) );
//                deleteTeam(w, A);
//                radixSort(A);
//                break;
//            case 0:
//                if(IsEmpty(A))
//                    fprintf(fileIn,"null\n");
//                else{
//                    nTeam p=A->Next;
//                    while (1){
//                        fprintf(fileIn,"%s,", p->name);
//                        fprintf(fileIn,"%s,", p->code);
//                        fprintf(fileIn,"%d,", p->noWins);
//                        fprintf(fileIn,"%d,", p->noDraws);
//                        fprintf(fileIn,"%d,", p->noLoses);
//                        fprintf(fileIn,"%d,", p->goalsDifference);
//                        fprintf(fileIn,"%d\n", p->point);
//                        p=p->Next;
//                        if(p==NULL)
//                            break;
//                    }
//                }
//                break;
//            default:
//                printf("wrong number\ntry again");
//                break;
//        }
//    }while(choose!=0);
//    print(A);
    FILE *filePlayers;
    filePlayers = fopen("C:\\Users\\2019\\Desktop\\players.txt", "r");
//    fscanf(filePlayers, "%s", &a);
//    printf("%s\n", a);
////    a[0]= (char) NULL;
//    printf("%c\n", a[0]);
////    t = strtok(a, "*");
//    printf("%s\n", t);
    nPlayer V;
    String m ;
//    m = strtok(a, "*");
    nTeam I;
//    I= FindTeam(t, A);
//    printf("%s\n",I->name);
//    printf("sd\n");



    while(fgets(a,20,filePlayers)!=NULL){
        if(a[0]=='*'){
            printf("creat\n");
            t = strtok(a, "*");
//            V=creatPlayer();
            strcpy(m, t);
            printf("%s\n", m);
            I = FindTeam(m, A);
            I->listPlayer=creatPlayer();
        }else{
            printf("insert\n");
            t = strtok(a, "-");
            t = strtok(NULL, "-");
            printf("%s\n",t);
            Inserwt(t,I->listPlayer);
        }
    }


    return 0;
}
int IsLastq(nTeam P){
    return P->Next==NULL;
}
nTeam creatList() {
    nTeam L;
    L = (nTeam) malloc(sizeof(struct TEAM));
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
    p->point=(3*p->noWins)+p->noDraws;
//    printf("insert\n");
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
            printf("%d\t", P->goalsDifference);
            printf("%d\n", P->point);
        }while( !IsLastq(P) );
    printf("\n");
}
void print (nTeam L){
    if(IsEmpty(L))
        printf("null\n");
    else{
        nTeam p=L->Next;
        while (1){
            printf("%s\t", p->name);
            printf("%s\t", p->code);
            printf("%d\t", p->noWins);
            printf("%d\t", p->noDraws);
            printf("%d\t", p->noLoses);
            printf("%d\t", p->goalsDifference);
            printf("%d\n", p->point);
            p=p->Next;
            if(p==NULL)
                break;
        }
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
        p->point=(3*p->noWins)+p->noDraws;
        p->Next->Next = t;
        t->Next = NULL;
        printf("insert last\n");
    }
}
struct node* createList(){
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node*));
    temp->Next = NULL;
    return temp;
}
int IsEmptyq(struct node* L) {
    return L->Next == NULL;
}
int getGreatestNum(struct node* L){
    if(L->Next==NULL)
        return -1;
    struct node*p=L->Next;
    int n=p->Data;
    while (p->Next != NULL) {
        p=p->Next;
        if (p->Data > n) {
            n=p->Data;
        }
    }
    return n;
}
int PN10(int n){
    int a=10;
    if(n==0)
        return 1;
    else
        for (int i = 1; i < n; i++)
            a*=10;
    return a;
}
int numOfIndex(int n){
    int a=0;
    while (1){
        n/=10;
        ++a;
        if(n==0)
            break;
    }
    return a;
}
int IsLast(struct node* P,struct node*L){
    return P->Next==NULL;
}
void insertLast(int x,struct node*L){
    struct node *p=L;
    struct node*temp=(struct node*) malloc(sizeof(struct node));
    while (!IsLast(p,L)){
        p=p->Next;
    }
    p->Next=temp;
    temp->Next=NULL;
    temp->Data=x;
}
void DeleteList(struct node* L) {
    struct node *P, *temp;
    P = L->Next;
    L->Next = NULL;
    while (P != NULL) {
        temp = P->Next;
        free(P);
        P = temp;
    }
}
void insertListLast(struct node* a,struct node*L){
    struct node *p=L;
    while (!IsLast(p,L)){
        p=p->Next;
    }
    p->Next=a->Next;
}
void PrintListq(struct node* L){
    struct node* P = L;
    if(IsEmptyq(L))
        printf("Empty list");
    else
        do{
            P=P->Next;
            printf("%d\t", P->Data);
        }while( !IsLast(P, L) );
    printf("\n");
}
void Insert(int X, struct node* P){
    struct node*temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->Data = X;
    temp->Next = P->Next;
    P->Next = temp;
}
nTeam findTeam(int key,nTeam L){
    nTeam p=L->Next;
    while(p!=NULL){
        if(p->point==key)
            break;
        p=p->Next;
    }
    return p;
}
nTeam FindTeam(const String c,nTeam L){
    nTeam p=L->Next;
    int a=0;
    while(p!=NULL){
        if(!compare(p->code,c)){
            a=1;
            break;
        }
        p=p->Next;
    }
    if(a==0)
        printf("not exist!\n");
    return p;
}
nTeam copy(nTeam L){
    nTeam p=(nTeam) malloc(sizeof(struct TEAM));
    strcpy(p->name,L->name);
    strcpy(p->code,L->code);
    p->noWins=L->noWins;
    p->noDraws=L->noDraws;
    p->noLoses=L->noLoses;
    p->goalsDifference=L->goalsDifference;
    p->point=(3*p->noWins)+p->noDraws;
    return p;
}
void MakeEmpty(nTeam L){
    L->Next=NULL;
}
nTeam deleteTeam(nTeam p,nTeam L){
//    printf("dff\n");
    nTeam a=L;
    while (!IsLastq(a)){
        if(a->Next==p){
            a->Next=a->Next->Next;
            break;
        }
        a=a->Next;
    }
//    L=L->Next;
    return L;
}