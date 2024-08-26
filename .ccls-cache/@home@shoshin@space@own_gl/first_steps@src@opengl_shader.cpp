#include "opengl_shader.h"
#include <sstream>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

Shader::Shader() {
}

void Shader::init(const std::string& vertex_code, const std::string& fragment_code) {
    m_vertex_code = vertex_code;
    m_fragment_code = fragment_code;
    compile();
    link();
}

void Shader::compile() {
    const char* vcode = m_vertex_code.c_str();
    m_vertex_id = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(m_vertex_id, 1, &vcode, NULL);
    glCompileShader(m_vertex_id);

    const char* fcode = m_fragment_code.c_str();
    m_fragment_id = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(m_fragment_id, 1, &fcode, NULL);
    glCompileShader(m_fragment_id);
    checkCompileErr();
}

void Shader::link() {
    m_id = glCreateProgram();
    glAttachShader(m_id, m_vertex_id);
    glAttachShader(m_id, m_fragment_id);
    glLinkProgram(m_id);
    checkLinkingErr();
    glDeleteShader(m_vertex_id);
    glDeleteShader(m_fragment_id);
}

void Shader::use() {
    glUseProgram(m_id);
}

template<>
void Shader::setUniform<int>(const std::string& name, int val) {
    glUniform1i(glGetUniformLocation(m_id, name.c_str()), val);
}

template<>
void Shader::setUniform<bool>(const std::string& name, bool val) {
    glUniform1i(glGetUniformLocation(m_id, name.c_str()), val);
}

template<>
void Shader::setUniform<float>(const std::string& name, float val) {
    glUniform1f(glGetUniformLocation(m_id, name.c_str()), val);
}

template<>
void Shader::setUniform<float>(const std::string &name, float val1, float val2) {
    glUniform2f(glGetUniformLocation(m_id, name.c_str()), val1, val2);
}

template<>
void Shader::setUniform<float>(const std::string& name, float val1, float val2, float val3) {
    glUniform3f(glGetUniformLocation(m_id, name.c_str()), val1, val2, val3);
}

template<>
void Shader::setUniform<float*>(const std::string& name, float* val) {
    glUniformMatrix4fv(glGetUniformLocation(m_id, name.c_str()), 1, GL_FALSE, val);
}

void Shader::checkCompileErr() {
    int success;
    char infoLog[1024];
    glGetShaderiv(m_vertex_id, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(m_vertex_id, 1024, NULL, infoLog);
        std::cout << "Error compiling Vertex Shader:\n" << infoLog << std::endl;
    }

    glGetShaderiv(m_fragment_id, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(m_fragment_id, 1024, NULL, infoLog);
        std::cout << "Error compiling Fragment Sahder:\n" << infoLog << std::endl;
    }

}

void Shader::checkLinkingErr() {
    int success;
    char infoLog[1024];
    glGetProgramiv(m_id, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(m_id, 1024, NULL, infoLog);
        std::cout << "Error Linking Shader Program:\n" << infoLog << std::endl;
    }
}
