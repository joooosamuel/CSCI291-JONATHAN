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
#define e_p_mini 3.5

/*Minimum for Cappucino*/
#define c_c_mini 8
#define c_w_mini 30
#define c_m_mini 70
#define c_cho_mini 0
#define c_p_mini 4.5


/*MOCHA INGREDIENTS*/
#define m_c_mini 8
#define m_w_mini 39
#define m_m_mini 160
#define m_cho_mini 30
#define m_p_mini 5.5


int total_amount = 0;
int coffee_beans=200;
int water=200;
int milk=200;
int syrup=200;

float price;

int choice = 0;

int menu();
/*Main Menu*/
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
        if(coffee_beans<e_c_mini || water<e_w_mini)
        {
            printf("Unavailable due to temporarily insufficient ingredients\n");
        }
        else
        {
            printf("Coffee is availble, your total is AED %.2f\n", e_p);
            coffee_beans=coffee_beans-e_c;
            water=water-e_w;
            printf("c: %d w: %d m: %d s: %d \n ", coffee_beans, water, milk, syrup);
            printf("Do you want to confirm your order\n");
            printf("1. Yes \n");
            printf("2. No \n");
            
        }

    }
    else if (coffe_type_choice==2)
    {
        if(coffee_beans<c_c_mini || water<c_w_mini || milk< c_m_mini)
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
            
        }
    }
    else if (coffe_type_choice==3)
    {
        if(coffee_beans<m_c_mini || water<m_w_mini || milk< m_m_mini || syrup<m_cho_mini)
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

        }
    }
    
    return 0;
    
}
