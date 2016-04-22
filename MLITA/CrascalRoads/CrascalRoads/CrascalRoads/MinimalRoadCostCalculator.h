#pragma once

typedef std::vector<std::pair<std::pair<int, int>, int>> Arcs;
typedef std::set<int> Vertexes;

class CMinimalRoadCostCalculator
{
public:
	CMinimalRoadCostCalculator() = delete;
	CMinimalRoadCostCalculator(std::string const& input);
	void Calculate(std::string const& output);
private:
	void ReadGraph(std::string const& input);
	Arcs m_arcs;
	Vertexes m_vertexes;
};

