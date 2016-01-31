#include "boost/signals2/connection.hpp"
class IShapeClickObserver
{
public:
	virtual void UpdateOnShapeClick(size_t shapeIndex) = 0;

	virtual boost::signals2::connection& GetShapeClickConnection() = 0;
};