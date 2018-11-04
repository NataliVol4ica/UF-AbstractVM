#include "defines.hpp"
#include "AVMParser.hpp"
#include <stdio.h>
#include <vector>

//todo: canonic form
//todo: log flag
//todo: more funcs
//todo: rm (void)-s
//todo: add command size
//todo: add command clean
//todo: print the program with numerated lines

int main(void)

{	
	try
	{
		std::vector<std::string> prog;
		prog.push_back("push int32(42);cmnt push");
		prog.push_back("");
		//prog.push_back("nekotorii musor");
		//prog.push_back("int32(8)");
		//prog.push_back("eshemusorpush int32(0)");
		//prog.push_back("push int32(0) 0 ;cmnt laal");
		//prog.push_back("push int8(42.3)");
		prog.push_back("push int8(41)");
		prog.push_back("dump");
		prog.push_back("add");
		prog.push_back("dump");
		prog.push_back("push int8(-2)");
		prog.push_back("print");
		prog.push_back("size");
		prog.push_back("clean");
		//prog.push_back("pop");
		prog.push_back("push int8(2)");
		prog.push_back("push int8(1)");
		prog.push_back("sub");
		prog.push_back("dump");
		prog.push_back("exit");
		AVMParser p = AVMParser();
		p.Parse(prog);

	/*	OperandFactory of = OperandFactory();
		const IOperand *a = of.createOperand(Int8, "gdgdf");
		const IOperand *b = of.createOperand(Int8, "1");
		const IOperand *c =  *a + *b;
		cout << c->toString() << endl;
	*/
	}
	catch(exception &e)
	{		
		cout << e.what() << endl;
	}
	catch(exception *e)
	{		
		cout <<"Error: "<< e->what() << endl;
	}
	//getchar();
	//system("leaks avm");
	return 0;
}

/*std::ifstream t("file.txt");
std::stringstream buffer;
buffer << t.rdbuf();

Now the contents of "file.txt" are available in a string as buffer.str().*/
//read from std while cin does not match ";;.*"
