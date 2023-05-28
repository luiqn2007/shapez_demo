#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <filesystem>

#include <glad/glad.h>

using std::string;
using std::vector;
using std::cout;
using std::cerr;
using std::endl;
using std::filesystem::path;

class GameRenderer;

/**
 * \brief ������
 */
class AbstractDrawer
{
	friend GameRenderer;

public:
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
	 * \param resize �����ڴ�С�����仯ʱ�����¸���ɫ������
	 */
	static void create_program(GLuint& program, string&& vert, string&& frag, bool resize);

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

	/**
	 * \brief ��Ҫ�ڴ��ڳߴ緢���仯ʱ���µ���ɫ������
	 *
	 * Ҫ�� location=0 �� uniform ����Ϊ vec2 ���͵ı�����ʾ width �� height
	 */
	inline static vector<GLuint> resizeable_program_;

	/**
	 * \brief �����ڴ�С�����仯ʱ����
	 * \param width ���ڿ��
	 * \param height ���ڸ߶�
	 */
	static void resize(GLfloat width, GLfloat height);
};
