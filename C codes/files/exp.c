#include <stdio.h>
// int main () {
//     int s;
//     for (s=0;s<=10;s++){
//         printf("HEllo");
//         if (s==5)
//         continue;
//         printf("%d ",s);
//     }
//     return 0;
// }

// C program to implement
// the above approach
// #include <stdio.h>

// // Iterative function to
// // reverse digits of num
int reverseDigits(int num)
{
	int rev_num = 0;
	while (num > 0)
	{
		rev_num = rev_num * 10 + num % 10;
		num = num / 10;
	}
	return rev_num;
}

// // Driver code
int main()
{
	int num = 4562;
	
	reverseDigits(num);
	printf("Reverse of no. is %d",num);

	return 0;
}


// #include <stdio.h>
// int main () {
//     int i;
//     scanf("%d", &i);
//     if (i<0)
//         printf("-ve");
//     else if (i>0) printf("+ve");
//     return 0;

// }