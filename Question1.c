#include <stdio.h>
#include <string.h>
int isbns[100], quantities[100], Choice, row = 0;
char titles[100][50];
float prices[100];
int AddData(int isbn, float price, int quantity, char name[50]);
int main()
{
    int isbn, quantity;
    float price;
    printf("Main menu\n");
    printf("Enter 1 to Add book,");
    printf("Enter 2 to process a sale,");
    printf("Enter 3 to generate a low stock report\n");
    scanf("%d", &Choice);
    getchar();
    switch (Choice)
    {
    case 1:
        printf("Enter the name of your Book: ");
        fgets(titles[row], sizeof(titles[row]), stdin);
        titles[row][strcspn(titles[row], "\n")] = '\0';
        printf("Enter The price of the book");
        scanf("%d", &isbn);
        printf("Enter The Quantities of the book");
        scanf("%d", &quantities);
        printf("Enter The isbn of the book");
        scanf("%f", &price);
        AddData(isbn, price, quantities);
        printf("%d\n", isbns[0]);
        break;
    case 2:
        /* code */
        break;
    case 3:
        /* code */
        break;

    default:
        break;
    }
    return 0;
}

int AddData(int isb, float Price, int Quantity)
{
    int flag = 0;
    // Check for Duplication
    while ((row != 99) && (flag == 0))
    {
        if (isb = isbns[row])
            flag = 1;
        else
            row++;
    }
    if (flag = 1)
        printf("Book already available\n");
    else
        isbns[row] = isb;
}