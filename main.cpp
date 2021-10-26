#include "func.h"


int main()
{
    TEST();

    printf ("\ngimme coefficients (u have only 2 chance, because i am zae...): \n\n ");

    double a = NAN, b = NAN, c = NAN;

    int res_of_read = read ( &a, &b, &c );

	  double x1 = NAN, x2 = NAN;

    int dataprint = check_input_solve_eq ( &a, &b, &c, &x1, &x2, res_of_read );

    print_result_solution ( dataprint, &x1, &x2 );

    if ( dataprint == not_readed ) restart( &a, &b, &c, &x1, &x2 );

    return 0;
}
