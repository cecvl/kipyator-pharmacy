#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100 // Maximum number of products

typedef struct{
    char name[15];
    int code;
    int amount;
    float price;
}Pharmacy;

void displayEnteredProducts(Pharmacy p){
    printf("\n\t\t\tProduct Name: %s", p.name);
    printf("\n\t\t\tProduct Code: %d", p.code);
    printf("\n\t\t\tProduct Amount:  [%d]", p.amount);
    printf("\n\t\t\tProduct Price: %.2f", p.price);
    printf("\n\t\t\t=============================\n");
};

void displayCompanyName(){
    printf("\n\t\t----------EKKY PHARMCARE LTD----------\n");
};
void displayOptions(){
    printf("\n\tWELCOME TO EKKY PHARMCARE MANAGEMENT SYSTEM\n");
    printf("\n\t\t\t1. Add Product");
    printf("\n\t\t\t2. Update Product Details");
    printf("\n\t\t\t3. Delete Product");
    printf("\n\t\t\t4. Exit\n");
}

int main()
{
    Pharmacy product;
    Pharmacy EnteredProducts[MAX];
    int productCount = 0;

    while(1){
        displayOptions();
        int choice;
        printf("\n\t\tEnter your choice(1,2,3 or 4): ");
        scanf("%d", &choice);        

        switch (choice)
        {
        case 1:
            //Add Product
        displayCompanyName();
        printf("\n\n\t\t\t----ENTER PRODUCT DETAILS----");
        printf("\n\t\t\tProduct Name: ");
        scanf(" %[^\n]s", product.name);

        printf("\n\t\t\tProduct Code: ");
        scanf("%d", &product.code);
        
        printf("\n\t\t\tProduct Amount: ");
        scanf("%d", &product.amount);
        
        printf("\n\t\t\tProduct Price: ");
        scanf("%f", &product.price);

        FILE *fp;
        fp = fopen("product.csv", "a");
        //add header line
        //fprintf(fp, "Name, Code, Amount, Price\n");
        fprintf(fp, "%s, %d, %d, %.2f\n", product.name, product.code, product.amount, product.price);
        fclose(fp);
        displayEnteredProducts(product);

        EnteredProducts[productCount] = product;
        productCount++;

        char next;
        printf("\n\t\t\tDo you want to add another product? (y/n): ");
        scanf("%s", &next);

        if(next == 'N' || next == 'n'){
            for(int i = 0; i < productCount; i++){
                printf("\n\n\t\t\t=====ENTERED PRODUCTS (%d)=====\n"), i+1;
                displayEnteredProducts(product);    
            }
            return 0;
        }
            break;
        case 2:
            //Update Product Details
            break;
        case 3:
            //Delete Product
            break;    
        default:
            displayCompanyName();
            exit(0);
        }
    }
}

