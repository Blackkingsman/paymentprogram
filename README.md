# House Payment Calculator

A C++ mortgage calculator. Enter the loan amount, the yearly interest rate, and the term in years, and it prints the monthly payment and a full month-by-month amortization table.

> Built by hand in 2020, before AI coding tools. Left as originally written.

## Example

Input: `200000`, `5`, `30`

```
 -------------------------------------------------------------------------
| Principal 200000.00   Interest 5.0000   Years 30.000    Payment 1073.64 |
|                                                                         |
| Month   Pay       Total     Monthly   Principal    Total     Remaining  |
|                   Paid     Interest      Paid    Principal    Balance   |
|                                                     Paid                |
|                                                                         |
|   1  1073.64     1073.64    833.33      240.31     240.31   199759.69   |
|   2  1073.64     2147.29    832.33      241.31     481.62   199518.38   |
|   3  1073.64     3220.93    831.33      242.32     723.94   199276.06   |
...
```

## How it works

The monthly payment uses the standard amortization formula:

```
payment = P · r / (1 − (1 + r)^−n)      r = annual rate / 1200,  n = years · 12
```

Each month, interest is `balance · r`, the rest of the payment goes to principal, and the table is formatted with `<iomanip>`.

## Running it

```bash
g++ housepayment.cpp -o payment
./payment
```
