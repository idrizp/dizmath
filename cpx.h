#ifndef CPX_H

#define CPX_H

struct complex 
{
    double re;
    double im;
};
 
/**
 * Creates a complex number.
 * @param re The real part.
 * @param im The imaginary part.
 */
struct complex complex_create(double re, double im);

/**
 * Adds two complex numbers.
 * @param a The complex number that gets the result.
 * @param b The complex number that we want to add to a.
 */
void complex_add(struct complex *a, struct complex b);

/**
 * Subtracts two complex numbers.
 * @param a The complex number that gets the result.
 * @param b The complex number that we want to subtract from a.
 */
void complex_sub(struct complex *a, struct complex b);

/**
 * Conjugates a complex number.
 * @param c The complex number we want to conjugate.
 */
void complex_conj(struct complex *c);

/**
 * Multiplies two complex numbers.
 * @param a The complex number that gets the result.
 * @param b The complex number that we want to add to a.
 */
void complex_mul(struct complex *a, struct complex b);

/**
 * Divides two complex numbers.
 * @param a The complex number that gets the result.
 * @param b The complex number that we want to add to a.
 */
void complex_div(struct complex *a, struct complex b);

/**
 * Creates a complex number from a polar one.
 * @param r The radius.
 * @param theta The angle.
 */
struct complex complex_pol2rec(double r, double theta);

/**
 * Creates a complex exponential with angle theta.
 * @param theta The angle of the complex exponential.
 */
struct complex complex_exp(double theta);
#endif