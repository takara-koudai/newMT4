#include "Quaternion.h"
#include "MatrixTrans.h"
#include <cmath>

Quaternion Multiply(const Quaternion& lhs, const Quaternion& rhs) 
{
	// ����
	float dot = Dot(Vector3(lhs.x, lhs.y, lhs.z), Vector3(rhs.x, rhs.y, rhs.z));
	// �O��
	Vector3 cross = Cross(Vector3(lhs.x, lhs.y, lhs.z), Vector3(rhs.x, rhs.y, rhs.z));

	// �v�Z����
	Quaternion result;
	result.x = cross.x + rhs.w * lhs.x + lhs.w * rhs.x;
	result.y = cross.y + rhs.w * lhs.y + lhs.w * rhs.y;
	result.z = cross.z + rhs.w * lhs.z + lhs.w * rhs.z;
	result.w = lhs.w * rhs.w - dot;

	return result;
}

Quaternion IdentituQuaternion() 
{
	return Quaternion{ 0,0,0,1 };
}

Quaternion Conjugate(const Quaternion& quaternion) 
{
	return Quaternion{ -quaternion.x,-quaternion.y ,-quaternion.z ,-quaternion.w };
}

float Norm(const Quaternion& quaternion) 
{
	float x = quaternion.x;
	float y = quaternion.y;
	float z = quaternion.z;
	float w = quaternion.w;
	return sqrt(x * x + y * y + z * z + w * w);
}

Quaternion Normalize(const Quaternion& quaternion) 
{
	// �m����
	float norm = Norm(quaternion);
	// �v�Z����
	Quaternion result;
	if (norm != 0.0f) 
	{
		result.x = quaternion.x / norm;
		result.y = quaternion.y / norm;
		result.z = quaternion.z / norm;
		result.w = quaternion.w / norm;
	}

	return result;
}

Quaternion Inverse(const Quaternion& quaternion)
{
	// ����
	Quaternion conjugate = Conjugate(quaternion);
	// �m����
	float norm = Norm(quaternion);

	// �v�Z����
	Quaternion result;
	result.x = conjugate.x / (norm * norm);
	result.y = conjugate.y / (norm * norm);
	result.z = conjugate.z / (norm * norm);
	result.w = conjugate.w / (norm * norm);

	return result;
}
