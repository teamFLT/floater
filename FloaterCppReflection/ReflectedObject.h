#pragma once
#include <string>
namespace flt
{
	namespace reflection
	{
		class ReflectedObject
		{
		public:
			ReflectedObject(unsigned depth);
			virtual ~ReflectedObject() = default;
			virtual std::string Serialize() abstract;
		public:
			std::string filename;
			unsigned depth;
		};

		inline ReflectedObject::ReflectedObject(unsigned depth) :
			depth(depth) {}
	}
}