#include "stdafx.h"
#include "OneStepCheckers.h"

using namespace std;


SPosition::SPosition(unsigned row, unsigned col)
	:row(row), col(col)
{

}

COneStepCheckers::COneStepCheckers(std::istream & in)
	: m_maxEatenBlackCount(0)
{
	string boardLine;
	for (size_t row = 0; row < m_board.size(); row++)
	{
		in >> boardLine;
		for (size_t col = 0; col < m_board[0].size(); col++)
		{
			auto cell = boardLine[col] - '0';
			if (cell == 2)
			{
				m_startPos = SPosition(row, col);
			}
			m_board[row][col] = cell;
		}
	}
	auto arr = std::array<bool, 8>();
	arr.fill(false);
	m_attendance.fill(arr);
}

void COneStepCheckers::WriteResult(std::ostream & out)
{
	out << m_maxEatenBlackCount;
}

unsigned COneStepCheckers::Run()
{
	unsigned counter = 0;
	CalculateEatenBlackCount(GetChiefCheckerPosition(), counter);
	return m_maxEatenBlackCount;
}

void COneStepCheckers::CalculateEatenBlackCount(SPosition const& start, unsigned & counter)
{
	m_onChiefsStateChange(SStateData(start, counter, m_maxEatenBlackCount));
	auto row = static_cast<int>(start.row);
	auto col = static_cast<int>(start.col);
	// Bottom Right
	if ((static_cast<unsigned>(row + 2) < m_board.size() 
		&& static_cast<unsigned>(col + 2) < m_board[0].size())
		&& (m_board[row + 1][col + 1] == 1) 
		&& (!m_attendance[row + 1][col + 1]))
	{
		counter++;
		m_attendance[row + 1][col + 1] = true;
		CalculateEatenBlackCount(SPosition(row + 2, col + 2), counter);
		m_onChiefsStateChange(SStateData(start, counter, m_maxEatenBlackCount));
		m_attendance[row + 1][col + 1] = false;
	}
	// Bottom Left
	if ((static_cast<unsigned>(row + 2) < m_board.size()
		&& col - 2 > 0)
		&& (m_board[row + 1][col - 1] == 1) 
		&& (!m_attendance[row + 1][col - 1]))
	{
		counter++;
		m_attendance[row + 1][col - 1] = true;
		CalculateEatenBlackCount(SPosition(row + 2, col - 2), counter);
		m_onChiefsStateChange(SStateData(start, counter, m_maxEatenBlackCount));
		m_attendance[row + 1][col - 1] = false;
	}
	// Upper Right
	if ((row - 2 > 0 
		&& static_cast<unsigned>(col + 2) < m_board.size())
		&& (m_board[row - 1][col + 1] == 1)
		&& (!m_attendance[row - 1][col + 1]))
	{
		counter++;
		m_attendance[row - 1][col + 1] = true;
		CalculateEatenBlackCount(SPosition(row - 2, col + 2), counter);
		m_onChiefsStateChange(SStateData(start, counter, m_maxEatenBlackCount));
		m_attendance[row - 1][col + 1] = false;
	}
	// Upper Left
	if ((row - 2 > 0 
		&& col - 2 > 0)
		&& (m_board[row - 1][col - 1] == 1)
		&& (!m_attendance[row - 1][col - 1]))
	{
		counter++;
		m_attendance[row - 1][col - 1] = true;
		CalculateEatenBlackCount(SPosition(row - 2, col - 2), counter);
		m_onChiefsStateChange(SStateData(start, counter, m_maxEatenBlackCount));
		m_attendance[row - 1][col - 1] = false;
	}
	if (counter > m_maxEatenBlackCount)
	{
		m_maxEatenBlackCount = counter;
	}
	if (counter != 0)
	{
		counter--;
	}
}

std::vector<SPosition> COneStepCheckers::GetBlackPositions() const
{
	std::vector<SPosition> blackPositions;
	for (size_t row = 0; row < m_board.size(); row++)
	{
		for (size_t col = 0; col < m_board[0].size(); col++)
		{
			if (m_board[row][col] == 1)
			{
				blackPositions.emplace_back(row, col);
			}
		}
	}
	return blackPositions;
}

SPosition COneStepCheckers::GetChiefCheckerPosition() const
{
	return m_startPos;
}

void COneStepCheckers::Connect(std::function<void(SStateData)> const& handler)
{
	m_onChiefsStateChange.connect(handler);
}

SStateData::SStateData(SPosition const& pos, unsigned count, unsigned max)
	:chiefPos(pos), count(count), max(max)
{

}
