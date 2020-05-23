/* If we enable C++11 at some time, the following defines may be replaced
 * by the following code:
constexpr unsigned numberOfBasisFunctions(unsigned O) {
  return O * (O + 1) * (O + 2) / 6;
}

constexpr unsigned numberOfAlignedBasisFunctions(unsigned O) {
  return (numberOfBasisFunctions(O) * sizeof(real) + (ALIGNMENT - (numberOfBasisFunctions(O) * sizeof(real)) % ALIGNMENT) % ALIGNMENT) / sizeof(real);
}

constexpr unsigned numberOfAlignedDerBasisFunctions(unsigned O) {
  return (O > 0) ? numberOfAlignedBasisFunctions(O) + numberOfAlignedDerBasisFunctions(O-1) : 0;
}

#define NUMBER_OF_ALIGNED_BASIS_FUNCTIONS numberOfAlignedBasisFunctions(CONVERGENCE_ORDER)
#define NUMBER_OF_ALIGNED_DER_BASIS_FUNCTIONS numberOfAlignedDerBasisFunctions(CONVERGENCE_ORDER)
 
*/
#if 0
! aligned number of basis functions
#endif

#if ALIGNMENT == 16 && defined(DOUBLE_PRECISION)

#if CONVERGENCE_ORDER == 2
#define NUMBER_OF_ALIGNED_BASIS_FUNCTIONS 4
#elif CONVERGENCE_ORDER == 3
#define NUMBER_OF_ALIGNED_BASIS_FUNCTIONS 10
#elif CONVERGENCE_ORDER == 4
#define NUMBER_OF_ALIGNED_BASIS_FUNCTIONS 20
#elif CONVERGENCE_ORDER == 5
#define NUMBER_OF_ALIGNED_BASIS_FUNCTIONS 36
#elif CONVERGENCE_ORDER == 6
#define NUMBER_OF_ALIGNED_BASIS_FUNCTIONS 56
#elif CONVERGENCE_ORDER == 7
#define NUMBER_OF_ALIGNED_BASIS_FUNCTIONS 84
#elif CONVERGENCE_ORDER == 8
#define NUMBER_OF_ALIGNED_BASIS_FUNCTIONS 120
#endif

#elif ( ALIGNMENT == 32 && defined(DOUBLE_PRECISION) ) || ( ALIGNMENT == 16 && defined(SINGLE_PRECISION) )

#if CONVERGENCE_ORDER == 2
#define NUMBER_OF_ALIGNED_BASIS_FUNCTIONS 4
#elif CONVERGENCE_ORDER == 3
#define NUMBER_OF_ALIGNED_BASIS_FUNCTIONS 12
#elif CONVERGENCE_ORDER == 4
#define NUMBER_OF_ALIGNED_BASIS_FUNCTIONS 20
#elif CONVERGENCE_ORDER == 5
#define NUMBER_OF_ALIGNED_BASIS_FUNCTIONS 36
#elif CONVERGENCE_ORDER == 6
#define NUMBER_OF_ALIGNED_BASIS_FUNCTIONS 56
#elif CONVERGENCE_ORDER == 7
#define NUMBER_OF_ALIGNED_BASIS_FUNCTIONS 84
#elif CONVERGENCE_ORDER == 8
#define NUMBER_OF_ALIGNED_BASIS_FUNCTIONS 120
#endif

#elif (( ALIGNMENT == 64 && defined(DOUBLE_PRECISION) ) || ( ALIGNMENT == 32 && defined(SINGLE_PRECISION) ) && !(defined(ACL_DEVICE)))

#if CONVERGENCE_ORDER == 2
#define NUMBER_OF_ALIGNED_BASIS_FUNCTIONS 8
#elif CONVERGENCE_ORDER == 3
#define NUMBER_OF_ALIGNED_BASIS_FUNCTIONS 16
#elif CONVERGENCE_ORDER == 4
#define NUMBER_OF_ALIGNED_BASIS_FUNCTIONS 24
#elif CONVERGENCE_ORDER == 5
#define NUMBER_OF_ALIGNED_BASIS_FUNCTIONS 40
#elif CONVERGENCE_ORDER == 6
#define NUMBER_OF_ALIGNED_BASIS_FUNCTIONS 56
#elif CONVERGENCE_ORDER == 7
#define NUMBER_OF_ALIGNED_BASIS_FUNCTIONS 88
#elif CONVERGENCE_ORDER == 8
#define NUMBER_OF_ALIGNED_BASIS_FUNCTIONS 120
#endif

#elif ALIGNMENT == 64 && (defined(SINGLE_PRECISION) || defined(ACL_DEVICE))

#if CONVERGENCE_ORDER == 2
#define NUMBER_OF_ALIGNED_BASIS_FUNCTIONS 16
#elif CONVERGENCE_ORDER == 3
#define NUMBER_OF_ALIGNED_BASIS_FUNCTIONS 16
#elif CONVERGENCE_ORDER == 4
#define NUMBER_OF_ALIGNED_BASIS_FUNCTIONS 32
#elif CONVERGENCE_ORDER == 5
#define NUMBER_OF_ALIGNED_BASIS_FUNCTIONS 48
#elif CONVERGENCE_ORDER == 6
#define NUMBER_OF_ALIGNED_BASIS_FUNCTIONS 64
#elif CONVERGENCE_ORDER == 7
#define NUMBER_OF_ALIGNED_BASIS_FUNCTIONS 96
#elif CONVERGENCE_ORDER == 8
#define NUMBER_OF_ALIGNED_BASIS_FUNCTIONS 128
#endif

#else

#error alignment-precision combination not implemented.

#endif

#define NUMBER_OF_ALIGNED_STRESS_DOFS   (NUMBER_OF_ALIGNED_BASIS_FUNCTIONS     * 6)
