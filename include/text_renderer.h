#ifndef TEXT_RENDERER_H
#define TEXT_RENDERER_H

#include <map>

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "texture.h"
#include "shader.h"

/// Holds all state information relevant to a character as loaded using FreeType
struct Character
{
    GLuint TextureID;   // ID handle of the glyph texture
    glm::ivec2 Size;    // Size of glyph
    glm::ivec2 Bearing; // Offset from baseline to left/top of glyph
    GLuint Advance;     // Horizontal offset to advance to next glyph
};

// A renderer class for rendering text displayed by a font loaded using the
// FreeType library. A single font is loaded, processed into a list of Character
// items for later rendering.
class TextRenderer
{
public:
    // Holds a list of pre-compiled Characters
    std::map<GLchar, Character> Characters;
    std::map<wchar_t, Character> ChineseChar;
    // Shader used for text rendering
    Shader TextShader;
    // Constructor
    TextRenderer(){};
    TextRenderer(Shader shader, GLuint width, GLuint height);
    TextRenderer(const char *vertexPath, const char *fragmentPath, GLuint width, GLuint height);
    void TextRendererInit(const char *vertexPath, const char *fragmentPath, GLuint width, GLuint height);
    void SetProjection(GLuint width, GLuint height);
    // Pre-compiles a list of characters from the given font
    void Load(std::string fontPath, GLuint fontSize);
    void LoadChinese(const wchar_t *text, std::string fontPath, GLuint fontSize);
    void ClearChinese();
    // Renders a string of text using the precompiled list of characters
    void RenderText(std::string text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color = glm::vec3(1.0f));
    void RenderTextAlignRight(std::string text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color = glm::vec3(1.0f));
    void RenderChinese(const wchar_t *text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color = glm::vec3(1.0f));

private:
    // Render state
    GLuint VAO, VBO;
};

#endif