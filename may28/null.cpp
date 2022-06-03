#include <iostream>
using namespace std;
int fun (int *p); //prototype

int main (void)
{
	int *p = 0; /*null pointer*/
	return fun (p);
}
int fun (int *p)
{
	int y = *p;
	return y;
}
