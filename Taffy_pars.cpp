

#include "Taffy.h"
#include "Taffyprot.h"

#define NO_FIX_ADRS 0
Token token;
SymTbl tmpTb;
int blkNest;
int localAdrs;
int mainTblNbr;
int loopNest;
bool fncDecl_F;
bool explicit_F;
char codebuf[LIN_SIZ + 1], *codebuf_p;
extern vector<char*> intercode;

void init()
{
	initChTyp();
	mainTblNbr = -1;
	blkNest = loopNest = 0;
	fncDecl_F = explicit_F = false;
	codebuf_p = codebuf;
}

void convert_to_internalCode(char *fname)
{
	init();

	fileOpen(fname);
	while (token = nextLine_tkn(), token.kind != EofProg)
	{
		if (token.kind == Func)
		{
			token = nextTkn(); set_name(); enter(tmpTb, fncId);
		}
	}
	push_intercode();
	fileOpen(fname);
	token = nextLine_tkn();

	while (token.kind != EofProg)
	{
		convert();
	}


	set_startPc(1);
	if (mainTblNbr != -1)
	{
		set_startPc(intercode.size());
		setCode(Fcall, mainTblNbr); setCode('('); setCode(')');
		push_intercode();
	}
}

void convert()
{
	switch (token.kind)
	{
	case Option: optionSet();
		break;
	case Var: varDecl();
		break;
	case Func: fncDecl(); 
		break;
	case While: case For:
		++loopNest;
		convert_block_set(); setCode_End();
		--loopNest;
		break;
	case If:
		convert_block_set();
		while (token.kind == Elif)
		{
			convert_block_set();
		}
		if (token.kind == Else)
		{
			convert_block_set();
		}
		setCode_End;
		break;
	case Break:
		if (loopNest <= 0) err_exit("�߸��� break�� �Դϴ�.");
		setCode(token.kind); token = nextTkn(); convert_rest();
		break;
	case Return:
		if (!fncDecl_F) err_exit("�߸��� return�Դϴ�.");
		setCode(token.kind); token = nextTkn(); convert_rest();
		break;
	case Exit:
		setCode(token.kind); token = nextTkn(); convert_rest();
		break;
	case Print: case Println:
		setCode(token.kind); token = nextTkn(); convert_rest();
		break;
	case End:
		err_exit("�߸��� end�Դϴ�.");
		break;
	default: convert_rest(); break;
	}
}


void convert_block_set()
{
	int patch_line;
	patch_line = setCode(token.kind, NO_FIX_ADRS); token = nextTkn();
	convert_rest();
	convert_block();
	backPatch(patch_line, get_linNo());
}

void convert_block()
{
	TknKind k;
	++blkNest;
	while(k=token.kind, k!=Elif && k!=Else && k!=End && k!=EofProg)
	{
		convert();
	}
	--blkNest;
}

void convert_reset()
{
	int tblNbr;

	for (;;) 
	{
		if (token.kind == EofLine) break;
		switch (token.kind)
		{
			case If: case Elif: case Else: case For: case While: case Break:
			case Func: case Return: case  Exit: case  Print: case Println:
			case Option: case Var: case End:
				err_exit("잘못된 기술입니다: ", token.text);
				break;
			case Ident:
				set_name():
				if ((tblNbr=searchName(tmpTb.name, 'F')) != -1)
				{
					if (tmpTb.name == "main")err_exit("Main함수는 호출할 수 없습니다.")
					setCode(Fcall, tblNbr); continue;
				}
				if ((tblNbr=searchName(tmpTb.name, 'V')) == -1)
					
		
			default:
				break;
		}
	}
}
