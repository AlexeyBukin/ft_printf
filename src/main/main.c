#include "printf.h"

//#define STR "%015-d"
//#define ARGS 42

// TODO fails precision with like
//#define STR "this |%.10Lf|%.20f|%.17f|"
//#define ARGS 0.87650894255l, 1.025978542436587568678, 1.025978548534310421734

//#define STR "this %.10Lf float"
//#define ARGS (0.87650894255l - 0.0000000000000000001l)

int a1 = 9;
int a2 = 0;

//#define STR "|%#-+f|%-10.20f|%-30.2f|%f|%-3f|"
//#define ARGS 123., 34., 1234345., 3., 88.

#define STR "%15.f|%15.1f|%15.2f|%15.5f|%15.12f"
#define ARGS 999.99999, 999.99999, 999.99999, 999.99999, 999.99999

//
//#define STR "|% %|% 10%|"
//#define ARGS

//#define STR "|%.19f|%.19f|"
//#define ARGS 1.025978542436587568678, -1.025978542436587568678

//#define STR "|%.f|%.f|%.f|%.f|%.f|%.f|"
//#define ARGS 44.5, 45.5, 44.4, 44.6, 44.50001, 44.5 + 1e-52

//#define STR "|%.f|%.f|"
//#define ARGS 44.50001, 44.5

#include <math.h>
int		main() {

	float b = 111.3;
	int a = fmod(b, 10.0);
	printf("a is %d\n\n", a);


	int *a4 = (int*)malloc(sizeof(int));
	ft_printf("ft_printf: \'"STR"\'\n", ARGS);
	//printf("gg_printf: \'"STR"\'\n", ARGS);
	free(a4);
	return (0);
}