#pragma once

struct Quaternion
{
	float x;
	float y;
	float z;
	float w;
};

// Ï
Quaternion Multiply(const Quaternion& lhs, const Quaternion& rhs);
// ’PˆÊQuaternion
Quaternion IdentituQuaternion();
// ‹¤–ğQuaternion‚ğ•Ô‚·
Quaternion Conjugate(const Quaternion& quaternion);
// Quaternion‚Ìnorm‚ğ•Ô‚·
float Norm(const Quaternion& quaternion);
// ³‹K‰»‚µ‚½Quaternion‚ğ•Ô‚·
Quaternion Normalize(const Quaternion& quaternion);
// ‹tQuaternion‚ğ•Ô‚·
Quaternion Inverse(const Quaternion& quaternion);

