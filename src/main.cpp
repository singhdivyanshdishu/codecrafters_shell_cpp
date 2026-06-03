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
  else if(str.substr(0,5)=="echo") {
    cout << str.substr(5)<<endl;
  }
  else cout<<str<<": command not found"<<endl;

}
}
