#include <iostream>
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


int main(int argc, char * argv[]){

	//Define Matrix Size.
	int MatA_col = atoi(argv[1]);
	int MatA_row = atoi(argv[2]);

	int MatB_col = atoi(argv[3]);
	int MatB_row = atoi(argv[4]);
	
	if( MatA_row != MatB_col){
		DMSG("Invaild Matirx multiplication" <<endl);
		return 0;
	}
	
	//Matrix generation for random integer, range [-9, 9]
  	MatrixXd Mata = (MatrixXd::Random(MatA_col,MatA_row))*10; 
	MatrixXi MatA = Mata.cast<int>();

 	MatrixXd Matb = (MatrixXd::Random(MatB_col,MatB_row))*10;  
 	MatrixXi MatB = Matb.cast<int>();

	double ts1 = timestamp();
	MatrixXi Result= MatA*MatB; 
	double ts2 = timestamp();

	//std::cout << MatA << endl << endl;
	//std::cout << MatB << endl << endl;

	DMSG("Eigen time: " << ts2-ts1 << endl);

}
