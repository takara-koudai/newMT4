#pragma once

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

