//Ahmed Rami Otsmane
//TP1 ALSDS 1CPS1 2023-2024

#include <stdio.h>
#include <stdbool.h>

int main() {
    bool q1 = false, q2 = false;
    char CardType;
    int CardNum, ch, eof = 0;
    do
    {
        //Display the main menu 
        printf("\n-------------------- MENU ----------------------\n-  1 : Enter Card Type : A, B, C);             -\n-  2 : Enter and check of the card number ---> -\n-  A (8 digits) ; B (7 digits) ; C (6 digits)  -\n-  3 : Checking the card validity              -\n-  4 : Exit                                    -\n------------------------------------------------\n");
        printf("What is your choice ---> : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1 : 
            q1 = true;
            do {
                printf("\nEnter a valid Card Type : A (8 Digits) ; B (7 Digits); C (6 Digits) : ");
                scanf(" %c", &CardType );
            } while ( CardType != 'A' && CardType != 'B' && CardType != 'C' );
            break; 
        case 2 : 
            if (q1 == false)
            {
                printf("Please enter a card type in first !\n");
            }
            else {
                q2 = true;
                bool valid = false;
                do
                {
                    printf("\nPlease enter a valid card number : ");
                    scanf("%d", &CardNum);
                    int temp = CardNum, cpt = 0;
                    //Count the digits of the card number
                    while (temp != 0 )
                    {
                        cpt++;
                        temp = temp / 10;
                    }
                    switch (CardType)
                    {
                    case 'A':
                        if (cpt == 8)
                        {
                            valid = true;
                        }
                        break;
                    case 'B':
                        if (cpt == 7)
                        {
                            valid = true;
                        }    
                        break;
                    case 'C':
                        if (cpt == 6)
                        {
                            valid = true;
                        }
                        break;
                    }
                } while (valid == false);
            }
            break;
        case 3 : 
            if ( q1 == false || q2 == false )
            {
                printf("Please enter a valid card number !");
            }
            else {
                int temp = CardNum;
                int sum = 0, d;
                while (temp != 0)
                {
                    d = ((temp % 100) / 10) *2;
                        while (d != 0)
                        {
                            sum = sum+ d% 10;
                            d = d / 10;
                        }
                    sum = sum + temp % 10;
                    temp= temp /100;
                }
                if (sum % 10 == 0)
                {
                    printf("\n--------------- Card Validity ------------------\nCard type : '%c' with number : %d\nCalculated sum by the method = %d\nThe last digit is 0 ----> Valid Card\n", CardType, CardNum, sum);
                }
                else {
                    printf("\n--------------- Card Validity ------------------\nCard type : '%c' with number : %d\nCalculated sum by the method = %d\nThe last digit is not 0 ----> Invalid Card\n", CardType, CardNum, sum);
                }
            }
            break;
        case 4: 
            eof = 1;
            break;
        default: 
            printf("\n-------------- Error of choice! ----------------\n");
            break; 
        }
    } while ( eof == 0);
    printf("\n--------------- End of program -----------------");
}
