#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int maxamountcarddigits = 16;
    long power = 10;
    int oddnumber = 1;
    int cardlength = 0;
    int *totalnumber = malloc(sizeof(int));
    if (totalnumber == NULL) {
        return 1;
    }
    int *sumofsecondnums = malloc(sizeof(int));
    if (sumofsecondnums == NULL) {
        return 1;
    }
    int *sumoffirstnums = malloc(sizeof(int));
    if (sumoffirstnums == NULL) {
        return 1;
    }
    *totalnumber = 0;
    *sumoffirstnums = 0;
    *sumofsecondnums = 0;

    long *cardnumber = malloc(2 * sizeof(long));
    if (cardnumber == NULL)
    {
        return 1;
    }
    printf("Number:");
    scanf("%ld", cardnumber);

    // Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.

    for (int place = 0; place < maxamountcarddigits; ++place)
    {
        long findnum = *cardnumber % power;
        // printf("current: %ld oddnumber: %i cardnumber: %ld cardlength: %i \n", findnum, oddnumber, *cardnumber, cardlength);
        if (oddnumber == 1) {
            // *sumoffirstnums = *sumoffirstnums + *cardnumber;
            // printf("firsts: %i \n", *sumoffirstnums);
            *sumoffirstnums = *sumoffirstnums + findnum;
            // printf("firsts: %i\n", *sumoffirstnums);
            oddnumber = 2;
        } else {
            // *sumofsecondnums = *sumofsecondnums + (*cardnumber * 2);
            // printf("seconds: %i \n", *sumofsecondnums);
            *sumofsecondnums = *sumofsecondnums + (findnum * 2);
            //printf("seconds: %i\n", *sumofsecondnums);
            oddnumber = 1;
        }
        *cardnumber = *cardnumber / 10;
        cardlength = cardlength + 1;
        if (*cardnumber == 0){
            break;
        }
    }
    //printf("seconds: %i firsts: %i \n", *sumoffirstnums, *sumofsecondnums);
    // Add the sum to the sum of the digits that weren’t multiplied by 2.
    *totalnumber = *sumoffirstnums + *sumofsecondnums;
    // If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!
    if (*totalnumber % 10 == 0) {
        //printf("Valid Card. Total number length: %i", cardlength);
        // American Express uses 15-digit numbers, MasterCard uses 16-digit numbers, and Visa uses 13- and 16-digit numbers.
        switch(cardlength)
        {
            case 13:
                printf("VISA\n");
            case 15:
                printf("AMEX\n");
                break;
            case 16:
                printf("MASTERCARD\n");
                break;
            default:
                break;
        }
        // AMEX\n or MASTERCARD\n or VISA\n or INVALID\n
    } else {
        printf("INVALID\n");
    }
    free(cardnumber);
    free(sumoffirstnums);
    free(sumofsecondnums);
    free(totalnumber);
}