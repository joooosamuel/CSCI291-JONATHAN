#include <stdio.h>
/*ESPRESSO INGREDIENT*/
#define e_c 8
#define e_w 30
#define e_m 0
#define e_choc 0
#define e_p 3.5

/*CAPPUCCINO INGREDIENTS*/
#define c_c 8
#define c_w 30
#define c_m 70
#define c_cho 0
#define c_p 4.5

/*MOCHA INGREDIENTS*/
#define m_c 8
#define m_w 39
#define m_m 160
#define m_cho 30
#define m_p 5.5

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



float total_amount;
int coffee_beans=200;
int water=200;
int milk=200;
int syrup=200;

float price;



int menu();
int payment();


/*Main Menu*/
int choice = 0;
int main()
{
    printf("1. Order a coffee\n");
    printf("2. Admin mode\n");
    printf("3. Leave\n");

    printf("Enter your chosen field's number from 1-3: ");
    scanf("%d", &choice);


    while (choice != 1 && choice != 2 && choice !=3)
    {
        printf("Wrong Input\n"); 
        printf("Enter your chosen field's number from 1-3: ");
        scanf("%d", &choice);
    }

    if(choice==1)
    {
        menu();
    }
    return 0;
}

/*If option 1 coffe is selected*/
int coffe_type_choice=0;
int confirmation;
int menu(){
    printf("1. Espresso AED %.2f\n", e_p);
    printf("2. Cappucino AED %.2f \n", c_p);
    printf("3. Mocha AED %.2f \n", m_p);

    
    printf("Enter your chosen field's number from 1-3: ");
    scanf("%d", &coffe_type_choice);
    while (coffe_type_choice != 1 && coffe_type_choice != 2 && coffe_type_choice !=3)
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
            printf("c: %d w: %d m: %d s: %d \n ", coffee_beans, water, milk, syrup);
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
            printf("c: %d w: %d m: %d s: %d \n", coffee_beans, water, milk, syrup);
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
            printf("c: %d w: %d m: %d s: %d \n", coffee_beans, water, milk, syrup);
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
    
    return 0;
    
}


/*Checking if the user pays the correct amount*/
float money_input;
float money_total=0;
int payment(){
    if (coffe_type_choice==1){
        total_amount=e_p;
        while (money_total!=total_amount)
        {
            printf("Enter only 1 or 0.5 to pay: ");
            scanf("%f", &money_input);
            if(money_input==1 || money_input==0.5)
            {
                money_total=money_input+money_total;
            }else printf("Wrong input ");
        }
    }else if (coffe_type_choice==2){
        total_amount=c_p;
        while (money_total!=total_amount)
        {
            printf("Enter only 1 or 0.5 to pay: ");
            scanf("%f", &money_input);
            if(money_input==1 || money_input==0.5)
            {
                money_total=money_input+money_total;
            }else printf("Wrong input ");
        }
    } else if (coffe_type_choice==3){
        total_amount=m_p;
        while (money_total!=total_amount)
        {
            printf("Enter only 1 or 0.5 to pay: ");
            scanf("%f", &money_input);
            if(money_input==1 || money_input==0.5)
            {
                money_total=money_input+money_total;
            }else printf("Wrong input ");
        }
    }
    if (total_amount==money_total)
    {
        printf("Enjoy your cofee");
    }
    
}

