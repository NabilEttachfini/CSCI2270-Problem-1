#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
    cout<<"# of arguments: "<<argc<< endl;
    cout<<" the second argument is: " << argv[1] <<endl;
    int arg=atoi (argv[1]);
    cout<< "the second argument plus 2 is:" << arg + 2<<endl;
    cout << "Hello C++" << endl;
    return 0;
}
