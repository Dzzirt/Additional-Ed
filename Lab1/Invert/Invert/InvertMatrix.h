#include <array>

typedef std::array < std::array<double, 3>, 3 > Matrix;

void PrintMatrix(Matrix const& matrix);

Matrix Get3dMatrixFromFile(std::string const& fileName);

bool ContainsAfterIncluding(std::string const& line, char symbol, size_t from);

Matrix Invert3dMatrix(Matrix const& matrix);

double Get3dMatrixDeterminant(Matrix const& matrix);

Matrix GetMinor3dMatrix(Matrix const& matrix);

Matrix GetCofactor3dMatrix(Matrix & matrix);

Matrix GetTransposed3dMatrix(Matrix const& matrix);

double GetMinorByPos(Matrix const& matrix, std::pair<size_t, size_t>const& pos);

Matrix Multiply3dMatrixWithNum(Matrix & matrix, double value);