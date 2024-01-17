#pragma once
#include "Matrix4.h"
#include "Vector3.h"

struct Matrix3x3 {
	float m[3][3];
};

// ���Z
Matrix4 Add(const Matrix4& m1, const Matrix4& m2);

// �X�J���[�{
Vector3 Multiply(const Vector3& m, float scale);

// �X�J���[�{
Matrix4 Multiply(Matrix4 m, float scale);

// �s��̐�
Matrix4 Multiply(const Matrix4& m1, const Matrix4& m2);

// ����(�m����)
float Length(const Vector3& v);

// ���K��
Vector3 Normalize(const Vector3& v);

// ����
float Dot(const Vector3& v1, const Vector3& v2);

Vector3 Cross(const Vector3& v1, const Vector3& v2);

// ���ˉe�x�N�g��
Vector3 Project(const Vector3& v1, const Vector3& v2);

// �C�ӎ���]�s��
Matrix4 MakeRotateAxisAngle(const Vector3& axis, float angle);

void MatrixScreenPrintf(int x, int y, const Matrix4& matrix, const char* label);

