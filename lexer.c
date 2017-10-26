int num_lines = 0, num_chars = 0;
%%
\n  ++num_lines; ++num_chars;
BEGINING.
BODY.
PRINT" ([A-Za-z]|[0-9])".
INPUT" ([A-Za-z]|[0-9])".
MOVE
ADD
END.
%%
main() {
    yyliex();
    printf("# of lines = %d, # of chars = %d\n", num_lines, num_chars);
}
                      
