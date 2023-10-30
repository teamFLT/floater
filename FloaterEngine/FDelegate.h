#include <utility>

namespace flt {
	namespace engine
	{
		template <class OutputClass, class InputClass>
		union horrible_union {
			OutputClass out;
			InputClass in;
			horrible_union() {};
		};

		template <class OutputClass, class InputClass>
		inline OutputClass horrible_cast(const InputClass input) {
			horrible_union<OutputClass, InputClass> u;
			typedef int ERROR_CantUseHorrible_cast[sizeof(InputClass) == sizeof(u)
				&& sizeof(InputClass) == sizeof(OutputClass) ? 1 : -1];
			u.in = input;
			return u.out;
		}

		class AbstractDelegate {};

		template<typename R, typename ... Args>
		class FDelegate;

		class IDelegate
		{
		public:
			template<typename R, typename... Args>
			R Invoke(Args... args)
			{
				FDelegate<R, Args...>* del = reinterpret_cast<FDelegate<R, Args...>*>(this);
				return (*del)(this, args...);
			}
		};

		template<typename R, typename ... Args>
		class FDelegate : public IDelegate
		{
			using obj_t = AbstractDelegate*;
			using mtd_t = R(AbstractDelegate::*)(Args ...);
			mtd_t method;

		public:

			template <typename T>
			FDelegate(R(T::* mtd)(Args ...)) {
				method = horrible_cast<mtd_t, R(T::*)(Args ...)>(mtd);
			}

			R operator()(void* obj, Args ... args) volatile {
				return (reinterpret_cast<obj_t>(obj)->*method)(std::forward<Args>(args) ...);
			}
		};
	}
}
