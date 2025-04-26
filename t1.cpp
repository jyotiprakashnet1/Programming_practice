#include<iostream>
#include<crypto++/osrng.h>
#include<crypto++/nbtheory.h>
#include<crypto++/integer.h>
#include<crypto++/files.h>

using namespace CryptoPP;
using namespace std;

void keygen(){
	AutoSeededRandomPool rng;
	PrimeAndGenerator pg;

	pg.Generate(1, rng, 3, 3);

	Integer p = pg.GetModulus()/*pg.Prime()*/;
	Integer q = pg.Prime();

	cout<< p <<endl;



}

int main(){

	keygen();
	return 0;
}
