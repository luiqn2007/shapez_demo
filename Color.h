#pragma once
#include <string>

static std::string color_names[]
{
	"uncolored.png", // 0b000
	"red.png", // 0b001
	"green.png", // 0b010
	"yellow.png", // 0b011
	"blue.png", // 0b100
	"purple.png", // 0b101
	"cyan.png", // 0b110
	"white.png", // 0b111
};

/**
 * \brief ��ʾ��ɫ
 */
enum class Color
{
	uncolored = 0b000,
	red = 0b001,
	green = 0b010,
	blue = 0b100,
	yellow = 0b011,
	cyan = 0b110,
	purple = 0b101,
	white = 0b111
};

/**
 * \brief ��ȡ��ɫ���ַ���������������й�
 * \param color ��ɫ
 * \return ��ɫ��
 */
inline std::string& color_icon(const Color color)
{
	return color_names[static_cast<int>(color)];
}

/**
 * \brief У��������ɫ�Ƿ���Ի��
 * \param color1 ��ɫ1
 * \param color2 ��ɫ2
 * \return �Ƿ�ɻ��
 */
inline bool operator|(Color color1, Color color2)
{
	return (static_cast<int>(color1) & static_cast<int>(color2)) == 0;
}

/**
 * \brief ��ȡ������ɫ��Ϻ�Ľ��
 * \param color1 ��ɫ1
 * \param color2 ��ɫ2
 * \return ��Ϻ����ɫ
 */
inline Color operator+(Color color1, Color color2)
{
	return static_cast<Color>(static_cast<int>(color1) | static_cast<int>(color2));
}
