#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

struct pass {
	char username[50];
	int tanggal, bulan, tahun;
	int age;
	char Phonenumber[15];
	char Firstname[20];
	char Lastname[20];
	char address[50];
	char password[20];
};

struct money {
    char tousername[50];
    char fromusername[50];
    int money1;
};


void createAccount(void) {
	struct pass p1;
	char ch;
	int i;
	char password [20];
	FILE *fp, *fu;

	system("cls");
	printf("CREATE ACCOUNT\n");
  
    printf("Masukkan Nama Pertama Anda: ");
	scanf("%s", &p1.Firstname);

    printf("Masukkan Nama Terakhir Anda: ");
	scanf("%s", &p1.Lastname);


    printf("Masukkan Umur Anda: ");
    scanf("%d", &p1.age);
    getchar(); 

   
	printf("\n\nTanggal Lahir");
	printf("\nDATE-");
	scanf("%d", &p1.tanggal);
	printf("\nMONTH-");
	scanf("%d", &p1.bulan);
	printf("\nYEAR-");
	scanf("%d", &p1.tahun);
    getchar(); 
  	
    printf("\n\nMasukkan Nomor Telepon Anda: ");
    scanf("%s", &p1.Phonenumber);
    getchar(); 
	
	printf("\n\nMasukan Username anda: ");
    scanf("%s", &p1.username);

	printf("Masukkan Password yang ingin Anda buat: ");
	for (i = 0; i < 50; i++) {
		ch = getch();
		if (ch != 13) {
			p1.password[i] = ch;
			ch = '*';
			printf("%c", ch);
		}
		else
			break;
	}
	
    fp = fopen("users.dat", "ab");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    printf("\n\n=============== Data Akun ===============\n");
    printf("Nama: %s %s\n", p1.Firstname, p1.Lastname);
    printf("Umur: %d\n", p1.age);
    printf("Tanggal Lahir: %02d-%02d-%04d\n", p1.tanggal, p1.bulan, p1.tahun);
    printf("Nomor Telepon: %lld\n", p1.Phonenumber);
    printf("Username anda adalah: %s\n", p1.username);
    printf("Password: %s\n", p1.password);

    
    fwrite(&p1, sizeof(p1),	1, fp);
    fclose(fp);
    
	printf("\n\nPLEASE WAIT....\n\nDATA IS PROCESSING.... \n");
	for (i = 0; i < 200000000; i++) {
		i++;
		i--;
	}

	printf("\nAccount created\n");

	printf("Press enter to login\n");

	getch();
	loginAccount();
}

void loginAccount(void){
	system("cls");
	int i;
	char username[50];
    char password[20];
    struct pass p1;
    FILE *fp;

    // Open file for reading
    fp = fopen("users.dat", "rb");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("ACCOUNT LOGIN\n");
    printf("==============\n");

    printf("USERNAME: ");
    scanf("%s", username);

    printf("PASSWORD: ");
    for (i = 0; i < 20; i++) { // Limit to 20 characters
        char ch = getch();
        if (ch != 13) { // Enter key
            password[i] = ch;
            ch = '*';
            printf("%c", ch);
        } else {
            password[i] = '\0'; // Null-terminate the string
            break;
        }
    }

    // Check if username exists in the file
    int found = 0;
    while (fread(&p1, sizeof(p1), 1, fp)) {
        if (strcmp(username, p1.username) == 0) {
            found = 1;
            // Check if the password matches
            if (strcmp(password, p1.password) == 0) {
                printf("\nWelcome, %s %s!\n", p1.Firstname, p1.Lastname);
                display(username);
            } else {
                printf("\nIncorrect password. Please try again.\n");
                getch();
                system("cls");
                loginAccount();
            }
            break;
        }
    }

    if (!found) {
        printf("\nUsername not found. Please try again.\n");
    }

    fclose(fp);
    printf("Press enter to return to the main menu...\n");
    getch();
    ;
}

	void loginsucess(void){
	int i;
	FILE* fp;
	struct pass u1;
	system("cls");
	printf("Fetching account details.....\n");
	for (i = 0; i < 20000; i++) {
		i++;
		i--;
	}

	printf("LOGIN SUCCESSFUL....\n");
	printf("Press enter to continue\n");

	getch();
}
void display(char username1[])
{
	system("cls");
	FILE* fp;
	int choice, i;
	fp = fopen("users.dat", "rb");
	struct pass p1;

	if (fp == NULL) {
		printf("error in opening file");
	}

	while (fread(&p1, sizeof(p1),
				1, fp)) {
		if (strcmp(username1,
				p1.username)
			== 0) {
			printf("WELCOME, %s %s\n",
				p1.Firstname, p1.Lastname);
			printf("..........................\n\n");

			printf("==== YOUR ACCOUNT INFO ====\n");

			printf("***************************\n");

			printf("\nName: %s %s\n", p1.Firstname,
				p1.Lastname);

			printf("Mobile Number: %s\n",
				p1.Phonenumber);

			printf("Date of Birth: %d-%d-%d\n",
				p1.tanggal, p1.bulan, p1.tahun);

		}
	}

	fclose(fp);

	printf("\n****************************\n");
	printf(" 1. CHECK BALANCE\n\n");
	printf(" 2. TRANSFER MONEY\n\n");
	printf(" 3. LOG OUT\n\n");
	printf(" 4. EXIT\n\n");

	printf(" Enter your choice: ");
	scanf("%d", &choice);

	switch (choice) {
	case 1:
		checkbalance(username1);
		break;

	case 2:
		transfermoney();
		break;

	case 3:
		logout();
		loginAccount();
		break;

	case 4:
		exit(0);
		break;
	}
}
void logout(void)
{
	int i, j;
	system("cls");
	printf("please wait, logging out\n");

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 25000000; j++) {
			i++;
			i--;
		}
		printf(".");
	}

	printf("Sign out successfully..\n");

	printf("press enter to continue..\n");

	getch();
}
void transfermoney(void) {
    int i, j;
    FILE *fm, *fp;
    struct pass user;
    struct money m1;
    char usernamet[20];
    char usernamep[20];
    system("cls");
    int fromExists = 0, toExists = 0;

    fp = fopen("users.dat", "rb");
    if (fp == NULL) {
        printf("Error opening username file!\n");
        return;
    }

    fm = fopen("mon.txt", "ab");
    if (fm == NULL) {
        printf("Error opening money file!\n");
        fclose(fp);
        return;
    }

    printf("---- TRANSFER MONEY ----\n");
    printf("========================\n");

    printf("From(your username): ");
    scanf("%s", usernamet);

    printf("To(username of person): ");
    scanf("%s", usernamep);

    // Check if both usernames exist in the user data file
    while (fread(&user, sizeof(user), 1, fp)) {
        if (strcmp(usernamet, user.username) == 0) {
            fromExists = 1; // Found the sender's username
        }
        if (strcmp(usernamep, user.username) == 0) {
            toExists = 1; // Found the recipient's username
        }
        // If both usernames are found, no need to continue searching
        if (fromExists && toExists) {
            break;
        }
    }

    // Check if both usernames were found
    if (!fromExists) {
        printf("Error: Your username '%s' does not exist.\n", usernamet);
        fclose(fp);
        fclose(fm);
        return;
    }
    if (!toExists) {
        printf("Error: The sender username '%s' does not exist.\n", usernamep);
        fclose(fp);
        fclose(fm);
        return;
    }

    printf("ENTER THE AMOUNT TO BE TRANSFERRED.. ");
    scanf("%d", &m1.money1);
	
	strcpy(m1.fromusername, usernamet);
    strcpy(m1.tousername, usernamep);
	
    // Writing to the file
    fwrite(&m1, sizeof(m1), 1, fm);

    printf("--------------------------------------------------\n");
    printf("Transferring amount, Please wait..\n");

    for (i = 0; i < 70; i++) {
        for (j = 0; j < 1200000; j++) {
            j++;
            j--;
        }
        printf("*");
    }

    printf("\nAMOUNT SUCCESSFULLY TRANSFERRED....\n");
    printf("Press enter to go back\n");
    getch();

    // Close the files
    fclose(fp);
    fclose(fm);


    display(usernamet);
}

void checkbalance(char username2[]) {
    system("cls");
    FILE *fm;
    struct money m1;
    int i = 1, summoney = 0;

    fm = fopen("mon.txt", "rb");
    if (fm == NULL) {
        printf("Error opening money file!\n");
        return;
    }

    printf("==== BALANCE DASHBOARD ====\n");
    printf("***************************\n");
    printf("no.\tFROM USER\tAMOUNT\n");

    // Fetch transactions where the current user is the recipient
    while (fread(&m1, sizeof(m1), 1, fm)) {
        if (strcmp(username2, m1.tousername) == 0) {
            printf("%d\t%s\t\t%d\n", i, m1.fromusername, m1.money1);
            summoney += m1.money1;
            i++;
        }
    }

    printf("\nTOTAL BALANCE RECEIVED: %d\n", summoney);
    printf("Press enter to go back\n");
    getch();

    fclose(fm);
    display(username2);
}

int main() {
	int choice;
	printf("Welcome to BINUS BANK\n");
	printf("_____________________\n");
	printf("by Alex, Fedro, Geo, Fernandes\n");
	printf("1. Create Account\n");
	printf("2. Login\n");	
	printf("3. Exit\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);
	switch (choice){
		case 1: 
			system("cls");
       		printf("\n\n USERNAME 50 CHARACTERS MAX!!");
        	printf("\n\n PASSWORD 20 CHARACTERS MAX!!");
        	createAccount();
        break;
        
        case 2:
        	loginAccount();
        break;
        
        case 3:
        	printf("Exitting program...");
        	exit(0);
        break;
        getchar();
	}
    return 0;
}
