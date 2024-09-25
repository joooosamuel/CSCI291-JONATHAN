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


int total_amount = 0;
int coffee_beans, water, milk, syrup, price;

int choice = 0;

int main()
{

}


int mamenu()
{
    printf("1. Order a coffee\n");
    printf("2. Admin mode\n");
    printf("3. Leave\n");

    while (choice != 1 || choice != 2 || choice !=3)
    {
        printf("Enter your chosen field's number from 1-3: ");
        scanf("%d", &choice);
    }
    return 0;
}