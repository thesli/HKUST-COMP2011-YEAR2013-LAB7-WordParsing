#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <iomanip>
using namespace std;
bool r1(string str);
bool r2(string str);
bool r3(string str);
bool r4(string str){
	int barPos = str.find_last_of('|');
	string lastTerms;
	if(barPos!=-1){
		lastTerms = str.substr(barPos+1);
		if(r3(lastTerms)){
			if(barPos==0){
				return true;
			}else{
				return r4(str.substr(0,barPos-1));
			}
		}else{
			return false;
		}
	}else{
		return r3(str);
	}
}
bool r3(string str){
	int found;
	int hypPos = str.find_last_of('-');
	int arrPos = str.find_last_of('>');
	found = max(hypPos,arrPos);
	string lastTerms;
	if(found!=-1){
		lastTerms = str.substr(found+1);
		if(r1(lastTerms)&&r2(lastTerms)){
			if(found == 0){
				return true;
			}
			return r3(str.substr(0,found-1));
		}else{
			return false;
		}
	}else{
		return (r1(str)&&r2(str));
	}
}
bool r2_isLessThanOne(string str,char a){
	return count(str.begin(),str.end(),a)<2;
}
bool r2(string str){
   return (r2_isLessThanOne(str,'@') && r2_isLessThanOne(str,'#')&& r2_isLessThanOne(str,'$')&& r2_isLessThanOne(str,'%')&& r2_isLessThanOne(str,'^')&&r2_isLessThanOne(str,'&'));
}

bool r1_char(char a){
	return (a=='@'||a=='#'||a=='$'||a=='%'||a=='^'||a=='&'||a=='-'||a=='>'||a=='|');
}

bool r1(string str){
	for (int i = str.length()-1; i >= 0 ; i--)
	{
		if(!r1_char(str[i])){
			return false;
		}
	}
	return true;
}

int main(int argc, char const *argv[])
{
	string test[] = {
		"#",
		"$",
		"-#",
		">$",
		"->$",
		">-#",
		"|>$->$",
		"||>$->$>-#",
		"---||>$->$>-#",
		"|---||>$->$>-#||>$->$>-#",
		"##",
		"|$$$",
		"---$@",
		">$>>%",
		"||##"
	};
	int len = sizeof(test)/sizeof(string);
	for (int i = 0; i < len; ++i)
	{
		cout << "result : " << r4(test[i]) << " for " << test[i] << "\n";
	}
	return 0;
}