#pragma once
#include "core/resource.h"
#include "graphics/gl_ext.h"


namespace Lumix
{
namespace FS
{
	class FileSystem;
	class IFile;
}

struct Vec3;
struct Matrix;

class LUMIX_ENGINE_API Shader : public Resource
{
	public:
		static const int MAX_ATTRIBUTE_COUNT = 16;

	public:
		Shader(const Path& path, ResourceManager& resource_manager);
		~Shader();

		void apply();
		void setUniform(const char* name, GLint value);
		void setUniform(const char* name, const Vec3& value);
		void setUniform(const char* name, GLfloat value);
		void setUniform(const char* name, const Matrix& mtx);
		void setUniform(const char* name, const Matrix* matrices, int count);
		GLint getAttribId(int index) const { return m_vertex_attributes_ids[index]; }
		GLint getPositionAttribId() const { return m_position_attrib_id; }
		GLint getNormalAttribId() const { return m_normal_attrib_id; }
		GLint getTexCoordAttribId() const { return m_tex_coord_attrib_id; }
		bool isShadowmapRequired() const { return m_is_shadowmap_required; }

	private:
		GLuint attach(GLenum type, const char* src, int32_t length);
		void loaded(FS::IFile* file, bool success, FS::FileSystem& fs);
		bool deserializeSettings(class ISerializer& serializer, char* attributes[MAX_ATTRIBUTE_COUNT]);

		virtual void doUnload(void) override;
		virtual FS::ReadCallback getReadCallback() override;

	private:
		GLuint	m_program_id;
		GLuint	m_vertex_id;
		GLuint	m_fragment_id;
		GLint	m_vertex_attributes_ids[MAX_ATTRIBUTE_COUNT];
		GLint	m_position_attrib_id;
		GLint	m_normal_attrib_id;
		GLint	m_tex_coord_attrib_id;
		bool	m_is_shadowmap_required;
};


} // ~namespace Lumix
