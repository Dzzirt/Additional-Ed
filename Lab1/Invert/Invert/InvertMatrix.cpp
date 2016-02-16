#include "stdafx.h"
#include "InvertMatrix.h"
#include <iomanip>
#include "fstream"
#include "iostream"
#include "sstream"
#include "string"
#include "algorithm"
using namespace std;

void PrintMatrix(Matrix const& matrix)
{
	for (size_t row = 0; row < matrix.size(); row++)
	{
		for (size_t col = 0; col < matrix[0].size(); col++)
		{
			cout << std::setprecision(3) << matrix[row][col] << " ";
		}
		cout << endl;
	}
}

Matrix Get3dMatrixFromFile(string const& fileName)
{
	size_t lineNum = 0;
	Matrix matrix;
	ifstream in(fileName);
	string line;
	while (!in.eof())
	{
		if (lineNum == 3)
		{
			throw invalid_argument("Input file should contain 3x3 matrix");
		}
		getline(in, line);
		istringstream strm(line);
		double m1, m2, m3;
		if (strm >> m1 >> m2 >> m3)
		{
			int lineLength = static_cast<int>(strm.tellg());
			if (lineLength != -1)
			{
				auto line = strm.str();
				if (!ContainsAfterIncluding(line, ' ', lineLength) &&
					!ContainsAfterIncluding(line, '\t', lineLength))
				{
					throw invalid_argument("Input file should contain 3x3 matrix");
				};
			}
			matrix[lineNum][0] = m1;
			matrix[lineNum][1] = m2;
			matrix[lineNum][2] = m3;
			lineNum++;
		}
		else
		{
			throw invalid_argument("Input file should contain 3x3 matrix");
		}
	}
	if (lineNum < 3)
	{
		throw invalid_argument("Input file should contain 3x3 matrix");
	}
	return matrix;
}

bool ContainsAfterIncluding(string const& line, char symbol, size_t from)
{
	auto isJunk = [=](char letter){
		return letter != symbol;
	};
	auto it = find_if(line.begin() + from, line.end(), isJunk);
	if (it != line.end())
	{
		return false;
	}
	return true;
}

Matrix Invert3dMatrix(Matrix const& matrix)
{
	double determinant = Get3dMatrixDeterminant(matrix);
	if (determinant == 0)
	{
		throw invalid_argument("Inverted matrix does not exist");
	}
	auto resultMatrix = GetMinor3dMatrix(matrix);
	GetCofactor3dMatrix(resultMatrix);
	resultMatrix = GetTransposed3dMatrix(resultMatrix);
	Multiply3dMatrixWithNum(resultMatrix, 1 / determinant);
	return resultMatrix;
}

double Get3dMatrixDeterminant(Matrix const& matrix)
{
	double determinant = matrix[0][0] * matrix[1][1] * matrix[2][2] +
		matrix[2][0] * matrix[0][1] * matrix[1][2] +
		matrix[1][0] * matrix[2][1] * matrix[0][2] -
		matrix[2][0] * matrix[1][1] * matrix[0][2] -
		matrix[0][0] * matrix[2][1] * matrix[1][2] -
		matrix[1][0] * matrix[0][1] * matrix[2][2];
	return determinant;
}

Matrix GetMinor3dMatrix(Matrix const& matrix)
{
	Matrix matrixOfMinors;
	for (size_t row = 0; row < matrix.size(); row++)
	{
		for (size_t col = 0; col < matrix[0].size(); col++)
		{
			matrixOfMinors[row][col] = GetMinorByPos(matrix, { row, col });
		}
	}
	return matrixOfMinors;
}

double GetMinorByPos(Matrix const& matrix, std::pair<size_t, size_t> const& pos)
{
	array<double, 4> minorElements;
	size_t counter = 0;
	for (size_t row = 0; row < matrix.size(); row++)
	{
		for (size_t col = 0; col < matrix[0].size(); col++)
		{
			if (row != pos.first && col != pos.second)
			{	
				minorElements.at(counter) = matrix[row][col];
				counter++;
			}
		}
	}
	double minor = minorElements[0] * minorElements[3] - minorElements[1] * minorElements[2];
	return minor;
}

Matrix Multiply3dMatrixWithNum(Matrix & matrix, double value)
{
	for (size_t row = 0; row < matrix.size(); row++)
	{
		for (size_t col = 0; col < matrix[0].size(); col++)
		{
			matrix[row][col] *= value;
		}
	}
	return matrix;
}

Matrix GetCofactor3dMatrix(Matrix & matrix)
{
	matrix[0][1] *= -1;
	matrix[1][0] *= -1;
	matrix[1][2] *= -1;
	matrix[2][1] *= -1;
	return matrix;
}

Matrix GetTransposed3dMatrix(Matrix const& matrix)
{
	Matrix transposed;
	for (size_t row = 0; row < matrix.size(); row++)
	{
		for (size_t col = 0; col < matrix[0].size(); col++)
		{
			transposed[col][row] = matrix[row][col];
		}
	}
	return transposed;
}



