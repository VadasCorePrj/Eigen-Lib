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

void fillRandMat(MatrixXi* mat, int row, int col, int range)
{
	for(int y = 0; y < row; y++)
	{
		for(int x = 0; x < col; x++)
		{
			(*mat)(y,x) %= range;
		}
	}
}

void fillRandVector(VectorXi* vec, int row)
{
	srand(time(NULL));

	for(int y = 0; y < row; y++)
	{
		(*vec)(y) = (int)((float)rand() / (float)RAND_MAX * 20) - 10;
	}
}

/*
 * A x B => C
 * $ nice -2 ./eigen_int [A's row] [B's row] [C's col]
 */
int main(int argc, char * argv[]){

	//Define Matrix Size.
	int N = atoi(argv[1]);
	int K = atoi(argv[2]);
	int M = atoi(argv[3]);
	double ts1, ts2;
	
  	MatrixXi src0 = (MatrixXi::Random(N,K));
	//Matrix generation for random int, range [-10, 10]
	fillRandMat(&src0, N, K, 10);
	MatrixXi dst(N, M); 

	VectorXi src1(K);
	fillRandVector(&src1, K);
	
	ts1 = timestamp();
	dst= src0*src1; 
	ts2 = timestamp();

	DMSGN("Eigen time of int : " << ts2-ts1);
}
