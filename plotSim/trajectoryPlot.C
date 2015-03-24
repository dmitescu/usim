#include<fstream>

void trajectoryPlot(){
	char tmp[20];
	cout << "Input data filename   :  ";
	cin >> tmp;
	const char * inFilename=tmp;
	ifstream fin(inFilename);
	if (fin.fail()){
		cout << "\nError opening file!\n";
		exit(-1);
	}
	else cout << "\n";
}
