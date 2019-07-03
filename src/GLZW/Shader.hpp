//
// Created by z16cn on 2019/4/29.
//

#ifndef SAINT_SHADER_H
#define SAINT_SHADER_H

#include <glad.h>
#include <glm/glm.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
public:
    unsigned int ID;
    // constructor generates the shader on the fly
    // ------------------------------------------------------------------------
    Shader(){
        ID=0;
    };

    Shader(const char* vertexPath, const char* fragmentPath, const char* geometryPath = nullptr);

    void create(const char* vShaderCode, const char * fShaderCode, const char * geometryCode= nullptr);
    static Shader createFromFile(const char* vertexPath, const char* fragmentPath, const char* geometryPath = nullptr);
    static Shader createFromString(const char* vShaderCode, const char * fShaderCode);

    // activate the shader
    // ------------------------------------------------------------------------
    inline void use()
    {
        glUseProgram(ID);
    }

    //region utility uniform functions part1

    // ------------------------------------------------------------------------
    inline void setBool(const std::string &name, bool value) const
    {
        glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
    }
    // ------------------------------------------------------------------------
    inline void setInt(const std::string &name, int value) const
    {
        glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
    }
    // ------------------------------------------------------------------------
    inline void setFloat(const std::string &name, float value) const
    {
        glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
    }
    // ------------------------------------------------------------------------
    inline void setVec2(const std::string &name, const glm::vec2 &value) const
    {
        glUniform2fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
    }
    inline void setVec2(const std::string &name, float x, float y) const
    {
        glUniform2f(glGetUniformLocation(ID, name.c_str()), x, y);
    }
    // ------------------------------------------------------------------------
    inline void setVec3(const std::string &name, const glm::vec3 &value) const
    {
        glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
    }
    inline void setVec3(const std::string &name, float x, float y, float z) const
    {
        glUniform3f(glGetUniformLocation(ID, name.c_str()), x, y, z);
    }
    // ------------------------------------------------------------------------
    inline void setVec4(const std::string &name, const glm::vec4 &value) const
    {
        glUniform4fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
    }
    inline void setVec4(const std::string &name, float x, float y, float z, float w)
    {
        glUniform4f(glGetUniformLocation(ID, name.c_str()), x, y, z, w);
    }
    // ------------------------------------------------------------------------
    inline void setMat2(const std::string &name, const glm::mat2 &mat) const
    {
        glUniformMatrix2fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
    }
    // ------------------------------------------------------------------------
    inline void setMat3(const std::string &name, const glm::mat3 &mat) const
    {
        glUniformMatrix3fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
    }
    // ------------------------------------------------------------------------
    inline void setMat4(const std::string &name, const glm::mat4 &mat) const
    {
        glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
    }

    //endregion

    //region uniform function part2

    inline void set(const std::string& name, bool value) const{
        setBool(name, value);
    }
    inline void set(const std::string& name, int value) const{
        setInt(name, value);
    }
    inline void set(const std::string& name, float value) const{
        setFloat(name, value);
    }
    inline void set(const std::string& name, const glm::vec2& value) const{
        setVec2(name, value);
    }
    inline void set(const std::string& name, const glm::vec3& value) const{
        setVec3(name, value);
    }
    inline void set(const std::string& name, const glm::vec4& value) const{
        setVec4(name, value);
    }
    inline void set(const std::string& name, const glm::mat2& value) const{
        setMat2(name, value);
    }
    inline void set(const std::string& name, const glm::mat3& value) const{
        setMat3(name, value);
    }
    inline void set(const std::string& name, const glm::mat4& value) const{
        setMat4(name, value);
    }

    //endregion

    //region uniform function3

    // ------------------------------------------------------------------------
    inline void setBool(int pos, bool value) const
    {
        glUniform1i(pos, (int)value);
    }
    // ------------------------------------------------------------------------
    inline void setInt(int pos, int value) const
    {
        glUniform1i(pos, value);
    }
    // ------------------------------------------------------------------------
    inline void setFloat(int pos, float value) const
    {
        glUniform1f(pos, value);
    }
    // ------------------------------------------------------------------------
    inline void setVec2(int pos, const glm::vec2 &value) const
    {
        glUniform2fv(pos, 1, &value[0]);
    }
    inline void setVec2(int pos, float x, float y) const
    {
        glUniform2f(pos, x, y);
    }
    // ------------------------------------------------------------------------
    inline void setVec3(int pos, const glm::vec3 &value) const
    {
        glUniform3fv(pos, 1, &value[0]);
    }
    inline void setVec3(int pos, float x, float y, float z) const
    {
        glUniform3f(pos, x, y, z);
    }
    // ------------------------------------------------------------------------
    inline void setVec4(int pos, const glm::vec4 &value) const
    {
        glUniform4fv(pos, 1, &value[0]);
    }
    inline void setVec4(int pos, float x, float y, float z, float w)
    {
        glUniform4f(pos, x, y, z, w);
    }
    // ------------------------------------------------------------------------
    inline void setMat2(int pos, const glm::mat2 &mat) const
    {
        glUniformMatrix2fv(pos, 1, GL_FALSE, &mat[0][0]);
    }
    // ------------------------------------------------------------------------
    inline void setMat3(int pos, const glm::mat3 &mat) const
    {
        glUniformMatrix3fv(pos, 1, GL_FALSE, &mat[0][0]);
    }
    // ------------------------------------------------------------------------
    inline void setMat4(int pos, const glm::mat4 &mat) const
    {
        glUniformMatrix4fv(pos, 1, GL_FALSE, &mat[0][0]);
    }

    //endregion

private:
    // utility function for checking shader compilation/linking errors.
    // ------------------------------------------------------------------------
    inline void checkCompileErrors(GLuint shader, std::string type)
    {
        GLint success;
        GLchar infoLog[1024];
        if(type != "PROGRAM")
        {
            glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
            if(!success)
            {
                glGetShaderInfoLog(shader, 1024, NULL, infoLog);
                std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
            }
        }
        else
        {
            glGetProgramiv(shader, GL_LINK_STATUS, &success);
            if(!success)
            {
                glGetProgramInfoLog(shader, 1024, NULL, infoLog);
                std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
            }
        }
    }
};
#endif //SAINT_SHADER_H
