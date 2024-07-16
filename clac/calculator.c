#include <stdio.h>
#include <stdlib.h>

float calculate(float a, float b, char op) 
{

    int result;

    result = 1;
    switch(op) 
    {
        case '+': 
		return a + b;
        case '-': 
		return a - b;
        case '*': 
		return a * b;
        case '/':
            if (b != 0)
		    return a / b;
            printf("Error: Division by zero\n");
            exit(1);
        case '%':
            if (b != 0)
		    return (int)a % (int)b;
            printf("Error: Modulo by zero\n");
            exit(1);
	case '^':
	    if (a == 0)
		    return 0;
	    if (b == 0 || a == 1)
		    return 1;
	    if (b - (int)b == 0)
	    {
		    for (int i = 0;i < b;i++)
			    result = result * a;
		    return result;
	    }
	    printf ("Error: unusable number\n");
	    exit(1);
 	default:
            printf("Error: Invalid operator\n");
            exit(1);
    }
}

int main() 
{
	float	*num_histry;
	float	num1, num2, result;
	int	i, max_histry;
	char	operator;
	char	continue_calc;
	

	max_histry = 3;
	num_histry = (float *)malloc(sizeof(float) * max_histry);

	do 
	{
		printf("Enter calculation (number operator number): ");
		if (scanf("%f %c %f", &num1, &operator, &num2) != 3) 
		{
			printf("Error: Invalid input\n");
			exit(1);
		}

		result = calculate(num1, num2, operator);
		num_histry[0] = num_histry[1];
		num_histry[1] = num_histry[2];
		num_histry[2] = result;

        	printf("Result: %.2f\n", result);

		printf("result log\n");

		i = 0;
		while (i < 3)
		{
			if (num_histry[i])
				printf(" %d : %f\n", i, num_histry[i]);
			else
				printf(" %d : no histry\n", i);
			i++;
		}
	        printf("Continue? (y/n): ");
        	scanf(" %c", &continue_calc);
	}
	while (continue_calc == 'y' || continue_calc == 'Y');

    	return 0;
}	
