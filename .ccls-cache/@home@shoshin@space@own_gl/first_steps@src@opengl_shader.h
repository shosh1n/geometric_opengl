#ifndef opengl_shader_hpp
#define opengl_shader_hpp
#include <string>
#include <vector>

class Shader {
    public:
        Shader();
        void init(const std::string& vertex_code, const std::string& fragment_code);
        void use();
        template<typename T> void setUniform(const std::string& name, T val);
        template<typename T> void setUniform(const std::string& name, T val1, T val2);
        template<typename T> void setUniform(const std::string& name, T val1, T val2, T val3);

    private:
        void checkCompileErr();
        void checkLinkingErr();
        void compile();
        void link();
        unsigned int m_vertex_id, m_fragment_id, m_id;
        std::string m_vertex_code;
        std::string m_fragment_code;
};
#endif // opengl_shader_hpp
