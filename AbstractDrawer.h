#pragma once

#include <string>
#include <iostream>
#include <filesystem>

#include <glad/glad.h>

#include "Resouces.h"

using std::string;
using std::cout;
using std::cerr;
using std::endl;
using std::filesystem::path;

/**
 * \brief GL ������
 */
class AbstractDrawer
{
public:
	/**
	 * \brief �����ڴ�С�����仯ʱ����
	 * \param width ���ڿ��
	 * \param height ���ڸ߶�
	 */
	void resize(GLfloat width, GLfloat height) const;

	/**
	 * \brief �Ի����๲����Դ���ͷ�
	 */
	static void destroy_static();

protected:

	/**
	 * \brief ����ʹ�õ���ɫ������
	 */
	GLuint program_ = 0;

	/**
	 * \brief ����ʹ�õĶ����������
	 */
	GLuint vao_ = 0;

	/**
	 * \brief ���㻺��������
	 */
	GLuint buffer_ = 0;

	/**
	 * \brief ������ɫ������
	 * \param program ��ɫ���������
	 * \param vert ������ɫ������
	 * \param frag ƬԪ��ɫ������
	 */
	static void create_program(GLuint& program, string&& vert, string&& frag);

	/**
	 * \brief ������ɫ��
	 * \param type ��ɫ������
	 * \param p ��ɫ��·��
	 * \return ��������ɫ�� id������ʧ���򷵻� 0
	 */
	static GLuint create_shader(const GLenum type, const path& p);

	/**
	 * \brief �����ڻ��Ʒ���Ķ������黺����
	 */
	static void bind_indices();

private:
	inline static GLuint indices_buffer_ = 0;
};

