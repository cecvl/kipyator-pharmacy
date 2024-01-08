#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100 // Maximum number of products

typedef struct {
    char name[15];
    int code;
    int amount;
    float price;
} Pharmacy;

void displayproduct(Pharmacy product) {
    printf("\n\n\t\tName and Code : %s[%d]", product.name, product.code);
    printf("\n\t\tProduct Price: %.2f", product.price);
    printf("\n\t\tProduct Amount:  %d", product.amount);
}
void displayCompanyName() {
    printf("\n\t\t===============EKKY PHARMCARE LTD=================");
}
void displayOptions() {
    printf("\n\t\t\t1. Add Product");
    printf("\n\t\t\t2. Search Product");
    printf("\n\t\t\t3. Update Product Details");
    printf("\n\t\t\t4. Delete Product");
    printf("\n\t\t\t5. Exit\n");
}
void displayBorderLine() {
    printf("\n\t\t==============================================");
}

void initializeProduct(Pharmacy* searchproduct) {
    strcpy(searchproduct->name, "");
    searchproduct->code = 0;
    searchproduct->amount = 0;
    searchproduct->price = 0.0;
}

Pharmacy* findProductbyCode(const char* filename, int p_code, int* numMatches) {
    Pharmacy* foundProducts = malloc(MAX * sizeof(Pharmacy));

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("\n\t\t\tERROR: Unable to open file %s", filename);
        *numMatches = 0;
        return foundProducts;
    }

    char buffer[100];
    Pharmacy s_product;
    *numMatches = 0;

    while (fgets(buffer, sizeof(buffer), fp)) {
        initializeProduct(&s_product);
        sscanf(buffer, "%[^,], %d, %d, %f", s_product.name, &s_product.code, &s_product.amount, &s_product.price);

        if (s_product.code == p_code) {
            foundProducts[*numMatches] = s_product;
            (*numMatches)++;
        }
    }
    fclose(fp);
    return foundProducts;
}

int main() {
    Pharmacy product;
    Pharmacy input_products[MAX];
    int productCount = 0;

    //Pharmacy edit_input_products[MAX];
    //Pharmacy search_product;

    while (1) {
        displayCompanyName();
        displayOptions();
        int choice;
        printf("\n\t\tEnter your choice(1,2,3,4 or 5): ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            // Add Product
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
            FILE* fp;
            fp = fopen("product.csv", "a");
            fprintf(fp, "%s, %d, %d, %.2f\n", product.name, product.code, product.amount, product.price);
            displayBorderLine();

            if (ferror(fp)) {
                printf("\n\t\t\tERROR adding product to system.");
                return 1;
            } else {
                printf("\n\t\t\tPRODUCT ADDED TO THE SYSTEM.");
            }

            displayBorderLine();
            fclose(fp);

            input_products[productCount] = product;
            productCount++;

            char next;
            printf("\n\n\t\tDo you want to add another product? (y/n): ");
            scanf(" %c", &next);

            if (next == 'N' || next == 'n') {
                for (int i = 0; i < productCount; i++) {
                    printf("\n\n\t\t============= INPUT PRODUCT =============");
                    displayproduct(input_products[i]);
                }
                displayBorderLine();
                printf("\n\t\tTotal number of inputs: %d", productCount);
                displayBorderLine();
                return 0;
            }
            break;

        case 2:
            // Search Product
            printf("\n\t\t===========SEARCH PRODUCT=============");
            printf("\n\t\tEnter Product Code to search : ");
            int codetosearch;
            scanf("%d", &codetosearch);

            // initialize search product
            int searchMatches;
            Pharmacy* found_products = findProductbyCode("product.csv", codetosearch, &searchMatches);

            displayBorderLine();
            if (searchMatches == 0) {
                printf("\n\t\t\tNO PRODUCT FOUND with code: [%d]", codetosearch);
                displayBorderLine();
            } else {
                printf("\n\t\t\tProducts Found (%d)", searchMatches);
                displayBorderLine();
                for (int i = 0; i < searchMatches; i++) {
                    displayproduct(found_products[i]);
                    displayBorderLine();
                }
            }

            // Free the allocated memory for found_products
            free(found_products);
            break;

        case 3:
            // Edit Product Details
            printf("\n\t\t===========EDIT PRODUCT DETAILS=============");
            int codetoedit;
            printf("\n\t\t\tEnter Product Code to Edit : ");
            scanf("%d", &codetoedit);
            // Add code for editing product details here
            break;

        case 4:
            // Delete Product
            printf("\n\t\t===========DELETE PRODUCT=============");
            printf("\n\t\tEnter Product Code to Delete : ");
            int codetodelete;
            scanf("%d", &codetodelete);

            int deleteMatches;
            Pharmacy* found_delete_products = findProductbyCode("product.csv", codetodelete, &deleteMatches);

            displayBorderLine();
            if (deleteMatches == 0) {
                printf("\n\t\t\tNo product found with code: %d", codetodelete);
                displayBorderLine();
            } else {
                printf("\n\t\t\tProducts Found (%d)", deleteMatches);
                for (int i = 0; i < deleteMatches; i++) {
                    displayproduct(found_delete_products[i]);
                    displayBorderLine();
                }
            }
            displayBorderLine();
            printf("\n\t\t***** Actions Available: *****");
            printf("\n\t\t\t1. Delete Product");
            printf("\n\t\t\t2. Exit");
            printf("\n\t\tEnter your choice(1 or 2): ");
            int delete_choice;
            scanf(" %d", &delete_choice);

            switch (delete_choice) {
                case 1:
                    // Delete product
                    FILE* write_fp = fopen("temp.csv", "w");
                    if (write_fp == NULL) {
                        printf("\n\t\t\tERROR creating file.");
                        return 1;
                    }

                    FILE* read_fp = fopen("product.csv", "r");
                    if (read_fp == NULL) {
                        printf("\n\t\t\tError opening file.");
                        fclose(write_fp);
                        return 1;
                    }
                    char buffer[100];
                    while(fgets(buffer, sizeof(buffer), read_fp)) {
                        Pharmacy f_product;
                        initializeProduct(&f_product);
                        sscanf(buffer, "%[^,], %d, %d, %f", f_product.name, &f_product.code, &f_product.amount, &f_product.price);

                        if (f_product.code != codetodelete) {
                            fprintf(write_fp, "%s, %d, %d, %.2f\n", f_product.name, f_product.code, f_product.amount, f_product.price);
                        }
                        
                    }
                    fclose(read_fp);
                    fclose(write_fp);

                    remove("product.csv");
                    rename("temp.csv", "product.csv");

                    displayBorderLine();
                    printf("\n\t\t\tProduct DELETED : %s [%d]", found_delete_products[0].name, found_delete_products[0].code);
                    displayBorderLine();
                    break;
                case 2:
                    // Exit
                    displayBorderLine();
                    return 0;
                default:
                    printf("\n\t\t\tInvalid choice. Enter a valid choice.");
                    break;        
            }

            free(found_delete_products);
            break;

        case 5:
            // Exit
            return 0;

        default:
            printf("\n\t\t\tInvalid choice. Enter a valid choice.");
            break;
        }
    }

    return 0;
}
