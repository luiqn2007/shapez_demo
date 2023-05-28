#pragma once

#include <filesystem>
#include <fstream>
#include <string>

using std::string;
using std::filesystem::path;
using std::filesystem::current_path;
using std::fstream;
using std::endl;

/**
 * \brief ���ı�
 */
struct Text
{
	uintmax_t len = 0;
	char* str = nullptr;

	~Text();

	void operator<<(const uintmax_t size)
	{
		str = new char[size + 1];
		len = 0;
	}

	void operator<<(const int ch)
	{
		str[len++] = static_cast<char>(ch);
	}

	void end() const
	{
		str[len - 1] = '\0';
	}
};

/**
 * \brief ʹ�� stb_image ����ͼƬ
 */
struct Image
{
	int width, height, channels;

	unsigned char* data;

	~Image();
};

/**
 * \brief ��ǰ·��
 */
#define ROOT (current_path())

/**
 * \brief ���ı�
 * \param p ·��
 * \return �ı�
 */
Text read_text(const path& p);

/**
 * \brief ��ͼƬ
 * \param p ·��
 * \return ͼƬ
 */
Image load_image(const path& p);
