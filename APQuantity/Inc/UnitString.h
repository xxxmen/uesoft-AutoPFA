#pragma once

#include <vector>
typedef std::vector< StdString > UnitStringSet;

template < typename Trans, int UnitNum >
class UnitStringManager : public UnitStringSet
{
	public:
		UnitStringManager() {
			for ( int i = 0; i < UnitNum; i++ )
			{
				push_back( Trans::UnitStringArray[i] );
			}
		}
};

#define DECLARE_UNITSTRING( trans, unit_num )\
	private:\
		typedef UnitStringManager< trans, unit_num > UnitStringSet_;\
		friend UnitStringSet_;\
	public:\
		static const UnitStringSet& UnitString();

#define IMPLEMENT_UNITSTRING( trans )\
	const UnitStringSet& trans::UnitString() {\
		static const trans::UnitStringSet_ UnitStringManagerObject;\
		return UnitStringManagerObject;\
	}