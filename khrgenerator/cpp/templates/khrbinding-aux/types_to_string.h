
#pragma once


#include <string>
#include <iosfwd>

#include <{{binding.bindingAuxIdentifier}}/{{binding.bindingAuxIdentifier}}_api.h>
#include <{{binding.bindingAuxIdentifier}}/{{binding.bindingAuxIdentifier}}_features.h>

#include <{{binding.identifier}}/{{api.identifier}}/types.h>
#include <{{binding.identifier}}/Value.h>


namespace {{api.identifier}}
{


{% for group in enumerators|sort(attribute='identifier') -%}
{{binding.auxApiExport}} std::ostream & operator<<(std::ostream & stream, const {{group.identifier}} & value);
{% endfor -%}
{% for group in uniqueEnumerators|sort(attribute='identifier') -%}
{{binding.auxApiExport}} std::ostream & operator<<(std::ostream & stream, const {{group.identifier}} & value);
{% endfor -%}
{% for group in bitfields|sort(attribute='identifier') -%}
{{binding.auxApiExport}} std::ostream & operator<<(std::ostream & stream, const {{group.identifier}} & value);
{% endfor %}

} // namespace {{api.identifier}}


namespace {{binding.namespace}}
{


class Version;


/**
*  @brief
*    Generic ostream operator for the Value template
*/
template <typename T>
{{binding.auxApiTemplateExport}} std::ostream & operator<<(std::ostream & stream, const Value<T> & value);

/**
*  @brief
*    Generic ostream operator for the Value template with pointer types
*/
template <typename T>
{{binding.auxApiTemplateExport}} std::ostream & operator<<(std::ostream & stream, const Value<T *> & value);

/**
*  @brief
*    A specialized ostream operator for the gl::GLenum Value template
*/
template <>
{{binding.auxApiExport}} std::ostream & operator<<(std::ostream & stream, const Value<{{api.identifier}}::{{binding.enumType}}> & value);

/* <- ToDo: Add back second * when implementing this function again
*  @brief
*    A specialized ostream operator for the gl::GLbitfield Value template
*/
/*template <>
{{binding.auxApiExport}} std::ostream & operator<<(std::ostream & stream, const Value<{{api.identifier}}::{{binding.bitfieldType}}> & value);*/

/**
*  @brief
*    A specialized ostream operator for the gl::GLenum Value template
*/
template <>
{{binding.auxApiExport}} std::ostream & operator<<(std::ostream & stream, const Value<{{api.identifier}}::{{binding.booleanType}}> & value);

/**
*  @brief
*    A specialized ostream operator for the const char * Value template
*/
template <>
{{binding.auxApiExport}} std::ostream & operator<<(std::ostream & stream, const Value<const char *> & value);

{%- for cStringTypeName in cStringTypes %}

/**
*  @brief
*    A specialized ostream operator for the {{cStringTypeName}} * Value template
*/
template <>
{{binding.auxApiExport}} std::ostream & operator<<(std::ostream & stream, const Value<{{api.identifier}}::{{cStringTypeName}} *> & value);
{%- endfor %}

/**
*  @brief
*    The operator to allow Versions to be printed onto a std::ostream
*/
{{binding.auxApiExport}} std::ostream & operator<<(std::ostream & stream, const Version & version);

/**
*  @brief
*    The operator to allow AbstractValues to be printed onto a std::ostream
*/
{{binding.auxApiExport}} std::ostream & operator<<(std::ostream & stream, const AbstractValue * value);


} // namespace {{binding.namespace}}


#include <{{binding.bindingAuxIdentifier}}/types_to_string.inl>
