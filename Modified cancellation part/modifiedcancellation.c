#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct passenger{//struct to store passenger ticket data
	int pnr;
	char name[15];
	char gender;
	int trainno;
	int cost;
};
struct passenger p;

struct passenger getCancelledTicketData(int pnr, char filename[]);
int getSrNo(int InputTrainNo);
void getPinfoFile(char *filename, int srNo);
void updatePinfo(struct passenger p, char filename[]);

int main(){
	int InputTrainNo;
	printf("Enter train no: ");
	scanf("%d", &InputTrainNo);
	int srNo;
	srNo = getSrNo(InputTrainNo);
	if(srNo>0){
	char filename[20];
	getPinfoFile(filename, srNo);
	printf("Enter PNR number: ");
	int pnr;
	scanf("%d", &pnr);
	p = getCancelledTicketData(pnr, filename);
	if(p.pnr<0){//shows error if invalid PNR entered
		printf("Error: Invalid PNR\n");
	}else{
		updatePinfo(p, filename);//ticket entry removed from pinfo.txt
		printf("YOU HAVE SUCCESSFULLY CANCELLED A TICKET!\nREFUNDED AMOUNT: %.2f\n", (float)p.cost/2);//shows refunded amount
	}
}
		
	
}

int getSrNo(int InputTrainNo){
	FILE *fp = fopen("./data/tinfo1.txt","r");
	char buffer[15];
	int srNo, tno;
	
	while(fgets(buffer,14,fp)){
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
	printf("Invalid train number\n");
	return -1;
}

struct passenger getCancelledTicketData(int pnr, char filename[]){
	FILE *fp = fopen(filename,"r");//opens file containing passenger data
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

void getPinfoFile(char *filename, int srNo){
	strcpy(filename, "./data/pinfo-t");
	char serialNo[5];
	itoa(srNo, serialNo, 10);
	strcat(filename, serialNo);
	strcat(filename, ".txt");
}

void updatePinfo(struct passenger p, char filename[]){
	FILE *fp1 = fopen(filename,"r");
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
	remove(filename);//deletes pinfo.txt
	rename("./data/temp.txt",filename);//renames temp.txt to pinfo.txt thus erasing entry of cancelled ticket
}