#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
int i=0,j=0,k=0,l=0,m=0;

struct stu
{
    int roll, year;
    char branch[10],event[10];
    char f_name[10], l_name[10];
};

struct new
{
    int cnt;
};

FILE *ptr;

void note(struct stu a);
void reg();
void show();
void year(struct stu a);
void trait(struct stu b);
void eventing(struct stu c);
void reg_no();
void count();

int main()
{
    int choice;
    while(1)
	{
        system("cls");
        printf("##### Welcome To My Program #####\n\n");
        printf("*** Enter Student Details ***\n");
        printf("1. Enter student data\n");
        printf("2. Display Student data\n");
        printf("3. End Program\n");
        printf("# Enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
		{
            case 1:
                reg();
                break;
            case 2:
                show();
                break; 
            case 3:
                printf("\n\n\t\t### Thank You For using This Program ###\n\n");
                printf("\t\t This Program is Made by \n");
                printf("\t\t1. Ayush Verma(2001430100073)\n");
                printf("\t\t2. Gungun Gupta(2001430100092)\n");
                printf("\t\t3. mehak sangal(2001430100127)\n");
                printf("\t\t4. Chehak Rajput(2001430100077)\n");

                exit(0);
        }
    }
    return 0;
}

void reg()
{
    int q;
    struct stu s;
    system("cls");
    printf("<----: Enter %d Student Detail :---->\n",i+1);
    printf("Enter Student First Name : ");
    fflush(stdin);
    scanf("%s",&s.f_name);
    printf("Enter Student Last Name : ");
    fflush(stdin);
    scanf("%s",&s.l_name);
    printf("Enter student's branch-->(Write in Word)\n(1.cse || 2.cs || 3.it || 4.biotech || 5.mech || 6.ec || 7.mba ): ");
    fflush(stdin);
    scanf("%s",&s.branch);
    printf("Enter Student's Year (1-4) : ");
    scanf("%d",&s.year);
    printf("Enter Student's Roll Number (Last 3 Digits) : ");
    scanf("%d",&s.roll);
    printf("Enter event's name in which you want to participate-->(Write in Word)\n( 1.dancing || 2.singing || 3.poetry || 4.anchoring ): ");
    fflush(stdin);
    scanf("%s",&s.event);
    i++;
    year(s);
    trait(s);
    eventing(s);
    count();
}

void year(struct stu a)
{
    if(a.year == 1)
	{
        ptr = fopen("data_1.txt","a+");
    }
    else if(a.year == 2)
	{
        ptr = fopen("data_2.txt","a+");
    }
    else if(a.year == 3)
	{
        ptr = fopen("data_3.txt","a+");
    }
    else
    {
        ptr = fopen("data_4.txt","a+");
    }
    fprintf(ptr,"%s %s\t%s\t%d\t%d\t%s\n",a.f_name,a.l_name,a.branch,a.year,a.roll,a.event);
    fclose(ptr);
}

void trait(struct stu b)
{
    if((strcmp("cse",b.branch) == 0))
    {
        ptr = fopen("branch_1.txt","a+");
    }
    else if((strcmp("cs",b.branch) == 0))
    {
        ptr = fopen("branch_2.txt","a+");
    }
    else if((strcmp("it",b.branch) == 0))
    {
        ptr = fopen("branch_3.txt","a+");
    }
    else if((strcmp("biotech",b.branch) == 0))
    {
        ptr = fopen("branch_4.txt","a+");
    }
    else if((strcmp("mech",b.branch) == 0))
    {
        ptr = fopen("branch_5.txt","a+");
    }
    else if((strcmp("ec",b.branch) == 0))
    {
        ptr = fopen("branch_6.txt","a+");
    }
    else
    {
        ptr = fopen("branch_7.txt","a+");
    }
    fprintf(ptr,"%s %s\t%s\t%d\t%d\t%s\n",b.f_name,b.l_name,b.branch,b.year,b.roll,b.event);
    fclose(ptr);
}

void eventing(struct stu c)
{
    if((strcmp("dancing",c.event) == 0))
    {
        ptr = fopen("event_1.txt","a+");
    }
    else if((strcmp("singing",c.event) == 0))
    {
        ptr = fopen("event_2.txt","a+");
    }
    else if((strcmp("anchoring",c.event) == 0))
    {
        ptr = fopen("event_3.txt","a+");
    }
    else
    {
        ptr = fopen("event_4.txt","a+");
    }
    fprintf(ptr,"%s %s\t%s\t%d\t%d\t%s\n",c.f_name,c.l_name,c.branch,c.year,c.roll,c.event);
    fclose(ptr);
}

void count()
{
    struct new n;
    ptr = fopen("count.txt","w");
    n.cnt=m+1;
    fprintf(ptr,"%d",n.cnt);
    m++;
    fclose(ptr);
}

void reg_no()
{
    struct new n;
    ptr = fopen("count.txt","r");
    if(ptr == NULL)
    {
        printf("data not found");
        getch();
    }
    else
    {
        fscanf(ptr,"%d",&n.cnt);
        printf("NO  OF REGISTRATION ARE : %d",n.cnt);
        getch();
        fclose(ptr);
    }
    
}


void show()
{
    int tip,ch;
    struct stu sh;
    system("cls");
    while(1)
    {
        system("cls");
        printf("1. get student detail by Year :\n");
        printf("2. get student detail by branch :\n");
        printf("3. get student detail by event: \n");
        printf("4. exit\n");
        printf("enter choice :--->");
        scanf("%d",&ch);
        if(ch==1)
        {
            system("cls");
            printf("which Year student you want to search : ");
            scanf("%d",&tip);
            if(tip == 1)
			{
                ptr = fopen("data_1.txt","r");
                if( ptr == NULL)
                {
                    printf("####### DATA NOT FOUND ######");
                    getch();
                }
                else
                {
                    printf("NAME \t\t\tBRANCH\t\tYEAR\t\tROLL_NO\t\tEVENT \n");
                    while(fscanf(ptr,"%s%s%s%d%d%s",sh.f_name,sh.l_name,sh.branch,&sh.year,&sh.roll,sh.event) !=EOF)
                    {
                    printf("%s %s\t\t%s\t\t%d\t\t%d\t\t%s\n",sh.f_name,sh.l_name,sh.branch,sh.year,sh.roll,sh.event);
                    }
                    getch();
                }
            }   
            else if(tip == 2)
			{
                ptr = fopen("data_2.txt","r");
                if( ptr == NULL)
                {
                    printf("####### DATA NOT FOUND ######");
                    getch();
                }
                else
                {
                    printf("NAME \t\t\tBRANCH\t\tYEAR\t\tROLL_NO\t\tEVENT \n");
                    while(fscanf(ptr,"%s%s%s%d%d%s",sh.f_name,sh.l_name,sh.branch,&sh.year,&sh.roll,sh.event) !=EOF)
                    {
                    printf("%s %s\t\t%s\t\t%d\t\t%d\t\t%s\n",sh.f_name,sh.l_name,sh.branch,sh.year,sh.roll,sh.event);
                    }
                    getch();
                }
            }
            else if(tip == 3)
			{
                ptr = fopen("data_3.txt","r");
                if( ptr == NULL)
                {
                    printf("####### DATA NOT FOUND ######");
                    getch();
                }
                else
                {
                    printf("NAME \t\t\tBRANCH\t\tYEAR\t\tROLL_NO\t\tEVENT \n");
                    while(fscanf(ptr,"%s%s%s%d%d%s",sh.f_name,sh.l_name,sh.branch,&sh.year,&sh.roll,sh.event) !=EOF)
                    {
                    printf("%s %s\t\t%s\t\t%d\t\t%d\t\t%s\n",sh.f_name,sh.l_name,sh.branch,sh.year,sh.roll,sh.event);
                    }
                    getch();
                }
            }
            else if(tip == 4)
			{
                ptr = fopen("data_4.txt","r");
                if( ptr == NULL)
                {
                    printf("####### DATA NOT FOUND ######");
                    getch();
                }
                else
                {
                    printf("NAME \t\t\tBRANCH\t\tYEAR\t\tROLL_NO\t\tEVENT \n");
                    while(fscanf(ptr,"%s%s%s%d%d%s",sh.f_name,sh.l_name,sh.branch,&sh.year,&sh.roll,sh.event) !=EOF)
                    {
                    printf("%s %s\t\t%s\t\t%d\t\t%d\t\t%s\n",sh.f_name,sh.l_name,sh.branch,sh.year,sh.roll,sh.event);
                    }
                    getch();
                }
            }
            else
            {
                printf("### INVALID YEAR ###\n");
                getch();
                show();
            }
        }
        else if(ch==2)
        {
            system("cls");
            char p[20];
			printf("1.cse\n2.cs\n3.it\n4.biotech\n5.mech\n6.ec\n7.mba\nwhich branch's student you want to search(1-7): ");
    		fflush(stdin);
    		gets(p);
    		if((strcmp(p,"1")==0))
            {
                ptr = fopen("branch_1.txt","r");
                if( ptr == NULL)
                {
                    printf("####### DATA NOT FOUND ######");
                    getch();
                }
                else
                {
                    printf("NAME \t\t\tBRANCH\t\tYEAR\t\tROLL_NO\t\tEVENT \n");
                    while(fscanf(ptr,"%s%s%s%d%d%s",sh.f_name,sh.l_name,sh.branch,&sh.year,&sh.roll,sh.event) !=EOF)
                    {
                    printf("%s %s\t\t%s\t\t%d\t\t%d\t\t%s\n",sh.f_name,sh.l_name,sh.branch,sh.year,sh.roll,sh.event);
                    }
                    getch();
                }
            }
            else if((strcmp(p,"2")==0))
            {
                ptr = fopen("branch_2.txt","r");
                if( ptr == NULL)
                {
                    printf("####### DATA NOT FOUND ######");
                    getch();
                }
                else
                {
                    printf("NAME \t\t\tBRANCH\t\tYEAR\t\tROLL_NO\t\tEVENT \n");
                    while(fscanf(ptr,"%s%s%s%d%d%s",sh.f_name,sh.l_name,sh.branch,&sh.year,&sh.roll,sh.event) !=EOF)
                    {
                    printf("%s %s\t\t%s\t\t%d\t\t%d\t\t%s\n",sh.f_name,sh.l_name,sh.branch,sh.year,sh.roll,sh.event);
                    }
                    getch();
                }
            }
            else if((strcmp(p,"3")==0))
            {
                ptr = fopen("branch_3.txt","r");
                if( ptr == NULL)
                {
                    printf("####### DATA NOT FOUND ######");
                    getch();
                }
                else
                {
                    printf("NAME \t\t\tBRANCH\t\tYEAR\t\tROLL_NO\t\tEVENT \n");
                    while(fscanf(ptr,"%s%s%s%d%d%s",sh.f_name,sh.l_name,sh.branch,&sh.year,&sh.roll,sh.event) !=EOF)
                    {
                    printf("%s %s\t\t%s\t\t%d\t\t%d\t\t%s\n",sh.f_name,sh.l_name,sh.branch,sh.year,sh.roll,sh.event);
                    }
                    getch();
                }
            }      
            else if((strcmp(p,"4")==0))
            {
                 ptr = fopen("branch_4.txt","r");
                 if( ptr == NULL)
                {
                    printf("####### DATA NOT FOUND ######");
                    getch();
                }
                else
                {
                    printf("NAME \t\t\tBRANCH\t\tYEAR\t\tROLL_NO\t\tEVENT \n");
                    while(fscanf(ptr,"%s%s%s%d%d%s",sh.f_name,sh.l_name,sh.branch,&sh.year,&sh.roll,sh.event) !=EOF)
                    {
                    printf("%s %s\t\t%s\t\t%d\t\t%d\t\t%s\n",sh.f_name,sh.l_name,sh.branch,sh.year,sh.roll,sh.event);
                    }
                    getch();
                }
            }
            else if((strcmp(p,"5")==0))
            {
                 ptr = fopen("branch_5.txt","r");
                 if( ptr == NULL)
                {
                    printf("####### DATA NOT FOUND ######");
                    getch();
                }
                else
                {
                    printf("NAME \t\t\tBRANCH\t\tYEAR\t\tROLL_NO\t\tEVENT \n");
                    while(fscanf(ptr,"%s%s%s%d%d%s",sh.f_name,sh.l_name,sh.branch,&sh.year,&sh.roll,sh.event) !=EOF)
                    {
                    printf("%s %s\t\t%s\t\t%d\t\t%d\t\t%s\n",sh.f_name,sh.l_name,sh.branch,sh.year,sh.roll,sh.event);
                    }
                    getch();
                }
            }
            else if((strcmp(p,"6")==0))
            {
                ptr = fopen("branch_6.txt","r");
                if( ptr == NULL)
                {
                    printf("####### DATA NOT FOUND ######");
                    getch();
                }
                else
                {
                    printf("NAME \t\t\tBRANCH\t\tYEAR\t\tROLL_NO\t\tEVENT \n");
                    while(fscanf(ptr,"%s%s%s%d%d%s",sh.f_name,sh.l_name,sh.branch,&sh.year,&sh.roll,sh.event) !=EOF)
                    {
                    printf("%s %s\t\t%s\t\t%d\t\t%d\t\t%s\n",sh.f_name,sh.l_name,sh.branch,sh.year,sh.roll,sh.event);
                    }
                    getch();
                }
            }
            else if((strcmp(p,"7")==0))
            {
                ptr = fopen("branch_7.txt","r");
                if( ptr == NULL)
                {
                    printf("####### DATA NOT FOUND ######");
                    getch();
                }
                else
                {
                    printf("NAME \t\t\tBRANCH\t\tYEAR\t\tROLL_NO\t\tEVENT \n");
                    while(fscanf(ptr,"%s%s%s%d%d%s",sh.f_name,sh.l_name,sh.branch,&sh.year,&sh.roll,sh.event) !=EOF)
                    {
                    printf("%s %s\t\t%s\t\t%d\t\t%d\t\t%s\n",sh.f_name,sh.l_name,sh.branch,sh.year,sh.roll,sh.event);
                    }
                    getch();
                }
            }
            else
            {
                printf("### INVALID BRANCH ###\n");
                getch();
                show();
            } 
        }
        else if(ch==3)
        {
            system("cls");
            char z[20];
			printf("1.dancing\n2.singing\n3.anchoring\n4.poetry\nwhich event's student you want to search(1-4):                            ");
    		fflush(stdin);
    		gets(z);
    		if((strcmp(z,"1")==0))
            {
                ptr = fopen("event_1.txt","r");
                if( ptr == NULL)
                {
                    printf("####### DATA NOT FOUND ######");
                    getch();
                }
                else
                {
                    printf("NAME \t\t\tBRANCH\t\tYEAR\t\tROLL_NO\t\tEVENT \n");
                    while(fscanf(ptr,"%s%s%s%d%d%s",sh.f_name,sh.l_name,sh.branch,&sh.year,&sh.roll,sh.event) !=EOF)
                    {
                    printf("%s %s\t\t%s\t\t%d\t\t%d\t\t%s\n",sh.f_name,sh.l_name,sh.branch,sh.year,sh.roll,sh.event);
                    }
                    getch();
                }
            }
            else if((strcmp(z,"2")==0))
            {
                ptr = fopen("event_2.txt","r");
                if( ptr == NULL)
                {
                    printf("####### DATA NOT FOUND ######");
                    getch();
                }
                else
                {
                    printf("NAME \t\t\tBRANCH\t\tYEAR\t\tROLL_NO\t\tEVENT \n");
                    while(fscanf(ptr,"%s%s%s%d%d%s",sh.f_name,sh.l_name,sh.branch,&sh.year,&sh.roll,sh.event) !=EOF)
                    {
                    printf("%s %s\t\t%s\t\t%d\t\t%d\t\t%s\n",sh.f_name,sh.l_name,sh.branch,sh.year,sh.roll,sh.event);
                    }
                    getch();
                }
            }
            else if((strcmp(z,"3")==0))
            {
                ptr = fopen("event_3.txt","r");
                if( ptr == NULL)
                {
                    printf("####### DATA NOT FOUND ######");
                    getch();
                }
                else
                {
                    printf("NAME \t\t\tBRANCH\t\tYEAR\t\tROLL_NO\t\tEVENT \n");
                    while(fscanf(ptr,"%s%s%s%d%d%s",sh.f_name,sh.l_name,sh.branch,&sh.year,&sh.roll,sh.event) !=EOF)
                    {
                    printf("%s %s\t\t%s\t\t%d\t\t%d\t\t%s\n",sh.f_name,sh.l_name,sh.branch,sh.year,sh.roll,sh.event);
                    }
                    getch();
                }
            }      
            else if((strcmp(z,"4")==0))
            {
                ptr = fopen("event_4.txt","r");
                if( ptr == NULL)
                {
                    printf("####### DATA NOT FOUND ######");
                    getch();
                }
                else
                {
                    printf("NAME \t\t\tBRANCH\t\tYEAR\t\tROLL_NO\t\tEVENT \n");
                    while(fscanf(ptr,"%s%s%s%d%d%s",sh.f_name,sh.l_name,sh.branch,&sh.year,&sh.roll,sh.event) !=EOF)
                    {
                    printf("%s %s\t\t%s\t\t%d\t\t%d\t\t%s\n",sh.f_name,sh.l_name,sh.branch,sh.year,sh.roll,sh.event);
                    }
                    getch();
                }
            }
            else
            {
                printf("### INVALID EVENT ###");
                getch();
                main();
            } 
        }
        else
        {
            main();
        }  
    }
}