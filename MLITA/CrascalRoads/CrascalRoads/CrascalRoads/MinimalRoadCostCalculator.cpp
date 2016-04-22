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
}
void CMinimalRoadCostCalculator::Calculate(string const& output)
{
	sort(m_arcs.begin(), m_arcs.end(), [&](auto const& pair1, auto const& pair2)
	{
		return pair1.second < pair2.second;
	});
	auto cost = 0;
	Arcs outputArcs;
	size_t counter = 0;
	Vertexes compared;
	while (m_vertexes != compared && counter < m_arcs.size())
	{
		cost += m_arcs[counter].second;
		outputArcs.push_back(m_arcs[counter]);
		compared.insert(m_arcs[counter].first.first);
		compared.insert(m_arcs[counter].first.second);
		counter++;
	}
	sort(outputArcs.begin(), outputArcs.end(), [&](auto const& pair1, auto const& pair2)
	{
		return pair1 < pair2;
	});
	ofstream out(output);
	out << cost << endl;
	for_each(outputArcs.begin(), outputArcs.end(), [&](auto const& pair1)
	{
		out << pair1.first.first << " " << pair1.first.second << endl;
	});
	out.close();
}


