#pragma once
#include "DomainModel.h"
#include "Command.h"
#include "stack"

typedef std::vector<std::shared_ptr<ShapeLogic>> ShapeLogicVec;

class ApplicationModel
{
public:
	
	ApplicationModel();
	ApplicationModel(std::shared_ptr<DomainModel> domainModel);
	~ApplicationModel();

	std::shared_ptr<ShapeLogic> CreateShape(ShapeType type);
	void RemoveShape(int pos);
	ShapeLogicVec & GetShapes();

	void AddShape(std::shared_ptr<ShapeLogic> & shapeLogic, size_t index);
	void SetSize(int pos, sf::Vector2f const& size);
	void SetPosition(int pos, sf::Vector2f const& position);
	void SetSelected(std::shared_ptr<ShapeLogic> & shapeLogic);

	std::shared_ptr<ShapeLogic>& GetShape(size_t pos);
	size_t GetShape(ShapeLogic & shapeLogic);
	std::shared_ptr<ShapeLogic> & GetSelected();
	std::shared_ptr<ShapeLogic> & GetTempShape();
	void AddCommand(std::shared_ptr<ICommand> command);
	void Undo();
	void Redo();
private:
	std::shared_ptr<DomainModel> m_domainModel;
	std::shared_ptr<ShapeLogic> m_selectedShape;
	std::shared_ptr<ShapeLogic> m_tempShape;
	std::stack<std::shared_ptr<ICommand>> m_undoStack;
	std::stack<std::shared_ptr<ICommand>> m_redoStack;
};

