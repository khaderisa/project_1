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
void radixSort(nTeam teamList){
    struct node* pointsList=createList();
    nTeam teamPointer=teamList->Next;
    while (!IsLastq(teamPointer)) {
        Insert(teamPointer->point, pointsList);
        teamPointer=teamPointer->Next;
    }
    Insert(teamPointer->point, pointsList);

    struct node* arrayList[10];
    for (int i = 0; i < 10; i++) {
        arrayList[i]=createList();
    }
    int greatestNum=getGreatestNum(pointsList);
    int numberOfIndex = numOfIndex(greatestNum);
    struct node*pointPointer;
    int N,modNum,divNum;
    for (int count = 0; count < numberOfIndex; count++) {
        pointPointer=pointsList->Next;
        modNum=PN10(count + 1);
        divNum=PN10(count);
        do{
            N= ((pointPointer->Data) % modNum) / divNum;
            insertLast(pointPointer->Data, arrayList[N]);
            pointPointer=pointPointer->Next;
        } while (pointPointer != NULL);
        DeleteList(pointsList);
        for (int i = 0; i < 10; i++) {
            if(!IsEmptyq(arrayList[i])){
                insertListLast(arrayList[i], pointsList);
                arrayList[i]->Next=NULL;
            }
        }
    }
    ////////////   ////
    nTeam sortedList=creatList();
    teamPointer=teamList->Next;
    while(teamPointer != NULL){
        insert(sortedList, teamPointer->name, teamPointer->code, teamPointer->noWins, teamPointer->noDraws,
               teamPointer->noLoses, teamPointer->goalsDifference);
//        teamList=deleteTeam(teamList);
//        PrintList(teamList);
        teamPointer=teamPointer->Next;
    }
    MakeEmpty(teamList);
//    PrintList(pointsList);
//    PrintList(sortedList);

//    struct node*o=pointsList->Next;
    pointPointer=pointsList->Next;
//    printf("hjhj\numberOfIndex");
    while (pointPointer != NULL) {
        teamPointer= findTeam(pointPointer->Data, sortedList);
        insert(teamList, teamPointer->name, teamPointer->code, teamPointer->noWins, teamPointer->noDraws,
               teamPointer->noLoses, teamPointer->goalsDifference);
        sortedList=deleteTeam(teamPointer, sortedList);
//        PrintList(sortedList);
        pointPointer=pointPointer->Next;
    }
//    PrintList(teamList);
    teamPointer=teamList;
//    int c=1;
    while (teamPointer->Next->Next != NULL ) {
        if((teamPointer->Next->point == teamPointer->Next->Next->point) &&
           (teamPointer->Next->goalsDifference) < (teamPointer->Next->Next->goalsDifference)){
            nTeam firstTeam=teamPointer->Next;
            teamPointer->Next=firstTeam->Next;
            firstTeam->Next=teamPointer->Next->Next;
            teamPointer->Next->Next=firstTeam;

        }
        teamPointer=teamPointer->Next;
    }
//    print(teamList);
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
}void insertPlayer(String X, nPlayer P){
    nPlayer temp;
    temp = (nPlayer)malloc(sizeof(struct Players));
    strcpy(temp->name, X);
    temp->Next = P->Next;
    P->Next = temp;
    printf("jin\n");
}
int compare(char a[100],char b[100])
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
            insertPlayer(t, I->listPlayer);
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