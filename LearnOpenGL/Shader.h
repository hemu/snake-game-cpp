#pragma once

#include <string>

class Shader
{
public:
    unsigned int ID;

    Shader(const char *sourcePath);
    ~Shader();

    void Use();
    void SetBool(const std::string &name, bool value) const;
    void SetInt(const std::string &name, int value) const;
    void SetFloat(const std::string &name, float value) const;

private:
    unsigned int CompileShader(unsigned int type, const char *source);
};
