#include "BatchRenderer2D.h"

namespace primal
{
	namespace graphics
	{

		BatchRenderer2D::BatchRenderer2D()
		{
			init();
		}

		BatchRenderer2D::~BatchRenderer2D()
		{
			delete m_IBO;
			glDeleteBuffers(1, &m_VBO);
		}

		void BatchRenderer2D::begin()
		{
			glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
			m_Buffer = (VertexData *) glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
		}

		void BatchRenderer2D::submit(const Renderable2D * renderable)
		{
			// send directly to opengl
			const maths::vec3& position = renderable->getPosition();
			const maths::vec2& size = renderable->getSize();
			const maths::vec4& color = renderable->getColor();
			const std::vector<maths::vec2>& texCoord = renderable->getTexCoord();
			const GLuint texID = renderable->getTexID();


			unsigned int c = 0;

			float ts = 0.0f;
			bool found = false;
			if (texID > 0)
			{
				for (int i = 0; i < m_TextureSlots.size(); i++)
					if (m_TextureSlots[i] == texID)
					{
						ts = (float) (i + 1);
						found = true;
						break;
					}
				if (!found)
				{
					if (m_TextureSlots.size() >= 32)
					{
						end();
						flush();
						begin();
					}
					m_TextureSlots.push_back(texID);
					ts = (float) m_TextureSlots.size();
				}
			}
			else
			{
				int r = color.x * 255.0f;
				int g = color.y * 255.0f;
				int b = color.z * 255.0f;
				int a = color.w * 255.0f;

				c = a << 24 | b << 16 | g << 8 | r;
			}

			m_Buffer->vertex = *m_TransformationBack * position;
			m_Buffer->texCoord = texCoord[0];
			m_Buffer->color = c;
			m_Buffer->texID = ts;
			m_Buffer++;

			m_Buffer->vertex = *m_TransformationBack * maths::vec3(position.x, position.y + size.y, position.z);
			m_Buffer->texCoord = texCoord[1];
			m_Buffer->color = c;
			m_Buffer->texID = ts;
			m_Buffer++;

			m_Buffer->vertex = *m_TransformationBack * maths::vec3(position.x + size.x, position.y + size.y, position.z);
			m_Buffer->texCoord = texCoord[2];
			m_Buffer->color = c;
			m_Buffer->texID = ts;
			m_Buffer++;

			m_Buffer->vertex = *m_TransformationBack * maths::vec3(position.x + size.x, position.y, position.z);
			m_Buffer->texCoord = texCoord[3];
			m_Buffer->color = c;
			m_Buffer->texID = ts;
			m_Buffer++;

			m_IndexCount += 6;
		}

		void BatchRenderer2D::end()
		{
			glUnmapBuffer(GL_ARRAY_BUFFER);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}

		void BatchRenderer2D::flush()
		{
			for (int i = 0; i < m_TextureSlots.size(); i++)
			{
				glActiveTexture(GL_TEXTURE0 + i);
				glBindTexture(GL_TEXTURE_2D, m_TextureSlots[i]);
			}

			glBindVertexArray(m_VAO);
			m_IBO->bind();

			glDrawElements(GL_TRIANGLES, m_IndexCount, GL_UNSIGNED_INT, NULL);

			m_IBO->unbind();
			glBindVertexArray(0);
			m_IndexCount = 0;
		}

		void BatchRenderer2D::drawString(const std::string & text, const maths::vec3 & position, const maths::vec4 & color)
		{
			using namespace ftgl;

			int r = color.x * 255.0f;
			int g = color.y * 255.0f;
			int b = color.z * 255.0f;
			int a = color.w * 255.0f;

			unsigned int col = a << 24 | b << 16 | g << 8 | r;

			float ts = 0.0f;
			bool found = false;
			for (int i = 0; i < m_TextureSlots.size(); i++)
				if (m_TextureSlots[i] == m_FTAtlas->id)
				{
					ts = (float) (i + 1);
					found = true;
					break;
				}
			if (!found)
			{
				if (m_TextureSlots.size() >= 32)
				{
					end();
					flush();
					begin();
				}
				m_TextureSlots.push_back(m_FTAtlas->id);
				ts = (float) m_TextureSlots.size();
			}

			float scale = 0.05;
			float x = position.x;

			for (const char & c : text)
			{
				texture_glyph_t* glyph = texture_font_get_glyph(m_FTFont, c);
				if (glyph)
				{
					float x0 = x + glyph->offset_x*scale;
					float y0 = position.y + glyph->offset_y*scale;
					float x1 = x0 + glyph->width		   *scale;
					float y1 = y0 + glyph->height		   *scale;

					float u0 = glyph->s0;
					float v0 = glyph->t0;
					float u1 = glyph->s1;
					float v1 = glyph->t1;

					m_Buffer->vertex = *m_TransformationBack * maths::vec3(x0, y0, 0);
					m_Buffer->texCoord = maths::vec2(u0, v1);
					m_Buffer->texID = ts;
					m_Buffer->color = col;
					m_Buffer++;

					m_Buffer->vertex = *m_TransformationBack * maths::vec3(x0, y1, 0);
					m_Buffer->texCoord = maths::vec2(u0, v0);
					m_Buffer->texID = ts;
					m_Buffer->color = col;
					m_Buffer++;

					m_Buffer->vertex = *m_TransformationBack * maths::vec3(x1, y1, 0);
					m_Buffer->texCoord = maths::vec2(u1, v0);
					m_Buffer->texID = ts;
					m_Buffer->color = col;
					m_Buffer++;

					m_Buffer->vertex = *m_TransformationBack * maths::vec3(x1, y0, 0);
					m_Buffer->texCoord = maths::vec2(u1, v1);
					m_Buffer->texID = ts;
					m_Buffer->color = col;
					m_Buffer++;

					m_IndexCount += 6;
					x += glyph->advance_x * scale;
				}
			}

		}

		void BatchRenderer2D::init()
		{
			glGenVertexArrays(1, &m_VAO);
			glGenBuffers(1, &m_VBO);

			glBindVertexArray(m_VAO);
			glBindBuffer(GL_ARRAY_BUFFER, m_VBO);

			glBufferData(GL_ARRAY_BUFFER, RENDERER_BUFFER_SIZE, NULL, GL_DYNAMIC_DRAW);

			glEnableVertexAttribArray(SHADER_VERTEX_INDEX);
			glEnableVertexAttribArray(SHADER_TEXCOORD_INDEX);
			glEnableVertexAttribArray(SHADER_TEXID_INDEX);
			glEnableVertexAttribArray(SHADER_COLOR_INDEX);

			glVertexAttribPointer(SHADER_VERTEX_INDEX, 3, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE, (const void*) 0);
			glVertexAttribPointer(SHADER_TEXCOORD_INDEX, 2, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE, (const void*) (offsetof(VertexData, VertexData::texCoord)));
			glVertexAttribPointer(SHADER_TEXID_INDEX, 1, GL_FLOAT, GL_TRUE, RENDERER_VERTEX_SIZE, (const void*) (offsetof(VertexData, VertexData::texID)));
			glVertexAttribPointer(SHADER_COLOR_INDEX, 4, GL_UNSIGNED_BYTE, GL_TRUE, RENDERER_VERTEX_SIZE, (const void*) (offsetof(VertexData, VertexData::color)));

			glBindBuffer(GL_ARRAY_BUFFER, 0);

			GLuint * indices = new GLuint[RENDERER_INDICES_SIZE];
			int offset = 0;
			for (int i = 0; i < RENDERER_INDICES_SIZE; i += 6)
			{
				indices[i] = offset + 0;
				indices[i + 1] = offset + 1;
				indices[i + 2] = offset + 2;

				indices[i + 3] = offset + 2;
				indices[i + 4] = offset + 3;
				indices[i + 5] = offset + 0;
				offset += 4;
			}

			m_IBO = new IndexBuffer(indices, RENDERER_INDICES_SIZE);
			glBindVertexArray(0);

			/////////initialize font////////////
			m_FTAtlas = ftgl::texture_atlas_new(512, 512, 1);
			//	m_FTFont = ftgl::texture_font_new_from_file(m_FTAtlas, 80, "./res/fonts/Raleway-Regular.ttf");
			m_FTFont = ftgl::texture_font_new_from_file(m_FTAtlas, 80, "./res/fonts/arial.ttf");

		}

	}
}
