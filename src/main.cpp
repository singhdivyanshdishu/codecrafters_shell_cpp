#include <iostream>
#include <string>
using namespace std;
int main() {

  cout << unitbuf;
  cerr << unitbuf;

  // TODO: Uncomment the code below to pass the first stage

  while(true){
  cout << "$ ";
  string str;
  cin>>str;
  cout<<str<<": command not found"<<endl;
  if(str=="exit") break;
}
}
