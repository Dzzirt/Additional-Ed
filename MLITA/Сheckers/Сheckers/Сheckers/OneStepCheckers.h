#pragma once
#include <array>

typedef std::array<std::array<int, 8>, 8> CheckersBoard;
typedef std::array<std::array<bool, 8>, 8> AttendanceTable;

struct SPosition
{
	SPosition() = default;
	SPosition(unsigned row, unsigned col);
	unsigned row = 0;
	unsigned col = 0;
};

class COneStepCheckers
{
public:
	COneStepCheckers(std::string const& input);
	void WriteStepResultInFile(std::string const& output);
private:
	void CalculateEatenBlackCount(SPosition const& start, unsigned & counter);

	CheckersBoard m_board;
	AttendanceTable m_attendance;
	SPosition m_startPos;
	unsigned m_maxEatenBlackCount;
};

