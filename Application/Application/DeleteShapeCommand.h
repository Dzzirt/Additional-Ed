#include "Command.h"
#include "memory"
#include "ShapeCreator.h"
#include "ShapeLogic.h"
#include "ShapeVisual.h"

class DeleteShapeCommand : public ICommand
{
public:
	DeleteShapeCommand(IShapeCreator & creator, std::shared_ptr<ShapeLogic> & logic, 
		std::shared_ptr<ShapeVisual> & visual);
	~DeleteShapeCommand();
	void execute()override;
	void undo()override;
private:
	std::shared_ptr<ShapeLogic> m_logic;
	std::shared_ptr<ShapeVisual> m_visual;
	size_t m_index;
	IShapeCreator & m_creator;
};
