#include <stdio.h>
#include <stdlib.h>

/*ESPRESSO INGREDIENT*/
#define e_c 8
#define e_w 30
#define e_m 0
#define e_choc 0


/*CAPPUCCINO INGREDIENTS*/
#define c_c 8
#define c_w 30
#define c_m 70
#define c_cho 0


/*MOCHA INGREDIENTS*/
#define m_c 8
#define m_w 39
#define m_m 160
#define m_cho 30


/*Minimum for espresso*/
#define e_c_mini 8
#define e_w_mini 30
#define e_m_mini 0
#define e_choc_mini 0


/*Minimum for Cappucino*/
#define c_c_mini 8
#define c_w_mini 30
#define c_m_mini 70
#define c_cho_mini 0



/*MOCHA INGREDIENTS*/
#define m_c_mini 8
#define m_w_mini 39
#define m_m_mini 160
#define m_cho_mini 30

/*Admin Password*/
#define pass 0000

/*Prices*/
float e_p = 3.5;
float c_p= 4.5;
float m_p= 5.5;


float total_amount;
int coffee_beans=200;
int water=200;
int milk=200;
int syrup=200;

float price;



int menu();
int payment();
int admin();
int repleninshing();
int reset();

/*Main Menu*/
int choice = 0;
int main(){
    while (1){
        printf("1. Order a coffee\n");
        printf("2. Admin mode\n");
        printf("3. Leave\n");

        printf("Enter your chosen field's number from 1-3: ");
        scanf("%d", &choice);
        while (choice != 1 && choice != 2 && choice !=3){
            printf("Wrong Input\n"); 
            printf("Enter your chosen field's number from 1-3: ");
            scanf("%d", &choice);
         }

        if(choice==1){
            menu();
        }else if (choice==2){
            admin();
        }else if (choice==3){
            break;
        }
    return 0;
    }
}

/*If option 1 coffe is selected*/
int coffe_type_choice=0;
int confirmation;
int menu(){
    printf("1. Espresso AED %.2f\n", e_p);
    printf("2. Cappucino AED %.2f \n", c_p);
    printf("3. Mocha AED %.2f \n", m_p);
    printf("4. Main menu \n");

    
    printf("Enter your chosen field's number from 1-4: ");
    scanf("%d", &coffe_type_choice);
    while (coffe_type_choice != 1 && coffe_type_choice != 2 && coffe_type_choice !=3 && coffe_type_choice !=4)
    {
        printf("Wrong Input\n"); 
        scanf("%d", &coffe_type_choice);
    }
    if (coffe_type_choice==1)
    {
        if(coffee_beans<=e_c_mini || water<=e_w_mini)
        {
            printf("Unavailable due to temporarily insufficient ingredients\n");
        }
        else
        {
            printf("Espresso Coffee is availble, your total is AED %.2f\n", e_p);
            coffee_beans=coffee_beans-e_c;
            water=water-e_w;
            printf("Do you want to confirm your order\n");
            printf("1. Yes \n");
            printf("2. No \n");
            printf("Enter your chosen field's number from 1-2: ");
            scanf("%d", &confirmation);
            if (confirmation==1){
                payment();
            }else if (confirmation!=1){
                menu();
            }
        }

    }
    else if (coffe_type_choice==2)
    {
        if(coffee_beans<=c_c_mini || water<=c_w_mini || milk<= c_m_mini)
        {
            printf("Unavailable due to temporarily insufficient ingredients\n");
        }
        else
        {
            printf("Coffee is availble, your total is AED %.2f\n", c_p);
            coffee_beans=coffee_beans-c_c;
            water=water-c_w;
            milk=milk-c_m;
            printf("Do you want to confirm your order\n");
            printf("1. Yes \n");
            printf("2. No \n");
            printf("Enter your chosen field's number from 1-2: ");
            scanf("%d", &confirmation);
            if (confirmation==1)
            {
                payment();
            }else if (confirmation!=1){
                menu();
            }
            
        }
    }
    else if (coffe_type_choice==3)
    {
        if(coffee_beans<=m_c_mini || water<=m_w_mini || milk<= m_m_mini || syrup<=m_cho_mini)
        {
            printf("Unavailable due to temporarily insufficient ingredients\n");
        }
        else
        {
            printf("Coffee is availble, your total is AED %.2f\n", m_p);
            coffee_beans=coffee_beans-m_c;
            water=water-m_w;
            milk=milk-m_m;
            syrup=syrup-m_cho;
            printf("Do you want to confirm your order\n");
            printf("1. Yes \n");
            printf("2. No \n");
            printf("Enter your chosen field's number from 1-2: ");
            scanf("%d", &confirmation);
            if (confirmation==1)
            {
                payment();
                
            }else if (confirmation!=1){
                menu();
            }

        }
    }
    else if(coffe_type_choice==4){
        main();
    }
    
    return 0;
    
}


/*Checking if the user pays the correct amount*/
float money_input;
float money_total=0;
float money_for_coffee;
float change;
int payment(){
    if (coffe_type_choice==1){
        money_for_coffee=e_p;
        while (money_total!=money_for_coffee)
        {
            printf("Enter only 1 or 0.5 to pay: ");
            scanf("%f", &money_input);
            if(money_input==1 || money_input==0.5){
                money_total=money_input+money_total;
            }else printf("Wrong input ");
        }
    }else if (coffe_type_choice==2){
        money_for_coffee=c_p;
        while (money_total!=money_for_coffee)
        {
            printf("Enter only 1 or 0.5 to pay: ");
            scanf("%f", &money_input);
            if(money_input==1 || money_input==0.5)
            {
                money_total=money_input+money_total;
            }else printf("Wrong input ");
        }
    } else if (coffe_type_choice==3){
        money_for_coffee=m_p;
        while (money_total!=money_for_coffee)
        {
            printf("Enter only 1 or 0.5 to pay: ");
            scanf("%f", &money_input);
            if(money_input==1 || money_input==0.5)
            {
                money_total=money_input+money_total;
            }else printf("Wrong input ");
        }
    }
    if (money_for_coffee==money_total)
    {
        printf("Enjoy your coffee\n\n\n");
        total_amount=total_amount+money_for_coffee;
        menu();
    }
    
}

/*Admin Mode*/
int admin_pass;
int admin_choice;
int replenish_choice;
int price_upd_choice;
float new_price;
int admin(){
    printf("Enter your password: ");
    scanf("%d", &admin_pass);
    if(admin_pass==pass){
        printf("1. Display the quantity of each ingredient in the machine and the total sale amount\n");
        printf("2. Replenish ingredients in the machine\n");
        printf("3. Change coffee price\n");
        printf("0. Exit the Admin function Mode\n");
        printf("Enter your chosen field from 0-3: ");
        scanf("%d", &admin_choice);
        if(admin_choice==0){
            main();
        }else if(admin_choice==1){
            printf("Coffee left: %d\n ", coffee_beans);
            printf("Water left: %d\n ", water);
            printf("Milk left: %d\n ", milk);
            printf("Syrup left: %d\n ", syrup);
            printf("Total Sales: %.2f\n ", total_amount);
            reset();
        }else if(admin_choice==2){
            printf("Choose the item you want to replenish\n");
            printf("1. Coffee \n");
            printf("2. Water \n");
            printf("3. Milk \n");
            printf("4. Syrup \n");
            printf("Enter your chosen option from 1-4: ");
            scanf("%d",&replenish_choice);
            repleninshing();

        }else if (admin_choice==3){
            printf("Choose the item you want to re-price\n");
            printf("1. Espresso \n");
            printf("2. Cappucino \n");
            printf("3. Mocha \n");
            printf("Enter your chosen field from 1-3: ");
            scanf("%d",&price_upd_choice);
            if (price_upd_choice==1)
            {
                printf("Enter the new price for the Espresso: ");
                scanf("%f", &new_price);
                e_p=new_price;
            }else if (price_upd_choice==2){
                printf("Enter the new price for the Cappucino: ");
                scanf("%f", &new_price);
                c_p=new_price;
            }else if (price_upd_choice==3){
                printf("Enter the new price for the Mocha: ");
                scanf("%f", &new_price);
                m_p=new_price;
            }
        }
    }else {
        printf("INCORRECT PASSWORD\n");
        main();
        }
}



/*Replenishing Function*/
int replenishing_amt;
int repleninshing(){
    if(replenish_choice==1){
        coffee_beans=coffee_beans+replenishing_amt;
        printf("Total amount of coffee beans: %d",coffee_beans);
    }else if(replenish_choice==2){
        printf("Enter the amount of water to add in ml: ");
        scanf("%d",&replenishing_amt);
        printf("test");
        water = water+replenishing_amt;
        printf("Total amount of water: %d",water);
    }else if(replenish_choice==3){
        printf("Enter the amount of milk to add in ml: ");
        scanf("%d",&replenishing_amt);
        milk=milk+replenishing_amt;
        printf("Total amount of milk: %d",milk);
    }else if(replenish_choice==4){
        printf("Enter the amount of syrup to add in ml: ");
        scanf("%d",&replenishing_amt);
        syrup=syrup+replenishing_amt;
        printf("Total amount of syrup: %d",syrup);
    }
}


/*Reseting the total amount*/
int choice_reset;
int reset(){
    printf("Enter 1 to reset the total ");
    scanf("%d", &choice_reset);
    if (choice_reset==1){
        total_amount=0;
    }else{
        main();
    }
}