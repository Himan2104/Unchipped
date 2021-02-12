#pragma once
#include<SFML/Graphics.hpp>

namespace util
{
	class eUtil
	{
	public:
		template<typename T>
		static inline void centerOrigin(T& object);
	};
	template<typename T>
	inline void eUtil::centerOrigin(T& object)
	{
		object.setOrigin(object.getGlobalBounds().width / 2.0f, object.getGlobalBounds().height / 2.0f);
	}
}
