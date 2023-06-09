#pragma once

#include <chrono>

class GameLogic;
class GameWindow;

/**
 * \brief 计时器
 */
class Timer
{
	friend GameLogic;
	friend GameWindow;
public:
	/// <summary>
	/// 时间节点
	/// </summary>
	time_t start_ms = 0, previous_ms = 0, current_ms = 0;

	/// <summary>
	/// 时间间隔
	/// </summary>
	time_t delta_ms = 0, running_ms = 0;

	/// <summary>
	/// 单位 s
	/// </summary>
	float delta = 0, running = 0;

	/**
	 * \brief 更新：推进到下一帧
	 */
	void update();

	/**
	 * \brief 重置/初始化
	 */
	void reset();

	static time_t time();

private:

	/**
	 * \brief 倍速
	 */
	float time_multiply_ = 1;

};
