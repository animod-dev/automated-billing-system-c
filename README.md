# Automated Billing System in C

A console-based **Automated Billing System** developed using the C programming language. The program collects purchased item details, calculates item-wise totals after applying an 18% tax rate, computes the grand total, and generates a formatted bill on the terminal and in a text file.

## Project Overview

The Automated Billing System simplifies basic billing operations by allowing users to enter the items they wish to purchase, their unit prices, and their quantities. It automatically calculates the total cost of each item, includes the applicable tax rate used by the program, and generates the final bill.

The generated bill contains the current date and time, item details, tax-inclusive totals, and the grand total payable. A copy is saved in `Bill.txt` for reference.

## Features

- **Interactive User Input:** Accepts the number of distinct items, item names, unit prices, and purchase quantities.
- **Dynamic Memory Allocation:** Uses dynamic memory allocation to store item details and accommodate additional items.
- **Add More Items:** Allows users to add another item after entering the initially specified items.
- **Automatic Tax Calculation:** Applies an 18% tax rate to each item's subtotal.
- **Item-Wise Billing:** Calculates and displays the tax-inclusive total for every item.
- **Grand Total Calculation:** Adds the individual item totals to calculate the total amount payable.
- **Date and Time Display:** Includes the current system date and local time in the bill.
- **Formatted Bill:** Displays item details in a structured tabular layout.
- **File Generation:** Writes a copy of the bill to `Bill.txt`.
- **Memory Cleanup:** Releases dynamically allocated memory before the program terminates.

## Technologies Used

- **Programming Language:** C
- **Standard Libraries:**
  - `stdio.h` — Input/output operations and file handling.
  - `stdlib.h` — Dynamic memory allocation and memory deallocation.
  - `string.h` — String manipulation.
  - `time.h` — Retrieving the current date and time.

## Billing Logic

The program calculates the total price of each item using the following formula:

**1. Calculate the subtotal**

\[
\text{Subtotal} = \text{Unit Price} \times \text{Quantity}
\]

**2. Calculate the tax**

\[
\text{Tax} = \text{Subtotal} \times 0.18
\]

**3. Calculate the tax-inclusive item total**

\[
\text{Item Total} = \text{Subtotal} + \text{Tax}
\]

Equivalently:

\[
\text{Item Total} = \text{Unit Price} \times 1.18 \times \text{Quantity}
\]

**4. Calculate the grand total**

\[
\text{Grand Total} = \sum_{i=1}^{n} \text{Item Total}_i
\]

Here, \(n\) represents the number of items entered into the bill.

> **Note:** The program uses a fixed 18% tax rate. This is the rate implemented in the source code and is not dynamically determined from tax rules or item categories.

## 💻 Sample Output

The following is an illustrative example of the bill format. The date, time, and calculated amounts will depend on the user's input and system clock.

```text
#########################################################################
                 WELCOME TO THE AUTOMATED BILLING SYSTEM
#########################################################################

 Date: DD/MM/YYYY                                      Time: HH:MM:SS

-------------------------------------------------------------------------

 Item Name: [Entered by User]

-------------------------------------------------------------------------

 The Total Bill is as follows -

-------------------------------------------------------------------------
 Item                 Price       Quantity     Total Price [incl. Taxes]
-------------------------------------------------------------------------
 Notebook             50.00       2.00         118.00
 Pen                  10.00       3.00         35.40
-------------------------------------------------------------------------
                            GRAND TOTAL:   153.40
-------------------------------------------------------------------------

#############################  THANK YOU !  #############################
```

The displayed item names, unit prices, quantities, and totals above are examples to illustrate the intended billing format.

## Output File

After running the program, a file named `Bill.txt` is created in the program's current working directory.

The file contains:

- Billing system heading
- Current date and time
- Item names
- Unit prices
- Purchase quantities
- Item-wise totals, including the fixed 18% tax
- Grand total payable
- Closing thank-you message

**Important:** The file is opened in write mode (`"w"`), so an existing `Bill.txt` file is overwritten when the program starts.

## Concepts Demonstrated

This project provides practical experience with fundamental C programming concepts, including:

- Structures (`struct`) for organizing related item data.
- Arrays for storing calculated item totals.
- Pointers for accessing dynamically allocated item records.
- Dynamic memory allocation using `malloc()` and `realloc()`.
- Memory deallocation using `free()`.
- Loops and conditional statements for input processing and calculations.
- Functions from standard C libraries for input/output, string manipulation, and date/time handling.
- File handling using `fopen()`, `fprintf()`, and `fclose()`.
- Floating-point arithmetic for billing calculations.
- Formatted output using `printf()` and `fprintf()`.

## Author

**Anish Moodi**

GitHub: https://github.com/anmo-02

Replace the placeholder author details with your own information.
