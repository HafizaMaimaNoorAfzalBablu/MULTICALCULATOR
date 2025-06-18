#include <stdio.h>
#include <complex.h>
#include <math.h>

int main(void)
{
    double real, imag;
    double complex z1, z2, result;
    int choice;

    while (1)
    {
        printf("\n\t\t=========== Complex Calculator ============\n");
        printf("1. Addition       2. Subtraction     3. Multiplication\n");
        printf("4. Division       5. Magnitude       6. Conjugate\n");
        printf("7. Square root    0. Exit\n");
        printf("Choose an option: ");

        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n')
                ;
            continue;
        }
        while (getchar() != '\n')
            ;

        if (choice >= 1 && choice <= 4)
        {

            printf("Enter real and imag parts of z1: ");
            while (scanf("%lf %lf", &real, &imag) != 2)
            {
                printf("Invalid! Re-enter z1: ");
                while (getchar() != '\n')
                    ;
            }
            z1 = real + imag * I;
            while (getchar() != '\n')
                ;

            printf("Enter real and imag parts of z2: ");
            while (scanf("%lf %lf", &real, &imag) != 2)
            {
                printf("Invalid! Re-enter z2: ");
                while (getchar() != '\n')
                    ;
            }
            z2 = real + imag * I;
            while (getchar() != '\n')
                ;
        }
        else if (choice >= 5 && choice <= 7)
        {

            printf("Enter real and imag parts of z: ");
            while (scanf("%lf %lf", &real, &imag) != 2)
            {
                printf("Invalid! Re-enter z: ");
                while (getchar() != '\n')
                    ;
            }
            z1 = real + imag * I;
            while (getchar() != '\n')
                ;
        }

        switch (choice)
        {
        case 1:
            result = z1 + z2;
            printf("Sum = %.4f %+.4fi\n", creal(result), cimag(result));
            break;
        case 2:
            result = z1 - z2;
            printf("Difference = %.4f %+.4fi\n", creal(result), cimag(result));
            break;
        case 3:
            result = z1 * z2;
            printf("Product = %.4f %+.4fi\n", creal(result), cimag(result));
            break;
        case 4:
            if (cabs(z2) == 0.0)
            {
                printf("Error: Division by zero!\n");
                break;
            }
            result = z1 / z2;
            printf("Quotient = %.4f %+.4fi\n", creal(result), cimag(result));
            break;
        case 5:
            printf("Magnitude = %.4f\n", cabs(z1));
            break;
        case 6:
            result = conj(z1);
            printf("Conjugate = %.4f %+.4fi\n", creal(result), cimag(result));
            break;
        case 7:
            result = csqrt(z1);
            printf("Square root = %.4f %+.4fi\n", creal(result), cimag(result));
            break;
        default:
            printf("Invalid choice. Try again.\n");
            break;
        }
    }
    return 0;
}