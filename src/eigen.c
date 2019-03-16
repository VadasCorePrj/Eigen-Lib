#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

#define DMSGN(x) do {std::cout << x << std::endl;} while(0)
#define DMSG(x) do {std::cout << x << " ";} while(0)
#define repeat 50

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
	double ts1, ts2,sum_d=0,sum_f;
	
	if( MatA_row != MatB_col){
		DMSG("Invaild Matirx multiplication" <<endl);
		return 0;
	}
	
	//Matrix generation for random integer, range [-9, 9]
#if 1
  	MatrixXd Mata = (MatrixXd::Random(MatA_col,MatA_row))*10; 
	MatrixXi MatA = Mata.cast<int>();

 	MatrixXd Matb = (MatrixXd::Random(MatB_col,MatB_row))*10;  
 	MatrixXi MatB = Matb.cast<int>();
	MatrixXi Result; 
	MatrixXd Result_jin; 
	
	//for (int i=0;i<repeat;i++)
	//{
		ts1 = timestamp();
		Result= MatA*MatB; 
		ts2 = timestamp();
		//sum_d = sum_d+(ts2-ts1);
		DMSG("Eigen time of int : " << ts2-ts1 << endl);
	//}
	//sum_d = sum_d/repeat;
	//std::cout << MatA << endl << endl;
	//std::cout << MatB << endl << endl;

	
//	DMSG("Average Eigen time of int: " << sum_d << endl);
#endif
#if 1
  	//MatrixXd Mata_jin = (MatrixXd::Random((double)MatA_col,(double)MatA_row))*10; 
	//MatrixXd MatA_jin = Mata_jin.cast<double>();

 	//MatrixXd Matb_jin = (MatrixXd::Random((double)MatB_col,(double)MatB_row))*10;  
 	//MatrixXd MatB_jin = Matb_jin.cast<double>();
	
	//for (int i=0;i<repeat;i++){
		ts1 = timestamp();
		Result_jin= Mata*Matb;  
		ts2 = timestamp();
	//	sum_f=sum_f+(ts2-ts1);
	//}
	//sum_f/=repeat;
	DMSG("Eigen time of double: " << ts2-ts1 << endl);
	//DMSG("Averge Eigen time of double: " << sum_f << endl);
#endif
}
