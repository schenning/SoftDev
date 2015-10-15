#include <stdio.h>


int main() {


	// Problem 1 
	
	int a[]= {12,23,34,45,56,67,78,89,90};
	int *p;
	p=a;

	printf ("int a[]= {12,23,34,45,56,67,78,89,90};\n\n\n\n");
	
	printf("1. *p+2                %d \t\t\t\t\t Dereferencing the first index in p, which is the same as a, and adds 2: 12+2=14  \n", *p+2);
	printf("2. *(p+2)              %d \t\t\t\t\t Dereferencing the third element in the array\n", *(p+2));
	printf("3. &p+1                %p \t\t\t\t\t The adress of p+1?\n", &p+1);
	printf("4. a[4]-3              %p\n", &a[4]-3);
	printf("5. a+3                 %p\n", a+3);
	printf("6. &a[7]-p             %ld\n", &a[7]-p );
	printf("7. p+(*p-10)           %p\n", p+(*p-10));
	printf("8. *(p+*(p+8)-a[7])    %d\n", *(p+*(p+8)-a[7]));
	


	// Problem 2



		
return 0;
}
