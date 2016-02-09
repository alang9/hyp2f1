/*							mconf.h
 *
 *	Common include file for math routines
 *
 *
 *
 * SYNOPSIS:
 *
 * #include "mconf.h"
 *
 *
 *
 * DESCRIPTION:
 *
 * This file contains definitions for error codes that are
 * passed to the common error handling routine mtherr()
 * (which see).
 *
 * The file also includes a conditional assembly definition
 * for the type of computer arithmetic (IEEE, DEC, Motorola
 * IEEE, or UNKnown).
 * 
 * For Digital Equipment PDP-11 and VAX computers, certain
 * IBM systems, and others that use numbers with a 56-bit
 * significand, the symbol DEC should be defined.  In this
 * mode, most floating point constants are given as arrays
 * of octal integers to eliminate decimal to binary conversion
 * errors that might be introduced by the compiler.
 *
 * For little-endian computers, such as IBM PC, that follow the
 * IEEE Standard for Binary Floating Point Arithmetic (ANSI/IEEE
 * Std 754-1985), the symbol IBMPC should be defined.  These
 * numbers have 53-bit significands.  In this mode, constants
 * are provided as arrays of hexadecimal 16 bit integers.
 *
 * Big-endian IEEE format is denoted MIEEE.  On some RISC
 * systems such as Sun SPARC, double precision constants
 * must be stored on 8-byte address boundaries.  Since integer
 * arrays may be aligned differently, the MIEEE configuration
 * may fail on such machines.
 *
 * To accommodate other types of computer arithmetic, all
 * constants are also provided in a normal decimal radix
 * which one can hope are correctly converted to a suitable
 * format by the available C language compiler.  To invoke
 * this mode, define the symbol UNK.
 *
 * An important difference among these modes is a predefined
 * set of machine arithmetic constants for each.  The numbers
 * MACHEP (the machine roundoff error), MAXNUM (largest number
 * represented), and several other parameters are preset by
 * the configuration symbol.  Check the file const.c to
 * ensure that these values are correct for your computer.
 *
 * Configurations NANS, INFINITIES, MINUSZERO, and DENORMAL
 * may fail on many systems.  Verify that they are supposed
 * to work on your computer.
 */
/*
Cephes Math Library Release 2.3:  June, 1995
Copyright 1984, 1987, 1989, 1995 by Stephen L. Moshier
*/


/* Define if the `long double' type works.  */
#define HAVE_LONG_DOUBLE 1

/* Define as the return type of signal handlers (int or void).  */
#define RETSIGTYPE void

/* Define if you have the ANSI C header files.  */
#define STDC_HEADERS 1

/* Define if your processor stores words with the most significant
   byte first (like Motorola and SPARC, unlike Intel and VAX).  */
/* #undef WORDS_BIGENDIAN */

/* Define if floating point words are bigendian.  */
/* #undef FLOAT_WORDS_BIGENDIAN */

/* The number of bytes in a int.  */
#define SIZEOF_INT 4

/* Define if you have the <string.h> header file.  */
#define HAVE_STRING_H 1

/* Name of package */
#define PACKAGE "cephes"

/* Version number of package */
#define VERSION "2.7"

/* Constant definitions for math error conditions
 */

#define DOMAIN		1	/* argument domain error */
#define SING		2	/* argument singularity */
#define OVERFLOW	3	/* overflow range error */
#define UNDERFLOW	4	/* underflow range error */
#define TLOSS		5	/* total loss of precision */
#define PLOSS		6	/* partial loss of precision */

#define EDOM		33
#define ERANGE		34
/* Complex numeral.  */
typedef struct
	{
	double r;
	double i;
	} cmplx;

#ifdef HAVE_LONG_DOUBLE
/* Long double complex numeral.  */
typedef struct
	{
	long double r;
	long double i;
	} cmplxl;
#endif


/* Type of computer arithmetic */

/* PDP-11, Pro350, VAX:
 */
/* #define DEC 1 */

/* Intel IEEE, low order words come first:
 */
/* #define IBMPC 1 */

/* Motorola IEEE, high order words come first
 * (Sun 680x0 workstation):
 */
/* #define MIEEE 1 */

/* UNKnown arithmetic, invokes coefficients given in
 * normal decimal format.  Beware of range boundary
 * problems (MACHEP, MAXLOG, etc. in const.c) and
 * roundoff problems in pow.c:
 * (Sun SPARCstation)
 */
#define UNK 1

/* If you define UNK, then be sure to set BIGENDIAN properly. */
#ifdef FLOAT_WORDS_BIGENDIAN
#define BIGENDIAN 1
#else
#define BIGENDIAN 0
#endif
/* Define this `volatile' if your compiler thinks
 * that floating point arithmetic obeys the associative
 * and distributive laws.  It will defeat some optimizations
 * (but probably not enough of them).
 *
 * #define VOLATILE volatile
 */
#define VOLATILE

/* For 12-byte long doubles on an i386, pad a 16-bit short 0
 * to the end of real constants initialized by integer arrays.
 *
 * #define XPD 0,
 *
 * Otherwise, the type is 10 bytes long and XPD should be
 * defined blank (e.g., Microsoft C).
 *
 * #define XPD
 */
#define XPD 0,

/* Define to support tiny denormal numbers, else undefine. */
#define DENORMAL 1

/* Define to ask for infinity support, else undefine. */
#define INFINITIES 1

/* Define to ask for support of numbers that are Not-a-Number,
   else undefine.  This may automatically define INFINITIES in some files. */
#define NANS 1

/* Define to distinguish between -0.0 and +0.0.  */
#define MINUSZERO 1

/* Define 1 for ANSI C atan2() function
   See atan.c and clog.c. */
#define ANSIC 1

/* Get ANSI function prototypes, if you want them. */
#if 1
/* #ifdef __STDC__ */
#define ANSIPROT 1
int mtherr ( char *, int );
#else
int mtherr();
#endif

/* Variable for error reporting.  See mtherr.c.  */
extern int merror;

#define NPY_E         2.718281828459045235360287471352662498  /* e */
#define NPY_LOG2E     1.442695040888963407359924681001892137  /* log_2 e */
#define NPY_LOG10E    0.434294481903251827651128918916605082  /* log_10 e */
#define NPY_LOGE2     0.693147180559945309417232121458176568  /* log_e 2 */
#define NPY_LOGE10    2.302585092994045684017991454684364208  /* log_e 10 */
#define NPY_PI        3.141592653589793238462643383279502884  /* pi */
#define NPY_PI_2      1.570796326794896619231321691639751442  /* pi/2 */
#define NPY_PI_4      0.785398163397448309615660845819875721  /* pi/4 */
#define NPY_1_PI      0.318309886183790671537767526745028724  /* 1/pi */
#define NPY_2_PI      0.636619772367581343075535053490057448  /* 2/pi */
#define NPY_EULER     0.577215664901532860606512090082402431  /* Euler constant */
#define NPY_SQRT2     1.414213562373095048801688724209698079  /* sqrt(2) */
#define NPY_SQRT1_2   0.707106781186547524400844362104849039  /* 1/sqrt(2) */
#define NPY_NAN (sqrt(-1))
#define NPY_INFINITY 1.79769313486231570815E308 // (1/0)
#define TOOMANY 7
#define DOMAIN		1	/* argument domain error */
#define SING		2	/* argument singularity */
#define OVERFLOW	3	/* overflow range error */
#define UNDERFLOW	4	/* underflow range error */
#define TLOSS		5	/* total loss of precision */
#define PLOSS		6	/* partial loss of precision */
#define TOOMANY         7	/* too many iterations */
#define MAXITER        500

#define EDOM		33
#define ERANGE		34

#include <assert.h>
extern double lgam_sgn(double x, int *sign);
