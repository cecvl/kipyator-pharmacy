#include <stdio.h>
#include <conio.h>
#include <string.h>
int code, qty, nxt;
float price, amt, total, cash, change; 
char next, ans;

 //BODY
 /*display products
    ask for code and amount
    display total amount
    ask if they want to buy another product
    if yes, repeat
    if no, ask for cash
    display change
    save code, amount sold & total cost to a file
    deduct quantity from inventory
 */
int main()
   
{
do {
    // Display all available products
    printf("     EKKY PHARMCARE LTD");
    printf("\n\n   --AVAILABLE PRODUCTS-- ");
    printf("\n = = = = = = = = = = = = = = = = = \n\n");
    printf("[101] Panadol\t\t   10.00\n");
    printf("[102] Paracitamol\t   15.00\n");
    printf("[103] Flugone\t\t   20.00\n");
    printf("[104] Cetrizine\t\t   20.00\n");
    printf("[105] Amoxyllin\t\t   15.00\n");
    printf("[106] Ampliclox\t\t   15.00\n");
    printf("[107] Metronidazol\t   20.00\n");
    printf("[108] Alugel Suspension\t   30.00\n");
    printf("[109] Diclofenac\t   15.00\n");
    printf("[110] Couph Syrup\t   20.00\n");
    printf("[111] Omeprazole\t   25.00\n");
    printf("[112[ Ibuprofen\t\t   20.00");
    printf("\n = = = = = = = = = = = = = = = = = \n");

    do {
        printf("\nProduct Code\t: ");
        scanf("%d", &code);
        printf("\nQuantity\t: ");
        scanf("%d", &qty);

        switch (code)
        {
            case 101:
                price = 10.00;
            break;
            case 102:
                price = 15.00;
            break;
            case 103:
                price = 20.00;
            break;
	        case 104:
	        	price = 20.00;
			break;
            case 105:
				price = 15.00;
			break;	 
		    case 106:
		    	price = 15.00;
		    break;	
            case 107:
				price = 20.00; 
			break;
		    case 108:
				price = 30.00;
			break;
		    case 109:
				price = 15.00;
			break;
		    case 110:
				price = 20.00;		
			break;
			case 111:
				price = 25.00;
			break;
		    case 112:
		    	price = 20.00;
			break;	 
            default: printf("Enter quantity\n");
			         scanf("%d, &qty"); 
		    break;
        }

        // Compute the amount for each product
        amt = price * qty;
        printf("Amount\t\t: %.2f", amt);

        // Compute total amount for all purchase
        total = total + amt;
        
        printf("\nNext? Enter any number (0 to exit): ");
        scanf("%d", &nxt);
    } while (nxt!=0);

    printf("\n = = = = = = = = = = = = = = = = = \n");
    printf("TOTAL\t\t: %.2f", total);
    printf("\n = = = = = = = = = = = = = = = = = \n");

    do {
        // Input cash payment, credit not allowed
        printf("\nCash\t\t: ");
        scanf("%f", &cash);

        // Compute amount change
        change = cash - total;
        printf("Change\t\t: %.2f", change);
    } while (cash<total);
    
    printf("\n\nNext Transaction? [y/n]: ");
    ans = getch();
    if
    	(ans = getch){
			printf("\n\n===== AFYA BORA, WAJIBU WETU =====\n");
		}
    
} while (ans=='y' || ans=='Y');
  
             
  return 0;
}