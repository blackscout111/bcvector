#include <iostream>
#include <string>
#include "bcvector.h"

using namespace std;

int main()
{
	bcvector <int>		intvecA,
				 		intvecB;

	bcvector <string>	strvec;

	cout << "invecA:" << endl;
	intvecA.print();
	cout << endl;

	cout << "invecB:" << endl;
	intvecB.print();
	cout << endl;

	cout << "strvec:" << endl;
	strvec.print();
	cout	<< "empty= " << strvec.empty() << endl
			<< "full= " << strvec.full() << endl << endl;

	unsigned int loopSize = 0xffff;

	for (unsigned int i = 0; i < loopSize; i++)
	{
		intvecA.append(i*2);
	}

	cout << "intvecA:" << endl;
	intvecA.print((intvecA.size() - 1), (intvecA.size() - 1));
	cout << endl;

	intvecB.makeConservative();
	for (unsigned int i = 0; i < loopSize; i++)
	{
		intvecB.append(i);
	}

	cout << "intvecB:" << endl;
	intvecB.print((intvecB.size() - 1), (intvecB.size() - 1));
	cout << endl;

	strvec.append("Wanna hear something funny?");
	strvec.append("penis");
	strvec.append("awesome");
	strvec.append("totally");

	cout << "strvec:" << endl;
	strvec.print(0, (strvec.size() - 1));
	cout << endl;

	cout	<< "empty= " << strvec.empty() << endl
			<< "full= " << strvec.full() << endl << endl;

	bcvector <string> copystrvec(strvec);

	cout << "copystrvec:" << endl;
	copystrvec.print(0, (copystrvec.size() - 1));
	cout << endl;

	copystrvec.rip();

	cout << "copystrvec:" << endl;
	copystrvec.print(0, (copystrvec.size() - 1));
	cout << endl;

	cout	<< "empty= " << copystrvec.empty() << endl
			<< "full= " << copystrvec.full() << endl << endl;


	cout << "Press ENTER to continue...";

	cin.get();

	return 0;
}
