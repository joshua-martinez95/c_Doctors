#include <stdio.h>
#include <stdlib.h>
#include <time.h>   
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

//Don't forget to put in verification for a loop to ask when done with program.

struct patients
{
	char name[25];
	char dob[11];
	int weight;
	int height;
	char ale[60]; //Might change this
	char docs[11];
	
};
void newP();
void clear(void);
void updateP();
int pplNum();
void showAllDocs();
void showAllP();
void deleteP();
void pin(int num, int n);
int main()
{
	
char mainMenu = 'y';
do{
	
int option;
printf("\t\t\t\tWelcome, Please choose an option from the menu(maybe inputing another digit will show a surprise!)\n\n");
printf("\t\t1. Enter a New patient\t\t\t\t\t2.Update info on a patient\n\n");
printf("\t\t3. Delete a person\t\t\t\t\t4.Show all patients\n\n");
printf("\t\t\t\t\t\t5.Show all our doctors\n\n");
scanf("%d", &option);
clear();

if(option == 1)
	newP();
else if(option == 2)
	updateP();
else if(option == 3)
	deleteP();
else if(option == 4)
	showAllP();
else if(option == 5)
	showAllDocs();
else
{
	//printf("\n\n\nPlease pick a valid option!\n\n\n");
	int num;
	printf("Input any number: ");
	scanf("%d", &num);
	pin(num, num);
	clear();
}
//clear();

	printf("\n\nWant to go back to the main menu? (y/n) : ");
	scanf("%c", &mainMenu);
}while (mainMenu != 'n');

}

void newP()
	//delete this and make pointer to array made from file
{
	struct patients p1;
	
	printf("Please enter following information:\n\n");
	printf("Name: ");
	fgets(p1.name, 25, stdin);
	//printf("\n\n%s\n\n", &p1.name);
	
	printf("Date of birth(MM/DD/YYYY): ");
	fgets(p1.dob, 11, stdin);
	//printf("\n\n%s\n\n", &p1.dob);
	clear();
	
	printf("Weight(in pounds, whole numbers): ");
	scanf("%d", &p1.weight);
	//printf("\n\n%d\n\n", p1.weight);
	clear();
	
	printf("Height(in inches, whole numbers): ");
	scanf("%d", &p1.height);
	//printf("\n\n%d\n\n", p1.height);
	clear();
	
	printf("What diseases or health problems does the patient?(Seperated by commas)\n");
	fgets(p1.ale, 60, stdin);
	//printf("\n\n%s\n\n", &p1.ale);
	
	
	printf("Who is this patients doctor? These are the options ");
	printf("Dr. Tompkins, Dr. Martin, Dr. Spalding, Dr. Lee, Dr. Strange(only include last name)\n\n");
	fgets(p1.docs, 11, stdin);

	FILE *fp;

   fp = fopen("people.txt", "a+");
   fprintf(fp, "%s%s\n%d\n%d\n%s%s", &p1.name, &p1.dob, p1.weight, p1.height, &p1.ale, &p1.docs);

   fclose(fp);
	printf("\n\nend of new patient\n\n");
	}
void updateP()
{
	char doneWithUpdate = 'y';

	do{
	
	int index; 
	int numPPL = pplNum();
	struct patients filePPL[numPPL];
	
	FILE *fp;
	fp = fopen("people.txt", "a+");
	
	char buff[300];

	
	
	for(int k = 0; k < numPPL; k++)
{
	char finalName[25];
	char nextToF[25];
	char finalDOB[11];
	char nextToD[11];

	
	for(int i = 0; i < 6; i++)
	{
		char tW[4];
		memset(tW, 0, 4);
		char tH[4];
		memset(tH, 0, 4);
		
	  fgets(buff, 300, (FILE*)fp);

	  if(i == 0)
		  strcpy(filePPL[k].name, buff);
	  else if(i == 1)
		  strcpy(filePPL[k].dob, buff);
	  else if(i == 2)
	  {
		  filePPL[k].weight = atoi(buff);
	  }
	  else if(i == 3)
		  filePPL[k].height = atoi(buff);
	  else if(i == 4)
		  strcpy(filePPL[k].ale, buff);
	  else if(i == 5)
		  strcpy(filePPL[k].docs, buff);
	}
	strcpy(nextToF, filePPL[k].name);
	

	

	memset(finalName, 0, 25);
	for(int j = 0; j < 25 && nextToF[j] != '\n'; j++)
	{
		finalName[j] = nextToF[j];
	}
	
	memset(filePPL[k].name, 0, 25);
	
	

	printf("\n\n");
	
	strcpy(filePPL[k].name, finalName);
	

	strcpy(nextToD, filePPL[k].dob);
	memset(finalDOB, 0, 11);
	
	
	for(int j = 0; j < 11 && nextToD[j] != '\n'; j++)
	{
		finalDOB[j] = nextToD[j];
	}
	memset(filePPL[k].dob, 0, 11);
	strcpy(filePPL[k].dob, finalDOB);


}	

	char temp[25];
	char value[25];
	bool nameSame = false;
	
	do{
	printf("Please input patients full name: ");
	fgets(temp, 25, stdin);

	for(int k = 0; k < numPPL; k++)
  {
	
	strcpy(value, filePPL[k].name);
	
	
	
	for(int i = 0; i < 25 && temp[i] <= 'z' && temp[i] >= 'A' || temp[i] == ' '; i++)
	{
		if(value[i] == temp[i])
		{
			nameSame = true;
		}
		else
		{
			//printf("\nthere is a false\n");
			nameSame = false;
			break;
		}
	}
	printf("\n\n\n");
	if(nameSame == true)
	{
	//printf("\n\nYour person is in index: %d\n\n", k);
	index = k;
	break;
	}

	memset(value, 0, 25);
  }
	}while(nameSame == false);
  
  char doneWithCurrP = 'y';
  
  do{
  int doThing;
  bool doThingBool = false;
  printf("What do you want to edit?\n(1)Weight (2)Height (3)Diseases (4)Doctor: ");
  scanf("%d", &doThing);
  clear();
  
  
  
  if(doThing == 1)
  {
	 printf("\nPlease input a new weight: ");
	 scanf("%d", &filePPL[index].weight);
	 clear();
  }
    if(doThing == 2)
  {
	 printf("\nPlease input a new height: ");
	 scanf("%d", &filePPL[index].height);
	 clear();
  }
    if(doThing == 3)
  {
	 printf("\n{%s}\n", filePPL[index].ale); 
	 printf("\nPlease input a new health conditions, includeing previous ones: ");
	 fgets(filePPL[index].ale, 60, stdin);
	 printf("\n{%s}\n", filePPL[index].ale); 
	
  }
	if(doThing == 4)
	{
	 printf("\n{%s}\n", filePPL[index].docs); 
	 printf("\nPlease choose a new Doctor: Dr. Tompkins, Dr. Martin, Dr. Spalding, Dr. Lee, Dr. Strange(only include last name): ");
	 fgets(filePPL[index].docs, 11, stdin);
	 printf("\n{%s}\n", filePPL[index].docs); 	
		
	}
	printf("\nDo you want to update something else from this person's information? (y/n)\n");
	scanf("%c", &doneWithCurrP);
  } while (doneWithCurrP != 'n');

fclose(fp);

	FILE *finalfp;
	finalfp = fopen("people.txt", "w+");
		
			
	for(int i = 0; i < numPPL; i++)
	{
		
		fprintf(fp, "%s\n%s\n%d\n%d\n%s%s", &filePPL[i].name, &filePPL[i].dob, filePPL[i].weight, filePPL[i].height, &filePPL[i].ale, &filePPL[i].docs);
		
	}
			

fclose(finalfp);

//	printf("-%c-\n", doneWithUpdate);
	printf("Want to update another persons info? (y/n)");
	clear();
	scanf("%c", &doneWithUpdate);
	//printf("-%c-", doneWithUpdate);
	
	
	}while (doneWithUpdate != 'n');
}
void deleteP()
{
	
	char doneDELETE = 'y';
	
do{
	char sure = 'y';
	

	
	int index; 
	int numPPL = pplNum();
	struct patients filePPL[numPPL];
	
	FILE *fp;
	fp = fopen("people.txt", "a+");
	
	char buff[300];

	
	
	for(int k = 0; k < numPPL; k++)
{
	char finalName[25];
	char nextToF[25];
	char finalDOB[11];
	char nextToD[11];
	
	for(int i = 0; i < 6; i++)
	{
		char tW[4];
		memset(tW, 0, 4);
		char tH[4];
		memset(tH, 0, 4);
		
	  fgets(buff, 300, (FILE*)fp);

	  if(i == 0)
		  strcpy(filePPL[k].name, buff);
	  else if(i == 1)
		  strcpy(filePPL[k].dob, buff);
	  else if(i == 2)
	  {
		  filePPL[k].weight = atoi(buff);
	  }
	  else if(i == 3)
		  filePPL[k].height = atoi(buff);
	  else if(i == 4)
		  strcpy(filePPL[k].ale, buff);
	  else if(i == 5)
		  strcpy(filePPL[k].docs, buff);
	}
	strcpy(nextToF, filePPL[k].name);
	

	memset(finalName, 0, 25);
	for(int j = 0; j < 25 && nextToF[j] != '\n'; j++)
	{
		finalName[j] = nextToF[j];
	}
	
	memset(filePPL[k].name, 0, 25);

	
	printf("\n\n");
	
	strcpy(filePPL[k].name, finalName);
	

	strcpy(nextToD, filePPL[k].dob);
	memset(finalDOB, 0, 11);
	
	
	for(int j = 0; j < 11 && nextToD[j] != '\n'; j++)
	{
		finalDOB[j] = nextToD[j];
	}
	memset(filePPL[k].dob, 0, 11);
	strcpy(filePPL[k].dob, finalDOB);

}	

	char temp[25];
	char value[25];
	bool nameSame = false;
	
	do{
	printf("Please input patients full name: ");
	fgets(temp, 25, stdin);

	for(int k = 0; k < numPPL; k++)
  {
	
	strcpy(value, filePPL[k].name);
	
	for(int i = 0; i < 25 && temp[i] <= 'z' && temp[i] >= 'A' || temp[i] == ' '; i++)
	{
		if(value[i] == temp[i])
		{
			nameSame = true;
		}
		else
		{
			//printf("\nthere is a false\n");
			nameSame = false;
			break;
		}
		//printf("|%c-%c|%d", value[i], temp[i], i);
	}
	printf("\n\n\n");
	if(nameSame == true)
	{
	//printf("\n\nYour person is in index: %d\n\n", k);
	index = k;
	break;
	}
	//////
	//add a do loop for to ask for keep going while you can't find the name
	/////
	memset(value, 0, 25);
  }
	}while(nameSame == false);
	fclose(fp);
	//print everyone with that last name with all with numbers next to the people
	//printf("Please pick a person(input a number): ");
	printf("Are you sure you want to delete (%s) (y/n)?",filePPL[index].name);
	//clear();
	scanf("%c", &sure);
//	printf("-%c-", sure);
	
	FILE *finalfp;
	finalfp = fopen("people.txt", "w+");
		
			
	for(int i = 0; i < numPPL; i++)
	{
		//printf("\n%d\n", i);
		if(i != index)
		{
			fprintf(finalfp, "%s\n%s\n%d\n%d\n%s%s", &filePPL[i].name, &filePPL[i].dob, filePPL[i].weight, filePPL[i].height, &filePPL[i].ale, &filePPL[i].docs);
			//printf("\nhello\n");
		}
		else
			printf("\nDeleted\n");
	}
			

fclose(finalfp);
	
	
	clear();
	
	printf("Another?(y/n) ");
	scanf("%c", &doneDELETE);
	} while(doneDELETE != 'n');
	
}
void showAllP()
{
	//print all patients
	//int index; 
	int numPPL = pplNum();
	struct patients *filePPL;//[numPPL];
	filePPL = (struct patients*)malloc(sizeof(struct patients)* numPPL);
	
	FILE *fp;
	fp = fopen("people.txt", "a+");
	
	//token = strtok((File*)fp, s);
	char buff[300];

	
	
	for(int k = 0; k < numPPL; k++)
{
	char finalName[25];
	char nextToF[25];
	char finalDOB[11];
	char nextToD[11];
	
	for(int i = 0; i < 6; i++)
	{
		char tW[4];
		memset(tW, 0, 4);
		char tH[4];
		memset(tH, 0, 4);
		
		//////do height next!!
	  fgets(buff, 300, (FILE*)fp);
	  if(i == 0)
		  strcpy(filePPL[k].name, buff);
	  else if(i == 1)
		  strcpy(filePPL[k].dob, buff);
	  else if(i == 2)
	  {
		  filePPL[k].weight = atoi(buff);
	  }
	  else if(i == 3)
		  filePPL[k].height = atoi(buff);
	  else if(i == 4)
		  strcpy(filePPL[k].ale, buff);
	  else if(i == 5)
		  strcpy(filePPL[k].docs, buff);
	}
	strcpy(nextToF, filePPL[k].name);
	

	
	
	memset(finalName, 0, 25);
	
	for(int j = 0; j < 25 && nextToF[j] != '\n'; j++)
	{
		finalName[j] = nextToF[j];
		
	}
	
	memset(filePPL[k].name, 0, 25);

	
	strcpy(filePPL[k].name, finalName);
	

	strcpy(nextToD, filePPL[k].dob);
	memset(finalDOB, 0, 11);
	
	
	for(int j = 0; j < 11 && nextToD[j] != '\n'; j++)
	{
		finalDOB[j] = nextToD[j];
	}
	memset(filePPL[k].dob, 0, 11);
	strcpy(filePPL[k].dob, finalDOB);

}	
	printf("These are all our patients!\n\n");
	
	for(int i = 0; i < numPPL; i++)
	{
		printf("\n\nName: %s", filePPL[i].name); 
		printf("\nDate of Birth: %s", filePPL[i].dob);
		printf("\nWeight: %d", filePPL[i].weight);
		printf("\nHeight in inches: %d", filePPL[i].height);
		printf("\nHealth Conditions: %s", filePPL[i].ale);
		printf("Doctor: Dr.%s", filePPL[i].docs);		
		printf("\n\n");
	}
	
	free(filePPL);
}
void showAllDocs()
{
	
	char *allDoctors[5];
	allDoctors[0] = "Tompkins";
	allDoctors[1] = "Martin";
	allDoctors[2] = "Spalding";
	allDoctors[3] = "Lee";
	allDoctors[4] = "Strange";
	printf("\n\nAll our Doctors are: ");//Dr. Tompkins, Dr. Martin, Dr. Spalding, Dr. Lee, Dr. Strange\n\n");
	for(int i = 0; i < 5; i++)
	{
		printf("Dr. %s", allDoctors[i]);
		if(i != 4)
			printf(", ");
		
	}
	printf("\n\n");
	
	
	}


void clear(void)
{
	while ( getchar() != '\n' );
}
int pplNum()
{
	///////________________method to see how many people are there
	FILE *fp1;
	//char *token;
	
	fp1 = fopen("people.txt", "a+");
	
	int lines = 0;
	char numBuff[300];
	do{
	  fgets(numBuff, 300, (FILE*)fp1);
	//  printf("\n-%c-\n", numBuff[0]);
	  lines++;
	  if(feof(fp1))
		  break;
	
	}while (numBuff != NULL);
	lines--;
	
	fclose(fp1);
	int numPPLs = lines/6;
	return numPPLs;
}

void pin(int num, int n)
{
	//static int j = 4;
    if (num <= 1)
	{
		for(int i = 0; i < n; i++)
			printf(" ");
        printf("*\n");
	}
    else
    {
		pin(num - 1, n);
		int j = n - (num - 1);
		//n = n-1;
		
		for(int i = 0; i < (n - (num-1)); i++)
			printf(" ");
       
		while(num >= 1)
        {
            printf("* ");
            num--;
        }
	//	for(int i = 0; i < n-1; i++)
		//printf(".");
	//	printf("%d", (j));
	   printf("\n");
    }
}
