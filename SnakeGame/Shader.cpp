#include <glad/glad.h>
#include "Shader.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <assert.h>
#include <glm/gtc/type_ptr.hpp>

enum class ShaderType
{
    NONE = -1,
    VERTEX = 0,
    FRAGMENT = 1
};

struct ShaderSource
{
    std::string VertexShader;
    std::string FragmentShader;
};

static ShaderSource ParseShader(const char *sourcePath)
{
    std::stringstream ss[2];
    std::ifstream sourceStream;
    ShaderType parseMode = ShaderType::NONE;

    sourceStream.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try
    {
        std::ifstream sourceStream(sourcePath);

        std::string line;
        while (getline(sourceStream, line))
        {
            if (line.find("#shader vertex") != std::string::npos)
            {
                parseMode = ShaderType::VERTEX;
            }
            else if (line.find("#shader fragment") != std::string::npos)
            {
                parseMode = ShaderType::FRAGMENT;
            }
            else
            {
                assert(parseMode != ShaderType::NONE);
                ss[(int)parseMode] << line << "\n";
            }
        }

        return ShaderSource{ss[(int)ShaderType::VERTEX].str(), ss[(int)ShaderType::FRAGMENT].str()};
    }
    catch (std::ifstream::failure e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ" << std::endl;
        std::cerr << e.what() << std::endl;
        throw e;
    }
}

Shader::Shader(const char *sourcePath)
{
    ShaderSource source = ParseShader(sourcePath);

    unsigned int vertex, fragment;
    vertex = Shader::CompileShader(GL_VERTEX_SHADER, source.VertexShader.c_str());
    fragment = Shader::CompileShader(GL_FRAGMENT_SHADER, source.FragmentShader.c_str());

    ID = glCreateProgram();
    glAttachShader(ID, vertex);
    glAttachShader(ID, fragment);
    glLinkProgram(ID);
    glValidateProgram(ID);
    int success{0};
    glGetProgramiv(ID, GL_LINK_STATUS, &success);
    if (!success)
    {
        char infoLog[512];
        glGetProgramInfoLog(ID, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED" << infoLog << std::endl;
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

Shader::~Shader()
{
    glDeleteProgram(ID);
}

unsigned int Shader::CompileShader(unsigned int type, const char *source)
{
    unsigned int id = glCreateShader(type);
    glShaderSource(id, 1, &source, NULL);
    glCompileShader(id);

    // Error handling
    int success{0};
    glGetShaderiv(id, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        char infoLog[512];
        glGetShaderInfoLog(id, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::" << (type == GL_VERTEX_SHADER ? "VERTEX" : "FRAGMENT") << "::COMPILATION_FAILED" << infoLog << std::endl;
    };

    return id;
}

void Shader::Use()
{
    glUseProgram(ID);
}
void Shader::SetBool(const std::string &name, bool value) const
{
    glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}
void Shader::SetInt(const std::string &name, int value) const
{
    glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}
void Shader::SetFloat(const std::string &name, float value) const
{
    glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::SetMatrix4fv(const std::string &name, glm::mat4 mat) const
{
    glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, glm::value_ptr(mat));
}