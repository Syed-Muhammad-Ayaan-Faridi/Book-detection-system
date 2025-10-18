#include <stdio.h>
#include <string.h>

// Array Declaration
int quantities[100], isbns[100], row = 0;
float prices[100];
char titles[100][50];
const int Trow = 100;

// Function Prototypes
int AddData();
int SaleProcessing();
int LowStock();
void OutputISBN();
void OutputQty();
void OutputPrice();
// Main Function
int main()
{
    int choice;
    do
    {
        printf("Menu\nEnter 1 to Add data\nEnter 2 to Process Sale\nEnter 3 to Generate Low Stock Report\nEnter your Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            AddData();
            break;
        case 2:
            SaleProcessing();
            break;
        case 3:
            LowStock();
            break;

        default:
            printf("Invalid Choice Entered!!!\n");
            break;
        }
        OutputISBN();
        OutputPrice();
        OutputQty();
    } while (choice >= 1 && choice <= 3);

    return 0;
}

int AddData()
{
    // Variable Declaration
    int ISBN, Qty, i = 0;
    float Price;
    char title[50];
    // Space in array available or not
    if (row >= Trow)
    {
        printf("Full!!! Can't add books");
    }

    // Input ISBN and Check for duplication
    printf("Enter the ISBN number of the book: ");
    scanf("%d", &ISBN);
    while (i < row)
    {
        if (ISBN == isbns[i])
        {
            printf("Book already available\n");
            return 0;
        }
        i++;
    }

    // If no duplication then Input the price, Quantity and the Name of the book
    getchar();
    printf("Enter the name of the book: ");
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = '\0';

    printf("Enter the Price of the book: ");
    scanf("%f", &Price);
    printf("Enter the Quantity of the books: ");
    scanf("%d", &Qty);

    isbns[row] = ISBN;
    prices[row] = Price;
    quantities[row] = Qty;
    strcpy(titles[row], title);

    row++;

    return 0;
}
void OutputISBN()
{
    for (int i = 0; i < Trow; i++)
        printf("%d ", isbns[i]);
    printf("\n");
}
void OutputQty()
{
    for (int i = 0; i < Trow; i++)
        printf("%d ", quantities[i]);
    printf("\n");
}
void OutputPrice()
{
    for (int i = 0; i < Trow; i++)
        printf("%.1f ", prices[i]);
    printf("\n");
}

int SaleProcessing()
{
    int ISBN, books_sold;

    // Input ISBN and number of copies sold
    printf("Enter the ISBN of the Book sold: ");
    scanf("%d", &ISBN);
    printf("Enter the Number of copies sold of this book: ");
    scanf("%d", &books_sold);

    // Check for the ISBN
    int count = 0, index = -1, flag = 1;
    while (flag && count < Trow)
    {
        if (ISBN == isbns[count])
        {
            index = count;
            flag = 0;
        }
        count++;
    }

    // Check its stock and deduct the copies sold
    if (index == -1)
        printf("No such book availalbe!!!\n");
    else if (quantities[index] == 0)
    {
        printf("Sorry this book is out of stock\n");
        return 0;
    }
    else
        quantities[index] = quantities[index] - books_sold;
}

int LowStock()
{
    printf("Low stock Summary!!!\n");
    for (int i = 0; i < Trow; i++)
    {
        if (isbns[i] == 0)
        {
            break;
        }
        if (quantities[i] <= 5)
        {
            printf("%d %s %d\n", isbns[i], titles[i], quantities[i]);
        }
    }
}