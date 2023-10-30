#pragma once
#include <string>
#include <vector>
#include "ReflectedMember.h"

namespace flt
{
	namespace reflection
	{
		class Macro : public ReflectedMember
		{
		public:
			Macro(unsigned depth,unsigned line, unsigned column, std::vector<std::string>&& token);
			virtual void OnLineVisited(); //매 라인 호출
			virtual void OnNextDataMemberAppeared(); //데이터 멤버 나올 때마다 호출 
			virtual void OnExpanded(); //매크로 확장시 호출
			virtual void OnParseEnd(); //파싱 끝났을때 호출
			std::string Serialize() override;

		public:
			unsigned GetLine();
			bool IsVisited();
			void SetVisited(bool value);

		protected:
			std::vector<std::string> _tokens;

		private:
			bool _isVisited;
		
		};
	}
}
