#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_Users 100
#define MAX_IDs 100
#define MAX_pws 100
#define MAX_Stocks 100
#define MAX_Name 100

char IDs[MAX_Users][MAX_IDs]; //a two-dimensional array that stores the user's ID.
char pws[MAX_Users][MAX_pws];//a two-dimensional array that stores the user's password.
char Stocks[MAX_Stocks][MAX_Name]; //a two-dimensional array that stores the stock name.
double StockP[MAX_Stocks]; //an array to store the price of the stock.
double Balances[MAX_Users] = {0}; //an array to store the user's balance.
int usernum = 2; //initial setting.
int stocknum = 3;
int StockOwnership[MAX_Users][MAX_Stocks] = {0}; //a two-dimensional array that stores the user's ownership.


//function to use.
void mainmenu();
void login();
void registration();
void adminfunc();
void ChangeStockPrices();
void AddStock();
void DeleteStock();
void UpdateStock();
void userfunc(int check); //the check is a number representing a user.
void DepositMoney(int check);
void WithdrawMoney(int check);
void BuyStock(int check);
void SellStock(int check);
void ShowAsset(int check);
int CheckID(char ID[]);
int CheckStock(char Stock[]);


int main(){
    srand(time(0)); //take a random seed.

    strcpy(IDs[0], "admin"); //store the initial setting.
    strcpy(pws[0], "Admin123");

    strcpy(IDs[1], "user");
    strcpy(pws[1], "User123");

    strcpy(Stocks[0], "Apple");
    strcpy(Stocks[1], "Samsung");
    strcpy(Stocks[2],"Google");
    StockP[0] = 150;
    StockP[1] = 120;
    StockP[2] = 200;

    mainmenu(); //start the main menu.


    return 0;
}

void mainmenu(){ //function of main menu.
    int n;
    while (1){ //use an infinite loop.
        printf("1. Login\n2. Register\n3. Exit\n");
        scanf("%d", &n); //receive the option number.

        if(n==1) 
            login();
        else if (n==2) 
            registration();
        else if (n==3) {
            break; //if choose exit, the loop break.
        }
        else
            printf("Please, select the right one.\n");

    }
}

void login(){ //function of login.
    char ID[MAX_IDs];
    char pw[MAX_pws];
    printf("Enter ID:\nEnter password:\n");
    scanf("%s", ID);
    scanf("%s", pw); //receive the ID and password.

    int check = CheckID(ID); //check whether the ID is stored.
    if(strcmp(IDs[check], ID)==0 && strcmp(pws[check], pw)==0){ //if all options are checked, login.
        if(strcmp(ID,"admin")==0)
            adminfunc();
        else
            userfunc(check);
    }
    else {
        printf("No exist.\n");
        return;
    }
}

int CheckID(char ID[]){ //function of checking whether the ID is stored.
    for (int i=0; i< usernum; i++){
        if(strcmp(IDs[i], ID)==0)
            return i; //if it is, return the i.
    }
    return -1; //if not, return -1.
}

int CheckStock(char Stock[]){ //function of checking whether the stock is stored.
    for (int i=0; i< stocknum; i++){
        if(strcmp(Stocks[i], Stock)==0)
            return i; //if it is, return the i.
    }
    return -1; //if not, return -1.
}

void registration(){ //function of registration.
    int p, upper=0, lower=0, num=0;

    if (usernum >= MAX_Users){ //if users rooms are full, return to the main menu.
        printf("There is no room to register.\n");
        return;
    }
    else{
        char ID[MAX_IDs];
        char pw[MAX_pws];
        printf("Enter ID:\n");
        scanf("%s", ID); //receive the ID.
        int check = CheckID(ID); //check whether the ID is stored.
        if (check == -1){ //if not, receive the password.
            printf("Enter password:\n");
            scanf("%s", pw);

            p = strlen(pw); //check whether the received password meets the conditions.
            char a;
            if (p>=5){ //if the password is at least 5 characters long, continue.
                for(int i =0; i<p; i++){
                    if(pw[i] >= 65 && pw[i] <=90)
                        upper++;
                    if(pw[i] >= 97 && pw[i] <=122)
                        lower++;
                    if(pw[i] >= 48 && pw[i] <=57)
                        num++;
                }
                if(upper>0 && lower>0 && num>0){ //if the received password meets the conditions, continue.
                    printf("Are you an admin or user? (a/u):\n");
                    scanf(" %c", &a);
                    getchar();
                    if(a == 'u'){ //if user, store the ID and password.
                        strcpy(IDs[usernum], ID);
                        strcpy(pws[usernum], pw);
                        Balances[usernum] = 0;
                        usernum++;
                    }
                    else if (a== 'a'){ //if not, return to main menu.
                        printf("Sorry. You cannot register for admin.\n ");
                        return;
                    }
                    else{
                        printf("Please, enter only a or u.\n");
                        return;
                    }

                }
                else{
                    printf("Your password should have at least one uppercase letter, lowercase letter, number.\n");
                    return;
                }
            }            
            else{
                printf("Your password should be at least 5 characters long.\n");
                return;
            }   
        }
        else{
            printf("The same ID already exists.\n");
            return;
        }
    }
}

void adminfunc(){ //function of admin menu.
    int option;
    printf("1. Change stock prices\n2. Add a new stock\n3. Delete a stock\n4. Update a stock's name or price\n5. Logout\nChoose an option:");
    scanf("%d", &option); //receive the option number.

    if(option==1) 
        ChangeStockPrices();
    else if (option==2) 
        AddStock();
    else if (option==3)
        DeleteStock();
    else if (option==4)
        UpdateStock();
    else if (option==5)
        mainmenu();
    else {
        printf("Please, select the right one.\n");
        return;
    }
}

void ChangeStockPrices(){ //function of change stock prices.
    for (int i=0; i<stocknum; i++){
        int change =(rand()%21)-10; //receive one random integer between 0 to 20 and subtract it as 10.
        StockP[i] *= (1+change/100.0); //apply the percentage.
    }
    printf("The stock prices are changed.\n");
    adminfunc();
}

void AddStock(){ //function of add the stock.
    if (stocknum >= MAX_Stocks){ //if stocks rooms are full, return to the admin menu.
        printf("There is no room to add stock.\n");
        return;
    }
    else{
        char stock[MAX_Stocks];
        double price;
        printf("Enter stock name:\n"); //receive the stock name.
        scanf("%s", stock);

        int check = CheckStock(stock); 
        if (check == -1){ //check whether the stock is stored.
            printf("Enter stock price:\n"); //if not, receive the stock price.
            scanf("%lf", &price);
            strcpy(Stocks[stocknum],stock); //store the stock name and price.
            StockP[stocknum]=price;
            stocknum++;
        }
        else { // if it is, return to admin menu.
            printf("The stock already exists.\n");
            return;
        }
    }
}

void DeleteStock(){ //function of delete the stock.
    char stock[MAX_Stocks];
    printf("Enter stock name to delete:\n");
    scanf("%s", stock);

    int check = CheckStock(stock);
    if (check != -1){ //check whether the stock is stored.
        for (int k=0; k<usernum; k++){ //Before deleting, rearrange the Stock Ownership not to be in trouble.
            for (int l=check; l<stocknum-1; l++){
                StockOwnership[k][l] = StockOwnership[k][l+1];
            }
            StockOwnership[k][stocknum-1]=0;
        }

        for (int i=check; i<stocknum-1; i++){ //delete the stock and rearrange the stock name and price.
            strcpy(Stocks[i],Stocks[i+1]);
            StockP[i]=StockP[i+1];
        }
        stocknum--;
        printf("The stock is deleted.\n");
        return;
    }
    else {  //if not checking in stored array.
        printf("No exist.\n");
        return;
    }
}

void UpdateStock(){ //function to update the stock.
    char stock[MAX_Stocks];
    printf("What is the stock name you want to update?:");
    scanf("%s", stock); //receive the stock name.

    int check = CheckStock(stock); //check whether the stock is stored.
        if (check != -1){ //if it is, continue.
            int option;
            printf("1.Name\n2.Price\nChoose an option to update.\n");
            scanf("%d", &option); //receive the number of the opion.

            if (option == 1){ //receive the option of updating Name.
                printf("Enter stock name to update.\n");
                scanf("%s", Stocks[check]); //update the name.
                printf("The stock name is updated.\n");
                return;
            }
            else if (option == 2){ //receive the option of updating price.
                printf("Enter stock price to update.\n");
                scanf("%lf", &StockP[check]); //update the price.
                printf("The stock price is updated.\n");
                return;
            }
        }
        else {
            printf("No exist.\n");
            return;
        }
}

void userfunc(int check){ //function of user menu.
    int option;
    printf("1. Deposit money\n2. Withdraw money\n3. Buy stocks\n4. Sell stocks\n5. Show all user assets\n6. Logout\nChoose an option:\n");
    scanf("%d", &option); //receive the number of the opion.

    if(option==1) 
        DepositMoney(check);
    else if (option==2) 
        WithdrawMoney(check);
    else if (option==3)
        BuyStock(check);
    else if (option==4)
        SellStock(check);
    else if (option==5)
        ShowAsset(check);
    else if (option==6)
        mainmenu(); //if choose logout, return to main menu.
    else {
        printf("Please, select the right one.\n");
        mainmenu();
    }
}

void DepositMoney(int check){ //function of depositing money.
    double money;
    printf("How much money to add from balance?:");
    scanf("%lf", &money); //receive the money to add.
    if(money>0){ //if the money is a positive number, continue.
        Balances[check] += money; //add the money to the logined user's balance.
        printf("The money has been added.\n");
        adminfunc();
    }
    else{
        printf("If you want to withdraw money, choose the second option.\n");
        adminfunc();
    }
}

void WithdrawMoney(int check){ //function to withdraw money.
    double money;
    printf("How much money to withdraw from balance?:");
    scanf("%lf", &money); //receive the money to withdraw.
    if(money>0 && money <= Balances[check]){ //if the money is a positive number and smaller than the balance, continue.
        Balances[check] -= money; //withdraw from the balance.
        printf("The money was withdrawn from the balance.\n");
        adminfunc();
    }
    else {
        printf("Please, write the exact money.\n");
        adminfunc();
    }
}

void BuyStock(int check){ //function of buying stock.
    char stname[MAX_Stocks][MAX_Name];
    char names[200];
    char stquan[200];
    int stocklist[100];
    int quan[100];
    printf("Enter stock name (e.g., stock name 1, stock name 2, stock name 3):");
    scanf(" %[^\n]", names); //read the whole line.
    printf("Enter quantity to buy (e.g., quantity of stock 1, quantity of stock 2, quantity of stock 3):");
    scanf(" %[^\n]", stquan); //read the whole line.

    char *wow; //store each in order in an array while removing commas.
    wow = strtok(names,", ");
    int i=0;
    while (wow!=NULL && i<MAX_Stocks){
        strcpy(stname[i], wow);
        wow = strtok(NULL, ", ");
        i++;
    }

    char *num; //store each in order in an array while removing space.
    num = strtok(stquan, " ");
    int n=0;
    while (num!=NULL){
        quan[n] = atoi(num);
        num = strtok(NULL, " ");
        n++;
    }

    if (i != n){ //if the number of stocks and the number of quantities are different, not continue.
        printf("Invalid input'\n");
        adminfunc();
    }


    double total = 0; //if no problem, continue.
    for (int j=0; j<i; j++){
        int checking = CheckStock(stname[j]); //check whether the stock is stored.
        if (checking == -1){ //if not, not continue.
            printf("No Exist.\n");
            total = 0;
            break;
        }
        else{ //if it is, continue.
            total += StockP[checking]*quan[j]; //calculate the total price to spend.
            stocklist[j] = checking; //store each number of location in the new list of stock.
        }
    }
    if (total > Balances[check]){ //if total price to spend is over the balance, not continue.
        printf("You don't have enough balance.\n");
        return;
    }
    else{ //if no problem, continue.
        Balances[check] -= total; //subtract the total money.
        for (int j=0; j<i; j++)
            StockOwnership[check][stocklist[j]] += quan[j]; //store the each ownership of the stock.
        printf("You successfully buy the stock(s).\n");
        return;
    }
}

void SellStock(int check){ //function of selling the stock.
    char stname[MAX_Stocks][MAX_Name];
    char names[200];
    char stquan[200];
    int stocklist[100];
    int quan[100];
    printf("Enter stock name (e.g., stock name 1, stock name 2, stock name 3):");
    scanf(" %[^\n]", names); //read the whole line.
    printf("Enter quantity to sell (e.g., quantity of stock 1, quantity of stock 2, quantity of stock 3):");
    scanf(" %[^\n]", stquan); //read the whole line.

    char *wow; //store each in order in an array while removing commas.
    wow = strtok(names,", ");
    int i=0;
    while (wow!=NULL && i<MAX_Stocks){
        strcpy(stname[i], wow);
        wow = strtok(NULL, ", ");
        i++;
    }

    char *num; //store each in order in an array while removing space.
    num = strtok(stquan, " ");
    int n=0;
    while (num!=NULL){
        quan[n] = atoi(num);
        num = strtok(NULL, " ");
        n++;
    }

    if (i != n){ //if the number of stocks and the number of quantities are different, not continue.
        printf("Invalid input'\n");
        userfunc(check);
    }


    double total = 0; //if no problem, continue.
    for (int j=0; j<i; j++){
        int checking = CheckStock(stname[j]); //check whether the stock is stored.
        if (checking == -1){ //if not, not continue.
            printf("No Exist.\n");
            total = 0;
            userfunc(check);
        }
        else{ //if no problem, continue.
            total += StockP[checking]*quan[j]; //calculate the total price to add.
            stocklist[j] = checking; //store each number of location in the new list of stock.
        }
    }
    
    for (int j=0; j<i; j++){
        if (quan[j] > StockOwnership[check][stocklist[j]]){ //if the number of quantities are over the stored one, not continue.
            printf("You don't have enough quantity of the stock(s).\n");
            userfunc(check);
        }
        else{ //if no problem, subtract from the stored array.
            StockOwnership[check][stocklist[j]] -= quan[j];
        }
    }
    Balances[check] += total; //add the total price to the balance.
    printf("You successfully sell the stock(s).\n");
    userfunc(check);
}

void ShowAsset(int check) { //function of showing the asset.
    double total=0;
    printf("Your owned stock(s):");
    for (int i=0; i< stocknum; i++){
        if(StockOwnership[check][i]>0){ //show each stock's name and quantity and it's current totla value.
            printf("Stock Name: %s Stock Quantity: %d Current total value: $%.2f\n", Stocks[i], StockOwnership[check][i], StockP[i]*StockOwnership[check][i]);
            total += StockP[i]*StockOwnership[check][i];
        }
    }
    printf("Your current total value: $%.2f", total); //show the current total value. 
    userfunc(check);
}