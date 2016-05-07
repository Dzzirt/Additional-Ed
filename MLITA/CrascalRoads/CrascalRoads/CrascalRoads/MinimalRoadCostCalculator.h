#pragma once

typedef std::vector<std::pair<std::pair<int, int>, int>> Arcs;
typedef std::set<int> Vertexes;
typedef std::map<int, int> VertexesID;


class CMinimalRoadCostCalculator
{
public:
	CMinimalRoadCostCalculator() = delete;
	CMinimalRoadCostCalculator(std::string const& input);
	void Calculate(std::string const& output);
private:
	void ReadGraph(std::string const& input);
	void Merge(size_t v2, size_t v1);
	void FillVertexesID();
	Arcs m_arcs;
	Vertexes m_vertexes;
	VertexesID m_vertexes_id;
};

