#pragma once

#include <string>
#include <glm/glm.hpp>

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
    void SetVec3(const std::string &name, glm::vec3 vec) const;
    void SetMatrix4fv(const std::string &name, glm::mat4 mat) const;

private:
    unsigned int CompileShader(unsigned int type, const char *source);
};
