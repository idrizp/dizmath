#include "cpx.h";
#include "math.h";

struct complex complex_create(double re, double im) {
    struct complex cpx;
    cpx.re = re;
    cpx.im = im;
    return cpx;
}


void complex_add(struct complex *a, struct complex b) {
    a->im = a->im + b.im;
    a->re = a->re + b.re;
}

void complex_sub(struct complex *a, struct complex b) {
    a->im = a->im - b.im;
    a->re = a->re - b.re;
}

void complex_conj(struct complex* a) {
    a->im = -a->im; 
}

void complex_mul(struct complex *a, struct complex b) {
    double re = (a->re * b.re) - (a->im * b.im);
    double im = (a->re * b.im) + (a->im * b.re);
}

void complex_div(struct complex *a, struct complex b) {
    // By smith's method
    double a_re = a->re;
    double a_im = a->im;

    double b_re = b.re;
    double b_im = b.im;

    double r, d;
    if (fabs(b_re) >= fabs(b_im)) {
        r = b_im / b_re;
        d = b_re + r * b_im;

        a->re = a_re + r * (a_im);
        a->im = (a_im - r * a_re) / d;
        return;
    }

    r = b_re / b_im;
    d = b_im + r * b_re;
    a->re = ((r * a_re + a_im));
    a->im = (r * a_im - a_re) / d;
}

struct complex complex_pol2rec(double r, double theta) {
    double re = r * cos(theta);
    double im = r * sin(theta);
    return complex_create(re, im);
}

struct complex complex_exp(double theta) {
    return complex_create(cos(theta), sin(theta));
}