#include "AVMParser.hpp"

/* ======== CANONICAL ======== */

AVMParser::AVMParser() {}

void AVMParser::Parse(std::vector<std::string> program)
{
	int errors = 0;
	for (size_t i = 0; i < program.size(); i++)
	{
		std::vector<std::string> stringTokens = Tokenize(program[i], i, errors);
		//check errors try catch
		//recognize lexems (struct string + enum)
		//compile
	}
	cout << "Errors in total: " << errors << endl;
}

std::vector<std::string> AVMParser::Tokenize(std::string program, size_t line, int &errors)
{
	std::vector<std::string> tokens;
	std::smatch sm;
	while (regex_search(program, sm, _lexemRegEx))
	{
		if (sm.prefix().length() != 0)
		{
			errors++;
			cout << "Line " << line << ": unknow lexem \"" << sm.prefix() << "\"" << endl;
		}
		//cout << sm.str() << '\n';
		tokens.push_back(sm.str());
		program = sm.suffix();
	}
	if (program.length() > 0)
	{
		errors++;
		cout << "Line " << line << ": unknow lexem \"" << program << "\"" << endl;
	}
	return tokens;
}

std::vector<LexemToken> AVMParser::RecognizeLexems(std::vector<std::string> tokens)
{
	std::vector<LexemToken> lTokens;
	for (size_t i = 0; i < tokens.size(); i++)
	{
		try
		{
			lTokens.push_back(LexemToken(tokens[i], lexemMap.at(tokens[i])));
		}
		catch (exception)
		{
			cout << tokens[i] << endl;
		}
	}
	return lTokens;
}

