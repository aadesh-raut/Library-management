#include<stdio.h>
#include<string.h>
#include<ctype.h>

//dummy file name
char filename[100];

// library counter
int libs = 0;

void welcome();
void reg_page();
void log_page();

// Take Credentials

void take_libname();
void take_adname();
void take_email();
void take_pass();

// file credentials

char line[200];


//
char choice;
char lib_name[200];
char admin_name[200];
char admin_email[200];
char password[200];
char input_email[200];
char input_pass[200];

//

FILE *libraries;

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
    printf("Enter the \n1. Library name\n2. Admin Name\n3. Admin Email Id\n4. Password( More then 8 characters)\n");
    take_libname();
    take_adname();
    take_email();

    printf("Registration Successfull !!!!!!!! :)\nLoging Once again and you are good to go :)\n");

    snprintf(filename,100,"Library_%d_books.txt",libs);

    FILE *lib_books = fopen(filename,"a+");

    snprintf(filename,100,"Library_%d_users.txt",libs);

    FILE *lib_users = fopen(filename,"a+");

    snprintf(filename,100,"Library_%d_transactions.txt",libs);

    FILE *lib_transactions = fopen(filename,"a+");

    libs++;

    welcome();
}

void log_page()
{
    printf("==================================================\n");
    printf("Welcome to Login page\n");
    printf("==================================================\n");

    printf("Enter the Email ID of Admin: \n");
    fgets(input_email,100,stdin);
    input_email[strcspn(input_email,"\n")] = '\0';
    printf("Enter the Password: \n");
    fgets(input_pass,100,stdin);
    input_pass[strcspn(input_pass,"\n")] = '\0';

    int flag_email = 1;
    int flag_pass = 1;

    sprintf(admin_email,"Admin Email: %s",input_email);
    sprintf(password,"Password: %s",input_pass);

    libraries = fopen("libraries.txt","r");

    while(fgets(line,200,libraries) != NULL)
    {
        line[strcspn(line,"\n")] = '\0';
        if(strcmp(line,admin_email) == 0){
            flag_email = 0;
        }
        if(strcmp(line,password) == 0){
            flag_pass = 0;
        }
    }
    if(flag_email != 0){
        printf("Incorrect Email ID !!!!!!");
    }
    else if (flag_email == 0 && flag_pass != 0)
    {
        printf("Incorrect Password !!!!!");
    }
    else{
        printf("Login Successfull!!!!");
    }
    
}

void take_libname()
{
    printf("Name of Library: ");
    fgets(lib_name,100,stdin);
    lib_name[strcspn(lib_name,"\n")] = '\0';


    libraries = fopen("libraries.txt","a+");

    fprintf(libraries,"==================================================\n");

    fprintf(libraries,"==================================================\n");

    fprintf(libraries,"Library Name: %s\n",lib_name);

    fclose(libraries);

    // snprintf(filename,100,"%s.txt",lib_name);

    // FILE *newlib = fopen(filename,"a");
}

void take_adname()
{
    printf("Admin Name: ");
    fgets(admin_name,100,stdin);
    admin_name[strcspn(admin_name,"\n")] = '\0';

    libraries = fopen("libraries.txt","a+");

    fprintf(libraries,"Admin Name: %s\n",admin_name);

    fclose(libraries);
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

        libraries = fopen("libraries.txt","a+");

        fprintf(libraries,"Admin Email: %s\n",admin_email);

        fclose(libraries);

        printf("Email id checked!!!!\n");
        take_pass();
    }
    else{
        printf("Email id is invalid \n Please enter the email id again!!!!!\n");
        take_email();
    }
}

void take_pass()
{
    printf("Password: ");
    fgets(password,100,stdin);
    int u = 0,l = 0,s = 0,sp = 0;
    password[strcspn(password,"\n")] = '\0';
    int len = strlen(password);

    for(int i=0;i<len;i++)
    {
        if(isupper(password[i])){
            u++;
        }
        else if(islower(password[i])){
            l++;
        }
        else if(password[i]==' '){
            sp++;
        }
        else{
            s++;
        }
    }

    if(u<1){
        printf("1. Password should be more than 8 characters\n2. Password should contain atleast 1 Uppercase\n3. Password should contain atleast 1 Lowercase\n4. Password should contain atleaset 1 special character\n5. Password should not contain spaces\n");
        printf("PLease enter the password again :)\n");
        take_pass();
    }
    else if (l<1)
    {
        printf("1. Password should be more than 8 characters\n2. Password should contain atleast 1 Uppercase\n3. Password should contain atleast 1 Lowercase\n4. Password should contain atleaset 1 special character\n5. Password should not contain spaces\n");
        printf("Please enter the password again :)\n");
        take_pass();
    }
    else if (s<1)
    {
        printf("1. Password should be more than 8 characters\n2. Password should contain atleast 1 Uppercase\n3. Password should contain atleast 1 Lowercase\n4. Password should contain atleaset 1 special character\n5. Password should not contain spaces\n");
        printf("Please enter the password again :)\n");
        take_pass();
    }
    else if (sp!=0){
        printf("1. Password should be more than 8 characters\n2. Password should contain atleast 1 Uppercase\n3. Password should contain atleast 1 Lowercase\n4. Password should contain atleaset 1 special character\n5. Password should not contain spaces\n");
        printf("Please enter the password again :)\n");
        take_pass();
    }
    else if (len<8)
    {
        printf("1. Password should be more than 8 characters\n2. Password should contain atleast 1 Uppercase\n3. Password should contain atleast 1 Lowercase\n4. Password should contain atleaset 1 special character\n5. Password should not contain spaces\n");
        printf("Please enter the password again :)\n");
        take_pass();
    }
    else{

        libraries = fopen("libraries.txt","a+");

        fprintf(libraries,"Password: %s\n",password);

        fprintf(libraries,"Library ID: %d\n",libs);

        fprintf(libraries,"==================================================\n");

        fprintf(libraries,"==================================================\n");

        fprintf(libraries,"\n\n");

        fclose(libraries);

        printf("Password Accepted !!!!!!\n");
    }
}