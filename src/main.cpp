#include <iostream>

bool validator(std::string num) {
  bool dot = false;
  bool minus;
  // bool positive = true;
  int posDot = 0;
  int startInt = 0;
  int endInt = 0;
  int startFrac = 0;
  minus = num.length() > 0 && num[0] == '-';

  for(int i = 0; !dot && i < num.length(); i++){
    if(num[i] == '.'){
      dot = true;
      posDot = i;
    }
  }

  startInt = minus ? 1 : 0;

  endInt = dot ? posDot : num.length();
  for(int i = startInt; i < endInt; i++){
    if(num[i] < '0' || num[i] > '9'){
      return false;
    }
  }

  startFrac = dot ? posDot + 1 : num.length();
  for(int i = startFrac; i < num.length(); i++){
    if(num[i] < '0' || num[i] > '9'){
      return false;
    }
  }

  if((endInt - startInt) + (num.length() - startFrac) == 0){
    return false;
  }
  // std::cout << (positive ? "Yes" : "No") << std::endl;
  return true;
}

int parsDec(std::string strDec){
  int numDec;
  strDec = strDec.substr(0, strDec.find("."));
  std::cout << "parsDec strDec - " << strDec.c_str() << std::endl;
  numDec = std::stoi(strDec);
  return numDec; 
}
int parsFrac(std::string strFrac) {
  int numFrac;
  std::string tmpStrFrac;
  tmpStrFrac = strFrac.erase(0, strFrac.find(".") + 1);
  std::cout << "parsFrac strFrac - " << tmpStrFrac.c_str() << std::endl;
  for(int i = 0; i < tmpStrFrac.length(); i++){
    if(tmpStrFrac[i] != '0'){
      numFrac = std::stoi(tmpStrFrac);
    }else{
      tmpStrFrac.erase(0, tmpStrFrac.length());
    }
  }
  return numFrac;
}
int main() {
  std::string num1;
  std::string num2;
  std::cout << "Comparison of real numbers!" << std::endl;
  std::cout << "Enter the first number " << std::endl;
  std::cin >> num1;
  std::cout << "Enter the second number " << std::endl;
  std::cin >> num2;
  if(validator(num1) && validator(num2)){
    if(parsDec(num1) > parsDec(num2)){
      std::cout << "More" << std::endl;
    }else if(parsDec(num1) < parsDec(num2)){
      std::cout << "Less" << std::endl;
    }else if(parsDec(num1) == parsDec(num2)){
      if(parsFrac(num1) > parsFrac(num2)){
        std::cout << "More" << std::endl;
      }else if(parsFrac(num1) < parsFrac(num2)){
        std::cout << "Less" << std::endl;
      }else{
        std::cout << "Equal" << std::endl;
      }
    }
  }else 
    std::cout << "Error" << std::endl;
}