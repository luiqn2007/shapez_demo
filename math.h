#pragma once

#include <cmath>
#include <random>

/**
 * \brief �ж������������Ƿ����
 * \param a a
 * \param b b
 * \return ���
 */
inline bool feq(const float a, const float b)
{
	return std::fabsf(a - b) <= FLT_EPSILON;
}

// c++ �����
static std::random_device rd;
static std::mt19937_64 engine{};
static std::uniform_int_distribution int_distribution{0, 99};
static std::uniform_real_distribution real_distribution;

inline void random_seed(const long long seed)
{
	engine.seed(seed);
}

/**
 * \brief ��ȡһ��������������������ΧΪ [0, 100)
 * \return �����
 */
inline int random_int()
{
	return int_distribution(engine);
}

/**
 * \brief ��ȡһ��������������������ΧΪ [0, 1]
 * \return �����
 */
inline float random()
{
	return static_cast<float>(real_distribution(engine));
}
