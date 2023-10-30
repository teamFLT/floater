#include "ReflectedMember.h"

flt::reflection::ReflectedMember::ReflectedMember(unsigned depth, unsigned line, unsigned column) :
	ReflectedObject(depth),
	_line(line),
	_column(column) {}
