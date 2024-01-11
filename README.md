# Pharmacy point-of-sale system

## Overview

This is a simple point-of-sale system for a pharmacy. It allows users to add, search, update, and delete product details in a pharmacy inventory.

## Design

**Main (main.c)**

NOT YET COMPLETED.
This is the main part of the program where sales will occur.
Display available products.
Calculate total cost and show receipts.
Automatically reduce number of products in the inventory after sales.
**Optional:**
Include file to store sales records.

**Manage (manage.c)**

This is designed to be the management module.
It has 4 main features:

1. **Add Product:** Add a new product to the inventory with details: name, code, amount & price.

2. **Search Product:** Search for a product by entering its code and display its details.

3. **Update Product Details:** NOT YET COMPLETED. The intention of this feature is to edit specific details of a product in the inventory.

4. **Delete Product:** Search for a product by its code then choose whether to delete it or not.

**File Handling**

- Product details are stored in a csv file named "product.csv."
- Deleting a product updates the csv file accordingly.

**Build and Run**

Compile and run the program with an appropriate compiler.
