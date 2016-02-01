#include "boost/signals2/connection.hpp"
class ICanvasClickObserver
{
public:
	virtual void UpdateOnCanvasClick() = 0;

	virtual boost::signals2::connection& GetCanvasClickConnection() = 0;
};