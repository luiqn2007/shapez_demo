#include "AbstractDrawer.h"

#include "resouces.h"

void AbstractDrawer::destroy_static()
{
	if (indices_buffer_)
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		glDeleteBuffers(1, &indices_buffer_);
		indices_buffer_ = 0;
	}

	resizeable_program_.clear();
}

void AbstractDrawer::resize(const GLfloat width, const GLfloat height)
{
	for (const GLuint program : resizeable_program_)
	{
		glUseProgram(program);
		glUniform2f(0, width, height);
	}
}

void AbstractDrawer::create_program(GLuint& program, string&& vert, string&& frag, bool resize)
{
	cout << " Create program with " << vert << " and " << frag << "..." << endl;
	program = glCreateProgram();
	// ���������붥����ɫ��
	const path vp = ROOT / "glsl" / vert;
	cout << "  Loading shader " << vp.string() << endl;
	const GLuint sp = create_shader(GL_VERTEX_SHADER, vp);
	// ����������ƬԪ��ɫ��
	const path vf = ROOT / "glsl" / frag;
	cout << "  Loading shader " << vf.string() << endl;
	const GLuint sf = create_shader(GL_FRAGMENT_SHADER, vf);
	// ������������ɫ������
	glAttachShader(program, sp);
	glAttachShader(program, sf);
	glLinkProgram(program);
	glDetachShader(program, sp);
	glDetachShader(program, sf);
	glDeleteShader(sp);
	glDeleteShader(sf);
	// У��������ӽ��
	GLint param;
	glGetProgramiv(program, GL_LINK_STATUS, &param);
	if (param != GL_TRUE)
	{
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &param);
		const auto msg = new GLchar[param + 1];
		glGetProgramInfoLog(program, param, &param, msg);
		// ������
		glDeleteProgram(program);
		program = 0;
		cerr << msg << endl;
		delete[] msg;
	}
	// ��¼��Ҫ���µ���ɫ������
	if (resize)
	{
		resizeable_program_.push_back(program);
	}
}

GLuint AbstractDrawer::create_shader(const GLenum type, const path& p)
{
	const auto [len, str] = read_text(p);
	const GLuint shader = glCreateShader(type);
	glShaderSource(shader, 1, &str, reinterpret_cast<const GLint*>(&len));
	glCompileShader(shader);
	// У�������
	GLint param;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &param);
	if (param != GL_TRUE)
	{
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &param);
		const auto info = new GLchar[param + 1];
		glGetShaderInfoLog(shader, param, &param, info);
		cerr << info << endl;
		glDeleteShader(shader);
		return 0;
	}
	return shader;
}

void AbstractDrawer::bind_indices()
{
	if (!indices_buffer_)
	{
		glCreateBuffers(1, &indices_buffer_);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indices_buffer_);
		const unsigned int indices[] = {0, 1, 3, 1, 2, 3};
		glNamedBufferStorage(indices_buffer_, sizeof indices, indices, GL_MAP_READ_BIT);
	}
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indices_buffer_);
}
