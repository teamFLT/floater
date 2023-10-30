#include "CppClassAnalyzer.h"

void main()
{
	flt::reflection::CppClassAnalyzer::AnalyzeDirectory("../Target");
	flt::reflection::CppClassAnalyzer::ShowAnalyzedClassQueue();
}