#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long number = get_long("enter your cc number: ");
    // this the main checker that stores results
    int check = 0;
    // last number
    int lastN = 0;
    // first two digits
    int firstN;
    //incremental to apply true false condition below from %2 and to calculate the length
    int i = 1;

    /*
        the idea is to grab the last number with %10,
        then substract, it and divide by 10,
        so we can grab the previous number and so on.
    */
    while (number != 0)
    {
        lastN = number % 10;
        number -= lastN;
        number /= 10;
        // get the first two digits
        if (number < 100 && number > 9)
        {
            firstN = number;
        }
        // skip the last number and get the other
        if (i % 2 == 0)
        {
            lastN *= 2;
            // an extraordinary case after multiplying by 2 we could have two digits
            // so we should add them up
            if (lastN >= 10)
            {
                int holder = lastN;
                lastN %= 10;
                holder -= lastN;
                holder /= 10;
                check += lastN;
                check += holder;
            }
            else
            {
                check += lastN;
            }
        }
        else
        {
            // add numbers that should not multiplied by 2
            check += lastN;
        }

        i++;
    }
    if (check % 10 == 0)
    {
        //length of the card number.
        i -= 1;
        // visa just has one digit not two so we must modify it.
        int holder = firstN % 10;
        int checkVisa = (firstN - holder) / 10;
        if ((firstN == 34 || firstN == 37) && i == 15)
        {
            printf("AMEX\n");
        }
        else if ((firstN == 51 || firstN == 52 || firstN == 53 || firstN == 54 || firstN == 55) && i == 16)
        {
            printf("MASTERCARD\n");
        }
        else if (checkVisa == 4 && (i == 13 || i == 16))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}