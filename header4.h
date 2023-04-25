#ifndef HEADERFILE_H
#define HEADERFILE_H

typedef char str20[21];
typedef char str30[31];
typedef char str10[11];
typedef char str80[81];

struct chatbot
{
	str80 question;
	str80 answer;
};

struct optionalInfo
{
	str10 secDate;
	str10 secVax;
	str10 secLoc;
	str10 booDate;
	str10 booVax;
	str10 booLoc;
};

struct appRequest
{
	double appID;
	str20 name;
	str10 location;
	str10 vaccine; 
	str10 time; 
	str10 date;
	str20 dose; 
};

struct userInfo // struct of the user info
{
	double userID;
	str10 passWord;
	str20 name;
	str30 address;
	double contact;
	str10 sex;
	str10 firstDate;
	str10 firstVax;
	str10 firstLoc;

	int doses;

	// optional info

	struct optionalInfo dose;
	
	// info for appointment request
	
	struct appRequest app;

};

struct temporary
{
	double userID;
	str10 passWord;
	str20 name;
	str30 address;
	double contact;
	str10 sex;
	str10 firstDate;
	str10 firstVax;
	str10 firstLoc;
	
	struct optionalInfo dose;

};

struct temporary2
{
	double appID;
	double userID;
	str20 name;
	str10 location;
	str10 vaccine; 
	str10 time; 
	str10 date;
	str20 dose; 
};

void displayData (struct userInfo user[], int *k, int n);

int vaxRegMenu (); // vax registration menu

int appointment (struct userInfo user[], 
				int *k);

int mainMenu (); // asks user to pick a menu

void userReg(struct userInfo user1[], int *k);  // gets the input for the user info

void vaxReg (struct userInfo user[], int vaxChoice, int *k);  // whole vax registration submenus

void getString (char string[], int n);

int vaxAppMenu ();

void printAllUsers (struct userInfo user[], int *k);

void userSex (struct userInfo user [], int *k, char sexx);

int adminLogin ();

int dataMenu ();

int userMenu();

void userMain (struct userInfo user[], int *k, int userChoice);

void addUser (struct userInfo user[], int *k); 

int exitFunc();

void exitz ();

char yesNoAdd ();

void editUser (struct userInfo user[], int *k);

int editChoice ();

void editDetails (struct userInfo user[], int k);

int checkID (struct userInfo user[], int k);

void exportUsers (struct userInfo user [], int *k);

void storeUsers (struct userInfo user[], int *k);

int deleteUsers (struct userInfo user[], int *k);

int deleteChoice ();

void shiftDelUsers (struct userInfo user[], int i);

int appointmentLogIn (struct userInfo user[], int *k);

int isValid (struct userInfo user[], double id, str10 pass, int *k);

void appRequest (struct userInfo user[], int i, int *k);

int checkAppID (struct userInfo user[], int n, int k);

void displayAppointment (struct userInfo user[], int k);

void toString (struct userInfo user[], int k);

void toStringSec (struct userInfo user[], int k);

void toStringBoo (struct userInfo user[], int k);

void toStringApp (struct userInfo user[], int k);

void time (struct userInfo user[], int k);

void manageApp (struct userInfo user[], int k);

void manageDeets (struct userInfo user[], int k);

void cancelApp (struct userInfo user[], int k);

int appMenu ();

void appData (struct userInfo user[], int *k);

void printApps (struct userInfo user[], int *k);

void sortApps (struct userInfo user[], int k);

void addApp (struct userInfo user[], int *k);

int addAppChoice (int n);

void editApp (struct userInfo user[], int *k);

int editAppChoice (int n);

void editAppDeetz (struct userInfo user[], int k, int *n);

void deleteApp (struct userInfo user[], int *k);

int deleteAppChoice (int n);

void chatbot ();

void chatbotMenu ();

void convertUpper (char array[]);

void removeNew (str80 string);

int importFaqs(struct chatbot faqs[]);

void storeFaqs (struct chatbot faqs[]);

void viewAllFaqs ();

void editFaqs (struct chatbot faqs[], int i);

void editChatbot (struct chatbot faqs[]);

void addFaqs (struct chatbot faqs[]);

void shiftDelFaqs(struct chatbot faqs[], int n);

void deleteFaqs (struct chatbot faqs[], int i);

void deleteChatbot (struct chatbot faqs[]);

void chatbotData (struct chatbot faqs[]);

void displayImportedUsers (struct temporary temp[], int k);

int importUsers (struct temporary temp[]);

int addChoice();

void shiftImportsU (struct temporary temp[], int i);

void addImportedUser (struct temporary temp[], struct userInfo user[], int i, int k);

void delTemp (struct temporary temp[], int n);

int addUserOrNo (struct temporary temp[], struct userInfo user[], int k);

void removeNewLine (char string []);

void sortUsers (struct userInfo user[], int k);

void displayImpApps (struct temporary2 temp2[], int k);

int importApps (struct temporary2 temp2[]);

int addImpAppChoice();

int addImportedApp (struct temporary2 temp2[], struct userInfo user[], int k, int n);

void shiftImpApp (struct temporary2 temp2[], int i);

void addAppOrNo (struct temporary2 temp2[], struct userInfo user[], int k);

int importChoice ();

void export (struct userInfo user[], int *k);

void exportApps (struct userInfo user[], int *k);

void storeApps (struct userInfo user[], int *k);

int vaccineValid (char vaccine[]);

#endif
