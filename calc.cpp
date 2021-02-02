
#include <stdio.h>
#include <iostream>
#include <cstdlib>
using namespace std;
int main(){
cout << "Calc++\na program made by 1ctinus\n";
while (true){
int testInteger;
int oops;
char what;
cout << "Do some maths and stuff: ";
cin >> testInteger;
cin >> what;
cin >> oops;
cout << "Number = ";
switch (what) {
case 'a':case '+':
cout<< testInteger+oops;
break;case 'm':case '*':
cout <<testInteger*oops;
break;case 's':case '-':
cout <<testInteger-oops;
break;case 'd':case '/':
float div = (float)testInteger/(float)oops;
cout << div;
break;"That don't work lol";
}
cout << "\n";
}
return 0;
}
