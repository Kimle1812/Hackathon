#include <stdio.h>
#include <stdbool.h> 
#include <stdlib.h> 
#include "functions.h"
#include <string.h>
#include <ctype.h>

//logic ham
void startMenu(){
	printf("\n***** Bank Management System Using C *****\n");
    printf("==========================================\n");
    printf("=======            MENU            =======\n");
    printf("==========================================\n");
    printf("[1] Admin\n");
    printf("[2] User\n");
    printf("[0] Exit the Program\n");
    printf("==========================================\n");
}

void menuAdmin(){
	system("cls");
	printf("\n***** Bank Management System Using C *****\n");
    printf("==========================================\n");
    printf("=======         ADMIN MENU         =======\n");
    printf("==========================================\n");
    printf("[1] Add A New User\n");
    printf("[2] Show All Users\n");
    printf("[3] Show Detail of a User\n");
    printf("[4] Lock (Unlock) a User\n");
    printf("[5] Sort the user list\n");
    printf("[6] Search for users by name\n");
    printf("[0] Exit\n");
    printf("==========================================\n");
}
void exitMenu(){
	char option;
    while(option != 'b' && option != 'B' && option != '0'){
    	printf(" Go back (b) or Exit (0):");
    	scanf(" %c", &option);
        getchar();
    	if (option == 'b' || option == 'B') { 
    		break; 
    	} else if (option == '0'){
        	exitTheProgram();
			exit(0);	 
    	} else {
    		printf("Invalid choice! Please select again!");
		} 
	} 
    
} 
void exitTheProgram(){
	system("cls");
	printf("\n========= Thank you =========\n");
	printf("========= See you soon=======\n");
}

void checkId(char *Id,int  *countId,int numberOfUser,struct User users[]) {
    *countId=0;
    int lengthId = strlen(Id);

    if (lengthId!=10){
        *countId = *countId + 1;
        printf("ID must be exactly 10 characters long.\n");
        return;  
    }
    
    for (int i = 0; i < lengthId; i++) {
        if (!isdigit(Id[i])) {
            *countId = *countId + 1;
            printf("ID must contain only digits.\n");
            return;  
        }
    }
    if(Id == " "){
    	printf("Id must not contain spaces\n");
    	*countId = *countId + 1;
    	return; 
	} 
    for(int i = 0;i < numberOfUser ;i++){
		if(strcmp(users[i].userId,Id)==0){
			printf("User ID already exists.\n");
			*countId+=1;
			return;
		}
    		
	}
} 
void checkName(char *name,int *countName,int numberOfUser,struct User users[]){
	*countName = 0;
    int lengthName = strlen(name);
    if (lengthName > 21 || lengthName < 1){ 
    	printf("Username must not exceed 20 characters\n");
        *countName = 1;
        return;
    }
    for (int  i = 0; i < lengthName; i++){
        if (!isalpha(name[i]) && name[i] != ' ') {
        	*countName = 2 ;
        	printf("Username can not be a number\n");
            return;
        }
    }
    for(int i = 0; i < numberOfUser; i++){
    	if(strcmp(users[i].name, name)==0){
    		printf("Username already exists.\n");
    		*countName = 3;
    		return;
		}
	}
}
void checkEmail(char *email, int *countEmail, int numberOfUser,struct User users[]){
	*countEmail=0;
	int lengthEmail = strlen(email);
	if(lengthEmail < 11 || lengthEmail > 49){
		printf("The email length is too large.\n");
		*countEmail = 1;
		return;
	}	
	if(strstr(email,"@gmail.com")==NULL){
		printf("Error: wrong email format(.......@gmail.com)\n");
		*countEmail = 2;
		return;
	}
	for(int i = 0 ; i < numberOfUser; i++){
    	if(strcmp(users[i].email,email)==0){
    		*countEmail = 3;
    		printf("Error: email number already exists.\n");
    		return;
		}
	}
}
void checkPhone(char *phone,int  *countPhone,int numberOfUser,struct User users[]) {
    *countPhone = 0;
    int lengthPhone = strlen(phone);

    if (lengthPhone != 9) {
        *countPhone = 1;
        printf("Error: Phone must be exactly 9 characters long.\n");
        return;  
    }

    for (int i = 0; i < lengthPhone; i++) {
        if (!isdigit(phone[i])) {
            *countPhone = 2;
            printf("Error: Phone must contain only digits.\n");
            return;  
        }
    } 
    for( int i = 0 ; i < numberOfUser;i++){
    	if(strcmp(users[i].phone, phone) == 0){
    		*countPhone = 3;
    		printf("Error: Phone number already exists.\n");
    		return;
		}
	}
}
void checkUserName(char *userName,int *countUserName,int numberOfUser,struct User users[]){
	*countUserName = 0;
    int lengthUserName = strlen(userName);
    if (lengthUserName> 11 || lengthUserName < 1){ 
    	printf("Username must not exceed 20 characters\n");
        *countUserName = 1;
        return;
    }
    for(int i = 0; i < numberOfUser; i++){
    	if(strcmp(users[i].username, userName)==0){
    		printf("Username already exists.\n");
    		*countUserName = 3;
    		return;
		}
	}
}
void addNewUser(int *length, struct User users[], struct AccountInfo accountInfo[]) {
    system("cls");
    int numberOfUser;
    int gender;
    int errorCount = 0; 
    printf("\nEnter the number of users you want to add: ");
    scanf("%d", &numberOfUser);
    getchar();
    printf("==========================================\n");
    printf("=======       Add A New User       =======\n");
    printf("==========================================\n");

    for (int i = *length; i < (*length + numberOfUser); i++) {
		bool validId = false;
        printf("\nEnter the user %d:\n", i);
        do{
			printf("Enter the ID: ");
            scanf("%s", users[i].userId);
            getchar();
        	checkId(users[i].userId, &errorCount, numberOfUser, users);	
		}while(errorCount!=0);
		errorCount = 0;
		
        do{
			printf("Enter the name: ");
        	fgets(users[i].name, sizeof(users[i].name), stdin);
        	users[i].name[strcspn(users[i].name, "\n")] = '\0';
        	checkName(users[i].name, &errorCount, numberOfUser, users);
		}while(errorCount != 0);
		errorCount = 0;
		
		do{
        	 printf("Enter the email: ");
        	fgets(users[i].email, sizeof(users[i].email), stdin);
        	users[i].email[strcspn(users[i].email, "\n")] = '\0';
        	checkEmail(users[i].email, &errorCount,numberOfUser, users);
		} while(errorCount!=0);
		errorCount = 0;
		
		do{
			printf("Enter the phone: ");
        	scanf("%s", users[i].phone);
            getchar();
        	checkPhone(users[i].phone, &errorCount, numberOfUser, users);
		}while(errorCount!=0);
		errorCount = 0;
		
		do{
			printf("Enter the username: ");
        	fgets(users[i].username, sizeof(users[i].username), stdin);
        	users[i].username[strcspn(users[i].username, "\n")] = '\0';
        	checkUserName(users[i].username, &errorCount, numberOfUser, users);
		} while(errorCount!=0);

        while (1) {
            printf("Enter the gender (1: Male, 2: Female): ");
            scanf("%d", &gender);
            getchar();
            if (gender == 1) {
                users[i].gender = true; // Male
                break;
            } else if (gender == 2) {
                users[i].gender = false; // Female
                break;
            } else {
                printf("Invalid choice. Please select again.\n");
            }
        }

        printf("Enter the date of birth:\n");
        printf("+\tEnter the day: ");
        scanf("%d", &users[i].dateOfBirth.day);
        getchar();

        printf("+\tEnter the month: ");
        scanf("%d", &users[i].dateOfBirth.month);
        getchar();

        printf("+\tEnter the year: ");
        scanf("%d", &users[i].dateOfBirth.year);
        getchar();

        printf("Enter the balance: ");
        scanf("%lf", &accountInfo[i].balance);
        getchar();
		
        printf("Status: %s\n", accountInfo[i].status ? "Lock" : "Unlock");
    }
	
    *length += numberOfUser;
    writeUserToFile(numberOfUser, &users[*length - numberOfUser]);
    //accountInfo[i].status = false; 
	writeAccountInfoToFile(numberOfUser, &users[*length - numberOfUser]);
    printf("==========================================\n");
    printf("User(s) added successfully!\n");
    exitMenu();
}

void writeUserToFile(int numberOfUser, struct User users[]) {
    FILE *file = fopen("BankUser.dat", "ab");
	if (file == NULL) {
    	perror("Error opening file");
    	return;
	}
	int written = fwrite(users, sizeof(struct User), numberOfUser, file);
	if (written != numberOfUser) {
    	printf("Error writing to file\n");
	}
    fclose(file);
}

void writeAccountInfoToFile(int *length, struct AccountInfo accountInfo[]) {
    FILE *file = fopen("AccountInfoUser.dat", "wb");
	if (file == NULL) {
    	perror("Error opening file");
    	return;
	}
	int written = fwrite(accountInfo, sizeof(struct AccountInfo), length, file);
	if (written != length) {
    	printf("Error writing to file\n");
	}
    fclose(file);
}


void printfUser(int *length, struct User users[]) {
    printf("|================================================================================================|\n");
    printf("                                    User Information\n");
    printf("|================================================================================================|\n");
    printf("+------------+----------------------+------------+------------+----------------------+-----------+\n");
    printf("| User ID    | Name                 | Gender     | Phone      | Email                | Status    |\n");
    printf("+------------+----------------------+------------+------------+----------------------+-----------+\n");
    for (int i = 0; i < *length; i++) {
        printf("| %-10s | %-20s | %-10s | %-10s | %-20s | %-9s |\n",
		users[i].userId,
		users[i].name,
		users[i].gender ? "Male" : "Female",
		users[i].phone, users[i].email,
		accountInfo[i].status ? "Lock" : "Unlock");
    }
    printf("+------------+----------------------+------------+------------+----------------------+\n");
    printf("\n");

}

void readUserFromFile(int *length, struct User users[]){
	system("cls");
	FILE *file = fopen("BankUser.dat", "rb");
	if(file == NULL){
		printf("Error opening file\n");
	}
	*length = fread(users, sizeof(struct User), 100, file);
    if(*length == 0){
        printf("No data found...\n");
    }else{
        printf("Read %d user from file\n", *length);
    }
    printfUser(length, users);
    fclose(file);
    exitMenu();
}

void searchId(int *length, struct User users[], struct AccountInfo accountInfo[]) {
	system("cls");
    bool value = false;
    char searchId [10]; 
    FILE *file = fopen("BankUser.dat", "rb");
    FILE *file1 = fopen("AccountInfoUser.dat", "rb");
	if(file == NULL){
		printf("Error opening file\n");
	}
	*length = fread(users, sizeof(struct User), 100, file);
    if(*length == 0){
        printf("No data found...\n");
    }
    printf("\nEnter the user ID you want to display:\n");
    scanf("%s", &searchId);
	getchar(); 
    for (int i = 0; i < *length; i++) {
        if (strcmp(users[i].userId, searchId) == 0) {
        	printf("|================================================================================================|\n");
    		printf("                              User Information\n");
    		printf("|================================================================================================|\n");
    		printf("+------------+----------------------+------------+------------+----------------------+-----------+\n");
    		printf("| User ID    | Name                 | Gender     | Phone      | Email                | Status    |\n");
    		printf("+------------+----------------------+------------+------------+----------------------------------+\n");
        	printf("| %-10s | %-20s | %-10s | %-10s | %-20s | %-9s |\n",
				users[i].userId,
				users[i].name,
				users[i].gender ? "Male" : "Female",
				users[i].phone, users[i].email,
				accountInfo[i].status ? "Lock" : "Unlock");
    		printf("+------------+----------------------+------------+------------+----------------------+-----------+\n");
    		printf("\n");
            value = true;
            break;
        }
    }
    if (!value) {
        printf("No user found with the ID: %s\n", searchId);
    }
    exitMenu();
    fclose(file);
}

void lockOrUnlockUser(int *length, struct User users[], struct AccountInfo accountInfo[]){
	system("cls");
	printf("***** Lock (Unlock) an user *****\n");
	char searchId [20];
	char option;
	int valid = 1; 
	FILE *file = fopen("BankUser.dat", "rb");
	if(file == NULL){
		printf("Error opening file\n");
		return;
	}
	*length = fread(users, sizeof(struct User), 100, file);
	fread(accountInfo, sizeof(struct AccountInfo), 100, file);
	if(*length == 0){
		printf("No data found...\n");
	}
	printf("\nEnter the user ID you want to display: ");
	scanf("%s", &searchId);
	fflush(stdin);
	for (int i = 0; i < *length; i++) {
		if (strcmp(users[i].userId, searchId) == 0) {
			valid = 0; 
			printf("One user was found for id: %s\n", searchId);
			if(accountInfo[i].status == false){
				printf("User's status was unlocked, lock user?\n");
				printf("Yes(y)? or No(n)?: ");
				scanf(" %c", &option);
				if (option == 'y' || option == 'Y') {
					accountInfo[i].status = true;
					writeAccountInfoToFile(*length, accountInfo);
					printf("Lock user successful\n");
					exitMenu();
				} else {
					exitMenu();
				}
			} else if(accountInfo[i].status == true) {
				printf("User's status was locked, unlock user?\n");
				printf("Yes(y)? or No(n)?: ");
				scanf(" %c", &option);
				if (option == 'y' || option == 'Y') {
					accountInfo[i].status = false;
					writeAccountInfoToFile(*length, accountInfo);
					printf("Unlock user successful\n");
					exitMenu();
				} else {
					exitMenu();
				}
			} else{
				exitMenu();
			}
		}
	}
	if(valid != 0){
		printf("No user was found for id: %s\n", searchId);
	}
	exitMenu();
	fclose(file);
}

void searchName(int *length, struct User users[], struct AccountInfo accountInfo[]) {
	system("cls");
    FILE *file = fopen("BankUser.dat", "rb");
	FILE *file1 = fopen("AccountInfoUser.dat", "rb");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }

    *length = fread(users, sizeof(struct User), 100, file);
    if (*length == 0) {
        printf("No data found...\n");
        return;
    }
	bool value = false;
    char searchName[20];
    fflush(stdin); 
    printf("\nEnter the user name you want to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';
    
    for (int i = 0; i < *length; i++) {
        if (strcmp(users[i].name, searchName) == 0) {
            printf("|================================================================================================|\n");
    		printf("                              User Information\n");
    		printf("|================================================================================================|\n");
    		printf("+------------+----------------------+------------+------------+----------------------+-----------+\n");
    		printf("| User ID    | Name                 | Gender     | Phone      | Email                | Status    |\n");
    		printf("+------------+----------------------+------------+------------+----------------------------------+\n");
        	printf("| %-10s | %-20s | %-10s | %-10s | %-20s | %-9s |\n",
				users[i].userId,
				users[i].name,
				users[i].gender ? "Male" : "Female",
				users[i].phone, users[i].email,
				accountInfo[i].status ? "Lock" : "Unlock");
    		printf("+------------+----------------------+------------+------------+----------------------+-----------+\n");
    		printf("\n");
            value = true;
            break;
        }
    }

    if (!value) {
        printf("No user found with the name: %s\n", searchName);
    }
	exitMenu();
    fclose(file);
}

void sortMenu(){
	system("cls");
	printf("\n***** Bank Management System Using C *****\n");
    printf("==========================================\n");
    printf("=======          SORT MENU         =======\n");
    printf("==========================================\n");
    printf("[1] Ascending\n");//tang dan
    printf("[2] Descending\n");//giam dan
    printf("[0] Exit\n");
    printf("==========================================\n");
} 
void sortAscending(int *length, struct User users[]){
	system("cls");
	FILE *file = fopen("BankUser.dat", "rb");
	if(file == NULL){
		printf("Error opening file\n");
	}
	*length = fread(users, sizeof(struct User), 100, file);
    if(*length == 0){
        printf("No data found...\n");
    }
	for (int i = 0; i < *length - 1; i++) {
        for (int j = i + 1; j < *length; j++) {
            if (strcmp(users[i].name, users[j].name) > 0) {
                struct User temp = users[i];
				users[i] = users[j];
				users[j] = temp;
            }
        }
    }
    printfUser(length, users);
	exitMenu();
	fclose(file); 
}

void sortDescending(int *length, struct User users[]){
	system("cls");
	FILE *file = fopen("BankUser.dat", "rb");
	if(file == NULL){
		printf("Error opening file\n");
	}
	*length = fread(users, sizeof(struct User), 100, file);
    if(*length == 0){
        printf("No data found...\n");
    }
	for (int i = 0; i < *length - 1; i++) {
        for (int j = i + 1; j < *length; j++) {
            if (strcmp(users[i].name, users[j].name) < 0) {
                struct User temp = users[i];
				users[i] = users[j];
				users[j] = temp;
            }
        }
    }
    printfUser(length, users);
	exitMenu();
	fclose(file); 
}

