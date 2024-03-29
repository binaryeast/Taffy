

#include "taffy.h"
#include "taffy_prot.h"

string dbl_to_s(double d)
{
	ostringstream ostr;
	ostr << d;
	return ostr.str();
}

string err_msg(const string& a, const string& b)
{
	if (a == "") return b + " 가 필요합니다.";
	if (b == "") return a + " 가 바르지 않습니다.";
	return b + " 가 " + a + " 앞에 필요합니다.";
}

void err_exit(Tobj a, Tobj b, Tobj c, Tobj d)
{
	Tobj ob[5];
	ob[1] = a; ob[2] = b; ob[3] = c; ob[4] = d;
	cerr << "line:" << get_lineNo() << "ERROR ";

	for (int i = 1; i <= 4 && ob[i].s != "\1"; i++)
	{
		if (ob[i].type == 'd') cout << ob[i].d;
		if (ob[i].type == 's') cout << ob[i].s;
	}
	cout << endl;
	exit(1);
}