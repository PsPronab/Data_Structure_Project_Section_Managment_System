#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#define ENTER 13
#define TAB 9
#define BKSP 8
#define SPACE 32
struct node
{

    char name[20];
    char id[20];
    char addr[100];
    char phn[11];
    float cgpa;

    struct node *link;
};
typedef struct node N;
N *Start, *ptr, *temp, *current,*mid1,*mid2,*mid3,*tail;

void info();
void Scarch_id();
void Amount();
void pass();
void add();
void remv();
void add_first();
void add_in_any();
void add_at_last();
void del_front();
void del_end();
void del_any();
void list_show();

int main()
{
    system ("COLOR 0b");
    system ("title ******************************************************Fuad_and_Pronab's__Project*********************************************");


    int c,cout=1;
    Start =(N *) malloc(sizeof(N));
    mid1 =(N *) malloc(sizeof(N));
    mid2 =(N *) malloc(sizeof(N));
    mid3 =(N *) malloc(sizeof(N));
    tail =(N *) malloc(sizeof(N));

    strcpy(Start->name, "Pronab Biswas");
    strcpy(Start->id, "171-15-1396");
    strcpy(Start->addr, "Diu Boy's Hostel,Room No:607");
    strcpy(Start->phn, "01754444410");
    Start->cgpa = 3.98;
    Start->link = mid1;

    strcpy(mid1->name, "Fuad");
    strcpy(mid1->id, "171-15-1402");
    strcpy(mid1->addr, "Uttara.");
    strcpy(mid1->phn, "01799894545");
    mid1->cgpa = 3.89;
    mid1->link = mid2;

    strcpy(mid2->name, "Nahid Hassan Lipu");
    strcpy(mid2->id, "171-15-1430");
    strcpy(mid2->addr, "Saver");
    strcpy(mid2->phn, "01624661654");
    mid2->cgpa = 3.99;
    mid2->link = mid3;

    strcpy(mid3->name, "Mou");
    strcpy(mid3->id, "171-15-1181");
    strcpy(mid3->addr, "Ashulia");
    strcpy(mid3->phn, "01784111837");
    mid3->cgpa = 3.56;
    mid3->link = tail;

    strcpy(tail->name, "Sonet ");
    strcpy(tail->id, "171-15-1182");
    strcpy(tail->addr, "Diu Boy's Hostel,Room No:509");
    strcpy(tail->phn, "01754444410");
    tail->cgpa = 3.98;
    tail->link = NULL;



    printf("\t\t\t\t\t\t\t\tDAFFODIL INTERNATIONAL UNIVERSITY\n");
    printf("\t\t\t\t\t\t\t\t\t  Permant Champus\n\n\n");
    printf("\t\t\t\t\t\t\t      <<<<<<Welcome to PC-(F) Section>>>>>>\n");
    printf("\t\t\t\t\t\t\t\t\t  Dept. of CSE\n");
    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------\n");


    while(cout==1)
    {
        printf("\n[*]To See The Information About PC-(F) Section Students:\n\n");
        printf("  Press->[1]-If you are Admin User.\n");
        printf("  Press->[2]-If you are Public User.\n\n");
        printf("  Enter your choice: ");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            pass();
            break;
        case 2:
            info();
            break;
        }
    }

}

void pass()
{
    char pass[20];
    int charposition=0;
    char ch;
    char loginpass[]="123456";
    printf("\n\tWelcome Admin");

PassWord:

    printf("\n===============================");
    printf("\nPlese Enter your Password\n->>>:  ");

    while(1)
    {
        ch = getch();
        if(ch == ENTER)
        {
            break;
        }
        else if(ch == BKSP)
        {
            if (charposition > 0)
            {
                charposition --;
                pass[charposition] = '\0';
                printf("\b \b");
            }
        }
        else if(ch == TAB || ch == SPACE)
        {
            continue;
        }
        else
        {

            pass[charposition]= ch;
            charposition++;
            printf("*");
        }
    }
    pass[charposition]='\0';
    printf("\n");
    if(strlen(pass)==0)
    {
        printf("No PassWord Entered>>>>>>>>>>>>>>>\n");
        goto PassWord;
    }
    else if(strlen(pass)!=0)
    {
        if(strcmp(loginpass,pass)==0)
        {
            printf("\nLogin Success (^-^)-->\n-----------------------------\n");
            int b,cut=1;
            while(cut==1)
            {
                printf("\n");
                printf("[1].Student Information.\n");
                printf("[2].Student Add.\n");
                printf("[3].Student Remove.\n");
                printf("Enter your choice: ");
                scanf("%d",&b);
                switch(b)
                {
                case 1:
                    info();
                    break;
                case 2:
                    add();
                    break;
                case 3:
                    remv();
                    break;

                }
                printf("\nContinue as Admin:-press[1]");
                printf("\nLogout :-press[0]");
                printf("\npress:- ");
                scanf("%d",&cut);



                system ("cls");

                printf("\t\t\t\t\t\t\t\tDAFFODIL INTERNATIONAL UNIVERSITY\n");
                printf("\t\t\t\t\t\t\t\t\t  Permant Champus\n\n\n");
                printf("\t\t\t\t\t\t\t      <<<<<<Welcome to PC-(F) Section>>>>>>\n");
                printf("\t\t\t\t\t\t\t\t\t  Dept. of CSE\n");
                printf("-----------------------------------------------------------------------------------------------------------------------------------------------------\n");


                if(cut==0)
                {
                    printf("\n[Successfully Logout>>>]\n\n|\n|\n\nPress Enter 2 time to Continue:\n");
                    getch();
                    system ("cls");
                    printf("\t\t\t\t\t\t\t\tDAFFODIL INTERNATIONAL UNIVERSITY\n");
                    printf("\t\t\t\t\t\t\t\t\t  Permant Champus\n\n\n");
                    printf("\t\t\t\t\t\t\t      <<<<<<Welcome to PC-(F) Section>>>>>>\n");
                    printf("\t\t\t\t\t\t\t\t\t  Dept. of CSE\n");
                    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------\n");


                }

            }
        }
        else
        {
            printf("-----------------");
            printf("\n|Wrong PassWord.|\n|\t\t|\n|\t\t|\nAccess Denied   |\n|x(-_-)x\t|\n|\t\t|\n|\t\t|\n-----------------");
            goto PassWord;
        }

    }
    getch();
}
void info()
{

    int b,cut=1;
    while(cut==1)
    {
        printf("\n");
        printf("[1].See Full List\n");
        printf("[2].Scarch specific student info.\n");
        printf("[3].Amount of students.\n");

        printf("Enter your choice: ");
        scanf("%d",&b);
        switch(b)
        {
        case 1:
            list_show();
            break;
        case 2:
            Scarch_id();
            break;
        case 3:
            Amount();
            break;
        }
        printf("\n\nDo You Need More Info. of Student??\nYes[1] Or No[0]: ");
        scanf("%d",&cut);
    }
    system ("cls");

    printf("\t\t\t\t\t\t\t\t\tDAFFODIL INTERNATIONAL UNIVERSITY\n");
    printf("\t\t\t\t\t\t\t\t\t\t  Permant Champus\n\n\n");
    printf("\t\t\t\t\t\t\t\t      <<<<<<Welcome to PC-(F) Section>>>>>>\n");
    printf("\t\t\t\t\t\t\t\t\t\t  Dept. of CSE\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

}

void add()
{
    int b,cut=1;
    while(cut==1)
    {
        printf("\n");
        printf("[1].Fast add\n");
        printf("[2].Any add\n");
        printf("[3].Last add\n");
        printf("Enter your choice: ");
        scanf("%d",&b);

        getchar();

        switch(b)
        {
        case 1:
            add_first();
            break;
        case 2:
            add_in_any();
            break;
        case 3:
            add_at_last();
            break;
        }
        printf("\nDo You Continue Add The Student??\nYes[1] Or No[0]: ");
        scanf("%d",&cut);
    }
    system ("cls");
    printf("\t\t\t\t\t\t\t\t\tDAFFODIL INTERNATIONAL UNIVERSITY\n");
    printf("\t\t\t\t\t\t\t\t\t\t  Permant Champus\n\n\n");
    printf("\t\t\t\t\t\t\t\t      <<<<<<Welcome to PC-(F) Section>>>>>>\n");
    printf("\t\t\t\t\t\t\t\t\t\t  Dept. of CSE\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}

void remv()
{
    int b,cut=1;
    while(cut==1)
    {
        printf("\n");
        printf("[1].Fast remove\n");
        printf("[2].Any remove\n");
        printf("[3].Last remove\n");
        printf("Enter your choice: ");
        scanf("%d",&b);

        getchar();

        switch(b)
        {
        case 1:
            del_front();
            break;
        case 2:
            del_any();
            break;
        case 3:
            del_end();
            break;

        }
        printf("\nDo You  want to Continue for remove Student information??\nYes[1] Or No[0]: ");
        scanf("%d",&cut);
    }
    system ("cls");
    printf("\t\t\t\t\t\t\t\t\tDAFFODIL INTERNATIONAL UNIVERSITY\n");
    printf("\t\t\t\t\t\t\t\t\t\t  Permant Champus\n\n\n");
    printf("\t\t\t\t\t\t\t\t      <<<<<<Welcome to PC-(F) Section>>>>>>\n");
    printf("\t\t\t\t\t\t\t\t\t\t  Dept. of CSE\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

}

void Amount()
{
    if(Start!=NULL)
    {
        int count=1;

        N *head, *current;

        current=Start;
        while(current->link != NULL)
        {
            current = current->link;
            count++;
        }
        printf("\nThe amount of Student(s) in this section is/are:- ");
        printf("%d\n",count);
    }
    else
    {
        printf("\nOhhoooo(>_<)---The list is empty.\n");
    }
}

void Scarch_id()
{
    N *current;
    char fid[20];
    int a=0,s=1;


    if(Start!=NULL)
    {
        while(s==1)
        {
            printf("\nWhich Id info You Want:");
            scanf("%s",&fid);
            current=Start;
            while(current->link !=NULL)
            {

                if(strcmp(current->id, fid)==0)
                {
                    printf("\n===========================");
                    printf("\nName: ");
                    printf("%s ", current->name);
                    printf("\nId: ");
                    printf("%s ", current->id);
                    printf("\nAddress: ");
                    printf("%s ", current->addr);
                    printf("\nPhone Number: ");
                    printf("%s ", current->phn);
                    printf("\nCGPA: ");
                    printf("%.2f ", current->cgpa);
                    printf("\n===========================");
                    a++;
                }
                current=current->link;

            }

            if (a==0)
            {
                printf("\nThis Id Not Found\n");
                printf("Do You continue Surch??Yes[1] or No[0]");
                scanf("%d",&s);
            }
            else
            {
                break;
            }
        }
    }
    else
    {
        printf("\nOhhoooo(>_<)---The list is empty.\n");

    }


}


void add_first()
{
    char fname[20];
    char fid[20];
    char faddr[100];
    char fphn[11];
    float fcgpa;

    printf("\nEnter Name:");
    gets(fname);
    printf("Enter Id:");
    gets(fid);
    printf("Enter Address:");
    gets(faddr);
    printf("Enter Phone Number:");
    gets(fphn);
    printf("Enter CGPA:");
    scanf("%f",&fcgpa);


    temp = (N *) malloc(sizeof(N));


    strcpy(temp->name, fname);
    strcpy(temp->id, fid);
    strcpy(temp->addr, faddr);
    strcpy(temp->phn,  fphn);
    temp-> cgpa= fcgpa;
    temp->link = Start;
    Start = temp;
    printf("\nFile Successfully added at the Top.  (^_^)Y\n");

}

void add_in_any()
{

    char fname[20];
    char fid[20];
    char faddr[100];
    char fphn[11];
    float fcgpa;

    int posstiton,coun;
up:
    coun=1;
    printf("\nNow enter the  The Possition you want to enter The New Data: ");
    scanf("%d", &posstiton);

    N *prev,*current,*temp;
    temp = (N*) malloc(sizeof(N));

    current = Start;
    while(current->link != NULL &&  coun<posstiton )
    {
        prev = current;
        current = current->link;
        coun++;
    }
    if(coun == posstiton )
    {
        printf("\nEnter Name:");
        scanf("%s",&fname);
        printf("Enter Id:");
        scanf("%s",&fid);
        printf("Enter Address:");
        scanf("%s",&faddr);
        printf("Enter Phone Number:");
        scanf("%s",&fphn);
        printf("Enter CGPA:");
        scanf("%f",&fcgpa);

        strcpy(temp->name, fname);
        strcpy(temp->id, fid);
        strcpy(temp->addr, faddr);
        strcpy(temp->phn,  fphn);
        temp-> cgpa= fcgpa;
        temp->link = current;
        prev->link = temp;
        printf("\nFile Successfully added as your Given position .  (^_^)Y\n");

    }

    else if(coun != posstiton)
    {
        printf("\nPosstiton %d is not exist in the list is beeing created. \n",posstiton);
        printf("\nTry again and give the exist possition:\n------------------------------------------------------------");
        goto up;
    }
}

void add_at_last()
{
    char fname[20];
    char fid[20];
    char faddr[100];
    char fphn[11];
    float fcgpa;

    printf("\nEnter Name:");
    gets(fname);
    printf("Enter Id:");
    gets(fid);
    printf("Enter Address:");
    gets(faddr);
    printf("Enter Phone Number:");
    gets(fphn);
    printf("Enter CGPA:");
    scanf("%f",&fcgpa);

    temp = (N *) malloc(sizeof(N));
    ptr = Start;

    while(ptr->link != NULL)
    {
        ptr = ptr->link;
    }


    strcpy(temp->name, fname);
    strcpy(temp->id, fid);
    strcpy(temp->addr, faddr);
    strcpy(temp->phn,  fphn);
    temp-> cgpa= fcgpa;
    temp->link = ptr->link;
    ptr->link = temp;
    printf("\nFile Successfully added at the Bottom.  (^_^)Y\n");
}

void del_front()
{
    if(Start!=NULL)
    {
        current = Start;
        Start = Start->link ;
        free (current);
        printf("\nFirst File Successfully Removed.(^_^)Y\n");
    }

    else
    {
        printf("\nOhhoooo  (>_<)  ---The list is empty.\n");
    }

}

void del_any()
{
    char fid[20];

    if(Start!=NULL)
    {
        N *prev, *current;
        current = Start;
        printf("\nEnter the ID of the student you want to Remove: ");
        scanf("%s",&fid);
        int a=0;
        if(strcmp(Start->id, fid)==0)
        {
            current = Start;
            Start = Start->link ;
            free (current);
            printf("\nThis File Successfully Removed.  (^_^)Y\n");

        }


        else
        {
            current = Start ;

            while (current->link != NULL )
            {
                if(strcmp(current->id, fid)==0 && current->link !=NULL)
                {
                    prev->link = current->link ;
                    free (current);
                    printf("\nThis File Successfully Removed.  (^_^)Y\n");
                    a=1;
                    break;

                }

                prev = current;
                current = current->link;

            }
            if(strcmp(current->id, fid)==0 && current->link ==NULL)
            {

                prev->link = NULL;
                free (current);
                printf("\nThis File Successfully Removed.  (^_^)Y\n");
                a=1;
            }


            else if(a==0)
            {
                printf("Given ID %s is not Match.",fid);
            }
        }

    }
    else
    {
        printf("\nOhhoooo  (>_<)  ---The list is empty.\n");
    }
}

void del_end()
{
    N *prev, *current;

    if(Start!=NULL)
    {
        current = Start;

        while(current->link != NULL)
        {
            prev = current;
            current = current->link;
        }
        prev->link = NULL;
        free (current);
        printf("\nLast File Successfully Removed.  (^_^)Y\n");
    }
    else
    {
        printf("\nOhhoooo  (>_<)  ---The list is empty.\n");
    }


}
void list_show()
{

    if(Start!=NULL)
    {
        int cou=1;
        printf("\n\t\t\t\t\t\tNow Showing the List of the Students of Section PC-F:\n                  -------------------------------------------------------------------------------------------------------------------\n");
        printf("\n=======================================================================================================================================================================\n");

        ptr = Start;

        printf("[%d]", cou);
        printf("\nName: ");
        printf("%s ", ptr->name);
        printf("\nId: ");
        printf("%s ", ptr->id);
        printf("\nAddress: ");
        printf("%s ", ptr->addr);
        printf("\nPhone Number: ");
        printf("%s ", ptr->phn);
        printf("\nCGPA: ");
        printf("%.2f ", ptr->cgpa);
        printf("\n=======================================================================================================================================================================");
        while(ptr->link != NULL)
        {
            cou++;
            printf("\n");
            printf("[%d]", cou);
            ptr = ptr->link;
            printf("\nName: ");
            printf("%s ", ptr->name);
            printf("\nId: ");
            printf("%s ", ptr->id);
            printf("\nAddress: ");
            printf("%s ", ptr->addr);
            printf("\nPhone Number: ");
            printf("%s ", ptr->phn);
            printf("\nCGPA: ");
            printf("%.2f ", ptr->cgpa);
            printf("\n=======================================================================================================================================================================");

        }
    }
    else
    {
        printf("\nOhhoooo(>_<)---The list is empty.\n");
    }

}
