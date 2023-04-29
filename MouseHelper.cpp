#include "MouseHelper.h"

namespace MouseHelper
{
	bool last_left_clicked;
	bool left_clicked;
	bool pos_initialized;
	float wheel_distance;
	float x_pos, y_pos, last_x_pos, last_y_pos;

	void update()
	{
		last_left_clicked = left_clicked;
		last_x_pos = x_pos;
		last_y_pos = y_pos;
		wheel_distance = 0;
	}

	void initialize()
	{
		last_left_clicked = false;
		left_clicked = false;
		pos_initialized = false;
		update();
	}

	bool is_left_clicked()
	{
		return last_left_clicked && !left_clicked;
	}

	bool is_left_drag()
	{
		return last_left_clicked && left_clicked;
	}

	float x()
	{
		return x_pos;
	}

	float y()
	{
		return y_pos;
	}

	float dx()
	{
		return x_pos - last_x_pos;
	}

	float dy()
	{
		return y_pos - last_y_pos;
	}

	float wheel()
	{
		return wheel_distance;
	}

	void set_left_click(const bool click)
	{
		left_clicked = click;
	}

	void set_position(const double x, const double y)
	{
		x_pos = static_cast<float>(x);
		y_pos = static_cast<float>(y);
		if (!pos_initialized)
		{
			last_x_pos = x_pos;
			last_y_pos = y_pos;
			pos_initialized = true;
		}
	}

	void set_wheel(const double v)
	{
		wheel_distance = static_cast<float>(v);
	}
}
