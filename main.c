//
// Created by Lesia Kiseleva on 10.12.2020.
//

//%7.5s", "bombastic");}



# include <stdio.h>
#include "ft_printf.h"
# include <limits.h>

#define BPRINT(x, ...) PRINT("\"%s\" // 1st '*' = %d, 2nd '*' = %d\n", x, a, b)


int main(void)
{
//	//char *ch = "start";
////	ch = NULL;
//	//char c = 'j';
//	//float f1 = 0.75;
//	//int f = 1;
////	printf("%7.3s%7.7sfin\n", "hello", "world");
////	ft_printf("%7.3s%7.7sfin\n", "hello", "world");
////	printf("%.6i\n", -3);
////	ft_printf("%.6i\n", -3);
////	printf("%07i\n", -54);
////	ft_printf("%07i\n", -54);
////	printf("%7i\n", -14);
////	ft_printf("%7i\n", -14);
////	printf("%7i\n", -2562);
////	ft_printf("%7i\n", -2562);
////	printf("\'%5.i\'\n", 0);
////	ft_printf("\'%5.i\'\n", 0);
////	printf("this %i number\n", -267);
////	ft_printf("this %i number\n", -267);
//	printf("%-3.7i\n", 3267);
//	ft_printf("%-3.7i\n", 3267);
//
//	printf("%-8.5i\'\n", 34);
//	ft_printf("%-8.5i\'\n", 34);
//	printf("%-10.5i\'\n", -216);
//	ft_printf("%-10.5i\'\n", -216);
	printf("%-05%\n");
	ft_printf("%-05%\n");
//	printf("%-7i\'\n", -14);
//	ft_printf("%-7i\'\n", -14);
//
//	printf("%.i\'\n", 0);
//	ft_printf("%.i\'\n", 0);
//	printf("%u\n", 4294967295u);
//	ft_printf("%u\n", 4294967295u);

//
//	printf("%-*s\'\n", -32, "abc");
//	ft_printf("%-*s\'\n", -32, "abc");
//
//////	printf("%.7s%.2s\n", "hello", "world");
////	ft_printf("%.7s%.2s\n", "hello", "world");
//
//char * it = "it";
//


//	printf("%u\n", INT_MIN);
//	ft_printf("%u\n", INT_MIN);

//	printf("%x\n", -12);
//	ft_printf("%x\n", -12);
//	printf("%X\n", -12);
//	ft_printf("%X\n", -12);

//	printf("'%p'\n", it);
//	ft_printf("'%p'\n", it);
//	printf("'%p'\n", &it);
//	ft_printf("'%p'\n", &it);


//
//
//		int		a = -4;
////		int		b = 0;
		char	c = 'a';
		int		d = 2147483647;
		int		e = -2147483648;
////	//	int		f = 42;
////	//	int		g = 25;
////	//	int		h = 4200;
		int		i = 8;
		int		j = -12;
		int		k = 123456789;
		int		l = 0;
		int		m = -12345678;
////		char	*n = "abcdefghijklmnop";
//////		char	*o = "-a";
////		char	*p = "-12";
////		char	*q = "0";
//////		char	*r = "%%";
////		char	*s = "-2147483648";
//////		char	*t = "0x12345678";
////		char	*u = "-0";
	int b1 = 0;
	int b2 = 0;
////
//////	PRINT(" --- Return : %d\n", PRINT("%-.i, %-.d, %-.d, %-.d, %-.d, %-.d, %-.d, %-.d", i, j, k, l, m, c, e, d)); //T17
//////	PRINT(" --- Return : %d\n", PRINT("%-.0i, %-.0d, %-.0d, %-.0d, %-.0d, %-.0d, %-.0d, %-.0d", i, j, k, l, m, c, e, d)); //T18
////////		PRINT(" --- Return : %d\n", PRINT("Simple input test"));
//////	b1 = printf("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X\n", i, j, k, l, m, n, c, c, j, j, j); //T2
//////	b2 = ft_printf("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X\n", i, j, k, l, m, n, c, c, j, j, j); //T2
////////
//////printf("%d\n%d\n",b1,b2);
////
////
////	b1 = printf("%-.i, %-.d, %-.d, %-.d, %-.d, %-.d, %-.d, %-.d\n", i, j, k, l, m, c, e, d); //T2
////	b2 = ft_printf("%-.i, %-.d, %-.d, %-.d, %-.d, %-.d, %-.d, %-.d\n", i, j, k, l, m, c, e, d); //T2
//////
////
////	b1 = printf("%-.i, %-.d, %-.d, %-.d, %-.d, %-.d, %-.d, %-.d\n", i, i, i, i, i, i, i, i); //T2
////	b2 = ft_printf("%-.i, %-.d, %-.d, %-.d, %-.d, %-.d, %-.d, %-.d\n", i, i, i, i, i, i, i, i); //T2
////printf("%d\n%d\n",b1,b2);
//
//	b1 = printf("%-.i\n", i); //T2
//	b2 = ft_printf("%-.i\n", i); //T2
//	printf("%d\n%d\n",b1,b2);
	//b2 = ft_printf("%1.i\n", i); //T2
//
//	b1 = printf("%1.i, %1.d, %1.d, %1.d, %1.d, %1.d, %1.d, %1.d\n", i, j, k, l, m, c, e, d); //T2
//	b2 = ft_printf("%1.i, %1.d, %1.d, %1.d, %1.d, %1.d, %1.d, %1.d\n", i, j, k, l, m, c, e, d); //T2
////
//printf("%d\n%d\n",b1,b2);

	int num = 70;
	int a = -2;
	int b = -2;
	while(a < 5) //T70-177
	{
		b = -2;
		while (b < 5)
		{

			b1 =printf("%*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d\n", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d);
			b2 = ft_printf("%*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d\n", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d);
			printf("%d:%d==%d, a == %d, b == %d\n",num, b1, b2, a, b);
			num ++;
			b1 =printf("%-*.*i, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d\n", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d);
			b2 =ft_printf("%-*.*i, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d\n", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d);
			printf("%d:%d==%d\n",num, b1, b2);
			num ++;
			b1 =printf("%0*.*i, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d\n", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d);
			b2 =printf("%0*.*i, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d\n", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d);
			printf("%d:%d==%d\n",num, b1, b2);
			num ++;
			b++;
		}
		a++;
	}

	a = -2;
	b = 3;
	b1 =printf("%*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d\n", a, b, j, a, b, i, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d);
	b2 = ft_printf("%*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d\n", a, b, j, a, b, i, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d);
	printf("%d:%d==%d, a == %d, b == %d\n",85, b1, b2, a, b);


//
//	b1 = printf("%u, %x, %X\n", j, j, j); //T2
//	b2 = ft_printf("%u, %x, %X\n", j, j, j); //T2
//
//	printf("%d\n%d\n",b1,b2);
	return (0);
}