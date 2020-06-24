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





int pnrassigner(int tsno)

{


    //opening passenger data file
    FILE *fp = fopen("data/pinfo.txt","r");
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






//seats decreasing function
//input: serial number, ticket decrease
void seatsdec(int sno,int tcdec){

    //ticket available
    int tcav, i=0, j=0;

    //opening database and temporary file
    FILE *fp1 = fopen("data/tinfo.txt","r");
    FILE *fp2 = fopen("data/temp.txt","w");

    //reading database one line at a time
    char line[200];
    while(fgets(line,sizeof(line),fp1)){
        i++;//count for lines
        //when line to be edited is selected
        if(i==(sno+3)){

            //converting data in line into tokens separated by multiple tabs
            for(char *token=strtok(line,"\t");token!=NULL;token=strtok(NULL,"\t")){
                j++;//count for tokens

                //when token for number of seats is read
                if(j==8){

                    //converting token to integer and decreasing available seats as bookings are done
                    tcav=atoi(token);
                    tcav=tcav-tcdec;


                    //making sure available seats data occupy 3 spaces and updated available seats stored in the spaces
                    if(tcav==0){
                        fprintf(fp2,"000%s","\n");
                    }
                    else{
                        if(tcav<10){
                            fprintf(fp2,"00");
                        }
                        else {
                            if(tcav<100){
                                fprintf(fp2,"0");
                            }
                        }
                        fprintf(fp2,"%d%s",tcav,"\n");
                    }
                    

                }

                //other tokens written to temporary file as they are
                else{
                    fprintf(fp2,"%s",token);

                    fprintf(fp2,"%s","\t\t");
                }

            }
        }

        //for other lines, writting data as it is in temporary file
        else{
            fprintf(fp2,"%s",line);
        }
    }

    //closing both files
    fclose(fp1);
    fclose(fp2);

    //removing previous database and making temporary file the new database
    remove("data/tinfo.txt");
    rename("data/temp.txt","data/tinfo.txt");
}






//seats increasing function
//input: serial number, ticket increase
void seatsinc(int sno,int tcinc){

    //ticket available
    int tcav, i=0, j=0;

    //opening database and temporary file
    FILE *fp1 = fopen("data/tinfo.txt","r");
    FILE *fp2 = fopen("data/temp.txt","w");

    //reading database one line at a time
    char line[200];
    while(fgets(line,sizeof(line),fp1)){
        i++;//count for lines
        //when line to be edited is selected
        if(i==(sno+3)){

            //converting data in line into tokens separated by multiple tabs
            for(char *token=strtok(line,"\t");token!=NULL;token=strtok(NULL,"\t")){
                j++;//count for tokens

                //when token for number of seats is read
                if(j==8){

                    //converting token to integer and increasing available seats as cancellations are done
                    tcav=atoi(token);
                    tcav=tcav+tcinc;


                    //making sure available seats data occupy 3 spaces and updated available seats stored in the spaces
                    if(tcav<10){
                        fprintf(fp2,"00");
                    }
                    else{
                        if(tcav<100){
                            fprintf(fp2,"0");
                        }
                    }
                    fprintf(fp2,"%d%s",tcav,"\n");

                }

                //other tokens written to temporary file as they are
                else{
                    fprintf(fp2,"%s",token);

                    fprintf(fp2,"%s","\t\t");
                }

            }
        }

        //for other lines, writting data as it is in temporary file
        else{
            fprintf(fp2,"%s",line);
        }
    }

    //closing both files
    fclose(fp1);
    fclose(fp2);

    //removing previous database and making temporary file the new database
    remove("data/tinfo.txt");
    rename("data/temp.txt","data/tinfo.txt");
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
scanf("%s",&str2);
ret=strcmp(str2,str1);

if(ret==0){
    printf("\n Trains may be available!!! \n");
    printf("\n Note: Due to the Corona pandemic outbreak only general class tickets are available. \n \n");
    printf("\n\nPress any key to view trains.");
    getch();
}
else
{
    printf("\n Sorry, No trains available");
    printf("\n\nPress any key to go to Main Menu..");
    getch();
    return;
}

	int i=0,charge;
	char confirm;
	float charges;
	pd passdetails;
	FILE *fp;
	system("cls");


    tinfo();
	printf("\nEnter Number of seats:> ");
	scanf("%d",&passdetails.num_of_seats);

    
	printf("\n\nEnter train number:> ");
	start1:
	scanf("%d",&passdetails.train_num);
	passdetails.pnr=0;

struct train
{
    char tname[20];
    int tno;
    char ttime[20];
    int tseats;
    int fpp;
    char source[20];
    char destination[20];
    int sno;
};

struct train t[10];





//opening train database to read and store train info
fp=fopen("data/tinfo.txt","r");
int l=0,tk=0;//line count, token count 
char line[200];
while (fgets(line,sizeof(line),fp)){
    l++;
    

    //line containing train information
    if(l>3){

        //converting data into tokens and storing data in structure
        for(char *token=strtok(line,"\t");token!=NULL;token=strtok(NULL,"\t")){
            tk++;
            switch (tk)
            {
                case 1:
                    t[l-3].sno=atoi(token);
                    break;
                case 2:
                    t[l-3].tno=atoi(token);
                    break;
                case 3:
                    strcpy(t[l-3].source,token);
                    break;
                case 4:
                    strcpy(t[l-3].destination,token);
                    break;
                case 5:
                    strcpy(t[l-3].tname,token);
                    break;
                case 6:
                    strcpy(t[l-3].ttime,token);
                    break;
                case 7:
                    t[l-3].fpp=atoi(token);
                    break;
                case 8:
                    t[l-3].tseats=atoi(token);
                    break;

                default:
                    continue;
            }
        }
        tk=0;
    }

}

//selecting serial number corresponding to train number selected by user
int sn;
for(int j=1;j<8;j++){
    if(t[j].tno==passdetails.train_num){
        sn=t[j].sno;
    }
}





//closing file
fclose(fp);


//seats availability check
if(t[sn].tseats<passdetails.num_of_seats){
    printf("%d seats are not available in this train. Please check availability.", passdetails.num_of_seats);
    printf("\n\nPress any key to go to Main Menu..");
    getch();
}
else{
    //opening file
    fp=fopen("data/pinfo.txt","a");


    //asking and printing passenger details
    printf("You have selected %s\n",t[sn].tname);
    printf("Fare per person is:%d \n",t[sn].fpp);
        charge=passdetails.num_of_seats*t[sn].fpp;
        charges=t[sn].fpp;
        printf("The total fare is :%d",charge);
	    passdetails.pnr=pnrassigner(sn);
	    for(i=0;i<passdetails.num_of_seats;i++)
        {
            printf("\nEnter the Name of Passenger[%d]:> ",i+1);
            fflush(stdin);
            gets(passdetails.name);
            printf("Gender(M/F):");
            scanf("%c",&passdetails.gender);
            printf("Your PNR is: %d",passdetails.pnr);
            fprintf(fp,"%d\t%s\t%c\t%d\t%.2f\n",passdetails.pnr,passdetails.name,passdetails.gender,passdetails.train_num,charges);
            passdetails.pnr++;
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
	    {	if(confirm=='n')
            {
		    	printf("\nReservation Not Done!\n");
		    }
		    else
		    {
		    	printf("\nInvalid choice entered! Enter again-----> ");

    		}
	    }
	    fclose(fp);

        //decreasing seats
        seatsdec(sn,passdetails.num_of_seats);

        printf("\n\nPress any key to go to Main Menu..");
        getch();
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

struct passenger getCancelledTicketData(int pnr, char filename[]);//function to get data of cancelled ticket
int getSrNo(int InputTrainNo);//gets the serial number of the train
void updatePinfo(struct passenger p, char filename[]);//removes entry from pinfo.txt

void cancel(void){
	int InputTrainNo;
	system("cls");
    tinfo();
	printf("\nEnter train no: ");
	scanf("%d", &InputTrainNo);
	int srNo;
	srNo = getSrNo(InputTrainNo);//gets the serial number of the train
	if(srNo>0){//error if srNo <=  0
	char filename[20];
	strcpy(filename, "./data/pinfo.txt");//filename = "./data/pinfo.txt"
	printf("Enter PNR number: ");
	int pnr;
	scanf("%d", &pnr);
	p = getCancelledTicketData(pnr, filename);
	if(p.pnr<0){//shows error if invalid PNR entered
		printf("Error: Invalid PNR\n");
		getch();//holds screen
	}else{
		updatePinfo(p, filename);//ticket entry removed from pinfo.txt
		printf("YOU HAVE SUCCESSFULLY CANCELLED A TICKET!\nREFUNDED AMOUNT: %.2f\n", (float)p.cost/2);//shows refunded amount
		seatsinc(srNo, 1);//increments a seat
        printf("\n\nPress any key to go to Main Menu..");
        getch();//holds screen
		
	}
}


}

int getSrNo(int InputTrainNo){
	FILE *fp = fopen("./data/tinfo1.txt","r");
	char buffer[15];
	int srNo, tno;

	while(fgets(buffer,14,fp)){//reads lines from tinfo1.txt and if train number matches returns serial number
		char* token = strtok(buffer, "\t");
		srNo = atoi(token);
		token = strtok(NULL, "\t");
		tno = atoi(token);

		if(tno == InputTrainNo){
			fclose(fp);
			return srNo;
		}
	}
	fclose(fp);
	printf("Invalid train number\n");//if invalid train number is entered
	return -1;
}

struct passenger getCancelledTicketData(int pnr, char filename[]){
	FILE *fp = fopen(filename,"r");//opens file containing passenger data
	struct passenger p;
    int i=0;
	char str[100];//buffer to store lines from pinfo.txt
	while(fgets(str,99,fp)){//gets lines from pinfo.txt until loop breaks
    i++;
    if(i>3){
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

    }
	p.pnr=-1;//if pnr input by user is not present in pinfo.txt, returns p.pnr = -1 to show error
	return p;
}

void updatePinfo(struct passenger p, char filename[]){
	FILE *fp1 = fopen(filename,"r");
	FILE *fp2 = fopen("./data/temp.txt","w");//new file opened to store all ticket data except the cancelled ticket
	struct passenger q;
    int i=0;
	char str[100], buffer[100];//buffers to copy file lines into
	while(fgets(str, 99, fp1)){
		i++;
        if(i>3){
            strcpy(buffer, str);
		    char* token = strtok(str, "\t");
		    q.pnr = atoi(token);//stores the pnr of the line being read to struct q

    		if(q.pnr!=p.pnr){//writes the line into temp.txt if q.pnr does not match pnr of cancelled ticket
	    		fputs(buffer, fp2);
		    }
        }
        else{
            fputs(str,fp2);
        }
        
	}
	fclose(fp1);
	fclose(fp2);
	remove(filename);//deletes pinfo.txt
	rename("./data/temp.txt",filename);//renames temp.txt to pinfo.txt thus erasing entry of cancelled ticket
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
            getch();
			break;
		case 3:
            cancel();
		 	break;
		case 4:
			return(0);
		default:
			printf("\nInvalid choice");
}
goto start;
}






