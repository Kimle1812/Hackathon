#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int numberOfUser;
	int length;
	int choice, choice1, choice2, option;
	do{
		startMenu();
		printf("Enter The Choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 1://Admin
				do {
					menuAdmin();
					printf("Enter The Choice: ");
					scanf("%d", &choice1);
					switch(choice1){
						case 1://Add A New User
							addNewUser(&length, users, accountInfo);
							break;
						case 2://Show All Users
							readUserFromFile(&numberOfUser, users);
							break;
						case 3://Show Detail of a User
							searchId(&length, users, accountInfo);
							break;
						case 4://Lock (Unlock) a User
							lockOrUnlockUser(&length, users, accountInfo);
							break;
						case 5://Sort the user list
							do {
								sortMenu();
								printf("Enter the choice:");
    							scanf("%d", &option);
    							switch(option){
    							case 1:
    								sortAscending(&length, users);
    								break;
    							case 2:
    								sortDescending(&length, users);
    								break;
    							case 0:
    								printf("Back Menu!");
    								break;
    							default:
    								printf("Invalid choice! Please select again!");
								}
							}while(option != 0);
							break;
						case 6://Search for users by name
							searchName(&length, users, accountInfo);
							break;
						case 0:
							printf("Back Menu!");
							break;
						default:
							printf("Invalid choice! Please select again!");
					}
				} while(choice1 != 0);
			case 2://User
				break;
			case 0:
				exitTheProgram();
				break;
			default:
				printf("Invalid choice! Please select again!");
		} 
	} while(choice != 0); 
	
	return 0;
}
