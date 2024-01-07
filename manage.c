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

void displayinput_products(Pharmacy p){
   
    printf("\n\n\t\tProduct Name: %s", p.name);
    printf("\n\t\tProduct Code: %d", p.code);
    printf("\n\t\tProduct Amount:  [%d]", p.amount);
    printf("\n\t\tProduct Price: %.2f", p.price);
};

void displayCompanyName(){
    printf("\n\t\t===============EKKY PHARMCARE LTD=================");
};
void displayOptions(){
    printf("\n\t\t\t1. Add Product");
    printf("\n\t\t\t2. Search Product");
    printf("\n\t\t\t3. Update Product Details");
    printf("\n\t\t\t4. Delete Product");
    printf("\n\t\t\t5. Exit\n");
}
void displayBorderLine(){
    printf("\n\t\t==============================================");
}

int main()
{
    Pharmacy product;
    Pharmacy edit_product;
    Pharmacy search_product;

    Pharmacy input_products[MAX];
    Pharmacy edit_input_products[MAX];
    Pharmacy search_input_products[MAX];

    int productCount = 0;
    int editCount = 0;

    while(1){
        displayCompanyName();
        displayOptions();
        int choice;
        printf("\n\t\t     Enter your choice(1,2,3 ,4 or 5): ");
        scanf("%d", &choice);        

        switch (choice)
        {
        case 1:
            //Add Product
        printf("\n\t\t===========ENTER PRODUCT DETAILS=============");
        printf("\n\t\t\tProduct Name: ");
        scanf(" %[^\n]s", product.name);

        printf("\n\t\t\tProduct Code: ");
        scanf("%d", &product.code);
        
        printf("\n\t\t\tProduct Amount: ");
        scanf("%d", &product.amount);
        
        printf("\n\t\t\tProduct Price: ");
        scanf("%f", &product.price);

        // Write to file
        FILE *fp;
        fp = fopen("product.csv", "a");
        //add header line
        //fprintf(fp, "Name, Code, Amount, Price\n");
        fprintf(fp, "%s, %d, %d, %.2f\n", product.name, product.code, product.amount, product.price);
        displayBorderLine();

        if(ferror(fp)){
            printf("\n\t\t\tERROR adding product to system.");
            return 1;
        }else{
            printf("\n\t\t\tPRODUCT ADDED THE SYST|E|M.");
        }
        displayBorderLine();
        fclose(fp);
        
        input_products[productCount] = product;
        productCount++;

        char next;
        printf("\n\n\t\tDo you want to add another product? (y/n): ");
        scanf(" %s", &next);

        if(next == 'N' || next == 'n'){
            for(int i = 0; i < productCount; i++){
                printf("\n\n\t\t============= INPUT PRODUCT =============");
                displayinput_products(input_products[i]);    
            }
            displayBorderLine();
            printf("\n\t\tTotal number of inputs: %d", productCount);
            displayBorderLine();
            return 0;
        }
            break;
        case 2:
            //Search Product
            printf("\n\t\t===========SEARCH PRODUCT=============");
            printf("\n\t\tEnter Product Code to search : ");
            scanf(" %d", search_product.code);

            //search in file
            
        case 3:
            //Edit Product Details
            //Write a program to edit product details in the file
            printf("\n\t\t===========EDIT PRODUCT DETAILS=============");
            printf("\n\t\t\tEnter Product Code to search : ");
            scanf(" %d", edit_product.code);

            break;
           
        case 4: 
            //Delete Product
            break;         
        default:
            printf("\n\t\t\tInvalid choice. Enter a valid choice.");
            break;
        }
    return 0;
    }
    }