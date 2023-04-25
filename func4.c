#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "header4.h"
#define MAX 100
typedef char str20[21];
typedef char str30[31];
typedef char str10[11];

/* getString accepts the user input with spaces
	@param string - string inputted by the user
	@param n - maximum number if characters
	@returns nothing
*/
void 
getString (char string[], 
			int n)
{
	scanf("\n%[^\n]%*c", string); // accepst input with spaces
	
	while ((strlen(string)) > n)
	{
		printf("Input has exceeded maximum number of characters. Please try again. \n");
		printf("Input: ");
		scanf("\n%[^\n]%*c", string);
	}
	
}

/* vaxRegMenu returns the choice of the user
	@returns choice picked by the user
	Pre-condition: input only contains integers
*/
int 
vaxRegMenu () // vax registration menu
{
    int vaxChoice;

    printf("Vaccination Registration Menu \n");
	
	printf("\n");
	
	printf("[1] User Registration\n");
	printf("[2] Vaccination Appointment\n");
	printf("[3] Chatbot FAQs\n");
	printf("[4] Exit\n");
	
	printf("\n");
	
	printf("Enter option (1/2/3/4): ");
	scanf("%d", &vaxChoice);             // gets user input

    while (vaxChoice > 4 || vaxChoice < 1)
    {
        printf("Invalid input. Please choose from the following options (1/2/3/4): ");
        scanf("%d", &vaxChoice);             // gets user input
    }

	system("cls");

    return vaxChoice;
}

/* 	mainMenu returns the choice of the user
	@returns choice picked by the user
	Pre-condition: input only contains integers
*/

int 
mainMenu () // asks user to pick a menu
{
	int mainChoice; 

	printf("\t\t\t\t Welcome to the Vaccine Registration with Chatbot App!\n");
	
	printf("\n\n\n");
	
	printf("\t\t\t\t\t[1] Vaccine Registration Menu\n");
	printf("\t\t\t\t\t[2] Data Management Menu\n");
	printf("\t\t\t\t\t[3] Exit\n");
	
	printf("\n");
	printf("\t\t\t\t\t Please choose an option: ");
	scanf("%d", &mainChoice);

    while (mainChoice > 3 || mainChoice < 1)
    {
        printf("\t\t\t\tInvalid input. Please choose from the following options (1/2/3): ");
        scanf("%d", &mainChoice);
    }
	
	system("cls");

	return mainChoice;
	
}

/* 	userReg lets the user input their personal information
	@param user1[] - struct containing the user data
	@param *k - number of registered users/index for the user struct arrays
 	@returns nothing
	Pre-condition: inputs correspond with the data type being asked
*/

void 
userReg(struct userInfo user1[], 
		int *k)  // gets the input for the user info
{
	int j;
	char ch;
	char sexx;
	int vax, check, valid;
	
	printf("\n");
	
	printf("Please enter the following information: \n");
			
			printf("\n");
			
			printf("userID: ");
			scanf("%lf", &user1[*k].userID);

			while (user1[*k].userID < 1000 || user1[*k].userID > 999999999)
			{
				printf("Invalid input. Input must be at least 4 digits. Please try again.\n");
				printf("userID: ");
				scanf("%lf", &user1[*k].userID);
			}

			if (k > 0)
			{
				check = checkID(user1, *k);
				
				while (check == 1)
				{
					printf("USER ID is already taken. Please try again.\n");
					printf("userID: ");
					scanf("%lf", &user1[*k].userID);
					while (user1[*k].userID < 1000 || user1[*k].userID > 999999999)
					{
						printf("Invalid input. Input must be at least 4 digits. Please try again.\n");
						printf("userID: ");
						scanf("%lf", &user1[*k].userID);
					}

					check = checkID(user1, *k);
				}

			}
						
			printf("Password: ");
   
 		for(j=0;j<10;j++)  // prints an asterisk when the user types the password
 		{	ch = getch();
  			user1[*k].passWord[j] = ch;
  			ch = '*' ;
  			printf("%c",ch);
 		}

	printf("\n");
	
	printf("Name: ");
	getString (user1[*k].name, 20);

	printf("Address: ");
	getString (user1[*k].address, 30);

	printf("Contact: ");
	scanf("%lf", &user1[*k].contact);

	printf("Sex (M/F): ");
	scanf(" %c", &sexx);

	while (sexx != 'm' && sexx != 'M' && sexx != 'f' && sexx != 'F')
	{
		printf("Invalid input. Please try again. \n");
		printf("Sex (M/F): ");
		scanf(" %c", &sexx);
	};

	userSex (user1, k, sexx);


	printf("\nHow many doses of vaccine have you already received? \n");
	printf("\n");

	printf("[1] 1st dose \n");
	printf("[2] 1st and 2nd dose \n");
	printf("[3] 1st, 2nd, and booster dose \n");

	printf("\n");

	printf("Input: ");
	scanf("%d", &vax);

	while (vax > 3 || vax < 1)
	{
		printf("Invalid input. Please try again: ");
		scanf("%d", &vax);
	}
	

	switch (vax)
	{
		case 1: 
		{
			printf("Date of first vaccine dose: \n");
			
			toString (user1, *k);

			printf("First Vaccine Dose: ");
			getString(user1[*k].firstVax, 10);

			valid = vaccineValid(user1[*k].firstVax);

			while (valid == 0)
			{
				printf("Input not recognized. Please try again.\n\n");
				printf("First Vaccine Dose: ");
				getString(user1[*k].firstVax, 10);
				valid = vaccineValid(user1[*k].firstVax);
			}

			printf("First Vaccine Dose Location: ");
			getString(user1[*k].firstLoc, 10);

			strcpy(user1[*k].dose.secDate, "N/A");
			strcpy(user1[*k].dose.secVax, "N/A");
			strcpy(user1[*k].dose.secLoc, "N/A");
			strcpy(user1[*k].dose.booDate, "N/A");
			strcpy(user1[*k].dose.booVax, "N/A");
			strcpy(user1[*k].dose.booLoc, "N/A");

            printf("\n");

			user1[*k].doses = 1;

		}break;

		case 2: 
		{
			printf("Date of first vaccine dose: \n");
			toString (user1, *k);
	
			printf("First Vaccine Dose: ");
			getString(user1[*k].firstVax, 10);

			valid = vaccineValid(user1[*k].firstVax);

			while (valid == 0)
			{
				printf("Input not recognized. Please try again.\n\n");
				printf("First Vaccine Dose: ");
				getString(user1[*k].firstVax, 10);
				valid = vaccineValid(user1[*k].firstVax);
			}

			printf("First Vaccine Dose Location: ");
			getString(user1[*k].firstLoc, 10);

            printf("\n");

			printf("Date of second vaccine dose: \n");
			toStringSec(user1, *k);

			printf("Second Vaccine Dose: ");
			getString(user1[*k].dose.secVax, 10);

			valid = vaccineValid(user1[*k].dose.secVax);

			while (valid == 0)
			{
				printf("Input not recognized. Please try again.\n\n");
				printf("Second Vaccine Dose: ");
				getString(user1[*k].dose.secVax, 10);
				valid = vaccineValid(user1[*k].dose.secVax);
			}

			printf("Second Vaccine Dose Location: ");
			getString(user1[*k].dose.secLoc, 10);

			strcpy(user1[*k].dose.booDate, "N/A");
			strcpy(user1[*k].dose.booVax, "N/A");
			strcpy(user1[*k].dose.booLoc, "N/A");

            printf("\n");

			user1[*k].doses = 2;


		} break;

		case 3: 
		{
			printf("Date of first vaccine dose: \n");
			toString (user1, *k);
	
			printf("First Vaccine Dose: ");
			getString(user1[*k].firstVax, 10);

			valid = vaccineValid(user1[*k].firstVax);

			while (valid == 0)
			{
				printf("Input not recognized. Please try again.\n\n");
				printf("First Vaccine Dose: ");
				getString(user1[*k].firstVax, 10);
				valid = vaccineValid(user1[*k].firstVax);
			}

			printf("First Vaccine Dose Location: ");
			getString(user1[*k].firstLoc, 10);

            printf("\n");

			printf("Date of second vaccine dose: \n");
			toStringSec(user1, *k);

			printf("Second Vaccine Dose: ");
			getString(user1[*k].dose.secVax, 10);

			valid = vaccineValid(user1[*k].dose.secVax);

			while (valid == 0)
			{
				printf("Input not recognized. Please try again.\n\n");
				printf("Second Vaccine Dose: ");
				getString(user1[*k].dose.secVax, 10);
				valid = vaccineValid(user1[*k].dose.secVax);
			}

			printf("Second Vaccine Dose Location: ");
			getString(user1[*k].dose.secLoc, 10);

            printf("\n");

			printf("Date of vaccine booster dose: \n");
			toStringBoo(user1, *k);

			printf("Booster Vaccine Dose: ");
			getString(user1[*k].dose.booVax, 10);

			valid = vaccineValid(user1[*k].dose.booVax);

			while (valid == 0)
			{
				printf("Input not recognized. Please try again.\n\n");
				printf("Booster Vaccine Dose: ");
				getString(user1[*k].dose.booVax, 10);
				valid = vaccineValid(user1[*k].dose.booVax);
			}

			printf("Booster Vaccine Dose Location: ");
			getString(user1[*k].dose.booLoc, 10);

            printf("\n");

			user1[*k].doses = 3;

		} break;
	}


	system("cls");

	printf("\n");

    printf("Congratulations! You have successfully registered in the Vaccination Registration App. \n");

}


/* 	vaxReg executes the Vax Reg submenus based on the given value
	@param user[] - struct containing the user data
	@param vaxChoice - variable containing the choice picked by the user
	@param *k - num of registered users/index for the user struct array
	@returns nothing
	Pre-condition: input reaches maximum capacity for the password
*/

void 
vaxReg (struct userInfo user[], 
		int vaxChoice, 
		int *k)  // whole vax registration submenus
{
	
			switch (vaxChoice)
			{
				case 1: 
					if (*k >= MAX)
						printf("Maximum capacity of users reached. \n\n");
					
					else 
						{
							userReg(user, k);    		// vaccine registration , gets user info 
							displayData(user, k, 0); 		// displays user info
						}
					
				
					break;

				case 3: 
					chatbotMenu();
					break;	
			}

}

/* 	appointment - allows the user to schedule a vaccination appointment
	@param user[] - struct containing the user data
	@param *k - number of registered users/index for the user struct arrays
 	@returns 1 if log in is valid and -1 if not
*/

int 
appointment (struct userInfo user[], 
				int *k)
{
	int vaxAppChoice, index;
	
					if (user[0].userID == 0)
						{
							printf("No registered users. Please register first before proceeding to Vaccination Appointment.\n\n");
						}
					
					else 
					{
						index = appointmentLogIn(user, k);    // user log in

						if (index != -1)    // gets executed if valid
						{
							system ("cls");
							do
							{
								vaxAppChoice = vaxAppMenu();    // vax appointment submenu 

								switch (vaxAppChoice)
								{
									case 1:
										system("cls");
											appRequest(user, index, k);
											system("cls");
											displayAppointment(user, index);
											exitz ();
										break;

									case 2:
										printf("\t\tMANAGE APPOINTMENT MENU\n\n");
										manageApp (user, index);
										exitz ();
										break;
								}
								
								
							} while (vaxAppChoice != 3 );
						}

						else
							return -1;
					}
	return 1;
}

/* 	vaxAppMenu allows the user to pick a submenu
 	@returns the number with a corresponding submenu
*/

int 
vaxAppMenu ()
{
	int vaxAppChoice; 
	
	system("cls");

	printf("Vaccine Appointment Menu \n");
	
	printf("\n");
	
	printf("[1] Appointment Request\n");
	printf("[2] Manage Appointment\n");
	printf("[3] Exit\n");
	
	printf("\n");
	
	printf("Enter option (1/2/3): ");
	scanf("%d", &vaxAppChoice);             // gets user input

    while (vaxAppChoice > 3 || vaxAppChoice < 1)
    {
        printf("Invalid input. Please choose from the following options (1/2/3/4): ");
        scanf("%d", &vaxAppChoice);             // gets user input
    }

	system("cls");

    return vaxAppChoice;
}

/* 	displayData displays the data of the registered user
	@param user[] - struct containing the user data
	@param *k - index of the user struct arrays
	@param n - is set to 1 if password must be shown
 	@returns nothing
*/

void 
displayData (struct userInfo user[], 
			int *k,
			int n)
{
	printf("\n");
	printf("******************************************\n");
 	printf("\n\t %*s \n", 15, "USER DATA");
 	printf("\n");

 	printf("User ID %10s %.0lf \n", ":", user[*k].userID);
 	printf("Name %13s %s \n", ":", user[*k].name);

	if (n == 1)
		printf("Password %9s %s \n", ":", user[*k].passWord);

 	printf("Address %10s %s \n", ":", user[*k].address);
 	printf("Contact %10s 0%.0lf \n", ":", user[*k].contact);
 	printf("Sex %14s %s \n", ":", user[*k].sex);

 	printf("\n");

 	printf("First Vaccine Dose %3s %s \n", ":", user[*k].firstDate);
 	printf("First Vaccine %8s %s \n", ":", user[*k].firstVax);
 	printf("First Dose Location %2s %s \n", ":", user[*k].firstLoc);

	printf("\n"); 

	printf("Second Vaccine Dose %2s %s \n", ":", user[*k].dose.secDate);
	printf("Second Vaccine %7s %s \n", ":", user[*k].dose.secVax);
	printf("Second Dose Location %1s %s \n", ":", user[*k].dose.secLoc);

	printf("\n");

	printf("Booster Vaccine Dose %1s %s \n", ":", user[*k].dose.booDate);
	printf("Booster Vaccine %6s %s \n", ":", user[*k].dose.booVax);
	printf("Booster Dose Location: %s \n", user[*k].dose.booLoc);

	printf("\n");
	
	printf("\n******************************************\n");
	
}

/* 	printAllUsers - prints all of the registered users 
	@param user[] - struct containing the user data
	@param *k - number of registered users/index for the user struct arrays
 	@returns nothing
*/

void
printAllUsers (struct userInfo user[], 
					int *k)
{

	if (*k == 0)
		printf("No users to print.\n\n");

	sortUsers (user, *k);   // sorts the users

}

/* 	dataMenu allows the user to pick a submenu from the Data Management menu
 	@returns the number with a corresponding submenu picked by the user
*/

int 
dataMenu ()
{
	int dataChoice; 

	printf("Welcome to the Data Management Menu \n");
	
	printf("\n");
	
	printf("[1] User\n");
	printf("[2] Appointment\n");
	printf("[3] Chatbot\n");
	printf("[4] Export\n");
	printf("[5] Import\n");
	printf("[6] Exit\n");
	
	printf("\n");
	printf("Please choose an option: ");
	scanf("%d", &dataChoice);

    while (dataChoice > 6 || dataChoice < 1)
    {
        printf("Invalid input. Please choose from the following options (1/2/3/4/5/6): ");
        scanf("%d", &dataChoice);
    }
	
	system("cls");

	return dataChoice;
}

/* 	adminLogin allows the admin to log in
 	@returns 1 if log in is valid and 0 if not
*/

int 
adminLogin ()
{
	double admin = 12295069;
	str10 adminPass = "cheskacute";

	double userLogin;
	str10 passLogin;

	int ctr = 1;
	char ch;
	int j;

	printf("\t ADMIN \n");
	printf("\n");

	printf("[ADMIN] ID: ");
	scanf("%lf", &userLogin);

	printf("[ADMIN] PASSWORD: ");

	for(j=0;j<10;j++)  // prints an asterisk when the user types the password
 		{	ch = getch();
  			passLogin[j] = ch;
  			ch = '*' ;
  			printf("%c",ch);
 		}


	while ((userLogin != admin || (strcmp(passLogin, adminPass) != 0))  
			&& ctr < 3)
	{
		printf("\nInvalid input. Please try again. \n");
		printf("\n");
		printf("[ADMIN] ID: ");
		scanf("%lf", &userLogin);

		printf("[ADMIN] PASSWORD: ");

		for(j=0;j<10;j++)  // prints an asterisk when the user types the password
 		{	ch = getch();
  			passLogin[j] = ch;
  			ch = '*' ;
  			printf("%c",ch);
 		}
		
		system("cls");

		ctr++;  // increments when loging attempt fails
	}

	system("cls");

	if (ctr == 3)
		return 0;
	else
		return 1;
}

/* 	userSex sets the string sex to the corresponding sex of the user
	@param user[] - struct containing the user data
	@param *k - index for the user struct arrays
	@param sexx - F for female; M for male
*/

void 
userSex (struct userInfo user [], 
			  int *k, 
			  char sexx)
{
	if (sexx == 'f' || sexx == 'F')
		strcpy(user[*k].sex, "Female");
	else if (sexx == 'm' || sexx == 'M')
		strcpy(user[*k].sex, "Male");
}

/* 	userMenu allows the user to pick a submenu from the User Menu
 	@returns the number with a corresponding submenu picked by the user
	Pre-condition: inputs are all integers
*/

int 
userMenu ()
{
	int userChoice; 

	printf("Welcome to the User Menu \n");
	
	printf("\n");
	
	printf("[1] Add New User\n");
	printf("[2] View All Users\n");
	printf("[3] Edit User Details\n");
	printf("[4] Delete User\n");
	printf("[5] Exit\n");
	
	printf("\n");
	printf("Please choose an option: ");
	scanf("%d", &userChoice);

	while (userChoice > 5 || userChoice < 1)
    {
        printf("Invalid input. Please choose from the following options (1/2/3/4/5): ");
        scanf("%d", &userChoice);
    }
	
	system("cls");

	return userChoice;

}

/* 	userMain allows the user to access the User submenus
	@param user[] - struct containing the user data
	@param *k - number of registered users/index for the user struct arrays
	@param userChoice - choice picked by the user
*/

void 
userMain (struct userInfo user[], 
				int *k, 
				int userChoice)
{
	switch (userChoice)
	{
		case 1: 
				if (*k >= MAX)
				{
					printf("Maximum capacity of users reached. \n\n");
				}
					
				else
				{
					addUser(user, k);
				}		
				 break;
		case 2: printAllUsers(user, k); 
				printf("Number of registered users: %d \n\n", *k);
				// system("cls");
				break;
		case 3: 
			editUser(user, k);
		break;
	}
}

/* 	addUser allows the user to add and register another user
	@param user[] - struct containing the user data
	@param *k - number of registered users/index for the user struct arrays
*/

void 
addUser (struct userInfo user[], 
		int *k)
{
		userReg(user, k);
		displayData(user, k, 0);
}

/* 	yesNoAdd asks the user if they want to add more users
 	@returns the choice of the user
	Pre-condition: inputs are members of the alphabets
*/

char 
yesNoAdd ()
{
	char input;
	
		printf("\n");
		printf("Would you like to add another user? (Y/N): ");
		scanf(" %c", &input);

		while (input != 'n' && input != 'N' && input != 'y' && input != 'Y')
		{
			printf("Invalid input. Please try again: ");
			scanf(" %c", &input);
		}
	
	return input;
}

/* exitFunc asks the user to click 1 to exit
   @returns 1
   Pre-condition: inputs are integers
*/

int 
exitFunc()
{
	int exit; 

	printf("\n");
	printf("Click 1 to exit: ");   // if user chooses exit, the user returns to vax Menu 
	scanf("%d", &exit);

	while (exit != 1)
	{
		printf("Invalid input. Please try again: ");
		scanf("%d", &exit);
	}

	return exit;
}

/* exitz asks the user to click 1 to exit
	@returns nothing
	Pre-condition: inputs are integers
*/

void 
exitz ()
{
	int exit; 

	printf("\n");
	printf("Click 1 to exit: ");   // if user chooses exit, the user returns to vax Menu 
	scanf("%d", &exit);

	while (exit != 1)
	{
		printf("Invalid input. Please try again: ");
		scanf("%d", &exit);
	}

	// doesn't do anything lol 
}

/* 	editUser allows the user skim through all of the user profiles
	@param user[] - struct containing the user data
	@param *k - number of registered users/index for the user struct arrays
 	@returns nothing
*/

void 
editUser (struct userInfo user[], 
          int *k)
{
	int i;
	int choice;

	if (*k == 0)
		printf("No users to edit.\n\n");
	else 
	{
		do 
		{
			for (i = 0; i < *k && choice != 3; i++)
			{
				displayData(user, &i, 1);

				choice = editChoice();

				if (choice ==  1)
				{
					system("cls");
					editDetails(user, i);
				}

				system("cls");
			}
		

		} while (choice != 3);
	}
	
}

/*	editChoice asks the user if they want to edit the user or move on to the next one
	@returns the choice of the user
	Pre-condition: inputs are integers
*/

int 
editChoice ()
{
	int choice;

		printf("\n");
		printf ("\n[1] Edit Details \n");
		printf("[2] Next User\n");
		printf("[3] Exit\n");
		printf("\n");

		printf("Input: ");
		scanf("%d", &choice);

		while (choice > 3 || choice < 1)
		{
			printf ("Invalid input. Please try again: ");
			scanf("%d", &choice);
		}

	return choice;

}

/* 	editDetails allows the user to manipulate user data
	@param user[] - struct containing the user data
	@param k - index of the user struct arrays
*/

void 
editDetails (struct userInfo user[], 
    		 int k)
{
	int input, check, valid; 
	char sexx;

	do
	{
		displayData(user, &k, 1);

		printf("\nWhich user detail would you like to edit? \n");
		printf(" [1] User ID \n [2] Password \n [3] Name \n [4] Address \n [5] Contact\n");
		printf(" [6] Sex \n [7] Date of First Dose \n [8] First Dose Vaccine \n [9] First Dose Location \n");
		printf(" [10] Date of Second Dose \n [11] Second Dose Vaccine \n [12] Second Dose Location \n");
		printf(" [13] Date of Booster Dose \n [14] Booster Dose Vaccine \n [15] Booster Dose Location \n [16] Exit \n");

		printf("\nInput: ");
		scanf("%d", &input);

		while (input > 16 || input < 1)
		{
			printf("Invalid input. Please try again: ");
			scanf("%d", &input);
		}

		switch (input)
		{
			case 1: 
				printf("Enter new ID: ");
				scanf("%lf", &user[k].userID);

				while (user[k].userID < 1000 || user[k].userID > 9999999999)
				{
					printf("Invalid input. Input must be at least 4 digits. Please try again.\n");
					printf("userID: ");
					scanf("%lf", &user[k].userID);
				}

				check = checkID(user, k);
				
				while (check == 1)
				{
					printf("USER ID is already taken. Please try again.\n");
					printf("userID: ");
					scanf("%lf", &user[k].userID);

					while (user[k].userID < 1000 || user[k].userID > 999999999)
					{
						printf("Invalid input. Input must be at least 4 digits. Please try again.\n");
						printf("userID: ");
						scanf("%lf", &user[k].userID);
					}

					check = checkID(user, k);
				}
				break;
			case 2: 
				printf("Previous password: %s \n", user[k].passWord);
				printf("Enter new password: ");
				getString(user[k].passWord, 10);
				break;
			case 3:
				printf("Enter new name: ");
				getString(user[k].name, 20);
				strcpy(user[k].app.name, user[k].name);
				break;
			case 4: 
				printf("Enter new address: ");
				getString(user[k].address, 30);
				break;
			case 5: 
				printf("Enter new contact: ");
				scanf("%lf", &user[k].contact);
				break;
			case 6:
				printf("Edit sex: ");
				scanf(" %c", &sexx);

				while (sexx != 'm' && sexx != 'M' && sexx != 'f' && sexx != 'F')
				{
					printf("Invalid input. Please try again. \n");
					printf("Sex (M/F): ");
					scanf(" %c", &sexx);
				}
				userSex (user, &k, sexx);
				break;
			case 7: 
				printf("Enter new date of first dose: \n");
				toString(user, k);
				break;
			case 8: 
				printf("Enter new first dose vaccine: ");
				getString(user[k].firstVax, 10);

				valid = vaccineValid(user[k].firstVax);

				while (valid == 0)
				{
					printf("Input not recognized. Please try again.\n\n");
					printf("Enter new first dose vaccine: ");
					getString(user[k].firstVax, 10);
					valid = vaccineValid(user[k].firstVax);
				}

				break;
			case 9: 
				printf("Enter new first dose location: ");
				getString(user[k].firstLoc, 10);
				break; 
			case 10:
				printf("Enter new date of second dose: \n");
				toStringSec(user, k);
				break;
			case 11:
				printf("Enter new second dose vaccine: ");
				getString(user[k].dose.secVax, 10);

				valid = vaccineValid(user[k].dose.secVax);

				while (valid == 0)
				{
					printf("Input not recognized. Please try again.\n\n");
					printf("Enter new second dose vaccine: ");
					getString(user[k].dose.secVax, 10);
					valid = vaccineValid(user[k].dose.secVax);
				}

				break;
			case 12: 
				printf("Enter new second dose location: ");
				getString(user[k].dose.secLoc, 10);
				break;
			case 13: 
				printf("Enter new date of booster dose: \n");
				toStringBoo(user, k);
				break;
			case 14:
				printf("Enter new booster dose vaccine: ");
				getString(user[k].dose.booVax, 10);

				valid = vaccineValid(user[k].dose.booVax);

				while (valid == 0)
				{
					printf("Input not recognized. Please try again.\n\n");
					printf("Enter new booster dose vaccine: ");
					getString(user[k].dose.booVax, 10);
					valid = vaccineValid(user[k].dose.booVax);
				}
				break; 
			case 15:
				printf("Enter new booster dose location: ");
				getString(user[k].dose.booLoc, 10);
				break;

		} // switch bracket

		system("cls");

	} while (input != 16);

}

/* 	checkID checks if the userID is unique
	@param user[] - struct containing the user data
	@param k - index of the user struct array
 	@returns 1 if ID is unique and 0 if not
*/

int 
checkID (struct userInfo user[], 
 		int k)
{
	int i; 

	for (i = 0; i < k; i++)
	{
		if (user[k].userID == user[i].userID)
			return 1;
	}
	 
	return 0;
}

/* 	exportUsers asks the user to export the user data
	@param user[] - struct containing the user data
	@param *k - number of registered users/index of the user struct arrays
*/

void 
exportUsers (struct userInfo user [], 
			int *k)
{
	FILE *fp;

	str30 fname;
	printf("File Name: ");
	scanf("%s", fname);

	strcat(fname, ".txt");

	fp = fopen (fname, "w");

	int i;

	for (i = 0; i < *k; i++)
	{
		fprintf(fp, "%.0lf %s\n", user[i].userID, user[i].passWord);
		fprintf(fp, "%s\n", user[i].name);
		fprintf(fp, "%s\n", user[i].address);
		fprintf(fp, "0%.0lf\n", user[i].contact);
		fprintf(fp, "%s\n", user[i].sex);
		fprintf(fp, "%s %s %s\n", user[i].firstLoc, user[i].firstDate, user[i].firstVax);
		fprintf(fp, "%s %s %s\n", user[i].dose.secLoc, user[i].dose.secDate, user[i].dose.secVax);
		fprintf(fp, "%s %s %s\n", user[i].dose.booLoc, user[i].dose.booDate, user[i].dose.booVax);
		fprintf(fp, "\n");
	}

	fclose(fp);
}

/* 	storeUsers exports the user data 
	@param user[] - struct containing the user data
	@param *k - number of registered users/index of the user struct arrays
*/

void 
storeUsers (struct userInfo user[], 
			int *k)
{
	FILE *fp;
	fp = fopen ("Users.txt", "w");

	int i;

		for (i = 0; i < *k; i++)
	{
		fprintf(fp, "%.0lf %s\n", user[i].userID, user[i].passWord);
		fprintf(fp, "%s\n", user[i].name);
		fprintf(fp, "%s\n", user[i].address);
		fprintf(fp, "0%.0lf\n", user[i].contact);
		fprintf(fp, "%s\n", user[i].sex);
		fprintf(fp, "%s %s %s\n", user[i].firstLoc, user[i].firstDate, user[i].firstVax);
		fprintf(fp, "%s %s %s\n", user[i].dose.secLoc, user[i].dose.secDate, user[i].dose.secVax);
		fprintf(fp, "%s %s %s\n", user[i].dose.booLoc, user[i].dose.booDate, user[i].dose.booVax);
		fprintf(fp, "\n");
	}

	fclose(fp);
}

/* 	deleteUsers deletes existing users from the struct array
	@param user[] - struct containing the user data
	@param *k - number of registered users/index of the user struct arrays
	@returns the number of deleted users
*/

int 
deleteUsers (struct userInfo user[], 
			int *k)
{
	int i, choice, p;
	int del = 0; 

	int j = *k;
	int choice2;

	if (*k == 0)
	{
		printf("No users to delete. Please continue.\n");
	}

	else 
	{
		do
		{
			for (i = 0; i < j && choice != 3; i++)
			{
				displayData(user, &i, 1);

				choice = deleteChoice();
				
				if (choice == 1)
				{
						j--;	
						del++;

						if (j == 0)
						{
							printf("You have successfully deleted a user. Press 2 to continue: ");
							scanf("%d", &choice2);
							while (choice2 != 2)
							{
								printf("Invalid input. Please try again.\n");
								printf("You have successfully deleted a user. Press 2 to continue: ");
								scanf("%d", &choice2);
							}
							return del;
						}
							

					for (p = i; p <= j; p++)
					{
						shiftDelUsers(user, p);	
					}

					printf("You have successfully deleted a user. Press 2 to continue: ");
					scanf("%d", &choice2);
					while (choice2 != 2)
					{
						printf("Invalid input. Please try again.\n");
						printf("You have successfully deleted a user. Press 2 to continue: ");
						scanf("%d", &choice2);
					}

				}

				system("cls");
			}

		} while (choice != 3);
	}


	return del;
}

/* 	deleteChoice asks the user if they want to delete the displayed user
	@returns the choice picked by the user
	Pre-condition: all inputs are integers
*/

int 
deleteChoice ()
{
	int choice; 

	printf("\n");
	printf("[1] Delete User\n");
	printf("[2] Next \n");
	printf("[3] Exit \n");
	printf("\n");

	printf("Input: ");
	scanf("%d", &choice);

	while (choice > 3 || choice < 1)
	{
		printf("Invalid input. Please try again.\n");
		printf("Input: ");
		scanf("%d", &choice);
	}

	return choice; 
}

/* 	shiftDelUSers shifts the users in the next index to the preceding index
	@param user[] - struct containing the user data
	@param i - index of the user struct array
*/

void 
shiftDelUsers (struct userInfo user[], 
			   int i)
{
	user[i].userID = user[i+1].userID; 
	strcpy(user[i].name, user[i+1].name);
	strcpy(user[i].address, user[i+1].address);
	strcpy(user[i].passWord, user[i+1].passWord);
	user[i].contact = user[i+1].contact;
	strcpy(user[i].sex, user[i+1].sex);
	strcpy(user[i].firstDate, user[i+1].firstDate);
	strcpy(user[i].firstVax, user[i+1].firstVax);
	strcpy(user[i].firstLoc, user[i+1].firstLoc);
	strcpy(user[i].dose.secVax, user[i+1].dose.secVax);
	strcpy(user[i].dose.secLoc, user[i+1].dose.secLoc);
	strcpy(user[i].dose.secDate, user[i+1].dose.secDate);
	strcpy(user[i].dose.booVax, user[i+1].dose.booVax);
	strcpy(user[i].dose.booLoc, user[i+1].dose.booLoc);
	strcpy(user[i].dose.booDate, user[i+1].dose.booDate);

	user[i].doses = user[i+1].doses;

	user[i].app.appID = user[i+1].app.appID;
	strcpy(user[i].app.name, user[i+1].app.name);
	strcpy(user[i].app.location, user[i+1].app.location);
	strcpy(user[i].app.vaccine, user[i+1].app.vaccine);
	strcpy(user[i].app.time, user[i+1].app.time);
	strcpy(user[i].app.date, user[i+1].app.date);
	strcpy(user[i].app.dose, user[i+1].app.dose);

}

/* 	appointment LogIn allows the registered user to log in
	@param user[] - struct containing the user data
	@param *k - number of registered users/index of the user struct arrays
	@returns 1 if log in is successful in -1 if not
*/

int 
appointmentLogIn (struct userInfo user[], 
				int *k)
{ 
	double id; 
	char ch;
	int j;
	str10 pass; 
	int valid, ctr = 0;

	printf("[USER] ID: ");
	scanf("%lf", &id);

	printf("[USER] Password: ");
	for(j=0;j<10;j++)  // prints an asterisk when the user types the password
 		{	ch = getch();
  			pass[j] = ch;
  			ch = '*' ;
  			printf("%c",ch);
 		}

	printf("\n");


	valid = isValid(user, id, pass, k);

	while (valid == -1 && ctr < 2)
	{
		printf("Invalid input. Please try again.\n");
		printf("ID: ");
		scanf("%lf", &id);
		printf("[USER] Password: ");
		for(j=0;j<10;j++)  // prints an asterisk when the user types the password
 		{	ch = getch();
  			pass[j] = ch;
  			ch = '*' ;
  			printf("%c",ch);
 		}

		printf("\n");

		valid = isValid(user, id, pass, k);

		ctr++;

		if (ctr >= 2)
			printf("You have exceeded the maximum number of attempts. \n");
	}

	if (ctr < 2)
		return valid;
	else 
		return -1;	
}

/* 	isValid checks if the entered ID and password are valid
	@param user[] - struct containing the user data
	@param *k - number of registered users/index of the user struct arrays
	@param double id - ID entered by the user
	@param str10 pass - password entered by the user
	@returns the index of the user if log in is successful and -1 if not
*/

int 
isValid (struct userInfo user[], 
		double id, 
		str10 pass, 
		int *k)
{
	int i, j, valid, valid2, index;

	for (i = 0; i < *k; i++)
	{
		if (user[i].userID == id)
		{
			valid = 1;
			j = i;
		}
			
	}

	if ((strcmp(user[j].passWord, pass)) == 0)
	{
			valid2 = 1;
			index = j;
	}
	else
		valid2 = 0;

	if (valid == 1 && valid2 == 1)
		return index;
	else
		return -1;
}

/* 	appRequest allows the user to set an appointment
	@param user[] - struct containing the user data
	@param i - index of the user
	@param *k - number of registered users/index of the user struct arrays
*/

void 
appRequest (struct userInfo user[], 
			int i, 
			int *k)
{
	int valid, j = i;

	if (user[i].app.appID == 0)
	{
			printf("\t\t\t Appointment Request \n");
			printf("\n\n");

			printf("Please enter the following information. \n"); 
			printf("\n");

			printf("Appointment ID: ");
			scanf("%lf", &user[i].app.appID);

			while (user[i].app.appID < 1000 || user[i].app.appID > 999999999)
			{
				printf("Invalid input. ID must be at least 4 digits. Please try again.\n");
				printf("Appointment ID: ");
				scanf("%lf", &user[i].app.appID);
			}

			valid = checkAppID(user, j, *k);
			
			while (valid == 1)
			{
				printf("Appointment ID already taken. Please try again. \n");
				printf("Appointment ID: ");
				scanf("%lf", &user[i].app.appID);
				while (user[i].app.appID < 1000)
				{
					printf("Invalid input. ID must be at least 4 digits. Please try again.\n");
					printf("Appointment ID: ");
					scanf("%lf", &user[i].app.appID);
				}
				valid = checkAppID(user, j, *k);
			}

			strcpy (user[i].app.name, user[i].name);

			printf("Name: %s \n", user[i].app.name);

			printf("Location: ");
			getString(user[i].app.location, 10);
			
			printf("Vaccine: ");
			getString(user[i].app.vaccine, 10);

			valid = vaccineValid(user[i].app.vaccine);

			while (valid == 0)
			{
				printf("Input not recognized. Please try again.\n\n");
				printf("Vaccine: ");
				getString(user[i].app.vaccine, 10);
				valid = vaccineValid(user[i].app.vaccine);
			}

			printf("\n");

			printf("Date (Please enter the following details) \n");
			toStringApp (user, i);

			printf("\n");

			printf("Time (Please enter the following details) \n");
			time(user, i);

			printf("\n");

			if (user[i].doses == 1)
			{
				printf("Since you have already received your first dose, you are only eligible for receiving the second dose.\n");
				printf("Dose: 2nd Dose\n");
				strcpy(user[i].app.dose, "2nd Dose");
			}

			else if (user[i].doses == 2 || (strcmp(user[i].dose.booVax, "N/A") == 0))
			{
				printf("Since you have already received your first and second dose, you are only eligible for receiving the booster.\n");
				printf("Dose: Booster\n");
				strcpy(user[i].app.dose, "Booster");
			}

			else if (user[i].doses == 3 || (strcmp(user[i].dose.booVax, "N/A") != 0))
			{
				printf("Since you have already received a vaccine booster, you are only eligible for receiving the second booster.\n");
				printf("Dose: 2nd Booster\n");
				strcpy(user[i].app.dose, "2nd Booster");
			}

			int cont;

			printf("\nClick 2 to continue: ");
			scanf("%d", &cont);

			while(cont != 2)
			{
				printf("Invalid input. Please try again. \n");
				printf("\nClick 2 to continue: ");
				scanf("%d", &cont);
			}
	}


}

/* 	checkAppID checks if the entered App ID is unique
	@param user[] - struct containing the user data
	@param n - index of the user
	@param k - number of registered users/index of the user struct arrays
	@returns 1 if ID is not unique and 0 if yes
*/

int 
checkAppID (struct userInfo user[], 
			int n, 
			int k)
{
	int i; 

	for (i = 0; i < k; i++)
	{
		if (i != n)
		{
			if (user[n].app.appID  == user[i].app.appID)
			{
				return 1;
			}
		}

	}

		return 0;
}

/* 	displayAppointment displays the appointment data of the user
	@param user[] - struct containing the user data
	@param k - index of the user
*/

void 
displayAppointment (struct userInfo user[], 
					int k)
{
	printf("******************************************\n");
	printf("\n \t %15s \n", "APPOINTMENT REQUEST DATA");
	printf("\n");
	
	printf("Appointment ID: %.0lf \n", user[k].app.appID);
	printf("Name %10s %s \n", ":", user[k].app.name);
	printf("Location %6s %s \n", ":", user[k].app.location);
	printf("Vaccine %7s %s \n", ":", user[k].app.vaccine);
	printf("Date %10s %s \n", ":", user[k].app.date);
	printf("Time %10s %s \n", ":", user[k].app.time);
	printf("Dose %10s %s \n", ":", user[k].app.dose);
	printf("\n\n******************************************\n");
}

/* 	toString collects the date of the first dose vaccination
	@param user[] - struct containing the user data
	@param k - index of the user
	Pre-Condition: all inputs are integers
*/

void 
toString (struct userInfo user[], 
		  int k)
{	
	int month, year, day;

			printf("Year: ");
			scanf("%d", &year);

			while (year < 2020)
			{
				printf("Invalid date. Please pick a year from 2020 and onwards only. \n");
				printf("Year: ");
				scanf("%d", &year);
			}
	
			printf("Month: ");
			scanf("%d", &month);

			while(month > 12 || month < 1)
			{
				printf("Invalid month number. Please pick from 1 to 12 only. \n");
				printf("Month: ");
				scanf("%d", &month);
			}

			printf("Day: ");
			scanf("%d", &day);

			while(day > 31 || day < 1)
			{
				if (month == 1 || month == 3 || month == 7 || month == 8 || month == 10 || month == 12)
				{
					while ( day > 31 || day < 1)
					{
						printf("Invalid date. Please pick from 1 to 31 only.\n");
						printf("Day: ");
						scanf("%d", &day);
					}
					
				}
				else if (month == 2)
				{
					while (day > 28 || day < 1)
					{
						printf("Invalid date. Please pick from 1 to 28 only.\n");
						printf("Day: ");
						scanf("%d", &day);
					}
					
				}
				else
				{
					while (day > 30 || day < 1)
					{
						printf("Invalid date. Please pick from 1 to 30 only.\n");
						printf("Day: ");
						scanf("%d", &day);
					}
				}
				
			}

	int temp;
	
	int i;
	
	for (i = 3; i >= 0; i--)
	{
		temp = year % 10;
		year/=10;
		
		user[k].firstDate[i] = temp + '0';
	}
	
	user[k].firstDate[4] = '-';
	
			if (month <= 9 && month >= 1)
	{
		user[k].firstDate[5] = '0';
		user[k].firstDate[6] = month + '0';
	}
	
	else 
	{
		for (i = 6; i >= 5; i--)
		{
			temp = month % 10;
			month /= 10;
			user[k].firstDate[i] = temp + '0';
		}
	}
	
	user[k].firstDate[7] = '-';
	
	if (day <= 9 && day >= 1)
	{
		user[k].firstDate[8] = '0';
		user[k].firstDate[9] = day + '0';
	}
	
	else 
	{
		for (i = 9; i >= 8; i--)
		{
			temp = day % 10;
			day /= 10;
			user[k].firstDate[i] = temp + '0';
		}
	}
	
}

/* 	toStringSec collects the date of the second dose vaccination
	@param user[] - struct containing the user data
	@param k - index of the user
	Pre-Condition: inputted date occurs later than the date of the first vaccination
*/

void 
toStringSec (struct userInfo user[], 
				  int k)
{	
	int month, year, day;

			printf("Year: ");
			scanf("%d", &year);

			while (year < 2020 || year > 2023)
			{
				printf("Invalid date. Please pick a year from 2020-2023 only. \n");
				printf("Year: ");
				scanf("%d", &year);
			}
	
			printf("Month: ");
			scanf("%d", &month);

			while(month > 12 || month < 1)
			{
				printf("Invalid month number. Please pick from 1 to 12 only. \n");
				printf("Month: ");
				scanf("%d", &month);
			}

			printf("Day: ");
			scanf("%d", &day);

			while(day > 31 || day < 1)
			{
				if (month == 1 || month == 3 || month == 7 || month == 8 || month == 10 || month == 12)
				{
					while ( day > 31 || day < 1)
					{
						printf("Invalid date. Please pick from 1 to 31 only.\n");
						printf("Day: ");
						scanf("%d", &day);
					}
					
				}
				else if (month == 2)
				{
					while (day > 28 || day < 1)
					{
						printf("Invalid date. Please pick from 1 to 28 only.\n");
						printf("Day: ");
						scanf("%d", &day);
					}
					
				}
				else
				{
					while (day > 30 || day < 1)
					{
						printf("Invalid date. Please pick from 1 to 30 only.\n");
						printf("Day: ");
						scanf("%d", &day);
					}
				}
				
			}

	int temp;
	
	int i;
	
	for (i = 3; i >= 0; i--)
	{
		temp = year % 10;
		year/=10;
		
		user[k].dose.secDate[i] = temp + '0';
	}
	
	user[k].dose.secDate[4] = '-';
	
			if (month <= 9 && month >= 1)
	{
		user[k].dose.secDate[5] = '0';
		user[k].dose.secDate[6] = month + '0';
	}
	
	else 
	{
		for (i = 6; i >= 5; i--)
		{
			temp = month % 10;
			month /= 10;
			user[k].dose.secDate[i] = temp + '0';
		}
	}
	
	user[k].dose.secDate[7] = '-';
	
	if (day <= 9 && day >= 1)
	{
		user[k].dose.secDate[8] = '0';
		user[k].dose.secDate[9] = day + '0';
	}
	
	else 
	{
		for (i = 9; i >= 8; i--)
		{
			temp = day % 10;
			day /= 10;
			user[k].dose.secDate[i] = temp + '0';
		}
	}
	
}

/* 	toStringSec collects the date of the booster dose vaccination
	@param user[] - struct containing the user data
	@param k - index of the user
	Pre-Condition: inputted date occurs later than the dates of the first and second vaccination
*/

void 
toStringBoo (struct userInfo user[], 
			 int k)
{
	int month, year, day;

			printf("Year: ");
			scanf("%d", &year);

			while (year < 2020 || year > 2023)
			{
				printf("Invalid date. Please pick a year from 2020-2023 only. \n");
				printf("Year: ");
				scanf("%d", &year);
			}
	
			printf("Month: ");
			scanf("%d", &month);

			while(month > 12 || month < 1)
			{
				printf("Invalid month number. Please pick from 1 to 12 only. \n");
				printf("Month: ");
				scanf("%d", &month);
			}

			printf("Day: ");
			scanf("%d", &day);

			while(day > 31 || day < 1)
			{
				if (month == 1 || month == 3 || month == 7 || month == 8 || month == 10 || month == 12)
				{
					while ( day > 31 || day < 1)
					{
						printf("Invalid date. Please pick from 1 to 31 only.\n");
						printf("Day: ");
						scanf("%d", &day);
					}
					
				}
				else if (month == 2)
				{
					while (day > 28 || day < 1)
					{
						printf("Invalid date. Please pick from 1 to 28 only.\n");
						printf("Day: ");
						scanf("%d", &day);
					}
					
				}
				else
				{
					while (day > 30 || day < 1)
					{
						printf("Invalid date. Please pick from 1 to 30 only.\n");
						printf("Day: ");
						scanf("%d", &day);
					}
				}
				
			}

	int temp;
	
	int i;
	
	for (i = 3; i >= 0; i--)
	{
		temp = year % 10;
		year/=10;
		
		user[k].dose.booDate[i] = temp + '0';
	}
	
	user[k].dose.booDate[4] = '-';
	
			if (month <= 9 && month >= 1)
	{
		user[k].dose.booDate[5] = '0';
		user[k].dose.booDate[6] = month + '0';
	}
	
	else 
	{
		for (i = 6; i >= 5; i--)
		{
			temp = month % 10;
			month /= 10;
			user[k].dose.booDate[i] = temp + '0';
		}
	}
	
	user[k].dose.booDate[7] = '-';
	
	if (day <= 9 && day >= 1)
	{
		user[k].dose.booDate[8] = '0';
		user[k].dose.booDate[9] = day + '0';
	}
	
	else 
	{
		for (i = 9; i >= 8; i--)
		{
			temp = day % 10;
			day /= 10;
			user[k].dose.booDate[i] = temp + '0';
		}
	}
}

/* 	toStringApp collects the date for the vaccination appointment
	@param user[] - struct containing the user data
	@param k - index of the user
	Pre-Condition: inputted date occurs later than the date of the first vaccination
*/

void 
toStringApp (struct userInfo user[], 
			 int k)
{
	int month, year, day;

			printf("Year: ");
			scanf("%d", &year);

			while (year < 2020)
			{
				printf("Invalid date. Please pick a year from 2020 and onwards only. \n");
				printf("Year: ");
				scanf("%d", &year);
			}
	
			printf("Month: ");
			scanf("%d", &month);

			while(month > 12 || month < 1)
			{
				printf("Invalid month number. Please pick from 1 to 12 only. \n");
				printf("Month: ");
				scanf("%d", &month);
			}

			printf("Day: ");
			scanf("%d", &day);

			while(day > 31 || day < 1)
			{
				if (month == 1 || month == 3 || month == 7 || month == 8 || month == 10 || month == 12)
				{
					while ( day > 31 || day < 1)
					{
						printf("Invalid date. Please pick from 1 to 31 only.\n");
						printf("Day: ");
						scanf("%d", &day);
					}
					
				}
				else if (month == 2)
				{
					while (day > 28 || day < 1)
					{
						printf("Invalid date. Please pick from 1 to 28 only.\n");
						printf("Day: ");
						scanf("%d", &day);
					}
					
				}
				else
				{
					while (day > 30 || day < 1)
					{
						printf("Invalid date. Please pick from 1 to 30 only.\n");
						printf("Day: ");
						scanf("%d", &day);
					}
				}
				
			}

	int temp;
	
	int i;
	
	for (i = 3; i >= 0; i--)
	{
		temp = year % 10;
		year/=10;
		
		user[k].app.date[i] = temp + '0';
	}
	
	user[k].app.date[4] = '-';
	
			if (month <= 9 && month >= 1)
	{
		user[k].app.date[5] = '0';
		user[k].app.date[6] = month + '0';
	}
	
	else 
	{
		for (i = 6; i >= 5; i--)
		{
			temp = month % 10;
			month /= 10;
			user[k].app.date[i] = temp + '0';
		}
	}
	
	user[k].app.date[7] = '-';
	
	if (day <= 9 && day >= 1)
	{
		user[k].app.date[8] = '0';
		user[k].app.date[9] = day + '0';
	}
	
	else 
	{
		for (i = 9; i >= 8; i--)
		{
			temp = day % 10;
			day /= 10;
			user[k].app.date[i] = temp + '0';
		}
	}
}

/* 	time collects the time for the vaccination appointment
	@param user[] - struct containing the user data
	@param k - index of the user
*/

void 
time (struct userInfo user[], 
	  int k)
{
	int hour, min, temp, i;

	printf("Enter hour (24-hour format): ");
	scanf("%d", &hour);

	while (hour > 16 || hour < 8)
	{
		printf("Invalid input. Vaccination appointments start at 08:00 and end at 17:00. \n");
		printf("Enter hour (24-hour format): ");
		scanf("%d", &hour);
	}

	printf("Please pick the time you prefer: \n");
	printf("[1] %d:00 \n", hour);
	printf("[2] %d:15 \n", hour);
	printf("[3] %d:30 \n", hour);
	printf("[4] %d:45 \n", hour);
	printf("Input: ");
	scanf("%d", &min);

	while (min > 4 || min < 1)
	{
		printf("Invalid input. Please pick from 1 to 4: ");
		scanf("%d", &min);
	}

	if (hour < 10 && hour > -1)
	{
		user[k].app.time[0] = '0';
		user[k].app.time[1] = hour + '0';
	}

	else
	{
		for (i = 1; i >= 0; i--)
		{
			temp = hour % 10;
			hour /= 10;
			user[k].app.time[i] = temp + '0';
		}
	}

	user[k].app.time[2] = ':';
	
	switch (min)
	{
		case 1:
			user[k].app.time[3] = '0';
			user[k].app.time[4] = '0';
			break;
		case 2: 
			user[k].app.time[3] = '1';
			user[k].app.time[4] = '5';
			break;
		case 3: 
			user[k].app.time[3] = '3';
			user[k].app.time[4] = '0';
			break;
		case 4:
			user[k].app.time[3] = '4';
			user[k].app.time[4] = '5';
			break;
	}

}

/* 	manageApp allows the user to edit or cancel their appointment
	@param user[] - struct containing the user data
	@param k - index of the user
*/

void 
manageApp (struct userInfo user[], 
			int k)
{
	if (user[k].app.appID == 0)
		printf("No appointment for user %s. \n", user[k].name);

	else
	{
		manageDeets(user, k);
		displayAppointment(user, k);
		if (user[k].app.appID == 0)
			printf("No appointments for user %s. \n", user[k].name);
	}
}

/* 	manageDeetsallows the user to edit or cancel their appointment
	@param user[] - struct containing the user data
	@param k - index of the user
*/

void 
manageDeets (struct userInfo user[], 
			 int k)
{
	int input, valid;
	
	do
	{
		displayAppointment(user, k);

		printf("\n\n");

		printf("Which option would you like to do? \n\n");

		printf(" [1] Reschedule Date \n [2] Reschedule Time \n [3] Change Vaccination Location \n");
		printf(" [4] Change Vaccine Brand \n [5] Cancel Appointment \n [6] Exit \n\n");

		printf("Input: ");
		scanf("%d", &input);

		while (input > 6 || input < 1)
		{
			printf("\nInvalid input. Please try again: ");
			scanf("%d", &input);
		}

		switch (input)
		{
			case 1: 
				toStringApp(user, k);
				break;
			case 2:
				printf ("Enter new time \n");
				time(user, k);
				break;
			case 3:
				printf("Enter preferred vaccination location: ");
				getString(user[k].app.location, 10);
				break;
			case 4:	
				printf("Enter preferred vaccine brand: ");
				getString(user[k].app.vaccine, 10);

				valid = vaccineValid(user[k].app.vaccine);

				while (valid == 0)
				{
					printf("Input not recognized. Please try again.\n\n");
					printf("Vaccine: ");
					getString(user[k].app.vaccine, 10);
					valid = vaccineValid(user[k].app.vaccine);
				}

				break;
			case 5: 
				cancelApp (user, k);
				input = 6;
				break;

				
		}
		system ("cls");

	} while (input != 6);
	
}

/*	cancelApp allows the user to cancel their appointment
	@param user[] - struct containing the user data
	@param k - index of the user
*/

void 
cancelApp (struct userInfo user[], 
		   int k)
{
	user[k].app.appID = 0;
	user[k].app.date[0] = '\0';
	user[k].app.dose[0] = '\0';
	user[k].app.location[0] = '\0';
	user[k].app.name[0] = '\0';
	user[k].app.time[0] = '\0';
	user[k].app.vaccine[0] = '\0';
}

/* 	appMenu allows the user to choose an Appointment Data Management submenu
	@returns the choice of the user
	Pre-condition: all inputs are integers
*/

int 
appMenu ()
{
	int choice;

	printf("Welcome to the Appointment Admin Menu!\n\n");

	printf(" [1] Add New Appointment\n [2] View All Appointments \n [3] Edit Appointment \n [4] Delete Appointment\n");
	printf(" [5] Exit \n\n");

	printf("Input: ");
	scanf("%d", &choice);

	while (choice > 5 || choice < 1)
	{
		printf("Invalid input. Please try again: ");
		scanf("%d", &choice);
	}

	return choice;
}

/* 	appData allows the user to acces the Appointment Data Management submenus
	@param user[] - struct containing the user data
	@param *k - number of registered users/index of the user struct arrays
*/

void 
appData (struct userInfo user[], 
		 int *k)
{
	int choice; 

	do 
	{
		choice = appMenu();

		switch (choice)
		{
			case 1: 
				system ("cls");
				addApp(user, k); 
				// exitz ();
				break;
			case 2: 
				system ("cls");
				printApps(user, k); 
				exitz ();
				system("cls");
				break;
			case 3: 
				system("cls");
				editApp(user, k);
				// exitz (); 
				
				break;
			case 4: 
				system("cls");
				deleteApp(user, k);
				// exitz ();
				break;
		}

		system ("cls");

	} while (choice != 5);

}

/* 	printApps displays the appointments
	@param user[] - struct containing the user data
	@param *k - number of registered users/index of the user struct arrays
*/

void 
printApps (struct userInfo user[], 
		   int *k)
{
	sortApps (user, *k);
}

/* 	sortApps sorts the appointments by the User ID
	@param user[] - struct containing the user data
	@param k - number of registered users/index of the user struct arrays
*/

void 
sortApps (struct userInfo user[], 
		  int k)
{
	int i, j;

	struct userInfo temp;


		for (i = 0; i < k; i++)
		{

			for (j = i + 1; j < k; j++)
			{
				if (user[i].userID > user[j].userID)
				{
					temp = user[i];
					user[i] = user[j];
					user[j] = temp;
					
				}
			}
		}

		for (i = 0; i < k; i++)
		{
			if (user[i].app.appID == 0)
				printf("\n\n\nNo appointment for user %s.\n\n\n", user[i].name);
			else
				displayAppointment(user, i);
		}
}

/* 	addApp allows the user to add apointments
	@param user[] - struct containing the user data
	@param *k - number of registered users/index of the user struct arrays
*/

void 
addApp (struct userInfo user[], 
		int *k)
{
	int i, choice, n; 

	if (user[0].userID == 0)
		printf("No registered users. \n\n");
	
	else
	{
		do
		{
			for (i = 0; i < *k && choice != 3; i++)
				{
					if (user[i].app.appID != 0)
						{
							system ("cls");

							printf("User %s has already set an appointment. \n\n", user[i].name);
							n = 1;
							choice = addAppChoice(n);
						}

					else	
						{
							displayData (user, &i, 1);
							n = 2;
							choice = addAppChoice(n);

							system ("cls");

							if (choice == 1)
								appRequest(user, i, k);
						}
				}

		} while (choice != 3);
	}
}

/* 	addAppChoice asks the user if they want to add an appointment to the registered user
	@param n - n = 1 if the user has already set an appointment and 2 if not
	@returns the choice of the user
*/

int 
addAppChoice (int n)
{
	int choice;
	switch (n)
	{
		case 1: 
			printf("[1] Next User \n");
			printf("[2] Exit\n\n");
			printf("Input: ");
			scanf("%d", &choice);

			while (choice > 2 || choice < 1)
			{
				printf("Invalid input. Please try again.\n");
				printf("Input: ");
				scanf("%d", &choice);
			}

			if (choice == 2)
				choice = 3;
			break; 
		case 2:
			printf("[1] Set Appointment \n");
			printf("[2] Next User \n");
			printf("[3] Exit\n\n");
			printf("Input: ");
			scanf("%d", &choice);
			while (choice > 3 || choice < 1)
			{
				printf("Invalid input. Please try again.\n");
				printf("Input: ");
				scanf("%d", &choice);
			}
			break;
	}

	return choice;
}

/* 	editApps allows the user to edit the appointments
	@param user[] - struct containing the user data
	@param *k - number of registered users/index of the user struct arrays
*/

void 
editApp (struct userInfo user[], 
		 int *k)
{
	int i, choice;

	if (user[0].userID == 0)
		printf("No registered users. \n\n");

	else
	{
		do
		{
			for (i = 0; i < *k && choice != 3; i++)
			{
				system("cls");

				if (user[i].app.appID == 0)
				{
					printf("User %s does not have an appointment. \n", user[i].name);
					choice = editAppChoice (1);
				}

				else 
				{
					displayAppointment(user, i);
					choice = editAppChoice (2);

					if (choice == 1)
					{
						system("cls");
						editAppDeetz(user, i, k);
					}
				}

				
			}

		} while (choice != 3);
	}

}

/* 	editAppChoice asks the user if they want to edit an appointment 
	@param n - n = 1 if the user has already set an appointment and 2 if not
	@returns the choice of the user
*/

int 
editAppChoice (int n)
{
	int choice; 

	switch (n)
	{
		case 1: 
			printf("\n");
			printf("[1] Next User \n");
			printf("[2] Exit\n");
			printf("Input: ");
			scanf("%d", &choice);

			while (choice > 2 || choice < 1)
			{
				printf("Invalid input. Please try again.\n");
				printf("Input: ");
				scanf("%d", &choice);
			}

			if (choice == 2)
				choice = 3;
			break;

		case 2: 
			printf("[1] Edit Appointment \n");
			printf("[2] Next User\n");
			printf("[3] Exit\n\n");
			printf("Input: ");
			scanf("%d", &choice);
			while (choice > 3 || choice < 1)
			{
				printf("Invalid input. Please try again.\n");
				printf("Input: ");
				scanf("%d", &choice);
			}
			break;
			
	}

	return choice;
}

/* 	editAppDeetz allows the user to edit an appointment 
	@param user[] - struct array for the user data
	@param k - index of the user
	@param *n - number of registered users
*/

void 
editAppDeetz (struct userInfo user[], 
			  int k, 
			  int *n)
{
	int input, valid; 

	do
	{
		displayAppointment(user, k);

		printf("\nWhich appointment detail would you like to edit?\n\n");
		printf(" [1] Appointment ID \n");
		printf(" [2] Name \n");
		printf(" [3] Location \n");
		printf(" [4] Vaccine \n");
		printf(" [5] Date \n");
		printf(" [6] Time \n");
		printf(" [7] Exit \n\n");

		printf("Input: ");
		scanf("%d", &input);

		while (input > 7 || input < 1)
		{
			printf("Invalid input. Please try again: ");
			scanf("%d", &input);
		}

		switch (input)
		{
			case 1: 
				printf("Enter new Appointment ID: ");
				scanf("%lf", &user[k].app.appID);

				while (user[k].app.appID < 1000 || user[k].app.appID > 9999999999)
				{
					printf("Invalid input. ID must be at least 4 digits. Please try again.\n");
					printf("Appointment ID: ");
					scanf("%lf", &user[k].app.appID);
				}

				valid = checkAppID(user, k, *n);
				
				while (valid == 1)
				{
					printf("Appointment ID already taken. Please try again. \n");
					printf("Appointment ID: ");
					scanf("%lf", &user[k].app.appID);
					while (user[k].app.appID < 1000)
					{
						printf("Invalid input. ID must be at least 4 digits. Please try again.\n");
						printf("Appointment ID: ");
						scanf("%lf", &user[k].app.appID);
					}
					valid = checkAppID(user, k, *n);
				}
				break;

			case 2:
				printf("Enter name: ");
				getString(user[k].app.name, 20);
				strcpy(user[k].name, user[k].app.name);
				break;
			
			case 3:
				printf("Enter location: ");
				getString(user[k].app.location, 10);
				break;

			case 4: 
				printf("Enter vaccine brand: ");
				getString(user[k].app.vaccine, 10);
				valid = vaccineValid(user[k].app.vaccine);

				while (valid == 0)
				{
					printf("Input not recognized. Please try again.\n\n");
					printf("Vaccine: ");
					getString(user[k].app.vaccine, 10);
					valid = vaccineValid(user[k].app.vaccine);
				}
				break;
			
			case 5: 
				printf("Enter new date: \n");
				toStringApp(user, k);
				break;
			
			case 6: 
				printf("Set new time: \n");
				time(user, k);
				break;
		}

		system("cls");

	} while (input != 7);
	
}

/* 	deleteApp allows the user to delete an appointment 
	@param user[] - struct array for the user data
	@param *k - number of registered users
*/

void 
deleteApp (struct userInfo user[], 
		   int *k)
{
	int i, choice; 

	if (user[0].userID < 1)
		printf("No registered users. \n\n");

	else
	{
		do
		{
			system("cls");

			for (i = 0; i < *k && choice != 3; i++)
			{
				system("cls");

				if (user[i].app.appID == 0)
				{
					printf("User %s does not have an appointment.\n\n", user[i].name);
					choice = deleteAppChoice(1);
				}

				else
				{
					displayAppointment(user, i);
					choice = deleteAppChoice(2);

					if (choice == 1)
					{
						cancelApp(user, i);
					}
				}
			}

		} while (choice != 3);
	}

}

/* 	deleteAppChoice allows the user pick which appointment to delete 
	@param n - is 1 if the user does not have an appointment and 2 if they do
	@returns the choice of the user
	Pre-condition: all inputs are integers
*/

int 
deleteAppChoice (int n)
{
	int choice;

	switch (n)
	{
		case 1: 
			printf("\n");
			printf("[1] Next User \n");
			printf("[2] Exit\n");
			printf("Input: ");
			scanf("%d", &choice);

			while (choice > 2 || choice < 1)
			{
				printf("Invalid input. Please try again.\n");
				printf("Input: ");
				scanf("%d", &choice);
			}

			if (choice == 2)
				choice = 3;
			break;

		case 2: 
			printf("[1] Delete Appointment \n");
			printf("[2] Next User\n");
			printf("[3] Exit\n\n");
			printf("Input: ");
			scanf("%d", &choice);
			while (choice > 3 || choice < 1)
			{
				printf("Invalid input. Please try again.\n");
				printf("Input: ");
				scanf("%d", &choice);
			}
			break;
	}

	return choice;
}

/* 	chatbot allows the user to ask a question to the VaxReg Chatbot 
*/

void 
chatbot ()
{	
	int input;
	str80 array;
	int i, k, j, isFound;
	
	do
	{
		printf("Enter question\n\n");
		printf(">>");
		getString(array, 80);
		
		convertUpper(array);
		
		char string[80];
		
		isFound = 0;
		
		FILE *fp;
		
		fp = fopen("Chatbot.txt", "r");
		
		while(fgets(string, 80, fp) != NULL)
		{
	        int n = strlen(string);
	        
	        for (i = 0; i < n; i++)
	        {
	        	if (string[i] == '\n')
	        		string[i] = '\0';
			}
	        
	        if (strcmp(string, array) == 0)
	        {
	        	isFound = 1;
	        	j = k;
			}
			
			if (k - j == 1)
				printf("\nbot>> %s\n", string);
		
			k++;
			
		}
		
		if(isFound == 0)
				printf("\nbot>>I am sorry, I cannot recognize this question. Please try again.\n\n");
		
		fclose(fp);
		
		
		printf("\nWould you like to ask one more question?\n");
		printf(" [1] Yes\n");
		printf(" [2] No\n");
		printf("Input: ");
		scanf("%d", &input);
		
		while (input > 2 || input < 1)
		{
			printf("Invalid input. Please try again.\n");
			printf("\nWould you like to ask one more question?\n");
			printf(" [1] Yes\n");
			printf(" [2] No\n");
			printf("Input: ");
			scanf("%d", &input);
		}

		if (input == 1)
			system("cls");
		
	} while (input != 2);
	
}

/*	chatbotMenu allows the user to access the chatbot menu
	Pre-condition: inputs are integers
*/

void 
chatbotMenu ()
{
	int choice;

	printf("Welcome to the Vaccine Registration ChatBot!\n\n");
	printf(" [1] Ask\n");
	printf(" [2] Exit\n\n");
	printf("Input: ");
	scanf("%d", &choice);

	while (choice > 2 || choice < 1)
	{
		printf("Invalid input. Please try again.\n\n");
		printf(" [1] Ask\n");
		printf(" [2] Exit\n\n");
		printf("Input: ");
		scanf("%d", &choice);
	}

	switch (choice)
	{
		case 1: chatbot(); break;
	}
}

/*	convertUpper converts all of the characters of a string to uppercase
	@param array[] - string to be converted
*/

void 
convertUpper (char array[])
{
	int i; 
	
	int SIZE = strlen(array);
	
	for (i = 0; i < SIZE; i++)
	{
		if(array[i] >= 97 && array[i] <= 122)	// subtracts 32 from the lowercase ascii values to convert them into uppercase ones
			array[i] -= 32;			
	}
}

/*	removeNew removes the new lines in the question and answer strings
	@param string - the string to be manipulated
*/

void 
removeNew (str80 string)   // removes new line
{
	int n = strlen (string);
	int i;
	
	for (i = 0; i < n; i++)
	    {
	        if (string[i] == '\n')
	        	string[i] = '\0';
		}
}

/*	importFaqs import the FAQs from the text file to a struct
	@param faqs[] - struct containing the FAQs
	@returns the number of FAQs
*/

int 
importFaqs(struct chatbot faqs[])  // imports the faqs from the text file to a struct
{
	FILE *fp;
	str30 fname;
	str80 string;
	int i, ctr = 0;
	
	printf("Enter file name: ");
	getString(fname, 30);
	
	strcat(fname, ".txt");
	
	fp = fopen(fname, "r");
	
	if (fp == NULL)
	{
		printf("Could not open file %s.\n", fname);
		return -1;
	}
	
	else
	{
		while (fgets(string, 80, fp) != NULL)
		{
			ctr++;
		}
		
		fclose(fp);
		
		fp = fopen(fname, "r");
		
		for (i = 0; i < ctr/2; i++)
		{
			
			fgets(faqs[i].question, sizeof(faqs[i].question), fp);
			removeNew (faqs[i].question);
			
			fgets(faqs[i].answer, sizeof(faqs[i].answer), fp);
			removeNew (faqs[i].answer);
		}
		
		fclose(fp);
	}
	
	return ctr;
}

/*	storeFaqs stores the faqs in the array into the txt file
	@param faqs[] - struct containing the FAQs
*/

void 
storeFaqs (struct chatbot faqs[])  // stores the faqs into the txt file
{
	FILE *fp;
	int i, ctr = 0;
	str30 fname;
	
	
	printf("Enter the file name where the FAQs will be stored: ");
	
	printf("\nEnter file name: ");
	getString(fname, 30);
	
	strcat(fname, ".txt");
	
	fp = fopen(fname, "w");

		for (i = 0; faqs[i].question[0] != '\0'; i++)
		{
			ctr++;
		}
		
		for (i = 0; i < ctr; i++)
		{
			if (i == ctr-1)
			{
				fprintf(fp, "%s\n", faqs[i].question);
				fprintf(fp, "%s", faqs[i].answer);
			}
			else
			{
				fprintf(fp, "%s\n", faqs[i].question);
				fprintf(fp, "%s\n", faqs[i].answer);
			}
							
		}
		
		fclose(fp);
	
}

/*	viewAllFaqs allows the user to view all of the existing FAQs
*/

void 
viewAllFaqs ()
{
	FILE *fp;
	str30 fname;
	str80 string;
	int ctr = 1;
	
	printf("Enter file name of all FAQs: ");
	getString(fname, 30);
	
	strcat(fname, ".txt");
	
	printf("\n");
	
	fp = fopen(fname, "r");
	
	if (fp == NULL)
	{
		printf("Could not open file %s.\n", fname);
	}
	
	else
	{
		while (fgets(string, sizeof(string), fp) != NULL)
		{
			if (ctr %2 == 0)
				printf("Answer  : %s\n", string);
			else
				printf("Question: %s", string);
				
			
			ctr++;
		}
		
		fclose(fp);
	}
}

/*	editFaqs allows the user to edit the FAQs and their answers
	@param faqs[] - struct containing the FAQs
	@param i - index of the QnA
*/

void 
editFaqs (struct chatbot faqs[], 
		  int i)
{
	int input;
	do
	{
		printf("******************************************\n\n");
		
		printf("Question: %s \n\n", faqs[i].question);
		printf("Answer  : %s \n\n", faqs[i].answer);
		
		printf("******************************************\n");
		
		printf("Which one would you like to edit?\n\n");
		printf(" [1] Question\n");
		printf(" [2] Answer\n");
		printf(" [3] Exit\n\n");
		printf("Input: ");
		scanf("%d", &input);
		
		while (input > 3 || input < 1)
		{
			printf("Invalid input. Please try again.\n\n");
			printf("Input: ");
			scanf("%d", &input);
		}
		
		switch (input)
		{
			case 1:
				printf("Enter question: ");
				getString(faqs[i].question, 80);
				convertUpper(faqs[i].question);
				break;
			
			case 2: 
				printf("Enter answer: ");
				getString(faqs[i].answer, 80);
				break;
		}
		
		system("cls");
		
	} while (input != 3);
	
	
}

/*	editChatbot asks the user if they want to edit the displayed QnA
	@param faqs[] - struct containing the FAQs
*/

void 
editChatbot (struct chatbot faqs[])
{
	int isFound = importFaqs(faqs);
	int input;
	
	int n = isFound/2;
	
	int i; 
	
	if (isFound != -1)
	{
		do 
		{
			for (i = 0; i < n && input != 3; i++)
			{
				printf("******************************************\n\n");
				printf("Question: %s \n\n", faqs[i].question);
				printf("Answer  : %s \n\n", faqs[i].answer);
				printf("******************************************\n\n");
				
				printf(" [1] Edit\n");
				printf(" [2] Next\n");
				printf(" [3] Exit \n");
				
				printf("\nInput: ");
				scanf("%d", &input);
				
				while (input > 3 || input < 1)
				{
					printf("Invalid input. Please try again.\n\n");
					printf("Input: ");
					scanf("%d", &input);
				}
				
				system("cls");
				
				if (input == 1)
				{
					editFaqs(faqs, i);
				}
				
				system("cls");	
			}
			
		} while (input != 3);
		
		storeFaqs(faqs);
	
	}
	
	else
		printf("File not found.\n");

}

/*	addFaqs allows the user to add questions and answers
	@param faqs[] - struct containing the FAQs
*/

void 
addFaqs (struct chatbot faqs[]) // adds faqs
{
	int input;
	int num;
	
	num = importFaqs(faqs);
	
	if (num != -1)
	{
		num /= 2;
		
		system("cls");
		
		do
		{
			printf("Question to be added: ");
			getString(faqs[num].question, 80);
			
			convertUpper(faqs[num].question);
			
			printf("\nAnswer: ");
			getString(faqs[num].answer, 80);
			
			printf("\nAdd more? (press 1 to exit/any number to continue)\n\nInput: ");
			scanf("%d", &input);
			
			if (input != 1)
				num++;
				
			system("cls");
				
		} while (input != 1);	
		
		storeFaqs(faqs);
	}
	
	else 
		printf("File not found.\n");

}

/*	shiftDelFaqs shifts the next faqs to the preceding index
	@param faqs[] - struct containing the FAQs
	@param n - index of the struct
*/

void 
shiftDelFaqs(struct chatbot faqs[], 
			 int n)
{
	strcpy(faqs[n].question, faqs[n+1].question);
	strcpy(faqs[n].answer, faqs[n+1].answer);
}

/* 	deleteFaqs deletes the FAQ
	@param user[] - struct array for the user data
	@param i - index of the struct
*/

void 
deleteFaqs (struct chatbot faqs[], 
			int i)
{
	faqs[i].question[0] = '\0';
	faqs[i].answer[0] = '\0';
}

/* 	deleteChatbot allows the user to delete questions and answers 
	@param user[] - struct array for the user data
*/

void 
deleteChatbot (struct chatbot faqs[])
{
	int isFound = importFaqs(faqs);
	int input;
	
	int n = isFound/2;
	
	int i, j; 
	
	if (isFound != -1)
	{
		do 
		{
			for (i = 0; i < n && input != 3; i++)
			{
				printf("******************************************\n\n");
				printf("Question: %s \n\n", faqs[i].question);
				printf("Answer  : %s \n\n", faqs[i].answer);
				printf("******************************************\n\n");
				
				printf(" [1] Delete\n");
				printf(" [2] Next\n");
				printf(" [3] Exit \n");
				
				printf("\nInput: ");
				scanf("%d", &input);
				
				while (input > 3 || input < 1)
				{
					printf("\n\nInvalid input. Please try again: ");
					scanf("%d", &input);
				}
				
				if (input == 1)
				{
					deleteFaqs(faqs, i);
					
					n--;
					
					if (n == 0)
					{
					
							printf("You have successfully all FAQS. Press 3 to continue: ");
							scanf("%d", &input);
							while (input != 3)
							{
								printf("Invalid input. Please try again.\n");
								printf("You have successfully deleted a user. Press 2 to continue: ");
								scanf("%d", &input);
							}
						
					}
					
					for (j = i; j <= n; j++)
					{
						shiftDelFaqs(faqs, j);
					}
				}
				
				system("cls");	
			}
			
		} while (input != 3 && n != 0);
	
	storeFaqs (faqs);
	
	}
	
	else
		printf("File not found.\n");
}

/*	chatbotData allows the user to access the data management menu for the chatbot
	@param faqs[] - struct containing the FAQs
*/

void 
chatbotData (struct chatbot faqs[])
{
	int input;
	
	do
	{
		printf("ChatBot Data Management\n\n");
		
		printf(" [1] Add New Question and Answer\n");
		printf(" [2] View All Questions and Answers\n");
		printf(" [3] Edit Questions and Answers\n");
		printf(" [4] Delete Questions and Answers\n");
		printf(" [5] Exit\n\n");
		
		printf("Input: ");
		scanf("%d", &input);
		
		while (input > 5 || input < 1)
		{
			printf("Invalid input. Please try again: ");
			scanf("%d", &input);
		}
		
		system("cls");
		
		switch (input)
		{
			case 1: 
				addFaqs(faqs);
				exitz();
				system("cls");
				break;
			
			case 2:
				viewAllFaqs();
				exitz();
				system("cls");
				break;
				
			case 3:
				editChatbot(faqs);
				exitz();
				system("cls");
				break;
				
			case 4:
				deleteChatbot(faqs);
				exitz();
				system("cls");
				break;
		}
		
	} while (input != 5);
	

}

/*	displayImportedUsers displays the imported users
	@param temp[] - struct containing the imported users
	@param k - index of the users
*/

void 
displayImportedUsers (struct temporary temp[], 
					  int k)
{
	printf("\n");
	printf("******************************************\n");
 	printf("\n\t %*s \n", 15, "USER DATA");
 	printf("\n");

 	printf("temp ID %10s %.0lf \n", ":", temp[k].userID);
 	printf("Name %13s %s \n", ":", temp[k].name);
 	
	printf("Password %9s %s \n", ":", temp[k].passWord);
	
	
 	printf("Address %10s %s \n", ":", temp[k].address);
 	printf("Contact %10s 0%.0lf \n", ":", temp[k].contact);
 	printf("Sex %14s %s \n", ":", temp[k].sex);

 	printf("\n");

 	printf("First Vaccine Dose %3s %s \n", ":", temp[k].firstDate);
 	printf("First Vaccine %8s %s \n", ":", temp[k].firstVax);
 	printf("First Dose Location %2s %s \n", ":", temp[k].firstLoc);

	printf("\n"); 

	printf("Second Vaccine Dose %2s %s \n", ":", temp[k].dose.secDate);
	printf("Second Vaccine %7s %s \n", ":", temp[k].dose.secVax);
	printf("Second Dose Location %1s %s \n", ":", temp[k].dose.secLoc);

	printf("\n");

	printf("Booster Vaccine Dose %1s %s \n", ":", temp[k].dose.booDate);
	printf("Booster Vaccine %6s %s \n", ":", temp[k].dose.booVax);
	printf("Booster Dose Location: %s \n", temp[k].dose.booLoc);

	printf("\n");
	
	
	
	printf("\n******************************************\n");
}

/*	importUsers allows the user to import users from a txt file
	@param temp[] - struct containing the imported users
	@returns the number of users
*/

int 
importUsers (struct temporary temp[])  
{
	FILE *fp;
	str30 fname;
	str30 string;
	
	char filler;
	
	int n = 0;
	
	printf("Enter file name: ");
	getString(fname, 30);
	
	strcat(fname, ".txt");
	
	fp = fopen(fname, "r");
	
	if (fp == NULL)
	{
		printf("Could not open file %s.\n", fname);
		return -1;
	}
	
	else
	{	
		fscanf(fp, "%lf", &temp[n].userID);
		
		if (temp[n].userID > 0)
		{
			filler = fgetc(fp);
			
			fgets(temp[n].passWord, sizeof(temp[n].passWord), fp);
			
			
			filler = fgetc(fp);
			fgets(temp[n].name, sizeof(temp[n].name), fp);
			fgets(temp[n].address, sizeof(temp[n].address), fp);
			filler = fgetc(fp);
			fscanf(fp, "%lf", &temp[n].contact);
			filler = fgetc(fp);
			fscanf(fp, "%s", temp[n].sex);
			filler = fgetc(fp);
			fscanf(fp, "%s", temp[n].firstLoc);
			filler = fgetc(fp);
			fscanf(fp, "%s", temp[n].firstDate);
			filler = fgetc(fp);
			fscanf(fp, "%s", temp[n].firstVax);
			filler = fgetc(fp);		
			fscanf(fp, "%s", temp[n].dose.secLoc);
			filler = fgetc(fp);
			fscanf(fp, "%s", temp[n].dose.secDate);
			filler = fgetc(fp);
			fscanf(fp, "%s", temp[n].dose.secVax);
			filler = fgetc(fp);
			fscanf(fp, "%s", temp[n].dose.booLoc);
			filler = fgetc(fp);
			fscanf(fp, "%s", temp[n].dose.booDate);
			filler = fgetc(fp);
			fscanf(fp, "%s", temp[n].dose.booVax);
			
			
			
				
			while (fgets(string, sizeof(string), fp) != NULL)
			{
				n++;
				fscanf(fp, "%lf", &temp[n].userID);

				filler = fgetc(fp);
							
				fgets(temp[n].passWord, sizeof(temp[n].passWord), fp);
				filler = fgetc(fp);

				fgets(temp[n].name, sizeof(temp[n].name), fp);
				fgets(temp[n].address, sizeof(temp[n].address), fp);
				filler = fgetc(fp);
				fscanf(fp, "%lf", &temp[n].contact);
				filler = fgetc(fp);
				fscanf(fp, "%s", temp[n].sex);
				filler = fgetc(fp);
				fscanf(fp, "%s", temp[n].firstLoc);
				filler = fgetc(fp);
				fscanf(fp, "%s", temp[n].firstDate);
				filler = fgetc(fp);
				fscanf(fp, "%s", temp[n].firstVax);
				filler = fgetc(fp);		
				fscanf(fp, "%s", temp[n].dose.secLoc);
				filler = fgetc(fp);
				fscanf(fp, "%s", temp[n].dose.secDate);
				filler = fgetc(fp);
				fscanf(fp, "%s", temp[n].dose.secVax);
				filler = fgetc(fp);
				fscanf(fp, "%s", temp[n].dose.booLoc);
				filler = fgetc(fp);
				fscanf(fp, "%s", temp[n].dose.booDate);
				filler = fgetc(fp);
				fscanf(fp, "%s", temp[n].dose.booVax);

				
			}
		}
					
		printf("%c", filler);
		system("cls");
		
		fclose(fp);
		
	}
	
	return n;     // will edit
}

/*	addChoice asks the user if they want to add the imported user to the database
	@returns the choice of the user
	Pre-condition: all inputs are integers
*/

int
addChoice()
{
	int choice;

		printf("\n");
		printf ("\n[1] Add User \n");
		printf("[2] Next User\n");
		printf("[3] Exit\n");
		printf("\n");

		printf("Input: ");
		scanf("%d", &choice);

		while (choice > 3 || choice < 1)
		{
			printf ("Invalid input. Please try again: ");
			scanf("%d", &choice);
		}

	return choice;
}

/*	shiftImportsU shifts the next user to the preceding index
	@param temp[] - struct containing the imported users
	@param i - index of the structS
*/

void 
shiftImportsU (struct temporary temp[], 
			   int i)
{
	temp[i].userID = temp[i+1].userID; 
	strcpy(temp[i].name, temp[i+1].name);
	strcpy(temp[i].address, temp[i+1].address);
	strcpy(temp[i].passWord, temp[i+1].passWord);
	temp[i].contact = temp[i+1].contact;
	strcpy(temp[i].sex, temp[i+1].sex);
	strcpy(temp[i].firstDate, temp[i+1].firstDate);
	strcpy(temp[i].firstVax, temp[i+1].firstVax);
	strcpy(temp[i].firstLoc, temp[i+1].firstLoc);
	strcpy(temp[i].dose.secVax, temp[i+1].dose.secVax);
	strcpy(temp[i].dose.secLoc, temp[i+1].dose.secLoc);
	strcpy(temp[i].dose.secDate, temp[i+1].dose.secDate);
	strcpy(temp[i].dose.booVax, temp[i+1].dose.booVax);
	strcpy(temp[i].dose.booLoc, temp[i+1].dose.booLoc);
	strcpy(temp[i].dose.booDate, temp[i+1].dose.booDate);
}

/*	addImportedUser adds the imported user to the database
	@param temp[] - struct containing the imported users
	@param user[] - struct containing the registered users
	@param i - index of the imported user
	@param k - index of the user where the imported user will be moved
*/

void 
addImportedUser (struct temporary temp[], 
				 struct userInfo user[], 
				 int i, 
				 int k)
{
	user[k].userID = temp[i].userID; 
	strcpy(user[k].name, temp[i].name);
	strcpy(user[k].address, temp[i].address);
	strcpy(user[k].passWord, temp[i].passWord);
	user[k].contact = temp[i].contact;
	strcpy(user[k].sex, temp[i].sex);
	strcpy(user[k].firstDate, temp[i].firstDate);
	strcpy(user[k].firstVax, temp[i].firstVax);
	strcpy(user[k].firstLoc, temp[i].firstLoc);
	strcpy(user[k].dose.secVax, temp[i].dose.secVax);
	strcpy(user[k].dose.secLoc, temp[i].dose.secLoc);
	strcpy(user[k].dose.secDate, temp[i].dose.secDate);
	strcpy(user[k].dose.booVax, temp[i].dose.booVax);
	strcpy(user[k].dose.booLoc, temp[i].dose.booLoc);
	strcpy(user[k].dose.booDate, temp[i].dose.booDate);

	removeNewLine (user[k].name);
	removeNewLine (user[k].address);
	removeNewLine (user[k].passWord);
	removeNewLine (user[k].sex);
	removeNewLine (user[k].firstDate);
	removeNewLine (user[k].firstVax);
	removeNewLine (user[k].firstLoc);
	removeNewLine (user[k].dose.secVax);
	removeNewLine (user[k].dose.secLoc);
	removeNewLine (user[k].dose.secDate);
	removeNewLine (user[k].dose.booVax);
	removeNewLine (user[k].dose.booLoc);
	removeNewLine (user[k].dose.booDate);

}

/*	delTemp deletes all the data in the temp[] struct
	@param n - index of the struct
*/

void 
delTemp (struct temporary temp[], 
		 int n)
{
	temp[n].userID = 0;
	temp[n].name[0] = '\0';
	temp[n].address[0] = '\0';
	temp[n].contact = 0;
	temp[n].passWord[0] = '\0';
	temp[n].sex[0] = '\0';
	temp[n].firstVax[0] = '\0';
	temp[n].firstLoc[0] = '\0';
	temp[n].firstDate[0] = '\0';

	temp[n].dose.secVax[0] = '\0';
	temp[n].dose.secLoc[0] = '\0';
	temp[n].dose.secDate[0] = '\0';
	temp[n].dose.booVax[0] = '\0';
	temp[n].dose.booDate[0] = '\0';
	temp[n].dose.booLoc[0] = '\0';
}

/*	addUserOrNo asks the user if they want to add the user to the database then adds it if yes
	@param temp[] - struct containing the imported users
	@param user[] - struct containing the registered users
	@param k - number of registered users
	@returns the number of added users
*/

int 
addUserOrNo (struct temporary temp[], 
			 struct userInfo user[], 
			 int k)
{
	int i, p, choice;
	int n = importUsers (temp);
	int ctr = 0;
	int m = n;

	if (n > 0)
	{
		if (k > 0)
		{
			do
			{
				for (i = 0; i < n && choice != 3; i++)
				{

					system("cls");

					displayImportedUsers(temp, i);
					
					choice = addChoice();
					
					if (choice == 1)
					{
						n--;
						ctr++;

						addImportedUser(temp, user, i, k);

						for (p = i; p < n; p++)
						{
							shiftImportsU (temp, p);
						}

							if (n == 0)
						{
							printf("You have successfully imported all of the users.\n\n");
							return ctr;
						}

						k++;
					}
				}

			} while (choice != 3);
		}
		
		else if (k == 0)
		{
			for (i = 0; i < n; i++)
			{
				addImportedUser(temp, user, i, k);
				k++;
				ctr++;
			}
		}

		for (i = 0; i < m; i++)
		{
			delTemp (temp, n);
		}

		printf("You have successfully imported the users.\n");
		
	}

	return ctr;
}

/*	removeNewLine removes the new line in the string
	@param string - the string to be manipulated
*/

void 
removeNewLine (char string []) // removes new line
{                                   
	int n = strlen (string);
	int i;
	
	for (i = 0; i < n; i++)
	    {
	        if (string[i] == '\n')
	        	string[i] = '\0';
		}

}

/*	sortUsers sorts the users based on their user ID
	@param user[] - struct containing the registered users
	@param k - number of registered users
*/

void 
sortUsers (struct userInfo user[], 
		   int k)
{
	int i, j;

	struct userInfo temp;


		for (i = 0; i < k; i++)
		{

			for (j = i + 1; j < k; j++)
			{
				if (user[i].userID > user[j].userID)
				{
					temp = user[i];
					user[i] = user[j];
					user[j] = temp;
					
				}
			}
		}

		for (i = 0; i < k; i++)
		{
			displayData(user, &i, 1);
		}

}

/*	displayImpApps diplays the imported appointments
	@param temp2[] - struct containing the imported appointments
	@param k - index of the struct
*/

void 
displayImpApps (struct temporary2 temp2[], 
				int k)
{
	printf("******************************************\n");
	printf("\n \t %15s \n", "APPOINTMENT REQUEST DATA");
	printf("\n");
	
	printf("Appointment ID: %.0lf \n", temp2[k].appID);
	printf("User ID %7s %.0lf \n", ":", temp2[k].userID);
	printf("Name %10s %s \n", ":", temp2[k].name);
	printf("Location %6s %s \n", ":", temp2[k].location);
	printf("Vaccine %7s %s \n", ":", temp2[k].vaccine);
	printf("Date %10s %s \n", ":", temp2[k].date);
	printf("Time %10s %s \n", ":", temp2[k].time);
	printf("Dose %10s %s \n", ":", temp2[k].dose);
	printf("\n\n******************************************\n");
}

/*	importApps allows the user to import appointments
	@param temp2[] - struct containing the imported appointments
	@returns the number of imported appointments
*/

int 
importApps (struct temporary2 temp2[])
{
	FILE *fp;
	str30 fname;
	str30 string;
	
	char filler;
	
	int n = 0, ctr = 0;
	
	printf("Enter file name: ");
	getString(fname, 30);
	
	strcat(fname, ".txt");
	
	fp = fopen(fname, "r");
	
	if (fp == NULL)
	{
		printf("Could not open file %s.\n", fname);
		return -1;
	}
	
	else
	{	
		fscanf(fp, "%lf", &temp2[n].appID);
		
		if (temp2[n].appID > 0)
		{
			ctr++;

			filler = fgetc(fp);
			fscanf(fp, "%lf", &temp2[n].userID);
			filler = fgetc(fp);
			fgets (temp2[n].name, sizeof(temp2[n].name), fp);
			fgets (temp2[n].location, sizeof(temp2[n].location), fp);
			// fgets (temp2[n].vaccine, sizeof(temp2[n].vaccine), fp);
			fscanf(fp, "%s", temp2[n].vaccine);
			fscanf(fp, "%s", temp2[n].date);
			filler = fgetc(fp);
			fscanf(fp, "%s", temp2[n].time);
			filler = fgetc(fp);
			fgets (temp2[n].dose, sizeof(temp2[n].dose), fp);
			
			n++;
			
				
			while (fgets(string, sizeof(string), fp) != NULL)
			{
				
			fscanf(fp, "%lf", &temp2[n].appID);

				if (temp2[n].appID > 0)
					ctr++;

				filler = fgetc(fp);
				fscanf(fp, "%lf", &temp2[n].userID);
				filler = fgetc(fp);
				fgets (temp2[n].name, sizeof(temp2[n].name), fp);
				fgets (temp2[n].location, sizeof(temp2[n].location), fp);
				// fgets (temp2[n].vaccine, sizeof(temp2[n].vaccine), fp);
				fscanf(fp, "%s", temp2[n].vaccine);
				fscanf(fp, "%s", temp2[n].date);
				filler = fgetc(fp);
				fscanf(fp, "%s", temp2[n].time);
				filler = fgetc(fp);
				fgets (temp2[n].dose, sizeof(temp2[n].dose), fp);

				n++;
				
			}
		}
					
		printf("%c", filler);
		system("cls");
		
		fclose(fp);
		
	}

	return ctr;
	
}

/*	addImpAppChoice allows the user to add an appointment or skip to the next user
	@returns the choice of the user
*/

int 
addImpAppChoice()
{
	int choice;

		printf("\n");
		printf ("\n[1] Add Appointment \n");
		printf("[2] Next User\n");
		printf("[3] Exit\n");
		printf("\n");

		printf("Input: ");
		scanf("%d", &choice);

		while (choice > 3 || choice < 1)
		{
			printf ("Invalid input. Please try again: ");
			scanf("%d", &choice);
		}

	return choice;
}

/*	addImportedApp adds the imported appointments to the existing database
	@param temp2[] - struct containing the imported appointments
	@param user[] - struct containing the users
	@param k - number of users
	@param n - index of the imported appointment
	@returns 1 if import successful
*/

int 
addImportedApp (struct temporary2 temp2[], 
				struct userInfo user[], 
				int k, 
				int n)
{
	int i, j, valid; 

	for (i = 0; i < k; i++)
	{
		if (user[i].userID == temp2[n].userID)
		{	
			valid = 1;
			j = i;
		}
			
	}

	if (valid == 1)
	{
		user[j].app.appID = temp2[n].appID;
		strcpy(user[j].app.name, temp2[n].name);
		strcpy(user[j].app.location, temp2[n].location);
		strcpy(user[j].app.vaccine, temp2[n].vaccine);
		strcpy(user[j].app.date, temp2[n].date);
		strcpy(user[j].app.time, temp2[n].time);
		strcpy(user[j].app.dose, temp2[n].dose);

		removeNewLine (user[j].app.name);
		removeNewLine (user[j].app.location);
		removeNewLine (user[j].app.vaccine);
		removeNewLine (user[j].app.date);
		removeNewLine (user[j].app.time);
		removeNewLine (user[j].app.dose);

		return 1;
	}

	return -1;
}

/*	shiftImpApp shifts the next appointment to the preceding one
	@param temp2[] - struct containing the imported appointments
	@param i - index of the struct
*/

void 
shiftImpApp (struct temporary2 temp2[], 
			 int i)
{
	temp2[i].appID = temp2[i+1].appID;
	temp2[i].userID = temp2[i+1].userID;

	strcpy(temp2[i].name, temp2[i+1].name);
	strcpy(temp2[i].location, temp2[i+1].location);
	strcpy(temp2[i].vaccine, temp2[i+1].vaccine);
	strcpy(temp2[i].date, temp2[i+1].date);
	strcpy(temp2[i].time, temp2[i+1].time);
	strcpy(temp2[i].dose, temp2[i+1].dose);
}

/*	addAppOrNo adds appointments to the existing users
	@param temp2[] - struct containing the imported appointments
	@param user[] - struct containing the users
	@param k - number of users
*/

void 
addAppOrNo (struct temporary2 temp2[], 
			struct userInfo user[], 
			int k)
{
	int i, p, choice, valid;
	int n = importApps(temp2);
	
	if (n > 0)
	{
		if (k > 0)
		{
			do
			{
				for (i = 0; i < n && choice != 3; i++)
				{

					system("cls");

					displayImpApps(temp2, i);
					
					choice = addImpAppChoice();
					
					if (choice == 1)
					{
						n--;

						valid = addImportedApp (temp2, user, k, i);

						if (valid == 1)
						{
							for (p = i; p < n; p++)
							{
								shiftImpApp (temp2, p);
							}
						}

						else
						{
							printf("User not found.\n\n");

							choice = addImpAppChoice();

						}

							if (n == 0)
						{
							printf("You have successfully imported all of the appointments.\n\n");
							return;
						}
					}
				}

			} while (choice != 3);
		}
		
		else if (k == 0)
		{
			printf("No registered users.\n\n");
		}
		
	}

}

/*
	importChoice allows the user to pick between importing users or appointments
	@returns the choice of the user
*/

int 
importChoice ()
{
	int choice; 

		printf("IMPORT FILES\n");
		printf ("\n[1] Users\n");
		printf("[2] Appointments\n");
		printf("[3] Exit\n");
		printf("\n");

		printf("Input: ");
		scanf("%d", &choice);

		while (choice > 3 || choice < 1)
		{
			printf ("Invalid input. Please try again: ");
			scanf("%d", &choice);
		}

	return choice;
}

/*
	exportChoice allows the user to pick between exporting users or appointments
	@returns the choice of the user
*/

int 
exportChoice ()
{
	int choice; 

		printf("EXPORT FILES\n");
		printf ("\n[1] Users\n");
		printf("[2] Appointments\n");
		printf("[3] Exit\n");
		printf("\n");

		printf("Input: ");
		scanf("%d", &choice);

		while (choice > 3 || choice < 1)
		{
			printf ("Invalid input. Please try again: ");
			scanf("%d", &choice);
		}

	return choice;
}

/*	export exports the user and appointment data
	@param user[] - struct containing the user data
*/

void 
export (struct userInfo user[], 
		int *k)
{
	int choice =exportChoice();

	switch (choice)
	{
		case 1: 
			exportUsers(user, k);
			printf("You have successfully exported the data. \n");
			break;
		case 2: 
			exportApps(user, k);
			printf("You have successfully exported the data. \n");
			break;
	}
}

/*	storeApps exports the appointment data
	@param user[] - struct containing the user data
	@param *k - number of users
*/

void 
storeApps (struct userInfo user[], 
		   int *k)
{
	FILE *fp; 

	fp = fopen ("Appointment.txt", "w");

	int i;

	for (i = 0; i < *k; i++)
	{
		if (user[i].app.appID > 0)
		{
			fprintf(fp, "%.0lf %.0lf\n", user[i].app.appID, user[i].userID);
			fprintf(fp, "%s\n", user[i].app.name);
			fprintf(fp, "%s\n", user[i].app.location);
			fprintf(fp, "%s\n", user[i].app.vaccine);
			fprintf(fp, "%s\n", user[i].app.date);
			fprintf(fp, "%s\n", user[i].app.time);
			fprintf(fp, "%s\n", user[i].app.dose);
			fprintf(fp, "\n");
		}
		
	}

	fclose(fp);
}

/*	exportApps exports the appointment data with the user giving the file name
	@param user[] - struct containing the user data
	@param *k - number of users
*/

void 
exportApps (struct userInfo user[], 
			int *k)
{
	FILE *fp; 
	str30 fname;

	printf("Enter file name: ");
	getString(fname, 30);
	
	strcat(fname, ".txt");

	fp = fopen (fname, "w");

	int i;

	for (i = 0; i < *k; i++)
	{
		if (user[i].app.appID > 0)
		{
			fprintf(fp, "%.0lf %.0lf\n", user[i].app.appID, user[i].userID);
			fprintf(fp, "%s\n", user[i].app.name);
			fprintf(fp, "%s\n", user[i].app.location);
			fprintf(fp, "%s\n", user[i].app.vaccine);
			fprintf(fp, "%s\n", user[i].app.date);
			fprintf(fp, "%s\n", user[i].app.time);
			fprintf(fp, "%s\n", user[i].app.dose);
			fprintf(fp, "\n");
		}
		
	}

	fclose(fp);
}

/*	vaccineValid checks if the vaccine entered by the user is valid
	@param vaccine - the string to be checked
	@returns 1 if the vaccine is valid and 0 if not
*/

int 
vaccineValid (char vaccine[])
{
	int valid = 0;

	if (strcmp(vaccine, "Pfizer") == 0)
		valid = 1;
	if (strcmp(vaccine, "Sinovac") == 0)
		valid = 1;
	if (strcmp(vaccine, "Moderna") == 0)
		valid = 1;
	if (strcmp(vaccine, "Sputnik") == 0)
		valid = 1;
	if (strcmp(vaccine, "Astra") == 0)
		valid = 1;
	if (strcmp(vaccine, "Janssen") == 0)
		valid = 1;
	if (strcmp(vaccine, "Sinopharm") == 0)
		valid = 1;
	if (strcmp(vaccine, "Covaxin") == 0)
		valid = 1;
	if (strcmp(vaccine, "Novavax") == 0)
		valid = 1;

	return valid;
}


