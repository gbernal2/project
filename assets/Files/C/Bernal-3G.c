#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

#define F_OK 0

typedef struct {
	char name[50];
	char author[50];
	char year[50];
	char price[50];
}book;

book Book;
char go_menu[50];

void menu();
void banner();
char Format(char temp_f[50],char filename[50]);
char Format_2nd(char temp_f2[50]);
void Create(char temp_f[50],char filename[50],char temp_f2[50]);
char Check(char temp_c1[50],char temp_c2[50]);
void Read(char temp_c1[50],char temp_c2[50]);
void Delete(char temp_c1[50],char temp_c2[50]);
void Booklist();
void Update(char temp_c1[50], char temp_c2[50]);
void Rename();

int main(){
	char choice[50];
	char temp_f[50];
	char temp_f2[50];
	char filename[50];
	char temp_c1[50];
	char temp_c2[50];
	
	while(1){
		
	menu();
	
	printf("Enter choice: ");
	fgets(choice,50,stdin);
	choice[strlen(choice)-1]= '\0';
	
	
		if(strcmp(choice,"Create")==0 || (strcmp(choice,"create")==0)){
			
			system("cls");
			Create(temp_f,filename,temp_f2);
			system("cls");
			
		}
		
		else if(strcmp(choice,"Check")==0 || (strcmp(choice,"check")==0)){
			
			system("cls");
			Check(temp_c1,temp_c2);
			system("cls");
			
		}
		
		
		else if(strcmp(choice,"Update")==0 || (strcmp(choice,"update")==0)){
			
			system("cls");
			Update(temp_c1,temp_c2);
			system("cls");
		}
		
		
		else if(strcmp(choice,"Read")==0 || (strcmp(choice,"read")==0)){
			
			system("cls");
			Read(temp_c1,temp_c2);
			system("cls");
			
		}
		
		
		else if(strcmp(choice,"Delete")==0 || (strcmp(choice,"delete")==0)){
			
			system("cls");
			Delete(temp_c1,temp_c2);
			system("cls");
			
		}
		
		
		else if(strcmp(choice,"Booklist")==0 || (strcmp(choice,"booklist")==0)){
			
			system("cls");
			banner();
			printf("\n\n");
			Booklist();
			system("pause");
			system("cls");
		}
		
		
		else if (strcmp(choice, "Rename") == 0 || strcmp(choice, "rename") == 0) {
			
        system("cls");
        Rename();
        system("cls");
        
    }
		
		else if(strcmp(choice,"Exit")==0 || (strcmp(choice,"exit")==0)){
			
			exit(0);
		
		}
	
	
		else{
			
			printf("\nInvalid input pls. try again..\n");
			system("pause");
			system("cls");
			
		}
	}
		
	return 0;
}



/* Menu in a function so I could call the menu option
   whenever I need it*/
void menu(){
	
 	puts("|-------------------------------------------|");
 	puts("|                  MENU                     |");
	puts("|       TYPE THE WORD OF THE FEATURE        |");
	puts("|-------------------------------------------|");
 	puts("|-------------------------------------------|");
	puts("|-------------------------------------------|");
 	puts("|         Create           Read             |");
 	puts("|         Delete         Booklist           |");
 	puts("|         Update           Exit             |");
 	puts("|-------------------------------------------|");
 
}



/* Banner in a function so I could call the Banner option
   whenever I need it*/
void banner(){
	puts("                    NOTE                     ");
	puts("|-------------------------------------------|");
 	puts("|               Press Enter                 |");
 	puts("|            to go back to MENU             |");
 	puts("|-------------------------------------------|");
 	puts("|-------------------------------------------|");
 	puts("|-------------------------------------------|");
 	puts("|               Type Exit                   |");
 	puts("|           to exit the program             |");
 	puts("|-------------------------------------------|");	
}



/*  -this function is use  to create a file with the book info
	-uses while(true) loop so the user can exit the program and go back to menu
	-has a exit and go back to menu feature using if else statement
*/
void Create(char temp_f[50],char filename[50],char temp_f2[50]){
	char choice1[50];
	while(1){
		
	banner();
	printf("\n\n\t\tCreate\n");
		
	printf("Enter Book name: ");
	fgets(Book.name,50,stdin);
	Book.name[strlen(Book.name)-1]= '\0';
	
		
		if(strcmp(Book.name,"")==0){
		break;
		}
		
		
		else if(strcmp(Book.name,"Exit")==0 || strcmp(Book.name,"exit")==0){
		exit(0);
		}
	
	
	printf("Enter Book author: ");
	fgets(Book.author,50,stdin);
	Book.author[strlen(Book.author)-1]= '\0';
	
	
		if(strcmp(Book.author,"")==0){
		break;
		}
		
		
		else if(strcmp(Book.author,"Exit")==0 || strcmp(Book.author,"exit")==0){
			exit(0);
		}
	
	printf("Enter Book year published: ");
	fgets(Book.year,50,stdin);
	Book.year[strlen(Book.year)-1]= '\0';


		if(strcmp(Book.year,"")==0){
		break;
		}
		
		
		else if(strcmp(Book.year,"Exit")==0 || strcmp(Book.year,"exit")==0){
		exit(0);
		}
	
	printf("Enter Book price: ");
	fgets(Book.price,50,stdin);
	Book.price[strlen(Book.price)-1]= '\0';
	
	
		if(strcmp(Book.price,"")==0){
		break;
		}
		
		
		else if(strcmp(Book.price,"Exit")==0 || strcmp(Book.price,"exit")==0){
		exit(0);
		}
	
	Format(temp_f,filename);
	Format_2nd(temp_f2);
	sprintf(temp_f,"%s",filename);
	
	FILE *fP = fopen(filename,"w");
	
		fprintf(fP,"Book name: %s \n",Book.name);
		fprintf(fP,"Book author: %s \n",Book.author);
		fprintf(fP,"Book year published: %s \n",Book.year);
		fprintf(fP,"Book price: %s \n",Book.price);
	
	fclose(fP);
	
	
	fopen("masterlist.dat","a");
		
		
		fprintf(fP,"%s|",Book.name);
		fprintf(fP,"%s|",Book.author);
		fprintf(fP,"%s|",Book.year);
		fprintf(fP,"%s|",Book.price);
		fprintf(fP,"%s|",filename);
		fprintf(fP,"%s|",temp_f2);
		fprintf(fP,"0|\n");
	
	fclose(fP);
	
	system("cls");
	
	banner();
	printf("\n|----File successfully created----|\n\n");
	
	printf("Do you still want to create another file? (yes or no): ");
	fgets(choice1,50,stdin);
	choice1[strlen(choice1)-1]= '\0';
	
		if(strcmp(choice1,"no")==0){
			break;
		}
	
	
		else if(strcmp(choice1,"")==0){
			break;
		}
	
	
		system("cls");
	}
		
}



/* This feature is use so that the Book's name and author turn into a single string
	that will be later used for the file name of the file */
char Format(char temp_f[50],char filename[50]){
	
	strncpy(filename,Book.name, sizeof(filename)-1);
	
	strcat(filename,"-");
	strcat(filename,Book.author);
	strcat(filename,".txt");
	
}



/* This feature is use format the filename differently, instead of a hyphen"-",
it is replaced with "by" for security purposes*/
char Format_2nd(char temp_f2[50]){
	
	strncpy(temp_f2,Book.name, sizeof(temp_f2)-1);
	
	strcat(temp_f2," by ");
	strcat(temp_f2,Book.author);
	
}



/* This feature is use check if the file already exist or not,
this function will be called in mostly all the other functions */
char Check(char temp_c1[50],char temp_c2[50]){
	while(1){
	
		banner();
		
		printf("\n\n\t\tCheck\n");
		printf("Enter the name of the Book: ");
		fgets(temp_c1,50,stdin);
		temp_c1[strlen(temp_c1)-1]= '\0';
		
		if(strcmp(temp_c1,"")==0){
	  		break;
		}
				  
				  
		else if(strcmp(temp_c1,"Exit")==0 || strcmp(temp_c1,"exit")==0){
	  		exit(0);
		}
	
	
		printf("Enter the author of the Book: ");
		fgets(temp_c2,50,stdin);
		temp_c2[strlen(temp_c2)-1]= '\0';
		
		if(strcmp(temp_c2,"")==0){
	  		break;
		}
				  
				  
		else if(strcmp(temp_c2,"Exit")==0 || strcmp(temp_c2,"exit")==0){
	  		exit(0);
		}
		
	
		strcat(temp_c1,"-");
		strcat(temp_c1,temp_c2);
		strcat(temp_c1,".txt");
	
	
	
			if(access(temp_c1,F_OK)==0){
				printf("\n\n|----File exist----|\n");
				system("pause");
				system("cls");
			}
	
	
			else{
				printf("\n\n|----File doesn't exist----|\n\n");
				system("pause");
				system("cls");
			}
			
			
			banner();
			
			printf("\nWant to read another file?(yes or no): ");
	  		fgets(go_menu,50,stdin);
	  		go_menu[strlen(go_menu)-1]= '\0';
	  		
	  		
	  			if(strcmp(go_menu,"no")==0){
	  				break;
				  }
				  
				  
				else if(strcmp(go_menu,"")==0){
	  				break;
				  }
				  
				  
				else if(strcmp(go_menu,"Exit")==0 || strcmp(go_menu,"exit")==0){
	  				exit(0);
				  }
			system("cls");
	}
	
}



/* This function is use to read an existing file with a feature of 
giving the user a choice to go back to menu or exit on every possible 
user input, it also prompts if the file didn't exist */
void Read(char temp_c1[50],char temp_c2[50]){
	while(1){
	
		banner();
		
		printf("\n\n\t\tCheck\n");
		printf("Enter the name of the Book: ");
		fgets(temp_c1,50,stdin);
		temp_c1[strlen(temp_c1)-1]= '\0';
		
		
		if(strcmp(temp_c1,"")==0){
	  		break;
		}
				  
				  
		else if(strcmp(temp_c1,"Exit")==0 || strcmp(temp_c1,"exit")==0){
	  		exit(0);
		}
		
	
		printf("Enter the author of the Book: ");
		fgets(temp_c2,50,stdin);
		temp_c2[strlen(temp_c2)-1]= '\0';
		
		
		if(strcmp(temp_c2,"")==0){
	  		break;
		}
				  
				  
		else if(strcmp(temp_c2,"Exit")==0 || strcmp(temp_c2,"exit")==0){
	  		exit(0);
		}
		
	
		strcat(temp_c1,"-");
		strcat(temp_c1,temp_c2);
		strcat(temp_c1,".txt");
	
	
	
			if(access(temp_c1,F_OK)==0){
				printf("\n\n|----File exist----|\n");
				printf("\n\n\tRead\n");
	
				FILE *fP = fopen(temp_c1,"r");
	
				char buffer[250];
		
		
					while(fgets(buffer,255,fP)!=NULL){
						printf("%s", buffer);
	  				}
	  				
	  		
	  			getchar();
	  			fclose(fP);
	  			system("cls");
	  			
			}
	
	
			else{
				printf("\n\n|----File doesn't exist----|\n\n");
				system("pause");
				system("cls");
				
			}
			system("cls");
			banner();
			
	  		printf("\nWant to read another file?(yes or no): ");
	  		fgets(go_menu,50,stdin);
	  		go_menu[strlen(go_menu)-1]= '\0';
	  		
	  		
	  			if(strcmp(go_menu,"no")==0){
	  				break;
				  }
				  
				  
				else if(strcmp(go_menu,"")==0){
	  				break;
				  }
				  
				  
				else if(strcmp(go_menu,"Exit")==0 || strcmp(go_menu,"exit")==0){
	  				exit(0);
				  }
				  
	
		system("cls");
	}
		
}



/* This function is use delete an existing file and delete
its content in the masterlist/booklist */
void Delete(char temp_c1[50], char temp_c2[50]) {
    while (1) {
        banner();

        printf("\n\n\t\tCheck\n");
        printf("Enter the name of the Book: ");
        fgets(temp_c1, 50, stdin);
        temp_c1[strlen(temp_c1) - 1] = '\0';

        if (strcmp(temp_c1, "") == 0) {
            break;
        }
        else if (strcmp(temp_c1, "Exit") == 0 || strcmp(temp_c1, "exit") == 0) {
            exit(0);
        }

        printf("Enter the author of the Book: ");
        fgets(temp_c2, 50, stdin);
        temp_c2[strlen(temp_c2) - 1] = '\0';

        if (strcmp(temp_c2, "") == 0) {
            break;
        }
        else if (strcmp(temp_c2, "Exit") == 0 || strcmp(temp_c2, "exit") == 0) {
            exit(0);
        }

        strcat(temp_c1, "-");
        strcat(temp_c1, temp_c2);
        strcat(temp_c1, ".txt");

        if (remove(temp_c1) == 0) {
            printf("\n\n|----File deleted----|\n");

            
            FILE *fP = fopen("masterlist.dat", "r");
            FILE *tempFile = fopen("temp_masterlist.dat", "w");

            if (fP == NULL || tempFile == NULL) {
                printf("Error opening file.\n");
                exit(1);
            }

            char line[500];
            while (fgets(line, sizeof(line), fP)) {


                if (strstr(line, temp_c1) == NULL) {
                    fputs(line, tempFile);
                }
            }

            fclose(fP);
            fclose(tempFile);


            remove("masterlist.dat");
            rename("temp_masterlist.dat", "masterlist.dat");

            system("pause");
            system("cls");
        }
        
        
        else {
            printf("\n\n|----File doesn't exist----|\n\n");
            system("pause");
            system("cls");
        }


        system("cls");
        banner();

        printf("\nWant to delete another file? (yes or no): ");
        fgets(go_menu, 50, stdin);
        go_menu[strlen(go_menu) - 1] = '\0';

        if (strcmp(go_menu, "no") == 0) {
            break;
        }
        else if (strcmp(go_menu, "") == 0) {
            break;
        }
        else if (strcmp(go_menu, "Exit") == 0 || strcmp(go_menu, "exit") == 0) {
            exit(0);
        }
        system("cls");
    }
}



/* This function is use to display the available books to the user */
void Booklist() {
	FILE *fP = fopen("masterlist.dat", "r");


    if (fP == NULL) {
        printf("Error opening masterlist file.\n");
        return;
    }

    printf("\t\tBooklist\n");
    char line[500];
    int bookNumber = 1;
    
    
    while (fgets(line, sizeof(line), fP)) {
        char bookName[100] = "";
        char bookAuthor[100] = "";
        char temp_f2[100] = "";
        int spaceCount = 0;

        int i = 0;
        while (line[i] != '\0') {
            if (line[i] == '|') {
                spaceCount++;
                if (spaceCount == 1) {
                    break;
                }
            } else {
                strncat(bookName, &line[i], 1);
            }
            i++;
        }

        spaceCount = 0;
        i++; 
        while (line[i] != '\0') {
            if (line[i] == '|') {
                spaceCount++;
                if (spaceCount == 1) {
                    break;
                }
            } else {
                strncat(bookAuthor, &line[i], 1);
            }
            i++;
        }

	char string1[50];
	char string2[50];
	
	strcpy(string1,bookName);
	strcpy(string2,bookAuthor);
	strcat(string1," by ");
	strcat(string1,string2);
	
		printf("Book %d: %s \n",bookNumber,string1);
        printf("Book Title: %s\n", bookName);
        printf("Book author: %s\n", bookAuthor);
        printf("------------------------------\n");
        
        bookNumber++;
    }

    fclose(fP);
    }
    
    
    
/*this function will ask the user for the book title and author
on the book that the user wants to change, after that the program  will
ask the user of which part of the file he wants to change, with every 
possible inputs of the user will have a choice of going back to menu or exit */
void Update(char temp_c1[50], char temp_c2[50]) {
    while (1) {
        
        banner();
		Booklist();
		
        printf("\n\n\t\tUpdate\n");
        printf("Enter the title of the Book: ");
        fgets(temp_c1, 50, stdin);
        temp_c1[strlen(temp_c1) - 1] = '\0';

        if (strcmp(temp_c1, "") == 0) {
            break;
        }
        else if (strcmp(temp_c1, "Exit") == 0 || strcmp(temp_c1, "exit") == 0) {
            exit(0);
        }

        printf("Enter the author of the Book: ");
        fgets(temp_c2, 50, stdin);
        temp_c2[strlen(temp_c2) - 1] = '\0';

        if (strcmp(temp_c2, "") == 0) {
            break;
        }
        else if (strcmp(temp_c2, "Exit") == 0 || strcmp(temp_c2, "exit") == 0) {
            exit(0);
        }

        strcat(temp_c1, "-");
        strcat(temp_c1, temp_c2);
        strcat(temp_c1, ".txt");

        if (access(temp_c1, F_OK) == 0) {
            printf("\n\n|----File exist----|\n");
            system("pause");
            system("cls");
            printf("\n\n\tUpdate\n");

            FILE *fP = fopen(temp_c1, "r");

            
            char bookDetails[4][50];
            int i = 0;
            while (fgets(bookDetails[i], sizeof(bookDetails[i]), fP)) {
                bookDetails[i][strlen(bookDetails[i]) - 1] = '\0';
                i++;
            }
            fclose(fP);

            
            printf("This is the contents of the book you want to update:\n");
            printf("1. %s\n", bookDetails[0]);
            printf("2. %s\n", bookDetails[1]);
            printf("3. %s\n", bookDetails[2]);
            printf("4. %s\n", bookDetails[3]);

            
            printf("\nEnter the number of the detail to update (1-4), or 'Exit' to return menu: ");
            char updateChoice[10];
            fgets(updateChoice, sizeof(updateChoice), stdin);
            updateChoice[strlen(updateChoice) - 1] = '\0';

            if (strcmp(updateChoice, "Exit") == 0 || strcmp(updateChoice, "exit") == 0) {
                break;
            }

            int detailNumber = atoi(updateChoice);
            if (detailNumber >= 1 && detailNumber <= 4) {
                printf("Enter new value for detail %d: ", detailNumber);
                fgets(bookDetails[detailNumber - 1], sizeof(bookDetails[detailNumber - 1]), stdin);
                bookDetails[detailNumber - 1][strlen(bookDetails[detailNumber - 1]) - 1] = '\0';
            }
            else {
                printf("Invalid choice. Please try again.\n");
                continue;
            }

            
            fP = fopen(temp_c1, "w");
            for (i = 0; i < 4; i++) {
                fprintf(fP, "%s\n", bookDetails[i]);
            }
            fclose(fP);

            printf("Book details updated.\n");
            system("pause");
            system("cls");
        }
        else {
            printf("\n\n|----File doesn't exist----|\n\n");
            system("pause");
            system("cls");
        }

        banner();

        printf("\nWant to update another file? (yes or no): ");
        fgets(go_menu, 50, stdin);
        go_menu[strlen(go_menu) - 1] = '\0';

        if (strcmp(go_menu, "no") == 0) {
            break;
        }
        else if (strcmp(go_menu, "") == 0) {
            break;
        }
        else if (strcmp(go_menu, "Exit") == 0 || strcmp(go_menu, "exit") == 0) {
            exit(0);
        }

        system("cls");
    }
}


/*this function will prompt if the file existed or not, after that 
it will proceed on it's function renaming a filename, with every 
possible input of the user has a choices to go back to menu or exit the program */
void Rename(){
	while(1){
		char temp[50];
		char file_path[50];
		
		banner();
	
		printf("Enter filename you want to rename: ");
		fgets(temp,50,stdin);
		temp[strlen(temp)-1]= '\0';
		
		
			if (strcmp(temp, "") == 0) {
            	break;
        	}
        	
        	
       	 	else if (strcmp(temp, "Exit") == 0 || strcmp(temp, "exit") == 0) {
           	 	exit(0);
        	}
	
		sprintf(file_path, "%s", temp);
	
	
			if(access(file_path,F_OK)==0){
				char newtemp[50];
				printf("File exist\n\n");
			
				printf("Enter new file name: ");
				fgets(newtemp,50,stdin);
				newtemp[strlen(newtemp)-1]= '\0';
				
				
					if (strcmp(newtemp, "") == 0) {
           				 break;
       				}
       				
       				
        			else if (strcmp(newtemp, "Exit") == 0 || strcmp(newtemp, "exit") == 0) {
            			 exit(0);
        			}
			
				rename(temp,newtemp);
				printf("File renamed successfully! \n\n");
			}
	
	
			else{
			
				printf("File doesn't exist\n");	
				exit(0);
			}
			
			printf("\nWant to update another file? (yes or no): ");
        	fgets(go_menu, 50, stdin);
        	go_menu[strlen(go_menu) - 1] = '\0';


       			 if (strcmp(go_menu, "no") == 0) {
           			 break;
        		 }
        		 
        		 
        		 else if (strcmp(go_menu, "") == 0) {
            		 break;
        		 }
        		 
        		 
        		 else if (strcmp(go_menu, "Exit") == 0 || strcmp(go_menu, "exit") == 0) {
            		 exit(0);
        		 }

        system("cls");
	}
}


