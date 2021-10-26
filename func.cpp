#include "func.h"

int compare_double ( const double x, const double y )
{
	assert ( std::isfinite(x) );
    assert ( std::isfinite(y) );

    if (fabs(x - y)  <  EPSILON)  return equa1;

    if (x - y  >  EPSILON)        return frst_more_scnd;

    else                          return scnd_more_frst;  
}

int read ( double *adr_a, double *adr_b, double *adr_c )
{
    *adr_a = NAN;
    *adr_b = NAN;
    *adr_c = NAN;

    assert ( adr_a != NULL );
	assert ( adr_b != NULL );
	assert ( adr_c != NULL );

    int y = scanf( "%lg %lg %lg", adr_a, adr_b, adr_c );

    if ( y != 3 ) return not_readed;

    return readed;
}

int check_coef ( const double *a, const double *b, const double *c )
{
	assert ( a != NULL );
	assert ( b != NULL );
	assert ( c != NULL );

    if ( compare_double ( *a, 0) == equa1 &&  compare_double ( *b, 0) == equa1 && compare_double ( *c, 0) == equa1)
	{
		return many_roots;
	}
	if ( compare_double ( *a, 0) == equa1 &&  compare_double ( *b, 0) == equa1 && compare_double ( *c, 0) != equa1)
	{
		return no_root;
	}
	if ( compare_double ( *a, 0) == equa1 &&  compare_double ( *b, 0) != equa1 && compare_double ( *c, 0) != equa1)
	{
		return one_root;
	}
	if ( compare_double ( *a, 0) != equa1)
	{
		return a_no_0;
	}
}

double calc_discrim ( const double *a, const double *b, const double *c )
{
	assert ( a != NULL );
	assert ( b != NULL );
	assert ( c != NULL );

    double b_val = *b, a_val = *a, c_val = *c;

    double D = b_val*b_val - 4*a_val*c_val;   //((*b_val)*)

    if ( D == -0) D = 0;

    return D;
}

int check_discrim ( double D )
{
	assert ( std::isfinite(D) );

    if ( compare_double ( D, 0 ) == scnd_more_frst )    return D_less_0;

    if ( compare_double ( D, 0 ) == equa1)              return D_equal_0;

    if ( compare_double ( D, 0 ) == frst_more_scnd )    return two_roots;
}

int calc_roots ( const double *a, const double *b, const double *c, double *x1, double *x2 )
{
	assert ( a != NULL );
	assert ( b != NULL );
	assert ( c != NULL );
	assert ( x1 != NULL );
	assert ( x2 != NULL );

    double a_val = *a, b_val = *b;

    double D = calc_discrim(a, b, c);

    double chD = check_discrim(D);

    if ( chD == two_roots )
    {
        double sqD = sqrt( D );
        
        *x1 = (-b_val - sqD) / (2*a_val);

        *x2 = (-b_val + sqD) / (2*a_val);

        if ( compare_double ( *x2, -0 ) == equa1 ) *x2 = 0;

        if ( compare_double ( *x1, -0 ) == equa1 ) *x1 = 0;

        return two_roots;
    }
    if ( chD == D_equal_0 )
    {
        *x1 = -b_val / (2*a_val);
        
        if ( compare_double ( *x1, -0 ) == equa1 ) *x1 = 0;

        return D_equal_0;
    }
    else return D_less_0;
}

int check_input_solve_eq ( const double *a, const double *b, const double *c, double *x1, double *x2, int  res_of_read )
{
    assert ( a != NULL );
	assert ( b != NULL );
	assert ( c != NULL );
	assert ( x1 != NULL );
	assert ( x2 != NULL );

    if ( res_of_read == readed )
	{
        int res_of_check = check_coef( a, b, c );

        if (  res_of_check == a_no_0 ) return calc_roots ( a, b, c, x1, x2 );

        if ( res_of_check == one_root )
		{
				double b_val = *b, c_val = *c;

				*x1 = -c_val / b_val;

				if ( compare_double ( *x1, -0 ) == equa1 ) *x1 = 0;

				return one_root;
		}
        return res_of_check;
    }
    return not_readed;
}

int print_result_solution ( const int dataprint, const double *x1, const double *x2 )
{
	assert ( x1 != NULL );
	assert ( x2 != NULL );

	switch ( dataprint )
    {
        case many_roots:
        {        
            printf ("\njeto ne kvadrat urravnenie and this have many roots\n");       // many_roots,  no_root,  D_less_0,  D_equal_0, one_root,  two_roots,
            break;
        }
        case no_root:
        {             
            printf ("\njeto ne kvadrat urravnenie and this have not roots\n");
            break;    
        }
        case D_less_0: 
        {           
            printf ("\nno roots\n");
            break;
        }    
        case D_equal_0:  
        {       
            printf ("\nhave 1 root equal %lg (+ or - %lg) \n", *x1, EPSILON);
            break;        
        }
        case one_root:
        {           
            printf ("\njeto ne kvadrat urravnenie and this have a root equal %lg\n", *x1 );
            break;
        }
        case two_roots:
        { 
            printf ("\n   x1 = %lg (+/- %lg)    x2 = %lg (+/- %lg)\n", *x1, EPSILON, *x2, EPSILON );
            break;
        }
        case not_readed:
        {
            return 0;
            break;
        }
        default: 
        {
            printf ("\nsmth wrong with me\n");
        }
    }
	return 1;
}

int restart ( double *a, double *b, double *c, double *x1, double *x2 )
{
    printf ("\ni wanna chisla and u have 0ne chance left, try again\n\n");

    char i = 'i';
    while ( i = getchar() != '\n'){;}

    int res_of_read = read ( a, b, c );

	print_result_solution ( check_input_solve_eq ( a, b, c, x1, x2, res_of_read ), x1, x2 );

    return  1;
}

 //
 // TEST FUNCTIONs
 //

int print_wrong_in_i_test ( int number_test,  double true_x1, double true_x2, double x1, double x2 )
{
	switch ( number_test )
    {
        case 0:
        {
            printf ("wrong in test number %d, in this taste simulated situation of erroneous input\n", number_test);
            break;
        }
        case 1:
        {  
            printf ("wrong in test number %d, in this taste simulated situation of many roots\n", number_test);
            break;
        }    
        case 2:
        {
            printf ("wrong in test number %d, in this taste simulated situation of no roots\n", number_test);
            break;
        }
        case 3:
        {
            printf ("wrong in test number %d, in this taste simulated situation of one root\n", number_test);
            break;
        }
        case 4:
        {
            printf ("wrong in test number %d, in this taste simulated situation of two roots, x1 = %lg, x2= %lg, but function give x1 = %lg, x2 = %lg\n", number_test, true_x1, true_x2, x1, x2);
            break;
        }
        case 5:
        {
            printf ("wrong in test number %d, in this taste simulated situation of two roots, x1 = %lg, x2= %lg, but function give x1 = %lg, x2 = %lg\n", number_test, true_x1, true_x2, x1, x2);
            break;
        }
        case 6:
        {
            printf ("wrong in test number %d, in this taste simulated situation of two roots, x1 = %lg, x2= %lg, but function give x1 = %lg, x2 = %lg\n", number_test, true_x1, true_x2, x1, x2);
            break;
        }
        case 7:
        {
            printf ("wrong in test number %d, in this taste simulated situation of one root, which equal %lg, but function give %lg or more solutions\n", number_test, true_x1, x1);
            break;
        }
        default:
        {
            printf ("smth wrong with test");
        }
    }
    return 1;
}

int compare_true_with_calc ( int res_of_solve, int true_res_of_solve, double root_x1, double root_x2, double true_root_x1, double true_root_x2 )
{
	if ( res_of_solve != true_res_of_solve )                                   return 0;

    else 
    {   if ( true_res_of_solve != many_roots && true_res_of_solve != not_readed && true_res_of_solve != no_root )
        {
            assert ( std::isfinite(root_x1));
            assert ( std::isfinite(true_root_x1));
            if ( compare_double ( root_x1, true_root_x1 ) != equa1 )           return 0;
        }
	    if ( true_res_of_solve == two_roots )
        {
            assert ( std::isfinite(root_x2));
            assert ( std::isfinite(true_root_x2));
            if ( compare_double ( root_x2, true_root_x2 ) != equa1 )           return 0;
        }
    }
	return 1;
}

int iteration_check ( int* res_of_read , int* true_res_of_solve  ,  double coef_a [ ], double coef_b [ ], double coef_c [ ], double true_root_x1 [ ], double true_root_x2 [ ] )
{
	assert ( res_of_read != NULL );
	assert ( true_res_of_solve != NULL );
	assert ( coef_a != NULL );
	assert ( coef_b != NULL );
	assert ( coef_c != NULL );
	assert ( true_root_x1 != NULL );
	assert ( true_root_x2 != NULL );

	double x1 = 0, x2 = 0;

	for ( int i = 0; i < 8 ; ++i ){

		double a = coef_a [ i ], b =   coef_b [ i ], c =  coef_c [ i ];
		int result_of_read = res_of_read [ i ];

		int res_of_solve = check_input_solve_eq ( &a, &b, &c, &x1, &x2, result_of_read );

		if ( compare_true_with_calc ( res_of_solve, true_res_of_solve [ i ], x1, x2, true_root_x1 [ i ], true_root_x2 [ i ] ) == 0 )
		{ 
			print_wrong_in_i_test ( i, true_root_x1 [ i ], true_root_x2 [ i ], x1, x2 );
		}
		x1 = 0, x2 = 0;
	}
	return 1;
}

int TEST()
{
   int res_of_read  [ 8 ]   =  { not_readed, readed, readed, readed, readed, readed, readed, readed };
   double coef_a    [ 8 ]   =  { 0, 0, 0,  0,   1,        1,    1, 1 };
   double coef_b    [ 8 ]   =  { 0, 0, 0,  2,   0,        0,   -5, 2 };
   double coef_c    [ 8 ]   =  { 0, 0, 1, -1, -9, -10*EPSILON,  4, 1 };

   int true_res_of_solve [ 8 ]   =  { not_readed, many_roots, no_root, one_root, two_roots, two_roots, two_roots, D_equal_0 };
   double true_root_x1   [ 8 ]   =  { NAN, NAN, NAN, 0.50, -3.0, -sqrt(10*EPSILON), 1,-1 };
   double true_root_x2   [ 8 ]   =  { NAN, NAN, NAN, NAN,  3.0,   sqrt(10*EPSILON), 4 , NAN};

	iteration_check ( res_of_read, true_res_of_solve, coef_a, coef_b, coef_c, true_root_x1, true_root_x2 );

   return 1;
}
