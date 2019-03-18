#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

#define DMSGN(x) do {std::cout << x << std::endl;} while(0)
#define DMSG(x) do {std::cout << x << " ";} while(0)

static inline double timestamp()
{
	struct timespec ts;

	clock_gettime(CLOCK_MONOTONIC, &ts);

	return (ts.tv_sec + ts.tv_nsec * 1e-9) * 1000;
}

void fillRandVector(VectorXf* vec, int row)
{
	srand(time(NULL));

	for(int y = 0; y < row; y++)
	{
		(*vec)(y) = (float)rand() / (float)RAND_MAX * 2 - 1.0f;
	}
}

/*
 * A x B => C
 * $ nice -n -2 ./eigen_int [A's row] [B's row] [C's col]
 */
int main(int argc, char * argv[]){

	//Define Matrix Size.
	int N = atoi(argv[1]);
	int K = atoi(argv[2]);
	int M = atoi(argv[3]);
	double ts1, ts2;
	
	//Matrix generation for random float, range [-1, 1]
  	MatrixXf src0 = (MatrixXf::Random(N,K))*1; 
	MatrixXf dst(N, M); 

	VectorXf src1(K);
	fillRandVector(&src1, K);
	
	ts1 = timestamp();
	dst= src0*src1; 
	ts2 = timestamp();

	DMSGN("Eigen time of float : " << ts2-ts1);
}
