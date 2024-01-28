#include "MatrixTrans.h"
#include <cmath>
#include <Novice.h>

// ‰ÁŽZ
Matrix4 Add(const Matrix4& m1, const Matrix4& m2) {
	Matrix4 result;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			result.m[i][j] = m1.m[i][j] + m2.m[i][j];
		}
	}

	return result;
};

// Ï
Vector3 Multiply(const Vector3& v1, const Vector3& v2) {
	Vector3 result{
		(v1.x * v2.x) + (v1.y * v2.x) + (v1.z * v2.x),
		(v1.x * v2.y) + (v1.y * v2.y) + (v1.z * v2.y),
		(v1.x * v2.z) + (v1.y * v2.z) + (v1.z * v2.z)
	};
	return result;
};

// ƒXƒJƒ‰[”{
Vector3 Multiply(const Vector3& v1, float scale) {
	Vector3 result;
	result.x = v1.x * scale;
	result.y = v1.y * scale;
	result.z = v1.z * scale;
	return result;
}

// ƒXƒJƒ‰[”{
Matrix4 Multiply(Matrix4 m, float scale) {
	Matrix4 result;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			result.m[i][j] = m.m[i][j] * scale;
		}
	}

	return result;
}

Matrix4 Multiply(const Matrix4& m1, const Matrix4& m2) {
	Matrix4 result{};
	result.m[0][0] = m1.m[0][0] * m2.m[0][0] + m1.m[0][1] * m2.m[1][0] + m1.m[0][2] * m2.m[2][0] +
		m1.m[0][3] * m2.m[3][0];
	result.m[0][1] = m1.m[0][0] * m2.m[0][1] + m1.m[0][1] * m2.m[1][1] + m1.m[0][2] * m2.m[2][1] +
		m1.m[0][3] * m2.m[3][1];
	result.m[0][2] = m1.m[0][0] * m2.m[0][2] + m1.m[0][1] * m2.m[1][2] + m1.m[0][2] * m2.m[2][2] +
		m1.m[0][3] * m2.m[3][2];
	result.m[0][3] = m1.m[0][0] * m2.m[0][3] + m1.m[0][1] * m2.m[1][3] + m1.m[0][2] * m2.m[2][3] +
		m1.m[0][3] * m2.m[3][3];

	result.m[1][0] = m1.m[1][0] * m2.m[0][0] + m1.m[1][1] * m2.m[1][0] + m1.m[1][2] * m2.m[2][0] +
		m1.m[1][3] * m2.m[3][0];
	result.m[1][1] = m1.m[1][0] * m2.m[0][1] + m1.m[1][1] * m2.m[1][1] + m1.m[1][2] * m2.m[2][1] +
		m1.m[1][3] * m2.m[3][1];
	result.m[1][2] = m1.m[1][0] * m2.m[0][2] + m1.m[1][1] * m2.m[1][2] + m1.m[1][2] * m2.m[2][2] +
		m1.m[1][3] * m2.m[3][2];
	result.m[1][3] = m1.m[1][0] * m2.m[0][3] + m1.m[1][1] * m2.m[1][3] + m1.m[1][2] * m2.m[2][3] +
		m1.m[1][3] * m2.m[3][3];

	result.m[2][0] = m1.m[2][0] * m2.m[0][0] + m1.m[2][1] * m2.m[1][0] + m1.m[2][2] * m2.m[2][0] +
		m1.m[2][3] * m2.m[3][0];
	result.m[2][1] = m1.m[2][0] * m2.m[0][1] + m1.m[2][1] * m2.m[1][1] + m1.m[2][2] * m2.m[2][1] +
		m1.m[2][3] * m2.m[3][1];
	result.m[2][2] = m1.m[2][0] * m2.m[0][2] + m1.m[2][1] * m2.m[1][2] + m1.m[2][2] * m2.m[2][2] +
		m1.m[2][3] * m2.m[3][2];
	result.m[2][3] = m1.m[2][0] * m2.m[0][3] + m1.m[2][1] * m2.m[1][3] + m1.m[2][2] * m2.m[2][3] +
		m1.m[2][3] * m2.m[3][3];

	result.m[3][0] = m1.m[3][0] * m2.m[0][0] + m1.m[3][1] * m2.m[1][0] + m1.m[3][2] * m2.m[2][0] +
		m1.m[3][3] * m2.m[3][0];
	result.m[3][1] = m1.m[3][0] * m2.m[0][1] + m1.m[3][1] * m2.m[1][1] + m1.m[3][2] * m2.m[2][1] +
		m1.m[3][3] * m2.m[3][1];
	result.m[3][2] = m1.m[3][0] * m2.m[0][2] + m1.m[3][1] * m2.m[1][2] + m1.m[3][2] * m2.m[2][2] +
		m1.m[3][3] * m2.m[3][2];
	result.m[3][3] = m1.m[3][0] * m2.m[0][3] + m1.m[3][1] * m2.m[1][3] + m1.m[3][2] * m2.m[2][3] +
		m1.m[3][3] * m2.m[3][3];

	return result;
}


// ’·‚³(ƒmƒ‹ƒ€)
float Length(const Vector3& v) {
	float result;
	result = sqrt(Dot(v, v));
	return result;
}

// ³‹K‰»
Vector3 Normalize(const Vector3& v) {
	Vector3 result{};
	float length = Length(v);
	if (length != 0.0f) {
		result.x = v.x / length;
		result.y = v.y / length;
		result.z = v.z / length;
	}
	return result;
}

Vector3 Transform(const Vector3& vector, const Matrix4& matrix) {
	Vector3 result;
	result.x = vector.x * matrix.m[0][0] + vector.y * matrix.m[1][0] + vector.z * matrix.m[2][0] + 1.0f * matrix.m[3][0];
	result.y = vector.x * matrix.m[0][1] + vector.y * matrix.m[1][1] + vector.z * matrix.m[2][1] + 1.0f * matrix.m[3][1];
	result.z = vector.x * matrix.m[0][2] + vector.y * matrix.m[1][2] + vector.z * matrix.m[2][2] + 1.0f * matrix.m[3][2];

	float w = vector.x * matrix.m[0][3] + vector.y * matrix.m[1][3] + vector.z * matrix.m[2][3] + 1.0f * matrix.m[3][3];
	result.x /= w;
	result.y /= w;
	result.z /= w;

	return result;
}


// “àÏ
float Dot(const Vector3& v1, const Vector3& v2) {
	float result;
	result = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return result;
}

Vector3 Cross(const Vector3& v1, const Vector3& v2) {
	return { v1.y * v2.z - v1.z * v2.y,v1.z * v2.x - v1.x * v2.z,v1.x * v2.y - v1.y * v2.x };
}

Matrix4 MakeRotateAxisAngle(const Vector3& axis, float angle) {
	// Šg‘åk¬
	Matrix4 matS[2] = {
		{cosf(angle),0,0,0,
		0,cosf(angle),0,0,
		0,0,cosf(angle),0,
		0,0,0,1},

		{1 - cosf(angle),0,0,0,
		0,1 - cosf(angle),0,0,
		0,0,1 - cosf(angle),0,
		0,0,0,1},
	};
	// ŽË‰e
	Matrix4 matP = {
		axis.x * axis.x, axis.x * axis.y, axis.x * axis.z,0,
		axis.x * axis.y, axis.y * axis.y, axis.y * axis.z,0,
		axis.x * axis.z, axis.y * axis.z, axis.z * axis.z,0,
		0,0,0,1
	};
	matP = Multiply(matS[1], matP);

	// 
	Matrix4 matC = {
		0,-axis.z,axis.y,  0,
		axis.z,0,-axis.x, 0,
		-axis.y,axis.x,0 , 0,
		0,0,0,1
	};
	matC = Multiply(matC, -sinf(angle));

	Matrix4 result = Add(matS[0], Add(matP, matC));
	result.m[3][3] = 1;

	return result;
}


Matrix4 DirectionToDirection(const Vector3& from, const Vector3& to) {
	// ³‹K‰»
	Vector3 n;
	// ^‹t‚ÌƒxƒNƒgƒ‹‚©‚ðƒ`ƒFƒbƒN
	float dotFrom2to = Dot(from, to);
	// ³‹K‰»
	n = Normalize(Cross(from, to));

	// ^‹t‚È‚ç”½“]
	if (dotFrom2to == -1) {
		n = { n.y, -n.x, 0 };
	}

	float cos = Dot(from, to);
	float sin = Length(Cross(from, to));

	Matrix4 result = {
		n.x * n.x * (1 - cos) + cos,	   n.x * n.y * (1 - cos) + n.z * sin, n.x * n.z * (1 - cos) - n.y * sin,0,
		n.x * n.y * (1 - cos) - n.z * sin, n.y * n.y * (1 - cos) + cos,		  n.y * n.z * (1 - cos) + n.x * sin,0,
		n.x * n.z * (1 - cos) + n.y * sin, n.y * n.z * (1 - cos) - n.x * sin, n.z * n.z * (1 - cos) + cos,0,
		0,0,0,1
	};
	return result;
}

void VectorScreenPrintf(int x, int y, const Vector3& vector, const char* label) {
	Novice::ScreenPrintf(x, y, "%.02f", vector.x);
	Novice::ScreenPrintf(x + kColumnWidth, y, "%.02f", vector.y);
	Novice::ScreenPrintf(x + kColumnWidth * 2, y, "%.02f", vector.z);
	Novice::ScreenPrintf(x + kColumnWidth * 3, y, "%s", label);
}

void MatrixScreenPrintf(int x, int y, const Matrix4& matrix, const char* label) {
	Novice::ScreenPrintf(x, y - 20, label);
	for (int row = 0; row < 4; ++row) {
		for (int column = 0; column < 4; ++column) {
			Novice::ScreenPrintf(x + column * 60, y + row * 20, "%6.03f", matrix.m[row][column]);
		}
	}
}
