#include "stdafx.h"
#include "../Invert/InvertMatrix.h"

BOOST_AUTO_TEST_SUITE(InvertMatrixTests)

BOOST_AUTO_TEST_CASE(InvertProcess)
{
	Matrix matrix3d = {
		{ 1, -2, 3 },
		{ 4, 0, 6 },
		{ -7, 8, 9 }
	};
	Matrix multBy2 = {
		{ 2, -4, 6 },
		{ 8, 0, 12 },
		{ -14, 16, 18 }
	};
	Matrix matrixOfMinors = {
		{  -48 ,  78 ,  32  },
		{  -42 ,  30 ,  -6  },
		{  -12 ,  -6 ,  8  }
	};
	Matrix algAddMatrix = {
		{ -48, -78, 32 },
		{ 42, 30, 6 },
		{ -12, 6, 8 }
	};
	Matrix transposed = {
		{ -48, 42, -12 },
		{ -78, 30, 6 },
		{ 32, 6, 8 }
	};
	Matrix matrix2d = {
		{  1 ,  -2 },
		{  4 ,  0 }
	};

	BOOST_CHECK_THROW(Get3dMatrixDeterminant(matrix2d), std::invalid_argument);
	BOOST_CHECK_THROW(GetMinorByPos(matrix2d, { 0, 0 }), std::invalid_argument);
	BOOST_CHECK_THROW(GetMinor3dMatrix(matrix2d), std::invalid_argument);
	BOOST_CHECK_THROW(ToAlgAdditions3dMatrix(matrix2d), std::invalid_argument);
	BOOST_CHECK_THROW(GetTransposed3dMatrix(matrix2d), std::invalid_argument);

	BOOST_CHECK_THROW(Get3dMatrixFromFile("errInput1.txt"), std::invalid_argument);
	BOOST_CHECK_THROW(Get3dMatrixFromFile("errInput2.txt"), std::invalid_argument);
	BOOST_CHECK_THROW(Get3dMatrixFromFile("errInput3.txt"), std::invalid_argument);
	BOOST_CHECK_THROW(Get3dMatrixFromFile("errInput4.txt"), std::invalid_argument);




	std::string lineErr = "14344";
	BOOST_CHECK_EQUAL(ContainsAfterIncluding(lineErr, '4', 1), false);

	BOOST_CHECK_EQUAL(Get3dMatrixDeterminant(matrix3d), 204.f);

	BOOST_CHECK_EQUAL(GetMinorByPos(matrix3d, { 0, 0 }), -48.f);
	BOOST_CHECK_EQUAL(GetMinorByPos(matrix3d, { 1, 2 }), -6.f);
	BOOST_CHECK_EQUAL(GetMinorByPos(matrix3d, { 2, 1 }), -6.f);
	BOOST_CHECK_EQUAL(GetMinorByPos(matrix3d, { 0, 1 }), 78.f);

	BOOST_CHECK(GetMinor3dMatrix(matrix3d) == matrixOfMinors);

	BOOST_CHECK(ToAlgAdditions3dMatrix(matrixOfMinors) == algAddMatrix);

	BOOST_CHECK(GetTransposed3dMatrix(matrixOfMinors) == transposed);

	BOOST_CHECK(Multiply3dMatrixWithNum(matrix3d, 2.f) == multBy2);

	BOOST_CHECK(Get3dMatrixFromFile("input.txt") == matrix3d);

	std::string lineOk = "14444";
	BOOST_CHECK_EQUAL(ContainsAfterIncluding(lineOk, '4', 1), true);
}
BOOST_AUTO_TEST_SUITE_END()