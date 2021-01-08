#include<stdio.h>          /* Created By Sagar Dolia, Student (Roll Number : 1819309) from Haryana Engineering College, Jagadhri */ 
#include<time.h>          /* For Usage of Time Functions */
float details(int);
int credit(int,float,float);
int debit(int,float,float);
int transfer(int,int,float,float);
int valid(int);
void main()
{
    float current_balance,amount,min_balance,withdraw_limit;
    int acno,validity,option,transfer_acno;
    min_balance = 2000;
    withdraw_limit = 20000;
    printf("WELCOME TO PINK CITY BANK\n\n");
    while(1) /* This loops insures the program keep the working for next account in same runtime */ 
    {
        while(1) /* This loops insures the program to ask right account number till it gets */
        {
            printf("Enter your Account Number:\n");
            scanf("%d",&acno);
            validity = valid(acno);
            if(validity == 1)
            {
                printf("\nAccount Number is Valid\n");
                break;
            }
            else
            {
                printf("\nAccount Number is Not Valid.\nPlease Enter the correct one.\n\n");
            }
        }
        current_balance = details(acno);
        if(current_balance < min_balance)
                {
                    printf("Please, Keep Minimum Balance in Your Account\n\n");
                }
                else
                {
                    printf("\n");
                }
        while(1) /* This loops insures the program to ask for exit from the option menu or keep in option menu */
        {
            printf("Select the Option you want:\n");    
            printf("\n1.Balance Enquiry\n2.Deposit Cash\n3.Withdraw Cash\n4.Transfer Funds To Another Bank Account\n5.Exit Menu\n\n");
            scanf("%d",&option);
            if(option < 5 || option > 5)
            {
                switch (option)
                {
                    case 1: /* To know about Current Balance of given account */
                    printf("Your Current Balance is: %.2f\n\n",current_balance);
                    break;

                    case 2: /* To credit the cash in given account */
                    printf("Enter the Amount you want to Credit in:\t");
                    scanf("%f",&amount);
                    if(amount < 1)
                    {
                        printf("You could Credit Minimum Rs.1\n");
                    }
                    else if(amount > 1)
                    {
                        credit(acno,current_balance,amount);
                        current_balance+=amount;
                        printf("Rs. %.2f is Credited to Your Account.\n",amount);
                        printf("Your Current Balance is:Rs. %.2f\n\n",current_balance);
                    }
                    break;

                    case 3: /* To debit the cash in given account */
                    printf("Enter the Amount you want to Debit in:\t");
                    scanf("%f",&amount);
                    if(amount < 1)
                    {
                        printf("You could Debit Minimum Rs.1\n");
                    }
                    else if(amount > withdraw_limit)
                    {
                        printf("Unsuccessful,You Crossed Withdrawal Limit.\n");
                    }
                    else if(amount > current_balance)
                    {
                        printf("You have Insufficient Balance in Your Account.\n");
                        printf("Your Current Balance is:Rs. %.2f\n\n",current_balance);
                    }
                    else if(amount < withdraw_limit && current_balance - amount < min_balance)
                    {
                        debit(acno,current_balance,amount);
                        current_balance-=amount;
                        printf("Rs. %.2f is Debited to Your Account.\n",amount);
                        printf("Your Current Balance is:Rs. %.2f\n",current_balance);
                        printf("Please Keep the Minimum Balance in your Account\n\n");
                    }
                    else if(amount < withdraw_limit && current_balance - amount > min_balance)
                    {
                        debit(acno,current_balance,amount);
                        current_balance-=amount;
                        printf("Rs. %.2f is Debited to Your Account.\n",amount);
                        printf("Your Current Balance is:Rs. %.2f\n\n",current_balance);
                    }
                    break;
                
                    case 4: /* To transfer funds from given account to another account */
                    printf("Enter the Account Number you want Transfer the Money:\t");
                    scanf("%d",&transfer_acno);
                    printf("Enter the Amount you want to Transfer to Account Number %d:\t",transfer_acno);
                    scanf("%f",&amount);
                    if(amount < 1)
                    {
                        printf("You could Transfer Minimum Rs.1\n");
                    }
                    else if(amount > withdraw_limit)
                    {
                        printf("Unsuccessful,You Crossed Withdrawal Limit.\n");
                    }
                    else if(amount > current_balance)
                    {
                        printf("You have Insufficient Balance in Your Account.\n");
                        printf("Your Current Balance is:Rs. %.2f\n\n",current_balance);
                    }
                    
                    else if(amount < withdraw_limit && current_balance - amount < min_balance)
                    {
                        transfer(acno,transfer_acno,current_balance,amount);
                        current_balance-=amount;
                        printf("Rs. %.2f is Transferred to Account Number %d\n",amount,transfer_acno);
                        printf("Your Current Balance is:Rs. %.2f\n",current_balance);
                        printf("Please Keep the Minimum Balance in your Account\n\n");
                    }
                    else if(amount < withdraw_limit && current_balance - amount > min_balance)
                    {
                        transfer(acno,transfer_acno,current_balance,amount);
                        current_balance-=amount;
                        printf("Rs. %.2f is Transferred to Account Number %d\n",amount,transfer_acno);
                        printf("Your Current Balance is:Rs. %.2f\n\n",current_balance);
                    }
                    break;

                    default:
                    printf("Invalid Option. Try Again.\n");
                }   
            }
            if(option == 5)
            {
                break;
            }
        }
        while(1) /* This loops insures the program to ask for exit from the program or work on another account */
        {
            printf("Select the Option:\n1.Exit the Tool\n2.Work on New Account\n\n");
            scanf("%d",&option);
            if(option == 1)
            {
                break;
            }
            else if(option == 2)
            {
                break;
            }
            else
            {
                printf("Invalid Option. Try Again.\n\n");
            }
        }
        if(option == 1)
        {
            break;
        }
    }
    /* Last Modified on 08 January 2021 07:45 PM */
}
float details(int acno)    /* This Function used to get Current Balance of Account */
{
    FILE *Entry;
    float current_balance;
    if(acno == 1234567891)
    {
        Entry = fopen("1234567891.txt","r");
    }
    else if(acno == 1234567892)
    {
        Entry = fopen("1234567892.txt","r");
    }
    else if(acno == 1234567893)
    {
        Entry = fopen("1234567893.txt","r");
    }
    else if(acno == 1234567894)
    {
        Entry = fopen("1234567894.txt","r");
    }
    else if(acno == 1234567895)
    {
        Entry = fopen("1234567895.txt","r");
    }
    if(Entry == NULL)
    {
        printf("Details are not available");
    }
    else
    {
        fscanf(Entry,"%f",&current_balance);
        fclose(Entry);
    }
    return current_balance;
}
int credit(int acno,float current_balance,float amount) /* Use for credit in current balance of account and to record Credit Transaction */
{
    FILE *Entry; 
    float new_balance;
    Entry = fopen("TransactionBook.txt","a") ; 
    if(Entry == NULL) 
    { 
        printf("Transaction Book is not responding."); 
    } 
    else
    {
        time_t curtime;
        time(&curtime);
        fprintf(Entry,"%sRs. %.2f is Credited from Account Number %d.\n\n",ctime(&curtime),amount,acno);
        printf("Data successfully written in Transaction Book.\n"); 
        fclose(Entry);
    }
    if(acno == 1234567891)
    {
        Entry = fopen("1234567891.txt","w");
    }
    else if(acno == 1234567892)
    {
        Entry = fopen("1234567892.txt","w");
    }
    else if(acno == 1234567893)
    {
        Entry = fopen("1234567893.txt","w");
    }
    else if(acno == 1234567894)
    {
        Entry = fopen("1234567894.txt","w");
    }
    else if(acno == 1234567895)
    {
        Entry = fopen("1234567895.txt","w");
    } 
    if(Entry == NULL) 
    { 
        printf("No Respond"); 
    } 
    else
    {
        new_balance = current_balance + amount;
        fprintf(Entry,"%.2f\n",new_balance);
        fclose(Entry);
    }
    return 0;
}
int debit(int acno,float current_balance,float amount) /* Use for debit in current balance of account and to record Debit Transaction */
{ 
    FILE *Entry; 
    float new_balance;
    Entry = fopen("TransactionBook.txt","a") ; 
    if(Entry == NULL) 
    { 
        printf("Transaction Book is not responding."); 
    } 
    else
    {
        time_t curtime;
        time(&curtime);
        fprintf(Entry,"%sRs. %.2f is Debited from Account Number %d.\n\n",ctime(&curtime),amount,acno);
        printf("Data successfully written in Transaction Book.\n"); 
        fclose(Entry);
    }
    if(acno == 1234567891)
    {
        Entry = fopen("1234567891.txt","w");
    }
    else if(acno == 1234567892)
    {
        Entry = fopen("1234567892.txt","w");
    }
    else if(acno == 1234567893)
    {
        Entry = fopen("1234567893.txt","w");
    }
    else if(acno == 1234567894)
    {
        Entry = fopen("1234567894.txt","w");
    }
    else if(acno == 1234567895)
    {
        Entry = fopen("1234567895.txt","w");
    } 
    if(Entry == NULL) 
    { 
        printf("No Respond"); 
    } 
    else
    {
        new_balance = current_balance - amount;
        fprintf(Entry,"%.2f\n",new_balance);
        fclose(Entry);
    }
    return 0;
}
int transfer(int acno,int transfer_acno,float current_balance,float amount) /* Use for change in current balance of account and to record Transaction Due to Transfer of Funds*/
{
    FILE *Entry;
    float new_balance; 
    Entry = fopen("TransactionBook.txt","a") ; 
    if(Entry == NULL) 
    { 
        printf("Transaction Book is not responding."); 
    } 
    else
    {
        time_t curtime;
        time(&curtime);
        fprintf(Entry,"%sRs. %.2f is Transferred from Account Number %d to Account Number %d.\n\n",ctime(&curtime),amount,acno,transfer_acno);
        printf("Data successfully written in Transaction Book.\n"); 
        fclose(Entry);
    }
    if(acno == 1234567891)
    {
        Entry = fopen("1234567891.txt","w");
    }
    else if(acno == 1234567892)
    {
        Entry = fopen("1234567892.txt","w");
    }
    else if(acno == 1234567893)
    {
        Entry = fopen("1234567893.txt","w");
    }
    else if(acno == 1234567894)
    {
        Entry = fopen("1234567894.txt","w");
    }
    else if(acno == 1234567895)
    {
        Entry = fopen("1234567895.txt","w");
    } 
    if(Entry == NULL) 
    { 
        printf("No Respond"); 
    } 
    else
    {
        new_balance = current_balance - amount;
        fprintf(Entry,"%.2f\n",new_balance);
        fclose(Entry);
    }
    current_balance = details(transfer_acno);
    if(transfer_acno == 1234567891)
    {
        Entry = fopen("1234567891.txt","w");
    }
    else if(transfer_acno == 1234567892)
    {
        Entry = fopen("1234567892.txt","w");
    }
    else if(transfer_acno == 1234567893)
    {
        Entry = fopen("1234567893.txt","w");
    }
    else if(transfer_acno == 1234567894)
    {
        Entry = fopen("1234567894.txt","w");
    }
    else if(transfer_acno == 1234567895)
    {
        Entry = fopen("1234567895.txt","w");
    } 
    if(Entry == NULL) 
    { 
        printf("No Respond"); 
    } 
    else
    {
        new_balance = current_balance + amount;
        fprintf(Entry,"%.2f\n",new_balance);
        fclose(Entry);
    }
    return 0;
}
int valid(int acno) /* To check that given bank account number is valid or not */
{
    int validity;
    if(acno > 1234567890 && acno < 1234567896)
    {
        validity = 1;
    }
    else
    {
        validity = 0;
    }
    return validity;
}
