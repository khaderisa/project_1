#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef char String[50];
struct queueRecord{
    int Capacity;
    int Front;
    int Rear;
    int Size;
    String * Array;
};
typedef struct queueRecord *Queue;
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
    Queue listSpare;
};
typedef struct TEAM *nTeam;

int IsLastTeam(nTeam P);
nTeam creatListTeam() ;
void insertTeam(nTeam L, String name, String code, int noWins,
                int noDraws, int noLoses, int goalsDifference);
int IsEmptyTeam(nTeam L);
void PrintTeam (nTeam L);
void InsertLast(nTeam P, String name,String code,int noWins,
                int noDraws,int noLoses,int goalsDifference);

////////////////////////////////////////////////////////////////
struct node {
    int Data;
    struct node* Next;
};
struct node* createList();
void insertListLast(struct node* a,struct node*L);
int IsEmptyNode(struct node* L);
int IsLast(struct node* P,struct node*L);
int getGreatestNum(struct node* L);
int PN10(int n);
int numOfIndex(int n);
void insertLast(int x,struct node*L);
void DeleteList(struct node* L);
//void PrintListq(struct node* L);
void Insert(int X, struct node* P);
/////////////////////////////////////////////////
nTeam findTeam(int key,nTeam L);
nTeam FindTeam(const String c,nTeam L);
//nTeam copy(nTeam L);
void MakeEmpty(nTeam L);
nTeam deleteTeam(nTeam p,nTeam L);
void radixSort(nTeam teamList);
void findDeletePlayer(int n,nTeam A);
void findPlayer(int n,nTeam A);
///////////////////////////////////////////////////////
nPlayer creatPlayer();
void insertPlayer(String X, nPlayer P);
int compare(char a[100],char b[100]);
void deletePlayer(nPlayer p,nPlayer L);
void PrintPlayers(nPlayer A){
    printf("a\n");
//    int n=0;
    printf("a\n");
    nPlayer p=A->Next;
    printf("a\n");
    while (p != NULL) {
        printf("A\n");
//        ++n;
        p=p->Next;
        printf("%s\n",p->name);
//        printf("%d-%s\n",n,p->name);
    }
//    if (n == 0) {
//        printf("null\n");
//    }
}
///////////////////////
Queue creatQueue(int max);
int isFull(Queue A);
int succ(int value,Queue q);
void Enqueue(String x,Queue Q);
int isEmptyQueue(Queue A);
int Front( Queue Q );
//////////////////////////////////////////////////////////////////
int main() {


    nTeam A= creatListTeam();
    FILE *fileTeam;
    fileTeam = fopen("C:\\Users\\2019\\Desktop\\teams.txt", "r");



    String a;
    char *t;
    String name, code, wins, draw, lose, df;
    while(fgets(a,50,fileTeam)!=NULL){
        t = strtok(a, ",");
        strcpy(name, t);
        t = strtok(NULL, ",");
        strcpy(code, t);
        t = strtok(NULL, ",");
        strcpy(wins, t);
        t = strtok(NULL, ",");
        strcpy(draw, t);
        t = strtok(NULL, ",");
        strcpy(lose, t);
        t = strtok(NULL, ",");
        strcpy(df, t);
        insertTeam(A, name, code, atoi(wins), atoi(draw),
                   atoi(lose), atoi(df));
    }

    FILE *filePlayers;
    filePlayers = fopen("C:\\Users\\2019\\Desktop\\players.txt", "r");
    String string ;
    nTeam team;

    int n=0;
    while(fgets(a,20,filePlayers)!=NULL){
        if(a[0]=='*'){
            t = strtok(a, "*");
            strcpy(string, t);
            team = FindTeam(string, A);
            team->listPlayer=creatPlayer();
            team->listSpare=creatQueue(11);
        }
        else if(n<11){
            n++;
            t = strtok(a, "-");
            t = strtok(NULL, "-");
            insertPlayer(t, team->listPlayer);
        }else{
            t = strtok(a, "-");
            t = strtok(NULL, "-");
            printf("%s\n",t);
            Enqueue(t, team->listSpare);
        }
    }

    radixSort(A);
    PrintTeam(A);


    int choose ;
    FILE * fileIn;
    fileIn = fopen("C:\\Users\\2019\\Desktop\\teaminfo.txt", "w");

    do{
        printf("1-Add Team\n"
               "2-Delete Team\n"
               "3-modify\n"
               "4-match\n"
               "0-out\n");
        scanf("%d", &choose);

        switch (choose) {
            case 1:
                printf(" Enter information like this\nname, code, No. of wins,"
                       " No. of draws, No. of loses,"
                       " Goals difference\n");
                scanf("%s", a);
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
                insertTeam(A, name, code, atoi(wins) , atoi(draw),
                       atoi(lose) , atoi(df) );
                radixSort(A);
                break;
            case 2:
                printf("Enter code of team you want to delete .\n");

                String td;
                scanf("%s", &td);
                nTeam q = FindTeam(td, A);
                deleteTeam(q, A);
                printf("deleted\n");
                radixSort(A);
                break;
            case 3:
                printf("Enter the code of team \n");
                String dt;
                scanf("%s", &dt);
                nTeam w = FindTeam(dt, A);
                if(w==NULL)
                    break;
                printf("Enter No. of wins,No. of draws, No. of loses,Goals difference\n");
                scanf("%s", &a);
                t = strtok(a, ",");
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
                insertTeam(A, w->name, w->code, atoi(wins) , atoi(draw),
                       atoi(lose) , atoi(df) );
                deleteTeam(w, A);
                radixSort(A);
                break;
            case 4:
                do{
                    printf("enter code of team 1\n");
                    scanf("%s", &a);
                    nTeam t1 = FindTeam(a, A);

                    printf("enter code of team 2\n");
                    scanf("%s", &a);
                    nTeam t2 = FindTeam(a, A);

                    printf("1-change player \n"
                           "2-red card\n"
                           "3-goal!!!\n"
                           "0-end match\n");
                    scanf("%d", &choose);
                    switch (choose) {
                        case 1:
                            printf("witch team?\n"
                                   "1-%s\n"
                                   "2-%s\n", t1->name, t2->name);
                            scanf("%d", &choose);
                            switch (choose) {
                                case 1:
                                    PrintPlayers(t1->listPlayer);
                                    scanf("%d", &choose);
                                    findDeletePlayer(choose, t1);
                                    break;
                                case 2:
                                    PrintPlayers(t1->listPlayer);
                                    scanf("%d", &choose);
                                    findDeletePlayer(choose, t2);
                                    break;
                                default:
                                    printf("wrong number\ntry again");
                                    break;
                            }
                            break;
                        case 2:
                            printf("witch team?\n"
                                   "1-%s\n"
                                   "2-%s\n", t1->name, t2->name);
                            scanf("%d", &choose);
                            switch (choose) {
                                case 1:
                                    printf("sdfsd");
                                    PrintPlayers(t1->listPlayer);
                                    printf("fdfdf");
                                    scanf("%d", &choose);
                                    findPlayer(choose, t1);
                                    break;
                                case 2:
                                    PrintPlayers(t2->listPlayer);
                                    scanf("%d", &choose);
                                    findPlayer(choose, t2);
                                    break;
                                default:
                                    printf("wrong number\ntry again");
                                    break;
                            }
                            break;
                        case 3:
                            printf("witch team?\n"
                                   "1-%s\n"
                                   "2-%s\n", t1->name, t2->name);
                            scanf("%d", &choose);
                            switch (choose) {
                                case 1:
                                    ++t1->goalsDifference;
                                    break;
                                case 2:
                                    ++t2->goalsDifference;
                                    break;
                                default:
                                    printf("wrong number\ntry again");
                                    break;
                            }
                            break;
                        case 0:
                            radixSort(A);
                            break;
                        default:
                            printf("wrong number\ntry again");
                            break;
                    }
                } while (choose!=0);
            case 0:
                if(IsEmptyTeam(A))
                    fprintf(fileIn,"null\n");
                else{
                    nTeam p=A->Next;
                    while (1){
                        fprintf(fileIn,"%s,", p->name);
                        fprintf(fileIn,"%s,", p->code);
                        fprintf(fileIn,"%d,", p->noWins);
                        fprintf(fileIn,"%d,", p->noDraws);
                        fprintf(fileIn,"%d,", p->noLoses);
                        fprintf(fileIn,"%d,", p->goalsDifference);
                        fprintf(fileIn,"%d\n", p->point);
                        p=p->Next;
                        if(p==NULL)
                            break;
                    }
                }
                break;
            default:
                printf("wrong number\ntry again");
                break;
        }
    }while(choose!=0);

    PrintTeam(A);
    return 0;
}
int IsLastTeam(nTeam P){
    return P->Next==NULL;
}
nTeam creatListTeam() {
    nTeam L;
    L = (nTeam) malloc(sizeof(struct TEAM));
    L->Next = NULL;
    return L;
}
void insertTeam(nTeam L, String name, String code,
                int noWins, int noDraws, int noLoses, int goalsDifference) {
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
}
int IsEmptyTeam(nTeam L){
    return L->Next == NULL;
}
//void PrintList(nTeam L){
//    nTeam P = L;
//    if(IsEmptyTeam(L))
//        printf("Empty list\n");
//    else
//        do{
//            P=P->Next;
//            printf("%s\t", P->name);
//            printf("%s\t", P->code);
//            printf("%d\t", P->noWins);
//            printf("%d\t", P->noDraws);
//            printf("%d\t", P->noLoses);
//            printf("%d\t", P->goalsDifference);
//            printf("%d\n", P->point);
//        }while( !IsLastTeam(P) );
//    printf("\n");
//}
void PrintTeam (nTeam L){
    if(IsEmptyTeam(L))
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
    if (IsEmptyTeam(P)){
        insertTeam(P, name, code, noWins, noDraws, noLoses, goalsDifference);
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
    }
}
struct node* createList(){
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node*));
    temp->Next = NULL;
    return temp;
}
int IsEmptyNode(struct node* L) {
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
//void PrintListq(struct node* L){
//    struct node* P = L;
//    if(IsEmptyNode(L))
//        printf("Empty list");
//    else
//        do{
//            P=P->Next;
//            printf("%d\t", P->Data);
//        }while( !IsLast(P, L) );
//    printf("\n");
//}
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
//nTeam copy(nTeam L){
//    nTeam p=(nTeam) malloc(sizeof(struct TEAM));
//    strcpy(p->name,L->name);
//    strcpy(p->code,L->code);
//    p->noWins=L->noWins;
//    p->noDraws=L->noDraws;
//    p->noLoses=L->noLoses;
//    p->goalsDifference=L->goalsDifference;
//    p->point=(3*p->noWins)+p->noDraws;
//    return p;
//}
void MakeEmpty(nTeam L){
    L->Next=NULL;
}
nTeam deleteTeam(nTeam p,nTeam L){
    nTeam a=L;
    while (!IsLastTeam(a)){
        if(a->Next==p){
            a->Next=a->Next->Next;
            break;
        }
        a=a->Next;
    }
    return L;
}
nPlayer creatPlayer() {
    nPlayer L;
    L = (nPlayer) malloc(sizeof(struct Players));
    L->Next = NULL;
    return L;
}
void insertPlayer(String X, nPlayer P){
    nPlayer temp;
    temp = (nPlayer)malloc(sizeof(struct Players));
    strcpy(temp->name, X);
    temp->Next = P->Next;
    P->Next = temp;
}
int compare(char a[100],char b[100]){
    int flag=0,i=0;
    while(a[i]!='\0' &&b[i]!='\0')
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
Queue creatQueue(int max){
    Queue q;
    q =(Queue) malloc(sizeof(struct queueRecord));
    q->Array = (String *) malloc(sizeof(String) * max);
    q->Capacity=max;
    q->Size=0;
    q->Front=1;
    q->Rear=0;
    return q;
}
int isFull(Queue A){
    return A->Capacity==A->Size;
}
int succ(int value,Queue q){
    if(++value==q->Capacity)
        value=0;
    return value;
}
void Enqueue(String x,Queue Q){
    if(isFull( Q ) )
        printf("full ");
    else{
        Q->Size++;
        Q->Rear =succ( Q->Rear, Q );
        strcpy(Q->Array[Q->Rear ] , x);
    }
}
int Front( Queue Q ){
    if( !isEmptyQueue(Q) )
        return Q->Array[ Q->Front ];
    printf("Empty Queue!");
    return 0;
}
void findDeletePlayer(int n,nTeam A){
    nPlayer p=A->listPlayer;
    for (int i = 0; i < n; i++) {
        p=p->Next;
    }
    deletePlayer(p, A->listPlayer);
    Queue e=A->listSpare;
    int t = Front(e);
    insertPlayer(e->Array[t],A->listPlayer);
}
void deletePlayer(nPlayer p,nPlayer L){
    nPlayer a=L;
    while (a->Next != p ) {
        p=p->Next;
    }
    a->Next=p->Next;
    p->Next=NULL;
    free(p);
}
void findPlayer(int n,nTeam A){
    nPlayer p=A->listPlayer;
    for (int i = 0; i < n; i++) {
        p=p->Next;
    }
    deletePlayer(p, A->listPlayer);
}
int isEmptyQueue(Queue A){
    return A->Size==0;
}












































void radixSort(nTeam teamList){
    struct node* pointsList=createList();
    nTeam teamPointer=teamList->Next;
    while (!IsLastTeam(teamPointer)) {
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
            if(!IsEmptyNode(arrayList[i])){
                insertListLast(arrayList[i], pointsList);
                arrayList[i]->Next=NULL;
            }
        }
    }
    ////////////   ////
    nTeam sortedList= creatListTeam();
    teamPointer=teamList->Next;
    while(teamPointer != NULL){
        insertTeam(sortedList, teamPointer->name, teamPointer->code, teamPointer->noWins, teamPointer->noDraws,
                   teamPointer->noLoses, teamPointer->goalsDifference);
        teamPointer=teamPointer->Next;
    }
    MakeEmpty(teamList);

    pointPointer=pointsList->Next;
    while (pointPointer != NULL) {
        teamPointer= findTeam(pointPointer->Data, sortedList);
        insertTeam(teamList, teamPointer->name, teamPointer->code, teamPointer->noWins, teamPointer->noDraws,
                   teamPointer->noLoses, teamPointer->goalsDifference);
        sortedList=deleteTeam(teamPointer, sortedList);
        pointPointer=pointPointer->Next;
    }
    teamPointer=teamList;
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
}