#pragma once

#include <chrono>

using time_ms = std::chrono::microseconds::rep;

/**
 * \brief ��ʱ��
 */
class Timer
{
public:
	/// <summary>
	/// ʱ��ڵ�
	/// </summary>
	time_ms start_ms = 0, previous_ms = 0, current_ms = 0;

	/// <summary>
	/// ʱ����
	/// </summary>
	time_ms delta_ms = 0, running_ms = 0;

	/// <summary>
	/// ��λ s
	/// </summary>
	float delta = 0, running = 0;

	/**
	 * \brief ���£��ƽ�����һ֡
	 */
	void update();

	/**
	 * \brief ����/��ʼ��
	 */
	void reset();

	static time_ms time();
};
