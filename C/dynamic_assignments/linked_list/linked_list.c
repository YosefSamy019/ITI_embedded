#include <stdio.h>
#define NULL ((void*)0)


struct SData{
    int id;
    char name[40];
    float height;
};

struct SStudent{
    struct SData data;
    struct SStudent * pNext;
};

void AddStudent();
int DeleteStudent();
void DisplayAll();
void DeleteAll();
void Reverse();
void GetNthNode();
void GetMiddle();
void GetLengthIterate();
void GetLengthRecursive();

int main(void)
{


    do
    {
        printf("Enter:-\n");
        printf("0: add student\n");
        printf("1: remove student\n");
        printf("2: display all\n");
        printf("3: delete all\n");
        printf("4: reverse\n");
        printf("5: get nTh node\n");
        printf("6: get middle\n");
        printf("7: get Length Iterate\n");
        printf("8: get Length Recursive\n");

        int i,temp;

        printf("--> ");
        scanf("%d",&i);

        switch(i)
        {
        case 0:
            AddStudent();
            break;
        case 1:
            temp = DeleteStudent();
            printf((temp == 1)? "Deleted\n" : "NotFound\n" );
            break;
        case 2:
            DisplayAll();
            break;
        case 3:
            DeleteAll();
            break;
        case 4:
            Reverse();
            break;
        case 5:
            GetNthNode();
            break;
        case 6:
            GetMiddle();
            break;
        case 7:
            GetLengthIterate();
            break;
        case 8:
            GetLengthRecursive();
            break;
        default:
            printf("Unsupported\n");
            break;
        }


        printf("-------------\n");
        printf("Press Enter to return to menu");
        getch();
        system("cls"); // For Windows use system("cls");

    }
    while(1);
    return 0;
}

// ------------------------------------------------------------

struct SStudent *pFirstStudent = NULL;

static void fill_record(struct SData * data)
{



    printf("Enter id: ");
    scanf("%d",&(data->id));

    fflush(stdin);
    fflush(stdout);

    printf("Enter name: ");
    gets(data->name);

    printf("Enter height: ");
    scanf("%f",&(data->height));
}

static void display_record(struct SData * data)
{
    printf("Id: %d\t",data->id);
    printf("Height: %f\t",data->height);
    printf("Name: %s\n",data->name);
}

void AddStudent()
{
    struct SStudent* newPtr = malloc(sizeof(struct SStudent));
    struct SStudent* pCurrrent = pFirstStudent;

    fill_record( &(newPtr->data) );
    newPtr->pNext = NULL;

    if(pFirstStudent == NULL)
    {
        pFirstStudent = newPtr;
    }
    else
    {
        while(pCurrrent->pNext != NULL)
        {
            pCurrrent = pCurrrent->pNext;
        }
        pCurrrent->pNext = newPtr;
    }
}

int DeleteStudent()
{
    int id;
    struct SStudent* pCurrrent = pFirstStudent;
    struct SStudent* pPrev = NULL;

    printf("Enter id to delete: ");
    scanf("%d",&id);


    if(pFirstStudent == NULL)
    {
        return 0;
    }
    else if(pFirstStudent->data.id == id)
    {
        pFirstStudent = pFirstStudent->pNext;
        free(pCurrrent);
        return 1;
    }
    else
    {
        while(pCurrrent->data.id != id && pCurrrent->pNext!=NULL)
        {
            pPrev = pCurrrent;
            pCurrrent = pCurrrent->pNext;
        }

        if(pCurrrent->data.id == id)
        {
            pPrev->pNext = pCurrrent->pNext;
            free(pCurrrent);
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

void DisplayAll()
{
    struct SStudent* pCurrrent = pFirstStudent;

    if(pFirstStudent ==NULL)
    {
        printf("Empty List\n");

    }
    else
    {
        while(pCurrrent != NULL)
        {
            display_record(&(pCurrrent->data));
            pCurrrent = pCurrrent->pNext;
        }
    }
}

void DeleteAll()
{
    struct SStudent* pCurrrent = pFirstStudent;
    struct SStudent* pLast = NULL;


    while(pCurrrent != NULL)
    {
        pLast = pCurrrent;
        pCurrrent = pCurrrent->pNext;
        free(pLast);
    }

    pFirstStudent = NULL;
}



void Reverse()
{

    if(pFirstStudent ==NULL)return;
    if(pFirstStudent->pNext ==NULL)return;

    struct SStudent* pPrev = NULL;
    struct SStudent* pCur = pFirstStudent;
    struct SStudent* pNext = pFirstStudent->pNext;

    while(pCur != NULL)
    {
        pNext = pCur->pNext;

        pCur->pNext = pPrev;
        pPrev = pCur;
        pCur = pNext;
    }

    pFirstStudent = pPrev;

}

void GetNthNode()
{
    int n,i;

    struct SStudent* pMain = pFirstStudent;
    struct SStudent* pRef = pFirstStudent;


    if(pFirstStudent ==NULL)
    {
        printf("Empty List\n");
        return;
    }

    printf("Enter n from End (0,1,2,3,...,size): ");
    scanf("%d",&n);



    for(i=0; i<n; i++)
    {
        if(pRef ->pNext != NULL) pRef = pRef->pNext;
        else
        {
            printf("Not Found\n");
            return;
        }
    }

    while(pRef->pNext!=NULL)
    {
        pRef = pRef->pNext;
        pMain = pMain->pNext;
    }

    display_record(&(pMain->data));
}


void GetMiddle()
{
    struct SStudent* pSlow = pFirstStudent;
    struct SStudent* pFast = pFirstStudent;


    if(pFirstStudent ==NULL)
    {
        printf("Empty List\n");
    }
    else
    {
        while(pFast->pNext !=NULL)
        {
            if(pSlow->pNext != NULL) pSlow = pSlow->pNext;

            if(pFast->pNext != NULL) pFast = pFast->pNext;
            if(pFast->pNext != NULL) pFast = pFast->pNext;
        }

        display_record(&(pSlow->data));

    }
}
void GetLengthIterate()
{

    struct SStudent* pCurrrent = pFirstStudent;
    int length =0;

    while(pCurrrent != NULL)
    {
        pCurrrent = pCurrrent->pNext;
        length++;
    }
    printf("Length: %d\n",length);
}
static int _lengthRecursion(struct SStudent* pCurrrent)
{
    if(pCurrrent == NULL) return 0;
    else return 1 + _lengthRecursion(pCurrrent->pNext);

}
void GetLengthRecursive()
{
    int length = _lengthRecursion(pFirstStudent);
    printf("Length: %d\n",length);

}
