#include "Taffy.h"
#include "Taffyprot.h"

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		cout << "¿ë¹ý: Taffy filename\n"; exit(1);
	}
	convert_to_internalCode(argv[1]);
	syntaxChk();
	execute();
	return 0;
}