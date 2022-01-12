#include "taffy.h"
#include "taffy_prot.h"

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		cout << "용법: Taffy filename\n"; exit(1);
	}
	convert_to_internalCode(argv[1]);
	syntaxChk();
	execute();
	return 0;
}