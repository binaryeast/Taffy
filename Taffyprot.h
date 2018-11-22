void init();
void convert_to_internalCode(char *fname);
void convert();
void convert_block_set();
void convert_block();
void convert_rest();
void optionSet();
void varDecl();
void var_namechk(const Token& tk);
void set_name();
void set_aryLen();
void fncDecl();
void backPatch(int line, int n);
void setCode(int cd);
int setCode(int cd, int nbr);
void setCode_rest