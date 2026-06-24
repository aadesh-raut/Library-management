#include<stdio.h>
#include<string.h>

void welcome();
void reg_page();
void log_page();

// Take Credentials

void take_libname();
void take_adname();
void take_email();
void take_pass();

char choice;
char lib_name[100];
char admin_name[100];
char admin_email[100];
char password[100];

int main()
{
    welcome();
}

void welcome()
{
    int flag = 1 ;
    printf("Welcome to Library Management System !!!!!\n");
    printf("\n");
    printf("\n");
    printf("\n");

    printf("1. Register the Library\n");
    printf("2. Login\n");
    printf("3. Exit\n");

    while(flag==1){
        printf("Enter the choice: ");
        scanf(" %c",&choice);

        while(getchar() != '\n');

        if(choice=='1')
        {
            reg_page();
            break;
        }
        else if (choice=='2')
        {
            log_page();
            break;
        }
        else if (choice=='3')
        {
            printf("Thank You for visiting!!!!\n Please do visit again!!!!\n");
            welcome();
            break;
        }
        else{
            printf("Please enter the valid input !!!!\n");
        }
    }
}

void reg_page()
{
    printf("Welcome to Registration Page\n");
    printf("\n");
    printf("\n");
    printf("Enter the \n1. Library name\n2. Admin Name(______@gmail.com)\n3. Admin Email Id\n4. Password( More then 8 characters)\n");
    take_libname();
    take_adname();
    take_email();
}

void log_page()
{
    printf("Welcome to Login page\n");

}

void take_libname()
{
    printf("Name of Library: ");
    fgets(lib_name,100,stdin);
}

void take_adname()
{
    printf("Admin Name: ");
    fgets(admin_name,100,stdin);
}

void take_email()
{
    int k=0,j=0;
    int atindex;
    int dotindex;
    int flag = 1;
    char def_email[100] = "@gmail.com";
    printf("Admin email: ");
    fgets(admin_email,100,stdin);
    admin_email[strcspn(admin_email,"\n")]='\0';

    int len = strlen(admin_email);
    
    for(int i=0;admin_email[i]!='\0';i++)
    {
        if(admin_email[i]=='@')
        {
            k++;
            atindex=i;
        }
        if(admin_email[i]=='.')
        {
            j++;
            dotindex = i;
        }
    }
    if(k!=1 || atindex==0 || j<1 || dotindex<atindex || dotindex == atindex+1 || dotindex == len -1){
        flag = 0;
    }

    if(flag==1){
        take_pass();
    }
    else{
        printf("Email id is invalid \n Please enter the email id again!!!!!\n");
        take_email();
    }
}

void take_pass()
{
    printf("Email id checked \nPlease enter the password ");
}