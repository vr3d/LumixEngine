#pragma once


#include "core/string.h"
#include "graphics/gl_ext.h"


namespace Lumix
{


class FrameBuffer
{
	public:
		enum RenderBuffers
		{
			DIFFUSE,
			POSITION,
			NORMAL,
			DEPTH,
			RENDERBUFFERS_COUNT
		};

		enum RenderBufferBits
		{
			DIFFUSE_BIT = 1 << DIFFUSE,
			POSITION_BIT = 1 << POSITION,
			NORMAL_BIT = 1 << NORMAL,
			DEPTH_BIT = 1 << DEPTH
		};

	public:
		FrameBuffer(int width, int height, int render_buffers, const char* name);
		~FrameBuffer();
		
		GLuint getId() const { return m_id; }
		GLuint getDiffuseTexture() const { return m_textures[DIFFUSE]; }
		GLuint getPositionTexture() const { return m_textures[POSITION]; }
		GLuint getNormalTexture() const { return m_textures[NORMAL]; }
		GLuint getDepthTexture() const { return m_textures[DEPTH]; }
		GLuint getTexture(RenderBuffers render_buffer) { return m_textures[render_buffer]; }
		void bind();
		int getWidth() const { return m_width; }
		int getHeight() const { return m_height; }
		const char* getName() { return m_name.c_str(); }
		static void unbind();

	private:
		string m_name;
		GLuint m_textures[RENDERBUFFERS_COUNT];
		GLuint m_renderbuffers[RENDERBUFFERS_COUNT];
		GLuint m_id;
		int m_render_buffers;
		int m_width;
		int m_height;
};


} // ~namespace
