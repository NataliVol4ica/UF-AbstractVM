
#include "eOperandType.hpp"
#include "Operand.hpp"
#include "avmFuncs.hpp"
#include "defines.hpp"

IOperand const * createOperand(eOperandType type, std::string const & value )
{
	if (type == Int8)
		return (new Operand<char>(static_cast<char>(stoi(value))));
	if (type == Int16)
		return (new Operand<char>(static_cast<short>(stoi(value))));
	if (type == Int32)
		return (new Operand<char>(stoi(value)));
	if (type == Float)
		return (new Operand<char>(stof(value)));
	if (type == Double)
		return (new Operand<char>(stod(value)));
	//throw exception?
}