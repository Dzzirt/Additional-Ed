#include "stdafx.h"
#include "MinimalRoadCostCalculator.h"
using namespace std;

CMinimalRoadCostCalculator::CMinimalRoadCostCalculator(string const& input)
{

	ReadGraph(input);
}

void CMinimalRoadCostCalculator::ReadGraph(std::string const& input)
{
	ifstream in(input);
	string line;
	int arcsCount;
	int vertexesCount;
	in >> vertexesCount >> arcsCount;
	m_arcs = Arcs(arcsCount);
	for (size_t i = 0; i < m_arcs.size(); ++i)
	{
		int firstVertex;
		int secondVertex;
		int weight;
		in >> firstVertex >> secondVertex >> weight;
		if (firstVertex > secondVertex)
		{
			swap(firstVertex, secondVertex);
		}
		m_arcs[i] = { { firstVertex, secondVertex }, weight };
		m_vertexes.insert(firstVertex);
		m_vertexes.insert(secondVertex);
	}
	FillVertexesID();
}
void CMinimalRoadCostCalculator::Calculate(string const& output)
{
	sort(m_arcs.begin(), m_arcs.end(), [&](auto const& pair1, auto const& pair2)
	{
		return pair1.second < pair2.second;
	});

	size_t cost = 0;
	vector < pair<int, int> > outputArcs;
	for (size_t i = 0; i < m_arcs.size(); ++i)
	{
		size_t vert1 = m_arcs[i].first.first;
		size_t vert2 = m_arcs[i].first.second;
		size_t weight = m_arcs[i].second;

		if (m_vertexes_id[vert1] != m_vertexes_id[vert2])
		{
			cost += weight;
			outputArcs.push_back({vert1, vert2});
			Merge(m_vertexes_id[vert2], m_vertexes_id[vert1]);
		}
	}

	sort(outputArcs.begin(), outputArcs.end(), [&](auto const& pair1, auto const& pair2)
	{
		return pair1 < pair2;
	});

	ofstream out(output);
	out << cost << endl;
	for_each(outputArcs.begin(), outputArcs.end(), [&](auto const& pair1)
	{
		out << pair1.first << " " << pair1.second << endl;
	});
	out.close();
}

void CMinimalRoadCostCalculator::FillVertexesID()
{
	std::vector<int> vert(m_vertexes.begin(), m_vertexes.end());
	for (size_t i = 0; i < m_vertexes.size(); ++i)
	{
		m_vertexes_id.emplace(vert[i], i);
	}
		
}

void CMinimalRoadCostCalculator::Merge(size_t dstGroup, size_t srcGroup)
{
	for (auto & pair : m_vertexes_id)
	{
		if (pair.second == srcGroup)
		{
			pair.second = dstGroup;
		}
	}
}

