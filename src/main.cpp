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
  getline(cin,str);
  if(str=="exit") break;
  else if(str.substr(0,4)=="echo") {
    cout << str.substr(5)<<endl;
  }
  else if(str.substr(0,4)=="type"){
    if(str.substr(5,9)=="echo"||str.substr(5,9)=="exit"||str.substr(5,9)=="type") cout << str.substr(5,9) << " is a shell builtin" << endl;
    else cout << str.substr(5) << ": not found" << endl;
  }
  else cout<<str<<": command not found"<<endl;

}
}
