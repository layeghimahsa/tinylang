//only C-style single line comments allowed
//all functions must always return one argument
//all variables are integers
//using "arg" in function arguments makes parsing easier

func foo(arg x, arg y)
(
	return (x + y);
)

//"void" for functions that take no arguments is mandatory
func main(void)
(
	//valid variable names: must start with letter or underscore, then any letter, underscore or digit
	int x; //no initialization on declaration
	int y;
	int z;
	x = 0;
	y = 1;

	//explicit parenthesis mandatory in combining logical expressions
	//can use &&, ! and ||
	if((x == 0) && (y==1)) // ==, !=, <, >, <=, >=
	(
		int k;
		z = foo(x,y);
	)
	else
	(
	
	)
	return 0;
)
