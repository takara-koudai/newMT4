#pragma once
#include "Matrix4.h"
#include "Vector3.h"

struct Quaternion
{
	float x;
	float y;
	float z;
	float w;
};

// ��
Quaternion Multiply(const Quaternion& lhs, const Quaternion& rhs);
// �P��Quaternion
Quaternion IdentituQuaternion();
// ����Quaternion��Ԃ�
Quaternion Conjugate(const Quaternion& quaternion);
// Quaternion��norm��Ԃ�
float Norm(const Quaternion& quaternion);
// ���K������Quaternion��Ԃ�
Quaternion Normalize(const Quaternion& quaternion);
// �tQuaternion��Ԃ�
Quaternion Inverse(const Quaternion& quaternion);
// �C�ӎ���]��\��Quaternion�̐���
Quaternion MakeRotateAxisAngleQuaternion(const Vector3& axis, float angle);
// �x�N�g����Quaternion�ŉ�]���������ʂ̃x�N�g�������߂�
Vector3 RotateVector(const Vector3& vector, Quaternion quaternion);
// Quaternion�����]�s������߂�
Matrix4 MakeRotateMatrix(const Quaternion& quaternion);

// Quaternion�̐��l�\��
void QuaternionScreenPrintf(int x, int y, const Quaternion& quaternion, const char* label);

