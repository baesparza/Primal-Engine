#pragma once

#include <cstddef>
#include "Renderer2D.h"
#include "Renderable2D.h"
#include "buffers\IndexBuffer.h"

#include "../../ext/FreeType-GL/freetype-gl.h"

#define RENDERER_MAX_SPRITES	60000
#define RENDERER_VERTEX_SIZE	sizeof(VertexData)
#define RENDERER_SPRITE_SIZE	RENDERER_VERTEX_SIZE * 4
#define RENDERER_BUFFER_SIZE	RENDERER_SPRITE_SIZE * RENDERER_MAX_SPRITES
#define RENDERER_INDICES_SIZE	RENDERER_MAX_SPRITES * 6

#define SHADER_VERTEX_INDEX 0
#define SHADER_TEXCOORD_INDEX 1
#define SHADER_TEXID_INDEX  2
#define SHADER_COLOR_INDEX  3

namespace primal
{
	namespace graphics
	{

		class BatchRenderer2D : public Renderer2D
		{
		private:
			GLuint m_VAO;
			GLuint m_VBO;
			IndexBuffer* m_IBO;
			GLsizei m_IndexCount;
			VertexData * m_Buffer;
			std::vector<GLuint> m_TextureSlots;

			ftgl::texture_atlas_t * m_FTAtlas;
			ftgl::texture_font_t * m_FTFont;
		public:
			BatchRenderer2D();
			~BatchRenderer2D();
			void begin() override;
			void submit(const Renderable2D * renderable) override;
			void end() override;
			void flush() override;

			void drawString(const std::string& text, const maths::vec3 & position, unsigned int color) override;
		private:
			void init();
		};

	}
}