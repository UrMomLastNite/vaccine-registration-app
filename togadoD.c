/*********************************************************************************************************
This is to certify that this project is my own work, based on my personal efforts in studying and applying the concepts
learned. I have constructed the functions and their respective algorithms and corresponding code by myself. The
program was run, tested, and debugged by my own efforts. I further certify that I have not copied in part or whole or
otherwise plagiarized the work of other students and/or persons.

 TOGADO, DALRIANNE FRANCESCA B., DLSU ID# 12295069
*********************************************************************************************************/

/*
	Programmed by: Dalrianne Francesca Togado - S18A
	Last modified: 04/7/2023
	Version: 9
*/

// gcc -Wall -std=c99 togadoD.c func4.c -o main && main

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "header4.h"
#define MAX 100
typedef char str20[21];
typedef char str30[31];
typedef char str10[11];

int 
main ()
{	
	int mainChoice, vaxChoice, dataChoice, userChoice, delete;   // for menu choices

	char input; 												// for Y/N choices
	
	int k = 0;													// struct array index
	
	int exit, valid, invalid, add, choice;						

	// system("cls");
	
	struct userInfo user[MAX];									// struct for users 

	struct chatbot faqs[MAX];									// struct for FAQs

	struct temporary temp[MAX];									// struct for imported users

	struct temporary2 temp2[MAX];								// struct for imported appointments
	
	do 
	{			
		mainChoice = mainMenu();								// main menu 
		
		switch (mainChoice)
		{
			case 1: 
				do
				{
					vaxChoice = vaxRegMenu();   				// vax reg menu 
					
					do
					{
						vaxReg(user, vaxChoice, &k);            // vax reg submenus

						switch (vaxChoice)
						{
							case 1: 							// vaccine registration
								k++;							// increments by one if a user registers
								exit = exitFunc();				// asks to click 1 to exit
								system("cls");
								break;

							case 2:
								invalid = appointment(user, &k);	// checks if log in is successful or not + allows the user to request an
																	// appointment if log in is successful

								if (invalid == 1)					// gets executed if log in is successful
								{	
									exit = 1;
									system("cls");
								}

								else
									return 0;						// ends the program if log in unsuccessful

								break;

							case 3: 
								exit = exitFunc();					// asks the user to click 1 to exit
								system("cls");
								break;
						}

					} while (exit != 1 && vaxChoice != 4);		 	// user exits the loop when exit == 1 or vaxChoice == 4
					
				} while (vaxChoice != 4);					 		// user returns to main menu when user picks 4

				break;
			
				
			case 2:                									// data management menu
				do
				{
					valid = adminLogin();							// becomes == 1 if admin log in is successful 

					if (valid == 1)
					{
						do 
						{
							dataChoice = dataMenu();				// data management menu

							switch(dataChoice)
							{
								case 1:
									do
									{
										userChoice = userMenu();	// user menu

										do
										{											
											switch (userChoice)
											{
												case 1:
													userMain(user, &k, userChoice);			 // allows the admin to add users
														k++;								 // increments by one if a user is added

													if (k >= MAX)
													{
														printf("\n");
													}

													else 
													{
														input = yesNoAdd();					  // asks user if they want to add more users

														while (input == 'y' || input == 'Y')  // gets executed if user picks yes
														{
															system("cls");

															addUser(user, &k);
															k++;
															input = yesNoAdd();
														}
													}
														exit = exitFunc();
														system ("cls");

													break;

												case 2: 
													userMain(user, &k, userChoice);			// allows the admin to view all the users
													exit = exitFunc();
													system("cls");
													break;

												case 3: 
													userMain(user, &k, userChoice);			// allows the admin to edit the users
													exit = exitFunc();
													system("cls");
													break;

												case 4:
													delete = deleteUsers(user, &k);			// allows the admin to delete users
													k -= delete;

													storeUsers (user, &k);

													exit = exitFunc();

													system("cls");
													
													break;

											}

										} while (exit != 1 && userChoice!= 5);

									} while (userChoice != 5);							// user returns to data management menu when this variable becomes == 5
									
									break;

								case 2: 
									appData (user, &k);									// allows the admin to access appointment data
									break;

								case 3:
									chatbotData(faqs);									// allows the admin to access chatbot data
									break;

								case 4:
									export(user, &k);									// allows the admin to export data
									exitz();
									system("cls");
									break;

								case 5:
									choice = importChoice();							// allows the admin to import data

									switch (choice)
									{
										case 1: 
											if (k >= MAX)
												{
													printf("Maximum capacity of users reached. \n\n");
												}

											else
											{
												add = addUserOrNo(temp, user, k);		// imports users
												k += add;
											}
											
											exitz();
											break; 

										case 2:
											addAppOrNo (temp2, user, k);				// imports appointments
											exitz();
											break;
									}
									system("cls");
									break;

								case 6:
									storeUsers(user, &k);					// exports users
									storeApps (user, &k);					// exports appointments
									break;

							} // datachoice switch bracket

						} while (dataChoice != 6);    // user returns to main menu when user picks 6	
													
					}  // valid == 1 bracket

					else
					{
						printf("You have exceeded the maximum number of login attempts.\n");
						return 0;       // terminates the program when the admin log in attempt exceeds the max num of log in attempts
					}
						
					
			} while (valid != 0 && dataChoice != 6);  // user returns to main menu when admin log in is invalid or when the user picks 6 in data management menu 
				break;				
		

		} // mainChoice switch 
		
	} while (mainChoice !=3);
	
	
	return 0;
}

