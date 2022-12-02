#include <unistd.h>
#include <stdio.h>

int main(void){
    char a[3] = {'a', 'b', 'c'};
    //write(1, &a, 3);

    printf("%d", -21 / 10);

    return 0;
}

int count_length(int number)
{
	if (number < 0)
	{
		int b =  number * 2;
		number = number - b;
	}
	return count_length_helper(number);
}

int count_length_helper(int number)
{
    static int count = 0;
    if (number > 0)
    {
        count++;
        number /= 10;
        count_length(number);
    }

	return number;
}