#include "datatypes.h"
//nguyen mau ham
void startMenu();
void menuAdmin();
void checkId( char *Id,int  *countId,int numberOfUser,struct User users[]);
void checkName(char *name,int *countName,int numberOfUser,struct User users[]);
void checkEmail(char *email, int *countEmail, int numberOfUser,struct User users[]);
void checkPhone(char *phone,int  *countPhone,int numberOfUser,struct User users[]);
void checkUserName(char *userName,int *countUserName,int numberOfUser,struct User users[]);

void addNewUser(int *length, struct User users[], struct AccountInfo accountInfo[]);
void writeUserToFile(int numberOfUser, struct User users[]);
void writeAccountInfoToFile(int *length, struct AccountInfo accountInfo[]);
void readUserFromFile(int *length, struct User users[]);
void printfUser(int *length, struct User users[]);
void searchId(int *length, struct User users[],struct AccountInfo accountInfo[]);
void lockOrUnlockUser(int *length, struct User users[],struct AccountInfo accountInfo[]);
void searchName(int *length, struct User users[], struct AccountInfo accountInfo[]);
void sortMenu();
void sortAscending(int *length, struct User users[]);
void sortDescending(int *length, struct User users[]);
bool isValidUser(int *length, struct User users[]);
void exitTheProgram();
void exitMenu();
 


