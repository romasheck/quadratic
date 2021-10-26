#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED    

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>


const double EPSILON   =   10e-6 ;

enum for_compare_doubles
{
	 equa1,
	 frst_more_scnd,
	 scnd_more_frst
};

enum midle_and_output_data
{
	readed,
	not_readed,
	D_less_0,
	D_equal_0,
	two_roots,
	many_roots,
	no_root,
	one_root,
	a_no_0
};

/** \brief  test for correct working function check_input_solve_eq
 *
 * \return  1
 */
int TEST();

/** \brief  compare calculated value, result of solution function with true roots and results
 *
 * \param   res_of_solve - flag about result of solution
 * \param   true_res_of_solve - true flag about priviosly
 * \param   root_x1 - value of frst root
 * \param   root_x2 - value of scnd root
 * \param   true_root_x1 - true value of frst root
 * \param   true_root_x2 - true value of scnd root
 * \return  0 if smth wrong, 1in other
 */
int compare_true_with_calc ( int res_of_solve, int true_res_of_solve, double root_x1, double root_x2, double true_root_x1, double true_root_x2 );

/** \brief   print in which test wrong, roots and true roots
 *
 * \param   i - number of wrong test
 * \param   true_x1 - true value of frst root
 * \param   true_x2 - true value of scnd root
 * \param    x1 - calculated value of frst root
 * \param    x2 - calculated value of scnd root
 * \return     1
 */
int print_wrong_in_i_test ( int i, double true_x1, double true_x2, double x1, double x2 );

/** \brief   restart  program only one time, if acquired information was wrong (no number)
 *
 * \param *a - quadratic coefficient
 * \param *b - linear coefficient
 * \param *c - free term
 * \param *x1 - first solution
 * \param *x2 - second solution
 * \return   1
 */
int restart ( double *a, double *b, double *c, double *x1, double *x2 );

/** \brief print solutions of eduation
 *
 * \param dataprint - result of read and number of solutions
 * \param *x1 - first solution
 * \param *x2 - second solution
 * \return 1
 */
int print_result_solution ( const int dataprint, const double *x1, const double *x2 );

/** \brief check  solve quadratic or linear equation
 *
 * \param *a - quadratic coefficient
 * \param *b - linear coefficient
 * \param *c - free term
 * \param *x1 - first solution
 * \param *x2 - second solution
 * \param *res_of_read - result of reading input data
 * \return  differnt const
 */
int check_input_solve_eq ( const double *a, const double *b, const double *c, double *x1, double *x2, int res_of_read );

/** \brief  calculted roots
 *
 * \param *a - quadratic coefficient
 * \param *b - linear coefficient
 * \param *c - free term
 * \param  *x1 - frst root
 * \param  *x2 - scnd root
 * \return    D_les_0, D_equal_0, two_roots -  const about number of roots
 */
int calc_roots ( const double *a, const double *b, const double *c, double *x1, double *x2 );

/** \brief   check sign D
 *
 * \param  D - value of discrim
 * \return   D_less_0, D_eqaul_0, many_roots
 */
int check_diskrim (double D);

/** \brief  calculated value of discrim
 *
 * \param *a - quadratic coefficient
 * \param *b - linear coefficient
 * \param *c - free term
 * \return   value of discrim
 */
double check_discrim (const double *a, const double *b, const double *c);

/** \brief   calculated number of roots
 *
 * \param *a - quadratic coefficient
 * \param *b - linear coefficient
 * \param *c - free term
 * \return     many_roots, no_root, one_root, a_no_0
 */
int check_coef ( const double *a, const double *b, const double *c );

/** \brief   read coifficients
 *
 * \param   *adr_a - quadratic coefficient
 * \param   *adr_b - linear coefficients
 * \param   *adr_c - free term
 * \return   readed or not_readed
 */
int read ( double *adr_a, double *adr_b, double *adr_c );

/** \brief  in cycle check correct from work solution function
 *
 * \param   which_wrong [ ] - massif numbers of wrong test
 * \param   res_of_read [ ]  -   massif of results of read
 * \param   true_res_of_solve [ ] - massif of true result  of solution
 * \param   coef_a [ ] - massif of quadratic coefficients
 * \param   coef_b [ ] - massif of linear coefs
 * \param  coef_c [ ] - massif of free terns
 * \param  true_root_x1 [ ] - frst massif of true roots
 * \param  true_root_x2 [ ] - scnd massif of true roots
 * \return  1
 */
int iteration_check ( int which_wrong [ ], int res_of_read [ ], int true_res_of_solve [ ],  double coef_a [ ], double coef_b [ ], double coef_c [ ], double true_root_x1 [ ], double true_root_x2 [ ] );

/** \brief find the largest number of two
 *
 * \param x - first number to compare
 * \param y - second number to compare
 * \return const about comapatoin of x and y
 */
int compare_double ( const double x, const double y );

/** \brief  print wrong in which test solution false
 *
 * \param  i -  number of wrong test
 * \param  true_x1 - true frst root of quadro
 * \param  true_x2 - true scnd root of quadro
 * \param  x1 - frst calculeted rot of quadro
 * \param x2 - scnd calculated root of quadro
 * \return  1
 */
int print_wrong_in_i_test ( int i, double true_x1, double true_x2, double x1, double x2 );

#endif
