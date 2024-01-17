#pragma once
#include "Matrix4.h"
#include "Vector3.h"

struct Matrix3x3 {
	float m[3][3];
};

// ‰ÁZ
Matrix4 Add(const Matrix4& m1, const Matrix4& m2);

// ƒXƒJƒ‰[”{
Vector3 Multiply(const Vector3& m, float scale);

// ƒXƒJƒ‰[”{
Matrix4 Multiply(Matrix4 m, float scale);

// s—ñ‚ÌÏ
Matrix4 Multiply(const Matrix4& m1, const Matrix4& m2);

// ’·‚³(ƒmƒ‹ƒ€)
float Length(const Vector3& v);

// ³‹K‰»
Vector3 Normalize(const Vector3& v);

// “àÏ
float Dot(const Vector3& v1, const Vector3& v2);

Vector3 Cross(const Vector3& v1, const Vector3& v2);

// ³Ë‰eƒxƒNƒgƒ‹
Vector3 Project(const Vector3& v1, const Vector3& v2);

// ”CˆÓ²‰ñ“]s—ñ
Matrix4 MakeRotateAxisAngle(const Vector3& axis, float angle);

void MatrixScreenPrintf(int x, int y, const Matrix4& matrix, const char* label);

