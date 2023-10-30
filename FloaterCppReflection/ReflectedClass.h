#pragma once
#include <set>
#include <string>
#include <vector>

#include "ReflectedObject.h"
#include "DataMember.h"
#include "EnumType.h"
#include "Macro.h"

namespace flt
{
	namespace reflection
	{
		class ReflectedClass : public ReflectedObject
		{
		public:
			ReflectedClass(unsigned depth,ReflectedClass* parent = nullptr);
			std::string Serialize() override;
			void CheckLine(unsigned line); //매 라인 호출
			void DataMemberAppear(unsigned line); //데이터 멤버 나올 때마다 호출 
			void ParseEnd(); //파싱 끝났을때 호출

		public:
			bool isStruct;
			std::string name;
			std::string usr;
			std::vector<Macro*> macros;
			std::vector<DataMember*> dataMembers;
			std::vector<EnumType*> enumTypes;
			std::set<std::string> rawBaseClasses;
			ReflectedClass* parent;
			std::vector<ReflectedClass*> nestedClasses;

		};
	}

}
