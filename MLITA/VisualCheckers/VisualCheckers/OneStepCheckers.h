#pragma once
#include <array>
#include "boost/signals2.hpp"

typedef std::array<std::array<int, 8>, 8> CheckersBoard;
typedef std::array<std::array<bool, 8>, 8> AttendanceTable;

struct SPosition
{
	SPosition() = default;
	SPosition(unsigned row, unsigned col);
	unsigned row = 0;
	unsigned col = 0;
};

struct SStateData
{
	SStateData(SPosition const& pos, unsigned count, unsigned max);
	unsigned count = 0;
	unsigned max = 0;
	SPosition chiefPos = SPosition(0, 0);
};

class COneStepCheckers
{
public:
	COneStepCheckers(std::istream & in);
	void WriteResult(std::ostream & out);
	unsigned Run();
	void CalculateEatenBlackCount(SPosition const& start, unsigned & counter);
	std::vector<SPosition> GetBlackPositions() const;
	SPosition GetChiefCheckerPosition() const;
	void Connect(std::function<void(SStateData)> const& handler);
private:
	CheckersBoard m_board;
	AttendanceTable m_attendance;
	SPosition m_startPos;
	unsigned m_maxEatenBlackCount;
	boost::signals2::signal<void(SStateData)> m_onChiefsStateChange;
};

