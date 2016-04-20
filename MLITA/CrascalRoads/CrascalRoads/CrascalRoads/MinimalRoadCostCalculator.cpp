#include "stdafx.h"
#include "MinimalRoadCostCalculator.h"
using namespace std;

CMinimalRoadCostCalculator::CMinimalRoadCostCalculator(string const& input)
{

	GetGraph(input);
}

void CMinimalRoadCostCalculator::GetGraph(std::string const& input)
{
	ifstream in(input);
	string line;
	getline(in, line);
	auto arcsCount = line[2] - '0';
	auto vertexesCount = line[0] - '0';
	m_arcs = Arcs(arcsCount);
	for (size_t i = 0; i < m_arcs.size(); ++i)
	{
		getline(in, line);
		vector<string> parsed;
		boost::split(parsed, line, bind2nd(equal_to<char>(), ' '));
		int first = stoi(parsed[0]);
		int second = stoi(parsed[1]);
		if (first > second)
		{
			swap(first, second);
		}
		m_arcs[i] = { { first, second }, stoi(parsed[2]) };
		m_vertexes.insert(first);
		m_vertexes.insert(second);
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
		return pair1.first < pair2.first;
	});
	ofstream out(output);
	out << cost << endl;
	for_each(outputArcs.begin(), outputArcs.end(), [&](auto const& pair1)
	{
		out << pair1.first.first << " " << pair1.first.second << endl;
	});
	out.close();
}


