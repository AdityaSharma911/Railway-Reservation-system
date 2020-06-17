#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

#define DATA_SIZE 1000


//Info of trains is opened using this function
void tinfo()
{
    /* Variable to store user content */
    char data[DATA_SIZE];

    /* File pointer to hold reference to our file */
    FILE * fP;
    char ch;


    /*
     * Open file in w (write) mode.
     * "data/file1.txt" is complete path to create file
     */
    fP = fopen("data/tinfo.txt", "r");
    ch=fgetc(fP);
    while(ch!=EOF)
    {
        printf("%c",ch);
        ch=getc(fP);
    }

    /* fopen() return NULL if last operation was unsuccessful */
    if(fP == NULL)
    {
        /* File not created hence exit */
        printf("The database of the trains is currently under maintenence.\n");
        exit(EXIT_FAILURE);
    }




    /* Write data to file */



    /* Close file to save file data */
    fclose(fP);







}





//Advisory info for corona pandemic
void ainfo(void)
{
    /* Variable to store user content */
    char data[DATA_SIZE];

    /* File pointer to hold reference to our file */
    FILE * fPa;
    char ch;


    fPa = fopen("data/ainfo.txt", "r");
    ch=fgetc(fPa);
    while(ch!=EOF)
    {
        printf("%c",ch);
        ch=getc(fPa);
    }

    /* fopen() return NULL if last operation was unsuccessful */
    if(fPa == NULL)
    {
        /* File not created hence exit */
        printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
    }




    /* Write data to file */



    /* Close file to save file data */
    fclose(fPa);






    return 0;
}

void login()
{
	int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="1234";
    do
{

    printf("\n  =======================  LOGIN FORM  =======================\n  ");
    printf(" \n                       ENTER USERNAME:-");
	scanf("%s", &uname);
	printf(" \n                       ENTER PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	//char code=pword;
	i=0;
	//scanf("%s",&pword);
		if(strcmp(uname,"user")==0 && strcmp(pword,"1234")==0)
	{
	printf("  \n\n\n       WELCOME TO OUR SYSTEM !! YOUR LOGIN IS SUCCESSFUL");
	printf("\n\n\n\t\t\t\tPress any key to continue...");
	getch();//holds the screen
	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;

		getch();//holds the screen
		system("cls");
	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");

		getch();

		}
		system("cls");
}
//ALl the globle variables and the composite data types will be declared here
typedef struct{
	char name[50];
	char gender;
	int train_num;
	int num_of_seats;
	int pnr;
	int last_pnr;
}pd;

int pnrassigner1()
    //opening file
{
    FILE *fp = fopen("data/pinfo-t1.txt","r");
    char buffer[100];
    int pnr;

    //selecting last line from database
    while(fgets(buffer,sizeof(buffer),fp));

    //separating by tokens, converting token to integer and incrementing
    char *token=strtok(buffer,"\t");
    pnr=atoi(token) + 1;

    //closing file
    fclose(fp);


    return pnr;
}

int pnrassigner2()
    //opening file
{
    FILE *fp = fopen("data/pinfo.txt-t2","r");
    char buffer[100];
    int pnr;

    //selecting last line from database
    while(fgets(buffer,sizeof(buffer),fp));

    //separating by tokens, converting token to integer and incrementing
    char *token=strtok(buffer,"\t");
    pnr=atoi(token) + 1;

    //closing file
    fclose(fp);


    return pnr;
}

int pnrassigner3()
    //opening file
{
    FILE *fp = fopen("data/pinfo-t3.txt","r");
    char buffer[100];
    int pnr;

    //selecting last line from database
    while(fgets(buffer,sizeof(buffer),fp));

    //separating by tokens, converting token to integer and incrementing
    char *token=strtok(buffer,"\t");
    pnr=atoi(token) + 1;

    //closing file
    fclose(fp);


    return pnr;
}

int pnrassigner4()
    //opening file
{
    FILE *fp = fopen("data/pinfo-t4.txt","r");
    char buffer[100];
    int pnr;

    //selecting last line from database
    while(fgets(buffer,sizeof(buffer),fp));

    //separating by tokens, converting token to integer and incrementing
    char *token=strtok(buffer,"\t");
    pnr=atoi(token) + 1;

    //closing file
    fclose(fp);


    return pnr;
}

int pnrassigner5()
    //opening file
{
    FILE *fp = fopen("data/pinfo-t5.txt","r");
    char buffer[100];
    int pnr;

    //selecting last line from database
    while(fgets(buffer,sizeof(buffer),fp));

    //separating by tokens, converting token to integer and incrementing
    char *token=strtok(buffer,"\t");
    pnr=atoi(token) + 1;

    //closing file
    fclose(fp);


    return pnr;
}

int pnrassigner6()
    //opening file
{
    FILE *fp = fopen("data/pinfo-t6.txt","r");
    char buffer[100];
    int pnr;

    //selecting last line from database
    while(fgets(buffer,sizeof(buffer),fp));

    //separating by tokens, converting token to integer and incrementing
    char *token=strtok(buffer,"\t");
    pnr=atoi(token) + 1;

    //closing file
    fclose(fp);


    return pnr;
}

int pnrassigner7()
    //opening file
{
    FILE *fp = fopen("data/pinfo-t7.txt","r");
    char buffer[100];
    int pnr;

    //selecting last line from database
    while(fgets(buffer,sizeof(buffer),fp));

    //separating by tokens, converting token to integer and incrementing
    char *token=strtok(buffer,"\t");
    pnr=atoi(token) + 1;

    //closing file
    fclose(fp);


    return pnr;
}

void reservation(void)
{
//first the passenger is asked the place of origin is it's Delhi
//str1 is the place of board

printf("Please do not use capital letters");
char str1[100];
char str2[100];
//fgo and all these are train fares
//fpp stands for fare per person
int ret,num;
strcpy(str1,"delhi");
printf("\n Enter the place from where you want to board:");
gets(str2);
ret=strcmp(str2,str1);

if(ret<0)
printf("\n Sorry, No trains available");
else if(ret>0)
printf("\n Sorry, No trains available");
else
{
    printf("\n Trains may be available!!! \n");
    printf("\n Note: Due to the Corona pandemic outbreak only general class tickets are available. \n \n");
}

	int i=0,fgo,fpra,fluc,fmew,fjab,fsha,fdur,fpp,time,charge,sgo,spra,sluc,smew,sjab,ssha,sdur,seats,pnr;
	char confirm;
	float charges;
	pd passdetails;
	FILE *fp;
	system("cls");
    fgo=1265;
    fpra=875;
    fluc=1589;
    fmew=830;
    fjab=650;
    fsha=800;
    fdur=1400;
    sgo=130;
    spra=120;
    sluc=150;
    smew=100;
    sjab=120;
    ssha=140;
    sdur=190;


	//error here have to take input of the name
	printf("\nEnter Number of seats:> ");
	scanf("%d",&passdetails.num_of_seats);
	printf("\n\n>>Press Enter To View Available Trains<< ");
	system("cls");

    tinfo();
	printf("\n\nEnter train number:> ");
	start1:
	scanf("%d",&passdetails.train_num);
	passdetails.pnr=0;

struct train
{
    char tname[20];
    int tno;
    int ttime;
    int tseats;
    int fpp;
    int pnr;
    char source[20];
    char destination[20];
};

struct train t[10];

//structure initialization
//t1=gomti express
strcpy(t[1].tname,"Gomti Express");
t[1].ttime=0500;
t[1].tseats=NULL;
t[1].fpp=fgo;
t[1].pnr=1;
strcpy(t[1].source,"NDLS");
strcpy(t[1].destination,"Lucknow");

strcpy(t[2].tname,"Pragraj Express");
t[2].ttime=0616;
t[2].tseats=NULL;
t[2].fpp=fpra;
t[2].pnr=1;
strcpy(t[2].source,"NDLS");
strcpy(t[2].destination,"Prayagraj");

strcpy(t[3].tname,"Mewar Express");
t[3].ttime=1620;
t[3].tseats=NULL;
t[3].fpp=fmew;
t[3].pnr=1;
strcpy(t[3].source,"H.Nizzamuddin");
strcpy(t[3].destination,"Udaipur");

strcpy(t[4].tname,"Jabalpur Express");
t[4].ttime=1815;
t[4].tseats=NULL;
t[4].fpp=fjab;
t[4].pnr=1;
strcpy(t[4].source,"H.Nizzamuddin");
strcpy(t[4].destination,"Jabalpur");

strcpy(t[5].tname,"Lucknow Mail");
t[5].ttime=1900;
t[5].tseats=NULL;
t[5].fpp=fluc;
t[5].pnr=1;
strcpy(t[5].source,"NDLS");
strcpy(t[5].destination,"Lucknow");

strcpy(t[6].tname,"Shalimar Express");
t[6].ttime=2310;
t[6].tseats=NULL;
t[6].fpp=fsha;
t[6].pnr=1;
strcpy(t[6].source,"H.Nizamuddin");
strcpy(t[6].destination,"Mumbai");

strcpy(t[7].tname,"Duranto");
t[7].ttime=2350;
t[7].tseats=NULL;
t[7].fpp=fdur;
t[7].pnr=1;
strcpy(t[7].source,"NDLS");
strcpy(t[7].destination,"Patna");

if (passdetails.train_num==2420)
{
    fp=fopen("data/pinfo-t1.txt","a");
    printf("You have selected %s.\n",t[1].tname);

    printf("Fare per person is:%d \n",t[1].fpp);
    charge=passdetails.num_of_seats*t[1].fpp;
    charges=fgo;
    printf("The total fare is :%d",charge);
	pnr=pnrassigner1();
	for(i=0;i<passdetails.num_of_seats;i++)
    {
        printf("\nEnter the Name of Passenger[%d]:> ",i+1);
        fflush(stdin);
        gets(passdetails.name);
        printf("Gender(M/F):");
        scanf("%c",&passdetails.gender);
        printf("Your PNR is: %d",pnr);
        fprintf(fp,"%d\t\t%s\t\t%c\t\t%d\t\t%.2f\n",pnr,passdetails.name,passdetails.gender,passdetails.train_num,charges);
        pnr++;
	}

    printf("\n\nConfirm Ticket (y/n):>");
    scanf(" %c",&confirm);
	if(confirm == 'y')
	{
		printf("==================");
		printf("\n Reservation Done\n");
		printf("==================");
		ainfo();
	}

	else
	{		if(confirm=='n'){
			printf("\nReservation Not Done!\n");
		}
		else
		{
			printf("\nInvalid choice entered! Enter again-----> ");

		}
	}
	fclose(fp);
}

else if (passdetails.train_num==2418)
{
    fp=fopen("data/pinfo-t2.txt","a");
    printf("You have selected %s.\n",t[2].tname);

    printf("Fare per person is:%d \n",t[2].fpp);
    charge=passdetails.num_of_seats*t[2].fpp;
    charges=fpra;
    printf("The total fare is :%d",charge);
	pnr=pnrassigner2();
	for(i=0;i<passdetails.num_of_seats;i++)
    {
        printf("\nEnter the Name of Passenger[%d]:> ",i+1);
        fflush(stdin);
        gets(passdetails.name);
        printf("Gender(M/F):");
        scanf("%c",&passdetails.gender);
        printf("Your PNR is: %d",pnr);
        fprintf(fp,"%d\t\t%s\t\t%c\t\t%d\t\t%.2f\n",pnr,passdetails.name,passdetails.gender,passdetails.train_num,charges);
        pnr++;
	}

    printf("\n\nConfirm Ticket (y/n):>");
    scanf(" %c",&confirm);
	if(confirm == 'y')
	{
		printf("==================");
		printf("\n Reservation Done\n");
		printf("==================");
		ainfo();
	}

	else
	{		if(confirm=='n'){
			printf("\nReservation Not Done!\n");
		}
		else
		{
			printf("\nInvalid choice entered! Enter again-----> ");

		}
	}
	fclose(fp);
}

//t3 is mewar express

else if (passdetails.train_num==2963)
{
    fp=fopen("data/pinfo-t3.txt","a");
    printf("You have selected %s.\n",t[3].tname);

    printf("Fare per person is:%d \n",t[3].fpp);
    charge=passdetails.num_of_seats*t[3].fpp;
    charges=fmew;
    printf("The total fare is :%d",charge);
	pnr=pnrassigner3();
	for(i=0;i<passdetails.num_of_seats;i++)
    {
        printf("\nEnter the Name of Passenger[%d]:> ",i+1);
        fflush(stdin);
        gets(passdetails.name);
        printf("Gender(M/F):");
        scanf("%c",&passdetails.gender);
        printf("Your PNR is: %d",pnr);
        fprintf(fp,"%d\t\t%s\t\t%c\t\t%d\t\t%.2f\n",pnr,passdetails.name,passdetails.gender,passdetails.train_num,charges);
        pnr++;
	}

    printf("\n\nConfirm Ticket (y/n):>");
    scanf(" %c",&confirm);
	if(confirm == 'y')
	{
		printf("==================");
		printf("\n Reservation Done\n");
		printf("==================");
		ainfo();
	}

	else
	{		if(confirm=='n'){
			printf("\nReservation Not Done!\n");
		}
		else
		{
			printf("\nInvalid choice entered! Enter again-----> ");

		}
	}
	fclose(fp);
}
//t4 is jabalpur express

else if (passdetails.train_num==2182)
{
    fp=fopen("data/pinfo-t4.txt","a");
    printf("You have selected %s.\n",t[4].tname);

    printf("Fare per person is:%d \n",t[4].fpp);
    charge=passdetails.num_of_seats*t[4].fpp;
    charges=fjab;
    printf("The total fare is :%d",charge);
	pnr=pnrassigner4();
	for(i=0;i<passdetails.num_of_seats;i++)
    {
        printf("\nEnter the Name of Passenger[%d]:> ",i+1);
        fflush(stdin);
        gets(passdetails.name);
        printf("Gender(M/F):");
        scanf("%c",&passdetails.gender);
        printf("Your PNR is: %d",pnr);
        fprintf(fp,"%d\t\t%s\t\t%c\t\t%d\t\t%.2f\n",pnr,passdetails.name,passdetails.gender,passdetails.train_num,charges);
        pnr++;
	}

    printf("\n\nConfirm Ticket (y/n):>");
    scanf(" %c",&confirm);
	if(confirm == 'y')
	{
		printf("==================");
		printf("\n Reservation Done\n");
		printf("==================");
		ainfo();
	}

	else
	{		if(confirm=='n'){
			printf("\nReservation Not Done!\n");
		}
		else
		{
			printf("\nInvalid choice entered! Enter again-----> ");

		}
	}
	fclose(fp);
}
//t5 is Lucknow express
else if (passdetails.train_num==2230)
{
    fp=fopen("data/pinfo-t4.txt","a");
    printf("You have selected %s.\n",t[5].tname);

    printf("Fare per person is:%d \n",t[5].fpp);
    charge=passdetails.num_of_seats*t[5].fpp;
    charges=fluc;
    printf("The total fare is :%d",charge);
	pnr=pnrassigner5();
	for(i=0;i<passdetails.num_of_seats;i++)
    {
        printf("\nEnter the Name of Passenger[%d]:> ",i+1);
        fflush(stdin);
        gets(passdetails.name);
        printf("Gender(M/F):");
        scanf("%c",&passdetails.gender);
        printf("Your PNR is: %d",pnr);
        fprintf(fp,"%d\t\t%s\t\t%c\t\t%d\t\t%.2f\n",pnr,passdetails.name,passdetails.gender,passdetails.train_num,charges);
        pnr++;
	}

    printf("\n\nConfirm Ticket (y/n):>");
    scanf(" %c",&confirm);
	if(confirm == 'y')
	{
		printf("==================");
		printf("\n Reservation Done\n");
		printf("==================");
		ainfo();
	}

	else
	{		if(confirm=='n'){
			printf("\nReservation Not Done!\n");
		}
		else
		{
			printf("\nInvalid choice entered! Enter again-----> ");

		}
	}
	fclose(fp);
}
//t6 is shalimar
else if (passdetails.train_num==2134)
{
    fp=fopen("data/pinfo-t6.txt","a");
    printf("You have selected %s.\n",t[6].tname);

    printf("Fare per person is:%d \n",t[6].fpp);
    charge=passdetails.num_of_seats*t[6].fpp;
    charges=fsha;
    printf("The total fare is :%d",charge);
	pnr=pnrassigner6();
	for(i=0;i<passdetails.num_of_seats;i++)
    {
        printf("\nEnter the Name of Passenger[%d]:> ",i+1);
        fflush(stdin);
        gets(passdetails.name);
        printf("Gender(M/F):");
        scanf("%c",&passdetails.gender);
        printf("Your PNR is: %d",pnr);
        fprintf(fp,"%d\t\t%s\t\t%c\t\t%d\t\t%.2f\n",pnr,passdetails.name,passdetails.gender,passdetails.train_num,charges);
        pnr++;
	}

    printf("\n\nConfirm Ticket (y/n):>");
    scanf(" %c",&confirm);
	if(confirm == 'y')
	{
		printf("==================");
		printf("\n Reservation Done\n");
		printf("==================");
		ainfo();
	}

	else
	{		if(confirm=='n'){
			printf("\nReservation Not Done!\n");
		}
		else
		{
			printf("\nInvalid choice entered! Enter again-----> ");

		}
	}
	fclose(fp);
}
//t7 is duranto
else if (passdetails.train_num==3321)
{
    fp=fopen("data/pinfo-t7.txt","a");
    printf("You have selected %s.\n",t[7].tname);

    printf("Fare per person is:%d \n",t[7].fpp);
    charge=passdetails.num_of_seats*t[7].fpp;
    charges=fdur;
    printf("The total fare is :%d",charge);
	pnr=pnrassigner7();
	for(i=0;i<passdetails.num_of_seats;i++)
    {
        printf("\nEnter the Name of Passenger[%d]:> ",i+1);
        fflush(stdin);
        gets(passdetails.name);
        printf("Gender(M/F):");
        scanf("%c",&passdetails.gender);
        printf("Your PNR is: %d",pnr);
        fprintf(fp,"%d\t\t%s\t\t%c\t\t%d\t\t%.2f\n",pnr,passdetails.name,passdetails.gender,passdetails.train_num,charges);
        pnr++;
	}

    printf("\n\nConfirm Ticket (y/n):>");
    scanf(" %c",&confirm);
	if(confirm == 'y')
	{
		printf("==================");
		printf("\n Reservation Done\n");
		printf("==================");
		ainfo();
	}

	else
	{		if(confirm=='n'){
			printf("\nReservation Not Done!\n");
		}
		else
		{
			printf("\nInvalid choice entered! Enter again-----> ");

		}
	}
	fclose(fp);
}

else{
    printf("Enter a valid train number>>>>");
}

}



struct passenger{//struct to store passenger ticket data
	int pnr;
	char name[15];
	char gender;
	int trainno;
	int cost;
};
struct passenger p;

struct passenger getCancelledTicketData();//to get the passenger's ticket data from pinfo.txt
void updatePinfo(struct passenger p);//to remove the entry of cancelled ticket




void cancel(void)
{
    printf("Enter PNR number: ");
	int pnr;
	scanf("%d", &pnr);//to get PNR number of ticket to cancel
	p = getCancelledTicketData(pnr);//returns a struct p which contains the data of the ticket being cancelled
	if(p.pnr<0){//shows error if invalid PNR entered
		printf("Error: Invalid PNR\n");
	}else{
		updatePinfo(p);//ticket entry removed from pinfo.txt
		printf("YOU HAVE SUCCESSFULLY CANCELLED A TICKET!\nREFUNDED AMOUNT: %.2f\n", (float)p.cost/2);//shows refunded amount
}
}
struct passenger getCancelledTicketData(int pnr){
	FILE *fp = fopen("./data/pinfo.txt","r");//opens file containing passenger data
	struct passenger p;
	char str[100];//buffer to store lines from pinfo.txt
	while(fgets(str,99,fp)){//gets lines from pinfo.txt until loop breaks
    char* token = strtok(str, "\t");//converts the data in the line into tokens and returns the first token
    p.pnr = atoi(token);//the first token contains pnr which is stored in p.pnr

    token = strtok(NULL, "\t"); //gives next token which contains the name
	strcpy(p.name,token);

    token = strtok(NULL, "\t"); //gives next token which contains the gender
	p.gender=token[0];

    token = strtok(NULL, "\t"); //gives next token which contains the train number
	p.trainno = atoi(token);

    token = strtok(NULL, "\t"); //gives next token which contains the price of ticket
	p.cost = atoi(token);

	if(pnr==p.pnr){ //if p.pnr matches the pnr of the ticket to cancel, returns the struct p containing all its data
			fclose(fp);
			return p;
	}
	}
	p.pnr=-1;//if pnr input by user is not present in pinfo.txt, returns p.pnr = -1 to show error
	return p;
}

void updatePinfo(struct passenger p){
	FILE *fp1 = fopen("./data/pinfo.txt","r");
	FILE *fp2 = fopen("./data/temp.txt","w");//new file opened to store all ticket data except the cancelled ticket
	struct passenger q;
	char str[100], buffer[100];//buffers to copy file lines into
	while(fgets(str, 99, fp1)){
		strcpy(buffer, str);
		char* token = strtok(str, "\t");
		q.pnr = atoi(token);//stores the pnr of the line being read to struct q

		if(q.pnr!=p.pnr){//writes the line into temp.txt if q.pnr does not match pnr of cancelled ticket
			fputs(buffer, fp2);
		}
	}
	fclose(fp1);
	fclose(fp2);
	remove("./data/pinfo.txt");//deletes pinfo.txt
	rename("./data/temp.txt","./data/pinfo.txt");//renames temp.txt to pinfo.txt thus erasing entry of cancelled ticket
}





int main()

{

login();
	int menu_choice,choice_return;
	start:
	system("cls");
	printf("\n_____________________________________\n");
	printf("    TRAIN RESERVATION SYSTEM");
	printf("\n_______________________________________");
	printf("\n1>> Reserve A Ticket");
	printf("\n_______________________________________");
	printf("\n2>> View All Available Trains");
	printf("\n_______________________________________");
	printf("\n3>> Cancel Reservation");
	printf("\n_______________________________________");
	printf("\n4>> Exit");
	printf("\n_______________________________________");
	printf("\n\n Please enter a choice number:");
	scanf("%d",&menu_choice);



switch(menu_choice)
{
		case 1:
			reservation();
			break;
		case 2:
			tinfo();
			printf("\n\nPress any key to go to Main Menu..");
			break;
		case 3:
			cancel();
			//function not added. code has been removed due to some errors
			break;
		case 4:
			return(0);
		default:
			printf("\nInvalid choice");
}
}






