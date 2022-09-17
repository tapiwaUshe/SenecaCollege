// Name: Tapi Z. Ushe
// Class: OOP244
// Assignment Project: Milestone 5
#include "AmaProduct.h"
#include "AmaPerishable.h"
using namespace sict;
using namespace std;
void piv(const char* sku, const char* name, const char* unit = "", char Tx = '\0',
  const char* price = "", const char* qty = "", const char* qtyNd = "",
  const char* date = "");
void dumpFile(const char* fname);
void _pause();
void m1();
void m2();
int main(){
  m1();
  m2();
  return 0;
}

void m1(){
  fstream prdfile("amaPrd.txt", ios::out);
  AmaProduct amaPrd;
  bool ok = true;
  cout << "--AmaProduct test:" << endl;
  cout << "----Taxed validation test:" << endl;
  piv("abc", "abc", "abc", 'a');
  cin >> amaPrd;
  if (cin.fail()){
    cin.clear();
    cin.ignore(2000, '\n');
    cout << "Passed!" << endl
      << "Message shoule be:  Only (Y)es or (N)o are acceptable" << endl
      << "Your Error message: " << amaPrd << endl;
  }
  else{
    ok = false;
    cout << "Taxed validation failed" << endl;
  }
  _pause();
  if (ok){
    cout << "----Price validation test:" << endl;
    piv("abc", "abc", "abc", 'y', "abc");
    cin >> amaPrd;
    if (cin.fail()){
      cin.clear();
      cin.ignore(2000, '\n');
      cout << "Passed!" << endl
        << "Message shoule be:  Invalid Price Entry" << endl
        << "Your Error message: " << amaPrd << endl;
    }
    else{
      ok = false;
      cout << "Price validation failed" << endl;
    }
    _pause();
  }
  if (ok){
    cout << "----Quantity validation test:" << endl;
    piv("abc", "abc", "abc", 'y', "10", "abc");
    cin >> amaPrd;
    if (cin.fail()){
      cin.clear();
      cin.ignore(2000, '\n');
      cout << "Passed!" << endl
        << "Message shoule be:  Invalid Quantity Entry" << endl
        << "Your Error message: " << amaPrd << endl;
    }
    else{
      ok = false;
      cout << "Quantity validaton failed" << endl;
    }
  }
  _pause();
  if (ok){
    cout << "----Quantity Needed validation test:" << endl;
    piv("abc", "abc", "abc", 'y', "10", "10", "abc");
    cin >> amaPrd;
    if (cin.fail()){
      cin.clear();
      cin.ignore(2000, '\n');
      cout << "Passed!" << endl
        << "Message shoule be:  Invalid Quantity Needed Entry" << endl
        << "Your Error message: " << amaPrd << endl;
    }
    else{
      ok = false;
      cout << "Quantity Needed validaton failed" << endl;
    }
  }
  _pause();
  if (ok){
    cout << "----Display test, the output of the Program and yours must match:" << endl;
    piv("1234", "box", "kg", 'y', "123.45", "1", "5");
    cin >> amaPrd;
    cin.ignore(1000, '\n');
    cout << "--Linear------------" << endl;
    cout << "Program: 1234   |box                 | 139.50|   1|kg        |   5|" << endl;
    cout << "  Yours: " << amaPrd << endl;
    cout << "--Form Display------" << endl;
    cout << "--Program: " << endl;
    cout << "Sku: 1234" << endl;
    cout << "Name : box" << endl;
    cout << "Price : 123.45" << endl;
    cout << "Price after tax : 139.50" << endl;
    cout << "Quantity On Hand : 1 kgs" << endl;
    cout << "Quantity Needed : 5" << endl;
    cout << "--Yours: " << endl;
    amaPrd.write(cout, false) << endl;
  }
  _pause();
  if (ok){
    cout << "----Storage and loading test, the output of the Program and yours must match:" << endl;
    AmaProduct tprd;
    amaPrd.store(prdfile);
    amaPrd.store(prdfile);
    prdfile.close();
    cout << "--Store AmaProduct, program: " << endl
      << "N,1234,box,123.45,1,1,kg,5" << endl
      << "N,1234,box,123.45,1,1,kg,5" << endl;
    cout << "--Store AmaProduct, yours: " << endl;
    dumpFile("amaPrd.txt");
    cout << "--Load AmaProduct: " << endl;
    prdfile.open("amaPrd.txt", ios::in);
    prdfile.ignore(2);
    tprd.load(prdfile);
    cout << "Program: 1234   |box                 | 139.50|   1|kg        |   5|" << endl;
    cout << "  Yours: " << tprd << endl;
    prdfile.clear();
    prdfile.close();
  }
}
void m2(){
  fstream pshfile("psh.txt", ios::out);
  AmaPerishable psh;
  bool ok = true;
  cout << "--AmaPerishable Item test:" << endl;
  if (ok){
    cout << "----Expiray date Validation test:" << endl;
    piv("abc", "abc", "abc", 'n', "10", "10", "10", "10/1/1");
    cin >> psh;
    if (cin.fail()){
      cin.clear();
      cout << "Passed!" << endl
        << "Message shoule be:  Invalid Year in Date Entry" << endl
        << "Your Error message: " << psh << endl;
    }
    else{
      ok = false;
      cout << "Expiry date validaton failed" << endl;
    }
    cin.ignore(2000, '\n');
  }
  _pause();
  if (ok){
    cout << "----Display test, the output of the Program and yours must match:" << endl;
    piv("1234", "water", "liter", 'n', "1.5", "1", "5", "2017/10/12");
    cin >> psh;
    cin.ignore(2000, '\n');
    cout << "--Linear------------" << endl;
    cout << "Program: 1234   |water               |   1.50|   1|liter     |   5|2017/10/12" << endl;
    cout << "  Yours: " << psh << endl;
    cout << "--Form Display------" << endl;
    cout << "--Program: " << endl;
    cout << "Sku: 1234" << endl;
    cout << "Name : water" << endl;
    cout << "Price : 1.50" << endl;
    cout << "Price after tax : N/A" << endl;
    cout << "Quantity On Hand : 1 liter" << endl;
    cout << "Quantity Needed : 5" << endl;
    cout << "Expiry date : 2017/10/12" << endl;
    cout << "--Yours: " << endl;
    psh.write(cout, false) << endl;
  }
  _pause();
  if (ok){
    cout << "----Storage and loading test, the output of the Program and yours must match:" << endl;
    AmaPerishable tpsh;
    psh.store(pshfile);
    psh.store(pshfile);
    pshfile.close();
    cout << "--Store AmaPerishable, program: " << endl
      << "P,1234,water,1.5,0,1,Liter,5,2017/10/12" << endl
      << "P,1234,water,1.5,0,1,Liter,5,2017/10/12" << endl;
    cout << "--Store AmaProduct, yours: " << endl;
    dumpFile("psh.txt");
    cout << "--Load AmaPerishable: " << endl;
    pshfile.open("psh.txt", ios::in);
    pshfile.ignore(2);
    tpsh.load(pshfile);
    cout << "Program: 1234   |water               |   1.50|   1|liter     |   5|2017/10/12" << endl;
    cout << "  Yours: " << tpsh << endl;
    pshfile.clear();
    pshfile.close();
  }
}

void piv(const char* sku, const char* name, const char* unit, char Tx ,
  const char* price, const char* qty, const char* qtyNd ,
  const char* date){
  cout
    << "Enter the following: " << endl
    << "Sku: " << sku << endl
    << "Name: " << name << endl
    << "Unit: " << unit << endl;
  if (Tx) cout << "Taxed: " << Tx << endl;
  if (price[0]) cout << "Price: " << price << endl;
  if (qty[0]) cout << "Quantity on hand: " << qty << endl;
  if (qtyNd[0]) cout << "Quantity needed: " << qtyNd << endl;
  if (date[0]) cout << "Expiry date: " << date << endl;
  cout << endl;
}
void dumpFile(const char* fname){
  ifstream f(fname);
  char ch;
  while (!f.get(ch).fail()){
    cout.put(ch);
  }
  f.clear();
  f.close();
}
void _pause(){
  cout << "****press enter to continue...";
  cin.ignore(1000, '\n');
}
