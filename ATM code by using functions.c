// ATM code by using c programming language

#include<stdio.h>
#include<stdlib.h>
void pingenerate();
int pin(int a);
void condition();
int balance(int amount);
int credit(int credit_amount);
int check_account(int account_number);

int main(){
    
      int option;
                                                 //To disply the option
    printf(" 1.How to use the YASH ATM\n");                                                                    
     printf("2. BANKING\t");               printf("3. PIN GENERATE\t");
   printf("\n4. PIN CHANGE\t");            printf("5. TRANSFER\t");
  printf("\n**********************************************************");
     printf("\nEnter the option number: ");
     scanf("%d",&option);
  
     //First switch statement
     long long int count=0;
     int p,ret,option2;            //Variable declaration
     switch(option)   
     {
         case 1:                     //First switch case 1
         //conditions of the yash Atm 
         condition();
         break;
         
         case 2:
         //banking
          
          printf("1. WITHDRAWL\t");              printf("2. BALANCE ENQUIRY\t");
        printf("\n3. MINISTATEMENT\t");          printf("4. CREDIT\t");
 printf("\n*********************************************************************");
          printf("\nEnter the option number: ");
          scanf("%d",&option2);
          switch(option2){
          case 1:
                        //Withdrawl 
                        
            printf("Enter your pin  number: ");
             scanf("%d",&p);
             ret=pin(p);                //Function call
             if(ret==4){
                long long int amount,available=100000,available1;
                 printf("Enter the money: ");
                 scanf("%lld",&amount);
                 ret=balance(amount);    //function call
                 if(ret==1){
                     available -= amount;
                      if(available>=0){                         
                          printf("\nPlease collect your cash");
                          printf("\nAvailable balance is : %lld",available);
                          printf("\nThank you for using YASH ATM..\nVisit Again");
                         
                       }else{               
                       
                           printf("Sorry!\nyou don't have sufficient money in your account\n");
                           printf("available Balance is: %lld",available1);
                           printf("\nVisit again");
                       }
                 }
             }
             break;
             
             case 2:
                     //balance ENQUIRY
             
            printf("Enter your pin  number: ");
             scanf("%d",&p);
             ret=pin(p);
             int available=100000;
             if(ret==4){
             printf("Available balance is:%d",available);
             printf("\nThank you for using YASH ATM");
             }else{
                 printf("Wrong pin number!\n");
             }
             break;
             
             case 3:
                         //ministstment
             
               printf("Enter your pin  number: ");
             scanf("%d",&p);
             ret=pin(p);
             if(ret==4){
                 
             }
             break;
             
             case 4:
                        //credit 
                        
             printf("Enter your pin  number: ");
             scanf("%d",&p);
             ret=pin(p);
             if(ret==4){
         long long int credit_cash;
    printf("Enter the amount to credit:");
    scanf("%lld",&credit_cash);
              if(1==credit(credit_cash))
              printf("%lld cash is succesfully credited\n",credit_cash);
             }else{
                printf("Wrong pin number!\n");
                printf("please try again!\n\n***** Thanks for using YASH ATM *****\n");
             }
             break;
             
          } 
         break;
         
         case 3:
                     //pin gerate 
        pingenerate();
         break;
         
         case 4:
                  //pin CHANGE
        printf("Enter pin number:");
        scanf("%d",&p);
        ret=pin(p);
        if(ret==4){
            int new_pin;
            printf("Enter new pin number:");
            scanf("%d",&new_pin);
            ret=pin(new_pin);
            if(ret==4) printf("your pin is succesfully generated\n");
            else printf("Your pin is not generated!\n");
        }
         break;
         
         case 5:
                   //transfer 
         printf("Enter pin number:");
        scanf("%d",&p);
        ret=pin(p);
        if(ret==4){
           long long int atm_number;
            printf("Enter tranfered ATM number:");
            scanf("%lld",&atm_number);
            ret=check_account(atm_number);
            if(ret<=16){
               long long int trans_amount;
                printf("Enter the amount:");
                scanf("%lld",&trans_amount);
                printf("%lld cash is succesfully transfered\n",trans_amount);
                printf("Thanks for using YASH ATM\n");
            }else printf("Please enter the valaid ATM number\nThanks for using YASH ATM\n");
            
        }else{
            printf("Please enter the valid pin number!\n");
        }
         break;
     }
    
   return 0;
}

          //pin generate function 
          
void pingenerate(){
long long account,mobile;
    printf("Enter the your account number:");
    scanf("%lld",&account);
    int ret;
    ret=check_account(account);
    if(ret>=10){
        printf("Enter your mobile number:");
        scanf("%lld",&mobile);
        ret=check_account(mobile);
        if(ret==10){
            int p;
            printf("Enter your new pin number:");
            scanf("%d",&p);
            ret=pin(p);
            if(ret==4){
            printf("New pin is succesfully generated\n");
            }else{printf("This pin not generated!\nTry another pin number\n");}
        }else{printf("please enter the valid mobile number!\nit must be linked with your account \n");}
    }else{
        printf("Please enter the valid account number!\n");
        printf("Thank you for using YASH ATM\n");
    }
    
}

         // pin checking  function
//int remainder,remainder2;
int pin(int pin){
    int remainder,remainder2;
       int pin2;  //Variable declaration
        long long int count=0;
              pin2=pin;
           
              while(pin!=0)
              {
                remainder=pin%10;
                pin=pin/10;
                remainder2=pin%10;
               if(remainder>remainder2){
                   count++;
               }
              }
              return count;
              
}
//conditions function
void condition(){
      printf("\nCondition of the YASH ATM is as follows:\n");
         printf("\n1. First of all enter the option number\n");
         printf("2. secrete  pin number is must have 4 digits and\n");
         printf("   it is in the form of ascending order\n");
         printf("3. Account number is must have greater than 15 digits\n");
         printf("4. ATM number must have 16 digits\n");
         printf("5.In your account fixed deposit amount is: 100000\n");
         
         
    
}

// available balance function

int balance(int amount){
    int amount2;
    amount2=amount;
      if(amount>40000)                      
                  {
                    printf("\n\nSorry! plese enter the amount below 40000 ");
                    printf("\nthank you for using YASH ATM");
                  }else{
                      return 1;
                  }                                   
                    
                       
}

// credit function
int credit(int credit_money){
  long long int credit_amount=credit_money;
    do{
    if(credit_amount<=40000){
        printf("place the %d money\n",credit_amount);
        break;
     }else{
         printf("place money 40000\n");
         credit_amount=credit_amount-40000;
     }
    }while(credit_amount!=0);
 return 1;   
}

    //Account number checking
    int check_account(int account_number){
      long long int count=0;
          while(account_number!=0)
              {
                account_number=account_number/10;
                   count++;
              }
              return count;
    }


