#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    printf("\n");

    FILE* fptr = fopen("Bill.txt", "w");

    fprintf(fptr,   "#########################################################################"
                    "\n"
                    "                 WELCOME TO THE AUTOMATED BILLING SYSTEM"
                    "\n"
                    "#########################################################################"
                    "\n");

    printf( "#########################################################################"
            "\n"
            "                 WELCOME TO THE AUTOMATED BILLING SYSTEM"
            "\n"
            "#########################################################################"
            "\n");

    fprintf(fptr, "\n");
    printf("\n");
    
    time_t current_time;
    time(&current_time);

    const struct tm* local_time = localtime(&current_time);
    
    fprintf(fptr, " Date: %02d/%02d/%d",
        local_time->tm_mday,
        local_time->tm_mon + 1,
        local_time->tm_year + 1900);
    printf(" Date: %02d/%02d/%d",
        local_time->tm_mday,
        local_time->tm_mon + 1,
        local_time->tm_year + 1900);

    fprintf(fptr, "%47s""%02d:%02d:%02d", "Time: ",
        local_time->tm_hour,
        local_time->tm_min,
        local_time->tm_sec);
    printf("%47s""%02d:%02d:%02d", "Time: ",
        local_time->tm_hour,
        local_time->tm_min,
        local_time->tm_sec);

    fprintf(fptr, "\n""\n");
    printf("\n""\n");
    
    printf( "-------------------------------------------------------------------------""\n");

    struct purchase
    {
        char itemName[20];
        float itemPrice;
        float itemQuantity;
    };

    printf("\n");

    short distinct_quantity;
    printf(" -> Enter the Number of Distinct Items to be Purchased: ");
    scanf("%d", &distinct_quantity);
    getchar();

    if (distinct_quantity <= 0)
    {
        printf(" -> Invalid Input. Please Try Again and Enter a Valid Number.\n");
        return 0;
    }

    printf("\n");

    printf( "-------------------------------------------------------------------------""\n");

    struct purchase* item = malloc(distinct_quantity * sizeof(struct purchase));

    short index = 0;

    char add_item = 'Y';

    printf("\n");

    short n = distinct_quantity;

    while(n > 0)
    {
        printf(" -> Enter the Item Name to be Purchased: ");
        fgets(item[index].itemName, 40, stdin);
        if(sizeof(item[index].itemName) > 20)
        {
            while(getchar() != '\n');
        }
        item[index].itemName[strcspn(item[index].itemName, "\n")] = '\0';
    
        printf("\n");

        while(item[index].itemPrice < 0)
        {
            printf(" -> Enter the Unit Price of the Item: ");
            scanf("%f", &item[index].itemPrice);
            getchar();

            if (item[index].itemPrice < 0)
            {
                printf(" -> Invalid Input. Please Try Again and Enter a Valid Number.\n");
            }
        }
    
        printf("\n");
    
        while(item[index].itemQuantity < 0)
        {
            printf(" -> Enter the Quantity of the Purchased Item: ");
            scanf("%f", &item[index].itemQuantity);
            getchar();

            if (item[index].itemQuantity < 0)
            {
                printf(" -> Invalid Input. Please Try Again and Enter a Valid Number.\n");
            }
        }

        printf("\n");

        ++index;

        --n;

        if(n == 0)
        {
            printf( "-------------------------------------------------------------------------""\n");
    
            printf("\n");
            
            printf(" -> Add another item ?"
                "\n"
                "    Enter 'Y' or 'y' for Yes and 'N' or 'n' for No: ");
            scanf("%c", &add_item);
            getchar();

            printf("\n");

            if(add_item == 'Y' || add_item == 'y')
            {
                ++distinct_quantity;
                ++n;

                item = realloc(item, distinct_quantity * sizeof(struct purchase));
            }
        }
    
        printf( "-------------------------------------------------------------------------""\n");
    
        printf("\n");
    }

    printf(" The Total Bill is as follows - ");
    printf("\n");
    printf("\n");

    float total_price[distinct_quantity];

    fprintf(fptr, "-------------------------------------------------------------------------""\n");
    printf( "-------------------------------------------------------------------------""\n");
    
    fprintf(fptr, " %-21s","Item");
    printf(" %-21s", "Item");

    fprintf(fptr, "%-12s", "Price");
    printf("%-12s", "Price");

    fprintf(fptr, "%-13s", "Quantity");
    printf("%-13s", "Quantity");

    fprintf(fptr, "%s", "Total Price [incl. Taxes]");

    fprintf(fptr, "\n");

    printf("%s", "Total Price [incl. Taxes]");

    printf("\n");

    fprintf(fptr, "-------------------------------------------------------------------------""\n");
    printf( "-------------------------------------------------------------------------""\n");

    for(int i = 0; i < index; i++)
    {
        fprintf(fptr, " %-21s", item[i].itemName);
        printf(" %-21s", item[i].itemName);
    
        fprintf(fptr, "%-12.2f", item[i].itemPrice);
        printf("%-12.2f", item[i].itemPrice);
        
        fprintf(fptr, "%-13.2f", item[i].itemQuantity);
        printf("%-13.2f", item[i].itemQuantity);
        
        total_price[i] = ((item[i].itemPrice * 1.18) * (item[i].itemQuantity));
        
        fprintf(fptr, "%.2f", total_price[i]);
        
        fprintf(fptr, "\n");
        
        printf("%.2f", total_price[i]);
        
        printf("\n");
    }

    float toPay = 0;
    for(int j = 0; j < index; j++)
    {
        toPay += total_price[j];
    }

    fprintf(fptr, "-------------------------------------------------------------------------""\n");

    printf( "-------------------------------------------------------------------------""\n");

    fprintf(fptr, "%38s""%8.2f", "GRAND TOTAL:", toPay);

    fprintf(fptr, "\n");

    printf("%38s""\033[1m%8.2f\033[0m", "GRAND TOTAL:", toPay);

    printf("\n");

    fprintf(fptr, "-------------------------------------------------------------------------""\n");

    printf( "-------------------------------------------------------------------------""\n");

    fprintf(fptr, "\n");

    printf("\n");

    fprintf(fptr, "#############################  THANK YOU !  #############################""\n");
    printf("#############################  THANK YOU !  #############################""\n");

    fprintf(fptr, "\n");

    printf("\n");

    free(item);
    item = NULL;

    fclose(fptr);

    return 0;
}
